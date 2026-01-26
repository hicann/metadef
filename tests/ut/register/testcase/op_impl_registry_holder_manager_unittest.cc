/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "register/op_impl_registry_holder_manager.h"
#include "graph/any_value.h"
#include "graph/utils/file_utils.h"
#include "common/util/mem_utils.h"
#include "common/ge_common/debug/ge_log.h"
#include "mmpa/mmpa_api.h"
#include "tests/depends/mmpa/src/mmpa_stub.h"
#include <gtest/gtest.h>
#include <iostream>

namespace gert_test {
namespace {
constexpr const char *kHomeEnvName = "HOME";

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
    impl[i].op_type = type[i];
    impl[i].funcs = funcs;
  }
  return 0;
}
uint32_t GetOpCtImplFunctions(TypesToCtImpl *impl, size_t g_ct_impl_num) {
  gert::OpCtImplKernelRegistry::OpCtImplFunctions funcs;
  for (size_t i = 0; i < g_ct_impl_num; ++i) {
    funcs.calc_op_param = (gert::OpCtImplKernelRegistry::OpCalcParamKernelFunc) (0x10 + i);
    funcs.gen_task = (gert::OpCtImplKernelRegistry::OpGenTaskKernelFunc) (0x20 + i);
    impl[i].op_type = type[i];
    impl[i].funcs = funcs;
  }
  return 0;
}
void *mock_handle = nullptr;
bool dlsys_get_impl_func_fail = false;
bool dlsys_get_ct_impl_func_fail = false;
class MockMmpa : public ge::MmpaStubApi {
 public:
  void *DlSym(void *handle, const char *func_name) override {
    if (std::string(func_name) == "GetRegisteredOpNum") {
      return (void *) &GetRegisteredOpNum;
    } else if (std::string(func_name) == "GetOpImplFunctions") {
      if (dlsys_get_impl_func_fail) {
        dlsys_get_impl_func_fail = false;
        return nullptr;
      }
      return (void *) &GetOpImplFunctions;
    }
    if (std::string(func_name) == "GetRegisteredOpCtNum") {
      return (void *) &GetRegisteredOpCtNum;
    } else if (std::string(func_name) == "GetOpCtImplFunctions") {
      if (dlsys_get_ct_impl_func_fail) {
        dlsys_get_ct_impl_func_fail = false;
        return nullptr;
      }
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
    return 0L;
  }
};
}

class OpImplRegistryHolderManagerUT : public testing::Test {
 protected:
  void SetUp() {}

  void TearDown() {
    gert::OpImplRegistryHolderManager::GetInstance().ClearOpImplRegistries();
    ge::MmpaStub::GetInstance().Reset();
  }
};

TEST_F(OpImplRegistryHolderManagerUT, OpImplRegistryManager_UpdateOpImplRegistries_Succeed) {
  std::string so_data("libopmaster.so");
  {
    auto registry_holder = std::make_shared<gert::OpImplRegistryHolder>();
    gert::OpImplRegistryHolderManager::GetInstance().AddRegistry(so_data, registry_holder);
    auto tmp_registry_holder = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_data);
    EXPECT_NE(tmp_registry_holder, nullptr);
    EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 1);
  }
  auto tmp_registry_holder = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_data);
  //  EXPECT_EQ(tmp_registry_holder, nullptr); // 最终方案适配后使用此校验
  EXPECT_NE(tmp_registry_holder, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 1);

  gert::OpImplRegistryHolderManager::GetInstance().UpdateOpImplRegistries();
  tmp_registry_holder = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_data);
  //  EXPECT_EQ(tmp_registry_holder, nullptr);  // 最终方案适配后使用此校验
  //  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 0); // 最终方案适配后使用此校验
  EXPECT_NE(tmp_registry_holder, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 1);
}

TEST_F(OpImplRegistryHolderManagerUT, OpImplRegistryManager_UpdateOpImplRegistries_Succeed2) {
  std::string so_data("libopmaster.so");

  gert::OpImplRegistryHolderManager::GetInstance().AddRegistry(so_data, nullptr);
  auto tmp_registry_holder = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_data);
  EXPECT_EQ(tmp_registry_holder, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 1);

  gert::OpImplRegistryHolderManager::GetInstance().UpdateOpImplRegistries();
  tmp_registry_holder = gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistryHolder(so_data);
  EXPECT_EQ(tmp_registry_holder, nullptr);
  EXPECT_EQ(gert::OpImplRegistryHolderManager::GetInstance().GetOpImplRegistrySize(), 0);
}
}  // namespace gert_test
