# GetOriginFormat<a name="ZH-CN_TOPIC_0000002078486433"></a>

## 函数功能<a name="zh-cn_topic_0000001585264980_zh-cn_topic_0000001339730426_section36583473819"></a>

获取原始format。

## 函数原型<a name="zh-cn_topic_0000001585264980_zh-cn_topic_0000001339730426_section13230182415108"></a>

```
ge::Format GetOriginFormat() const
```

## 参数说明<a name="zh-cn_topic_0000001585264980_zh-cn_topic_0000001339730426_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001585264980_zh-cn_topic_0000001339730426_section25791320141317"></a>

原始format。

## 约束说明<a name="zh-cn_topic_0000001585264980_zh-cn_topic_0000001339730426_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585264980_zh-cn_topic_0000001339730426_section320753512363"></a>

```
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
auto origin_format = format.GetOriginFormat();  // Format::FORMAT_NCHW
```

