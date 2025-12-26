# SetDim<a name="ZH-CN_TOPIC_0000002042368730"></a>

## 函数功能<a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_section36583473819"></a>

设置某一个轴的维度值。

## 函数原型<a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_section13230182415108"></a>

```
void SetDim(size_t idx, const int64_t dim_value)
```

## 参数说明<a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_section75395119104"></a>

<a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p10223674448"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p10223674448"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p645511218169"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p645511218169"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1922337124411"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1922337124411"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p11582728191"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p11582728191"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p11582728191"></a>idx</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1210652116402"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1210652116402"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1210652116402"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p19455739131310"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p19455739131310"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p19455739131310"></a>dim的index，调用者需要保证index合法。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_row189225428135"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p19923194215136"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p19923194215136"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p19923194215136"></a>dim_value</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p169231042131314"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p169231042131314"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p169231042131314"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1923144220135"><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1923144220135"></a><a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_p1923144220135"></a>对idx轴设置的维度值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_section19165124931511"></a>

调用者需要保证index合法。

## 调用示例<a name="zh-cn_topic_0000001584184966_zh-cn_topic_0000001339718182_section320753512363"></a>

```
Shape shape0({3, 256, 256});
shape0.SetDim(0U, 1); // 1,256,256
```

