/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/op_infer_shape_context_builder.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/context_holder_builder.h"
#include "common/ge_common/util.h"
#include "op_info.h"
#include <memory>
#include "graph/debug/ge_util.h"

namespace gert {
class OpInferShapeContextBuilderImpl : public ContextBuilderImpl {
 public:
  OpInferShapeContextBuilderImpl() : ContextBuilderImpl() {}
  ~OpInferShapeContextBuilderImpl() override = default;

  std::unique_ptr<ContextHolderImpl> BuildInferShapeContext() {
    auto holder = ge::ComGraphMakeUnique<ContextHolderImpl>();
    GE_ASSERT_NOTNULL(holder, "Create ContextHolderImpl failed.");
    GE_ASSERT_SUCCESS(CreateComputeNodeInfo(*holder), "Create compute node info failed.");
    input_values_.emplace_back(std::make_pair(nullptr, nullptr));  // FindInferShapeFunc
    std::vector<std::pair<void *, gert::Chain::Deleter>> tmp_outputs;
    static auto shape_deleter = [](void *p) {
      if (p == nullptr) {
        return;
      }
      delete static_cast<gert::Shape *>(p);
    };
    for (size_t i = 0U; i < op_info_.output_instance_num; ++i) {
      output_values_.emplace_back(new (std::nothrow) gert::Shape(), shape_deleter);
    }
    GE_ASSERT_SUCCESS(BuildCtx(*holder), "BuildCtx failed.");
    return holder;
  }
};

static_assert(sizeof(OpInferShapeContextBuilderImpl) == sizeof(ContextBuilderImpl), "OpInferShapeContextBuilderImpl size error");

OpInferShapeContextBuilder::OpInferShapeContextBuilder()
    : OpContextBuilderBase<OpInferShapeContextBuilder>() {
  impl_ = ge::ComGraphMakeUnique<OpInferShapeContextBuilderImpl>();
}

OpInferShapeContextBuilder::~OpInferShapeContextBuilder() = default;

OpInferShapeContextBuilder &OpInferShapeContextBuilder::OutputTensorDesc(size_t index, ge::DataType dtype,
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

OpInferShapeContextBuilder &OpInferShapeContextBuilder::InputTensors(const std::vector<gert::Tensor *> &inputs) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  std::vector<void *> tmp_inputs;
  for (size_t i = 0; i < inputs.size(); ++i) {
    MutableInputDataType(i) = inputs[i]->GetDataType();
    MutableInputOriginalFormat(i) = inputs[i]->GetOriginFormat();
    MutableInputStorageFormat(i) = inputs[i]->GetStorageFormat();
    MutableInputExpandDimsType(i) = inputs[i]->GetExpandDimsType();
    tmp_inputs.emplace_back(inputs[i]);
  }
  impl_->Inputs(std::move(tmp_inputs));
  return *this;
}

ContextHolder<InferShapeContext> OpInferShapeContextBuilder::Build() {
  GE_CHECK_NOTNULL_EXEC(impl_, return ContextHolder<InferShapeContext>());
  auto ctx_holder_impl = static_cast<OpInferShapeContextBuilderImpl *>(impl_.get())->BuildInferShapeContext();
  auto holder_void = ContextHolderBuilder::Create(std::move(ctx_holder_impl));
  return ContextHolder<InferShapeContext>(std::move(holder_void));
}

}  // namespace gert
