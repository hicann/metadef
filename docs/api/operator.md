# operator==<a name="ZH-CN_TOPIC_0000002042527106"></a>

## 函数功能<a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_section36583473819"></a>

判断本补维规则对象与另一个对象是否一致。

## 函数原型<a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_section13230182415108"></a>

```
bool operator==(const ExpandDimsType &other) const
```

## 参数说明<a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_section75395119104"></a>

<a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_row6223476444"><th class="cellrowborder" valign="top" width="19.29%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p10223674448"><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p10223674448"></a><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p645511218169"><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p645511218169"></a><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p1922337124411"><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p1922337124411"></a><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_row152234713443"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p18984952202910"><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p18984952202910"></a><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p18984952202910"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p191819441211"><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p191819441211"></a><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p176237456288"><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p176237456288"></a><a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_p176237456288"></a>另一个补维规则对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_section25791320141317"></a>

true表示一致，false表示不一致。

## 约束说明<a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585105580_zh-cn_topic_0000001390265785_section320753512363"></a>

```
ExpandDimsType type1("1001");
ExpandDimsType type2("1001");
bool is_same_type = type1 == type2; // true
```

