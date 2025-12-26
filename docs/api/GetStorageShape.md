# GetStorageShape<a name="ZH-CN_TOPIC_0000002078447825"></a>

## 函数功能<a name="zh-cn_topic_0000001634265529_zh-cn_topic_0000001339577300_section36583473819"></a>

获取运行时shape。

## 函数原型<a name="zh-cn_topic_0000001634265529_zh-cn_topic_0000001339577300_section13230182415108"></a>

```
const Shape &GetStorageShape() const
```

## 参数说明<a name="zh-cn_topic_0000001634265529_zh-cn_topic_0000001339577300_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001634265529_zh-cn_topic_0000001339577300_section25791320141317"></a>

运行时shape。

## 约束说明<a name="zh-cn_topic_0000001634265529_zh-cn_topic_0000001339577300_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634265529_zh-cn_topic_0000001339577300_section320753512363"></a>

```
StorageShape shape({3, 256, 256}, {256, 256, 3});
auto storage_shape = shape.GetStorageShape(); // 256,256,3
```

