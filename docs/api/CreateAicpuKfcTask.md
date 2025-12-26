# CreateAicpuKfcTask<a name="ZH-CN_TOPIC_0000002445955486"></a>

## 函数功能<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section36583473819"></a>

创建一个AI CPU的KFC Task。

## 函数原型<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section13230182415108"></a>

```
static KernelLaunchInfo CreateAicpuKfcTask(const gert::ExeResGenerationContext *context, const char *so_name, const char *kernel_name)
```

## 参数说明<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section75395119104"></a>

<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p18543242515"><a name="p18543242515"></a><a name="p18543242515"></a>context</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p182416224172"><a name="p182416224172"></a><a name="p182416224172"></a>GenrateTask函数的入参，保存了算子的基础信息。</p>
</td>
</tr>
<tr id="row1106171716259"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p101061617122516"><a name="p101061617122516"></a><a name="p101061617122516"></a>so_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p51061517172514"><a name="p51061517172514"></a><a name="p51061517172514"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p46019157447"><a name="p46019157447"></a><a name="p46019157447"></a>AI CPU算子打包的so名称。</p>
</td>
</tr>
<tr id="row107395194258"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p15739819112516"><a name="p15739819112516"></a><a name="p15739819112516"></a>kernel_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p1473921910251"><a name="p1473921910251"></a><a name="p1473921910251"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p684211245448"><a name="p684211245448"></a><a name="p684211245448"></a>AI CPU算子的入口函数名称。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section25791320141317"></a>

返回创建出的AI CPU KFC Task信息。

## 约束说明<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // 创建AI CPU任务
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  // 获取attach流
  auto stream_infos = context->GetAttachedStreamInfos();
  GE_ASSERT_TRUE(!stream_infos.empty());
  const int64_t attach_stream_id = stream_infos[0].stream_id;
  // 往AI CPU KFC的任务中添加信息
  aicpu_task->SetStreamId(attach_stream_id);
  ...
}
```

