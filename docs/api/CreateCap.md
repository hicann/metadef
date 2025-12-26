# CreateCap<a name="ZH-CN_TOPIC_0000002042526830"></a>

## 函数功能<a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_section36583473819"></a>

根据指定的最大容量创建一个TilingData类实例。

## 函数原型<a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_section13230182415108"></a>

**static std::unique\_ptr<uint8\_t\[\]\> CreateCap\(const size\_t cap\_size\)**

## 参数说明<a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_section75395119104"></a>

<a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p10223674448"><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p10223674448"></a><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p645511218169"><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p645511218169"></a><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p1922337124411"><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p1922337124411"></a><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p2340183613156"><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p2340183613156"></a><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p2340183613156"></a>cap_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p143401361158"><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p143401361158"></a><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p123019197354"><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p123019197354"></a><a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_p123019197354"></a>最大容量，单位为字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_section25791320141317"></a>

TilingData的实例指针。

## 约束说明<a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576606661_zh-cn_topic_0000001390053305_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
```

