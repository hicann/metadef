# GetAttrPointer<a name="ZH-CN_TOPIC_0000002078447761"></a>

## 函数功能<a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_section36583473819"></a>

获取指定索引的算子属性，返回指向此属性的指针。

## 函数原型<a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_section13230182415108"></a>

```
template<typename T>  const T *GetAttrPointer(size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_section75395119104"></a>

<a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p10223674448"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p10223674448"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.32%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p645511218169"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p645511218169"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.46%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p1922337124411"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p1922337124411"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p51918481213"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p51918481213"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p51918481213"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="15.32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p193313781810"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p193313781810"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p193313781810"></a>指定的输出类型</p>
</td>
<td class="cellrowborder" valign="top" width="67.46%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p189651246153917"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p189651246153917"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p189651246153917"></a>属性类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_row125412192439"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p181654101217"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p181654101217"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p181654101217"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p18157411216"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p18157411216"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p18157411216"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.46%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p8146419129"><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p8146419129"></a><a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_p8146419129"></a>属性在IR原型定义中的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_section25791320141317"></a>

指向属性的指针。

## 约束说明<a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001640332721_zh-cn_topic_0000001390180365_section320753512363"></a>

```
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const gert::ContinuousVector attr0 = runtime_attrs->GetAttrPointer<gert::ContinuousVector>(0);
```

