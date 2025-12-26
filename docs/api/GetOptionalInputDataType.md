# GetOptionalInputDataType<a name="ZH-CN_TOPIC_0000002078447641"></a>

## 函数功能<a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_section36583473819"></a>

根据算子原型定义中的输入索引获取对应可选输入的数据类型。

## 函数原型<a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_section13230182415108"></a>

```
ge::DataType GetOptionalInputDataType(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_section75395119104"></a>

<a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p10223674448"><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p10223674448"></a><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p645511218169"><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p645511218169"></a><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p1922337124411"><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p1922337124411"></a><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576806825_p598419310257"><a name="zh-cn_topic_0000001576806825_p598419310257"></a><a name="zh-cn_topic_0000001576806825_p598419310257"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p320343694214"><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p320343694214"></a><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p17783144418158"><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p17783144418158"></a><a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_p17783144418158"></a>可选输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_section25791320141317"></a>

返回指定输入的数据类型，若输入的ir\_index非法或该输入没有实例化，返回DT\_UNDEFINED。

## 约束说明<a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576806825_zh-cn_topic_0000001339499092_section320753512363"></a>

```
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto data_type = context->GetOptionalInputDataType(1);
  ...
}
```

