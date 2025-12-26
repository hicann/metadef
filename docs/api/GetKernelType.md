# GetKernelType<a name="ZH-CN_TOPIC_0000002078447717"></a>

## 函数功能<a name="zh-cn_topic_0000001642297037_zh-cn_topic_0000001389625401_section36583473819"></a>

获取本kernel的类型。

## 函数原型<a name="zh-cn_topic_0000001642297037_zh-cn_topic_0000001389625401_section13230182415108"></a>

```
const ge::char_t *GetKernelType() const
```

## 参数说明<a name="zh-cn_topic_0000001642297037_zh-cn_topic_0000001389625401_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001642297037_zh-cn_topic_0000001389625401_section25791320141317"></a>

本kernel的type。

## 约束说明<a name="zh-cn_topic_0000001642297037_zh-cn_topic_0000001389625401_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642297037_zh-cn_topic_0000001389625401_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto kernel_type = extend_context->GetKernelType();
```

