# SetDimNum<a name="ZH-CN_TOPIC_0000002078447809"></a>

## 函数功能<a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_section36583473819"></a>

设置Shape的维度个数。

## 函数原型<a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_section13230182415108"></a>

```
void SetDimNum(const size_t dim_num)
```

## 参数说明<a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_section75395119104"></a>

<a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p10223674448"><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p10223674448"></a><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p645511218169"><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p645511218169"></a><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p1922337124411"><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p1922337124411"></a><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p2340183613156"><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p2340183613156"></a><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p2340183613156"></a>dim_num</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p143401361158"><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p143401361158"></a><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p14151132861"><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p14151132861"></a><a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_p14151132861"></a>将Shape的维度个数设置为dim_num。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634265525_zh-cn_topic_0000001390158093_section320753512363"></a>

```
Shape shape0({3, 256, 256});
shape0.SetDimNum(1);
auto dim_num = shape0.GetDimNum(); // 1
```

