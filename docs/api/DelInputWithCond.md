# DelInputWithCond<a name="ZH-CN_TOPIC_0000002079121237"></a>

## 函数功能<a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_section8722525"></a>

根据算子属性，删除算子指定输入边。

## 函数原型<a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_section11393865"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
OpRegistrationData &DelInputWithCond(int32_t inputIdx, const std::string &attrName, bool attrValue)
OpRegistrationData &DelInputWithCond(int32_t input_idx, const char_t *attr_name, bool attr_value)
```

## 参数说明<a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_section35435929"></a>

<a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_table28443956"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_row13063050"><th class="cellrowborder" valign="top" width="26.26262626262626%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p51474147"><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p51474147"></a><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p51474147"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="23.06230623062306%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p8656348"><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p8656348"></a><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p8656348"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="50.67506750675068%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p30075549"><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p30075549"></a><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p30075549"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_row20200399"><td class="cellrowborder" valign="top" width="26.26262626262626%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p25619609"><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p25619609"></a><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p25619609"></a>input_idx/inputIdx</p>
</td>
<td class="cellrowborder" valign="top" width="23.06230623062306%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p61922468"><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p61922468"></a><a name="zh-cn_topic_0000001312390169_zh-cn_topic_0204328201_p61922468"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.67506750675068%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312390169_p92336130154"><a name="zh-cn_topic_0000001312390169_p92336130154"></a><a name="zh-cn_topic_0000001312390169_p92336130154"></a>需要删除的输入边编号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312390169_row11208191242019"><td class="cellrowborder" valign="top" width="26.26262626262626%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312390169_p1920861219204"><a name="zh-cn_topic_0000001312390169_p1920861219204"></a><a name="zh-cn_topic_0000001312390169_p1920861219204"></a>attr_name/attrName</p>
</td>
<td class="cellrowborder" valign="top" width="23.06230623062306%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312390169_p12241125712013"><a name="zh-cn_topic_0000001312390169_p12241125712013"></a><a name="zh-cn_topic_0000001312390169_p12241125712013"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.67506750675068%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312390169_p8208121252012"><a name="zh-cn_topic_0000001312390169_p8208121252012"></a><a name="zh-cn_topic_0000001312390169_p8208121252012"></a>属性名字。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312390169_row61581414202010"><td class="cellrowborder" valign="top" width="26.26262626262626%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312390169_p1015851417205"><a name="zh-cn_topic_0000001312390169_p1015851417205"></a><a name="zh-cn_topic_0000001312390169_p1015851417205"></a>attr_value/attrValue</p>
</td>
<td class="cellrowborder" valign="top" width="23.06230623062306%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312390169_p2247957202018"><a name="zh-cn_topic_0000001312390169_p2247957202018"></a><a name="zh-cn_topic_0000001312390169_p2247957202018"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.67506750675068%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312390169_p2809155315434"><a name="zh-cn_topic_0000001312390169_p2809155315434"></a><a name="zh-cn_topic_0000001312390169_p2809155315434"></a>属性的值。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001312390169_section1386084611573"></a>

无。

