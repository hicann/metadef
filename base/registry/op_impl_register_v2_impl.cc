/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "graph/any_value.h"
#include "base/registry/op_impl_register_v2_impl.h"

namespace gert {
OpImplRegisterV2Impl &OpImplRegisterV2Impl::InferSymbolShape(OpImplKernelRegistry::InferSymbolShapeKernelFunc func) {
  auto space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry();
  if (space_registry == nullptr) {
    space_registry = std::make_shared<gert::OpImplSpaceRegistry>();
    gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(space_registry);
  }
  auto funcs = space_registry->CreateOrGetOpImpl(op_type.GetString());
  GELOGI("Register infer symbol shape for %s.", op_type.GetString());
  if (funcs->infer_symbol_shape != nullptr) {
    GELOGW("[%s] infer_symbol_shape already registered, will using new function.", op_type.GetString());
  }
  funcs->infer_symbol_shape = func;
  return *this;
}
}  // namespace gert
