# TensorDesc构造函数和析构函数<a name="ZH-CN_TOPIC_0000001312399909"></a>

## 函数功能<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section36893359"></a>

TensorDesc构造函数和析构函数。

## 函数原型<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section136951948195410"></a>

```
TensorDesc()
~TensorDesc() = default
explicit TensorDesc(Shape shape, Format format = FORMAT_ND, DataType dt = DT_FLOAT)
TensorDesc(const TensorDesc &desc)
TensorDesc(TensorDesc &&desc)
TensorDesc &operator=(const TensorDesc &desc)
TensorDesc &operator=(TensorDesc &&desc)
```

## 参数说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section63604780"></a>

<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_table1802150"></a>
<table><thead align="left"><tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row32153279"><th class="cellrowborder" valign="top" width="18.93%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="17.65%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="63.42%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row34574683"><td class="cellrowborder" valign="top" width="18.93%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"></a>shape</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="63.42%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"></a>Shape对象。</p>
</td>
</tr>
<tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row52756755"><td class="cellrowborder" valign="top" width="18.93%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p45438767"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p45438767"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p45438767"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p56661507"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p56661507"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p56661507"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="63.42%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p40155382"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p40155382"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p40155382"></a>Format对象，默认取值FORMAT_ND。</p>
<p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p12276181811190"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p12276181811190"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p12276181811190"></a>关于Format数据类型的定义，请参见<a href="Format.md">Format</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row25854119"><td class="cellrowborder" valign="top" width="18.93%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p13808900"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p13808900"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p13808900"></a>dt</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p44779134"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p44779134"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p44779134"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="63.42%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60402919"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60402919"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60402919"></a>DataType对象，默认取值DT_FLOAT。</p>
<p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p285824051918"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p285824051918"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p285824051918"></a>关于DataType数据类型的定义，请参见<a href="DataType.md">DataType</a>。</p>
</td>
</tr>
<tr id="row192766390519"><td class="cellrowborder" valign="top" width="18.93%" headers="mcps1.1.4.1.1 "><p id="p1227763912516"><a name="p1227763912516"></a><a name="p1227763912516"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" width="17.65%" headers="mcps1.1.4.1.2 "><p id="p8277173916518"><a name="p8277173916518"></a><a name="p8277173916518"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="63.42%" headers="mcps1.1.4.1.3 "><p id="p1227712393513"><a name="p1227712393513"></a><a name="p1227712393513"></a>待拷贝或者移动的TensorDesc对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

TensorDesc构造函数返回TensorDesc类型的对象。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

