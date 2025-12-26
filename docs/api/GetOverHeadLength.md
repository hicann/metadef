# GetOverHeadLength<a name="ZH-CN_TOPIC_0000002042368710"></a>

## 函数功能<a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340326216_section36583473819"></a>

获取数据描述信息的长度。

## 函数原型<a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340326216_section13230182415108"></a>

```
static size_t GetOverHeadLength(const size_t capacity)
```

## 参数说明<a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340326216_section75395119104"></a>

<a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_row6223476444"><th class="cellrowborder" valign="top" width="21.13%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p10223674448"><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p10223674448"></a><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="11.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p645511218169"><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p645511218169"></a><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p1922337124411"><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p1922337124411"></a><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_row14829163161614"><td class="cellrowborder" valign="top" width="21.13%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001702266362_p6497153720426"><a name="zh-cn_topic_0000001702266362_p6497153720426"></a><a name="zh-cn_topic_0000001702266362_p6497153720426"></a>capacity</p>
</td>
<td class="cellrowborder" valign="top" width="11.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p1082983131619"><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p1082983131619"></a><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001390646121_p1082983131619"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340006336_p1769121516311"><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340006336_p1769121516311"></a><a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340006336_p1769121516311"></a>实例的最大容量。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340326216_section25791320141317"></a>

数据描述信息的长度。

## 约束说明<a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340326216_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001702266362_zh-cn_topic_0000001340326216_section320753512363"></a>

```
size_t capacity = 100U;
auto length = ContinuousVectorVector::GetOverHeadLength(capacity);
```

