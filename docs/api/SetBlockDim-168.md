# SetBlockDim<a name="ZH-CN_TOPIC_0000002479355365"></a>

## 函数功能<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section36583473819"></a>

设置算子BlockDim。

## 函数原型<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section13230182415108"></a>

```
graphStatus SetBlockDim(uint32_t block_dim)
```

## 参数说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section75395119104"></a>

<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"></a>block_dim</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p714514448017"><a name="p714514448017"></a><a name="p714514448017"></a>算子BlockDim。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  aicpu_task.SetBlockDim(4);
  ...
}
```

