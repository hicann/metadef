# TilingInputsDataDependency<a name="ZH-CN_TOPIC_0000002078447929"></a>

## 函数功能<a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_section36583473819"></a>

标记Tiling计算时需要依赖算子第几个输入tensor的值，同时标记tiling计算支持执行的位置。

## 函数原型<a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_section13230182415108"></a>

```
OpImplRegisterV2 &TilingInputsDataDependency(std::initializer_list<int32_t> inputs)
OpImplRegisterV2 &TilingInputsDataDependency(std::initializer_list<int32_t> inputs, std::initializer_list<TilingPlacement> placements)
```

## 参数说明<a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_section181917342085"></a>

<a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p10223674448"><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p10223674448"></a><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p645511218169"><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p645511218169"></a><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p1922337124411"><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p1922337124411"></a><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p17770136956"><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p17770136956"></a><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p17770136956"></a>inputs</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p167701536957"><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p167701536957"></a><a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071624613_p1072817164214"><a name="zh-cn_topic_0000002071624613_p1072817164214"></a><a name="zh-cn_topic_0000002071624613_p1072817164214"></a>指定算子tiling计算需要依赖的输入index列表。举例来说，inputs={0，3}，说明该算子的tiling计算需要依赖第0、3个输入的tensor值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002071624613_row2046011326383"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071624613_p9455183215385"><a name="zh-cn_topic_0000002071624613_p9455183215385"></a><a name="zh-cn_topic_0000002071624613_p9455183215385"></a>placements</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071624613_p114551332143812"><a name="zh-cn_topic_0000002071624613_p114551332143812"></a><a name="zh-cn_topic_0000002071624613_p114551332143812"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071624613_p14455133293812"><a name="zh-cn_topic_0000002071624613_p14455133293812"></a><a name="zh-cn_topic_0000002071624613_p14455133293812"></a>指定算子tiling计算可以执行的位置，0代表支持在host侧执行， 1代表支持在AI CPU上执行。如果不包含本参数，代表只支持在host执行。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了算子tiling值依赖输入的第index个tensor值以及可执行的位置。

## 约束说明<a name="zh-cn_topic_0000002071624613_zh-cn_topic_0000001346709604_section19165124931511"></a>

无。

