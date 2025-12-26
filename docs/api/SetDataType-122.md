# SetDataType<a name="ZH-CN_TOPIC_0000002518460605"></a>

## 函数功能<a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_section36583473819"></a>

设置Tensor的数据类型。

## 函数原型<a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_section13230182415108"></a>

```
void SetDataType(const ge::DataType data_type)
```

## 参数说明<a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_section75395119104"></a>

<a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p10223674448"><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p10223674448"></a><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p645511218169"><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p645511218169"></a><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p1922337124411"><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p1922337124411"></a><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p11582728191"><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p11582728191"></a><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p11582728191"></a>data_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p1210652116402"><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p1210652116402"></a><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p1210652116402"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p13106202194014"><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p13106202194014"></a><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p13106202194014"></a>需要设置的Tensor的数据类型。</p>
<p id="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p11642024182518"><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p11642024182518"></a><a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_p11642024182518"></a>关于ge::DataType的定义，请参见<a href="DataType.md">DataType</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001633985557_zh-cn_topic_0000001339551774_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetDataType(ge::DT_DOUBLE);
```

