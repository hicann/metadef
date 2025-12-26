# GetArgsFormat<a name="ZH-CN_TOPIC_0000002445955494"></a>

## 函数功能<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section36583473819"></a>

获取算子的ArgsFormat。

## 函数原型<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section13230182415108"></a>

```
const char *GetArgsFormat() const
```

## 参数说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section25791320141317"></a>

成功时返回算子的ArgsFormat。

失败时，返回nullptr。

## 约束说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section19165124931511"></a>

只有AI CPU和AI Core类型的任务能获取到ArgsFormat。

## 调用示例<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  auto aicore_args_format_str = aicore_task.GetArgsFormat();
  auto aicore_args_format = ArgsFormatSerializer::Deserialize(aicore_args_format_str);
  ...
}
```

