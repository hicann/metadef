# SetArgsFormat<a name="ZH-CN_TOPIC_0000002479435145"></a>

## 函数功能<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section36583473819"></a>

设置算子的ArgsFormat。

## 函数原型<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section13230182415108"></a>

```
graphStatus SetArgsFormat(const char *args_format)
```

## 参数说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section75395119104"></a>

<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"></a>args_format</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p55238413113"><a name="p55238413113"></a><a name="p55238413113"></a>算子的ArgsFormat。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section19165124931511"></a>

只有AI CPU和AI Core类型的任务需要设置ArgsFormat。

## 调用示例<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section320753512363"></a>

```
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  auto aicore_args_format_str = aicore_task.GetArgsFormat();
  auto aicore_args_format = ArgsFormatSerializer::Deserialize(aicore_args_format_str);
  size_t i = 0UL;
  for (; i < aicore_args_format.size(); i++) {
    if (aicore_args_format[i].GetType() == ArgDescType::kIrInput ||
        aicore_args_format[i].GetType() == ArgDescType::kInputInstance) {
      break;
    }
  }
  // 插入HiddenInput
  aicore_args_format.insert(aicore_args_format.begin() + i, ArgDescInfo::CreateHiddenInput(HiddenInputSubType::kHcom));
  aicore_task.SetArgsFormat(ArgsFormatSerializer::Serialize(aicore_args_format).GetString());
  ...
}
```

