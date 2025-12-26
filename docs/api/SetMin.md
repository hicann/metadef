# SetMin<a name="ZH-CN_TOPIC_0000002078447817"></a>

## 函数功能<a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_section36583473819"></a>

设置最小的T对象指针。

## 函数原型<a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_section13230182415108"></a>

```
void SetMin(T *min)
```

## 参数说明<a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_section75395119104"></a>

<a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p10223674448"><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p10223674448"></a><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p645511218169"><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p645511218169"></a><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p1922337124411"><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p1922337124411"></a><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p2340183613156"><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p2340183613156"></a><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p2340183613156"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p143401361158"><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p143401361158"></a><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p12212164717178"><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p12212164717178"></a><a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_p12212164717178"></a>最小的T对象指针。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001602288474_zh-cn_topic_0000001646166113_section320753512363"></a>

```
Range<int> range;
int min = -1;
range.SetMin(&min);
```

