# OpExecuteFunc<a name="ZH-CN_TOPIC_0000002078486545"></a>

## 函数功能<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section36583473819"></a>

单个算子包含多kernel组合执行逻辑的场景下，算子可以通过该接口设置算子级的回调函数，回调函数内实现多kernel的下发。该功能为预留特性，暂不支持。

## 函数原型<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section13230182415108"></a>

```
OpImplRegisterV2 &OpExecuteFunc(OpExecFunc op_execute_func)
```

## 参数说明<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section181917342085"></a>

<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p10223674448"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p10223674448"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p645511218169"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p645511218169"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p1922337124411"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p1922337124411"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17770136956"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17770136956"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17770136956"></a>op_execute_func</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p167701536957"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p167701536957"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17695364517"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17695364517"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17695364517"></a>注册的自定义OpExecuteFunc函数，类型为OpExecFunc。</p>
<p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001396749553_p127074518214"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001396749553_p127074518214"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001396749553_p127074518214"></a>OpExecFunc类型定义如下：</p>
<a name="zh-cn_topic_0000002071546041_screen139321658102316"></a><a name="zh-cn_topic_0000002071546041_screen139321658102316"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000002071546041_screen139321658102316">using OpExecFunc = UINT32 (*)(OpExecuteContext *);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了算子级的回调函数。

## 约束说明<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section19165124931511"></a>

无。

