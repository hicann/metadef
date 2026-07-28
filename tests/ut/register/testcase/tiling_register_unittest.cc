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

#include "register/tilingdata_base.h"

using namespace optiling;

namespace {
void VerifyField(const FieldInfo &field, const char *class_type, const char *dtype, const char *name,
                 size_t arr_size = 0, const char *struct_type = nullptr, size_t struct_size = 0) {
  EXPECT_STREQ(field.classType_, class_type);
  EXPECT_STREQ(field.dtype_, dtype);
  EXPECT_STREQ(field.name_, name);
  if (std::string(class_type) == "1") {
    EXPECT_EQ(field.arrSize_, arr_size);
  }
  if (std::string(class_type) == "2") {
    EXPECT_STREQ(field.structType_, struct_type);
    EXPECT_EQ(field.structSize_, struct_size);
  }
}
}  // namespace

class UtestRegister : public testing::Test {
 protected:
  void SetUp() {}

  void TearDown() {}
};

BEGIN_TILING_DATA_DEF(TestMaxPoolTilingData)
// format: TILING_DATA_FIELD_DEF(data_type, field_name);
TILING_DATA_FIELD_DEF(int8_t, dim_0);
TILING_DATA_FIELD_DEF(int16_t, dim_1);
TILING_DATA_FIELD_DEF(int32_t, dim_2);
TILING_DATA_FIELD_DEF(int64_t, dim_3);
TILING_DATA_FIELD_DEF(uint8_t, dim_4);
TILING_DATA_FIELD_DEF(uint16_t, dim_5);
TILING_DATA_FIELD_DEF(uint32_t, dim_6);
TILING_DATA_FIELD_DEF(uint64_t, dim_7);
TILING_DATA_FIELD_DEF(int32_t, act_core_num);
END_TILING_DATA_DEF

// register class
REGISTER_TILING_DATA_CLASS(TestMaxPool, TestMaxPoolTilingData)

BEGIN_TILING_DATA_DEF(TestMaxPoolTilingDataStruct)
// format: TILING_DATA_FIELD_DEF(data_type, field_name);
TILING_DATA_FIELD_DEF_ARR(int8_t, 8, dim_0);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_1);
END_TILING_DATA_DEF

// register class
REGISTER_TILING_DATA_CLASS(TestMaxPoolStruct, TestMaxPoolTilingDataStruct)

namespace test1 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 5, dim_0);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_1);
END_TILING_DATA_DEF
}  // namespace test1

namespace test2 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 5, dim_1);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_2);
END_TILING_DATA_DEF
}  // namespace test2

namespace test3 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF(uint64_t, dim_1);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_2);
END_TILING_DATA_DEF
}  // namespace test3

namespace test4 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 4, dim_0);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_1);
END_TILING_DATA_DEF
}  // namespace test4
namespace test5 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 50, dim_0);
END_TILING_DATA_DEF
}  // namespace test5

std::shared_ptr<TilingDef> Test_api1() {
  return std::make_shared<test1::TestMaxPoolTilingStruct>();
}

std::shared_ptr<TilingDef> Test_api2() {
  return std::make_shared<test2::TestMaxPoolTilingStruct>();
}

std::shared_ptr<TilingDef> Test_api3() {
  return std::make_shared<test3::TestMaxPoolTilingStruct>();
}

std::shared_ptr<TilingDef> Test_api4() {
  return std::make_shared<test4::TestMaxPoolTilingStruct>();
}

std::shared_ptr<TilingDef> Test_api5() {
  return std::make_shared<test5::TestMaxPoolTilingStruct>();
}

TEST_F(UtestRegister, ascendC_py_interface_get_tiling_def_ok) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  std::string op_type = "TestMaxPool";
  std::shared_ptr<TilingDef> tiling_def =
      CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  EXPECT_NO_THROW(tiling_def->GeLogError("test log error"));

  EXPECT_STREQ(tiling_def->GetTilingClassName(), "TestMaxPoolTilingData");
  EXPECT_EQ(tiling_def->GetDataSize(), 40U);

  const auto &fields = tiling_def->GetFieldInfo();
  EXPECT_EQ(fields.size(), 12U);
  VerifyField(fields[0], "0", "int8_t", "dim_0");
  VerifyField(fields[1], "1", "uint8_t", "dim_1PH", 1U);
  VerifyField(fields[2], "0", "int16_t", "dim_1");
  VerifyField(fields[3], "0", "int32_t", "dim_2");
  VerifyField(fields[4], "0", "int64_t", "dim_3");
  VerifyField(fields[5], "0", "uint8_t", "dim_4");
  VerifyField(fields[6], "1", "uint8_t", "dim_5PH", 1U);
  VerifyField(fields[7], "0", "uint16_t", "dim_5");
  VerifyField(fields[8], "0", "uint32_t", "dim_6");
  VerifyField(fields[9], "0", "uint64_t", "dim_7");
  VerifyField(fields[10], "0", "int32_t", "act_core_num");
  VerifyField(fields[11], "1", "uint8_t", "TestMaxPoolTilingDataPH", 4U);

  op_type = "TestMaxPoolStruct";
  tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  unsetenv("ENABLE_RUNTIME_V2");
}

TEST_F(UtestRegister, test_register_tiling_data) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  std::string op_type = "Test_MaxPool";

  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api1);
  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api2);
  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api3);
  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api4);
  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api5);

  std::shared_ptr<TilingDef> tiling_def =
      CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);

  EXPECT_STREQ(tiling_def->GetTilingClassName(), "TestMaxPoolTilingStruct");
  EXPECT_EQ(tiling_def->GetDataSize(), 48U);

  const auto &fields = tiling_def->GetFieldInfo();
  EXPECT_EQ(fields.size(), 3U);
  VerifyField(fields[0], "1", "int8_t", "dim_0", 5U);
  VerifyField(fields[1], "1", "uint8_t", "dim_1PH", 3U);
  VerifyField(fields[2], "2", "struct", "dim_1", 0U, "TestMaxPoolTilingData", 40U);

  unsetenv("ENABLE_RUNTIME_V2");
}

TEST_F(UtestRegister, ascendC_py_interface_get_tiling_def_without_callback) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  std::string op_type = "TestMaxPoolNotExist";
  std::shared_ptr<TilingDef> tiling_def =
      CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_EQ(tiling_def, nullptr);
  unsetenv("ENABLE_RUNTIME_V2");
}

TEST_F(UtestRegister, ascendC_register_tilingdata_record_tiling_struct) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  uint32_t ret = TilingDataStructBase::GetInstance().RecordTilingStruct("TestTiling1", "test.cpp", 1);
  ret = TilingDataStructBase::GetInstance().RecordTilingStruct("TestTiling2", "test.h", 1);
  ret = TilingDataStructBase::GetInstance().RecordTilingStruct("TestTiling1", "test.cpp", 2);
  EXPECT_EQ(ret, 0);
  ret = TilingDataStructBase::GetInstance().RecordTilingStruct("TestTiling1", "test.h", 1);
  EXPECT_EQ(ret, 0);
  ret = TilingDataStructBase::GetInstance().RecordTilingStruct("TestTiling2", "test.h", 1);
  EXPECT_EQ(ret, 0);
  ret = TilingDataStructBase::GetInstance().RecordTilingStruct("TestTiling2", "test.h", 2);
  EXPECT_EQ(ret, 0);
  unsetenv("ENABLE_RUNTIME_V2");
}

TEST_F(UtestRegister, ascendC_register_tilingdata_base_ok) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  auto params = TestMaxPoolTilingData();
  params.set_dim_0(0);
  params.set_dim_1(10);
  params.set_dim_2(20);
  params.set_dim_3(30);
  params.set_dim_4(40);
  params.set_dim_5(50);
  params.set_dim_6(60);
  params.set_dim_7(70);
  params.set_act_core_num(8);
  uint8_t res_data[1024];
  int offset = 0;
  params.SaveToBuffer((void *)(&res_data), params.GetDataSize());
  EXPECT_EQ(*((int8_t *)(res_data + offset)), params.get_dim_0());
  offset += sizeof(int16_t);
  EXPECT_EQ(*((int16_t *)(res_data + offset)), params.get_dim_1());
  offset += sizeof(int16_t);
  EXPECT_EQ(*((int32_t *)(res_data + offset)), params.get_dim_2());
  offset += sizeof(int32_t);
  EXPECT_EQ(*((int64_t *)(res_data + offset)), params.get_dim_3());
  offset += sizeof(int64_t);
  EXPECT_EQ(*((uint8_t *)(res_data + offset)), params.get_dim_4());
  offset += sizeof(uint16_t);
  EXPECT_EQ(*((uint16_t *)(res_data + offset)), params.get_dim_5());
  offset += sizeof(uint16_t);
  EXPECT_EQ(*((uint32_t *)(res_data + offset)), params.get_dim_6());
  offset += sizeof(uint32_t);
  EXPECT_EQ(*((uint64_t *)(res_data + offset)), params.get_dim_7());
  offset += sizeof(uint64_t);
  EXPECT_EQ(*((int32_t *)(res_data + offset)), params.get_act_core_num());
  offset += sizeof(int32_t);
  unsetenv("ENABLE_RUNTIME_V2");
}

TEST_F(UtestRegister, ascendC_register_tilingdata_base_failed) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  auto paramStruct = TestMaxPoolTilingDataStruct();
  int8_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
  uint8_t res_data[1024];
  int offset = 0;
  paramStruct.set_dim_0(arr);
  paramStruct.dim_1.set_dim_0(0);
  paramStruct.dim_1.set_dim_1(10);
  paramStruct.dim_1.set_dim_2(20);
  paramStruct.dim_1.set_dim_3(30);
  paramStruct.dim_1.set_dim_4(40);
  paramStruct.dim_1.set_dim_5(50);
  paramStruct.dim_1.set_dim_6(60);
  paramStruct.dim_1.set_dim_7(70);
  paramStruct.dim_1.set_act_core_num(8);
  paramStruct.SaveToBuffer((void *)(&res_data), 1024);

  auto params = TestMaxPoolTilingData((void *)(&res_data));
  params.set_dim_0(0);
  params.set_dim_1(10);
  params.set_dim_2(20);
  params.set_dim_3(30);
  params.set_dim_4(40);
  params.set_dim_5(50);
  params.set_dim_6(60);
  params.set_dim_7(70);
  params.set_act_core_num(8);
  params.SaveToBuffer((void *)(&res_data), 1024);
  EXPECT_EQ(*((int8_t *)(res_data + offset)), params.get_dim_0());
  offset += sizeof(int16_t);
  EXPECT_EQ(*((int16_t *)(res_data + offset)), params.get_dim_1());
  params.SetDataPtr(res_data);
  unsetenv("ENABLE_RUNTIME_V2");
}

TEST_F(UtestRegister, ascendC_register_tilingdata_base_struct_ok) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  auto paramStruct = TestMaxPoolTilingDataStruct();
  int8_t arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
  uint8_t res_data[1024];
  int offset = 0;
  paramStruct.set_dim_0(arr);
  paramStruct.dim_1.set_dim_0(0);
  paramStruct.dim_1.set_dim_1(10);
  paramStruct.dim_1.set_dim_2(20);
  paramStruct.dim_1.set_dim_3(30);
  paramStruct.dim_1.set_dim_4(40);
  paramStruct.dim_1.set_dim_5(50);
  paramStruct.dim_1.set_dim_6(60);
  paramStruct.dim_1.set_dim_7(70);
  paramStruct.dim_1.set_act_core_num(8);
  paramStruct.SetDataPtr((void *)(&res_data));
  EXPECT_EQ(*((int8_t *)(res_data + offset)), paramStruct.get_dim_0()[0]);

  unsetenv("ENABLE_RUNTIME_V2");
}
