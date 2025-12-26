/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <fstream>
#include "register/op_impl_registry.h"
#include "graph/any_value.h"
#include "common/util/error_manager/error_manager.h"
#include "common/util/mem_utils.h"
#include "mmpa/mmpa_api.h"
#include "tests/depends/mmpa/src/mmpa_stub.h"
#include <gtest/gtest.h>
#include "register/op_impl_registry_base.h"
#include "base/registry/op_impl_register_v2_impl.h"
#include "base/registry/op_impl_space_registry_v2.h"
#include "base/registry/op_impl_space_registry_v2_impl.h"
#include "graph/utils/file_utils.h"
#include "base/err_msg.h"
#include "base/err_mgr.h"
#include "nlohmann/json.hpp"

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

uint32_t GetOpImplFunctionsV3NoTiling(TypesToImplV2 *impl, size_t g_impl_num) {
  gert::OpImplKernelRegistry::OpImplFunctionsV2 funcs;
  for (size_t i = 0; i < g_impl_num; ++i) {
    funcs.tiling = nullptr;
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
bool enable_OpImplFunctions_V3_no_tiling = false;

size_t dlopen_num = 0;
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
    } else if (std::string(func_name) == "GetOpImplFunctionsV2" && enable_OpImplFunctions_V3){
      enable_OpImplFunctions_V3 = false;
      return (void *) &GetOpImplFunctionsV3;
    } else if (std::string(func_name) == "GetOpImplFunctionsV2" && enable_OpImplFunctions_V3_fail) {
      enable_OpImplFunctions_V3_fail = false;
      return (void *) &GetOpImplFunctionsFailV3;
    } else if (std::string(func_name) == "GetOpImplFunctionsV2" && enable_OpImplFunctions_V3_no_tiling) {
      return (void *) &GetOpImplFunctionsV3NoTiling;
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
    dlopen_num++;
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

ge::graphStatus CreateOmOppDir(std::string &opp_dir) {
  static std::atomic<uint64_t> load_so_count{0U};
  opp_dir = CMAKE_BINARY_DIR;
  opp_dir += "/ascend_temp/" + std::to_string(mmGetPid()) + "_" + std::to_string(mmGetTid()) + "_" +
      std::to_string(load_so_count.fetch_add(1)) + "/";
  std::cout << opp_dir << std::endl;
  GELOGD("opp_dir is %s", opp_dir.c_str());

  // EXPECT_EQ(mmAccess2(opp_dir.c_str(), M_F_OK), EN_OK);
  EXPECT_EQ(ge::CreateDir(opp_dir), 0);

  return ge::GRAPH_SUCCESS;
}
ge::graphStatus SaveToFile(const std::shared_ptr<ge::OpSoBin> &so_bin, const std::string &opp_path) {
  constexpr mmMode_t kAccess = static_cast<mmMode_t>(static_cast<uint32_t>(M_IRUSR) | static_cast<uint32_t>(M_IWUSR) |
                                                     static_cast<uint32_t>(M_UMASK_USREXEC));
  const int32_t fd = mmOpen2(opp_path.c_str(),
                             static_cast<int32_t>(static_cast<uint32_t>(M_WRONLY) | static_cast<uint32_t>(M_CREAT) |
                                                  static_cast<uint32_t>(O_TRUNC)),
                             kAccess);
  if (fd < 0) {
    GELOGE(ge::FAILED, "Failed to open file, path = %s", opp_path.c_str());
    return ge::GRAPH_FAILED;
  }
  const int32_t write_count =
      mmWrite(fd, const_cast<uint8_t *>(so_bin->GetBinData()), static_cast<uint32_t>(so_bin->GetBinDataSize()));
  if ((write_count == EN_INVALID_PARAM) || (write_count == EN_ERROR)) {
    GELOGE(ge::FAILED, "Write data failed. mmpa error no is %d", write_count);
    EXPECT_EQ(mmClose(fd), EN_OK);
    return ge::GRAPH_FAILED;
  }
  EXPECT_EQ(mmClose(fd), EN_OK);
  return ge::GRAPH_SUCCESS;
}

ge::graphStatus RmOmOppDir(const std::string &opp_dir) {
  if (opp_dir.empty()) {
    GELOGD("opp dir is empty, no need remove");
    return ge::GRAPH_SUCCESS;
  }

  if (mmRmdir(opp_dir.c_str()) != 0) {
    const ge::char_t *error = mmDlerror();
    error = (error == nullptr) ? "" : error;
    GELOGE(ge::FAILED, "Failed to rm dir %s, errmsg: %s", opp_dir.c_str(), error);
    return ge::GRAPH_FAILED;
  }

  return ge::GRAPH_SUCCESS;
}

}

class OpImplSpaceRegistryV2UT : public testing::Test {
 protected:
  void SetUp() {}

  void TearDown() {
    gert::OpImplRegistryHolderManager::GetInstance().ClearOpImplRegistries();
    ge::MmpaStub::GetInstance().Reset();
  }
};

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistryV2_GetOrCreateRegistry_1so_Succeed) {
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
  gert::OpImplSpaceRegistryV2 space_registry_v2;
  for (const auto &so_bin : bins) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc({ge::AscendString(so_path.c_str())}, "")), ge::GRAPH_SUCCESS);
    ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
  };
  std::string so_data = so_name;
  auto registry_holder = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_data);
  EXPECT_NE(registry_holder, nullptr);
  EXPECT_NE(space_registry_v2.GetOpImpl("Add_0"), nullptr);
  EXPECT_EQ(space_registry_v2.GetOpImpl("Add_0")->private_attrs.size(), 0);
  auto reg_func = space_registry_v2.GetOpImpl("Add_0");
  EXPECT_NE(reg_func, nullptr);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->calc_op_param), 0x10);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->gen_task), 0x20);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->check_support), 0x30);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->op_select_format), 0x40);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->get_op_support_info), 0x50);
  EXPECT_EQ(reinterpret_cast<int64_t>(reg_func->get_op_specific_info), 0x60);
}

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistryV2_GetOrCreateRegistry_2so_Succeed) {
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
  std::string so_name2("libopsproto.so");
  std::string vendor_name2("/opp/DC");
  ge::OpSoBinPtr so_bin_ptr2 = CreateSoBinPtr(so_name2, vendor_name2);

  gert::OpImplSpaceRegistryV2 space_registry_v2;
  for (const auto &so_bin : {so_bin_ptr1, so_bin_ptr2}) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc({ge::AscendString(so_path.c_str())}, "")), ge::GRAPH_SUCCESS);
    ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
  }
  auto registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
  EXPECT_NE(space_registry_v2.GetOpImpl("Add_0"), nullptr);
  EXPECT_EQ(space_registry_v2.GetOpImpl("Add_0")->private_attrs.size(), 0);

  auto registry_holder2 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name2);
  EXPECT_NE(registry_holder2, nullptr);

  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 2);
  // 再次校验 registry_holder1
  registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
}

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistryV2_AddSomeSoToRegistry) {
  dlopen_num = 0;
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

  gert::OpImplSpaceRegistryV2 space_registry_v2;
  for (const auto &so_bin : {so_bin_ptr1, so_bin_ptr1, so_bin_ptr1}) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc({ge::AscendString(so_path.c_str())}, "")), ge::GRAPH_SUCCESS);
    ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
  }
  auto registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_EQ(dlopen_num, 1);
  EXPECT_EQ(space_registry_v2.impl_->op_impl_registries_.size(), 3);

  EXPECT_NE(registry_holder1, nullptr);
  EXPECT_NE(space_registry_v2.GetOpImpl("Add_0"), nullptr);
  EXPECT_EQ(space_registry_v2.GetOpImpl("Add_0")->private_attrs.size(), 0);

}

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistryV2_GetOrCreateRegistry_3so_Succeed) {
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

  std::string so_name2("libopsproto.so");
  std::string vendor_name2("/opp/DC");
  ge::OpSoBinPtr so_bin_ptr2 = CreateSoBinPtr(so_name2, vendor_name2);

  std::string so_name3("libopsproto.so");
  std::string vendor_name3("/opp/DC");
  ge::OpSoBinPtr so_bin_ptr3 = CreateSoBinPtr(so_name3, vendor_name3);

  gert::OpImplSpaceRegistryV2 space_registry_v2;
  for (const auto &so_bin : {so_bin_ptr1, so_bin_ptr2, so_bin_ptr3}) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc({ge::AscendString(so_path.c_str())}, "")), ge::GRAPH_SUCCESS);
    ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
  }

  auto registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
  EXPECT_NE(space_registry_v2.GetOpImpl("Add_0"), nullptr);
  EXPECT_EQ(space_registry_v2.GetOpImpl("Add_0")->private_attrs.size(), 0);

  auto registry_holder2 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name2);
  EXPECT_NE(registry_holder2, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 2);

  auto registry_holder3 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name2);
  EXPECT_NE(registry_holder2, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 2);

  // 再次校验 registry_holder1
  registry_holder1 = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_name1);
  EXPECT_NE(registry_holder1, nullptr);
}

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistry_AddRegistry_Succeed) {
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 3;

  gert::OpImplSpaceRegistryV2 space_registry_v2;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  for (const auto &so_bin : {so_bin_ptr}) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc({ge::AscendString(so_path.c_str())}, "")), ge::GRAPH_SUCCESS);
    ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
  }

  auto func = space_registry_v2.GetOpImpl("Add_0");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x10);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x20);

  func = space_registry_v2.GetOpImpl("Add_1");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x11);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x21);

  func = space_registry_v2.GetOpImpl("Add_2");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x12);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x22);

  func = space_registry_v2.GetOpImpl("Add_3");
  EXPECT_EQ(func, nullptr);
}

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistry_AddRegistry_SucceedV2) {
  enable_OpImplFunctions_V2 = true;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 1;

  gert::OpImplSpaceRegistryV2 space_registry_v2;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  gert::OpImplKernelRegistry::OpImplFunctionsV2 funcs;
  funcs.infer_symbol_shape = reinterpret_cast<gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc>(100);
  registry_holder->AddTypesToImpl("Add_test", funcs);

  gert::OpImplRegistry::GetInstance().GetAllTypesToImpl()["Add_test"]=funcs;
  const auto ret_impl = gert::OpImplRegistry::GetInstance();
  EXPECT_EQ(1, ret_impl.GetAllTypesToImpl().size());

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  for (const auto &so_bin : {so_bin_ptr}) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc({ge::AscendString(so_path.c_str())}, "")), ge::GRAPH_SUCCESS);
    ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
  }
  auto func = space_registry_v2.GetOpImpl("Add_test");
  EXPECT_EQ(func->infer_symbol_shape, reinterpret_cast<gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc>(100));
}

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistry_AddRegistry_SucceedV3) {
  enable_OpImplFunctions_V3 = true;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 3;

  gert::OpImplSpaceRegistryV2 space_registry_v2;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  for (const auto &so_bin : {so_bin_ptr}) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc({ge::AscendString(so_path.c_str())}, "")), ge::GRAPH_SUCCESS);
    ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
  }

  auto func = space_registry_v2.GetOpImpl("Add_0");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x10);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x20);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x30);

  func = space_registry_v2.GetOpImpl("Add_1");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x11);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x21);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x31);

  func = space_registry_v2.GetOpImpl("Add_2");
  EXPECT_EQ(func->tiling, (gert::OpImplRegisterV2::TilingKernelFunc) 0x12);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x22);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x32);

  func = space_registry_v2.GetOpImpl("Add_3");
  EXPECT_EQ(func, nullptr);
}

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistry_AddRegistry_WithSameOptype_Succeed) {
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

TEST_F(OpImplSpaceRegistryV2UT, OpImplSpaceRegistry_AddRegistry_NoTiling) {
  enable_OpImplFunctions_V3_no_tiling = true;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 3;

  gert::OpImplSpaceRegistryV2 space_registry_v2;
  auto registry_holder = std::make_shared<gert::OmOpImplRegistryHolder>();

  std::string so_name("libopmaster.so");
  std::string vendor_name("/opp/MDC");
  ge::OpSoBinPtr so_bin_ptr = CreateSoBinPtr(so_name, vendor_name);
  for (const auto &so_bin : {so_bin_ptr}) {
    std::string so_bin_data(so_bin->GetBinData(), so_bin->GetBinData() + so_bin->GetBinDataSize());
    std::string opp_dir;
    EXPECT_EQ(CreateOmOppDir(opp_dir), ge::GRAPH_SUCCESS);

    const std::string so_path = opp_dir + so_bin->GetSoName();
    if (SaveToFile(so_bin, so_path) != ge::GRAPH_SUCCESS) {
      ASSERT_EQ(RmOmOppDir(opp_dir), ge::GRAPH_SUCCESS);
    }
    if (access(so_path.c_str(), R_OK) == -1) {
      perror("access failed");
    }
    EXPECT_NE(
        mmDlopen(so_path.c_str(),
                 static_cast<int32_t>(static_cast<uint32_t>(MMPA_RTLD_NOW) | static_cast<uint32_t>(MMPA_RTLD_GLOBAL))),
        nullptr);
    std::vector<ge::AscendString> opp_path_vector = {ge::AscendString(so_path.c_str())};
    EXPECT_EQ(space_registry_v2.AddSoToRegistry(gert::OppSoDesc(opp_path_vector, "")), ge::GRAPH_SUCCESS);
  };

  auto func = space_registry_v2.GetOpImpl("Add_0");
  EXPECT_EQ(func->tiling, nullptr);
  auto &instance = ErrorManager::GetInstance();
  EXPECT_EQ(instance.Init(""), -1);
  instance.is_init_ = true;

  std::ofstream out("out.json");
  if (out.is_open()){
    out << "{\"error_info_list\":[{\"ErrCode\":\"W11003\", \"ErrMessage\":\"Operator [%s] is missing required deliverable [%s].\", \"Arglist\":\"optype, func\"}]}";
    out.close();
  }
  nlohmann::json json_file;
  EXPECT_EQ(instance.ReadJsonFile("out.json", &json_file), 0);
  EXPECT_EQ(instance.ParseJsonFormatString(ge::PtrToPtr<nlohmann::json, void>(&json_file)), 0);

  REPORT_PREDEFINED_ERR_MSG("W11003", std::vector<const char *>({"optype", "func"}),
                                  std::vector<const char *>({"123", "inferDataType"}));
  std::string res(error_message::GetErrMgrErrorMessage().get());
  res = error_message::GetErrMgrWarningMessage().get();
  EXPECT_EQ(res.find("W11003") != std::string::npos, true);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x20);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x30);

  func = space_registry_v2.GetOpImpl("Add_1");
  EXPECT_EQ(func->tiling, nullptr);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x21);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x31);

  func = space_registry_v2.GetOpImpl("Add_2");
  EXPECT_EQ(func->tiling, nullptr);
  EXPECT_EQ(func->infer_shape, (gert::OpImplRegisterV2::InferShapeKernelFunc) 0x22);
  EXPECT_EQ(func->infer_symbol_shape, (gert::OpImplKernelRegistry::InferSymbolShapeKernelFunc) 0x32);

  func = space_registry_v2.GetOpImpl("Add_3");
  EXPECT_EQ(func, nullptr);
}

TEST_F(OpImplSpaceRegistryV2UT, DefaultOpImplSpaceRegistry_SetSpaceRegistry_Succeed) {
  auto space_registry_v2 = std::make_shared<gert::OpImplSpaceRegistryV2>();
  gert::DefaultOpImplSpaceRegistryV2::GetInstance().SetSpaceRegistry(space_registry_v2);
  EXPECT_NE(gert::DefaultOpImplSpaceRegistryV2::GetInstance().GetSpaceRegistry(), nullptr);
  gert::DefaultOpImplSpaceRegistryV2::GetInstance().ClearSpaceRegistry();
}
}  // namespace gert_test
