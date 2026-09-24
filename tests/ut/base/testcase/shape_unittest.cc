/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/shape.h"
#include <gtest/gtest.h>

namespace gert {
class ShapeUT : public testing::Test {};

TEST_F(ShapeUT, SetDimDoesNotChangeRank) {
  Shape shape;
  shape.SetDim(0, 7);
  EXPECT_EQ(shape.GetDimNum(), 0);
  EXPECT_EQ(shape.GetDim(0), 7);

  shape.SetDim(2, 9);
  EXPECT_EQ(shape.GetDimNum(), 0);
  EXPECT_EQ(shape.GetDim(2), 9);

  shape.SetDimNum(3);
  shape.SetDim(2, 11);
  EXPECT_EQ(shape.GetDimNum(), 3);
  EXPECT_EQ(shape.GetDim(2), 11);
}
}  // namespace gert
