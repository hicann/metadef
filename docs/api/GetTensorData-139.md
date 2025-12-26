# GetTensorData<a name="ZH-CN_TOPIC_0000002486260738"></a>

## 函数功能<a name="zh-cn_topic_0000001583705858_zh-cn_topic_0000001389914181_section36583473819"></a>

获取Tensor中的数据，返回只读的TensorData类型对象。

## 函数原型<a name="zh-cn_topic_0000001583705858_zh-cn_topic_0000001389914181_section13230182415108"></a>

```
const TensorData &GetTensorData() const
```

## 参数说明<a name="zh-cn_topic_0000001583705858_zh-cn_topic_0000001389914181_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001583705858_zh-cn_topic_0000001389914181_section25791320141317"></a>

只读的tensor data引用。

关于TensorData类型的定义，请参见[TensorData](TensorData.md)。

## 约束说明<a name="zh-cn_topic_0000001583705858_zh-cn_topic_0000001389914181_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001583705858_zh-cn_topic_0000001389914181_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto a = reinterpret_cast<void *>(10);
t.MutableTensorData() = TensorData{a, nullptr}; // 设置新tensordata
auto addr = t.GetTensorData().GetAddr(); // 10
```

