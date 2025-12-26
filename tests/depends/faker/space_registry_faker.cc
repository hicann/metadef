/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#define private public
#include "base/registry/op_impl_space_registry_v2.h"
#undef private
#include "register/op_impl_registry_api.h"
#include "register/op_impl_registry_holder_manager.h"
#include "register/op_impl_space_registry.h"
#include "graph/any_value.h"
#include "common/ge_common/debug/ge_log.h"
#include "space_registry_faker.h"

namespace gert {
using namespace ge;
OpImplSpaceRegistryPtr SpaceRegistryFaker::Build() {
  auto impl_num = GetRegisteredOpNum();
  auto impl_funcs = std::unique_ptr<TypesToImplV2[]>(new (std::nothrow) TypesToImplV2[impl_num]);
  auto ret = GetOpImplFunctionsV2(reinterpret_cast<TypesToImplV2 *>(impl_funcs.get()), impl_num);
  if (ret != ge::GRAPH_SUCCESS) {
    GELOGE(ge::FAILED, "Get functions from OpImplRegistry failed!");
    return nullptr;
  }
  auto registry_holder = std::make_shared<gert::OpImplRegistryHolder>();
  auto &types_to_impl = registry_holder->GetTypesToImpl();
  for (size_t i = 0U; i < impl_num; ++i) {
    types_to_impl[impl_funcs[i].op_type] = impl_funcs[i].funcs;
  }
  GELOGI("ori size:%zu, after size:%zu", types_to_impl.size(), registry_holder->GetTypesToImpl().size());
  auto space_registry = std::make_shared<gert::OpImplSpaceRegistry>();
  space_registry->AddRegistry(registry_holder);
  return space_registry;
}

OpImplSpaceRegistryV2Ptr SpaceRegistryFaker::BuildV2() {
  auto impl_num = GetRegisteredOpNum();
  auto impl_funcs = std::unique_ptr<TypesToImplV2[]>(new (std::nothrow) TypesToImplV2[impl_num]);
  auto ret = GetOpImplFunctionsV2(reinterpret_cast<TypesToImplV2 *>(impl_funcs.get()), impl_num);
  if (ret != ge::GRAPH_SUCCESS) {
    GELOGE(ge::FAILED, "Get functions from OpImplRegistry failed!");
    return nullptr;
  }
  auto registry_holder = std::make_shared<gert::OpImplRegistryHolder>();
  auto &types_to_impl = registry_holder->GetTypesToImpl();
  for (size_t i = 0U; i < impl_num; ++i) {
    types_to_impl[impl_funcs[i].op_type] = impl_funcs[i].funcs;
  }
  GELOGI("ori size:%zu, after size:%zu", types_to_impl.size(), registry_holder->GetTypesToImpl().size());
  auto space_registry = std::make_shared<gert::OpImplSpaceRegistryV2>();
  space_registry->AddRegistry(registry_holder);
  return space_registry;
}

void SpaceRegistryFaker::UpdateOpImplToDefaultSpaceRegistry() {
  auto space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry();
  if (space_registry != nullptr) {
    GELOGD("Default Space registry already exist!");
    return;
  }
  auto impl_num = GetRegisteredOpNum();
  auto impl_funcs = std::unique_ptr<TypesToImplV2[]>(new (std::nothrow) TypesToImplV2[impl_num]);
  auto ret = GetOpImplFunctionsV2(reinterpret_cast<TypesToImplV2 *>(impl_funcs.get()), impl_num);
  if (ret != ge::GRAPH_SUCCESS) {
    GELOGE(ge::FAILED, "Get functions from OpImplRegistry failed!");
    return;
  }
  auto registry_holder = std::make_shared<gert::OpImplRegistryHolder>();
  auto &types_to_impl = registry_holder->GetTypesToImpl();
  for (size_t i = 0U; i < impl_num; ++i) {
    types_to_impl[impl_funcs[i].op_type] = impl_funcs[i].funcs;
  }
  GELOGI("ori size:%zu, after size:%zu", types_to_impl.size(), registry_holder->GetTypesToImpl().size());
  space_registry = std::make_shared<OpImplSpaceRegistry>();
  if (space_registry == nullptr) {
    GELOGE(ge::FAILED, "Create space registry failed!");
    return;
  }
  space_registry->AddRegistry(registry_holder);
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(space_registry);
}

void SpaceRegistryFaker::SetefaultSpaceRegistryNull() {
  gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr);
}

}
