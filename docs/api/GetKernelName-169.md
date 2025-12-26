# GetKernelName<a name="ZH-CN_TOPIC_0000002479355369"></a>

## 函数功能<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section36583473819"></a>

获取AI CPU任务的Kernel入口函数名字。

## 函数原型<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section13230182415108"></a>

```
const char *GetKernelName() const
```

## 参数说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section25791320141317"></a>

获取成功时返回算子的Kernel入口函数名字。

获取失败时，返回nullptr。

## 约束说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section19165124931511"></a>

只有AI Cpu任务可以获取到Kernel入口函数名字。

## 调用示例<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  // 获取到RunAicpuKfcSrvLaunch
  auto so_name = aicpu_task.GetKernelName();
  ...
}
```

