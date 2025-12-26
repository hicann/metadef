# MutableStorageShape<a name="ZH-CN_TOPIC_0000002042368746"></a>

## 函数功能<a name="zh-cn_topic_0000001584184970_zh-cn_topic_0000001390097241_section36583473819"></a>

获取可写的运行时shape。

## 函数原型<a name="zh-cn_topic_0000001584184970_zh-cn_topic_0000001390097241_section13230182415108"></a>

```
Shape &MutableStorageShape()
```

## 参数说明<a name="zh-cn_topic_0000001584184970_zh-cn_topic_0000001390097241_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001584184970_zh-cn_topic_0000001390097241_section25791320141317"></a>

可写的运行时shape。

## 约束说明<a name="zh-cn_topic_0000001584184970_zh-cn_topic_0000001390097241_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584184970_zh-cn_topic_0000001390097241_section320753512363"></a>

```
StorageShape shape({3, 256, 256}, {256, 256, 3});
auto storage_shape = shape.MutableStorageShape(); // 256,256,3
```

