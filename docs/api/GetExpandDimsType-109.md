# GetExpandDimsType<a name="ZH-CN_TOPIC_0000002078447753"></a>

## 函数功能<a name="zh-cn_topic_0000001634064977_zh-cn_topic_0000001339553822_section36583473819"></a>

获取shape的补维规则。

## 函数原型<a name="zh-cn_topic_0000001634064977_zh-cn_topic_0000001339553822_section13230182415108"></a>

**ExpandDimsType GetExpandDimsType\(\) const**

## 参数说明<a name="zh-cn_topic_0000001634064977_zh-cn_topic_0000001339553822_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001634064977_zh-cn_topic_0000001339553822_section25791320141317"></a>

返回shape的补维规则。

关于ExpandDimsType类型的定义，请参见[ExpandDimsType](ExpandDimsType.md)。

## 约束说明<a name="zh-cn_topic_0000001634064977_zh-cn_topic_0000001339553822_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634064977_zh-cn_topic_0000001339553822_section320753512363"></a>

```
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape              
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format              
              kFollowing,                                  // placement              
              ge::DT_FLOAT16,                              //dt              
              nullptr};
auto expand_dims_type = tensor.GetExpandDimsType();   // ExpandDimsType{}
```

