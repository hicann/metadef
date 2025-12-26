# MutableOriginShape<a name="ZH-CN_TOPIC_0000002486260732"></a>

## 函数功能<a name="zh-cn_topic_0000001634064973_zh-cn_topic_0000001339553818_section36583473819"></a>

获取Tensor的原始shape。

## 函数原型<a name="zh-cn_topic_0000001634064973_zh-cn_topic_0000001339553818_section13230182415108"></a>

```
Shape &MutableOriginShape()
```

## 参数说明<a name="zh-cn_topic_0000001634064973_zh-cn_topic_0000001339553818_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001634064973_zh-cn_topic_0000001339553818_section25791320141317"></a>

原始Shape引用。

关于Shape类型的定义，请参见[Shape](Shape.md)。

## 约束说明<a name="zh-cn_topic_0000001634064973_zh-cn_topic_0000001339553818_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001634064973_zh-cn_topic_0000001339553818_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {2, 1, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.MutableOriginShape(); // 1,2,3
```

