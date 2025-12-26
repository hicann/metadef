# Build<a name="ZH-CN_TOPIC_0000002421312598"></a>

## 函数功能<a name="zh-cn_topic_0000002453597597_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section36583473819"></a>

根据之前的设置，构建InferDataTypeContext，返回一个ContextHolder<InferDataTypeContext\>对象。

## 函数原型<a name="zh-cn_topic_0000002453597597_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
ContextHolder<InferDataTypeContext> Build()
```

## 参数说明<a name="zh-cn_topic_0000002453597597_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000002453597597_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section25791320141317"></a>

返回一个ContextHolder<InferDataTypeContext\>对象。通过调用GetContext\(\)方法可获取InferDataTypeContext指针。

## 约束说明<a name="zh-cn_topic_0000002453597597_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section19165124931511"></a>

-   所有通过指针传入OpInferDataTypeContextBuilder的参数，其内存所有权归调用者。调用者必须确保这些指针在ContextHolder对象的整个生命周期内有效。
-   ContextHolder析构时会自动释放内部上下文资源。请勿手动释放GetContext\(\)返回的指针。

## 调用示例<a name="zh-cn_topic_0000002453597597_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section320753512363"></a>

```
#include "base/context_builder/op_infer_datatype_context_builder.h"
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
```

