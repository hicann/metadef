# Op2StageExecuteFuncs<a name="ZH-CN_TOPIC_0000002496145121"></a>

## 函数功能<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section36583473819"></a>

单个算子包含多Kernel组合执行逻辑的场景下，算子可以通过该接口设置算子级的回调函数，包含下发准备回调函数和下发回调函数，下发准备回调函数完成Kernel下发使用到的参数的准备，下发回调函数内实现多Kernel的下发。本接口为内部关联接口，开发者不会直接调用，暂时无需关注。

## 函数原型<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section13230182415108"></a>

```
OpImplRegisterV2 &Op2StageExecuteFuncs(OpExecPrepareFunc prepare_func, OpExecLaunchFunc launch_func)
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
<tbody><tr id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17770136956"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17770136956"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17770136956"></a>prepare_func</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p167701536957"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p167701536957"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17695364517"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17695364517"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_p17695364517"></a>注册的自定义OpExecPrepareFunc函数，类型为OpExecPrepareFunc。</p>
<p id="zh-cn_topic_0000002071546041_zh-cn_topic_0000001396749553_p127074518214"><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001396749553_p127074518214"></a><a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001396749553_p127074518214"></a>OpExecPrepareFunc类型定义如下：</p>
<a name="zh-cn_topic_0000002071546041_screen139321658102316"></a><a name="zh-cn_topic_0000002071546041_screen139321658102316"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000002071546041_screen139321658102316">using OpExecPrepareFunc = UINT32 (*)(OpExecutePrepareContext *);</pre>
</td>
</tr>
<tr id="row139051138101916"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p1790510381199"><a name="p1790510381199"></a><a name="p1790510381199"></a>launch_func</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p19051388199"><a name="p19051388199"></a><a name="p19051388199"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p291074115278"><a name="p291074115278"></a><a name="p291074115278"></a>注册的自定义OpExecLaunchFunc函数，类型为OpExecLaunchFunc。</p>
<a name="screen18494817132810"></a><a name="screen18494817132810"></a><pre class="screen" codetype="Cpp" id="screen18494817132810">using OpExecLaunchFunc = UINT32 (*)(OpExecuteLaunchContext *);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了算子级的回调函数。

## 约束说明<a name="zh-cn_topic_0000002071546041_zh-cn_topic_0000001346709604_section19165124931511"></a>

无。

