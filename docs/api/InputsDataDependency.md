# InputsDataDependency<a name="ZH-CN_TOPIC_0000002078447925"></a>

## 函数功能<a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_section36583473819"></a>

设置算子计算依赖第几个输入tensor的值。

所谓的数据依赖，是指算子的计算不仅依赖于输入tensor的shape，还依赖输入tensor的具体值。

## 函数原型<a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_section13230182415108"></a>

```
OpImplRegisterV2 &InputsDataDependency(std::initializer_list<int32_t> inputs)
```

## 参数说明<a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_section181917342085"></a>

<a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p10223674448"><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p10223674448"></a><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p645511218169"><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p645511218169"></a><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p1922337124411"><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p1922337124411"></a><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p17770136956"><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p17770136956"></a><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p17770136956"></a>inputs</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p167701536957"><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p167701536957"></a><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p17695364517"><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p17695364517"></a><a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_p17695364517"></a>指定算子计算需要依赖的输入index列表。举例来说，inputs={0，3}，说明该算子的计算需要依赖第0、3个输入的tensor值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_section25791320141317"></a>

返回算子的OpImplRegisterV2 对象，该对象新增设置算子计算依赖第几个输入tensor的值。

## 约束说明<a name="zh-cn_topic_0000002035516800_zh-cn_topic_0000001346709604_section19165124931511"></a>

无。

