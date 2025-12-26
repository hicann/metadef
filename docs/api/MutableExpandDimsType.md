# MutableExpandDimsType<a name="ZH-CN_TOPIC_0000002042527066"></a>

## 函数功能<a name="zh-cn_topic_0000001635065525_zh-cn_topic_0000001389930801_section36583473819"></a>

获取可写的补维规则。

## 函数原型<a name="zh-cn_topic_0000001635065525_zh-cn_topic_0000001389930801_section13230182415108"></a>

```
ExpandDimsType &MutableExpandDimsType()
```

## 参数说明<a name="zh-cn_topic_0000001635065525_zh-cn_topic_0000001389930801_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001635065525_zh-cn_topic_0000001389930801_section25791320141317"></a>

补维规则引用。

## 约束说明<a name="zh-cn_topic_0000001635065525_zh-cn_topic_0000001389930801_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635065525_zh-cn_topic_0000001389930801_section320753512363"></a>

```
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
ExpandDimsType new_dim_type("1010");
format.SetExpandDimsType(new_dim_type);
auto &fmt_dim_type = format.MutableExpandDimsType();
```

