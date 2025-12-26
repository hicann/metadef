# SetExpandIndex<a name="ZH-CN_TOPIC_0000002078486497"></a>

## 函数功能<a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_section36583473819"></a>

将第index轴设置为补维轴。

## 函数原型<a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_section13230182415108"></a>

```
void SetExpandIndex(const AxisIndex index)
```

## 参数说明<a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_section75395119104"></a>

<a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_row6223476444"><th class="cellrowborder" valign="top" width="19.29%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p10223674448"><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p10223674448"></a><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p645511218169"><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p645511218169"></a><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p1922337124411"><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p1922337124411"></a><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_row152234713443"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p42071411143112"><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p42071411143112"></a><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p42071411143112"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p17145104618372"><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p17145104618372"></a><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p17145104618372"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p192211258192913"><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p192211258192913"></a><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_p192211258192913"></a>第index根轴为补维轴。</p>
<pre class="screen" id="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_screen1486434317378"><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_screen1486434317378"></a><a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_screen1486434317378"></a>using AxisIndex = uint64_t;</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584945796_zh-cn_topic_0000001339585784_section320753512363"></a>

```
ExpandDimsType type1("1001");
type1.SetExpandIndex(1); // 补维规则mask_=1101
```

