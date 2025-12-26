/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "graph/utils/type_utils.h"
#include <climits>
#include <gtest/gtest.h>
#include "graph/debug/ge_util.h"

namespace ge {
class UtestTypeUtils : public testing::Test {
 protected:
  void SetUp() {}
  void TearDown() {}
};

TEST_F(UtestTypeUtils, FormatToSerialString) {
  ASSERT_EQ(TypeUtils::FormatToSerialString(FORMAT_NCHW), "NCHW");
  ASSERT_EQ(TypeUtils::FormatToSerialString(FORMAT_END), "END");
  ASSERT_EQ(TypeUtils::FormatToSerialString(static_cast<Format>(GetFormatFromSub(FORMAT_FRACTAL_Z, 1))), "FRACTAL_Z:1");
  ASSERT_EQ(TypeUtils::FormatToSerialString(static_cast<Format>(GetFormatFromSub(FORMAT_END, 1))), "END:1");
  ASSERT_EQ(TypeUtils::FormatToSerialString(FORMAT_C1HWC0), "C1HWC0");
  ASSERT_EQ(TypeUtils::FormatToSerialString(static_cast<Format>(FORMAT_END + 1)), "RESERVED");
}

TEST_F(UtestTypeUtils, SerialStringToFormat) {
  ASSERT_EQ(TypeUtils::SerialStringToFormat("NCHW"), FORMAT_NCHW);
  ASSERT_EQ(TypeUtils::SerialStringToFormat("C1HWC0"), FORMAT_C1HWC0);
  ASSERT_EQ(TypeUtils::SerialStringToFormat("INVALID"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::SerialStringToFormat("FRACTAL_Z:1"), GetFormatFromSub(FORMAT_FRACTAL_Z, 1));
  ASSERT_EQ(TypeUtils::SerialStringToFormat("FRACTAL_Z:01"), GetFormatFromSub(FORMAT_FRACTAL_Z, 1));
  ASSERT_EQ(TypeUtils::SerialStringToFormat("INVALID:1"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::SerialStringToFormat("FRACTAL_Z:1%"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::SerialStringToFormat("FRACTAL_Z:"), FORMAT_RESERVED);  // invalid_argument exception
  ASSERT_EQ(TypeUtils::SerialStringToFormat("FRACTAL_Z:65535"), GetFormatFromSub(FORMAT_FRACTAL_Z, 0xffff));
  ASSERT_EQ(TypeUtils::SerialStringToFormat("FRACTAL_Z:65536"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::SerialStringToFormat("FRACTAL_Z:9223372036854775807"), FORMAT_RESERVED);
}

TEST_F(UtestTypeUtils, DataFormatToFormat) {
  ASSERT_EQ(TypeUtils::DataFormatToFormat(std::string("NCHW")), FORMAT_NCHW);
  ASSERT_EQ(TypeUtils::DataFormatToFormat(std::string("INVALID")), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::DataFormatToFormat(std::string("NCHW:1")), GetFormatFromSub(FORMAT_NCHW, 1));
  ASSERT_EQ(TypeUtils::DataFormatToFormat(std::string("NCHW:01")), GetFormatFromSub(FORMAT_NCHW, 1));
  ASSERT_EQ(TypeUtils::DataFormatToFormat(std::string("INVALID:1")), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::DataFormatToFormat(std::string("NCHW:1%")), FORMAT_RESERVED);
}

TEST_F(UtestTypeUtils, DataTypeToSerialString) {
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_INT2), "DT_INT2");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_UINT2), "DT_UINT2");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_UINT1), "DT_UINT1");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_HIFLOAT8), "DT_HIFLOAT8");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_FLOAT8_E5M2), "DT_FLOAT8_E5M2");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_FLOAT8_E4M3FN), "DT_FLOAT8_E4M3FN");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_FLOAT8_E8M0), "DT_FLOAT8_E8M0");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_FLOAT6_E3M2), "DT_FLOAT6_E3M2");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_FLOAT6_E2M3), "DT_FLOAT6_E2M3");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_FLOAT4_E2M1), "DT_FLOAT4_E2M1");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_FLOAT4_E1M2), "DT_FLOAT4_E1M2");
  ASSERT_EQ(TypeUtils::DataTypeToSerialString(DT_MAX), "UNDEFINED");
}

TEST_F(UtestTypeUtils, SerialStringToDataType) {
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_UINT1"), DT_UINT1);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_INT2"), DT_INT2);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_HIFLOAT8"), DT_HIFLOAT8);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_FLOAT8_E5M2"), DT_FLOAT8_E5M2);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_FLOAT8_E4M3FN"), DT_FLOAT8_E4M3FN);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_FLOAT8_E8M0"), DT_FLOAT8_E8M0);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_FLOAT6_E3M2"), DT_FLOAT6_E3M2);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_FLOAT6_E2M3"), DT_FLOAT6_E2M3);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_FLOAT4_E2M1"), DT_FLOAT4_E2M1);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_FLOAT4_E1M2"), DT_FLOAT4_E1M2);
  ASSERT_EQ(TypeUtils::SerialStringToDataType("DT_MAX"), DT_UNDEFINED);
}

TEST_F(UtestTypeUtils, FormatToAscendString) {
  ASSERT_EQ(TypeUtils::FormatToAscendString(FORMAT_NCHW), "NCHW");
  ASSERT_EQ(TypeUtils::FormatToAscendString(FORMAT_END), "END");
  ASSERT_EQ(TypeUtils::FormatToAscendString(static_cast<Format>(GetFormatFromSub(FORMAT_FRACTAL_Z, 1))), "FRACTAL_Z:1");
  ASSERT_EQ(TypeUtils::FormatToAscendString(static_cast<Format>(GetFormatFromSub(FORMAT_END, 1))), "END:1");
  ASSERT_EQ(TypeUtils::FormatToAscendString(FORMAT_C1HWC0), "C1HWC0");
}

TEST_F(UtestTypeUtils, AscendStringToFormat) {
  ASSERT_EQ(TypeUtils::AscendStringToFormat("NCHW"), FORMAT_NCHW);
  ASSERT_EQ(TypeUtils::AscendStringToFormat("C1HWC0"), FORMAT_C1HWC0);
  ASSERT_EQ(TypeUtils::AscendStringToFormat("INVALID"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::AscendStringToFormat("FRACTAL_Z:1"), GetFormatFromSub(FORMAT_FRACTAL_Z, 1));
  ASSERT_EQ(TypeUtils::AscendStringToFormat("FRACTAL_Z:01"), GetFormatFromSub(FORMAT_FRACTAL_Z, 1));
  ASSERT_EQ(TypeUtils::AscendStringToFormat("INVALID:1"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::AscendStringToFormat("FRACTAL_Z:1%"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::AscendStringToFormat("FRACTAL_Z:"), FORMAT_RESERVED);  // invalid_argument exception
  ASSERT_EQ(TypeUtils::AscendStringToFormat("FRACTAL_Z:65535"), GetFormatFromSub(FORMAT_FRACTAL_Z, 0xffff));
  ASSERT_EQ(TypeUtils::AscendStringToFormat("FRACTAL_Z:65536"), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::AscendStringToFormat("FRACTAL_Z:9223372036854775807"), FORMAT_RESERVED);
}

TEST_F(UtestTypeUtils, DataFormatAscendStringToFormat) {
  ASSERT_EQ(TypeUtils::DataFormatToFormat(AscendString("NCHW")), FORMAT_NCHW);
  ASSERT_EQ(TypeUtils::DataFormatToFormat(AscendString("INVALID")), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::DataFormatToFormat(AscendString("NCHW:1")), GetFormatFromSub(FORMAT_NCHW, 1));
  ASSERT_EQ(TypeUtils::DataFormatToFormat(AscendString("NCHW:01")), GetFormatFromSub(FORMAT_NCHW, 1));
  ASSERT_EQ(TypeUtils::DataFormatToFormat(AscendString("INVALID:1")), FORMAT_RESERVED);
  ASSERT_EQ(TypeUtils::DataFormatToFormat(AscendString("NCHW:1%")), FORMAT_RESERVED);
}

TEST_F(UtestTypeUtils, DataTypeToAscendString) {
  ASSERT_EQ(TypeUtils::DataTypeToAscendString(DT_INT2), "DT_INT2");
  ASSERT_EQ(TypeUtils::DataTypeToAscendString(DT_UINT2), "DT_UINT2");
  ASSERT_EQ(TypeUtils::DataTypeToAscendString(DT_UINT1), "DT_UINT1");
  ASSERT_EQ(TypeUtils::DataTypeToAscendString(DT_MAX), "UNDEFINED");
}

TEST_F(UtestTypeUtils, AscendStringToDataType) {
  ASSERT_EQ(TypeUtils::AscendStringToDataType("DT_UINT1"), DT_UINT1);
  ASSERT_EQ(TypeUtils::AscendStringToDataType("DT_INT2"), DT_INT2);
  ASSERT_EQ(TypeUtils::AscendStringToDataType("DT_MAX"), DT_UNDEFINED);
}
}
