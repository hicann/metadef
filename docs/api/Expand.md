# Expand<a name="ZH-CN_TOPIC_0000002454297904"></a>

## 函数功能<a name="zh-cn_topic_0000001576727165_zh-cn_topic_0000001339693316_section36583473819"></a>

该函数用于将TilingData扩展指定的大小。

## 函数原型<a name="zh-cn_topic_0000001576727165_zh-cn_topic_0000001339693316_section13230182415108"></a>

```
void *Expand(size_t size)
```

## 参数说明<a name="zh-cn_topic_0000001576727165_zh-cn_topic_0000001339693316_section75395119104"></a>

<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p10223674448"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p10223674448"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p645511218169"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p645511218169"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1922337124411"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1922337124411"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p2340183613156"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p2340183613156"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p2340183613156"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p143401361158"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p143401361158"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p19544204917121"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p19544204917121"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p19544204917121"></a>需要拓展的大小，单位为字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576727165_zh-cn_topic_0000001339693316_section25791320141317"></a>

返回扩展对应size后TilingData的内存地址。

## 约束说明<a name="zh-cn_topic_0000001576727165_zh-cn_topic_0000001339693316_section19165124931511"></a>

扩展后的总大小不能超过TilingData的最大容量。

## 调用示例<a name="zh-cn_topic_0000001576727165_zh-cn_topic_0000001339693316_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
auto ptr = td->Expand(64U);
size_t cap = td->GetCapacity(); // 64U
```

