# SetAicpuBlockDim<a name="ZH-CN_TOPIC_0000002319609180"></a>

## 函数功能<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section36583473819"></a>

设置可以调度的AI CPU核数。

在使用HCCL高阶API的BatchWrite接口时，可以通过合理设置AI CPU核数获得更好的性能。

## 函数原型<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section13230182415108"></a>

**ge::graphStatus SetAicpuBlockDim\(uint32\_t block\_dim\)**

## 参数说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section75395119104"></a>

<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p10223674448"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p10223674448"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p645511218169"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p645511218169"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p1922337124411"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p1922337124411"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p2340183613156"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p2340183613156"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p2340183613156"></a>block_dim</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p143401361158"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p143401361158"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576727157_p487385410280"><a name="zh-cn_topic_0000001576727157_p487385410280"></a><a name="zh-cn_topic_0000001576727157_p487385410280"></a>可以调度的AI CPU核数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetAicpuBlockDim(5U);
  // ...
}
```

