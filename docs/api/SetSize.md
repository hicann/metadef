# SetSize<a name="ZH-CN_TOPIC_0000002078447781"></a>

## 函数功能<a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_section36583473819"></a>

设置当前保存的元素个数。

## 函数原型<a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_section13230182415108"></a>

```
ge::graphStatus SetSize(const size_t size)
```

## 参数说明<a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_section75395119104"></a>

<a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_row6223476444"><th class="cellrowborder" valign="top" width="19.29%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p10223674448"><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p10223674448"></a><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p645511218169"><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p645511218169"></a><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p1922337124411"><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p1922337124411"></a><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_row152234713443"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p18984952202910"><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p18984952202910"></a><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p18984952202910"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p191819441211"><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p191819441211"></a><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p14460194219718"><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p14460194219718"></a><a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_p14460194219718"></a>当前保存的元素个数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_section25791320141317"></a>

成功时返回ge::GRAPH\_SUCCESS。

设置的size\>capacity时，返回失败ge::GRAPH\_FAILED。

## 约束说明<a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001593014940_zh-cn_topic_0000001390446193_section320753512363"></a>

```
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<ContinuousVector *>(cv_holder.get());
auto ret = cv->SetSize(10U); // ge::GRAPH_SUCCESS
ret = cv->GetSize(101U); // ge::GRAPH_FAILED
```

