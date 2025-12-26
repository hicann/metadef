# GetOptionalInputShapeRange<a name="ZH-CN_TOPIC_0000002042526850"></a>

## 函数功能<a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的可选输入shape range指针。

## 函数原型<a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_section13230182415108"></a>

```
const Range<Shape> *GetOptionalInputShapeRange(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_section75395119104"></a>

<a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p10223674448"><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p10223674448"></a><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p645511218169"><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p645511218169"></a><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p1922337124411"><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p1922337124411"></a><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p2340183613156"><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p2340183613156"></a><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p143401361158"><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p143401361158"></a><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p17783144418158"><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p17783144418158"></a><a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_p17783144418158"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_section25791320141317"></a>

返回shape range指针，ir\_index非法，或该INPUT没有实例化时，返回空指针。

## 约束说明<a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526526770_zh-cn_topic_0000001528340201_section320753512363"></a>

```
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetOptionalInputShapeRange(0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  output_shape_range->SetMin(const_cast<gert::Shape *>(input_shape_range->GetMin()));
  output_shape_range->SetMax(const_cast<gert::Shape *>(input_shape_range->GetMax()));
  return GRAPH_SUCCESS;
};
```

