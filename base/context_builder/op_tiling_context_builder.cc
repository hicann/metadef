/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/op_tiling_context_builder.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/context_holder_builder.h"
#include "op_info.h"
#include "common/ge_common/util.h"
#include <memory>
#include "graph/debug/ge_util.h"

namespace gert {
class OpTilingContextBuilderImpl : public ContextBuilderImpl {
 public:
  OpTilingContextBuilderImpl() : ContextBuilderImpl() {}
  ~OpTilingContextBuilderImpl() override = default;

  std::unique_ptr<ContextHolderImpl> BuildTilingContext() {
    GE_ASSERT_NOTNULL(tiling_info_.compile_info_, "Compile info is nullptr");
    GE_ASSERT_NOTNULL(tiling_info_.platform_info_, "Platform info is nullptr");

    auto holder = ge::ComGraphMakeUnique<ContextHolderImpl>();
    GE_ASSERT_NOTNULL(holder, "Create ContextHolderImpl failed.");
    GE_ASSERT_SUCCESS(CreateComputeNodeInfo(*holder), "Create compute node info failed.");
    for (auto& outvaue : output_values_) {
      input_values_.emplace_back(outvaue.first, outvaue.second);
    }
    input_values_.emplace_back(tiling_info_.compile_info_, nullptr);   // TilingCompileInfo
    input_values_.emplace_back(tiling_info_.platform_info_, nullptr);  // PlatformInfo
    input_values_.emplace_back(nullptr, nullptr);                      // PrepareTilingFrameworkData
    input_values_.emplace_back(
        reinterpret_cast<void *>(tiling_info_.deterministic_), nullptr);  // Deterministic
    output_values_.resize(TilingContext::kOutputNum);
    output_values_[TilingContext::kOutputTilingData] =
        std::make_pair(tiling_info_.tiling_data_.first, tiling_info_.tiling_data_.second);
    output_values_[TilingContext::kOutputWorkspace] = std::make_pair(tiling_info_.workspace_, nullptr);
    GE_ASSERT_SUCCESS(BuildCtx(*holder), "BuildCtx failed.");
    return holder;
  }
};
static_assert(sizeof(OpTilingContextBuilderImpl) == sizeof(ContextBuilderImpl), "OpTilingContextBuilderImpl size error");

OpTilingContextBuilder::OpTilingContextBuilder() : OpContextBuilderBase<OpTilingContextBuilder>() {
  impl_ = ge::ComGraphMakeUnique<OpTilingContextBuilderImpl>();
}

OpTilingContextBuilder::~OpTilingContextBuilder() = default;

OpTilingContextBuilder &OpTilingContextBuilder::CompileInfo(const void *compile_info) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetCompiledInfo(compile_info);
  return *this;
}

OpTilingContextBuilder &OpTilingContextBuilder::PlatformInfo(const void *platform_info) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetPlatformInfo(platform_info);
  return *this;
}
OpTilingContextBuilder &OpTilingContextBuilder::Deterministic(int32_t deterministic) {
  if (deterministic != 0 && deterministic != 1) {
    GELOGE(ge::PARAM_INVALID, "Deterministic value is invalid, expect 0 or 1, but got %d", deterministic);
    return *this;
  }
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetDeterministic(deterministic);
  return *this;
}

OpTilingContextBuilder &OpTilingContextBuilder::TilingData(const gert::TilingData *tiling_data,
                                                           gert::Chain::Deleter deleter) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetTilingData(tiling_data, deleter);
  return *this;
}

OpTilingContextBuilder &OpTilingContextBuilder::TilingDataSize(size_t tiling_data_size) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  auto tiling_data = TilingData::CreateCap(tiling_data_size);
  static auto delete_tiling_data = [] (void *data) {
    if (data != nullptr) {
      delete [] static_cast<uint8_t *>(data);
    }
  };
  impl_->SetTilingData(tiling_data.release(), delete_tiling_data);
  return *this;
}

OpTilingContextBuilder &OpTilingContextBuilder::Workspace(const gert::ContinuousVector *workspace) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  impl_->SetWorkspace(workspace);
  return *this;
}

OpTilingContextBuilder &OpTilingContextBuilder::InputTensors(const std::vector<gert::Tensor *> &inputs) {
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

OpTilingContextBuilder &OpTilingContextBuilder::OutputTensors(const std::vector<gert::Tensor *> &outputs) {
  GE_CHECK_NOTNULL_EXEC(impl_, return *this);
  std::vector<void *> tmp_outputs;
  for (size_t i = 0; i < outputs.size(); ++i) {
    MutableOutputDataType(i) = outputs[i]->GetDataType();
    MutableOutputOriginalFormat(i) = outputs[i]->GetOriginFormat();
    MutableOutputStorageFormat(i) = outputs[i]->GetStorageFormat();
    MutableOutputExpandDimsType(i) = outputs[i]->GetExpandDimsType();
    tmp_outputs.emplace_back(outputs[i]);
  }
  impl_->Outputs(std::move(tmp_outputs));
  return *this;
}

ContextHolder<TilingContext> OpTilingContextBuilder::Build() {
  GE_CHECK_NOTNULL_EXEC(impl_, return ContextHolder<TilingContext>());
  auto ctx_holder_impl = static_cast<OpTilingContextBuilderImpl *>(impl_.get())->BuildTilingContext();
  auto holder_void = ContextHolderBuilder::Create(std::move(ctx_holder_impl));
  return ContextHolder<TilingContext>(std::move(holder_void));
}

}  // namespace gert