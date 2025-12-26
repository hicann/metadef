# GetListListInt<a name="ZH-CN_TOPIC_0000002078486365"></a>

## 函数功能<a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_section36583473819"></a>

获取ContinuousVectorVector \*类型的属性值，即二维数组且每个元素类型为int。

## 函数原型<a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_section13230182415108"></a>

```
const ContinuousVectorVector *GetListListInt(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_section75395119104"></a>

<a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p10223674448"><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p10223674448"></a><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p645511218169"><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p645511218169"></a><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p1922337124411"><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p1922337124411"></a><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p51918481213"><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p51918481213"></a><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p51918481213"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p191819441211"><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p191819441211"></a><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p16171244128"><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p16171244128"></a><a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_p16171244128"></a>属性在IR原型定义中的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_section25791320141317"></a>

指向属性值的指针。

关于ContinuousVectorVector类型的定义，请参见[ContinuousVectorVector](ContinuousVectorVector.md)。

## 约束说明<a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001651967081_zh-cn_topic_0000001647131705_section320753512363"></a>

```
// 假设某算子的IR原型定义中，第一个属性的值是二维数组int类型
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const ContinuousVectorVector *attr0 = runtime_attrs->GetListListInt(0);
```

