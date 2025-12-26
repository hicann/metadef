# operator\[\]<a name="ZH-CN_TOPIC_0000002078447805"></a>

## 函数功能<a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_section36583473819"></a>

获取指定index轴的dim值。

## 函数原型<a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_section13230182415108"></a>

```
const int64_t &operator[](const size_t idx) const
int64_t &operator[](const size_t idx)
```

## 参数说明<a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_section75395119104"></a>

<a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p10223674448"><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p10223674448"></a><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p645511218169"><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p645511218169"></a><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p1922337124411"><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p1922337124411"></a><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p51918481213"><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p51918481213"></a><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p51918481213"></a>idx</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p191819441211"><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p191819441211"></a><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p16171244128"><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p16171244128"></a><a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_p16171244128"></a>dim的index，调用者需要保证index合法。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_section25791320141317"></a>

-   const int64\_t &operator\[\]\(const size\_t idx\) const：dim值，在idx\>=kMaxDimNum时，行为未定义。
-   int64\_t &operator\[\]\(const size\_t idx\)：dim值，在idx\>=kMaxDimNum时，行为未定义。

## 约束说明<a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_section19165124931511"></a>

调用者需要保证index合法，即idx<kMaxDimNum。

## 调用示例<a name="zh-cn_topic_0000001633985569_zh-cn_topic_0000001339560910_section320753512363"></a>

```
Shape shape0({3, 256, 256});
auto dim0 = shape0[0]; // 3
auto dim5 = shape0[5]; // 0
auto invalid_dim = shape0[kMaxDimNum]; // 行为未定义
```

