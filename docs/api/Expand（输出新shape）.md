# Expand（输出新shape）<a name="ZH-CN_TOPIC_0000002042527114"></a>

## 函数功能<a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_section36583473819"></a>

对shape做补维，并将补维后的结果写入指定的输出shape对象。

## 函数原型<a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_section13230182415108"></a>

```
ge::graphStatus Expand(const Shape &shape, Shape &out_shape) const
```

## 参数说明<a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_section75395119104"></a>

<a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p10223674448"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p10223674448"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="14.719999999999999%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p645511218169"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p645511218169"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="68.06%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p1922337124411"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p1922337124411"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p4304194063810"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p4304194063810"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p4304194063810"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="14.719999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p143401361158"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p143401361158"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="68.06%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p14151132861"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p14151132861"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p14151132861"></a>输入shape，补维前shape。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_row19415175063220"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p34161150173214"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p34161150173214"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p34161150173214"></a>out_shape</p>
</td>
<td class="cellrowborder" valign="top" width="14.719999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p13416135063210"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p13416135063210"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p13416135063210"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="68.06%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p541665003210"><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p541665003210"></a><a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_p541665003210"></a>输出shape，补维后shape。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_section25791320141317"></a>

补维成功返回ge::GRAPH\_SUCCESS；失败则返回ge::GRAPH\_FAILED。

关于ge::graphStatus类型的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585424944_zh-cn_topic_0000001390185665_section320753512363"></a>

```
Shape origin_shape({3, 256, 256}); // 设置原始shape 3x256x256
Shape out_shape;
ExpandDimsType type1("1000");
ExpandDimsType type2("10000");
ExpandDimsType type3("1001");
auto ret = type1.Expand(origin_shape, out_shape); // ret = ge::GRAPH_SUCCESS, out_shape = 1,3,256,256
ret = type2.Expand(origin_shape, out_shape); // ret = ge::GRAPH_FAILED
ret = type3.Expand(origin_shape, out_shape); // ret = ge::GRAPH_SUCCESS, out_shape = 1,3,256,1,256
```

