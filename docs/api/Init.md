# Init<a name="ZH-CN_TOPIC_0000002042527094"></a>

## 函数功能<a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_section36583473819"></a>

初始化ComputeNodeInfo类。

## 函数原型<a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_section13230182415108"></a>

```
void Init(const size_t ir_inputs_num, const size_t inputs_num, const size_t outputs_num, const ge::char_t *node_name, const ge::char_t *node_type)
void Init(const size_t ir_inputs_num, const size_t ir_outputs_num, const size_t inputs_num, const size_t outputs_num, const size_t attr_size, const ge::char_t *node_name, const ge::char_t *node_type)
```

## 参数说明<a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_section75395119104"></a>

<a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p10223674448"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p10223674448"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p645511218169"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p645511218169"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1922337124411"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1922337124411"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1365516713431"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1365516713431"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1365516713431"></a><strong id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b5316134116481"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b5316134116481"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b5316134116481"></a>ir_inputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001938638972_p134431081949"><a name="zh-cn_topic_0000001938638972_p134431081949"></a><a name="zh-cn_topic_0000001938638972_p134431081949"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001938638972_p94421581344"><a name="zh-cn_topic_0000001938638972_p94421581344"></a><a name="zh-cn_topic_0000001938638972_p94421581344"></a>算子原型输入的个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_row1872833452311"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1172993419233"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1172993419233"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p1172993419233"></a><strong id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b1322616461485"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b1322616461485"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b1322616461485"></a>inputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001938638972_p544248044"><a name="zh-cn_topic_0000001938638972_p544248044"></a><a name="zh-cn_topic_0000001938638972_p544248044"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001938638972_p104411780415"><a name="zh-cn_topic_0000001938638972_p104411780415"></a><a name="zh-cn_topic_0000001938638972_p104411780415"></a>算子实际输入个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_row10270539102320"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p92702039142318"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p92702039142318"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_p92702039142318"></a><strong id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b1111725118481"><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b1111725118481"></a><a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_b1111725118481"></a>outputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001938638972_p144404818411"><a name="zh-cn_topic_0000001938638972_p144404818411"></a><a name="zh-cn_topic_0000001938638972_p144404818411"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001938638972_p15439681944"><a name="zh-cn_topic_0000001938638972_p15439681944"></a><a name="zh-cn_topic_0000001938638972_p15439681944"></a>算子实际输出个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_row11270163942310"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001938638972_p1140432714415"><a name="zh-cn_topic_0000001938638972_p1140432714415"></a><a name="zh-cn_topic_0000001938638972_p1140432714415"></a><strong id="zh-cn_topic_0000001938638972_b640420271948"><a name="zh-cn_topic_0000001938638972_b640420271948"></a><a name="zh-cn_topic_0000001938638972_b640420271948"></a>node_name</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001938638972_p164392814415"><a name="zh-cn_topic_0000001938638972_p164392814415"></a><a name="zh-cn_topic_0000001938638972_p164392814415"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001938638972_p543615810414"><a name="zh-cn_topic_0000001938638972_p543615810414"></a><a name="zh-cn_topic_0000001938638972_p543615810414"></a>节点名称。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001938638972_row1178623118411"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001938638972_p1787831846"><a name="zh-cn_topic_0000001938638972_p1787831846"></a><a name="zh-cn_topic_0000001938638972_p1787831846"></a><strong id="zh-cn_topic_0000001938638972_b070611352048"><a name="zh-cn_topic_0000001938638972_b070611352048"></a><a name="zh-cn_topic_0000001938638972_b070611352048"></a>node_type</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001938638972_p13787153116416"><a name="zh-cn_topic_0000001938638972_p13787153116416"></a><a name="zh-cn_topic_0000001938638972_p13787153116416"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001938638972_p19787431348"><a name="zh-cn_topic_0000001938638972_p19787431348"></a><a name="zh-cn_topic_0000001938638972_p19787431348"></a>节点类型（算子原型名称）。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001938638972_row16188688513"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001938638972_p318928052"><a name="zh-cn_topic_0000001938638972_p318928052"></a><a name="zh-cn_topic_0000001938638972_p318928052"></a><strong id="zh-cn_topic_0000001938638972_b0645203714518"><a name="zh-cn_topic_0000001938638972_b0645203714518"></a><a name="zh-cn_topic_0000001938638972_b0645203714518"></a>ir_outputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001938638972_p7189781757"><a name="zh-cn_topic_0000001938638972_p7189781757"></a><a name="zh-cn_topic_0000001938638972_p7189781757"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001938638972_p164056763017"><a name="zh-cn_topic_0000001938638972_p164056763017"></a><a name="zh-cn_topic_0000001938638972_p164056763017"></a>算子原型输出的个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001938638972_row56891732950"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001938638972_p176899321856"><a name="zh-cn_topic_0000001938638972_p176899321856"></a><a name="zh-cn_topic_0000001938638972_p176899321856"></a><strong id="zh-cn_topic_0000001938638972_b13776113318517"><a name="zh-cn_topic_0000001938638972_b13776113318517"></a><a name="zh-cn_topic_0000001938638972_b13776113318517"></a>attr_size</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001938638972_p11689183218513"><a name="zh-cn_topic_0000001938638972_p11689183218513"></a><a name="zh-cn_topic_0000001938638972_p11689183218513"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001938638972_p7689123219515"><a name="zh-cn_topic_0000001938638972_p7689123219515"></a><a name="zh-cn_topic_0000001938638972_p7689123219515"></a>属性个数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001938638972_zh-cn_topic_0000001390567205_section320753512363"></a>

```
auto ir_input_num = compute_node->GetOpDesc()->GetIrInputs().size();
auto inputs_num = compute_node->GetInDataNodesAndAnchors().size();
auto outputs_num = compute_node->GetOutDataNodesAndAnchors().size();
auto compute_node_info_holder = std::make_unique<uint8_t[]>(total_size);
auto compute_node_info = reinterpret_cast<ComputeNodeInfo *>(compute_node_info_holder.get());
compute_node_info->Init(ir_input_num, inputs_num, outputs_num, node_name, node_type);
```

