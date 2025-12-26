# SetScheduleMode<a name="ZH-CN_TOPIC_0000002078486197"></a>

## 函数功能<a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_section36583473819"></a>

设置算子在NPU上执行时的调度模式。

## 函数原型<a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_section13230182415108"></a>

**ge::graphStatus SetScheduleMode\(const uint32\_t schedule\_mode\)**

## 参数说明<a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_section75395119104"></a>

<a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p10223674448"><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p10223674448"></a><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.32%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p645511218169"><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p645511218169"></a><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.46%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p1922337124411"><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p1922337124411"></a><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p2340183613156"><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p2340183613156"></a><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p2340183613156"></a><strong id="zh-cn_topic_0000001657550406_b8446184013434"><a name="zh-cn_topic_0000001657550406_b8446184013434"></a><a name="zh-cn_topic_0000001657550406_b8446184013434"></a>schedule_mode</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p15663137127"><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p15663137127"></a><a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_p15663137127"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.46%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001657550406_p98991210497"><a name="zh-cn_topic_0000001657550406_p98991210497"></a><a name="zh-cn_topic_0000001657550406_p98991210497"></a>0：普通模式，默认情况下为普通模式。</p>
<p id="zh-cn_topic_0000001657550406_p1265518111813"><a name="zh-cn_topic_0000001657550406_p1265518111813"></a><a name="zh-cn_topic_0000001657550406_p1265518111813"></a>1：batchmode模式，核间同步算子需要设置该模式。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

设置失败时返回 “ge::GRAPH\_FAILED”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001657550406_zh-cn_topic_0000001339347384_section320753512363"></a>

```
ge::graphStatus TilingForAdd(TilingContext *context) {
  uint32_t batch_mode = 1U;
  auto ret = context->SetScheduleMode(batch_mode);  
  GE_ASSERT_SUCCESS(ret);
  ...
}
```

