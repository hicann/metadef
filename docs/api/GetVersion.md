# GetVersion<a name="ZH-CN_TOPIC_0000002519126777"></a>

## 函数功能<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section36583473819"></a>

获取Tensor中的版本。kTensorV1：不携带view和offset 信息， kTensorV2：携带view和offset信息

>![](public_sys-resources/icon-note.gif) **说明：** 
>该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

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
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape                
               {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format                              
               kFollowing,                                  // placement                
               ge::DT_FLOAT16,                              //dt                
               nullptr};
auto version = tensor.GetVersion(); // kTensorV1
```

