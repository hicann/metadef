# GetDynamicInputTensorRange<a name="ZH-CN_TOPIC_0000002078447633"></a>

## 函数功能<a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入tensor range指针。

## 函数原型<a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_section13230182415108"></a>

```
const TensorRange *GetDynamicInputTensorRange(const size_t ir_index, const size_t relative_index) const
```

## 参数说明<a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_section75395119104"></a>

<a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p10223674448"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p10223674448"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.409999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p645511218169"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p645511218169"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.36999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p1922337124411"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p1922337124411"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p1169694155618"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p1169694155618"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p1169694155618"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p320343694214"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p320343694214"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.36999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p17783144418158"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p17783144418158"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p17783144418158"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_row1518516493561"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p19185154915611"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p19185154915611"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p19185154915611"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.409999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p7185124955616"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p7185124955616"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p7185124955616"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.36999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p19185104915561"><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p19185104915561"></a><a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_p19185104915561"></a>该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的有效范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_section25791320141317"></a>

TensorRange类型指针，定义如下：

```
using TensorRange = Range<Tensor>;
```

ir\_index或relative\_index非法时，返回空指针。

## 约束说明<a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_section19165124931511"></a>

如果输入没有被设置为数据依赖，调用此接口获取tensor range时，只能在tensor中获取到正确的shape、format、datatype信息，无法获取到真实的tensor数据地址（获取到的地址为nullptr）。

## 调用示例<a name="zh-cn_topic_0000001652194685_zh-cn_topic_0000001647821269_section320753512363"></a>

```
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetDynamicInputTensorRange(0U, 0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  *output_shape_range-->GetMin() = input_shape_range->GetMin()->GetStorageShape();
  *output_shape_range-->GetMax() = input_shape_range->GetMax()->GetStorageShape();
  return GRAPH_SUCCESS;
};
```

