# Stage<a name="ZH-CN_TOPIC_0000002327049972"></a>

## AI处理器支持情况<a name="section789110355111"></a>

<a name="zh-cn_topic_0000001312404881_table38301303189"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312404881_row20831180131817"><th class="cellrowborder" valign="top" width="57.99999999999999%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001312404881_p1883113061818"><a name="zh-cn_topic_0000001312404881_p1883113061818"></a><a name="zh-cn_topic_0000001312404881_p1883113061818"></a><span id="zh-cn_topic_0000001312404881_ph20833205312295"><a name="zh-cn_topic_0000001312404881_ph20833205312295"></a><a name="zh-cn_topic_0000001312404881_ph20833205312295"></a>AI处理器类型</span></p>
</th>
<th class="cellrowborder" align="center" valign="top" width="42%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001312404881_p783113012187"><a name="zh-cn_topic_0000001312404881_p783113012187"></a><a name="zh-cn_topic_0000001312404881_p783113012187"></a>是否支持</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312404881_row220181016240"><td class="cellrowborder" valign="top" width="57.99999999999999%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001312404881_p48327011813"><a name="zh-cn_topic_0000001312404881_p48327011813"></a><a name="zh-cn_topic_0000001312404881_p48327011813"></a><span id="zh-cn_topic_0000001312404881_ph583230201815"><a name="zh-cn_topic_0000001312404881_ph583230201815"></a><a name="zh-cn_topic_0000001312404881_ph583230201815"></a><term id="zh-cn_topic_0000001312404881_zh-cn_topic_0000001312391781_term1253731311225"><a name="zh-cn_topic_0000001312404881_zh-cn_topic_0000001312391781_term1253731311225"></a><a name="zh-cn_topic_0000001312404881_zh-cn_topic_0000001312391781_term1253731311225"></a>Ascend 910C</term></span></p>
</td>
<td class="cellrowborder" align="center" valign="top" width="42%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001312404881_p108715341013"><a name="zh-cn_topic_0000001312404881_p108715341013"></a><a name="zh-cn_topic_0000001312404881_p108715341013"></a>√</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312404881_row173226882415"><td class="cellrowborder" valign="top" width="57.99999999999999%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001312404881_p14832120181815"><a name="zh-cn_topic_0000001312404881_p14832120181815"></a><a name="zh-cn_topic_0000001312404881_p14832120181815"></a><span id="zh-cn_topic_0000001312404881_ph1483216010188"><a name="zh-cn_topic_0000001312404881_ph1483216010188"></a><a name="zh-cn_topic_0000001312404881_ph1483216010188"></a><term id="zh-cn_topic_0000001312404881_zh-cn_topic_0000001312391781_term11962195213215"><a name="zh-cn_topic_0000001312404881_zh-cn_topic_0000001312391781_term11962195213215"></a><a name="zh-cn_topic_0000001312404881_zh-cn_topic_0000001312391781_term11962195213215"></a>Ascend 910B</term></span></p>
</td>
<td class="cellrowborder" align="center" valign="top" width="42%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001312404881_p19948143911820"><a name="zh-cn_topic_0000001312404881_p19948143911820"></a><a name="zh-cn_topic_0000001312404881_p19948143911820"></a>√</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="section865990310"></a>

设置自定义Pass执行阶段。

## 函数原型<a name="section36595013115"></a>

```
PassRegistrationData &Stage(const CustomPassStage stage)
```

## 参数说明<a name="section66599010110"></a>

<a name="table146591702113"></a>
<table><thead align="left"><tr id="row9660703111"><th class="cellrowborder" valign="top" width="12.94%" id="mcps1.1.4.1.1"><p id="p1566050316"><a name="p1566050316"></a><a name="p1566050316"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="10.05%" id="mcps1.1.4.1.2"><p id="p11660303111"><a name="p11660303111"></a><a name="p11660303111"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="77.01%" id="mcps1.1.4.1.3"><p id="p766015011111"><a name="p766015011111"></a><a name="p766015011111"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row566020312"><td class="cellrowborder" valign="top" width="12.94%" headers="mcps1.1.4.1.1 "><p id="p205416461114"><a name="p205416461114"></a><a name="p205416461114"></a>stage</p>
</td>
<td class="cellrowborder" valign="top" width="10.05%" headers="mcps1.1.4.1.2 "><p id="p6660110413"><a name="p6660110413"></a><a name="p6660110413"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="77.01%" headers="mcps1.1.4.1.3 "><p id="p74901933153013"><a name="p74901933153013"></a><a name="p74901933153013"></a>表示自定义Pass执行阶段。</p>
<a name="ul436915409308"></a><a name="ul436915409308"></a><ul id="ul436915409308"><li>kBeforeInferShape：（默认值）自定义Pass在框架入口处InferShape之前执行。</li><li>kAfterInferShape：自定义Pass在InferShape之后执行。<p id="p231024694316"><a name="p231024694316"></a><a name="p231024694316"></a>如果自定义Pass在InferShape之后执行，Pass中需要保证改图之后shape的连续性：</p>
<a name="screen13531144547"></a><a name="screen13531144547"></a><pre class="screen" codetype="Cpp" id="screen13531144547">    // 1. 获取输入节点node1的输出描述
    TensorDesc output_desc;
    node1.GetOutputDesc(0, output_desc);
    // 2. 更新当前节点node2的输入描述
    node2.UpdateInputDesc(0, output_desc);
    // 3. 当前节点node2推导InferShape
    operator2.InferShapeAndType();</pre>
</li><li>kAfterAssignLogicStream：自定义Pass在逻辑流分配阶段之后执行。该阶段仅接收逻辑流分配的Pass（注册自定义的逻辑流分配Pass执行函数请参见<a href="CustomAllocateStreamPassFn.md">CustomAllocateStreamPassFn</a>），由于该阶段不允许改图，其他场景的改图Pass会校验报错。</li><li>kAfterBuiltinFusionPass：自定义Pass在内置的原图融合Pass之后执行。</li></ul>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="section666040417"></a>

返回PassRegistrationData对象。

## 约束说明<a name="section3659801615"></a>

无

