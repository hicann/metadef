# GetFormat<a name="ZH-CN_TOPIC_0000002042368670"></a>

## 函数功能<a name="zh-cn_topic_0000001634184901_zh-cn_topic_0000001339393886_section36583473819"></a>

获取Tensor的format，包含运行时format和原始format，返回的format对象都是只读的。

## 函数原型<a name="zh-cn_topic_0000001634184901_zh-cn_topic_0000001339393886_section13230182415108"></a>

**const StorageFormat &GetFormat\(\) const**

## 参数说明<a name="zh-cn_topic_0000001634184901_zh-cn_topic_0000001339393886_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001634184901_zh-cn_topic_0000001339393886_section25791320141317"></a>

只读的format引用。

关于StorageFormat类型的定义，请参见[StorageFormat](StorageFormat.md)。

## 约束说明<a name="zh-cn_topic_0000001634184901_zh-cn_topic_0000001339393886_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634184901_zh-cn_topic_0000001339393886_section320753512363"></a>

```
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape              
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format              
              kFollowing,                                  // placement              
              ge::DT_FLOAT16,                              //dt              
              nullptr};
auto fmt = tensor.GetFormat(); 
```

