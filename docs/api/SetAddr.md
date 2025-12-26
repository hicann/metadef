# SetAddr<a name="ZH-CN_TOPIC_0000002078486325"></a>

## 函数功能<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_section36583473819"></a>

设置tensor地址。

## 函数原型<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_section13230182415108"></a>

```
ge::graphStatus SetAddr(const ConstTensorAddressPtr addr, TensorAddrManager manager)
```

## 参数说明<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_section75395119104"></a>

<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p10223674448"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p10223674448"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.32%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p645511218169"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p645511218169"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.46%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1922337124411"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1922337124411"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p31071321114018"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p31071321114018"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p31071321114018"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="15.32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1210652116402"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1210652116402"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1210652116402"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.46%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p13106202194014"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p13106202194014"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p13106202194014"></a>tensor地址。</p>
<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_screen12118136183"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_screen12118136183"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_screen12118136183">using ConstTensorAddressPtr = const void *;</pre>
</td>
</tr>
<tr id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_row6432942133712"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p11051216406"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p11051216406"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p11051216406"></a>manager</p>
</td>
<td class="cellrowborder" valign="top" width="15.32%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p410422164012"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p410422164012"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p410422164012"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.46%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1310219213405"><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1310219213405"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_p1310219213405"></a>tensor的管理函数。</p>
<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_screen19433152810184"></a><a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_screen19433152810184"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_screen19433152810184">using TensorAddrManager = ge::graphStatus (*)(TensorAddress addr, TensorOperateType operate_type, void **out);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_section25791320141317"></a>

成功时返回ge::GRAPH\_SUCCESS；失败时返回manager管理函数中定义的错误码。

## 约束说明<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635172301_zh-cn_topic_0000001339549074_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
td.SetAddr(addr, HostAddrManager);
```

