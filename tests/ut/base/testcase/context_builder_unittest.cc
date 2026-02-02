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
#include <memory>
#include <cmath>
#include "base/context_builder/context_holder.h"
#include "base/context_builder/op_kernel_run_context_builder.h"
#include "base/context_builder/op_infer_datatype_context_builder.h"
#include "base/context_builder/op_infer_shape_context_builder.h"
#include "base/context_builder/op_infer_shape_range_context_builder.h"
#include "base/context_builder/op_tiling_context_builder.h"
#include "base/context_builder/op_tiling_parse_context_builder.h"
#include "graph/def_types.h"
#include "exe_graph/runtime/kernel_run_context.h"
#include "exe_graph/runtime/extended_kernel_context.h"
#include "exe_graph/runtime/kernel_context.h"
#include "exe_graph/runtime/infer_datatype_context.h"
#include "exe_graph/runtime/infer_shape_context.h"
#include "exe_graph/runtime/infer_shape_range_context.h"
#include "exe_graph/runtime/tiling_context.h"
#include "exe_graph/runtime/tiling_parse_context.h"

using namespace gert;
using namespace ge;
class UtestContextBuilder : public testing::Test {};

TEST_F(UtestContextBuilder, CreateKernelRunContextOK) {
  OpKernelContextBuilder ctx_builder;
  gert::StorageShape shape0 = {{10, 20}, {10, 20}};
  auto holder = ctx_builder.OpType("Add")
                    .OpName("add_1")
                    .IONum(2, 1)
                    .InputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .InputTensorDesc(1, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .OutputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .Inputs({&shape0, &shape0})
                    .Outputs({&shape0})
                    .Build();
  auto ctx = reinterpret_cast<KernelContext *>(holder.GetContext());
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = static_cast<const gert::ComputeNodeInfo *>(ctx->GetComputeNodeExtend());
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("Add"));
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("add_1"));
  EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 2);
  EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
  EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 2);
  EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
  const CompileTimeTensorDesc *info_input_0 = ctx_compute_node_info->GetInputTdInfo(0);
  EXPECT_NE(info_input_0, nullptr);
  EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_FRACTAL_NZ);
  EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_ND);
  EXPECT_EQ(ctx->GetInput(0)->GetPointer<gert::StorageShape>(), &shape0);
  EXPECT_EQ(ctx->GetInput(1)->GetPointer<gert::StorageShape>(), &shape0);
  EXPECT_EQ(ctx->GetOutput(0)->GetPointer<gert::StorageShape>(), &shape0);
}

TEST_F(UtestContextBuilder, CreateKernelRunContextFailed) {
  OpKernelContextBuilder ctx_builder;
  gert::StorageShape shape0 = {{10, 20}, {10, 20}};
  auto holder = ctx_builder.OpName("add_1")
                    .IONum(1, 1)
                    .InputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .InputTensorDesc(1, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .OutputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .Inputs({&shape0, &shape0})
                    .Outputs({&shape0})
                    .Build();
  auto ctx = reinterpret_cast<KernelContext *>(holder.GetContext());
  EXPECT_EQ(ctx, nullptr);
}

TEST_F(UtestContextBuilder, CreateInferDataTypeContextOK) {
  OpInferDataTypeContextBuilder ctx_builder;
  ge::DataType dtype0 = ge::DT_FLOAT;
  ge::DataType dtype1 = ge::DT_FLOAT16;
  ge::DataType dtype2 = ge::DT_FLOAT;
  ge::DataType dtype3 = ge::DT_FLOAT16;
  ge::DataType dtype4 = ge::DT_FLOAT16;

  std::vector<ge::DataType *> input_dtype_ref = {&dtype0, &dtype1, &dtype2, &dtype3};
  std::vector<ge::DataType *> output_dtype_ref = {&dtype4};
  auto holder = ctx_builder.OpType("Concat")
                    .OpName("concat_1")
                    .IOInstanceNum({4}, {1})
                    .InputTensorDesc(0, dtype0, ge::FORMAT_ND, ge::FORMAT_ND)
                    .InputTensorDesc(1, dtype1, ge::FORMAT_ND, ge::FORMAT_ND)
                    .InputTensorDesc(2, dtype2, ge::FORMAT_ND, ge::FORMAT_ND)
                    .InputTensorDesc(3, dtype3, ge::FORMAT_ND, ge::FORMAT_ND)
                    .OutputTensorDesc(0, ge::FORMAT_ND, ge::FORMAT_ND)
                    .Build();
  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("Concat"));
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("concat_1"));
  EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 1);
  EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
  EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 4);
  EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
  const CompileTimeTensorDesc *info_input_0 = ctx_compute_node_info->GetInputTdInfo(0);
  EXPECT_NE(info_input_0, nullptr);
  EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_ND);
  EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_ND);
  ge::DataType expected_datatype_0 = ge::DT_FLOAT;
  ge::DataType expected_datatype_1 = ge::DT_FLOAT16;
  EXPECT_EQ(ctx->GetInputDataType(0), expected_datatype_0);
  EXPECT_EQ(ctx->GetInputDataType(1), expected_datatype_1);
  EXPECT_EQ(ctx->GetInputDataType(2), expected_datatype_0);
  EXPECT_EQ(ctx->GetInputDataType(3), expected_datatype_1);
  EXPECT_EQ(ctx->GetOutputDataType(0), ge::DT_MAX);
}

TEST_F(UtestContextBuilder, CreateInferDataTypeWithTypeContextOK) {
  OpInferDataTypeContextBuilder ctx_builder;
  ge::DataType dtype0 = ge::DT_FLOAT;
  ge::DataType dtype1 = ge::DT_FLOAT16;
  ge::DataType dtype2 = ge::DT_FLOAT;
  ge::DataType dtype3 = ge::DT_FLOAT16;
  ge::DataType dtype4 = ge::DT_FLOAT16;

  std::vector<ge::DataType> input_dtype_ref = {dtype0, dtype1, dtype2, dtype3};
  std::vector<ge::DataType *> output_dtype_ref = {&dtype4};
  auto holder = ctx_builder.OpType("Concat")
                    .OpName("concat_1")
                    .IOInstanceNum({4}, {1})
                    .InputTensorDesc(0, dtype0, ge::FORMAT_ND, ge::FORMAT_ND)
                    .InputTensorDesc(1, dtype1, ge::FORMAT_ND, ge::FORMAT_ND)
                    .InputTensorDesc(2, dtype2, ge::FORMAT_ND, ge::FORMAT_ND)
                    .InputTensorDesc(3, dtype3, ge::FORMAT_ND, ge::FORMAT_ND)
                    .OutputTensorDesc(0, ge::FORMAT_ND, ge::FORMAT_ND)
                    .Build();
  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("Concat"));
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("concat_1"));
  EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 1);
  EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
  EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 4);
  EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
  const CompileTimeTensorDesc *info_input_0 = ctx_compute_node_info->GetInputTdInfo(0);
  EXPECT_NE(info_input_0, nullptr);
  EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_ND);
  EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_ND);
  ge::DataType expected_datatype_0 = ge::DT_FLOAT;
  ge::DataType expected_datatype_1 = ge::DT_FLOAT16;
  EXPECT_EQ(ctx->GetInputDataType(0), expected_datatype_0);
  EXPECT_EQ(ctx->GetInputDataType(1), expected_datatype_1);
  EXPECT_EQ(ctx->GetInputDataType(2), expected_datatype_0);
  EXPECT_EQ(ctx->GetInputDataType(3), expected_datatype_1);
  EXPECT_EQ(ctx->GetOutputDataType(0), ge::DT_MAX);
}

TEST_F(UtestContextBuilder, CreateInferShapeContextFailed) {
  OpInferShapeContextBuilder ctx_builder;
  gert::StorageShape shape0 = {{10, 20}, {10, 20}};
  gert::Tensor tensor;
  tensor.MutableStorageShape() = shape0.GetStorageShape();
  tensor.MutableOriginShape() = shape0.GetOriginShape();
  ctx_builder.OpType("DIY").OpName("diy_1").IONum(2, 1);
  auto holder = ctx_builder.InputTensors({&tensor, &tensor}).Build();
  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("DIY"));
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("diy_1"));
  EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 2);
  EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
  EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 2);
  EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
}

TEST_F(UtestContextBuilder, CreateInferShapeContextOK) {
  OpInferShapeContextBuilder ctx_builder;
  StorageShape shape0 = {{1, 2, 3, 4}, {4, 3, 2, 1}};
  StorageShape shape1 = {{2, 3, 4, 5}, {5, 4, 3, 2}};
  StorageShape shape2 = {{3, 4, 5, 6}, {6, 5, 4, 3}};
  StorageShape shape3 = {{4, 5, 6, 7}, {7, 6, 5, 4}};
  StorageFormat format{FORMAT_ND, FORMAT_FRACTAL_NZ, {}};
  gert::Tensor tensor0{shape0, format, ge::DT_FLOAT};
  gert::Tensor tensor1{shape1, format, ge::DT_FLOAT};
  gert::Tensor tensor2{shape2, format, ge::DT_FLOAT};
  gert::Tensor tensor3{shape3, format, ge::DT_FLOAT};

  std::vector<gert::Tensor *> input_dtype_ref = {&tensor0, &tensor1, &tensor2, &tensor3};
  auto holder = ctx_builder.OpType("DIY")
                    .OpName("diy_1")
                    .IOInstanceNum({1, 1, 1, 1}, {1})
                    .OutputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_ND, ge::FORMAT_NCHW)
                    .InputTensors(input_dtype_ref)
                    .Build();
  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("DIY"));
  EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("diy_1"));
  EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 4);
  EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
  EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 4);
  EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
  const CompileTimeTensorDesc *info_input_0 = ctx_compute_node_info->GetInputTdInfo(0);
  EXPECT_NE(info_input_0, nullptr);
  EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_FRACTAL_NZ);
  EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_ND);
  EXPECT_NE(ctx->GetInputShape(0), nullptr);
  EXPECT_EQ(*(ctx->GetInputShape(0)), shape0.GetOriginShape());
  EXPECT_NE(ctx->GetInputShape(1), nullptr);
  EXPECT_EQ(*(ctx->GetInputShape(1)), shape1.GetOriginShape());
  EXPECT_NE(ctx->GetInputShape(2), nullptr);
  EXPECT_EQ(*(ctx->GetInputShape(2)), shape2.GetOriginShape());
  EXPECT_NE(ctx->GetInputShape(3), nullptr);
  EXPECT_EQ(*(ctx->GetInputShape(3)), shape3.GetOriginShape());
  EXPECT_NE(ctx->GetOutputShape(0), nullptr);
  EXPECT_EQ(ctx->GetOutputShape(0)->GetDimNum(), 0);
  EXPECT_EQ(ctx->GetComputeNodeInfo()->GetOutputTdInfo(0)->GetDataType(), DT_FLOAT);
  EXPECT_EQ(ctx->GetComputeNodeInfo()->GetOutputTdInfo(0)->GetOriginFormat(), FORMAT_ND);
  EXPECT_EQ(ctx->GetComputeNodeInfo()->GetOutputTdInfo(0)->GetStorageFormat(), FORMAT_NCHW);
}

TEST_F(UtestContextBuilder, CreateInferShapeContextOutOfRangeFailed) {
  OpInferShapeContextBuilder ctx_builder;
  StorageShape shape0 = {{1, 2, 3, 4}, {4, 3, 2, 1}};
  StorageShape shape1 = {{2, 3, 4, 5}, {5, 4, 3, 2}};
  StorageShape shape2 = {{3, 4, 5, 6}, {6, 5, 4, 3}};
  StorageShape shape3 = {{4, 5, 6, 7}, {7, 6, 5, 4}};
  StorageFormat format{FORMAT_ND, FORMAT_FRACTAL_NZ, {}};
  gert::Tensor tensor0{shape0, format, ge::DT_FLOAT};
  gert::Tensor tensor1{shape1, format, ge::DT_FLOAT};
  gert::Tensor tensor2{shape2, format, ge::DT_FLOAT};
  gert::Tensor tensor3{shape3, format, ge::DT_FLOAT};

  std::vector<gert::Tensor *> input_dtype_ref = {&tensor0, &tensor1, &tensor2, &tensor3};
  auto holder = ctx_builder.OpType("DIY")
                    .OpName("diy_1")
                    .IOInstanceNum({1, 1, 1, 1}, {1})
                    .OutputTensorDesc(1, ge::DT_FLOAT, ge::FORMAT_ND, ge::FORMAT_ND)
                    .InputTensors(input_dtype_ref)
                    .Build();
  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  EXPECT_NE(ctx->GetOutputShape(0), nullptr);
  EXPECT_EQ(ctx->GetOutputShape(0)->GetDimNum(), 0);
  EXPECT_EQ(ctx->GetOutputShape(1), nullptr);
}

TEST_F(UtestContextBuilder, CreateInferShapeRangeContextOK) {
  OpInferShapeRangeContextBuilder ctx_builder;
  gert::StorageShape xShapeMin{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  gert::StorageShape xShapeMax{{10, 10, 10, 10, 20}, {10, 10, 10, 10, 20}};
  gert::StorageShape wShapeMin{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  gert::StorageShape wShapeMax{{10, 10, 10, 10, 20}, {10, 10, 10, 10, 20}};
  gert::Shape yShapeMinNull{1, 1, 1, 1, 1};
  gert::Shape yShapeMaxNull{10, 10, 10, 10, 20};
  gert::StorageShape yShapeMin{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  gert::StorageShape yShapeMax{{10, 10, 10, 10, 20}, {10, 10, 10, 10, 20}};
  StorageFormat format{FORMAT_NCDHW, FORMAT_RESERVED, {}};

  gert::Tensor xTensorMin{xShapeMin, format, ge::DT_INT8};
  gert::Tensor xTensorMax{xShapeMax, format, ge::DT_INT8};
  gert::Range<gert::Tensor> xShapeRange(&xTensorMin, &xTensorMax);

  gert::Tensor wTensorMin{wShapeMin, format, ge::DT_INT8};
  gert::Tensor wTensorMax{wShapeMax, format, ge::DT_INT8};

  gert::Range<gert::Tensor> wShapeRange(&wTensorMin, &wTensorMax);
  gert::Range<gert::Shape> yShapeRange(&yShapeMinNull, &yShapeMaxNull);

  auto holder = ctx_builder.IONum(2, 1)
                    .OutputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                    .OpType("DIY")
                    .OpName("diy_1")
                    .InputTensorsRange({&xShapeRange, &wShapeRange})
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  const CompileTimeTensorDesc *info_input_0 = ctx->GetInputDesc(0);
  EXPECT_NE(info_input_0, nullptr);
  EXPECT_EQ(info_input_0->GetDataType(), ge::DT_INT8);
  EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_NCDHW);
  EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_RESERVED);
  const CompileTimeTensorDesc *info_input_1 = ctx->GetInputDesc(1);
  EXPECT_NE(info_input_1, nullptr);
  EXPECT_EQ(info_input_1->GetDataType(), ge::DT_INT8);
  EXPECT_EQ(info_input_1->GetOriginFormat(), ge::FORMAT_NCDHW);
  EXPECT_EQ(info_input_1->GetStorageFormat(), ge::FORMAT_RESERVED);
  const CompileTimeTensorDesc *info_output_0 = ctx->GetOutputDesc(0);
  EXPECT_NE(info_output_0, nullptr);
  EXPECT_EQ(info_output_0->GetDataType(), ge::DT_FLOAT16);
  EXPECT_EQ(info_output_0->GetOriginFormat(), ge::FORMAT_NCDHW);
  EXPECT_EQ(info_output_0->GetStorageFormat(), ge::FORMAT_RESERVED);
  EXPECT_NE(ctx->GetInputShapeRange(0), nullptr);
  EXPECT_EQ(*(ctx->GetInputShapeRange(0)->GetMin()), xShapeMin.GetOriginShape());
  EXPECT_EQ(*(ctx->GetInputShapeRange(0)->GetMax()), xShapeMax.GetOriginShape());
  EXPECT_NE(ctx->GetInputShapeRange(1), nullptr);
  EXPECT_EQ(*(ctx->GetInputShapeRange(1)->GetMin()), wShapeMin.GetOriginShape());
  EXPECT_EQ(*(ctx->GetInputShapeRange(1)->GetMax()), wShapeMax.GetOriginShape());
  EXPECT_NE(ctx->GetOutputShapeRange(0), nullptr);
  EXPECT_NE(ctx->GetOutputShapeRange(0)->GetMin(), nullptr);
  EXPECT_NE(ctx->GetOutputShapeRange(0)->GetMax(), nullptr);
  EXPECT_EQ(ctx->GetOutputShapeRange(0)->GetMin()->GetDimNum(), 0);
  EXPECT_EQ(ctx->GetOutputShapeRange(0)->GetMax()->GetDimNum(), 0);
  ctx->GetOutputShapeRange(0)->GetMin()->SetDimNum(5);
  ctx->GetOutputShapeRange(0)->GetMax()->SetDimNum(5);
  for (size_t i = 0; i < 5; i++) {
    ctx->GetOutputShapeRange(0)->GetMin()->SetDim(i, yShapeMin.GetOriginShape()[i]);
    ctx->GetOutputShapeRange(0)->GetMax()->SetDim(i, yShapeMax.GetOriginShape()[i]);
  }
  EXPECT_EQ(*(ctx->GetOutputShapeRange(0)->GetMin()), yShapeMin.GetOriginShape());
  EXPECT_EQ(*(ctx->GetOutputShapeRange(0)->GetMax()), yShapeMax.GetOriginShape());
}

TEST_F(UtestContextBuilder, CreateInferShapeRangeContextFailed) {
  OpInferShapeRangeContextBuilder ctx_builder;
  gert::StorageShape xShapeMin{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  gert::StorageShape xShapeMax{{10, 10, 10, 10, 20}, {10, 10, 10, 10, 20}};
  gert::StorageShape wShapeMin{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  gert::StorageShape wShapeMax{{10, 10, 10, 10, 20}, {10, 10, 10, 10, 20}};
  gert::Shape yShapeMinNull{1, 1, 1, 1, 1};
  gert::Shape yShapeMaxNull{10, 10, 10, 10, 20};
  gert::StorageShape yShapeMin{{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
  gert::StorageShape yShapeMax{{10, 10, 10, 10, 20}, {10, 10, 10, 10, 20}};
  StorageFormat format{FORMAT_NCDHW, FORMAT_RESERVED, {}};

  gert::Tensor xTensorMin{xShapeMin, format, ge::DT_FLOAT};
  gert::Tensor xTensorMax{xShapeMax, format, ge::DT_INT8};
  gert::Range<gert::Tensor> xShapeRange(&xTensorMin, &xTensorMax);

  gert::Tensor wTensorMin{wShapeMin, format, ge::DT_INT8};
  gert::Tensor wTensorMax{wShapeMax, format, ge::DT_INT8};

  gert::Range<gert::Tensor> wShapeRange(&wTensorMin, &wTensorMax);
  gert::Range<gert::Shape> yShapeRange(&yShapeMinNull, &yShapeMaxNull);

  auto holder = ctx_builder.IONum(2, 1)
                    .OutputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                    .OpType("DIY")
                    .OpName("diy_1")
                    .InputTensorsRange({&xShapeRange, &wShapeRange})
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  const CompileTimeTensorDesc *info_input_0 = ctx->GetInputDesc(0);
  EXPECT_NE(info_input_0, nullptr);
  EXPECT_EQ(info_input_0->GetDataType(), ge::DT_MAX);
  EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_MAX);
  EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_MAX);
}

TEST_F(UtestContextBuilder, CreateTilingContextOK) {
  auto workspace_size_holer = gert::ContinuousVector::Create<size_t>(4096);
  auto ws_ptr = reinterpret_cast<gert::ContinuousVector *>(workspace_size_holer.get());

  gert::Shape shape_0{1, 1, 1, 1, 1};
  gert::Shape shape_1{10, 10, 10, 10, 20};
  gert::Shape shape_2{1, 1, 1, 1, 1};
  gert::Shape shape_3{10, 10, 10, 10, 20};
  gert::Shape resultShape{10, 10, 10, 10, 20};

  gert::StorageShape x({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape resultIn({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape gamma({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape beta({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape result({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});

  uint8_t data_x[1] = {9};
  gert::Tensor x_tensor(x, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                        ge::DT_FLOAT, (void *) data_x);
  gert::Tensor resultIn_tensor(resultIn, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                               TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr);
  gert::Tensor gammax_tensor(gamma, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                             ge::DT_FLOAT, nullptr);
  gert::Tensor beta_tensor(beta, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                           ge::DT_FLOAT, nullptr);
  gert::Tensor result_tensor(result, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                             TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr);

  auto tmp_tiling_data = gert::TilingData::CreateCap(100);
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};
  int32_t deterministic = 1;

  OpTilingContextBuilder ctx_builder;
  auto holder = ctx_builder.OpName("tmp")
                    .OpType("DIY")
                    .IONum(4, 1)
                    .AppendAttr(int64_t(1))
                    .AppendAttr(bool(true))
                    .AppendAttr(float(0.3))
                    .AppendAttr(AscendString("my_info"))
                    .AppendAttr(std::vector<bool>({true, false, true}))
                    .AppendAttr(std::vector<int64_t>({1, 2, 3}))
                    .AppendAttr(std::vector<float>({0.1, 0.2, 0.3}))
                    .AppendAttr(std::vector<AscendString>({"123", "234"}))
                    .AppendAttr(std::vector<std::vector<int64_t>>({{1, 2, 3}, {4, 5, 6}}))
                    .TilingData(reinterpret_cast<gert::TilingData *>(tmp_tiling_data.get()))
                    .Workspace(ws_ptr)
                    .CompileInfo(tmp_compile_info)
                    .Deterministic(deterministic)
                    .PlatformInfo(tmp_platform_info)
                    .InputTensors({&x_tensor, &resultIn_tensor, &gammax_tensor, &beta_tensor})
                    .OutputTensors({&result_tensor})
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(ctx->GetCompileInfo(), tmp_compile_info);
  EXPECT_EQ(ctx->GetInputShape(0)->GetOriginShape(), shape_0);
  EXPECT_EQ(ctx->GetInputShape(0)->GetStorageShape(), shape_0);
  EXPECT_EQ(ctx->GetInputTensor(0)->GetAddr(), data_x);
  EXPECT_EQ(ctx->GetInputTensor(0), &x_tensor);
  EXPECT_EQ(ctx->GetInputTensor(0)->GetStorageShape(), x_tensor.GetStorageShape());
  EXPECT_EQ(ctx->GetInputTensor(0)->GetOriginShape(), x_tensor.GetOriginShape());
  EXPECT_EQ(ctx->GetInputTensor(0)->GetSize(), x_tensor.GetSize());
  EXPECT_EQ(ctx->GetOutputShape(0)->GetOriginShape(), resultShape);
  EXPECT_EQ(ctx->GetOutputShape(0)->GetStorageShape(), resultShape);
  EXPECT_EQ(static_cast<void *>(ctx->GetWorkspaceSizes(4096)), static_cast<const void *>(ws_ptr->GetData()));
  EXPECT_EQ(static_cast<void *>(ctx->GetPlatformInfo()), static_cast<void *>(tmp_platform_info));
  EXPECT_EQ(ctx->GetDeterministic(), deterministic);
  EXPECT_EQ(static_cast<void *>(ctx->GetRawTilingData()), static_cast<void *>(tmp_tiling_data.get()));
  EXPECT_EQ(*(ctx->GetAttrs()->GetInt(0)), 1);
  EXPECT_EQ(*(ctx->GetAttrs()->GetBool(1)), true);
  EXPECT_FLOAT_EQ(*(ctx->GetAttrs()->GetFloat(2)), 0.3);
  auto str_ptr = ctx->GetAttrs()->GetStr(3);
  EXPECT_EQ(strcmp(str_ptr, "my_info"), 0);
  auto bool_vec = ctx->GetAttrs()->GetAttrPointer<TypedContinuousVector<bool>>(4);
  EXPECT_EQ(bool_vec->GetData()[0], true);
  EXPECT_EQ(bool_vec->GetData()[1], false);
  EXPECT_EQ(bool_vec->GetData()[2], true);
  EXPECT_EQ(ctx->GetAttrs()->GetListInt(5)->GetData()[0], 1);
  EXPECT_EQ(ctx->GetAttrs()->GetListInt(5)->GetData()[1], 2);
  EXPECT_EQ(ctx->GetAttrs()->GetListInt(5)->GetData()[2], 3);
  EXPECT_FLOAT_EQ(ctx->GetAttrs()->GetListFloat(6)->GetData()[0], 0.1);
  EXPECT_FLOAT_EQ(ctx->GetAttrs()->GetListFloat(6)->GetData()[1], 0.2);
  EXPECT_FLOAT_EQ(ctx->GetAttrs()->GetListFloat(6)->GetData()[2], 0.3);
  auto int_vec_vec = ctx->GetAttrs()->GetListListInt(8);
  EXPECT_EQ(((int64_t *) (int_vec_vec->Get(0)->GetData()))[0], 1);
  EXPECT_EQ(((int64_t *) (int_vec_vec->Get(0)->GetData()))[1], 2);
  EXPECT_EQ(((int64_t *) (int_vec_vec->Get(0)->GetData()))[2], 3);
  EXPECT_EQ(((int64_t *) (int_vec_vec->Get(1)->GetData()))[0], 4);
  EXPECT_EQ(((int64_t *) (int_vec_vec->Get(1)->GetData()))[1], 5);
  EXPECT_EQ(((int64_t *) (int_vec_vec->Get(1)->GetData()))[2], 6);
}

TEST_F(UtestContextBuilder, CreateTilingContextViewWithTensorV2OK) {
  auto workspace_size_holer = gert::ContinuousVector::Create<size_t>(4096);
  auto ws_ptr = reinterpret_cast<gert::ContinuousVector *>(workspace_size_holer.get());

  gert::Shape shape_1{1, 1, 1, 1, 1};
  gert::Shape shape_2{10, 10, 10, 10, 20};
  gert::Shape resultShape{10, 10, 10, 10, 20};
  gert::Shape view_shape{20, 20, 20, 20, 40};

  gert::StorageShape x({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape resultIn({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape gamma({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape beta({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape result({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});

  uint8_t data_x[1] = {9};
  gert::TensorV2 x_tensor(x, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                        ge::DT_FLOAT, (void *) data_x);

  gert::TensorV2 resultIn_tensor(resultIn, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, ge::DT_FLOAT);

  gert::TensorV2 gammax_tensor(gamma, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                             ge::DT_FLOAT, nullptr, nullptr);
  Stride gammax_stride({1, 1, 1, 1, 1});
  gammax_tensor.GetShape().MutableShape()  = view_shape;
  gammax_tensor.MutableStride()  = gammax_stride;;
  gammax_tensor.SetOffset(8);

  Stride beta_stride({2, 2, 2, 2, 2});
  gert::TensorV2 beta_tensor(beta, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                           ge::DT_FLOAT, nullptr, nullptr, beta_stride, 8);

  gert::TensorV2 default_tensor;
  Stride default_stride({3, 3, 3, 3, 3});
  default_tensor.GetShape().MutableShape()  = view_shape;
  default_tensor.MutableStride()  = default_stride;;
  default_tensor.SetOffset(8);

  gert::TensorV2 result_tensor(result, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                             TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr, nullptr);
  Stride result_stride({4, 4, 4, 4, 4});
  result_tensor.GetShape().MutableShape()  = view_shape;
  result_tensor.MutableStride()  = result_stride;;
  result_tensor.SetOffset(8);

  auto tmp_tiling_data = gert::TilingData::CreateCap(100);
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};
  int32_t deterministic = 1;
  int32_t deterministic_level = 1;

  OpTilingContextBuilder ctx_builder;
  auto holder = ctx_builder.OpName("tmp")
                    .OpType("DIY")
                    .IONum(5, 1)
                    .AppendAttr(int64_t(1))
                    .AppendAttr(bool(true))
                    .AppendAttr(float(0.3))
                    .AppendAttr(AscendString("my_info"))
                    .AppendAttr(std::vector<bool>({true, false, true}))
                    .AppendAttr(std::vector<int64_t>({1, 2, 3}))
                    .AppendAttr(std::vector<float>({0.1, 0.2, 0.3}))
                    .AppendAttr(std::vector<AscendString>({"123", "234"}))
                    .AppendAttr(std::vector<std::vector<int64_t>>({{1, 2, 3}, {4, 5, 6}}))
                    .TilingData(reinterpret_cast<gert::TilingData *>(tmp_tiling_data.get()))
                    .Workspace(ws_ptr)
                    .CompileInfo(tmp_compile_info)
                    .Deterministic(deterministic)
                    .DeterministicLevel(deterministic_level)
                    .PlatformInfo(tmp_platform_info)
                    .InputTensors({reinterpret_cast<gert::Tensor*>(&x_tensor),
                                   reinterpret_cast<gert::Tensor*>(&resultIn_tensor),
                                   reinterpret_cast<gert::Tensor*>(&gammax_tensor),
                                   reinterpret_cast<gert::Tensor*>(&beta_tensor),
                                   reinterpret_cast<gert::Tensor*>(&default_tensor)})
                    .OutputTensors({reinterpret_cast<gert::Tensor*>(&result_tensor)})
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(ctx->GetCompileInfo(), tmp_compile_info);

  EXPECT_EQ(ctx->InputIsView(0), true);
  EXPECT_EQ(ctx->GetInputStride(0)->GetDimNum(), 0);
  EXPECT_EQ(ctx->GetInputStride(0)->GetStride(0), 0);
  EXPECT_EQ(ctx->GetInputOffset(0), 0);
  EXPECT_EQ(ctx->GetInputShape(0)->GetShape(), shape_1);

  EXPECT_EQ(ctx->InputIsView(1), true);
  EXPECT_EQ(ctx->GetInputStride(1)->GetDimNum(), 0);
  EXPECT_EQ(ctx->GetInputStride(1)->GetStride(0), 0);
  EXPECT_EQ(ctx->GetInputOffset(1), 0);
  EXPECT_EQ(ctx->GetInputShape(1)->GetShape(), shape_2);

  EXPECT_EQ(ctx->InputIsView(2), true);
  EXPECT_EQ(*(ctx->GetInputStride(2)), gammax_stride);
  EXPECT_EQ(ctx->GetInputOffset(2), 8);
  EXPECT_EQ(ctx->GetInputShape(2)->GetShape(), view_shape);

  EXPECT_EQ(ctx->InputIsView(3), true);
  EXPECT_EQ(*(ctx->GetInputStride(3)), beta_stride);
  EXPECT_EQ(ctx->GetInputOffset(3), 8);
  EXPECT_EQ(ctx->GetInputShape(3)->GetShape(), shape_2);

  EXPECT_EQ(ctx->OptionalInputIsView(3), true);
  EXPECT_EQ(*(ctx->GetOptionalInputStride(3)), beta_stride);
  EXPECT_EQ(ctx->GetOptionalInputOffset(3), 8);
  EXPECT_EQ(ctx->GetOptionalInputShape(3)->GetShape(), shape_2);

  EXPECT_EQ(ctx->DynamicInputIsView(3, 0), true);
  EXPECT_EQ(*(ctx->GetDynamicInputStride(3, 0)), beta_stride);
  EXPECT_EQ(ctx->GetDynamicInputOffset(3, 0), 8);
  EXPECT_EQ(ctx->GetDynamicInputShape(3, 0)->GetShape(), shape_2);

  EXPECT_EQ(ctx->RequiredInputIsView(3), true);
  EXPECT_EQ(*(ctx->GetRequiredInputStride(3)), beta_stride);
  EXPECT_EQ(ctx->GetRequiredInputOffset(3), 8);
  EXPECT_EQ(ctx->GetRequiredInputShape(3)->GetShape(), shape_2);

  EXPECT_EQ(ctx->InputIsView(4), true);
  EXPECT_EQ(*(ctx->GetInputStride(4)), default_stride);
  EXPECT_EQ(ctx->GetInputOffset(4), 8);
  EXPECT_EQ(ctx->GetInputShape(4)->GetShape(), view_shape);

  EXPECT_EQ(ctx->OutputIsView(0), true);
  EXPECT_EQ(*(ctx->GetOutputStride(0)), result_stride);
  EXPECT_EQ(ctx->GetOutputOffset(0), 8);
  EXPECT_EQ(ctx->GetOutputShape(0)->GetShape(), view_shape);

  // 异常索引验证
  EXPECT_EQ(ctx->InputIsView(5), false);
  EXPECT_EQ(ctx->GetInputStride(5), nullptr);
  EXPECT_EQ(ctx->GetInputOffset(5), -1);
  EXPECT_EQ(ctx->GetInputShape(5), nullptr);

  EXPECT_EQ(ctx->OptionalInputIsView(5), false);
  EXPECT_EQ(ctx->GetOptionalInputStride(5), nullptr);
  EXPECT_EQ(ctx->GetOptionalInputOffset(5), -1);
  EXPECT_EQ(ctx->GetOptionalInputShape(5), nullptr);

  EXPECT_EQ(ctx->RequiredInputIsView(5), false);
  EXPECT_EQ(ctx->GetRequiredInputStride(5), nullptr);
  EXPECT_EQ(ctx->GetRequiredInputOffset(5), -1);
  EXPECT_EQ(ctx->GetRequiredInputShape(5), nullptr);

  EXPECT_EQ(ctx->DynamicInputIsView(5, 0), false);
  EXPECT_EQ(ctx->GetDynamicInputStride(5, 0), nullptr);
  EXPECT_EQ(ctx->GetDynamicInputOffset(5, 0), -1);
  EXPECT_EQ(ctx->GetDynamicInputShape(5, 0), nullptr);

  EXPECT_EQ(ctx->OutputIsView(1), false);
  EXPECT_EQ(ctx->GetOutputStride(1), nullptr);
  EXPECT_EQ(ctx->GetOutputOffset(1), -1);
  EXPECT_EQ(ctx->GetOutputShape(1), nullptr);
}

TEST_F(UtestContextBuilder, CreateTilingContextViewWithTensorV1OK) {
  auto workspace_size_holer = gert::ContinuousVector::Create<size_t>(4096);
  auto ws_ptr = reinterpret_cast<gert::ContinuousVector *>(workspace_size_holer.get());

  gert::Shape shape_1{1, 1, 1, 1, 1};
  gert::Shape shape_2{10, 10, 10, 10, 20};
  gert::Shape shape_3{1, 1, 1, 1, 1};
  gert::Shape shape_4{10, 10, 10, 10, 20};
  gert::Shape resultShape{10, 10, 10, 10, 20};
  gert::Shape default_shape;

  gert::StorageShape x({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape resultIn({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape gamma({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape beta({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape result({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});

  uint8_t data_x[1] = {9};

  gert::Tensor x_tensor(x, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                        ge::DT_FLOAT, (void *) data_x, nullptr);

  gert::Tensor resultIn_tensor(resultIn, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, ge::DT_FLOAT);

  gert::Tensor gammax_tensor(gamma, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                             ge::DT_FLOAT, nullptr, nullptr);

  gert::Tensor beta_tensor(beta, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                           ge::DT_FLOAT, nullptr);

  gert::Tensor default_tensor;

  gert::Tensor result_tensor(result, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                             TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr, nullptr);

  auto tmp_tiling_data = gert::TilingData::CreateCap(100);
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};
  int32_t deterministic = 1;

  OpTilingContextBuilder ctx_builder;
  auto holder = ctx_builder.OpName("tmp")
                    .OpType("DIY")
                    .IONum(5, 1)
                    .AppendAttr(int64_t(1))
                    .AppendAttr(bool(true))
                    .AppendAttr(float(0.3))
                    .AppendAttr(AscendString("my_info"))
                    .AppendAttr(std::vector<bool>({true, false, true}))
                    .AppendAttr(std::vector<int64_t>({1, 2, 3}))
                    .AppendAttr(std::vector<float>({0.1, 0.2, 0.3}))
                    .AppendAttr(std::vector<AscendString>({"123", "234"}))
                    .AppendAttr(std::vector<std::vector<int64_t>>({{1, 2, 3}, {4, 5, 6}}))
                    .TilingData(reinterpret_cast<gert::TilingData *>(tmp_tiling_data.get()))
                    .Workspace(ws_ptr)
                    .CompileInfo(tmp_compile_info)
                    .Deterministic(deterministic)
                    .PlatformInfo(tmp_platform_info)
                    .InputTensors({&x_tensor, &resultIn_tensor, &gammax_tensor, &beta_tensor, &default_tensor})
                    .OutputTensors({&result_tensor})
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(ctx->GetCompileInfo(), tmp_compile_info);

  EXPECT_EQ(ctx->InputIsView(0), false);
  EXPECT_EQ(ctx->GetInputStride(0), nullptr);
  EXPECT_EQ(ctx->GetInputOffset(0), -1);
  EXPECT_EQ(ctx->GetInputShape(0)->GetShape(), shape_1);

  EXPECT_EQ(ctx->InputIsView(1), false);
  EXPECT_EQ(ctx->GetInputStride(1), nullptr);
  EXPECT_EQ(ctx->GetInputOffset(1), -1);
  EXPECT_EQ(ctx->GetInputShape(1)->GetShape(), shape_2);

  EXPECT_EQ(ctx->InputIsView(2), false);
  EXPECT_EQ(ctx->GetInputStride(2), nullptr);
  EXPECT_EQ(ctx->GetInputOffset(2), -1);
  EXPECT_EQ(ctx->GetInputShape(2)->GetShape(), shape_3);

  EXPECT_EQ(ctx->InputIsView(3), false);
  EXPECT_EQ(ctx->GetInputStride(3), nullptr);
  EXPECT_EQ(ctx->GetInputOffset(3), -1);
  EXPECT_EQ(ctx->GetInputShape(3)->GetShape(), shape_4);

  EXPECT_EQ(ctx->OptionalInputIsView(3), false);
  EXPECT_EQ(ctx->GetOptionalInputStride(3), nullptr);
  EXPECT_EQ(ctx->GetOptionalInputOffset(3), -1);
  EXPECT_EQ(ctx->GetOptionalInputShape(3)->GetShape(), shape_4);

  EXPECT_EQ(ctx->DynamicInputIsView(3, 0), false);
  EXPECT_EQ(ctx->GetDynamicInputStride(3, 0), nullptr);
  EXPECT_EQ(ctx->GetDynamicInputOffset(3, 0), -1);
  EXPECT_EQ(ctx->GetDynamicInputShape(3, 0)->GetShape(), shape_4);

  EXPECT_EQ(ctx->RequiredInputIsView(3), false);
  EXPECT_EQ(ctx->GetRequiredInputStride(3), nullptr);
  EXPECT_EQ(ctx->GetRequiredInputOffset(3), -1);
  EXPECT_EQ(ctx->GetRequiredInputShape(3)->GetShape(), shape_4);

  EXPECT_EQ(ctx->InputIsView(4), false);
  EXPECT_EQ(ctx->GetInputStride(4), nullptr);
  EXPECT_EQ(ctx->GetInputOffset(4), -1);
  EXPECT_EQ(ctx->GetInputShape(4)->GetShape(), default_shape);

  EXPECT_EQ(ctx->OutputIsView(0), false);
  EXPECT_EQ(ctx->GetOutputStride(0), nullptr);
  EXPECT_EQ(ctx->GetOutputOffset(0), -1);
  EXPECT_EQ(ctx->GetOutputShape(0)->GetShape(), resultShape);

  // 异常索引验证
  EXPECT_EQ(ctx->InputIsView(5), false);
  EXPECT_EQ(ctx->GetInputStride(5), nullptr);
  EXPECT_EQ(ctx->GetInputOffset(5), -1);
  EXPECT_EQ(ctx->GetInputShape(5), nullptr);

  EXPECT_EQ(ctx->OptionalInputIsView(5), false);
  EXPECT_EQ(ctx->GetOptionalInputStride(5), nullptr);
  EXPECT_EQ(ctx->GetOptionalInputOffset(5), -1);
  EXPECT_EQ(ctx->GetOptionalInputShape(5), nullptr);

  EXPECT_EQ(ctx->RequiredInputIsView(5), false);
  EXPECT_EQ(ctx->GetRequiredInputStride(5), nullptr);
  EXPECT_EQ(ctx->GetRequiredInputOffset(5), -1);
  EXPECT_EQ(ctx->GetRequiredInputShape(5), nullptr);

  EXPECT_EQ(ctx->DynamicInputIsView(5, 0), false);
  EXPECT_EQ(ctx->GetDynamicInputStride(5, 0), nullptr);
  EXPECT_EQ(ctx->GetDynamicInputOffset(5, 0), -1);
  EXPECT_EQ(ctx->GetDynamicInputShape(5, 0), nullptr);

  EXPECT_EQ(ctx->OutputIsView(1), false);
  EXPECT_EQ(ctx->GetOutputStride(1), nullptr);
  EXPECT_EQ(ctx->GetOutputOffset(1), -1);
  EXPECT_EQ(ctx->GetOutputShape(1), nullptr);
}


TEST_F(UtestContextBuilder, CreateTilingContextTilingDataSizeOK) {
  auto workspace_size_holer = gert::ContinuousVector::Create<size_t>(4096);
  auto ws_ptr = reinterpret_cast<gert::ContinuousVector *>(workspace_size_holer.get());
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};

  OpTilingContextBuilder ctx_builder;
  auto holder = ctx_builder.OpName("tmp")
                    .OpType("DIY")
                    .IONum(4, 1)
                    .CompileInfo(tmp_compile_info)
                    .PlatformInfo(tmp_platform_info)
                    .TilingDataSize(100)
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  EXPECT_NE(ctx->GetRawTilingData(), nullptr);
  EXPECT_EQ(ctx->GetRawTilingData()->GetCapacity(), 100);

  auto tmp_tiling_data_120 = gert::TilingData::CreateCap(120);
  OpTilingContextBuilder ctx_builder2;
  auto holder2 = ctx_builder2.OpName("tmp")
                     .OpType("DIY")
                     .IONum(1, 1)
                     .CompileInfo(tmp_compile_info)
                     .PlatformInfo(tmp_platform_info)
                     .TilingDataSize(100)
                     .TilingData(reinterpret_cast<const gert::TilingData *>(tmp_tiling_data_120.get()))
                     .Workspace(ws_ptr)
                     .Build();
  ctx = holder2.GetContext();
  EXPECT_NE(ctx, nullptr);
  EXPECT_NE(ctx->GetRawTilingData(), nullptr);
  EXPECT_EQ(ctx->GetRawTilingData(), reinterpret_cast<gert::TilingData*>(tmp_tiling_data_120.get()));
  EXPECT_EQ(ctx->GetRawTilingData()->GetCapacity(), 120);

  holder2 = ctx_builder2.OpName("tmp")
                   .OpType("DIY")
                   .IONum(1, 1)
                   .CompileInfo(tmp_compile_info)
                   .PlatformInfo(tmp_platform_info)
                   .TilingData(reinterpret_cast<const gert::TilingData *>(tmp_tiling_data_120.get()))
                   .TilingDataSize(100)
                   .Workspace(ws_ptr)
                   .Build();
  ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  EXPECT_NE(ctx->GetRawTilingData(), nullptr);
  EXPECT_EQ(ctx->GetRawTilingData()->GetCapacity(), 100);
}

TEST_F(UtestContextBuilder, CreateTilingParseContextOK) {

  std::string tmp_compile_json = "123.json";

  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};

  OpTilingParseContextBuilder ctx_builder;

  auto holder = ctx_builder.OpName("tmp")
                    .OpType("DIY")
                    .IONum(4, 1)
                    .InputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                    .InputTensorDesc(1, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                    .InputTensorDesc(2, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                    .InputTensorDesc(3, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                    .OutputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                    .CompiledJson(tmp_compile_json.c_str())
                    .CompiledInfo(tmp_compile_info)
                    .PlatformInfo(tmp_platform_info)
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(ctx->GetInputDesc(0)->GetOriginFormat(), ge::FORMAT_NCDHW);
  EXPECT_EQ(ctx->GetInputDesc(0)->GetStorageFormat(), ge::FORMAT_RESERVED);
  EXPECT_EQ((void *) ctx->GetPlatformInfo(), (void *) tmp_platform_info);
  EXPECT_EQ((void *) ctx->GetPlatformInfo(), (void *) tmp_platform_info);
  EXPECT_EQ(ctx->GetCompiledJson(), tmp_compile_json.c_str());
  EXPECT_EQ(ctx->GetCompiledInfo<uint8_t>(), tmp_compile_info);
}

TEST_F(UtestContextBuilder, CreateTilingParseContextExpandDimsTypeOK) {
  std::string tmp_compile_json = "123.json";

  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};

  OpTilingParseContextBuilder ctx_builder;
  gert::ExpandDimsType expand_dims_type11;
  expand_dims_type11.SetExpandIndex(11);
  gert::ExpandDimsType expand_dims_type12;
  expand_dims_type12.SetExpandIndex(12);
  auto holder = ctx_builder.OpName("tmp")
                    .OpType("DIY")
                    .IONum(2, 1)
                    .InputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, expand_dims_type11)
                    .InputTensorDesc(1, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, expand_dims_type12)
                    .OutputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, gert::ExpandDimsType())
                    .CompiledJson(tmp_compile_json.c_str())
                    .CompiledInfo(tmp_compile_info)
                    .PlatformInfo(tmp_platform_info)
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(ctx->GetInputDesc(0)->GetExpandDimsType(), expand_dims_type11);
  EXPECT_EQ(ctx->GetInputDesc(1)->GetExpandDimsType(), expand_dims_type12);
}

TEST_F(UtestContextBuilder, CreateTilingParseContextExpandDimsTypeFailed) {
  std::string tmp_compile_json = "123.json";

  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};

  OpTilingParseContextBuilder ctx_builder;
  gert::ExpandDimsType expand_dims_type11;
  expand_dims_type11.SetExpandIndex(11);
  gert::ExpandDimsType expand_dims_type12;
  expand_dims_type12.SetExpandIndex(12);
  auto holder = ctx_builder.OpName("tmp")
                    .OpType("DIY")
                    .IONum(2, 1)
                    .InputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, expand_dims_type11)
                    .InputTensorDesc(1, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, expand_dims_type12)
                    .InputTensorDesc(2, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, expand_dims_type12)
                    .OutputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, gert::ExpandDimsType())
                    .OutputTensorDesc(1, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, gert::ExpandDimsType())
                    .CompiledJson(tmp_compile_json.c_str())
                    .CompiledInfo(tmp_compile_info)
                    .PlatformInfo(tmp_platform_info)
                    .Build();

  auto ctx = holder.GetContext();
  EXPECT_NE(ctx, nullptr);
  auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
  EXPECT_NE(ctx_compute_node_info, nullptr);
  EXPECT_EQ(ctx->GetInputDesc(0)->GetExpandDimsType(), expand_dims_type11);
  EXPECT_EQ(ctx->GetInputDesc(1)->GetExpandDimsType(), expand_dims_type12);
}

TEST_F(UtestContextBuilder, SetDeterministicLevelTest) {
  auto workspace_size_holer = gert::ContinuousVector::Create<size_t>(4096);
  auto ws_ptr = reinterpret_cast<gert::ContinuousVector *>(workspace_size_holer.get());

  gert::StorageShape x({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape resultIn({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape gamma({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
  gert::StorageShape beta({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
  gert::StorageShape result({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});

  uint8_t data_x[1] = {9};
  gert::Tensor x_tensor(x, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                        ge::DT_FLOAT, (void *) data_x);
  gert::Tensor resultIn_tensor(resultIn, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                               TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr);
  gert::Tensor gammax_tensor(gamma, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                             ge::DT_FLOAT, nullptr);
  gert::Tensor beta_tensor(beta, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                           ge::DT_FLOAT, nullptr);
  gert::Tensor result_tensor(result, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                             TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr);

  auto tmp_tiling_data = gert::TilingData::CreateCap(100);
  uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7};
  uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7};
  int32_t deterministic = 1;

  auto BuildContext = [&](OpTilingContextBuilder &builder) {
    (void)builder.OpName("tmp")
        .OpType("DIY")
        .IONum(4, 1)
        .AppendAttr(int64_t(1))
        .AppendAttr(bool(true))
        .AppendAttr(float(0.3))
        .AppendAttr(AscendString("my_info"))
        .AppendAttr(std::vector<bool>({true, false, true}))
        .AppendAttr(std::vector<int64_t>({1, 2, 3}))
        .AppendAttr(std::vector<float>({0.1, 0.2, 0.3}))
        .AppendAttr(std::vector<AscendString>({"123", "234"}))
        .AppendAttr(std::vector<std::vector<int64_t>>({{1, 2, 3}, {4, 5, 6}}))
        .TilingData(reinterpret_cast<gert::TilingData *>(tmp_tiling_data.get()))
        .Workspace(ws_ptr)
        .CompileInfo(tmp_compile_info)
        .Deterministic(deterministic)
        .PlatformInfo(tmp_platform_info)
        .InputTensors({&x_tensor, &resultIn_tensor, &gammax_tensor, &beta_tensor})
        .OutputTensors({&result_tensor});
  };

  OpTilingContextBuilder ctx_builder1;
  BuildContext(ctx_builder1);
  ctx_builder1.DeterministicLevel(1);
  auto holder1 = ctx_builder1.Build();
  EXPECT_EQ(holder1.GetContext()->GetDeterministicLevel(), 1);

  OpTilingContextBuilder ctx_builder2;
  BuildContext(ctx_builder2);
  auto ret = gert_TilingContextBuilder_SetDeterministicLevel(nullptr, 1);
  EXPECT_EQ(ret, GRAPH_PARAM_INVALID);
  ret = gert_TilingContextBuilder_SetDeterministicLevel(reinterpret_cast<void *>(&ctx_builder2), 4);
  EXPECT_EQ(ret, GRAPH_PARAM_INVALID);
  ret = gert_TilingContextBuilder_SetDeterministicLevel(reinterpret_cast<void *>(&ctx_builder2), 2);
  EXPECT_EQ(ret, 0);
  auto holder2 = ctx_builder2.Build();
  EXPECT_EQ(holder2.GetContext()->GetDeterministicLevel(), 2);

  OpTilingContextBuilder ctx_builder3;
  BuildContext(ctx_builder3);
  ctx_builder3.DeterministicLevel(4);
  auto holder3 = ctx_builder3.Build();
  EXPECT_EQ(holder3.GetContext()->GetDeterministicLevel(), 0);
}
