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
#include "exe_graph/runtime/tiling_context.h"

int main() {
  // 必须随机造一个内存，不然编译器会静态分析出代码不可达，从而不进行全量符号链接
  auto data = std::shared_ptr<uint8_t>(new uint8_t[1000]);
  gert::TilingContext &tiling_context = *reinterpret_cast<gert::TilingContext *>(data.get());
  // TilingContext methods
  tiling_context.GetCompileInfo();
  tiling_context.GetCompileInfo<void>();
  tiling_context.GetInputShape(0);
  tiling_context.GetInputTensor(0);
  tiling_context.GetOutputShape(0);
  tiling_context.GetOptionalInputTensor(0);
  tiling_context.GetOptionalInputShape(0);
  tiling_context.GetOptionalInputDesc(0);
  tiling_context.GetDynamicInputShape(0, 0);
  tiling_context.GetDynamicInputTensor(0, 0);
  tiling_context.GetDynamicInputDesc(0, 0);

  tiling_context.GetBlockDim();
  tiling_context.NeedAtomic();
  tiling_context.GetScheduleMode();
  tiling_context.GetTilingCond();
  tiling_context.GetTilingKey();
  tiling_context.GetWorkspaceSizes(0);
  tiling_context.GetWorkspaceNum();
  tiling_context.GetDeterministic();
  tiling_context.GetPlatformInfo();

  // ExtendedKernelContext methods
  tiling_context.GetInputDesc(0);
  tiling_context.GetOutputDesc(0);
  tiling_context.GetDynamicInputDesc(0, 0);
  tiling_context.GetOptionalInputDesc(0);
  tiling_context.GetIrInputInstanceInfo(0);
  tiling_context.GetAttrs();
  tiling_context.GetComputeNodeInfo();
  tiling_context.GetComputeNodeInputNum();
  tiling_context.GetComputeNodeOutputNum();
  tiling_context.GetExtendInfo();
  tiling_context.GetComputeNodeInfo();
  tiling_context.GetKernelName();
  tiling_context.GetKernelType();
  tiling_context.GetNodeName();
  tiling_context.GetNodeType();

  tiling_context.SetBlockDim(0);
  tiling_context.SetNeedAtomic(true);
  tiling_context.SetScheduleMode(0);
  tiling_context.SetTilingCond(0);
  tiling_context.SetTilingKey(0);

  // TilingData methods
  tiling_context.GetTilingData<int>();

  // RawTilingData methods
  // 用于构造TilingData结构，不应该被Tiling函数使用
  auto &raw_tiling_data = *tiling_context.GetRawTilingData();
  raw_tiling_data.GetCapacity();
  raw_tiling_data.GetData();
  raw_tiling_data.SetDataSize(0);
  raw_tiling_data.Append(0);
  raw_tiling_data.Append(static_cast<int *>(nullptr), 0);
  raw_tiling_data.AppendConvertedAttrVal(nullptr, 1, gert::AttrDataType::kBfloat16, gert::AttrDataType::kBfloat16);

  // RuntimeAttrs methods
  const gert::RuntimeAttrs &runtime_attrs = *tiling_context.GetAttrs();
  runtime_attrs.GetAttrNum();
  runtime_attrs.GetAttrPointer<int>(0);
  runtime_attrs.GetBool(0);
  runtime_attrs.GetFloat(0);
  runtime_attrs.GetInt(0);
  runtime_attrs.GetListFloat(0);
  runtime_attrs.GetListInt(0);
  runtime_attrs.GetListListFloat(0);
  runtime_attrs.GetListListInt(0);
  runtime_attrs.GetStr(0);
  runtime_attrs.GetTensor(0);

  // ComputeNodeInfo methods
  // ComputeNodeInfo大部分接口都已经在ExtendedKernelContext中被调用，这里只测试未被调用的
  const gert::ComputeNodeInfo &compute_node_info = *tiling_context.GetComputeNodeInfo();
  compute_node_info.GetInputTdInfo(0);
  compute_node_info.GetOutputInstanceInfo(0);
  compute_node_info.GetOutputTdInfo(0);
  compute_node_info.GetIrInputsNum();
  compute_node_info.GetIrOutputsNum();

  compute_node_info.MutableAttrs();
  compute_node_info.MutableInputInstanceInfo(0);
  compute_node_info.MutableInputTdInfo(0);
  compute_node_info.MutableOutputInstanceInfo(0);
  compute_node_info.MutableOutputTdInfo(0);

  return 0;
}
