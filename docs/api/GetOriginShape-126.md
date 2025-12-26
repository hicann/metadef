# GetOriginShape<a name="ZH-CN_TOPIC_0000002518460607"></a>

## 函数功能<a name="zh-cn_topic_0000001634265513_zh-cn_topic_0000001339713798_section36583473819"></a>

获取Tensor的原始Shape。

## 函数原型<a name="zh-cn_topic_0000001634265513_zh-cn_topic_0000001339713798_section13230182415108"></a>

```
const Shape &GetOriginShape() const
```

## 参数说明<a name="zh-cn_topic_0000001634265513_zh-cn_topic_0000001339713798_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001634265513_zh-cn_topic_0000001339713798_section25791320141317"></a>

只读的原始Shape引用。

关于Shape类型的定义，请参见[Shape](Shape.md)。

## 约束说明<a name="zh-cn_topic_0000001634265513_zh-cn_topic_0000001339713798_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634265513_zh-cn_topic_0000001339713798_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {2, 1, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetOriginShape(); // 1,2,3
```

