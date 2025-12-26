# SetOutputDataType<a name="ZH-CN_TOPIC_0000002078447645"></a>

## 函数功能<a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_section36583473819"></a>

根据输出索引，设置指定输出的数据类型。

## 函数原型<a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_section13230182415108"></a>

```
ge::graphStatus SetOutputDataType(const size_t index, const ge::DataType datatype)
```

## 参数说明<a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_section75395119104"></a>

<a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p10223674448"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p10223674448"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p645511218169"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p645511218169"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p1922337124411"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p1922337124411"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p2340183613156"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p2340183613156"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p143401361158"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p143401361158"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p123391362158"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p123391362158"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p123391362158"></a>算子IR原型定义中的输出索引，从0开始计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_row4387826153015"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p103871226123011"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p103871226123011"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p103871226123011"></a>datatype</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p12387112614303"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p12387112614303"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p12387112614303"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p12802173615310"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p12802173615310"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p12802173615310"></a>需要设置的输出数据类型。</p>
<p id="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p10387026173011"><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p10387026173011"></a><a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_p10387026173011"></a>关于DataType的说明，请参见<a href="DataType.md">DataType</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_section25791320141317"></a>

返回设置的结果状态，状态说明请参见[ge::graphStatus](ge-graphStatus.md)。

index非法时，返回失败。

## 约束说明<a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576486689_zh-cn_topic_0000001339339192_section320753512363"></a>

```
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto ret = context->SetOutputDataType(0, ge::DataType::DT_FLOAT);
  ...
}
```

