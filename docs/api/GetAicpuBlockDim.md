# GetAicpuBlockDim<a name="ZH-CN_TOPIC_0000002319768980"></a>

## 函数功能<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section36583473819"></a>

获取用户设置的可以调度的AI CPU核数。设置方式请参考[SetAicpuBlockDim](SetAicpuBlockDim.md)。

## 函数原型<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section13230182415108"></a>

**uint32\_t GetAicpuBlockDim\(\) const**

## 参数说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section25791320141317"></a>

用户设置的可以调度的AI CPU核数。

## 约束说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetAicpuBlockDim();
  // ...
}
```

