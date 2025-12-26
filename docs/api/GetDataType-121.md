# GetDataType<a name="ZH-CN_TOPIC_0000002486420698"></a>

## 函数功能<a name="zh-cn_topic_0000001584025006_zh-cn_topic_0000001339711742_section36583473819"></a>

获取Tensor的数据类型。

## 函数原型<a name="zh-cn_topic_0000001584025006_zh-cn_topic_0000001339711742_section13230182415108"></a>

```
ge::DataType GetDataType() const
```

## 参数说明<a name="zh-cn_topic_0000001584025006_zh-cn_topic_0000001339711742_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001584025006_zh-cn_topic_0000001339711742_section25791320141317"></a>

返回Tensor中的数据类型。

关于ge::DataType的定义，请参见[DataType](DataType.md)。

## 约束说明<a name="zh-cn_topic_0000001584025006_zh-cn_topic_0000001339711742_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584025006_zh-cn_topic_0000001339711742_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto dt = t.GetDataType(); //  ge::DT_FLOAT
```

