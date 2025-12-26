/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef AIR_CXX_TESTS_UT_GE_RUNTIME_V2_SPACE_REGISTRY_FAKER_H_
#define AIR_CXX_TESTS_UT_GE_RUNTIME_V2_SPACE_REGISTRY_FAKER_H_
#include "register/op_impl_registry_api.h"
#include "register/op_impl_registry_holder_manager.h"
#include "base/registry/op_impl_space_registry_v2.h"
#include "register/op_impl_space_registry.h"
#include "graph/any_value.h"
#include "common/ge_common/debug/ge_log.h"

namespace gert {
class SpaceRegistryFaker {
 public:
  OpImplSpaceRegistryPtr Build();
  OpImplSpaceRegistryV2Ptr BuildV2();
  static void UpdateOpImplToDefaultSpaceRegistry();
  static void SetefaultSpaceRegistryNull();
};
}  // namespace gert
#endif  //AIR_CXX_TESTS_UT_GE_RUNTIME_V2_SPACE_REGISTRY_FAKER_H_
