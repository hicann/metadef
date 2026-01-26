/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef METADEF_EXE_BASE_CONTEXT_BUILDER_OP_CONTEXT_BUILDER_IMPL_H_
#define METADEF_EXE_BASE_CONTEXT_BUILDER_OP_CONTEXT_BUILDER_IMPL_H_
#include <memory>
#include "securec.h"
#include "exe_graph/runtime/kernel_context.h"
#include "exe_graph/runtime/tiling_context.h"
#include "exe_graph/runtime/tiling_parse_context.h"
#include "exe_graph/runtime/compute_node_info.h"
#include "exe_graph/runtime/continuous_vector.h"
#include "common/ge_common/debug/ge_log.h"
#include "common/checker.h"
#include "op_info.h"
#include "base/runtime/runtime_attrs_def.h"
#include "graph/debug/ge_util.h"
namespace gert {
struct TilingInfo {
  const void *compile_info_ = nullptr;
  const void *platform_info_ = nullptr;
  std::pair<const void *, gert::Chain::Deleter> tiling_data_ = {nullptr, nullptr};
  int32_t deterministic_ = 0;
  const gert::ContinuousVector *workspace_ = nullptr;
};
struct TilingParseInfo {
  const ge::char_t *compiled_json_ = nullptr;
};
class ContextHolderImpl {
 public:
  ContextHolderImpl() = default;
  ContextHolderImpl(ContextHolderImpl &&holder) noexcept {
    context_holder_ = std::move(holder.context_holder_);
    value_holder_ = std::move(holder.value_holder_);
    compute_node_info_holder_ = std::move(holder.compute_node_info_holder_);
    string_pool_ = holder.string_pool_;
    context_ = holder.context_;
    holder.context_ = nullptr;
  }

  ContextHolderImpl &operator=(ContextHolderImpl &&holder) noexcept {
    context_holder_ = std::move(holder.context_holder_);
    value_holder_ = std::move(holder.value_holder_);
    compute_node_info_holder_ = std::move(holder.compute_node_info_holder_);
    string_pool_ = std::move(holder.string_pool_);
    context_ = holder.context_;
    holder.context_ = nullptr;
    return *this;
  }

  ~ContextHolderImpl() {
    for (auto &value : value_holder_) {
      value.Set(nullptr, nullptr);
    }
  }
  template<typename T>
  auto GetContext() const -> T* {
    return reinterpret_cast<T *>(context_);
  }

  std::unique_ptr<uint8_t[]> context_holder_;
  std::vector<Chain> value_holder_;
  std::unique_ptr<uint8_t[]> compute_node_info_holder_;
  std::vector<std::string> string_pool_;
  KernelContext *context_;
};

class ContextBuilderImpl {
 public:
  ContextBuilderImpl() = default;
  virtual ~ContextBuilderImpl() = default;

  OpInfo &MutableOpInfo() {
    return op_info_;
  }

  void SetCompiledInfo(const void *compile_info) {
    tiling_info_.compile_info_ = compile_info;
  }

  void SetPlatformInfo(const void *platform_info) {
    tiling_info_.platform_info_ = platform_info;
  }
  void SetDeterministic(int32_t deterministic) {
    tiling_info_.deterministic_ = deterministic;
  }

  void SetCompiledJson(const ge::char_t *compiled_json) {
    tiling_parse_info_.compiled_json_ = compiled_json;
  }

  void SetTilingData(const void *tiling_data, gert::Chain::Deleter deleter) {
    if (tiling_info_.tiling_data_.first != nullptr && tiling_info_.tiling_data_.second != nullptr) {
      tiling_info_.tiling_data_.second(const_cast<void*>(tiling_info_.tiling_data_.first));
    }
    tiling_info_.tiling_data_ = {tiling_data, deleter};
  }

  void SetWorkspace(const gert::ContinuousVector *workspace) {
    tiling_info_.workspace_ = workspace;
  }

  void Inputs(std::vector<void *> inputs) {
    for (auto i : inputs) {
      (void) input_values_.emplace_back(std::make_pair(i, nullptr));
    }
  }

  void Outputs(std::vector<void *> outputs) {
    for (auto i : outputs) {
      (void) output_values_.emplace_back(std::make_pair(i, nullptr));
    }
  }

 protected:
  ge::graphStatus BuildCtx(ContextHolderImpl &holder);
  ge::graphStatus InitCompileTimeTD(ComputeNodeInfo &compute_node_info);
  std::unique_ptr<uint8_t[]> CreateComputeNodeInfoImpl(const std::unique_ptr<uint8_t[]> &attr_buf,
                                                       size_t attr_size, const OpInfo &op_info,
                                                       std::vector<std::string> &string_pool, size_t &total_size);
  ge::graphStatus CreateComputeNodeInfo(ContextHolderImpl &holder);
  ge::graphStatus InitIOInstanceInfo(ComputeNodeInfo &compute_node_info);
  ge::graphStatus SetCompileTimeTd(const ContextTensorDesc &desc, CompileTimeTensorDesc &td) const;

  OpInfo op_info_;
  TilingInfo tiling_info_;
  TilingParseInfo tiling_parse_info_;
  std::vector<std::pair<const void *, gert::Chain::Deleter>> input_values_;
  std::vector<std::pair<const void *, gert::Chain::Deleter>> output_values_;
 private:
  bool use_data_type_ptr_{false};
};
}  // namespace gert

#endif  // METADEF_EXE_BASE_CONTEXT_BUILDER_OP_CONTEXT_BUILDER_IMPL_H_