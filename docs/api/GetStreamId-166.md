# GetStreamId<a name="ZH-CN_TOPIC_0000002445955490"></a>

## 函数功能<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section36583473819"></a>

获取当前Task所在流的id。

## 函数原型<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section13230182415108"></a>

```
uint32_t GetStreamId() const
```

## 参数说明<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section25791320141317"></a>

返回当前Task所在流的id，默认值为0。

异常时，返回int32\_max。

## 约束说明<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  auto stream_id = aicore_task.GetStreamId();
  ...
}
```

