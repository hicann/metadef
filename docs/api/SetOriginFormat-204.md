# SetOriginFormat<a name="ZH-CN_TOPIC_0000001938690506"></a>

## 函数功能<a name="section13070512"></a>

设置Tensor的原始Format。

该Format是指原始网络模型的Format。

## 函数原型<a name="section12173916170"></a>

```
graphStatus SetOriginFormat(const ge::Format &format)
```

## 参数说明<a name="section50525752"></a>

<a name="table32237730"></a>
<table><thead align="left"><tr id="row54443429"><th class="cellrowborder" valign="top" width="21.14%" id="mcps1.1.4.1.1"><p id="p47841633"><a name="p47841633"></a><a name="p47841633"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.4.1.2"><p id="p49967061"><a name="p49967061"></a><a name="p49967061"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="57.84%" id="mcps1.1.4.1.3"><p id="p7092232"><a name="p7092232"></a><a name="p7092232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row37599894"><td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.4.1.1 "><p id="p24621958165115"><a name="p24621958165115"></a><a name="p24621958165115"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.4.1.2 "><p id="p1530018402505"><a name="p1530018402505"></a><a name="p1530018402505"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.84%" headers="mcps1.1.4.1.3 "><p id="p26079124527"><a name="p26079124527"></a><a name="p26079124527"></a>需设置的原始Format值。</p>
<p id="p4227155673417"><a name="p4227155673417"></a><a name="p4227155673417"></a>关于Format类型，请参见<a href="Format.md">Format</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section52078584"></a>

graphStatus类型：设置成功返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理<a name="section66054074"></a>

无。

## 约束说明<a name="section57615760"></a>

无。

