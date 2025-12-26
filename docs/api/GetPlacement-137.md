# GetPlacement<a name="ZH-CN_TOPIC_0000002486420706"></a>

## 函数功能<a name="zh-cn_topic_0000001584025014_zh-cn_topic_0000001390153701_section36583473819"></a>

获取Tensor的placement。

## 函数原型<a name="zh-cn_topic_0000001584025014_zh-cn_topic_0000001390153701_section13230182415108"></a>

```
TensorPlacement GetPlacement() const
```

## 参数说明<a name="zh-cn_topic_0000001584025014_zh-cn_topic_0000001390153701_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001584025014_zh-cn_topic_0000001390153701_section25791320141317"></a>

返回tensor的placement。

关于TensorPlacement类型的定义，请参见[TensorPlacement](TensorPlacement.md)。

## 约束说明<a name="zh-cn_topic_0000001584025014_zh-cn_topic_0000001390153701_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001584025014_zh-cn_topic_0000001390153701_section320753512363"></a>

```
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape              
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format              
                kFollowing,                                  // placement              
                ge::DT_FLOAT16,                              //dt              
                nullptr};
auto placement = tensor.GetPlacement(); // kFollowing
```

