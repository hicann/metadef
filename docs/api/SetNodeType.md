# SetNodeType<a name="ZH-CN_TOPIC_0000002078486481"></a>

## 函数功能<a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_section36583473819"></a>

设置算子的类型。

## 函数原型<a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_section13230182415108"></a>

```
void SetNodeType(const ge::char_t *node_type)
```

## 参数说明<a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_section75395119104"></a>

<a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p10223674448"><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p10223674448"></a><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p645511218169"><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p645511218169"></a><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p1922337124411"><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p1922337124411"></a><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p142513248189"><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p142513248189"></a><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p142513248189"></a>node_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p1712865704213"><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p1712865704213"></a><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p1712865704213"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p8770152851817"><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p8770152851817"></a><a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_p8770152851817"></a>算子的类型。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001886896573_zh-cn_topic_0000001390486793_section320753512363"></a>

```
compute_node_info.SetNodeType("Const");
```

