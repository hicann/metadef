# Add<a name="ZH-CN_TOPIC_0000002078486389"></a>

## 函数功能<a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_section36583473819"></a>

新增一个ContinuousVector元素，其中新增ContinuousVector元素的容量为inner\_vector\_capacity。

## 函数原型<a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_section13230182415108"></a>

```
template<typename T> ContinuousVector *Add(size_t inner_vector_capacity)
```

## 参数说明<a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_section75395119104"></a>

<a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_row6223476444"><th class="cellrowborder" valign="top" width="21.13%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p10223674448"><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p10223674448"></a><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="11.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p645511218169"><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p645511218169"></a><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p1922337124411"><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p1922337124411"></a><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_row14829163161614"><td class="cellrowborder" valign="top" width="21.13%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p4829133121620"><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p4829133121620"></a><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p4829133121620"></a>inner_vector_capacity</p>
</td>
<td class="cellrowborder" valign="top" width="11.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p1082983131619"><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p1082983131619"></a><a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_p1082983131619"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001750066161_p833814143513"><a name="zh-cn_topic_0000001750066161_p833814143513"></a><a name="zh-cn_topic_0000001750066161_p833814143513"></a>新增ContinuousVector元素的容量。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_section25791320141317"></a>

新增ContinuousVector元素的首地址。

## 约束说明<a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001750066161_zh-cn_topic_0000001390646121_section320753512363"></a>

```
// 创建ContinuousVectorVector对象cvv
...
// 增加元素
size_t inner_vector_capacity = 2;
auto cv = cvv->Add(inner_vector_capacity);
```

