# CalcTotalSize<a name="ZH-CN_TOPIC_0000002042368530"></a>

## 函数功能<a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_section36583473819"></a>

通过最大容量计算TilingData实例所占用的内存空间。

## 函数原型<a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_section13230182415108"></a>

**static ge::graphStatus CalcTotalSize\(const size\_t cap\_size, size\_t &total\_size\)**

## 参数说明<a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_section75395119104"></a>

<a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p10223674448"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p10223674448"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p645511218169"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p645511218169"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1922337124411"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1922337124411"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p2340183613156"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p2340183613156"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p2340183613156"></a>cap_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p143401361158"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p143401361158"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p123019197354"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p123019197354"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p123019197354"></a>最大容量，单位为字节。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_row121695494363"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p4169114913610"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p4169114913610"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p4169114913610"></a>total_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1416994913365"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1416994913365"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1416994913365"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1416994923613"><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1416994923613"></a><a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_p1416994923613"></a>内存空间，单位为字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_section25791320141317"></a>

-   成功返回：ge::GRAPH\_SUCCESS。
-   失败返回：ge::GRAPH\_FAILED。

## 约束说明<a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526206890_zh-cn_topic_0000001339533324_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
size_t total_size = 0U;
auto ret = td->CalcTotalSize(td.GetCapacity, total_size); // total_size = 100 + sizeof(TilingData)
```

