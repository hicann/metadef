/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "register/op_impl_registry.h"
#include "register/op_impl_space_registry.h"
#include "register/op_impl_registry_holder_manager.h"
#include "graph/any_value.h"
//#include "graph/utils/file_utils.h"
#include "common/util/mem_utils.h"
#include "mmpa/mmpa_api.h"
#include "tests/depends/mmpa/src/mmpa_stub.h"
#include <gtest/gtest.h>
#include "register/op_impl_registry_base.h"
#include "base/registry/op_impl_register_v2_impl.h"

namespace gert_test {
namespace {
ge::OpSoBinPtr CreateSoBinPtr(std::string &so_name, std::string &vendor_name) {
  std::unique_ptr<char[]> so_bin = std::unique_ptr<char[]>(new(std::nothrow) char[so_name.length()]);
  (void) memcpy_s(so_bin.get(), so_name.length(), so_name.data(), so_name.length());
  ge::OpSoBinPtr so_bin_ptr = ge::MakeShared<ge::OpSoBin>(so_name, vendor_name, std::move(so_bin), so_name.length());
  return so_bin_ptr;
}

size_t g_impl_num = 3;
size_t g_ct_impl_num = 2;
const char *type[] = {"Add_0", "Add_1", "Add_2"};
size_t GetRegisteredOpNum() { return g_impl_num; }
size_t GetRegisteredOpCtNum() { return g_ct_impl_num; }
uint32_t GetOpImplFunctions(TypesToImpl *impl, size_t g_impl_num) {
  gert::OpImplKernelRegistry::OpImplFunctions funcs;
  for (size_t i = 0; i < g_impl_num; ++i) {
    funcs.tiling = (gert::OpImplRegisterV2::TilingKernelFunc) (0x10 + i);
    funcs.infer_shape = (gert::OpImplRegisterV2::InferShapeKernelFunc) (0x20 + i);
    funcs.infer_datatype = nullptr;
    funcs.tiling_parse = nullptr;
    funcs.compile_info_deleter = nullptr;
    funcs.compile_info_creator = nullptr;
    funcs.inputs_dependency = 0;
    impl[i].op_type = type[i];
    impl[i].funcs = funcs;
  }
  return 0;
}

uint32_t GetOpImplFunctionsV3(TypesToImplV2 *impl, size_t g_impl_num) {
  gert::OpImplKernelRegistry::OpImplFunctionsV2 funcs;
  for (size_t i = 0; i < g_impl_num; ++i) {
    funcs.tiling = (gert::OpImplRegisterV2::TilingKernelFunc) (0x10 + i);
    funcs.infer_shape = (gert::OpImplRegisterV2::InferShapeKernelFunc) (0x20 + i);
    funcs.infer_symbol_shape = (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) (0x30 + i);
    funcs.infer_datatype = nullptr;
    funcs.tiling_parse = nullptr;
    funcs.compile_info_deleter = nullptr;
    funcs.compile_info_creator = nullptr;
    funcs.inputs_dependency = 0;
    funcs.unique_private_attrs.clear();
    impl[i].op_type = type[i];
    impl[i].funcs = funcs;
  }
  return 0;
}

uint32_t GetOpImplFunctionsFailV3(TypesToImplV2 *impl, size_t g_impl_num) {
    return ge::GRAPH_FAILED;
}

uint32_t GetOpCtImplFunctions(TypesToCtImpl *impl, size_t g_ct_impl_num) {
  gert::OpCtImplKernelRegistry::OpCtImplFunctions funcs;
  for (size_t i = 0; i < g_ct_impl_num; ++i) {
    funcs.calc_op_param = (gert::OpCtImplKernelRegistry::OpCalcParamKernelFunc) (0x10 + i);
    funcs.gen_task = (gert::OpCtImplKernelRegistry::OpGenTaskKernelFunc) (0x20 + i);
    funcs.check_support = (gert::OpCtImplKernelRegistry::OP_CHECK_FUNC_V2) (0x30 + i);
    funcs.op_select_format = (gert::OpCtImplKernelRegistry::OP_CHECK_FUNC_V2) (0x40 + i);
    funcs.get_op_support_info = (gert::OpCtImplKernelRegistry::OP_CHECK_FUNC_V2) (0x50 + i);
    funcs.get_op_specific_info = (gert::OpCtImplKernelRegistry::OP_CHECK_FUNC_V2) (0x60 + i);
    impl[i].op_type = type[i];
    impl[i].funcs = funcs;
  }
  return 0;
}

void *mock_handle = nullptr;
bool get_func_null = false;
bool close_fail = false;
bool enable_OpImplFunctions_V2 = false;
bool enable_OpImplFunctions_V3 = false;
bool enable_OpImplFunctions_V3_fail = false;

class MockMmpa : public ge::MmpaStubApi {
 public:
  void *DlSym(void *handle, const char *func_name) override {
    if (get_func_null) {
      get_func_null = true;
      return nullptr;
    }
    if (std::string(func_name) == "GetRegisteredOpNum") {
      return (void *) &GetRegisteredOpNum;
    } else if (std::string(func_name) == "GetOpImplFunctions") {
      return (void *) &GetOpImplFunctions;
    } else if (std::string(func_name) == "GetOpImplFunctionsV2" && enable_OpImplFunctions_V2){
      enable_OpImplFunctions_V2 = false;
      return (void *) &GetOpImplFunctionsV2;
    }else if (std::string(func_name) == "GetOpImplFunctionsV2" && enable_OpImplFunctions_V3){
      enable_OpImplFunctions_V3 = false;
      return (void *) &GetOpImplFunctionsV3;
    }else if (std::string(func_name) == "GetOpImplFunctionsV2" && enable_OpImplFunctions_V3_fail) {
      enable_OpImplFunctions_V3_fail = false;
      return (void *) &GetOpImplFunctionsFailV3;
    }
    if (std::string(func_name) == "GetRegisteredOpCtNum") {
      return (void *) &GetRegisteredOpCtNum;
    } else if (std::string(func_name) == "GetOpCtImplFunctions") {
      return (void *) &GetOpCtImplFunctions;
    }
    return nullptr;
  }
  void *DlOpen(const char *fileName, int32_t mode) override {
    if (mock_handle == nullptr) {
      return nullptr;
    }
    return (void *) mock_handle;
  }
  int32_t DlClose(void *handle) override {
    if (close_fail) {
      close_fail = false;
      return -1;
    }
    return 0L;
  }
};
}

class OpImplSpaceRegistryUT : public testing::Test {
 protected:
  void SetUp() {}

  void TearDown() {
    gert::OpImplRegistryHolderManager::GetInstance().ClearOpImplRegistries();
    ge::MmpaStub::GetInstance().Reset();
  }
};

ge::graphStatus TestInferShapeFunc(gert::InferShapeContext *) {
  return ge::GRAPH_SUCCESS;
}
TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_GetOrCreateRegistry_1so_Succeed) {
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 1;

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  std::vector<ge::OpSoBinPtr> bins;
  bins.emplace_back(so_bin_ptr);
  ge::SoInOmInfo so_info;
  so_info.cpu_info = "x86";
  so_info.os_info = "Linux";
  so_info.opp_version = "1.84";
  gert::OpImplSpaceRegistry space_registry;
  EXPECT_EQ(space_registry.GetOrCreateRegistry(bins, so_info), ge::GRAPH_SUCCESS);
  EXPECT_EQ(space_registry.GetOrCreateRegistry(bins, so_info, "/opp_latest/"), ge::GRAPH_SUCCESS);
  std::string so_data = so_name;
  auto registry_holder = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_data);
  EXPECT_NE(registry_holder, nullptr);
  EXPECT_NE(space_registry.GetOpImpl("Add_0"), nullptr);
  EXPECT_EQ(space_registry.GetPrivateAttrs("Add_0").size(), 0);
  auto reg_func = space_registry.GetOpCtImpl("Add_0");
  EXPECT_NE(reg_func, nullptr);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->calc_op_param), 0x10);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->gen_task), 0x20);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->check_support), 0x30);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->op_select_format), 0x40);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->get_op_support_info), 0x50);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->get_op_specific_info), 0x60);
}

TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_GetOrCreateRegistry_2so_Succeed) {
  g_impl_num = 2;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;

  ge::SoInOmInfo so_info;
  so_info.cpu_info = "x86";
  so_info.os_info = "Linux";
  so_info.opp_version = "1.84";

  std::string so_name1("libopmaster.so");
  std::string vendor_name1("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr1 = CreateSoBinPtr(so_name1, vendor_name1);

  gert::OpImplSpaceRegistry space_registry;
  EXPECT_EQ(space_registry.GetOrCreateRegistry({so_bin_ptr1}, so_info), ge::GRAPH_SUCCESS);
  auto registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
  EXPECT_NE(space_registry.GetOpImpl("Add_0"), nullptr);
  EXPECT_EQ(space_registry.GetPrivateAttrs("Add_0").size(), 0);

  std::string so_name2("libopsproto.so");
  std::string vendor_name2("/opp/DC");
  ge::OpSoBinPtr so_bin_ptr2 = CreateSoBinPtr(so_name2, vendor_name2);
  EXPECT_EQ(space_registry.GetOrCreateRegistry({so_bin_ptr2}, so_info), ge::GRAPH_SUCCESS);
  auto registry_holder2 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name2);
  EXPECT_NE(registry_holder2, nullptr);

  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 2);
  // 再次校验 registry_holder1
  registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
}
TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_GetOrCreateRegistry_3so_Succeed) {
  g_impl_num = 2;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;

  ge::SoInOmInfo so_info;
  so_info.cpu_info = "x86";
  so_info.os_info = "Linux";
  so_info.opp_version = "1.84";

  std::string so_name1("libopmaster.so");
  std::string vendor_name1("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr1 = CreateSoBinPtr(so_name1, vendor_name1);

  gert::OpImplSpaceRegistry space_registry;
  EXPECT_EQ(space_registry.GetOrCreateRegistry({so_bin_ptr1}, so_info), ge::GRAPH_SUCCESS);
  auto registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
  EXPECT_NE(space_registry.GetOpImpl("Add_0"), nullptr);
  EXPECT_EQ(space_registry.GetPrivateAttrs("Add_0").size(), 0);

  std::string so_name2("libopsproto.so");
  std::string vendor_name2("/opp/DC");
  ge::OpSoBinPtr so_bin_ptr2 = CreateSoBinPtr(so_name2, vendor_name2);
  EXPECT_EQ(space_registry.GetOrCreateRegistry({so_bin_ptr2}, so_info), ge::GRAPH_SUCCESS);
  auto registry_holder2 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name2);
  EXPECT_NE(registry_holder2, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 2);

  std::string so_name3("libopsproto.so");
  std::string vendor_name3("/opp/DC");
  ge::OpSoBinPtr so_bin_ptr3 = CreateSoBinPtr(so_name2, vendor_name2);
  EXPECT_EQ(space_registry.GetOrCreateRegistry({so_bin_ptr2}, so_info), ge::GRAPH_SUCCESS);
  auto registry_holder3 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name2);
  EXPECT_NE(registry_holder2, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 2);

  // 再次校验 registry_holder1
  registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
}

TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_AddRegistry_Succeed) {
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 3;

  gert::OpImplSpaceRegistry space_registry;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  auto ret = registry_holder->LoadSo(so_bin_ptr);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);

  auto types_to_impl = registry_holder->GetTypesToImpl();
  ret = space_registry.AddRegistry(registry_holder);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);

  auto func = space_registry.GetOpImpl("Add_0");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x10);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x20);

  func = space_registry.GetOpImpl("Add_1");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x11);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x21);

  func = space_registry.GetOpImpl("Add_2");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x12);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x22);

  func = space_registry.GetOpImpl("Add_3");
  EXPECT_EQ(func, nullptr);
}

TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_AddRegistry_FailV2) {
  enable_OpImplFunctions_V2 = true;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 3;

  gert::OpImplSpaceRegistry space_registry;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();
  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  auto ret = registry_holder->LoadSo(so_bin_ptr);
  EXPECT_EQ(ret, ge::GRAPH_FAILED);
}

TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_AddRegistry_SucceedV2) {
  enable_OpImplFunctions_V2 = true;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 1;

  gert::OpImplSpaceRegistry space_registry;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  gert::OpImplKernelRegistry::OpImplFunctionsV2 funcs;
  funcs.infer_symbol_shape = (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc)100;
  registry_holder->AddTypesToImpl("Add_test", funcs);

  gert::OpImplRegistry::GetInstance().GetAllTypesToImpl()["Add_test"]=funcs;
  const auto ret_impl = gert::OpImplRegistry::GetInstance();
  EXPECT_EQ(1, ret_impl.GetAllTypesToImpl().size());

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  auto ret = registry_holder->LoadSo(so_bin_ptr);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);


  auto types_to_impl = registry_holder->GetTypesToImpl();
  ret = space_registry.AddRegistry(registry_holder);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);

  auto func = space_registry.GetOpImpl("Add_test");
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 100);
}

TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_AddRegistry_SucceedV3) {
  enable_OpImplFunctions_V3 = true;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 3;

  gert::OpImplSpaceRegistry space_registry;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  auto ret = registry_holder->LoadSo(so_bin_ptr);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);

  auto types_to_impl = registry_holder->GetTypesToImpl();
  ret = space_registry.AddRegistry(registry_holder);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);

  auto func = space_registry.GetOpImpl("Add_0");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x10);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x20);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x30);

  func = space_registry.GetOpImpl("Add_1");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x11);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x21);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x31);

  func = space_registry.GetOpImpl("Add_2");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x12);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x22);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x32);

  func = space_registry.GetOpImpl("Add_3");
  EXPECT_EQ(func, nullptr);
}

TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_AddRegistry_FailV3) {
  enable_OpImplFunctions_V3_fail = true;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 3;

  gert::OpImplSpaceRegistry space_registry;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  auto ret = registry_holder->LoadSo(so_bin_ptr);
  EXPECT_EQ(ret, ge::GRAPH_FAILED);
}

TEST_F(OpImplSpaceRegistryUT, OpImplSpaceRegistry_AddRegistry_WithSameOptype_Succeed) {
  gert::OpImplSpaceRegistry space_registry;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();
  gert::OpImplKernelRegistry::OpImplFunctions funcs;
  funcs.max_tiling_data_size = 100;
  funcs.host_inputs = 1;
  funcs.tiling_dependency = 1;
  funcs.tiling_dependency_placements = 1;
  funcs.output_shape_depend_compute = 1UL;
  funcs.unique_private_attrs.insert("test");
  registry_holder->AddTypesToImpl("Add_test", funcs);
  auto ret = space_registry.AddRegistry(registry_holder);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);
  ret = space_registry.AddRegistry(registry_holder);
  EXPECT_EQ(ret, ge::GRAPH_SUCCESS);
}

TEST_F(OpImplSpaceRegistryUT, DefaultOpImplSpaceRegistry_SetSpaceRegistry_Succeed) {
  auto space_registry = std::make_shared<gert::OpImplSpaceRegistry>();
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(space_registry);
  EXPECT_NE(gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry(), nullptr);
}

TEST_F(OpImplSpaceRegistryUT, DefaultOpImplSpaceRegistry_SetSpaceRegistry_null) {
  auto space_registry = std::make_shared<gert::OpImplSpaceRegistry>();
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(space_registry, ge::OppImplVersion::kOpp);
  EXPECT_NE(gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry(ge::OppImplVersion::kOpp), nullptr);

  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr, ge::OppImplVersion::kOpp);
  EXPECT_EQ(gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry(ge::OppImplVersion::kOpp), nullptr);
  // 通过校验原始类成员变量中space_registries_中存储的智能指针引用计数判断是否析构
  // 不能通过GetDefaultSpaceRegistry接口，该接口里做了封装，如果获取DefaultOpImplSpaceRegistryV2中为nullptr，直接返回nullptr
  EXPECT_EQ(gert::DefaultOpImplSpaceRegistry::GetInstance().space_registries_[static_cast<size_t>(ge::OppImplVersion::kOpp)].use_count(), 0);
}

TEST_F(OpImplSpaceRegistryUT, LoadSoAndSaveToRegistry_success) {
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 1;

  const std::string so_path = "./libop_master_test.so";
  system(("touch " + so_path).c_str());
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr);
  EXPECT_EQ(gert::OpImplSpaceRegistry::LoadSoAndSaveToRegistry(so_path), ge::GRAPH_SUCCESS);

  // 重复load相同so，但是版本一样， load成功
  EXPECT_EQ(gert::OpImplSpaceRegistry::LoadSoAndSaveToRegistry(so_path), ge::GRAPH_SUCCESS);

  // 重复load相同so，但是版本不一样， load失败，之前是load时，如果so内容一样，都不会造一个space_registry，现在是外部造space_registry，
  // 即使opp跟opp_kenrl内容一样，也会造space registry，但是OpImplHolder会复用
  mock_handle = (void *) 0xfffffffe;
  EXPECT_EQ(gert::OpImplSpaceRegistry::ConvertSoToRegistry(so_path, ge::OppImplVersion::kOppKernel), ge::GRAPH_SUCCESS);

  // 显示释放handle
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr);
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr, ge::OppImplVersion::kOppKernel);
  system(("rm -f " + so_path).c_str());
  gert::OpImplRegistryHolderManager::GetInstance().ClearOpImplRegistries();
}

TEST_F(OpImplSpaceRegistryUT, LoadSoAndSaveToRegistry_fail) {
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = nullptr;
  g_impl_num = 0;
  const std::string so_path = "./libop_master_test.so";
  system(("touch " + so_path).c_str());
  // LoadSoAndSaveToRegistry always success
  EXPECT_EQ(gert::OpImplSpaceRegistry::LoadSoAndSaveToRegistry(so_path), ge::GRAPH_SUCCESS);

  mock_handle = (void *) 0xfffffffc;
  get_func_null = true;
  close_fail = true;
  EXPECT_EQ(gert::OpImplSpaceRegistry::LoadSoAndSaveToRegistry(so_path), ge::GRAPH_SUCCESS);
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr);
  system(("rm -f " + so_path).c_str());
}
}  // namespace gert_test
