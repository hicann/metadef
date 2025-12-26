# Expand（更改原shape）<a name="ZH-CN_TOPIC_0000002042368814"></a>

## 函数功能<a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_section36583473819"></a>

对shape做补维，并将补维后的结果直接更新原shape对象。

## 函数原型<a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_section13230182415108"></a>

```
ge::graphStatus Expand(Shape &shape) const
```

## 参数说明<a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_section75395119104"></a>

<a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p10223674448"><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p10223674448"></a><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p645511218169"><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p645511218169"></a><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p1922337124411"><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p1922337124411"></a><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p865117470342"><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p865117470342"></a><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p865117470342"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p796912238145"><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p796912238145"></a><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p796912238145"></a>既是输入，又是输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p14151132861"><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p14151132861"></a><a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_p14151132861"></a>需要进行补维操作的shape对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_section25791320141317"></a>

补维成功返回ge::GRAPH\_SUCCESS。

关于ge::graphStatus类型的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635185489_zh-cn_topic_0000001390105721_section320753512363"></a>

```
Shape shape({3, 256, 256}); // 设置原始shape 3,256,256
ExpandDimsType type1("1000");
auto ret = type1.Expand(shape); // ret = ge::GRAPH_SUCCESS, shape = 1,3,256,256
```

