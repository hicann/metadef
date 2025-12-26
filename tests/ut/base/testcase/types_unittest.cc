/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "external/graph/types.h"
#include "graph/utils/type_utils_inner.h"
#include "graph/ascend_string.h"
#include <climits>
#include <gtest/gtest.h>

namespace ge {
class UtestTypes : public testing::Test {
 protected:
  void SetUp() {}

  void TearDown() {}
};

TEST_F(UtestTypes, GetFormatName) {
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NCHW), "NCHW"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NHWC), "NHWC"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_ND), "ND"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NC1HWC0), "NC1HWC0"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_Z), "FRACTAL_Z"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NC1C0HWPAD), "NC1C0HWPAD"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NHWC1C0), "NHWC1C0"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FSR_NCHW), "FSR_NCHW"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_DECONV), "FRACTAL_DECONV"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_C1HWNC0), "C1HWNC0"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_DECONV_TRANSPOSE), "FRACTAL_DECONV_TRANSPOSE"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_DECONV_SP_STRIDE_TRANS), "FRACTAL_DECONV_SP_STRIDE_TRANS"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NC1HWC0_C04), "NC1HWC0_C04"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_Z_C04), "FRACTAL_Z_C04"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_DECONV_SP_STRIDE8_TRANS), "DECONV_SP_STRIDE8_TRANS"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NC1KHKWHWC0), "NC1KHKWHWC0"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_BN_WEIGHT), "BN_WEIGHT"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FILTER_HWCK), "FILTER_HWCK"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_HASHTABLE_LOOKUP_LOOKUPS), "LOOKUP_LOOKUPS"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_HASHTABLE_LOOKUP_KEYS), "LOOKUP_KEYS"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_HASHTABLE_LOOKUP_VALUE), "LOOKUP_VALUE"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_HASHTABLE_LOOKUP_OUTPUT), "LOOKUP_OUTPUT"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_HASHTABLE_LOOKUP_HITS), "LOOKUP_HITS"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_C1HWNCoC0), "C1HWNCoC0"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_MD), "MD"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NDHWC), "NDHWC"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_ZZ), "UNKNOWN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_NZ), "FRACTAL_NZ"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NCDHW), "NCDHW"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_DHWCN), "DHWCN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NDC1HWC0), "NDC1HWC0"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_Z_3D), "FRACTAL_Z_3D"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_CN), "CN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NC), "NC"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_DHWNC), "DHWNC"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_Z_3D_TRANSPOSE), "FRACTAL_Z_3D_TRANSPOSE"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_ZN_LSTM), "FRACTAL_ZN_LSTM"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_Z_G), "FRACTAL_Z_G"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_C1HWC0), "C1HWC0"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_NZ_C0_16), "FRACTAL_NZ_C0_16"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_NZ_C0_32), "FRACTAL_NZ_C0_32"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_ND_RNN_BIAS), "ND_RNN_BIAS"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_ZN_RNN), "FRACTAL_ZN_RNN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NYUV), "NYUV"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NYUV_A), "NYUV_A"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NCL), "NCL"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_RESERVED), "UNKNOWN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_ALL), "UNKNOWN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_NULL), "UNKNOWN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_END), "UNKNOWN"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_NZ_C0_2), "FRACTAL_NZ_C0_2"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_NZ_C0_4), "FRACTAL_NZ_C0_4"), 0);
  ASSERT_EQ(strcmp(GetFormatName(FORMAT_FRACTAL_NZ_C0_8), "FRACTAL_NZ_C0_8"), 0);
  ASSERT_EQ(FORMAT_END, 55); // if add formats definition, add ut here
}

TEST_F(UtestTypes, GetFormatFromSub) {
  ASSERT_EQ(GetFormatFromSub(10, 8), 0x80a);
  ASSERT_EQ(GetFormatFromSub(1, 0), 1);
  ASSERT_EQ(GetFormatFromSub(0, 0), 0);
  ASSERT_EQ(GetFormatFromSub(0xff, 0), 0xff);
  ASSERT_EQ(GetFormatFromSub(0xff, 0xffff), 0xffffff);
  ASSERT_EQ(GetFormatFromSub(FORMAT_FRACTAL_Z, 8), 0x804);
}

TEST_F(UtestTypes, GetPrimaryFormat) {
  ASSERT_EQ(GetPrimaryFormat(0x804), FORMAT_FRACTAL_Z);
  ASSERT_EQ(GetPrimaryFormat(0), FORMAT_NCHW);
  ASSERT_EQ(GetPrimaryFormat(0xffffff), 0xff);
}

TEST_F(UtestTypes, GetSubFormat) {
  ASSERT_EQ(GetSubFormat(0x804), 8);
  ASSERT_EQ(GetSubFormat(0), 0);
  ASSERT_EQ(GetSubFormat(0xffffff), 0xffff);
  ASSERT_EQ(GetSubFormat(0x4), 0);

  ASSERT_EQ(HasSubFormat(0x804), true);
  ASSERT_EQ(HasSubFormat(0), false);
  ASSERT_EQ(HasSubFormat(0xffffff), true);
  ASSERT_EQ(GetSubFormat(0x4), false);
}

TEST_F(UtestTypes, GetSizeByDataType) {
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT), 4);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT16), 2);
  EXPECT_EQ(GetSizeByDataType(DT_INT8), 1);
  EXPECT_EQ(GetSizeByDataType(DT_INT16), 2);
  EXPECT_EQ(GetSizeByDataType(DT_UINT16), 2);
  EXPECT_EQ(GetSizeByDataType(DT_UINT8), 1);
  EXPECT_EQ(GetSizeByDataType(DT_INT32), 4);
  EXPECT_EQ(GetSizeByDataType(DT_INT64), 8);
  EXPECT_EQ(GetSizeByDataType(DT_UINT32), 4);
  EXPECT_EQ(GetSizeByDataType(DT_UINT64), 8);
  EXPECT_EQ(GetSizeByDataType(DT_BOOL), 1);
  EXPECT_EQ(GetSizeByDataType(DT_DOUBLE), 8);
  EXPECT_EQ(GetSizeByDataType(DT_STRING), -1);
  EXPECT_EQ(GetSizeByDataType(DT_DUAL_SUB_INT8), 1);
  EXPECT_EQ(GetSizeByDataType(DT_DUAL_SUB_UINT8), 1);
  EXPECT_EQ(GetSizeByDataType(DT_COMPLEX64), 8);
  EXPECT_EQ(GetSizeByDataType(DT_COMPLEX128), 16);
  EXPECT_EQ(GetSizeByDataType(DT_QINT8), 1);
  EXPECT_EQ(GetSizeByDataType(DT_QINT16), 2);
  EXPECT_EQ(GetSizeByDataType(DT_QINT32), 4);
  EXPECT_EQ(GetSizeByDataType(DT_QUINT8), 1);
  EXPECT_EQ(GetSizeByDataType(DT_QUINT16), 2);
  EXPECT_EQ(GetSizeByDataType(DT_RESOURCE), 8);
  EXPECT_EQ(GetSizeByDataType(DT_STRING_REF), -1);
  EXPECT_EQ(GetSizeByDataType(DT_DUAL), 5);
  EXPECT_EQ(GetSizeByDataType(DT_VARIANT), 8);
  EXPECT_EQ(GetSizeByDataType(DT_BF16), 2);
  EXPECT_EQ(GetSizeByDataType(DT_UNDEFINED), -1);
  EXPECT_EQ(GetSizeByDataType(DT_INT4), kDataTypeSizeBitOffset + 4);
  EXPECT_EQ(GetSizeByDataType(DT_INT2), kDataTypeSizeBitOffset + 2);
  EXPECT_EQ(GetSizeByDataType(DT_UINT2), kDataTypeSizeBitOffset + 2);
  EXPECT_EQ(GetSizeByDataType(DT_UINT1), kDataTypeSizeBitOffset + 1);
  EXPECT_EQ(GetSizeByDataType(DT_COMPLEX32), 4);
  EXPECT_EQ(GetSizeByDataType(DT_MAX), -1);
  EXPECT_EQ(GetSizeByDataType(static_cast<DataType>(-1)), -1);
  EXPECT_EQ(GetSizeByDataType(DT_HIFLOAT8), 1);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT8_E5M2), 1);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT8_E4M3FN), 1);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT8_E8M0), 1);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT6_E3M2), kDataTypeSizeBitOffset + 6);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT6_E2M3), kDataTypeSizeBitOffset + 6);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT4_E2M1), kDataTypeSizeBitOffset + 4);
  EXPECT_EQ(GetSizeByDataType(DT_FLOAT4_E1M2), kDataTypeSizeBitOffset + 4);
  EXPECT_EQ(DT_MAX, 42);
}

TEST_F(UtestTypes, GetSizeInBytes) {
  EXPECT_EQ(GetSizeInBytes(-1, DT_FLOAT), -1);
  EXPECT_EQ(GetSizeInBytes(10, DT_UNDEFINED), -1);
  EXPECT_EQ(GetSizeInBytes(INT64_MAX, DT_INT32), -1);
  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT), 40);
  EXPECT_EQ(GetSizeInBytes(10, DT_INT4), 5);
  EXPECT_EQ(GetSizeInBytes(9, DT_INT4), 5);
  EXPECT_EQ(GetSizeInBytes(INT64_MAX, DT_INT4), -1);
  EXPECT_EQ(GetSizeInBytes(10, DT_INT2), 3);
  EXPECT_EQ(GetSizeInBytes(9, DT_INT2), 3);
  EXPECT_EQ(GetSizeInBytes(INT64_MAX, DT_INT2), -1);
  EXPECT_EQ(GetSizeInBytes(10, DT_UINT1), 2);
  EXPECT_EQ(GetSizeInBytes(9, DT_UINT1), 2);
  EXPECT_EQ(GetSizeInBytes(10, DT_HIFLOAT8), 10);
  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT8_E5M2), 10);
  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT8_E4M3FN), 10);
  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT8_E8M0), 10);

  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT6_E3M2), 8);  // 10 * 6 / 8 = 7.5
  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT6_E2M3), 8);  // 10 * 6 / 8 = 7.5
  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT4_E2M1), 5);  // 10 * 4 / 8 = 5
  EXPECT_EQ(GetSizeInBytes(10, DT_FLOAT4_E1M2), 5);  // 10 * 4 / 8 = 5
}

TEST_F(UtestTypes, GetC0ValueFromFormat) {
  // {c0_value, bit_value}: c0_value = 2 ^ (bit_value - 1)
  // {1, 1}, {2, 2}, {4, 3}, {8, 4}, {16, 5}, {32, 6}, {64, 7}, {128, 8}, {256, 9}
  // 5 indicates that cube size is 16
  const Format format = static_cast<Format>(GetFormatFromSubAndC0(FORMAT_NC1HWC0, FORMAT_RESERVED, 5));
  EXPECT_EQ(GetC0Value(format), 16);
  const Format origin_format = static_cast<Format>(GetFormatFromSub(FORMAT_FRACTAL_Z, FORMAT_RESERVED));
  EXPECT_EQ(GetC0Value(origin_format), -1);
}

TEST_F(UtestTypes, Promote) {
  ge::Promote promote({"a", "b", "c"});
  auto syms = promote.Syms();
  EXPECT_EQ(syms.size(), 3U);
  EXPECT_EQ(syms[0], std::string("a"));
  EXPECT_EQ(syms[1], std::string("b"));
  EXPECT_EQ(syms[2], std::string("c"));

  auto promote_cm(std::move(promote));
  EXPECT_EQ(promote.Syms().size(), 0U);
  syms = promote_cm.Syms();
  EXPECT_EQ(syms.size(), 3U);
  EXPECT_EQ(syms[0], std::string("a"));
  EXPECT_EQ(syms[1], std::string("b"));
  EXPECT_EQ(syms[2], std::string("c"));

  auto promote_am= std::move(promote_cm);
  EXPECT_EQ(promote_cm.Syms().size(), 0U);
  syms = promote_am.Syms();
  EXPECT_EQ(syms[0], std::string("a"));
  EXPECT_EQ(syms[1], std::string("b"));
  EXPECT_EQ(syms[2], std::string("c"));
}

TEST_F(UtestTypes, IsDataTypeValid) {
  ASSERT_FALSE(TypeUtilsInner::IsDataTypeValid(DT_MAX));
  ASSERT_TRUE(TypeUtilsInner::IsDataTypeValid(DT_INT4));

  ASSERT_FALSE(TypeUtilsInner::IsDataTypeValid("MAX"));
  ASSERT_TRUE(TypeUtilsInner::IsDataTypeValid("UINT64"));
  ASSERT_TRUE(TypeUtilsInner::IsDataTypeValid("STRING_REF"));
}

TEST_F(UtestTypes, CheckUint64MulOverflow) {
  ASSERT_FALSE(TypeUtilsInner::CheckUint64MulOverflow(0x00ULL, 0x00UL));
  ASSERT_FALSE(TypeUtilsInner::CheckUint64MulOverflow(0x02ULL, 0x01UL));
  ASSERT_TRUE(TypeUtilsInner::CheckUint64MulOverflow(0xFFFFFFFFFFFFULL, 0xFFFFFFFUL));
}

TEST_F(UtestTypes, CheckUint64MulOverflow2) {
  ASSERT_FALSE(TypeUtilsInner::CheckUint64MulOverflow(0, 1));
  ASSERT_FALSE(TypeUtilsInner::CheckUint64MulOverflow(1, 1));
  ASSERT_TRUE(TypeUtilsInner::CheckUint64MulOverflow(ULLONG_MAX, 2));
}

TEST_F(UtestTypes, IsFormatValid) {
  ASSERT_TRUE(TypeUtilsInner::IsFormatValid(FORMAT_NCHW));
  ASSERT_FALSE(TypeUtilsInner::IsFormatValid(FORMAT_END));

  ASSERT_TRUE(TypeUtilsInner::IsFormatValid("DECONV_SP_STRIDE8_TRANS"));
  ASSERT_FALSE(TypeUtilsInner::IsFormatValid("FORMAT_END"));
}
}
