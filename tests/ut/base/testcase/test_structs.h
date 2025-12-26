/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef METADEF_CXX_TEST_STRUCTS_H
#define METADEF_CXX_TEST_STRUCTS_H

#include "graph/debug/ge_util.h"
namespace ge {
struct TestStructA {
  TestStructA(int64_t a, int64_t b, int64_t c) : a(a), b(b), c(c) {}
  int64_t a;
  int64_t b;
  int64_t c;
  bool operator==(const TestStructA &other) const {
    return a == other.a && b == other.b && c == other.c;
  }
};

struct InlineStructB {
  InlineStructB() {
    a = new int32_t[10]();
  }
  InlineStructB(const InlineStructB  &other) {
    a = new int32_t[10]();
    memcpy(a, other.a, sizeof(int32_t[10]));
  }
  InlineStructB(InlineStructB &&other) {
    a = other.a;
    other.a = nullptr;
  }
  InlineStructB &operator=(const InlineStructB &other) {
    memcpy(a, other.a, sizeof(int32_t[10]));
    return *this;
  }
  InlineStructB &operator=(InlineStructB &&other) noexcept {
    delete[] a;
    a = other.a;
    other.a = nullptr;
    return *this;
  }
  bool operator==(const InlineStructB &other) const {
    return memcmp(a, other.a, sizeof(int32_t) * 10) == 0;
  }
  ~InlineStructB() {
    delete[] a;
  }

  InlineStructB &Set(size_t index, int32_t value) {
    a[index] = value;
    return *this;
  }

  int32_t Get(size_t index) const {
    return a[index];
  }
  int32_t *GetP() {
    return a;
  }
 private:
  int32_t *a;
};
}
#endif  //METADEF_CXX_TEST_STRUCTS_H
