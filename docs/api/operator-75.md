# operator!=<a name="ZH-CN_TOPIC_0000002078486449"></a>

## 函数功能<a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_section36583473819"></a>

判断格式是否不相同。

## 函数原型<a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_section13230182415108"></a>

```
bool operator!=(const StorageFormat &other) const
```

## 参数说明<a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_section75395119104"></a>

<a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p10223674448"><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p10223674448"></a><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p645511218169"><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p645511218169"></a><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p1922337124411"><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p1922337124411"></a><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p4304194063810"><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p4304194063810"></a><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p4304194063810"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p143401361158"><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p143401361158"></a><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p14151132861"><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p14151132861"></a><a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_p14151132861"></a>另一种格式。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_section25791320141317"></a>

true代表格式不相同，false代表格式相同。

## 约束说明<a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585264984_zh-cn_topic_0000001339730430_section320753512363"></a>

```
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
StorageFormat another_format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_NC, dim_type);
bool is_diff_fmt = format != another_format; // true
```

