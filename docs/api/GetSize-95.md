# GetSize<a name="ZH-CN_TOPIC_0000002078447737"></a>

## 函数功能<a name="zh-cn_topic_0000001634064969_zh-cn_topic_0000001389912121_section36583473819"></a>

获取Tensor数据的内存大小。

## 函数原型<a name="zh-cn_topic_0000001634064969_zh-cn_topic_0000001389912121_section13230182415108"></a>

**size\_t GetSize\(\) const**

## 参数说明<a name="zh-cn_topic_0000001634064969_zh-cn_topic_0000001389912121_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001634064969_zh-cn_topic_0000001389912121_section25791320141317"></a>

内存大小，单位是字节。

## 约束说明<a name="zh-cn_topic_0000001634064969_zh-cn_topic_0000001389912121_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634064969_zh-cn_topic_0000001389912121_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto td_size = t.GetSize(); // 1*2*3*sizeof(float) = 24;
```

