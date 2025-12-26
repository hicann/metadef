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
#include "graph/ge_error_codes.h"
#include <gtest/gtest.h>
#include "faker/allocator_faker.h"
#include "exe_graph/runtime/storage_shape.h"
#include "base/context_builder/op_kernel_run_context_builder.h"

namespace gert {
class OpExecuteContextUT : public testing::Test {};


TEST_F(OpExecuteContextUT, MallocFreeWorkSpaceOk) {
  OpKernelContextBuilder ctx_builder;
  gert::StorageShape shape0 = {{10, 20}, {10, 20}};
  AllocatorFaker gert_allocator;
  auto output_block_memory = std::make_shared<std::vector<gert::GertMemBlock *>>();
  ASSERT_NE(output_block_memory, nullptr);
  output_block_memory->reserve(1UL);

  auto holder = ctx_builder.OpType("Add")
      .OpName("add_1")
      .IONum(2, 1)
      .InputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
      .InputTensorDesc(1, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
      .OutputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
      .Inputs({&shape0, &shape0, &gert_allocator, &gert_allocator})
      .Outputs({output_block_memory.get()})
      .Build();

  auto context = reinterpret_cast<OpExecuteContext *>(holder.GetContext());
  ASSERT_NE(context, nullptr);

  auto block = context->MallocWorkspace(1024);
  ASSERT_NE(block, nullptr);

  auto kernel_context = reinterpret_cast<KernelContext *>(context);
  auto memory_vec = kernel_context->GetOutputPointer<std::vector<GertMemBlock *>>(0UL);
  ASSERT_NE(memory_vec, nullptr);
  EXPECT_EQ(memory_vec->size(), 1UL);
  context->FreeWorkspace();
  EXPECT_EQ(memory_vec->size(), 0UL);
}
}
