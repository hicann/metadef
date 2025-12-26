/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/op_infer_datatype_context_builder.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/context_holder_builder.h"
#include "common/ge_common/util.h"
#include "op_info.h"
#include <memory>
#include "securec.h"
#include "graph/debug/ge_util.h"

namespace gert {
class OpInferDataTypeContextBuilderImpl : public ContextBuilderImpl {
 public:
  OpInferDataTypeContextBuilderImpl() : ContextBuilderImpl() {}
  ~OpInferDataTypeContextBuilderImpl() override = default;

  std::unique_ptr<ContextHolderImpl> BuildInferDataTypeContext() {
    auto holder = ge::ComGraphMakeUnique<ContextHolderImpl>();
    GE_ASSERT_NOTNULL(holder, "Create ContextHolderImpl failed.");
    GE_ASSERT_SUCCESS(CreateComputeNodeInfo(*holder), "Create compute node info failed.");
    std::vector<std::pair<void *, gert::Chain::Deleter>> tmp_outputs;
    for (size_t i = 0U; i < op_info_.input_instance_num; ++i) {
      input_values_.emplace_back(std::make_pair<void *, gert::Chain::Deleter>(
          ge::ValueToPtr(MutableOpInfo().input_tensor_descs[i].dtype), nullptr));
    }
    for (size_t i = 0U; i < op_info_.output_instance_num; ++i) {
      output_values_.emplace_back(std::make_pair<void *, gert::Chain::Deleter>(ge::ValueToPtr(ge::DT_MAX), nullptr));
    }
    GE_ASSERT_SUCCESS(BuildCtx(*holder), "BuildCtx failed.");
    return holder;
  }
};

static_assert(sizeof(OpInferDataTypeContextBuilderImpl) == sizeof(ContextBuilderImpl), "OpInferDataTypeContextBuilderImpl size error");

OpInferDataTypeContextBuilder::OpInferDataTypeContextBuilder()
    : OpContextBuilderBase<OpInferDataTypeContextBuilder>() {
  impl_ = ge::ComGraphMakeUnique<OpInferDataTypeContextBuilderImpl>();
}

OpInferDataTypeContextBuilder::~OpInferDataTypeContextBuilder() = default;

OpInferDataTypeContextBuilder &OpInferDataTypeContextBuilder::InputTensorDesc(size_t index, ge::DataType dtype,
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

OpInferDataTypeContextBuilder &OpInferDataTypeContextBuilder::OutputTensorDesc(size_t index, ge::Format origin_format,
                                                                               ge::Format storage_format,
                                                                               const gert::ExpandDimsType &expand_dims_type) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  MutableOutputOriginalFormat(index) = origin_format;
  MutableOutputStorageFormat(index) = storage_format;
  MutableOutputExpandDimsType(index) = expand_dims_type;
  return *this;
}

ContextHolder<InferDataTypeContext> OpInferDataTypeContextBuilder::Build() {
  GE_CHECK_NOTNULL_EXEC(impl_, return ContextHolder<InferDataTypeContext>());
  auto ctx_holder_impl = static_cast<OpInferDataTypeContextBuilderImpl *>(impl_.get())->BuildInferDataTypeContext();
  auto holder_void = ContextHolderBuilder::Create(std::move(ctx_holder_impl));
  return ContextHolder<InferDataTypeContext>(std::move(holder_void));
}

}  // namespace gert
