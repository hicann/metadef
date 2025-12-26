# SetExpandDimsType<a name="ZH-CN_TOPIC_0000002078447845"></a>

## 函数功能<a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_section36583473819"></a>

设置补维规则。

## 函数原型<a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_section13230182415108"></a>

```
void SetExpandDimsType(const ExpandDimsType &expand_dims_type)
```

## 参数说明<a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_section75395119104"></a>

<a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p10223674448"><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p10223674448"></a><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p645511218169"><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p645511218169"></a><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p1922337124411"><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p1922337124411"></a><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p7274174218360"><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p7274174218360"></a><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p7274174218360"></a>expand_dims_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p191819441211"><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p191819441211"></a><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p1072034893618"><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p1072034893618"></a><a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_p1072034893618"></a>补维规则。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585105576_zh-cn_topic_0000001390170321_section320753512363"></a>

```
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
ExpandDimsType new_dim_type("1010");
format.SetExpandDimsType(new_dim_type);
```

