# SetInstantiationNum<a name="ZH-CN_TOPIC_0000002043535718"></a>

## 函数功能<a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_section36583473819"></a>

设置IR原型定义某个输入对应的实际输入个数。

## 函数原型<a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_section13230182415108"></a>

```
void SetInstantiationNum(const uint32_t instantiation_num)
```

## 参数说明<a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_section75395119104"></a>

<a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p10223674448"><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p10223674448"></a><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p645511218169"><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p645511218169"></a><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p1922337124411"><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p1922337124411"></a><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p2340183613156"><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p2340183613156"></a><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p2340183613156"></a>instantiation_num</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p143401361158"><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p143401361158"></a><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p1410311123516"><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p1410311123516"></a><a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_p1410311123516"></a>实例化的个数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642694573_zh-cn_topic_0000001390482549_section320753512363"></a>

```
const auto &ir_inputs = node->GetOpDesc()->GetIrInputs();  // 算子IR原型定义的所有输入
for (size_t i = 0; i < ir_inputs.size(); ++i) {
  auto ins_info = compute_node_info.MutableInputInstanceInfo(i);  // 获取第i个IR输入对应的AnchorInstanceInfo对象
  GE_ASSERT_NOTNULL(ins_info);
  size_t instance_num = ir_index_to_instance_index_pair_map[i].second; // 获取统计后的算子IR输入对应的实际输入个数
  ins_info->SetInstantiationNum(instance_num); // 将该信息保存到IR输入对应的AnchorInstanceInfo对象中
}
```

