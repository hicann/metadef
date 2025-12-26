# GetDynamicInputDataType<a name="ZH-CN_TOPIC_0000002042526858"></a>

## 函数功能<a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_section36583473819"></a>

根据算子原型定义中的输入索引获取对应动态输入的数据类型。

## 函数原型<a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_section13230182415108"></a>

```
ge::DataType GetDynamicInputDataType(const size_t ir_index, const size_t relative_index) const
```

## 参数说明<a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_section75395119104"></a>

<a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p10223674448"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p10223674448"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p645511218169"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p645511218169"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p1922337124411"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p1922337124411"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526366790_p1995741214269"><a name="zh-cn_topic_0000001526366790_p1995741214269"></a><a name="zh-cn_topic_0000001526366790_p1995741214269"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p143401361158"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p143401361158"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p839813425319"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p839813425319"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p839813425319"></a>动态输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_row10847172717282"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p1584762732820"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p1584762732820"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p1584762732820"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p15847227182812"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p15847227182812"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p15847227182812"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p984714277289"><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p984714277289"></a><a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_p984714277289"></a>该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的取值范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_section25791320141317"></a>

返回指定输入的数据类型，若输入的ir\_index或者relative\_index非法，返回DT\_UNDEFINED。

## 约束说明<a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526366790_zh-cn_topic_0000001339179524_section320753512363"></a>

```
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto data_type = context->GetDynamicInputDataType(1, 2);
  ...
}
```

