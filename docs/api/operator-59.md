# operator==<a name="ZH-CN_TOPIC_0000002078486417"></a>

## 函数功能<a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_section36583473819"></a>

判断与另外一个range对象是否相等，如果两个range的上下界的地址相同，或者上下界的值相同，这两个对象相等。

## 函数原型<a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_section13230182415108"></a>

```
bool operator==(const Range<T>&rht) const
```

## 参数说明<a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_section75395119104"></a>

<a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p10223674448"><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p10223674448"></a><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p645511218169"><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p645511218169"></a><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p1922337124411"><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p1922337124411"></a><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p51918481213"><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p51918481213"></a><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p51918481213"></a>rht</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p191819441211"><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p191819441211"></a><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p16171244128"><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p16171244128"></a><a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_p16171244128"></a>另一个Range对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_section25791320141317"></a>

true：相等；false：不相等。

## 约束说明<a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001602446690_zh-cn_topic_0000001596844074_section320753512363"></a>

```
int min = 0;
int max = 1024;
int max2 = 1024;
Range<int> range1(&min, &max); // 上界为1024，下界为0
Range<int> range2(&min, &max); // 上界为1024，下界为0
Range<int> range3(&min, &max2); // 上界为1024，下界为0

auto ret1 = range1 == range2; // true
auto ret2 = range1 == range3; // true
```

