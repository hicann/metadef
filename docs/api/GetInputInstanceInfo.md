# GetInputInstanceInfo<a name="ZH-CN_TOPIC_0000002042527082"></a>

## 函数功能<a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_section36583473819"></a>

根据算子IR原型中的输入索引，获取对应的实例化对象。

## 函数原型<a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_section13230182415108"></a>

```
const AnchorInstanceInfo *GetInputInstanceInfo(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_section75395119104"></a>

<a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p10223674448"><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p10223674448"></a><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p645511218169"><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p645511218169"></a><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p1922337124411"><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p1922337124411"></a><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p2340183613156"><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p2340183613156"></a><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p143401361158"><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p143401361158"></a><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p1410311123516"><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p1410311123516"></a><a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_p1410311123516"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_section25791320141317"></a>

返回const类型的实例化对象的地址。

## 约束说明<a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001965919037_zh-cn_topic_0000001340206838_section320753512363"></a>

```
for (size_t i = 0; i < ir_inputs.size(); ++i) {
  auto ins_info = compute_node_info.GetInputInstanceInfo(i);
  ...
}
```

