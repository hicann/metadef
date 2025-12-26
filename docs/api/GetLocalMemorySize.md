# GetLocalMemorySize<a name="ZH-CN_TOPIC_0000002069054562"></a>

## 函数功能<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section36583473819"></a>

算子获取所需的Local Memory大小。

**该接口为预留接口，为后续功能做保留，不建议开发者使用，开发者无需关注。**

## 函数原型<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section13230182415108"></a>

**uint32\_t GetLocalMemorySize\(\)**

## 参数说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section25791320141317"></a>

返回Local Memory大小，如果之前没有调用SetLocalMemorySize进行设置，则返回0。

## 约束说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto local_memory_size = context->GetLocalMemorySize();
  // ...
}
```

