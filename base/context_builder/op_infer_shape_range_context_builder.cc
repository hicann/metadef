/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/op_infer_shape_range_context_builder.h"
#include "exe_graph/runtime/infer_shape_range_context.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/context_holder_builder.h"
#include "common/ge_common/util.h"
#include "op_info.h"
#include <memory>
#include "graph/debug/ge_util.h"

namespace gert {
class OpInferShapeRangeContextBuilderImpl : public ContextBuilderImpl {
 public:
  OpInferShapeRangeContextBuilderImpl() : ContextBuilderImpl() {}
  ~OpInferShapeRangeContextBuilderImpl() override = default;

  std::unique_ptr<ContextHolderImpl> BuildInferShapeRangeContext() {
    auto holder = ge::ComGraphMakeUnique<ContextHolderImpl>();
    GE_ASSERT_NOTNULL(holder, "Create ContextHolderImpl failed.");
    GE_ASSERT_SUCCESS(CreateComputeNodeInfo(*holder), "Create compute node info failed.");
    std::vector<std::pair<void *, gert::Chain::Deleter>> tmp_outputs;
    static auto shape_range_deleter = [](void *p) {
      if (p == nullptr) {
        return;
      }
      delete static_cast<Range<gert::Shape>*>(p)->GetMin();
      delete static_cast<Range<gert::Shape>*>(p)->GetMax();
      delete static_cast<Range<gert::Shape>*>(p);
    };
    for (size_t i = 0U; i < op_info_.output_instance_num; ++i) {
      auto min_shape = ge::ComGraphMakeUnique<gert::Shape>();
      GE_ASSERT_NOTNULL(min_shape, "Create min shape failed.");
      auto max_shape = ge::ComGraphMakeUnique<gert::Shape>();
      GE_ASSERT_NOTNULL(max_shape, "Create max shape failed.");
      auto range = ge::ComGraphMakeUnique<Range<gert::Shape>>(min_shape.release(), max_shape.release());
      GE_ASSERT_NOTNULL(range, "Create range failed.");
      output_values_.emplace_back(range.release(), shape_range_deleter);
    }
    GE_ASSERT_SUCCESS(BuildCtx(*holder), "BuildCtx failed.");
    return holder;
  }
};
static_assert(sizeof(OpInferShapeRangeContextBuilderImpl) == sizeof(ContextBuilderImpl), "OpInferShapeRangeContextBuilderImpl size error");

OpInferShapeRangeContextBuilder::OpInferShapeRangeContextBuilder()
    : OpContextBuilderBase<OpInferShapeRangeContextBuilder>() {
  impl_ = ge::ComGraphMakeUnique<OpInferShapeRangeContextBuilderImpl>();
}
OpInferShapeRangeContextBuilder::~OpInferShapeRangeContextBuilder() = default;

OpInferShapeRangeContextBuilder &OpInferShapeRangeContextBuilder::InputTensorsRange(
    const std::vector<gert::Range<gert::Tensor> *> &inputs) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  std::vector<void *> tmp_inputs;
  for (size_t i = 0; i < inputs.size(); ++i) {
    if (inputs[i]->GetMin()->GetDataType() != inputs[i]->GetMax()->GetDataType() ||
      inputs[i]->GetMin()->GetFormat() != inputs[i]->GetMax()->GetFormat() ||
      inputs[i]->GetMin()->GetStorageFormat() != inputs[i]->GetMax()->GetStorageFormat() ||
      !(inputs[i]->GetMin()->GetExpandDimsType() == inputs[i]->GetMax()->GetExpandDimsType())) {
      GELOGE(ge::PARAM_INVALID,
             "Index %zu, Input max and min tensor data type/origin_format/storage_format are not equal, "
             "min data type: %d, max data type: %d, min format: %d, max format: %d, min storage format: %d, max "
             "storage format: %d, min expand dims type: %d, max expand dims type: %d",
             i, inputs[i]->GetMin()->GetDataType(), inputs[i]->GetMax()->GetDataType(),
             inputs[i]->GetMin()->GetFormat(), inputs[i]->GetMax()->GetFormat(),
             inputs[i]->GetMin()->GetStorageFormat(), inputs[i]->GetMax()->GetStorageFormat(),
             inputs[i]->GetMin()->GetExpandDimsType(), inputs[i]->GetMax()->GetExpandDimsType());
      return *this;
    }
    MutableInputDataType(i) = inputs[i]->GetMin()->GetDataType();
    MutableInputOriginalFormat(i) = inputs[i]->GetMin()->GetOriginFormat();
    MutableInputStorageFormat(i) = inputs[i]->GetMin()->GetStorageFormat();
    MutableInputExpandDimsType(i) = inputs[i]->GetMin()->GetExpandDimsType();
    tmp_inputs.emplace_back(inputs[i]);
  }
  impl_->Inputs(std::move(tmp_inputs));
  return *this;
}

OpInferShapeRangeContextBuilder &OpInferShapeRangeContextBuilder::OutputTensorDesc(size_t index, ge::DataType dtype,
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

ContextHolder<InferShapeRangeContext> OpInferShapeRangeContextBuilder::Build() {
  GE_CHECK_NOTNULL_EXEC(impl_, return ContextHolder<InferShapeRangeContext>());
  auto ctx_holder_impl = static_cast<OpInferShapeRangeContextBuilderImpl *>(impl_.get())->BuildInferShapeRangeContext();
  auto holder_void = ContextHolderBuilder::Create(std::move(ctx_holder_impl));
  return ContextHolder<InferShapeRangeContext>(std::move(holder_void));
}

}  // namespace gert
