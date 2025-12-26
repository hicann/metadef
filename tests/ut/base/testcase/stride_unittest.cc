/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/stride.h"
#include <gtest/gtest.h>
namespace gert {
class StrideUT : public testing::Test {};

TEST_F(StrideUT, CreateStrideOK) {
  Stride stride_default;
  EXPECT_EQ(stride_default.GetDimNum(), 0);
  EXPECT_EQ(stride_default.GetStride(0), 0);

  Stride stride_1({1, 2, 3, 4});
  EXPECT_EQ(stride_1.GetDimNum(), 4);
  EXPECT_EQ(stride_1.GetStride(0), 1);
  EXPECT_EQ(stride_1.GetStride(1), 2);
  EXPECT_EQ(stride_1.GetStride(2), 3);
  EXPECT_EQ(stride_1.GetStride(3), 4);

  Stride stride_2(stride_1);
  EXPECT_EQ(stride_1, stride_2);

  Stride stride_3 = stride_1;
  EXPECT_EQ(stride_3.GetDimNum(), 4);
  EXPECT_EQ(stride_3.GetStride(0), 1);
  EXPECT_EQ(stride_3.GetStride(1), 2);
  EXPECT_EQ(stride_3.GetStride(2), 3);
  EXPECT_EQ(stride_3.GetStride(3), 4);
  EXPECT_EQ(stride_1, stride_3);
  EXPECT_NE(stride_default, stride_3);

  Stride stride_4;
  stride_4.SetDimNum(4);
  stride_4.SetStride(0, 1);
  stride_4.SetStride(1, 2);
  stride_4.SetStride(2, 3);
  stride_4.SetStride(3, 4);
  EXPECT_EQ(stride_1, stride_4);
  const int64_t dim_0 = stride_4[0];
  const int64_t dim_1 = stride_4[1];
  const int64_t dim_2 = stride_4[2];
  const int64_t dim_3 = stride_4[3];
  EXPECT_EQ(dim_0, 1);
  EXPECT_EQ(dim_1, 2);
  EXPECT_EQ(dim_2, 3);
  EXPECT_EQ(dim_3, 4);
  EXPECT_EQ(stride_4[0], 1);
  EXPECT_EQ(stride_4[1], 2);
  EXPECT_EQ(stride_4[2], 3);
  EXPECT_EQ(stride_4[3], 4);

  Stride stride_5({1, 2, 3, 4});
  stride_5.SetStride(Stride::kMaxDimNum + 1, 100);
  EXPECT_EQ(stride_5.GetDimNum(), 4);
  EXPECT_EQ(stride_5.GetStride(Stride::kMaxDimNum + 1), stride_5.kInvalidStrideValue);
  stride_5.AppendStride(5);
  EXPECT_EQ(stride_5.GetDimNum(), 5);
  EXPECT_EQ(stride_5.GetStride(4), 5);

  Stride stride_6({1, 2, 3, 4, 5 ,6 , 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 28, 19, 20, 21, 22, 23, 24, 25, 26});
  EXPECT_EQ(stride_6.GetDimNum(), 0);
  EXPECT_EQ(stride_6.GetStride(0), 0);

  Stride stride_7({1, 2, 3, 4, 5 ,6 , 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 28, 19, 20, 21, 22, 23, 24, 25});
  EXPECT_EQ(stride_7.GetDimNum(), 25);
  stride_7.AppendStride(26);
  EXPECT_EQ(stride_7.GetDimNum(), 25);
  EXPECT_EQ(stride_7.GetStride(24), 25);
}

}  // namespace gert
