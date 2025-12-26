# SetStreamId<a name="ZH-CN_TOPIC_0000002479435141"></a>

## 函数功能<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section36583473819"></a>

设置Task的流id。

## 函数原型<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
void SetStreamId(uint32_t stream_id)
```

## 参数说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section75395119104"></a>

<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p10223674448"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p10223674448"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p645511218169"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p645511218169"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1922337124411"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1922337124411"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p205163302573"><a name="p205163302573"></a><a name="p205163302573"></a>stream_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p88767238815"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p88767238815"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p88767238815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p131917964515"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p131917964515"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p131917964515"></a>流id。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section25791320141317"></a>

无

## 约束说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto wait_task = KernelLaunchInfo::CreateHcomWaitTask(context);
  wait_task.SetStreamId(attach_stream_id);
  ...
}
```

