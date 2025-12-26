# MutableFormat<a name="ZH-CN_TOPIC_0000002518460611"></a>

## 函数功能<a name="zh-cn_topic_0000001634265517_zh-cn_topic_0000001339713802_section36583473819"></a>

获取Tensor的数据格式，包含运行时数据格式和原始数据格式。

## 函数原型<a name="zh-cn_topic_0000001634265517_zh-cn_topic_0000001339713802_section13230182415108"></a>

```
StorageFormat &MutableFormat()
```

## 参数说明<a name="zh-cn_topic_0000001634265517_zh-cn_topic_0000001339713802_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001634265517_zh-cn_topic_0000001339713802_section25791320141317"></a>

Format引用。

关于StorageFormat类型的定义，请参见[StorageFormat](StorageFormat.md)。

## 约束说明<a name="zh-cn_topic_0000001634265517_zh-cn_topic_0000001339713802_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001634265517_zh-cn_topic_0000001339713802_section320753512363"></a>

```
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape              
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format              
                kFollowing,                                  // placement              
                ge::DT_FLOAT16,                              //dt              
                nullptr};
auto fmt = tensor.MutableFormat(); 
```

