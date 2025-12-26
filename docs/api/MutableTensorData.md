# MutableTensorData<a name="ZH-CN_TOPIC_0000002042526982"></a>

## 函数功能<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section36583473819"></a>

获取tensor中的数据。

## 函数原型<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section13230182415108"></a>

**TensorData &MutableTensorData\(\)**

## 参数说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section25791320141317"></a>

可写的tensor data引用。

关于TensorData类型的定义，请参见[TensorData](TensorData.md)。

## 约束说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto a = reinterpret_cast<void *>(10);
t.MutableTensorData() = TensorData{a, nullptr}; // 设置新tensordata
auto td = t.GetTensorData(); // TensorData{a, nullptr}
```

