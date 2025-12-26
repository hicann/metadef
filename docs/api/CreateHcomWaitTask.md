# CreateHcomWaitTask<a name="ZH-CN_TOPIC_0000002446115338"></a>

## 函数功能<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

创建一个Wait Task，此Task用于阻塞流，当与其有相同group\_name的Record Task被执行时，阻塞会被解除。

## 函数原型<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

```
static KernelLaunchInfo CreateHcomWaitTask(const gert::ExeResGenerationContext *context, const char *group_name = "group")
```

## 参数说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section75395119104"></a>

<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p10223674448"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p10223674448"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p645511218169"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p645511218169"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1922337124411"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1922337124411"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p1538588131411"><a name="p1538588131411"></a><a name="p1538588131411"></a>context</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p143401361158"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p143401361158"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p2684123934216"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p2684123934216"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p2684123934216"></a>GenerateTask函数的入参，保存了算子的基础信息。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_row12431522375"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p580301371420"><a name="p580301371420"></a><a name="p580301371420"></a>group_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p28596925620"><a name="p28596925620"></a><a name="p28596925620"></a>Wait Task的分组名字，默认为group，用于与Record Task配套。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

返回创建出来的Wait Task信息。

## 约束说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section19165124931511"></a>

group\_name必须与算子原型中定义的属性一致。例如，某个mc2算子定义了一个属性group\_ep，则可以使用group\_name为group\_ep创建Record任务和Wait任务。

## 调用示例<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // 创建WaitTask
  auto wait_task = KernelLaunchInfo::CreateHcomWaitTask(context);
  wait_task.SetStreamId(attach_stream_id);
  tasks.insert(tasks.begin() + aicore_index, wait_task.Serialize());
  aicore_index++;
  ...
}
```

