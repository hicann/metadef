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
#include <nlohmann/json.hpp>

#include "register/tilingdata_base.h"

using namespace optiling;


std::string AscendCPyInterfaceGetTilingDefInfo(std::shared_ptr<TilingDef> tiling_def) {
  nlohmann::json json_obj;
  json_obj["class_name"] = tiling_def->GetTilingClassName();
  json_obj["data_size"] = tiling_def->GetDataSize();
  const auto &field_list = tiling_def->GetFieldInfo();
  nlohmann::json json_field_list;
  for (const auto &field : field_list) {
    nlohmann::json json_field;
    json_field["classType"] = field.classType_;
    json_field["name"] = field.name_;
    json_field["dtype"] = field.dtype_;
    if (json_field["classType"] == "1") {
      json_field["arrSize"] = field.arrSize_;
    } else if (json_field["classType"] == "2") {
      json_field["structType"] = field.structType_;
      json_field["structSize"] = field.structSize_;
    }
    json_field_list.emplace_back(json_field);
  }
  json_obj["fields"] = json_field_list;
  return json_obj.dump();
}


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

TEST_F(UtestRegister, ascendC_py_interface_get_tiling_def_ok) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  std::string op_type = "TestMaxPool";
  std::shared_ptr<TilingDef> tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  EXPECT_NO_THROW(tiling_def->GeLogError("test log error"));
  std::string res_info = AscendCPyInterfaceGetTilingDefInfo(tiling_def);
  const nlohmann::json result =
      R"({"class_name":"TestMaxPoolTilingData","data_size":40,"fields":[{"classType":"0","dtype":"int8_t","name":"dim_0"},{"arrSize":1,"classType":"1","dtype":"uint8_t","name":"dim_1PH"},{"classType":"0","dtype":"int16_t","name":"dim_1"},{"classType":"0","dtype":"int32_t","name":"dim_2"},{"classType":"0","dtype":"int64_t","name":"dim_3"},{"classType":"0","dtype":"uint8_t","name":"dim_4"},{"arrSize":1,"classType":"1","dtype":"uint8_t","name":"dim_5PH"},{"classType":"0","dtype":"uint16_t","name":"dim_5"},{"classType":"0","dtype":"uint32_t","name":"dim_6"},{"classType":"0","dtype":"uint64_t","name":"dim_7"},{"classType":"0","dtype":"int32_t","name":"act_core_num"},{"arrSize":4,"classType":"1","dtype":"uint8_t","name":"TestMaxPoolTilingDataPH"}]})"_json;
  std::string result_str = result.dump();
  EXPECT_EQ(result_str, res_info);
  op_type = "TestMaxPoolStruct";
  tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  unsetenv("ENABLE_RUNTIME_V2");
}


namespace test1 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 5, dim_0);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_1);
END_TILING_DATA_DEF
}

namespace test2 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 5, dim_1);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_2);
END_TILING_DATA_DEF
}  //name

namespace test3 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF(uint64_t, dim_1);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_2);
END_TILING_DATA_DEF
}  //infosize

namespace test4 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 4, dim_0);
TILING_DATA_FIELD_DEF_STRUCT(TestMaxPoolTilingData, dim_1);
END_TILING_DATA_DEF
}  //arrsize
namespace test5 {
BEGIN_TILING_DATA_DEF(TestMaxPoolTilingStruct)
TILING_DATA_FIELD_DEF_ARR(int8_t, 50, dim_0);
END_TILING_DATA_DEF
} //datasize

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

TEST_F(UtestRegister, test_register_tiling_data) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  std::string op_type = "Test_MaxPool";
  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api1);
  std::shared_ptr<TilingDef> tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  std::string res_info = AscendCPyInterfaceGetTilingDefInfo(tiling_def);
  const nlohmann::json result1 =
      R"({"class_name":"TestMaxPoolTilingStruct","data_size":48,"fields":[{"arrSize":5,"classType":"1","dtype":"int8_t","name":"dim_0"},{"arrSize":3,"classType":"1","dtype":"uint8_t","name":"dim_1PH"},{"classType":"2","dtype":"struct","name":"dim_1","structSize":40,"structType":"TestMaxPoolTilingData"}]})"_json;
  std::string result_str1 = result1.dump();
  EXPECT_EQ(result_str1, res_info);

  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api2);
  tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  res_info = AscendCPyInterfaceGetTilingDefInfo(tiling_def);
  const nlohmann::json result2 =
      R"({"class_name":"TestMaxPoolTilingStruct","data_size":48,"fields":[{"arrSize":5,"classType":"1","dtype":"int8_t","name":"dim_0"},{"arrSize":3,"classType":"1","dtype":"uint8_t","name":"dim_1PH"},{"classType":"2","dtype":"struct","name":"dim_1","structSize":40,"structType":"TestMaxPoolTilingData"}]})"_json;
  std::string result_str2 = result2.dump();
  EXPECT_EQ(result_str1, res_info);

  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api3);
  tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  res_info = AscendCPyInterfaceGetTilingDefInfo(tiling_def);
  const nlohmann::json result3 =
      R"({"class_name":"TestMaxPoolTilingStruct","data_size":48,"fields":[{"arrSize":5,"classType":"1","dtype":"int8_t","name":"dim_0"},{"arrSize":3,"classType":"1","dtype":"uint8_t","name":"dim_1PH"},{"classType":"2","dtype":"struct","name":"dim_1","structSize":40,"structType":"TestMaxPoolTilingData"}]})"_json;
  std::string result_str3 = result3.dump();
  EXPECT_EQ(result_str1, res_info);

  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api4);
  tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  res_info = AscendCPyInterfaceGetTilingDefInfo(tiling_def);
  const nlohmann::json result4 =
      R"({"class_name":"TestMaxPoolTilingStruct","data_size":48,"fields":[{"arrSize":5,"classType":"1","dtype":"int8_t","name":"dim_0"},{"arrSize":3,"classType":"1","dtype":"uint8_t","name":"dim_1PH"},{"classType":"2","dtype":"struct","name":"dim_1","structSize":40,"structType":"TestMaxPoolTilingData"}]})"_json;
  std::string result_str4 = result4.dump();
  EXPECT_EQ(result_str1, res_info);

  CTilingDataClassFactory::GetInstance().RegisterTilingData("Test_MaxPool", Test_api5);
  tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
  EXPECT_NE(tiling_def, nullptr);
  res_info = AscendCPyInterfaceGetTilingDefInfo(tiling_def);
  const nlohmann::json result5 =
      R"({"class_name":"TestMaxPoolTilingStruct","data_size":48,"fields":[{"arrSize":5,"classType":"1","dtype":"int8_t","name":"dim_0"},{"arrSize":3,"classType":"1","dtype":"uint8_t","name":"dim_1PH"},{"classType":"2","dtype":"struct","name":"dim_1","structSize":40,"structType":"TestMaxPoolTilingData"}]})"_json;
  std::string result_str5 = result5.dump();
  EXPECT_EQ(result_str1, res_info);
  unsetenv("ENABLE_RUNTIME_V2");
}

TEST_F(UtestRegister, ascendC_py_interface_get_tiling_def_without_callback) {
  setenv("ENABLE_RUNTIME_V2", "1", 0);
  std::string op_type = "TestMaxPoolNotExist";
  std::shared_ptr<TilingDef> tiling_def = CTilingDataClassFactory::GetInstance().CreateTilingDataInstance(op_type.c_str());
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
  params.SaveToBuffer((void *) (&res_data), params.GetDataSize());
  EXPECT_EQ(*((int8_t *) (res_data + offset)), params.get_dim_0());
  offset += sizeof(int16_t);
  EXPECT_EQ(*((int16_t *) (res_data + offset)), params.get_dim_1());
  offset += sizeof(int16_t);
  EXPECT_EQ(*((int32_t *) (res_data + offset)), params.get_dim_2());
  offset += sizeof(int32_t);
  EXPECT_EQ(*((int64_t *) (res_data + offset)), params.get_dim_3());
  offset += sizeof(int64_t);
  EXPECT_EQ(*((uint8_t *) (res_data + offset)), params.get_dim_4());
  offset += sizeof(uint16_t);
  EXPECT_EQ(*((uint16_t *) (res_data + offset)), params.get_dim_5());
  offset += sizeof(uint16_t);
  EXPECT_EQ(*((uint32_t *) (res_data + offset)), params.get_dim_6());
  offset += sizeof(uint32_t);
  EXPECT_EQ(*((uint64_t *) (res_data + offset)), params.get_dim_7());
  offset += sizeof(uint64_t);
  EXPECT_EQ(*((int32_t *) (res_data + offset)), params.get_act_core_num());
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
  paramStruct.SaveToBuffer((void *) (&res_data), 1024);

  auto params = TestMaxPoolTilingData((void *) (&res_data));
  params.set_dim_0(0);
  params.set_dim_1(10);
  params.set_dim_2(20);
  params.set_dim_3(30);
  params.set_dim_4(40);
  params.set_dim_5(50);
  params.set_dim_6(60);
  params.set_dim_7(70);
  params.set_act_core_num(8);
  params.SaveToBuffer((void *) (&res_data), 1024);
  EXPECT_EQ(*((int8_t *) (res_data + offset)), params.get_dim_0());
  offset += sizeof(int16_t);
  EXPECT_EQ(*((int16_t *) (res_data + offset)), params.get_dim_1());
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
  paramStruct.SetDataPtr((void *) (&res_data));
  EXPECT_EQ(*((int8_t *) (res_data + offset)), paramStruct.get_dim_0()[0]);
  
  unsetenv("ENABLE_RUNTIME_V2");
}