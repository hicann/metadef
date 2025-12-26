# GetComputeNodeOutputNum<a name="ZH-CN_TOPIC_0000002042368626"></a>

## 函数功能<a name="zh-cn_topic_0000001652210725_zh-cn_topic_0000001602764414_section36583473819"></a>

获取算子的输出个数。

## 函数原型<a name="zh-cn_topic_0000001652210725_zh-cn_topic_0000001602764414_section13230182415108"></a>

```
size_t GetComputeNodeOutputNum() const
```

## 参数说明<a name="zh-cn_topic_0000001652210725_zh-cn_topic_0000001602764414_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001652210725_zh-cn_topic_0000001602764414_section25791320141317"></a>

算子的输出个数。

## 约束说明<a name="zh-cn_topic_0000001652210725_zh-cn_topic_0000001602764414_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001652210725_zh-cn_topic_0000001602764414_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeOutputNum(); ++idx) {
  auto input_td = extend_context->GetOutputDesc(idx);
  ...
}
```

