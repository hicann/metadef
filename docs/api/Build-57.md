# Build<a name="ZH-CN_TOPIC_0000002455031473"></a>

## 函数功能<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section36583473819"></a>

根据之前的设置，构建TilingParseContext，返回一个ContextHolder<TilingParseContext\> 对象。

## 函数原型<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
ContextHolder<TilingParseContext> Build()
```

## 参数说明<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section25791320141317"></a>

返回一个 ContextHolder<TilingParseContext\> 对象，通过其GetContext\(\)方法可获取TilingParseContext指针。

## 约束说明<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section19165124931511"></a>

-   所有通过指针传入的参数，其内存所有权归调用者所有；调用者必须确保这些指针在ContextHolder对象的整个生命周期内有效。
-   ContextHolder析构时会自动释放内部上下文资源。请勿手动释放GetContext\(\) 返回的指针。

## 调用示例<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section320753512363"></a>

```
#include "base/context_builder/op_tiling_parse_context_builder.h"
const char* json_data = R"({"block_dim": 16, "stream_num": 1})";
uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7}; // fake数据
uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7}; // fake数据
OpTilingParseContextBuilder ctx_builder;
auto holder = ctx_builder.OpName("tmp")
                  .OpType("DIY")
                  .IONum(4, 1)
                  .InputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .InputTensorDesc(1, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .InputTensorDesc(2, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .InputTensorDesc(3, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .OutputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .CompiledJson(json_data)
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
EXPECT_EQ(std::string(ctx->GetCompiledJson()), std::string(json_data.c_str()));
EXPECT_EQ(ctx->GetCompiledInfo<uint8_t>(), tmp_compile_info);
```

