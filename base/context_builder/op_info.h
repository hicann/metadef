/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef METADEF_INC_EXTERNAL_BASE_CONTEXT_BUILDER_OP_INFO_H_
#define METADEF_INC_EXTERNAL_BASE_CONTEXT_BUILDER_OP_INFO_H_
#include <memory>
#include "graph/types.h"
#include "exe_graph/runtime/storage_shape.h"
#include "exe_graph/runtime/shape.h"
#include "graph/ascend_string.h"
#include "graph/any_value.h"

using namespace ge;
namespace gert {
struct ContextTensorDesc {
  ge::DataType dtype = ge::DataType::DT_MAX;
  ge::Format origin_format = ge::Format::FORMAT_MAX;
  ge::Format storage_format = ge::Format::FORMAT_MAX;
  gert::ExpandDimsType expand_dims_type;
  gert::StorageShape storage_shape = {};
};

struct OpInfo {
  std::string op_type;
  std::string op_name;
  std::vector<ge::AnyValue> attrs;  // 传递给context中的compute_node_info
  uint32_t input_ir_num = 0U;
  uint32_t input_instance_num = 0U;
  uint32_t output_ir_num = 0U;
  uint32_t output_instance_num = 0U;
  std::vector<uint32_t> input_instance;
  std::vector<uint32_t> output_instance;
  std::vector<ContextTensorDesc> input_tensor_descs;   // 传递给context中的compute_node_info
  std::vector<ContextTensorDesc> output_tensor_descs;  // 传递给context中的compute_node_info
};
}  // namespace gert
#endif  // METADEF_INC_EXTERNAL_BASE_CONTEXT_BUILDER_OP_INFO_H_