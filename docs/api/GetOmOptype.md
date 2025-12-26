# GetOmOptype<a name="ZH-CN_TOPIC_0000002043200504"></a>

## 函数功能<a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328255_section37097208"></a>

获取模型的算子类型。

## 函数原型<a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328255_section65439422"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
std::string GetOmOptype () const
Status GetOmOptype(ge::AscendString &om_op_type) const
```

## 参数说明<a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328255_section1887443012563"></a>

<a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_table28443956"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_row13063050"><th class="cellrowborder" valign="top" width="26.02260226022602%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p51474147"><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p51474147"></a><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p51474147"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="23.18231823182318%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p8656348"><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p8656348"></a><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p8656348"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="50.79507950795079%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p30075549"><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p30075549"></a><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p30075549"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_row20200399"><td class="cellrowborder" valign="top" width="26.02260226022602%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001264911330_p2488454254"><a name="zh-cn_topic_0000001264911330_p2488454254"></a><a name="zh-cn_topic_0000001264911330_p2488454254"></a><strong id="zh-cn_topic_0000001264911330_b7488105102519"><a name="zh-cn_topic_0000001264911330_b7488105102519"></a><a name="zh-cn_topic_0000001264911330_b7488105102519"></a>om_op_type</strong></p>
</td>
<td class="cellrowborder" valign="top" width="23.18231823182318%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p61922468"><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p61922468"></a><a name="zh-cn_topic_0000001264911330_zh-cn_topic_0204328201_p61922468"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="50.79507950795079%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001264911330_p92336130154"><a name="zh-cn_topic_0000001264911330_p92336130154"></a><a name="zh-cn_topic_0000001264911330_p92336130154"></a>模型的算子类型。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001264911330_section366717016305"></a>

无。

