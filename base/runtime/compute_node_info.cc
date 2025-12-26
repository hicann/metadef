/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/compute_node_info.h"
#include "common/checker.h"
namespace gert {
ge::graphStatus ComputeNodeInfo::CalcSize(const size_t ir_inputs_num, const size_t inputs_num,
                                          const size_t outputs_num, size_t &total_size) {
  return CalcSize(ir_inputs_num, 0U, inputs_num, outputs_num, total_size);
}
void ComputeNodeInfo::Init(const size_t ir_inputs_num, const size_t inputs_num, const size_t outputs_num,
                           const char *node_name, const char *node_type) {
  Init(ir_inputs_num, 0U, inputs_num, outputs_num, 0U, node_name, node_type);
}
ge::graphStatus ComputeNodeInfo::CalcSize(const size_t ir_inputs_num, const size_t ir_outputs_num,
                                          const size_t inputs_num, const size_t outputs_num, size_t &total_size) {
  size_t ir_inputs_size;
  size_t ir_outputs_size;
  size_t inputs_size;
  size_t outputs_size;
  GE_ASSERT_TRUE(!ge::MulOverflow(sizeof(AnchorInstanceInfo), ir_inputs_num, ir_inputs_size));
  GE_ASSERT_TRUE(!ge::MulOverflow(sizeof(AnchorInstanceInfo), ir_outputs_num, ir_outputs_size));
  GE_ASSERT_TRUE(!ge::MulOverflow(sizeof(CompileTimeTensorDesc), inputs_num, inputs_size));
  GE_ASSERT_TRUE(!ge::MulOverflow(sizeof(CompileTimeTensorDesc), outputs_num, outputs_size));

  total_size = sizeof(ComputeNodeInfo);
  GE_ASSERT_TRUE(!ge::AddOverflow(total_size, ir_inputs_size, total_size));
  GE_ASSERT_TRUE(!ge::AddOverflow(total_size, ir_outputs_size, total_size));
  GE_ASSERT_TRUE(!ge::AddOverflow(total_size, inputs_size, total_size));
  GE_ASSERT_TRUE(!ge::AddOverflow(total_size, outputs_size, total_size));
  return ge::GRAPH_SUCCESS;
}
void ComputeNodeInfo::Init(const size_t ir_inputs_num, const size_t ir_outputs_num, const size_t inputs_num,
                           const size_t outputs_num, const size_t attr_size, const ge::char_t *node_name,
                           const ge::char_t *node_type) {
  ir_inputs_num_ = ir_inputs_num;
  ir_outputs_num_ = ir_outputs_num;
  inputs_num_ = inputs_num;
  outputs_num_ = outputs_num;
  node_name_ = node_name;
  node_type_ = node_type;
  runtime_attr_size_ = attr_size;
  (void)memset_s(reserved_, sizeof(reserved_), 0, sizeof(reserved_));
}
AnchorInstanceInfo *ComputeNodeInfo::MutableInputInstanceInfo(const size_t ir_index) const {
  return const_cast<AnchorInstanceInfo *>(GetInputInstanceInfo(ir_index));
}
AnchorInstanceInfo *ComputeNodeInfo::MutableOutputInstanceInfo(const size_t ir_index) const {
  return const_cast<AnchorInstanceInfo *>(GetOutputInstanceInfo(ir_index));
}
CompileTimeTensorDesc *ComputeNodeInfo::MutableInputTdInfo(const size_t index) const {
  return const_cast<CompileTimeTensorDesc *>(GetInputTdInfo(index));
}
CompileTimeTensorDesc *ComputeNodeInfo::MutableOutputTdInfo(const size_t index) const {
  return const_cast<CompileTimeTensorDesc *>(GetOutputTdInfo(index));
}
RuntimeAttrs *ComputeNodeInfo::MutableAttrs() const {
  return const_cast<RuntimeAttrs *>(GetAttrs());
}
}  // namespace gert
