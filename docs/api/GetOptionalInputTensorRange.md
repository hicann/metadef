# GetOptionalInputTensorRange<a name="ZH-CN_TOPIC_0000002078486229"></a>

## 函数功能<a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的可选输入tensor range指针。

## 函数原型<a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_section13230182415108"></a>

```
const TensorRange *GetOptionalInputTensorRange(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_section75395119104"></a>

<a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p10223674448"><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p10223674448"></a><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.409999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p645511218169"><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p645511218169"></a><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.36999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p1922337124411"><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p1922337124411"></a><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p2480125055319"><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p2480125055319"></a><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p2480125055319"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p320343694214"><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p320343694214"></a><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.36999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p17783144418158"><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p17783144418158"></a><a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_p17783144418158"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_section25791320141317"></a>

TensorRange类型指针，定义如下：

```
using TensorRange = Range<Tensor>;
```

ir\_index非法，或该INPUT没有实例化时，返回空指针。

## 约束说明<a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_section19165124931511"></a>

如果输入没有被设置为数据依赖，调用此接口获取tensor range时，只能在tensor中获取到正确的shape、format、datatype信息，无法获取到真实的tensor数据地址（获取到的地址为nullptr）。

## 调用示例<a name="zh-cn_topic_0000001651955881_zh-cn_topic_0000001647423137_section320753512363"></a>

```
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetOptionalInputTensorRange(0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  *output_shape_range->GetMin() = input_shape_range->GetMin()->GetStorageShape();
  *output_shape_range->GetMax() = input_shape_range->GetMax()->GetStorageShape();
  return GRAPH_SUCCESS;
};
```

