# CustomAllocateStreamPassFn<a name="ZH-CN_TOPIC_0000002360888565"></a>

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

注册自定义的逻辑流分配Pass执行函数。

## 函数原型<a name="section36595013115"></a>

```
PassRegistrationData &CustomAllocateStreamPassFn(const CustomAllocateStreamPassFunc &allocate_stream_pass_fn)
```

## 参数说明<a name="section66599010110"></a>

<a name="table146591702113"></a>
<table><thead align="left"><tr id="row9660703111"><th class="cellrowborder" valign="top" width="22.62%" id="mcps1.1.4.1.1"><p id="p1566050316"><a name="p1566050316"></a><a name="p1566050316"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="10.97%" id="mcps1.1.4.1.2"><p id="p11660303111"><a name="p11660303111"></a><a name="p11660303111"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="66.41%" id="mcps1.1.4.1.3"><p id="p766015011111"><a name="p766015011111"></a><a name="p766015011111"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row566020312"><td class="cellrowborder" valign="top" width="22.62%" headers="mcps1.1.4.1.1 "><p id="p766010818"><a name="p766010818"></a><a name="p766010818"></a>allocate_stream_pass_fn</p>
</td>
<td class="cellrowborder" valign="top" width="10.97%" headers="mcps1.1.4.1.2 "><p id="p6660110413"><a name="p6660110413"></a><a name="p6660110413"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.41%" headers="mcps1.1.4.1.3 "><p id="p156601401219"><a name="p156601401219"></a><a name="p156601401219"></a>自定义的逻辑流分配函数。详情请参见<a href="#section165831449175516">回调函数CustomAllocateStreamPassFunc</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="section666040417"></a>

返回自身对象的引用。

## 约束说明<a name="section3659801615"></a>

无。

## 回调函数CustomAllocateStreamPassFunc<a name="section165831449175516"></a>

用户自定义并实现CustomAllocateStreamPassFunc类函数，即自定义的逻辑流分配函数。

```
Status CustomAllocateStreamPassFunc(const ConstGraphPtr &graph, StreamPassContext &stream_context)
```

**表 1**  参数说明

<a name="table55831993549"></a>
<table><thead align="left"><tr id="row1258399175419"><th class="cellrowborder" valign="top" width="18.54%" id="mcps1.2.4.1.1"><p id="p3583119195416"><a name="p3583119195416"></a><a name="p3583119195416"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="12.21%" id="mcps1.2.4.1.2"><p id="p1158349155418"><a name="p1158349155418"></a><a name="p1158349155418"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="69.25%" id="mcps1.2.4.1.3"><p id="p4583149145413"><a name="p4583149145413"></a><a name="p4583149145413"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row105834955411"><td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.2.4.1.1 "><p id="p1480415111441"><a name="p1480415111441"></a><a name="p1480415111441"></a>graph</p>
</td>
<td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.4.1.2 "><p id="p140910277115"><a name="p140910277115"></a><a name="p140910277115"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.25%" headers="mcps1.2.4.1.3 "><p id="p3409227718"><a name="p3409227718"></a><a name="p3409227718"></a>待分配逻辑流的图</p>
</td>
</tr>
<tr id="row1373614611106"><td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.2.4.1.1 "><p id="p209041656184410"><a name="p209041656184410"></a><a name="p209041656184410"></a>stream_context</p>
</td>
<td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.4.1.2 "><p id="p340862716114"><a name="p340862716114"></a><a name="p340862716114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.25%" headers="mcps1.2.4.1.3 "><p id="p1408112713118"><a name="p1408112713118"></a><a name="p1408112713118"></a>逻辑流分配上下文，可通过该上下文申请新stream id，设置节点的stream id等。详见<a href="zh-cn_topic_0000002516516787.md">StreamPassContext</a>结构定义。</p>
</td>
</tr>
<tr id="row1961527105415"><td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.2.4.1.1 "><p id="p042994418450"><a name="p042994418450"></a><a name="p042994418450"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.4.1.2 "><p id="p1461727155413"><a name="p1461727155413"></a><a name="p1461727155413"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="69.25%" headers="mcps1.2.4.1.3 "><a name="ul75701241142"></a><a name="ul75701241142"></a><ul id="ul75701241142"><li>SUCCESS：成功。</li><li>其他值：失败。</li></ul>
</td>
</tr>
</tbody>
</table>

