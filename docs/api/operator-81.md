# operator==<a name="ZH-CN_TOPIC_0000002486260718"></a>

## 函数功能<a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_section36583473819"></a>

判断与另外一个Stride对象是否相等，如果两个Stride的维度数量相等，并且内每个维度的步长的值都相等，则认为两个Stride对象相等。

## 函数原型<a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_section13230182415108"></a>

```
bool operator==(const Stride &rht) const
```

## 参数说明<a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_section75395119104"></a>

<a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p10223674448"><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p10223674448"></a><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p645511218169"><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p645511218169"></a><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p1922337124411"><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p1922337124411"></a><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p51918481213"><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p51918481213"></a><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p51918481213"></a>rht</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p191819441211"><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p191819441211"></a><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p16171244128"><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p16171244128"></a><a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_p16171244128"></a>另一个Stride对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_section25791320141317"></a>

true：相等；false：不相等。

## 约束说明<a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584184962_zh-cn_topic_0000001339558194_section320753512363"></a>

```
Stride stride0({3, 256, 256});
Stride stride1({1, 3, 256, 256});
auto is_same_shape = stride0 == stride1; // 返回值为false，不相等
```

