# GetOriginShape<a name="ZH-CN_TOPIC_0000002078486425"></a>

## 函数功能<a name="zh-cn_topic_0000001634184913_zh-cn_topic_0000001339417376_section36583473819"></a>

获取原始shape。

## 函数原型<a name="zh-cn_topic_0000001634184913_zh-cn_topic_0000001339417376_section13230182415108"></a>

```
const Shape &GetOriginShape() const
```

## 参数说明<a name="zh-cn_topic_0000001634184913_zh-cn_topic_0000001339417376_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001634184913_zh-cn_topic_0000001339417376_section25791320141317"></a>

原始shape。

## 约束说明<a name="zh-cn_topic_0000001634184913_zh-cn_topic_0000001339417376_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634184913_zh-cn_topic_0000001339417376_section320753512363"></a>

```
StorageShape shape({3, 256, 256}, {256, 256, 3});
auto origin_shape = shape.GetOriginShape(); // 3,256,256
```

