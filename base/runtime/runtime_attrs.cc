/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/runtime_attrs.h"
#include "common/ge_common/debug/ge_log.h"
#include "base/runtime/runtime_attrs_def.h"
#include "graph/def_types.h"
namespace gert {
const void *RuntimeAttrs::GetPointerByIndex(size_t index) const {
  auto attrs = ge::PtrToPtr<uint64_t, const RuntimeAttrsDef>(&placeholder_);
  if (index >= attrs->attr_num) {
    GELOGE(ge::FAILED, "Failed to get attr, the index %zu out of range %zu", index, attrs->attr_num);
    return nullptr;
  }
  return ge::PtrToPtr<const RuntimeAttrsDef, const uint8_t>(attrs) + attrs->offset[index];
}
size_t RuntimeAttrs::GetAttrNum() const {
  return ge::PtrToPtr<uint64_t, const RuntimeAttrsDef>(&placeholder_)->attr_num;
}
}  // namespace gert
