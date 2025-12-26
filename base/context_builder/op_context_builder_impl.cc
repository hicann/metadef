/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "base/context_builder/op_context_builder_impl.h"
#include "base/context_builder/op_kernel_run_context_builder.h"
#include "base/context_builder/op_tiling_context_builder.h"

#include "graph/debug/ge_util.h"
#include "base/attr/attrs_to_buffer.h"
namespace gert {
ge::graphStatus ContextBuilderImpl::SetCompileTimeTd(const ContextTensorDesc &desc, CompileTimeTensorDesc &td) {
  td.SetDataType(desc.dtype);
  td.SetOriginFormat(desc.origin_format);
  td.SetStorageFormat(desc.storage_format);
  td.SetExpandDimsType(desc.expand_dims_type);
  return ge::GRAPH_SUCCESS;
}

ge::graphStatus ContextBuilderImpl::InitIOInstanceInfo(ComputeNodeInfo &compute_node_info) {
  size_t input_index = 0U;
  for (size_t i = 0U; i < op_info_.input_instance.size(); ++i) {
    size_t instance_num = op_info_.input_instance[i];
    compute_node_info.MutableInputInstanceInfo(i)->SetInstantiationNum(instance_num);
    compute_node_info.MutableInputInstanceInfo(i)->SetInstanceStart(input_index);
    input_index += instance_num;
  }

  size_t output_index = 0U;
  for (size_t i = 0U; i < op_info_.output_instance.size(); ++i) {
    size_t instance_num = op_info_.output_instance[i];
    compute_node_info.MutableOutputInstanceInfo(i)->SetInstantiationNum(instance_num);
    compute_node_info.MutableOutputInstanceInfo(i)->SetInstanceStart(output_index);
    output_index += instance_num;
  }
  return ge::GRAPH_SUCCESS;
}

ge::graphStatus ContextBuilderImpl::InitCompileTimeTD(ComputeNodeInfo &compute_node_info) {
  for (size_t i = 0U; i < compute_node_info.GetInputsNum(); ++i) {
    const auto &ctx_io_desc = op_info_.input_tensor_descs[i];
    auto td = compute_node_info.MutableInputTdInfo(i);
    GE_ASSERT_NOTNULL(td, "tensor desc in compute node info is null");
    SetCompileTimeTd(ctx_io_desc, *td);
  }

  for (size_t i = 0U; i < compute_node_info.GetOutputsNum(); ++i) {
    const auto &ctx_io_desc = op_info_.output_tensor_descs[i];
    auto td = compute_node_info.MutableOutputTdInfo(i);
    GE_ASSERT_NOTNULL(td, "tensor desc in compute node info is null");
    SetCompileTimeTd(ctx_io_desc, *td);
  }
  return ge::SUCCESS;
}

std::unique_ptr<uint8_t[]> ContextBuilderImpl::CreateComputeNodeInfoImpl(const std::unique_ptr<uint8_t[]> &attr_buf,
                                                                         size_t attr_size,
                                                                         const OpInfo &op_info,
                                                                         std::vector<std::string> &string_pool,
                                                                         size_t &total_size) {
  const size_t ir_input_num = op_info.input_ir_num;
  const size_t ir_output_num = op_info.output_ir_num;
  const size_t input_num = op_info.input_instance_num;
  const size_t output_num = op_info.output_instance_num;
  GELOGD("opinfo: %s(%s), ir_input_num:%zu, ir_output_num:%zu, input_num:%zu, output_num:%zu.", op_info.op_name.c_str(),
         op_info.op_type.c_str(), ir_input_num, ir_output_num, input_num, output_num);
  GE_ASSERT_SUCCESS(ComputeNodeInfo::CalcSize(ir_input_num, ir_output_num, input_num, output_num, total_size));
  GE_ASSERT_TRUE(!ge::AddOverflow(total_size, attr_size, total_size));
  auto compute_node_info_holder = ge::ComGraphMakeUnique<uint8_t[]>(total_size);
  GE_ASSERT_NOTNULL(compute_node_info_holder, "Create compute node info holder failed");

  auto idx = string_pool.size();
  string_pool.emplace_back(op_info.op_name);
  string_pool.emplace_back(op_info.op_type);
  auto name_ptr = string_pool[idx].c_str();
  auto type_ptr = string_pool[idx + 1].c_str();

  auto compute_node_info = ge::PtrToPtr<uint8_t, ComputeNodeInfo>(compute_node_info_holder.get());
  compute_node_info->Init(ir_input_num, ir_output_num, input_num, output_num, attr_size, name_ptr, type_ptr);

  auto ret = InitIOInstanceInfo(*compute_node_info);
  GE_ASSERT_SUCCESS(ret, "Init input instance info for node:%s failed.", op_info.op_name.c_str());

  ret = InitCompileTimeTD(*compute_node_info);
  GE_ASSERT_SUCCESS(ret, "Init compile time tensor desc for node:%s failed.", op_info.op_name.c_str());

  auto attr = compute_node_info->MutableAttrs();
  const auto offset = ge::PtrToPtr<RuntimeAttrs, uint8_t>(attr) - compute_node_info_holder.get();
  GE_ASSERT_TRUE(
      static_cast<size_t>(offset) <= total_size,
      "Failed to create kernel context extend info, the offset of attr %zu beyond the total size of ExtendInfo %zu",
      offset, total_size);
  const auto outputs_ins_info_size = compute_node_info->GetIrOutputsNum() * sizeof(AnchorInstanceInfo);
  ret = memcpy_s(ge::PtrToPtr<RuntimeAttrs, uint8_t>(attr), (total_size - offset - outputs_ins_info_size),
                 attr_buf.get(), attr_size);
  GE_ASSERT_SUCCESS(ret, "memcpy_s failed, copy size is %zu, dst size is %zu", attr_size,
                    (total_size - offset - outputs_ins_info_size));
  GELOGI("Node %s, compute_node_info attr_size %zu, outputs_ins_info_size:%zu, offset:%zu, total_size:%zu.",
         op_info.op_name.c_str(), attr_size, outputs_ins_info_size, offset, total_size);
  return compute_node_info_holder;
}
ge::graphStatus ContextBuilderImpl::CreateComputeNodeInfo(ContextHolderImpl &holder) {
  GE_ASSERT_TRUE((!op_info_.op_type.empty()) && (!op_info_.op_name.empty()) && (op_info_.input_ir_num != 0) &&
                     (op_info_.output_ir_num != 0),
                 "Invalid params, op_type: %s, op_name: %s, input_num: %u, output_num: %u", op_info_.op_type.c_str(),
                 op_info_.op_name.c_str(), op_info_.input_ir_num, op_info_.output_ir_num);
  size_t attr_size;
  auto attr_buf = bg::CreateAttrBufferWithAttrs(op_info_.attrs, attr_size);

  size_t total_size = 0U;
  holder.compute_node_info_holder_ =
      CreateComputeNodeInfoImpl(attr_buf, attr_size, op_info_, holder.string_pool_, total_size);
  return ge::GRAPH_SUCCESS;
}
ge::graphStatus ContextBuilderImpl::BuildCtx(ContextHolderImpl &holder) {
  const auto in_size = input_values_.size();
  const auto out_size = output_values_.size();
  const auto io_size = in_size + out_size;
  const auto size = sizeof(KernelRunContext) + sizeof(Chain *) * (io_size);
  holder.context_holder_.reset(new (std::nothrow) uint8_t[size]);
  GE_ASSERT_NOTNULL(holder.context_holder_, "Create context holder failed.");

  holder.context_ = ge::PtrToPtr<uint8_t, KernelContext>(holder.context_holder_.get());
  auto kernel_run_context = holder.context_->GetContext();
  kernel_run_context->input_size = in_size;
  kernel_run_context->output_size = out_size;
  kernel_run_context->compute_node_info = holder.compute_node_info_holder_.get();
  kernel_run_context->output_start = &(kernel_run_context->values[kernel_run_context->input_size]);
  holder.value_holder_.resize(io_size);
  for (size_t i = 0UL; i < holder.value_holder_.size(); ++i) {
    kernel_run_context->values[i] = ge::PtrToPtr<Chain, AsyncAnyValue>(&holder.value_holder_[i]);
  }
  for (size_t i = 0UL; i < input_values_.size(); ++i) {
    holder.value_holder_[i].Set(const_cast<void *>(input_values_[i].first), input_values_[i].second);
  }
  for (size_t i = 0UL; i < output_values_.size(); ++i) {
    holder.value_holder_[input_values_.size() + i].Set(const_cast<void *>(output_values_[i].first),
                                                       output_values_[i].second);
  }
  return ge::GRAPH_SUCCESS;
}
}  // namespace gert