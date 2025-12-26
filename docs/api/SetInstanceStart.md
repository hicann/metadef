# SetInstanceStart<a name="ZH-CN_TOPIC_0000002079616437"></a>

## 函数功能<a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_section36583473819"></a>

设置算子某个IR输入在实际输入中的起始序号（index）。

## 函数原型<a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_section13230182415108"></a>

```
void SetInstanceStart(const uint32_t instance_start)
```

## 参数说明<a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_section75395119104"></a>

<a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p10223674448"><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p10223674448"></a><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p645511218169"><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p645511218169"></a><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p1922337124411"><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p1922337124411"></a><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p368843113347"><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p368843113347"></a><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p368843113347"></a>instance_start</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p143401361158"><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p143401361158"></a><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p107611046171819"><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p107611046171819"></a><a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_p107611046171819"></a>首个实例化Anchor的index。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001593014944_zh-cn_topic_0000001390682489_section320753512363"></a>

```
const auto &ir_inputs = node->GetOpDesc()->GetIrInputs();  // 算子IR原型定义的所有输入
for (size_t i = 0; i < ir_inputs.size(); ++i) {
  auto ins_info = compute_node_info.MutableInputInstanceInfo(i);  // 获取第i个IR输入对应的AnchorInstanceInfo对象
  GE_ASSERT_NOTNULL(ins_info);
  size_t input_index = ir_index_to_instance_index_pair_map[i].first; // 获取统计后的算子IR输入对应的实际输入index
  ins_info->SetInstanceStart(input_index); // 将该信息保存到IR输入对应的AnchorInstanceInfo对象中
}
```

