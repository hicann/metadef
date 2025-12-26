# GetExpandDimsType<a name="ZH-CN_TOPIC_0000002078486441"></a>

## 函数功能<a name="zh-cn_topic_0000001635424853_zh-cn_topic_0000001339410542_section36583473819"></a>

获取补维规则。

## 函数原型<a name="zh-cn_topic_0000001635424853_zh-cn_topic_0000001339410542_section13230182415108"></a>

```
ExpandDimsType GetExpandDimsType() const
```

## 参数说明<a name="zh-cn_topic_0000001635424853_zh-cn_topic_0000001339410542_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001635424853_zh-cn_topic_0000001339410542_section25791320141317"></a>

补维规则。

## 约束说明<a name="zh-cn_topic_0000001635424853_zh-cn_topic_0000001339410542_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635424853_zh-cn_topic_0000001339410542_section320753512363"></a>

```
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
auto fmt_dim_type = format.GetExpandDimsType();
```

