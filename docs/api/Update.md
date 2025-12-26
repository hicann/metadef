# Update<a name="ZH-CN_TOPIC_0000001312720973"></a>

## 函数功能<a name="section63978914"></a>

更新TensorDesc的Shape、Format、DataType属性。

## 函数原型<a name="section97881446182514"></a>

```
void Update(const Shape &shape, Format format = FORMAT_ND, DataType dt = DT_FLOAT)
```

## 参数说明<a name="section38939322"></a>

<a name="table1802150"></a>
<table><thead align="left"><tr id="row32153279"><th class="cellrowborder" valign="top" width="17.43%" id="mcps1.1.4.1.1"><p id="p54278838"><a name="p54278838"></a><a name="p54278838"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="16.12%" id="mcps1.1.4.1.2"><p id="p34509720"><a name="p34509720"></a><a name="p34509720"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="66.45%" id="mcps1.1.4.1.3"><p id="p60079171"><a name="p60079171"></a><a name="p60079171"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row34574683"><td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.1.4.1.1 "><p id="p49085952"><a name="p49085952"></a><a name="p49085952"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.4.1.2 "><p id="p16539161"><a name="p16539161"></a><a name="p16539161"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.45%" headers="mcps1.1.4.1.3 "><p id="p65514185"><a name="p65514185"></a><a name="p65514185"></a>需刷新的Shape对象。</p>
</td>
</tr>
<tr id="row52756755"><td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.1.4.1.1 "><p id="p45438767"><a name="p45438767"></a><a name="p45438767"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.4.1.2 "><p id="p56661507"><a name="p56661507"></a><a name="p56661507"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.45%" headers="mcps1.1.4.1.3 "><p id="p40155382"><a name="p40155382"></a><a name="p40155382"></a>需刷新的Format对象，默认取值FORMAT_ND。</p>
</td>
</tr>
<tr id="row25854119"><td class="cellrowborder" valign="top" width="17.43%" headers="mcps1.1.4.1.1 "><p id="p13808900"><a name="p13808900"></a><a name="p13808900"></a>dt</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.4.1.2 "><p id="p44779134"><a name="p44779134"></a><a name="p44779134"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.45%" headers="mcps1.1.4.1.3 "><p id="p60402919"><a name="p60402919"></a><a name="p60402919"></a>需刷新的DataType对象，默认取值DT_FLOAT。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section14909584"></a>

无。

## 异常处理<a name="section67077397"></a>

无。

## 约束说明<a name="section66825666"></a>

无。

