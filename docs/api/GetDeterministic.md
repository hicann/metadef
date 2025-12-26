# GetDeterministic<a name="ZH-CN_TOPIC_0000002142344965"></a>

## 函数功能<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section36583473819"></a>

获取确定性计算配置选项。

## 函数原型<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section13230182415108"></a>

**int32\_t GetDeterministic\(\) const**

## 参数说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section25791320141317"></a>

0：未开启确定性配置选项。

1：开启确定性配置选项。

## 约束说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  int32_t ret = context->GetDeterministic();
  // ...
}
```

