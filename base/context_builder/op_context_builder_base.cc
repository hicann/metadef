/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <memory>
#include "exe_graph/runtime/tensor.h"
#include "common/ge_common/util.h"
#include "graph/debug/ge_util.h"
#include "base/context_builder/op_context_builder_base.h"
#include "base/context_builder/op_tiling_context_builder.h"
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/op_infer_shape_context_builder.h"
#include "base/context_builder/op_infer_datatype_context_builder.h"
#include "base/context_builder/op_tiling_parse_context_builder.h"
#include "base/context_builder/op_infer_shape_range_context_builder.h"
#include "base/context_builder/op_kernel_run_context_builder.h"

namespace gert {
template<typename T>
OpContextBuilderBase<T>::OpContextBuilderBase() : impl_(ge::ComGraphMakeUnique<ContextBuilderImpl>()) {}
template<typename T>
OpContextBuilderBase<T>::~OpContextBuilderBase() = default;

template<typename T>
T &OpContextBuilderBase<T>::OpType(const ge::AscendString &op_type) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().op_type = op_type.GetString();
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::OpName(const ge::AscendString &op_name) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().op_name = op_name.GetString();
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::IONum(size_t input_ir_num, size_t output_ir_num) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  auto &op_info = impl_->MutableOpInfo();
  if (!op_info.input_instance.empty() || !op_info.output_instance.empty()) {
    GELOGW("IO has been set. Set IO Num failed!");
    return static_cast<T &>(*this);  // 已经设置过输入输出， 无需不允许再次设置
  }
  op_info.input_ir_num = input_ir_num;
  op_info.output_ir_num = output_ir_num;
  op_info.input_tensor_descs.resize(op_info.input_ir_num, ContextTensorDesc());
  op_info.output_tensor_descs.resize(op_info.output_ir_num, ContextTensorDesc());
  op_info.input_instance.resize(op_info.input_ir_num, 1);
  op_info.output_instance.resize(op_info.output_ir_num, 1);
  op_info.input_instance_num = op_info.input_ir_num;
  op_info.output_instance_num = op_info.output_ir_num;
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::IOInstanceNum(const std::vector<uint32_t> &input_instance_num,
                                          const std::vector<uint32_t> &output_instance_num) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  auto &op_info = impl_->MutableOpInfo();
  op_info.input_instance = input_instance_num;
  op_info.output_instance = output_instance_num;
  op_info.input_ir_num = input_instance_num.size();
  op_info.output_ir_num = output_instance_num.size();
  op_info.input_instance_num = 0U;
  op_info.output_instance_num = 0U;
  for (const auto &num : op_info.input_instance) {
    op_info.input_instance_num += num;
  }
  op_info.input_tensor_descs.resize(op_info.input_instance_num, ContextTensorDesc());
  for (const auto &num : op_info.output_instance) {
    op_info.output_instance_num += num;
  }
  op_info.output_tensor_descs.resize(op_info.output_instance_num, ContextTensorDesc());
  return static_cast<T &>(*this);
}

template<typename T>
ge::DataType &OpContextBuilderBase<T>::MutableInputDataType(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().input_tensor_descs.size()) {
    static ge::DataType default_dtype = ge::DT_MAX;
    GELOGE(ge::PARAM_INVALID, "Input index %zu is out of range, input tensor desc size is %zu", index,
           impl_->MutableOpInfo().input_tensor_descs.size());
    return default_dtype;
  }
  return impl_->MutableOpInfo().input_tensor_descs[index].dtype;
}

template<typename T>
ge::Format &OpContextBuilderBase<T>::MutableInputOriginalFormat(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().input_tensor_descs.size()) {
    static ge::Format default_format = ge::FORMAT_MAX;
    GELOGE(ge::PARAM_INVALID, "Input index %zu is out of range, input tensor desc size is %zu", index,
           impl_->MutableOpInfo().input_tensor_descs.size());
    return default_format;
  }
  return impl_->MutableOpInfo().input_tensor_descs[index].origin_format;
}

template<typename T>
ge::Format &OpContextBuilderBase<T>::MutableInputStorageFormat(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().input_tensor_descs.size()) {
    static ge::Format default_format = ge::FORMAT_MAX;
    GELOGE(ge::PARAM_INVALID, "Input index %zu is out of range, input tensor desc size is %zu", index,
           impl_->MutableOpInfo().input_tensor_descs.size());
    return default_format;
  }
  return impl_->MutableOpInfo().input_tensor_descs[index].storage_format;
}

template<typename T>
gert::ExpandDimsType &OpContextBuilderBase<T>::MutableInputExpandDimsType(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().input_tensor_descs.size()) {
    static gert::ExpandDimsType default_expand_dims_type;
    GELOGE(ge::PARAM_INVALID, "Input index %zu is out of range, input tensor desc size is %zu", index,
           impl_->MutableOpInfo().input_tensor_descs.size());
    return default_expand_dims_type;
  }
  return impl_->MutableOpInfo().input_tensor_descs[index].expand_dims_type;
}

template<typename T>
DataType &OpContextBuilderBase<T>::MutableOutputDataType(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().output_tensor_descs.size()) {
    static ge::DataType default_dtype = ge::DT_MAX;
    GELOGE(ge::PARAM_INVALID, "Output index %zu is out of range, output tensor desc size is %zu", index,
           impl_->MutableOpInfo().output_tensor_descs.size());
    return default_dtype;
  }
  return impl_->MutableOpInfo().output_tensor_descs[index].dtype;
}

template<typename T>
ge::Format &OpContextBuilderBase<T>::MutableOutputOriginalFormat(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().output_tensor_descs.size()) {
    static ge::Format default_format = ge::FORMAT_MAX;
    GELOGE(ge::PARAM_INVALID, "Output index %zu is out of range, output tensor desc size is %zu", index,
           impl_->MutableOpInfo().output_tensor_descs.size());
    return default_format;
  }
  return impl_->MutableOpInfo().output_tensor_descs[index].origin_format;
}

template<typename T>
ge::Format &OpContextBuilderBase<T>::MutableOutputStorageFormat(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().output_tensor_descs.size()) {
    static ge::Format default_format = ge::FORMAT_MAX;
    GELOGE(ge::PARAM_INVALID, "Output index %zu is out of range, output tensor desc size is %zu", index,
           impl_->MutableOpInfo().output_tensor_descs.size());
    return default_format;
  }
  return impl_->MutableOpInfo().output_tensor_descs[index].storage_format;
}

template<typename T>
gert::ExpandDimsType &OpContextBuilderBase<T>::MutableOutputExpandDimsType(size_t index) {
  if (impl_ == nullptr || index >= impl_->MutableOpInfo().output_tensor_descs.size()) {
    static gert::ExpandDimsType default_expand_dims_type;
    GELOGE(ge::PARAM_INVALID, "Output index %zu is out of range, output tensor desc size is %zu", index,
           impl_->MutableOpInfo().output_tensor_descs.size());
    return default_expand_dims_type;
  }
  return impl_->MutableOpInfo().output_tensor_descs[index].expand_dims_type;
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(bool attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<bool>(attr));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(int64_t attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<int64_t>(attr));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(float attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<float>(attr));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(const ge::AscendString &attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<std::string>(attr.GetString()));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(const std::vector<bool> &attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<std::vector<bool>>(attr));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(const std::vector<int64_t> &attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<std::vector<int64_t>>(attr));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(const std::vector<float> &attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<std::vector<float>>(attr));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(const std::vector<ge::AscendString> &attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  std::vector<std::string> attr_str;
  for (auto &item : attr) {
    attr_str.emplace_back(item.GetString());
  }
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<std::vector<std::string>>(attr_str));
  return static_cast<T &>(*this);
}

template<typename T>
T &OpContextBuilderBase<T>::AppendAttr(const std::vector<std::vector<int64_t>> &attr) {
  GE_CHECK_NOTNULL_EXEC(impl_, return static_cast<T &>(*this));
  impl_->MutableOpInfo().attrs.emplace_back(ge::AnyValue::CreateFrom<std::vector<std::vector<int64_t>>>(attr));
  return static_cast<T &>(*this);
}
template class OpContextBuilderBase<OpTilingContextBuilder>;
template class OpContextBuilderBase<OpInferDataTypeContextBuilder>;
template class OpContextBuilderBase<OpInferShapeContextBuilder>;
template class OpContextBuilderBase<OpTilingParseContextBuilder>;
template class OpContextBuilderBase<OpInferShapeRangeContextBuilder>;
template class OpContextBuilderBase<OpKernelContextBuilder>;
}  // namespace gert
