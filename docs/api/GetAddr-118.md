# GetAddr<a name="ZH-CN_TOPIC_0000002518460603"></a>

## 函数功能<a name="zh-cn_topic_0000001634265505_zh-cn_topic_0000001390151661_section36583473819"></a>

获取Tensor的数据地址。

## 函数原型<a name="zh-cn_topic_0000001634265505_zh-cn_topic_0000001390151661_section13230182415108"></a>

```
const void *GetAddr() const
void *GetAddr()
```

## 参数说明<a name="zh-cn_topic_0000001634265505_zh-cn_topic_0000001390151661_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001634265505_zh-cn_topic_0000001390151661_section25791320141317"></a>

返回数据地址。

## 约束说明<a name="zh-cn_topic_0000001634265505_zh-cn_topic_0000001390151661_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001634265505_zh-cn_topic_0000001390151661_section320753512363"></a>

```
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape                
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format                              
                kFollowing,                                  // placement                
                ge::DT_FLOAT16,                              //dt                
                nullptr};
auto addr = tensor.GetAddr(); // &tensor + 1
```

