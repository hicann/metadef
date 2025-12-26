# SetMax<a name="ZH-CN_TOPIC_0000002042527042"></a>

## 函数功能<a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_section36583473819"></a>

设置最大的T对象指针。

## 函数原型<a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_section13230182415108"></a>

```
void SetMax(T *max)
```

## 参数说明<a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_section75395119104"></a>

<a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p10223674448"><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p10223674448"></a><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p645511218169"><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p645511218169"></a><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1922337124411"><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1922337124411"></a><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p11582728191"><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p11582728191"></a><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p11582728191"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1210652116402"><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1210652116402"></a><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1210652116402"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1291152082516"><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1291152082516"></a><a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_p1291152082516"></a>最大的T对象指针。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001651848369_zh-cn_topic_0000001596844078_section320753512363"></a>

```
Range<int> range;
int max = 1024;
range.SetMax(&max);
```

