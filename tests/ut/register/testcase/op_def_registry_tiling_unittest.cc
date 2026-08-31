/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#define OP_TILING_LIB
#include <gtest/gtest.h>
#include "register/op_def_registry.h"
#include "register/op_impl_registry_base.h"

namespace ops {
namespace {

ge::graphStatus TestTiling(gert::TilingContext *context) {
  (void)context;
  return ge::GRAPH_SUCCESS;
}

ge::graphStatus TestGenSimplifiedKey(gert::TilingContext *context, ge::char_t *simplified_key) {
  (void)context;
  (void)simplified_key;
  return ge::GRAPH_SUCCESS;
}

class OpDefWithGenSimplifiedKey : public OpDef {
 public:
  explicit OpDefWithGenSimplifiedKey(const char *name) : OpDef(name) {
    this->AICore().SetTiling(TestTiling).SetGenSimplifiedKey(TestGenSimplifiedKey);
  }
};
OP_ADD(OpDefWithGenSimplifiedKey);

class OpDefWithoutGenSimplifiedKey : public OpDef {
 public:
  explicit OpDefWithoutGenSimplifiedKey(const char *name) : OpDef(name) {
    this->AICore().SetTiling(TestTiling);
  }
};
OP_ADD(OpDefWithoutGenSimplifiedKey);

class OpDefRegistryTilingUT : public testing::Test {};

TEST_F(OpDefRegistryTilingUT, RegisterGenSimplifiedKey) {
  const auto *funcs = gert::OpImplRegistry::GetInstance().GetOpImpl("OpDefWithGenSimplifiedKey");
  ASSERT_NE(funcs, nullptr);
  EXPECT_EQ(funcs->tiling, &TestTiling);
  EXPECT_EQ(funcs->gen_simplifiedkey, &TestGenSimplifiedKey);
}

TEST_F(OpDefRegistryTilingUT, KeepNullWhenCallbackIsNotSet) {
  const auto *funcs = gert::OpImplRegistry::GetInstance().GetOpImpl("OpDefWithoutGenSimplifiedKey");
  ASSERT_NE(funcs, nullptr);
  EXPECT_EQ(funcs->tiling, &TestTiling);
  EXPECT_EQ(funcs->gen_simplifiedkey, nullptr);
}

}  // namespace
}  // namespace ops
