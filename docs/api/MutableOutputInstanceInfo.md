# MutableOutputInstanceInfo<a name="ZH-CN_TOPIC_0000002078486477"></a>

## 函数功能<a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_section36583473819"></a>

根据算子IR原型中的输出索引，获取对应的实例化对象。

## 函数原型<a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_section13230182415108"></a>

```
AnchorInstanceInfo *MutableOutputInstanceInfo(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_section75395119104"></a>

<a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p10223674448"><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p10223674448"></a><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p645511218169"><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p645511218169"></a><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p1922337124411"><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p1922337124411"></a><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p1365516713431"><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p1365516713431"></a><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p1365516713431"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p143401361158"><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p143401361158"></a><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001886896569_zh-cn_topic_0000001340206838_p1410311123516"><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001340206838_p1410311123516"></a><a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001340206838_p1410311123516"></a>算子IR原型定义中的输出索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_section25791320141317"></a>

返回的实例化对象的地址。返回对象为非const。

## 约束说明<a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001886896569_zh-cn_topic_0000001677338137_section320753512363"></a>

```
for (size_t i = 0; i < ir_outputs.size(); ++i) {
  auto ins_info = compute_node_info.MutableOutputInstanceInfo(i);
  ...
}
```

