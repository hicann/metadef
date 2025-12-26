# GetStorageShape<a name="ZH-CN_TOPIC_0000002518580597"></a>

## 函数功能<a name="zh-cn_topic_0000001583865626_zh-cn_topic_0000001390071737_section36583473819"></a>

获取运行时Tensor的StorageShape，此Shape对象为只读。StorageShape和[Originshape](GetOriginShape-101.md)的区别如下：Originshape是Tensor最初创建时的形状，StorageShape是保存Tensor数据的底层存储的形状。运行时为了适配底层硬件，Tensor的StorageShape和其Originshape可能会有所不同。

## 函数原型<a name="zh-cn_topic_0000001583865626_zh-cn_topic_0000001390071737_section13230182415108"></a>

```
const Shape &GetStorageShape() const
```

## 参数说明<a name="zh-cn_topic_0000001583865626_zh-cn_topic_0000001390071737_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001583865626_zh-cn_topic_0000001390071737_section25791320141317"></a>

只读的运行时shape引用。

## 约束说明<a name="zh-cn_topic_0000001583865626_zh-cn_topic_0000001390071737_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001583865626_zh-cn_topic_0000001390071737_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {2, 1, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetStorageShape(); // 2,1,3
```

