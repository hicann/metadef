# GetSoName<a name="ZH-CN_TOPIC_0000002446115346"></a>

## 函数功能<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section36583473819"></a>

获取AI CPU任务的so名称。

## 函数原型<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section13230182415108"></a>

```
const char *GetSoName() const
```

## 参数说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section25791320141317"></a>

获取成功时返回算子的so名称。

获取失败时，返回nullptr。

## 约束说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section19165124931511"></a>

只有AI Cpu任务可以获取到so名称。

## 调用示例<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  // 获取到libcc_kernel.so
  auto so_name = aicpu_task.GetSoName();
  ...
}
```

