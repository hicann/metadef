# operator!=<a name="ZH-CN_TOPIC_0000002078486401"></a>

## 函数功能<a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_section36583473819"></a>

判断与另一个Shape对象是否不等。

## 函数原型<a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_section13230182415108"></a>

```
bool operator!=(const Shape &rht) const
```

## 参数说明<a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_section75395119104"></a>

<a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p10223674448"><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p10223674448"></a><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p645511218169"><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p645511218169"></a><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p1922337124411"><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p1922337124411"></a><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p51918481213"><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p51918481213"></a><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p51918481213"></a>rht</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p191819441211"><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p191819441211"></a><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p16171244128"><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p16171244128"></a><a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_p16171244128"></a>另一个Shape对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_section25791320141317"></a>

true：不相等；false：相等。

## 约束说明<a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584025018_zh-cn_topic_0000001339398282_section320753512363"></a>

```
Shape shape0({3, 256, 256});
Shape shape1({1, 3, 256, 256});
auto is_diff_shape = shape0 != shape1; // 返回值为true，不相等
```

