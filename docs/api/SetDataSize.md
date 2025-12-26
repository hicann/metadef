# SetDataSize<a name="ZH-CN_TOPIC_0000002042368526"></a>

## 函数功能<a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_section36583473819"></a>

设置tiling data长度。

## 函数原型<a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_section13230182415108"></a>

**void SetDataSize\(const size\_t size\)**

## 参数说明<a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_section75395119104"></a>

<a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p10223674448"><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p10223674448"></a><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p645511218169"><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p645511218169"></a><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p1922337124411"><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p1922337124411"></a><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p389991032711"><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p389991032711"></a><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p389991032711"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p143401361158"><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p143401361158"></a><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p2349471065"><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p2349471065"></a><a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_p2349471065"></a>tiling data长度。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526366806_zh-cn_topic_0000001389733237_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
size_t data_size = td->GetDataSize(); // 0

td->SetDataSize(100U);
data_size = td->GetDataSize(); // 100
```

