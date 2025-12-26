# GetOriginFormat<a name="ZH-CN_TOPIC_0000002078447749"></a>

## 函数功能<a name="zh-cn_topic_0000001583705854_zh-cn_topic_0000001389914177_section36583473819"></a>

获取Tensor的原始format。

## 函数原型<a name="zh-cn_topic_0000001583705854_zh-cn_topic_0000001389914177_section13230182415108"></a>

**ge::Format GetOriginFormat\(\) const**

## 参数说明<a name="zh-cn_topic_0000001583705854_zh-cn_topic_0000001389914177_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001583705854_zh-cn_topic_0000001389914177_section25791320141317"></a>

原始format。

关于ge::Format类型的定义，请参见[Format](Format.md)。

## 约束说明<a name="zh-cn_topic_0000001583705854_zh-cn_topic_0000001389914177_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001583705854_zh-cn_topic_0000001389914177_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetOriginFormat(ge::FORMAT_NHWC);
t.SetStorageFormat(ge::FORMAT_NC1HWC0);
auto fmt = t.GetOriginFormat(); // ge::FORMAT_NHWC
```

