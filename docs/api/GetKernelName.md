# GetKernelName<a name="ZH-CN_TOPIC_0000002078486313"></a>

## 函数功能<a name="zh-cn_topic_0000001592697020_zh-cn_topic_0000001389505457_section36583473819"></a>

获取本kernel的名称。

## 函数原型<a name="zh-cn_topic_0000001592697020_zh-cn_topic_0000001389505457_section13230182415108"></a>

```
const ge::char_t *GetKernelName() const
```

## 参数说明<a name="zh-cn_topic_0000001592697020_zh-cn_topic_0000001389505457_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001592697020_zh-cn_topic_0000001389505457_section25791320141317"></a>

本kernel的name。

## 约束说明<a name="zh-cn_topic_0000001592697020_zh-cn_topic_0000001389505457_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001592697020_zh-cn_topic_0000001389505457_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto kernel_name = extend_context->GetKernelName();
```

