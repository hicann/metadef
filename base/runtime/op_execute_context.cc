/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/op_execute_context.h"
#include "exe_graph/runtime/gert_mem_allocator.h"

namespace gert {
  void *OpExecuteContext::MallocWorkspace(const size_t size) {
    auto memory_vec =
        GetOutputPointer<std::vector<GertMemBlock *>>(
            static_cast<size_t>(OpExecuteOutputIndex::kBlockMemory));
    if (memory_vec == nullptr) {
      return nullptr;
    }
    const size_t input_num = GetComputeNodeInputNum();
    const size_t output_num = GetComputeNodeOutputNum();
    auto gert_allocator = GetInputValue<GertAllocator *>(
        input_num + output_num + static_cast<size_t>(OpExecuteInputExtendIndex::kAllocate));
    if (gert_allocator == nullptr) {
      return nullptr;
    }
    auto mem_block = gert_allocator->Malloc(size);
    if (mem_block == nullptr) {
      return nullptr;
    }
    (void)memory_vec->emplace_back(mem_block);
    return mem_block->GetAddr();
  }

  void OpExecuteContext::FreeWorkspace() {
    auto memory_vec =
        GetOutputPointer<std::vector<GertMemBlock *>>(
            static_cast<size_t>(OpExecuteOutputIndex::kBlockMemory));
    auto gert_allocator = GetInputValue<GertAllocator *>(
        GetComputeNodeInputNum() + GetComputeNodeOutputNum() +
            static_cast<size_t>(OpExecuteInputExtendIndex::kAllocate));
    auto stream_id = gert_allocator->GetStreamId();
    if (memory_vec == nullptr) {
      return;
    }
    for (size_t i = 0UL; i < memory_vec->size(); i++) {
      if (memory_vec->at(i) != nullptr) {
        memory_vec->at(i)->Free(stream_id);
      }
    }
    memory_vec->clear();
  }
}
