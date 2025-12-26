/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <gtest/gtest.h>
#include "graph/ascend_string.h"

namespace ge
{
  class UtestAscendString : public testing::Test {
    protected:
    void SetUp() {}
    void TearDown() {}
  };

  TEST_F(UtestAscendString, OperatorLess_success) {
    AscendString strcmp1(nullptr);
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp_");

    ASSERT_EQ(strcmp1 < strcmp2, false);
    ASSERT_EQ(strcmp1 < strcmp3, true);
    ASSERT_EQ(strcmp3 < strcmp2, false);
    ASSERT_EQ(strcmp3 < strcmp4, true);
  }

  TEST_F(UtestAscendString, OperatorGreater_success) {
    AscendString strcmp1 = nullptr;
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp_");

    ASSERT_EQ(strcmp1 > strcmp2, false);
    ASSERT_EQ(strcmp1 > strcmp3, false);
    ASSERT_EQ(strcmp3 > strcmp2, true);
    ASSERT_EQ(strcmp4 > strcmp3, true);
  }

  TEST_F(UtestAscendString, OperatorEqual_success) {
    AscendString strcmp1 = nullptr;
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp");
    AscendString strcmp5("strcmp_");

    ASSERT_EQ(strcmp1 == strcmp2, true);
    ASSERT_EQ(strcmp1 == strcmp3, false);
    ASSERT_EQ(strcmp3 == strcmp2, false);
    ASSERT_EQ(strcmp4 == strcmp3, true);
    ASSERT_EQ(strcmp4 == strcmp5, false);
  }

  TEST_F(UtestAscendString, OperatorLess_Equal_success) {
    AscendString strcmp1 = nullptr;
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp");
    AscendString strcmp5("strcmp_");

    ASSERT_EQ(strcmp1 <= strcmp2, true);
    ASSERT_EQ(strcmp3 <= strcmp2, false);
    ASSERT_EQ(strcmp4 <= strcmp3, true);
    ASSERT_EQ(strcmp5 <= strcmp3, false);
  }

  TEST_F(UtestAscendString, OperatorGreater_Equal_success) {
    AscendString strcmp1 = nullptr;
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp");
    AscendString strcmp5("strcmp_");

    ASSERT_EQ(strcmp1 >= strcmp2, true);
    ASSERT_EQ(strcmp1 >= strcmp3, false);
    ASSERT_EQ(strcmp3 >= strcmp2, true);
    ASSERT_EQ(strcmp4 >= strcmp3, true);
    ASSERT_EQ(strcmp5 >= strcmp3, true);
  }

  TEST_F(UtestAscendString, OperatorUnequal_success) {
    AscendString strcmp1 = nullptr;
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp_");

    ASSERT_EQ(strcmp1 != strcmp2, false);
    ASSERT_EQ(strcmp1 != strcmp3, true);
    ASSERT_EQ(strcmp3 != strcmp2, true);
    ASSERT_EQ(strcmp4 != strcmp3, true);
  }

  TEST_F(UtestAscendString, OperatorEqual_char) {
    AscendString strcmp1 = nullptr;
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp");
    AscendString strcmp5("strcmp_");

    ASSERT_EQ(strcmp1 == nullptr, true);
    ASSERT_EQ(strcmp1 == "strcmp", false);
    ASSERT_EQ(strcmp3 == nullptr, false);
    ASSERT_EQ(strcmp4 == "strcmp", true);
    ASSERT_EQ(strcmp4 == "strcmp_", false);
    ASSERT_EQ(strcmp5 == "strcmp", false);
  }

  TEST_F(UtestAscendString, OperatorUnequal_char_success) {
    AscendString strcmp1 = nullptr;
    AscendString strcmp2 = nullptr;
    AscendString strcmp3("strcmp");
    AscendString strcmp4("strcmp_");

    ASSERT_EQ(strcmp1 != nullptr, false);
    ASSERT_EQ(strcmp1 != "strcmp", true);
    ASSERT_EQ(strcmp3 != nullptr, true);
    ASSERT_EQ(strcmp4 != "strcmp", true);
  }

  TEST_F(UtestAscendString, with_length) {
    size_t trunk_size = strlen("strcmp");
    AscendString strcmp1("strcmp1", trunk_size);
    AscendString strcmp2("strcmp2", trunk_size);
    AscendString strcmp3("strcmp1");
    ASSERT_EQ(strcmp1.GetLength(), trunk_size);
    ASSERT_EQ(strcmp2.GetLength(), trunk_size);
    ASSERT_GT(strcmp3.GetLength(), trunk_size);
    ASSERT_TRUE(strcmp1 == strcmp2);
    ASSERT_FALSE(strcmp1 == strcmp3);
  }

  TEST_F(UtestAscendString, null_size) {
    AscendString strcmp1(nullptr, 1);
    ASSERT_EQ(strcmp1.GetLength(), 0);
  }

  TEST_F(UtestAscendString, with_terminal) {
    std::string with_terminal_str("abc\0def", 7);
    AscendString with_terminal("abc\0def", 7);
    AscendString without_terminal("abc\0def");
    ASSERT_EQ(with_terminal.GetLength(), with_terminal_str.length());
    ASSERT_GT(with_terminal.GetLength(), without_terminal.GetLength());
    std::string re_build_str(with_terminal.GetString(), with_terminal.GetLength());
    ASSERT_EQ(re_build_str, with_terminal_str);
  }

  TEST_F(UtestAscendString, find) {
    AscendString str("abcd");
    AscendString sub("bc");
    ASSERT_EQ(str.Find(sub), 1U);
  }

  TEST_F(UtestAscendString, hash) {
    std::string data = "abcd";
    AscendString str(data.c_str());
    ASSERT_EQ(str.Hash(), std::hash<std::string>()(data));
  }
}
