# CalcSize<a name="ZH-CN_TOPIC_0000002042368794"></a>

## 函数功能<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_section36583473819"></a>

用于计算算子对应的ComputeNodeInfo需要预分配的内存空间大小。

ComputeNodeInfo的内存空间是平铺式的，内存依次存放ComputeNodeInfo自身的数据成员、算子IR原型定义输入个数的Anchor信息、实际输入个数和输出个数的编译阶段的Tensor描述信息以及属性信息。该函数的计算结果不包含属性信息所占的内存空间大小。

## 函数原型<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_section13230182415108"></a>

```
static ge::graphStatus CalcSize(const size_t ir_inputs_num, const size_t inputs_num, const size_t outputs_num, size_t &total_size)
static ge::graphStatus CalcSize(const size_t ir_inputs_num, const size_t ir_outputs_num, const size_t inputs_num, const size_t outputs_num, size_t &total_size)
```

## 参数说明<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_section75395119104"></a>

<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p10223674448"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p10223674448"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p645511218169"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p645511218169"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1922337124411"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1922337124411"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1365516713431"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1365516713431"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1365516713431"></a><strong id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b5316134116481"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b5316134116481"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b5316134116481"></a>ir_inputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p143401361158"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p143401361158"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1410311123516"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1410311123516"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1410311123516"></a>算子IR原型定义的输入个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001586126874_row137532461225"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126874_p47541146202212"><a name="zh-cn_topic_0000001586126874_p47541146202212"></a><a name="zh-cn_topic_0000001586126874_p47541146202212"></a><strong id="zh-cn_topic_0000001586126874_b6202165810221"><a name="zh-cn_topic_0000001586126874_b6202165810221"></a><a name="zh-cn_topic_0000001586126874_b6202165810221"></a>ir_outputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126874_p775417465229"><a name="zh-cn_topic_0000001586126874_p775417465229"></a><a name="zh-cn_topic_0000001586126874_p775417465229"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126874_p127541046172211"><a name="zh-cn_topic_0000001586126874_p127541046172211"></a><a name="zh-cn_topic_0000001586126874_p127541046172211"></a>算子IR原型定义的输出个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row1872833452311"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1172993419233"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1172993419233"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1172993419233"></a><strong id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b1322616461485"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b1322616461485"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b1322616461485"></a>inputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p47290348231"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p47290348231"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p47290348231"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p10729143411234"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p10729143411234"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p10729143411234"></a>算子实际的输入个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row10270539102320"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p92702039142318"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p92702039142318"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p92702039142318"></a><strong id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b1111725118481"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b1111725118481"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b1111725118481"></a>outputs_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p112706397233"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p112706397233"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p112706397233"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1027023910237"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1027023910237"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1027023910237"></a>算子实际的输出个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row11270163942310"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1927115393238"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1927115393238"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1927115393238"></a><strong id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b8417135817487"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b8417135817487"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_b8417135817487"></a>total_size</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p3271143942314"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p3271143942314"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p3271143942314"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1327110392239"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1327110392239"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1327110392239"></a>需要预分配的ComputeNodeInfo和相关信息的内存总大小，不包含RuntimeAttrs的内存大小。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_section25791320141317"></a>

返回值为graphStatus类型（uint32\_t），其不同的状态取值说明如下：

<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_table18159174418020"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row3160044802"><th class="cellrowborder" valign="top" width="30.243024302430243%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p616015441700"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p616015441700"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p616015441700"></a>状态</p>
</th>
<th class="cellrowborder" valign="top" width="11.701170117011701%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p101601844601"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p101601844601"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p101601844601"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="58.055805580558065%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1316016441704"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1316016441704"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p1316016441704"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row15160744305"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p12160134415015"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p12160134415015"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p12160134415015"></a>ge::GRAPH_SUCCESS</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p716004414012"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p716004414012"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p716004414012"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p61602441509"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p61602441509"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p61602441509"></a>执行成功。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_row13160444801"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p31607448017"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p31607448017"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p31607448017"></a>ge::GRAPH_PARAM_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p9160134413017"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p9160134413017"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p9160134413017"></a>50331649</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p18817619259"><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p18817619259"></a><a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_p18817619259"></a>执行失败，参数无效，校验未通过。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586126874_zh-cn_topic_0000001390567205_section320753512363"></a>

```
auto ir_input_num = node->GetOpDesc()->GetIrInputs().size();
auto input_num = node->GetInDataNodesAndAnchors().size();
auto output_num = node->GetAllOutDataAnchorsSize();
GE_ASSERT_SUCCESS(ComputeNodeInfo::CalcSize(ir_input_num, input_num, output_num, total_size));
```

