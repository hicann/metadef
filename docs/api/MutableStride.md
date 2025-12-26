# MutableStride<a name="ZH-CN_TOPIC_0000002519041517"></a>

## 函数功能<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section36583473819"></a>

获取Tensor中的Stride引用，该Stride可修改。

## 函数原型<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section13230182415108"></a>

```
Stride &MutableStride()
```

## 参数说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section25791320141317"></a>

可写的Tensor Stride引用。

关于Stride类型的定义，请参见[Stride](Stride.md)。

## 约束说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 0};
t.MutableStride() = Stride({6, 1, 1});
auto stride = t.GetStride(); // Stride({6, 1, 1})
```

