# GetDynamicInputShapeRange<a name="ZH-CN_TOPIC_0000002042368550"></a>

## 函数功能<a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入shape range指针。

## 函数原型<a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_section13230182415108"></a>

```
const Range<Shape> *GetDynamicInputShapeRange(const size_t ir_index, const size_t relative_index) const
```

## 参数说明<a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_section75395119104"></a>

<a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_row6223476444"><th class="cellrowborder" valign="top" width="18.38%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p10223674448"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p10223674448"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p645511218169"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p645511218169"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.77%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p1922337124411"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p1922337124411"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_row152234713443"><td class="cellrowborder" valign="top" width="18.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p2340183613156"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p2340183613156"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p143401361158"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p143401361158"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p131917964515"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p131917964515"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p131917964515"></a>动态输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_row188425379530"><td class="cellrowborder" valign="top" width="18.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p13842113775313"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p13842113775313"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p13842113775313"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p08426376538"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p08426376538"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p08426376538"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p201910915458"><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p201910915458"></a><a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_p201910915458"></a>该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的取值范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_section25791320141317"></a>

shape range指针，ir\_index或relative\_index非法时，返回空指针。

## 约束说明<a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576486685_zh-cn_topic_0000001477460346_section320753512363"></a>

```
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetDynamicInputShapeRange(0U, 0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  output_shape_range->SetMin(const_cast<gert::Shape *>(input_shape_range->GetMin()));
  output_shape_range->SetMax(const_cast<gert::Shape *>(input_shape_range->GetMax()));
  return GRAPH_SUCCESS;
};
```

