/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/tensor.h"
#include <gtest/gtest.h>
namespace gert {
class TensorUT : public testing::Test {};
TEST_F(TensorUT, ConstructOk_V2) {
  TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                  {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                  kOnDeviceHbm,                                // placement
                  ge::DT_FLOAT16,                              //dt
                  nullptr};
  const TensorV2 &t2 = tensor;

  EXPECT_EQ(t2.GetOriginShape(), Shape({8, 3, 224, 224}));
  EXPECT_EQ(t2.GetStorageShape(), Shape({16, 3, 224, 224}));

  EXPECT_EQ(t2.GetOriginFormat(), ge::FORMAT_ND);
  EXPECT_EQ(t2.GetStorageFormat(), ge::FORMAT_FRACTAL_NZ);
  StorageFormat storage_format{ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}};
  EXPECT_EQ(t2.GetFormat(), storage_format);
  EXPECT_EQ(t2.GetExpandDimsType(), ExpandDimsType{});

  EXPECT_EQ(t2.GetPlacement(), kOnDeviceHbm);
  EXPECT_EQ(t2.GetDataType(), ge::DT_FLOAT16);
  EXPECT_EQ(t2.GetAddr(), nullptr);
  EXPECT_EQ(t2.GetData<int64_t>(), nullptr);
}


TEST_F(TensorUT, GetDataAddrFollowingOk_V2) {
  TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                  {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                  kFollowing,                                // placement
                  ge::DT_FLOAT16,                              //dt
                  nullptr};
  const TensorV2 &t2 = tensor;

  EXPECT_EQ(t2.GetOriginShape(), Shape({8, 3, 224, 224}));
  EXPECT_EQ(t2.GetStorageShape(), Shape({16, 3, 224, 224}));

  EXPECT_EQ(t2.GetOriginFormat(), ge::FORMAT_ND);
  EXPECT_EQ(t2.GetStorageFormat(), ge::FORMAT_FRACTAL_NZ);
  EXPECT_EQ(t2.GetExpandDimsType(), ExpandDimsType{});

  EXPECT_EQ(t2.GetPlacement(), kFollowing);
  EXPECT_EQ(t2.GetDataType(), ge::DT_FLOAT16);
  EXPECT_EQ(t2.GetAddr(), &tensor + 1);
  EXPECT_EQ(t2.GetData<int64_t>(), reinterpret_cast<const int64_t *>(&tensor + 1));
}

TEST_F(TensorUT, GetCopiedDataAddrFollowingOk_V2) {
  TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                  {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                  kFollowing,                                // placement
                  ge::DT_FLOAT16,                              //dt
                  nullptr};
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  memcpy(static_cast<void *>(&t2), static_cast<void *>(&tensor), sizeof(tensor));

  EXPECT_EQ(t2.GetOriginShape(), Shape({8, 3, 224, 224}));
  EXPECT_EQ(t2.GetStorageShape(), Shape({16, 3, 224, 224}));

  EXPECT_EQ(t2.GetOriginFormat(), ge::FORMAT_ND);
  EXPECT_EQ(t2.GetStorageFormat(), ge::FORMAT_FRACTAL_NZ);
  EXPECT_EQ(t2.GetExpandDimsType(), ExpandDimsType{});

  EXPECT_EQ(t2.GetPlacement(), kFollowing);
  EXPECT_EQ(t2.GetDataType(), ge::DT_FLOAT16);
  EXPECT_EQ(t2.GetAddr(), &t2 + 1);
  EXPECT_EQ(t2.GetData<int64_t>(), reinterpret_cast<int64_t *>(&t2 + 1));
}

TEST_F(TensorUT, SetGetShapeOk_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  const TensorV2 &ct = t2;
  t2.MutableOriginShape() = Shape{8,3,224,224};
  t2.MutableStorageShape() = Shape{8,1,224,224,16};
  EXPECT_EQ(t2.GetOriginShape(), Shape({8,3,224,224}));
  EXPECT_EQ(t2.GetStorageShape(), Shape({8,1,224,224,16}));
  EXPECT_EQ(ct.GetOriginShape(), Shape({8,3,224,224}));
  EXPECT_EQ(ct.GetStorageShape(), Shape({8,1,224,224,16}));
}

TEST_F(TensorUT, SetGetFormatOk_V2) {
  TensorV2 tensor = {{}, {}, {}, {}, nullptr};
  const TensorV2 &t2 = tensor;
  tensor.SetOriginFormat(ge::FORMAT_NHWC);
  tensor.SetStorageFormat(ge::FORMAT_NC1HWC0);

  EXPECT_EQ(t2.GetOriginFormat(), ge::FORMAT_NHWC);
  EXPECT_EQ(t2.GetStorageFormat(), ge::FORMAT_NC1HWC0);

  EXPECT_EQ(t2.GetFormat().GetOriginFormat(), ge::FORMAT_NHWC);
  EXPECT_EQ(t2.GetFormat().GetStorageFormat(), ge::FORMAT_NC1HWC0);
}

TEST_F(TensorUT, SetGetPlacementOk_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  const TensorV2 &ct2 = t2;
  t2.SetPlacement(kOnHost);
  EXPECT_EQ(t2.GetPlacement(), kOnHost);
  EXPECT_EQ(ct2.GetPlacement(), kOnHost);
}

TEST_F(TensorUT, SetGetDataTypeOk_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  const TensorV2 &ct2 = t2;
  t2.SetDataType(ge::DT_FLOAT16);
  EXPECT_EQ(t2.GetDataType(), ge::DT_FLOAT16);
  EXPECT_EQ(ct2.GetDataType(), ge::DT_FLOAT16);
}

TEST_F(TensorUT, SetGetAddrOk_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  const TensorV2 &ct2 = t2;
  void *a = &t2;

  TensorData td(a, nullptr);
  t2.SetData(std::move(td));
  EXPECT_EQ(t2.GetAddr(), a);
  EXPECT_EQ(ct2.GetAddr(), a);

  EXPECT_EQ(t2.GetData<TensorV2>(), &t2);
  EXPECT_EQ(ct2.GetData<TensorV2>(), &t2);
}

TEST_F(TensorUT, GetTensorDataOk_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  auto a = reinterpret_cast<void *>(10);
  t2.MutableTensorData() = TensorData{a, nullptr};
  t2.SetSize(10);
  EXPECT_EQ(t2.GetAddr(), a);
  EXPECT_EQ(t2.GetTensorData().GetAddr(), a);
  EXPECT_EQ(t2.MutableTensorData().GetSize(), 10);
}

TEST_F(TensorUT, GetTensorPlacementOk_V2) {
  TensorV2 t2 = {{}, {}, kOnHost, {}, nullptr};
  EXPECT_EQ(t2.GetPlacement(), kOnHost);
}

TEST_F(TensorUT, GetTensorSizeOk_V2) {
  StorageShape sh({1, 2, 3}, {1, 2, 3});
  TensorV2 t2 = {sh, {}, {}, ge::DT_FLOAT, nullptr};
  EXPECT_EQ(t2.GetSize(), 24);
}


TEST_F(TensorUT, CreateFollowingCheckTotalSize_V2) {
  size_t total_size;
  auto ptr = TensorV2::CreateFollowing(32, ge::DataType::DT_INT8, total_size);
  EXPECT_NE(ptr, nullptr);
  auto tensor = reinterpret_cast<TensorV2 *>(ptr.get());
  EXPECT_EQ(tensor->GetSize(), 32);
}

TEST_F(TensorUT, CreateFollowingWithTensorCheckTotalSize_V2) {
  size_t total_size;
  auto ptr = TensorV2::CreateFollowing(ge::DT_FLOAT, 8U, total_size);
  EXPECT_NE(ptr, nullptr);
  auto tensor = reinterpret_cast<TensorV2 *>(ptr.get());
  EXPECT_EQ(tensor->GetSize(), 8);
}

TEST_F(TensorUT, CreateFollowingWithTensorUseStringTypeCheckTotalSize_V2) {
  size_t total_size;
  auto ptr = TensorV2::CreateFollowing(ge::DT_STRING, 160U, total_size);
  EXPECT_NE(ptr, nullptr);
  auto tensor = reinterpret_cast<TensorV2 *>(ptr.get());
  EXPECT_EQ(tensor->GetSize(), 160);
}

TEST_F(TensorUT, GetShapeOk_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  Shape shape{1, 1, 1, 1, 1};
  t2.GetShape().MutableShape() = shape;
  EXPECT_EQ(t2.GetShape().GetShape(), shape);
}

TEST_F(TensorUT, GetStride_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  Stride stride{1, 1, 1, 1, 1};
  t2.MutableStride() = stride;
  EXPECT_EQ(t2.GetStride(), stride);
}

TEST_F(TensorUT, GetOffset_V2) {
  TensorV2 t2 = {{}, {}, {}, {}, nullptr};
  t2.SetOffset(100);
  EXPECT_EQ(t2.GetOffset(), 100);
}

TEST_F(TensorUT, GetExpandDimsTypeOk_V2) {
  TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                  {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                  kOnDeviceHbm,                                // placement
                  ge::DT_FLOAT16,                              //dt
                  nullptr};

  ExpandDimsType expend_dims_type(1);
  tensor.SetExpandDimsType(expend_dims_type);
  EXPECT_EQ(tensor.GetExpandDimsType(), expend_dims_type);
}

TEST_F(TensorUT, GetStorageFormatOk_V2) {
  TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                  {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                  kOnDeviceHbm,                                // placement
                  ge::DT_FLOAT16,                              //dt
                  nullptr};
  StorageFormat storage_format{ge::FORMAT_ND, ge::FORMAT_ND, {}};
  tensor.MutableFormat() = storage_format;
  EXPECT_EQ(tensor.GetFormat(), storage_format);
}

TEST_F(TensorUT, GetOriginShapeOk_V2) {
  TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                  {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                  kOnDeviceHbm,                                // placement
                  ge::DT_FLOAT16,                              //dt
                  nullptr};
  EXPECT_EQ(tensor.GetOriginShape(), Shape({8, 3, 224, 224}));
  Shape modify_shape{1, 2, 3, 4 , 5};
  tensor.MutableOriginShape() = modify_shape;
  EXPECT_EQ(tensor.GetOriginShape(), modify_shape);
}

TEST_F(TensorUT, GetStorageShapeOk_V2) {
  TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                  {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                  kOnDeviceHbm,                                // placement
                  ge::DT_FLOAT16,                              //dt
                  nullptr};
  StorageShape storage_shape{{8, 3, 224, 224}, {16, 3, 224, 224}};
  const StorageShape& const_storage_shape = tensor.GetShape();
  EXPECT_EQ(const_storage_shape, storage_shape);
  StorageShape& mutable_storage_shape = tensor.GetShape();
  EXPECT_EQ(mutable_storage_shape, storage_shape);

  mutable_storage_shape.MutableOriginShape() = {10, 10, 10, 10, 10};
  mutable_storage_shape.MutableStorageShape() = {20, 20, 20, 20, 20};

  EXPECT_EQ(mutable_storage_shape, StorageShape({10, 10 ,10, 10, 10}, {20, 20, 20, 20, 20}));
  EXPECT_EQ(mutable_storage_shape.GetOriginShape(), Shape({10, 10 ,10, 10, 10}));
  EXPECT_EQ(mutable_storage_shape.GetStorageShape(), Shape({20, 20, 20, 20, 20}));
  EXPECT_EQ(tensor.GetShape().GetStorageShape(), Shape({20, 20, 20, 20, 20}));
  EXPECT_EQ(tensor.GetShapeSize(), 3200000);
}

}  // namespace gert
