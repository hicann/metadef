# GetInputShapeRange<a name="ZH-CN_TOPIC_0000002042526846"></a>

## 函数功能<a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_section36583473819"></a>

根据算子输入索引获取对应的输入shape range指针。这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_section13230182415108"></a>

```
const Range<Shape> *GetInputShapeRange(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_section75395119104"></a>

<a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p10223674448"><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p10223674448"></a><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p645511218169"><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p645511218169"></a><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p1922337124411"><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p1922337124411"></a><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p2340183613156"><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p2340183613156"></a><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p320343694214"><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p320343694214"></a><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p2684123934216"><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p2684123934216"></a><a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_p2684123934216"></a>算子输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_section25791320141317"></a>

输入shape range指针，index非法时，返回空指针。

## 约束说明<a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576806817_zh-cn_topic_0000001477779958_section320753512363"></a>

```
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetInputShapeRange(0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  output_shape_range->SetMin(const_cast<gert::Shape *>(input_shape_range->GetMin()));
  output_shape_range->SetMax(const_cast<gert::Shape *>(input_shape_range->GetMax()));
  return GRAPH_SUCCESS;
};
```

