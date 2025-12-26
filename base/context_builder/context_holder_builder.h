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
#include "common/checker.h"
#ifndef METADEF_CXX_BASE_CONTEXT_BUILDER_CTX_HOLDER_BUILDER_H_
#define METADEF_CXX_BASE_CONTEXT_BUILDER_CTX_HOLDER_BUILDER_H_
namespace gert {
class ContextHolderBuilder {
 public:
  static ContextHolderVoid Create(std::unique_ptr<ContextHolderImpl> &&ctx_holder_impl) {
    GE_ASSERT_NOTNULL(ctx_holder_impl, "ctx_holder_impl is null while creating ContextHolder");
    ContextHolderVoid holder;
    holder.ctx_holder_impl_ = std::move(ctx_holder_impl);
    return holder;
  }
};
}  // namespace gert
#endif  // METADEF_CXX_BASE_CONTEXT_BUILDER_CTX_HOLDER_BUILDER_H_