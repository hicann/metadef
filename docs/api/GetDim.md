# GetDim<a name="ZH-CN_TOPIC_0000002042527034"></a>

## 函数功能<a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_section36583473819"></a>

获取对应idx轴的dim值。

## 函数原型<a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_section13230182415108"></a>

```
int64_t GetDim(const size_t idx) const
```

## 参数说明<a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_section75395119104"></a>

<a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p10223674448"><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p10223674448"></a><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p645511218169"><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p645511218169"></a><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p1922337124411"><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p1922337124411"></a><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p2340183613156"><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p2340183613156"></a><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p2340183613156"></a>idx</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p143401361158"><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p143401361158"></a><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p14151132861"><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p14151132861"></a><a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_p14151132861"></a>dim的index，调用者需要保证index合法。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_section25791320141317"></a>

dim值，在idx\>=kMaxDimNum时，返回\`kInvalidDimValue\`。

## 约束说明<a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_section19165124931511"></a>

调用者需要保证index合法，即idx<kMaxDimNum。

## 调用示例<a name="zh-cn_topic_0000001634064985_zh-cn_topic_0000001339238634_section320753512363"></a>

```
Shape shape0({3, 256, 256});
auto dim0 = shape0.GetDim(0); // 3
auto invalid_dim = shape0.GetDim(kMaxDimNum); // kInvalidDimValue
```

