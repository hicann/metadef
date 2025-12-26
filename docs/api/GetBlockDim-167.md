# GetBlockDim<a name="ZH-CN_TOPIC_0000002446115342"></a>

## 函数功能<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section36583473819"></a>

获取算子BlockDim。

## 函数原型<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
uint32_t GetBlockDim() const
```

## 参数说明<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section25791320141317"></a>

返回此算子Task的BlockDim值，默认值为0。

异常时返回int32\_max。

## 约束说明<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  auto block_dim = aicore_task.GetBlockDim();
  ...
}
```

