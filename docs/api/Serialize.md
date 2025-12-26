# Serialize<a name="ZH-CN_TOPIC_0000002479355361"></a>

## 函数功能<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section36583473819"></a>

将KernelLaunchInfo序列化成数据流。

## 函数原型<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
std::vector<uint8_t> Serialize()
```

## 参数说明<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section25791320141317"></a>

返回序列化后的数据流。

## 约束说明<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // 创建WaitTask
  auto wait_task = KernelLaunchInfo::CreateHcomWaitTask(context);
  wait_task.SetStreamId(attach_stream_id);
  // 序列化
  tasks.insert(tasks.begin() + aicore_index, wait_task.Serialize());
  aicore_index++;
  ...
}
```

