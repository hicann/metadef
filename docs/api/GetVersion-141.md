# GetVersion<a name="ZH-CN_TOPIC_0000002487041626"></a>

## 函数功能<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section36583473819"></a>

获取Tensor中的version。

## 函数原型<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section13230182415108"></a>

```
TensorVersion GetVersion () const
```

## 参数说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section25791320141317"></a>

获取Tensor的version。

关于TensorVersion类型的定义，请参见[TensorVersion](TensorVersion.md)。

## 约束说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section320753512363"></a>

```
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape                
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format                              
                kFollowing,                                  // placement                
                ge::DT_FLOAT16,                              //dt                
                nullptr};
auto version = tensor.GetVersion(); // kTensorV2
```

