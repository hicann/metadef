/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/context_holder.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "common/checker.h"

namespace gert {
void *ContextHolderVoid::GetContext() const {
  GE_ASSERT_NOTNULL(ctx_holder_impl_, "ctx_holder_impl_ is null");
  return ctx_holder_impl_->GetContext<void *>();
}

ContextHolderVoid::ContextHolderVoid() = default;
ContextHolderVoid::~ContextHolderVoid() = default;
ContextHolderVoid::ContextHolderVoid(ContextHolderVoid &&other) noexcept {
  ctx_holder_impl_ = std::move(other.ctx_holder_impl_);
}
ContextHolderVoid &ContextHolderVoid::operator=(ContextHolderVoid &&other) noexcept {
  if (this != &other) {
    ctx_holder_impl_ = std::move(other.ctx_holder_impl_);
  }
  return *this;
}
}  // namespace gert
