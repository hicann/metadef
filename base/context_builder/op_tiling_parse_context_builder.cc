/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/op_tiling_parse_context_builder.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/context_holder_builder.h"
#include "common/ge_common/util.h"
#include "op_info.h"
#include <memory>
#include "graph/debug/ge_util.h"

namespace gert {
class OpTilingParseContextBuilderImpl : public ContextBuilderImpl {
 public:
  using ContextBuilderImpl::ContextBuilderImpl;
  ~OpTilingParseContextBuilderImpl() override = default;

  std::unique_ptr<ContextHolderImpl> BuildTilingParseContext() {
    GE_ASSERT_NOTNULL(tiling_parse_info_.compiled_json_, "Compile json is nullptr");
    GE_ASSERT_NOTNULL(tiling_info_.platform_info_, "Platform info is nullptr");
    output_values_.clear();
    output_values_.resize(1);
    output_values_[0] = std::make_pair(tiling_info_.compile_info_, nullptr);
    auto holder = ge::ComGraphMakeUnique<ContextHolderImpl>();
    GE_ASSERT_NOTNULL(holder, "Create ContextHolderImpl failed.");
    GE_ASSERT_SUCCESS(CreateComputeNodeInfo(*holder), "Create compute node info failed.");
    auto compute_node_info = ge::PtrToPtr<uint8_t, ComputeNodeInfo>(holder->compute_node_info_holder_.get());
    input_values_.clear();
    (void)input_values_.emplace_back(tiling_parse_info_.compiled_json_, static_cast<Chain::Deleter>(nullptr));
    (void)input_values_.emplace_back(tiling_info_.platform_info_, nullptr);
    (void)input_values_.emplace_back(compute_node_info->GetNodeType(), nullptr);
    GE_ASSERT_SUCCESS(BuildCtx(*holder), "BuildCtx failed.");
    return holder;
  }
};
static_assert(sizeof(OpTilingParseContextBuilderImpl) == sizeof(ContextBuilderImpl),
              "OpTilingParseContextBuilderImpl size error");

OpTilingParseContextBuilder::OpTilingParseContextBuilder() : OpContextBuilderBase<OpTilingParseContextBuilder>() {
  impl_ = ge::ComGraphMakeUnique<OpTilingParseContextBuilderImpl>();
}

OpTilingParseContextBuilder::~OpTilingParseContextBuilder() = default;

OpTilingParseContextBuilder &OpTilingParseContextBuilder::CompiledJson(const ge::char_t *compiled_json) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetCompiledJson(compiled_json);
  return *this;
}
OpTilingParseContextBuilder &OpTilingParseContextBuilder::CompiledInfo(const void *compile_info) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetCompiledInfo(compile_info);
  return *this;
}
OpTilingParseContextBuilder &OpTilingParseContextBuilder::PlatformInfo(const void *platform_info) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetPlatformInfo(platform_info);
  return *this;
}

ContextHolder<TilingParseContext> OpTilingParseContextBuilder::Build() {
  GE_CHECK_NOTNULL_EXEC(impl_, return ContextHolder<TilingParseContext>());
  auto ctx_holder_impl = static_cast<OpTilingParseContextBuilderImpl *>(impl_.get())->BuildTilingParseContext();
  auto holder_void = ContextHolderBuilder::Create(std::move(ctx_holder_impl));
  return ContextHolder<TilingParseContext>(std::move(holder_void));
}

OpTilingParseContextBuilder &OpTilingParseContextBuilder::InputTensorDesc(size_t index, ge::DataType dtype,
                                                                          ge::Format origin_format,
                                                                          ge::Format storage_format,
                                                                          const gert::ExpandDimsType &expand_dims_type) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  MutableInputDataType(index) = dtype;
  MutableInputOriginalFormat(index) = origin_format;
  MutableInputStorageFormat(index) = storage_format;
  MutableInputExpandDimsType(index) = expand_dims_type;
  return *this;
}

OpTilingParseContextBuilder &OpTilingParseContextBuilder::OutputTensorDesc(size_t index, ge::DataType dtype,
                                                                           ge::Format origin_format,
                                                                           ge::Format storage_format,
                                                                           const gert::ExpandDimsType &expand_dims_type) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  MutableOutputDataType(index) = dtype;
  MutableOutputOriginalFormat(index) = origin_format;
  MutableOutputStorageFormat(index) = storage_format;
  MutableOutputExpandDimsType(index) = expand_dims_type;
  return *this;
}

}  // namespace gert