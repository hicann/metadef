# GetExtendInfo<a name="ZH-CN_TOPIC_0000002042526938"></a>

## 函数功能<a name="zh-cn_topic_0000001642455769_zh-cn_topic_0000001338625948_section36583473819"></a>

获取本kernel的扩展信息。

## 函数原型<a name="zh-cn_topic_0000001642455769_zh-cn_topic_0000001338625948_section13230182415108"></a>

```
const KernelExtendInfo *GetExtendInfo() const
```

## 参数说明<a name="zh-cn_topic_0000001642455769_zh-cn_topic_0000001338625948_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001642455769_zh-cn_topic_0000001338625948_section25791320141317"></a>

本kernel的扩展信息。

关于KernelExtendInfo类型的定义，请参见[内部关联接口](内部关联接口.md)KernelExtendInfo类。

## 约束说明<a name="zh-cn_topic_0000001642455769_zh-cn_topic_0000001338625948_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642455769_zh-cn_topic_0000001338625948_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto extend_info = extend_context->GetExtendInfo();
```

