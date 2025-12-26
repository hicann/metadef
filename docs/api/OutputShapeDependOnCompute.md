# OutputShapeDependOnCompute<a name="ZH-CN_TOPIC_0000002042368870"></a>

## 函数功能<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section36583473819"></a>

注册shape依赖于计算得到的输出列表。某些算子，比如NonZero（统计tensor中非零值的个数），计算完成前无法得知算子输出的shape信息，算子计算完成后才能获取。该类算子在原型定义时，需要使用OutputShapeDependOnCompute接口进行标识，同时在算子核函数中将实际输出shape写入到出参中，便于框架侧基于该信息进行输出内存的管理。

## 函数原型<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section13230182415108"></a>

```
OpImplRegisterV2 &OutputShapeDependOnCompute(std::initializer_list<int32_t> outputs)
```

## 参数说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section75395119104"></a>

<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p10223674448"><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p10223674448"></a><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p645511218169"><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p645511218169"></a><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p1922337124411"><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p1922337124411"></a><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p17770136956"><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p17770136956"></a><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p17770136956"></a>outputs</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p167701536957"><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p167701536957"></a><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p17695364517"><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p17695364517"></a><a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001346709604_p17695364517"></a>指定输出index列表。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了shape依赖于计算得到的输出列表。

## 约束说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section19165124931511"></a>

-   只能用于标识算子输出。

