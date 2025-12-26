/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/op_kernel_run_context_builder.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/context_holder_builder.h"
#include "common/ge_common/util.h"
#include "op_info.h"
#include <memory>
#include "graph/debug/ge_util.h"

namespace gert {
class OpKernelRunContextBuilderImpl : public ContextBuilderImpl {
 public:
  OpKernelRunContextBuilderImpl() : ContextBuilderImpl() {}
  ~OpKernelRunContextBuilderImpl() override = default;

  std::unique_ptr<ContextHolderImpl> BuildKernelRunContext() {
    auto holder = ge::ComGraphMakeUnique<ContextHolderImpl>();
    GE_ASSERT_NOTNULL(holder, "Create ContextHolderImpl failed.");
    GE_ASSERT_SUCCESS(CreateComputeNodeInfo(*holder), "Create compute node info failed.");
    GE_ASSERT_SUCCESS(BuildCtx(*holder), "BuildCtx failed.");
    return holder;
  }
};
static_assert(sizeof(OpKernelRunContextBuilderImpl) == sizeof(ContextBuilderImpl),
              "OpKernelRunContextBuilderImpl size error");

OpKernelContextBuilder::OpKernelContextBuilder() : OpContextBuilderBase<OpKernelContextBuilder>() {
  impl_ = ge::ComGraphMakeUnique<OpKernelRunContextBuilderImpl>();
}

OpKernelContextBuilder::~OpKernelContextBuilder() = default;

OpKernelContextBuilder &OpKernelContextBuilder::Inputs(std::vector<void *> inputs) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->Inputs(std::move(inputs));
  return *this;
}

OpKernelContextBuilder &OpKernelContextBuilder::Outputs(std::vector<void *> outputs) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->Outputs(std::move(outputs));
  return *this;
}

OpKernelContextBuilder &OpKernelContextBuilder::InputTensorDesc(size_t index, ge::DataType dtype,
                                                                ge::Format origin_format, ge::Format storage_format,
                                                                const gert::ExpandDimsType &expand_dims_type) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  MutableInputDataType(index) = dtype;
  MutableInputOriginalFormat(index) = origin_format;
  MutableInputStorageFormat(index) = storage_format;
  MutableInputExpandDimsType(index) = expand_dims_type;
  return *this;
}

OpKernelContextBuilder &OpKernelContextBuilder::OutputTensorDesc(size_t index, ge::DataType dtype,
                                                                 ge::Format origin_format, ge::Format storage_format,
                                                                 const gert::ExpandDimsType &expand_dims_type) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  MutableOutputDataType(index) = dtype;
  MutableOutputOriginalFormat(index) = origin_format;
  MutableOutputStorageFormat(index) = storage_format;
  MutableOutputExpandDimsType(index) = expand_dims_type;
  return *this;
}

ContextHolder<KernelContext> OpKernelContextBuilder::Build() {
  GE_CHECK_NOTNULL_EXEC(impl_, return ContextHolder<KernelContext>());
  auto ctx_holder_impl = static_cast<OpKernelRunContextBuilderImpl *>(impl_.get())->BuildKernelRunContext();
  auto holder_void = ContextHolderBuilder::Create(std::move(ctx_holder_impl));
  return ContextHolder<KernelContext>(std::move(holder_void));
}

}  // namespace gert
