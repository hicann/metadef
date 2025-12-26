# GetOutputShapeRange<a name="ZH-CN_TOPIC_0000002042526854"></a>

## 函数功能<a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_section36583473819"></a>

根据算子输出索引获取对应的输出shape range指针。这里的输出索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_section13230182415108"></a>

```
Range<Shape> *GetOutputShapeRange(const size_t index)
```

## 参数说明<a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_section75395119104"></a>

<a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p10223674448"><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p10223674448"></a><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p645511218169"><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p645511218169"></a><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="66.77%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p1922337124411"><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p1922337124411"></a><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p2340183613156"><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p2340183613156"></a><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p143401361158"><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p143401361158"></a><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p123391362158"><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p123391362158"></a><a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_p123391362158"></a>算子输出索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_section25791320141317"></a>

输出shape range指针，index非法时，返回空指针。

## 约束说明<a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576606641_zh-cn_topic_0000001528699733_section320753512363"></a>

```
ge::graphStatus InferShapeRangeForXXX(gert::InferShapeRangeContext *context) {
  const auto x_shape_range = context->GetInputShapeRange(0);
  if (x_shape_range == nullptr) {
    // 防御式编程 ....
  }
  const auto min_shape = x_shape_range->GetMin();
  const auto max_shape = x_shape_range->GetMax();

  auto y_shape_range = context->GetOutputShapeRange(0);
  if (y_shape_range == nullptr) {
    // 防御式编程 ....
  }
  if (y_shape_range->GetMin() == nullptr || y_shape_range->GetMax() == nullptr) {
    // 防御式编程 ....
  }
  // shape range推导逻辑 .....
}
```

