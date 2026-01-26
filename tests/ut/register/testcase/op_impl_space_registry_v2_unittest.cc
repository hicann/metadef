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

}

class OpImplSpaceRegistryV2UT : public testing::Test {
 protected:
  void SetUp() {}

  void TearDown() {
    gert::OpImplRegistryHolderManager::GetInstance().ClearOpImplRegistries();
    ge::MmpaStub::GetInstance().Reset();
  }
};

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

TEST_F(OpImplSpaceRegistryV2UT, DefaultOpImplSpaceRegistry_SetSpaceRegistry_Succeed) {
  auto space_registry_v2 = std::make_shared<gert::OpImplSpaceRegistryV2>();
  gert::DefaultOpImplSpaceRegistryV2::GetInstance().SetSpaceRegistry(space_registry_v2);
  EXPECT_NE(gert::DefaultOpImplSpaceRegistryV2::GetInstance().GetSpaceRegistry(), nullptr);
  gert::DefaultOpImplSpaceRegistryV2::GetInstance().ClearSpaceRegistry();
}
}  // namespace gert_test
