# CustomPassFn<a name="ZH-CN_TOPIC_0000002327049960"></a>

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

注册自定义Pass的执行函数。

## 函数原型<a name="section36595013115"></a>

```
PassRegistrationData &CustomPassFn(const CustomPassFunc &custom_pass_fn)
```

## 参数说明<a name="section66599010110"></a>

<a name="table146591702113"></a>
<table><thead align="left"><tr id="row9660703111"><th class="cellrowborder" valign="top" width="18.54%" id="mcps1.1.4.1.1"><p id="p1566050316"><a name="p1566050316"></a><a name="p1566050316"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="10.66%" id="mcps1.1.4.1.2"><p id="p11660303111"><a name="p11660303111"></a><a name="p11660303111"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="70.8%" id="mcps1.1.4.1.3"><p id="p766015011111"><a name="p766015011111"></a><a name="p766015011111"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row566020312"><td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.1.4.1.1 "><p id="p766010818"><a name="p766010818"></a><a name="p766010818"></a>custom_pass_fn</p>
</td>
<td class="cellrowborder" valign="top" width="10.66%" headers="mcps1.1.4.1.2 "><p id="p6660110413"><a name="p6660110413"></a><a name="p6660110413"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="70.8%" headers="mcps1.1.4.1.3 "><p id="p156601401219"><a name="p156601401219"></a><a name="p156601401219"></a>自定义Pass的执行函数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="section666040417"></a>

返回自身对象的引用。

## 约束说明<a name="section3659801615"></a>

无

## 回调函数CustomPassFunc<a name="section286814295311"></a>

用户自定义并实现CustomPassFunc类函数，即自定义的改图函数。

```
Status CustomPassFunc(GraphPtr &graph, CustomPassContext &custom_context)
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
<tbody><tr id="row105834955411"><td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.2.4.1.1 "><p id="p221281518108"><a name="p221281518108"></a><a name="p221281518108"></a>graph</p>
</td>
<td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.4.1.2 "><p id="p6212141514105"><a name="p6212141514105"></a><a name="p6212141514105"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.25%" headers="mcps1.2.4.1.3 "><p id="p15212111510105"><a name="p15212111510105"></a><a name="p15212111510105"></a>要修改的图。</p>
</td>
</tr>
<tr id="row1373614611106"><td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.2.4.1.1 "><p id="p13212111510109"><a name="p13212111510109"></a><a name="p13212111510109"></a>custom_context</p>
</td>
<td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.4.1.2 "><p id="p16212101531010"><a name="p16212101531010"></a><a name="p16212101531010"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.25%" headers="mcps1.2.4.1.3 "><p id="p10212115181018"><a name="p10212115181018"></a><a name="p10212115181018"></a>维测类对象，通过此对象向框架注册维测信息。</p>
</td>
</tr>
<tr id="row1961527105415"><td class="cellrowborder" valign="top" width="18.54%" headers="mcps1.2.4.1.1 "><p id="p36152745410"><a name="p36152745410"></a><a name="p36152745410"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.4.1.2 "><p id="p1461727155413"><a name="p1461727155413"></a><a name="p1461727155413"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="69.25%" headers="mcps1.2.4.1.3 "><a name="ul75701241142"></a><a name="ul75701241142"></a><ul id="ul75701241142"><li>SUCCESS：成功。</li><li>其他值：失败。</li></ul>
</td>
</tr>
</tbody>
</table>

