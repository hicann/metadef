# SetDim<a name="ZH-CN_TOPIC_0000001312640909"></a>

## 函数功能<a name="section14909584"></a>

将Shape中第idx维度的值设置为value。

## 函数原型<a name="section678150101519"></a>

```
graphStatus SetDim(size_t idx, int64_t value)
```

## 参数说明<a name="section67077397"></a>

<a name="table11756443"></a>
<table><thead align="left"><tr id="row54278838"><th class="cellrowborder" valign="top" width="18.32%" id="mcps1.1.4.1.1"><p id="p34509720"><a name="p34509720"></a><a name="p34509720"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="22.52%" id="mcps1.1.4.1.2"><p id="p43823951"><a name="p43823951"></a><a name="p43823951"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="59.160000000000004%" id="mcps1.1.4.1.3"><p id="p34574683"><a name="p34574683"></a><a name="p34574683"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row49085952"><td class="cellrowborder" valign="top" width="18.32%" headers="mcps1.1.4.1.1 "><p id="p16539161"><a name="p16539161"></a><a name="p16539161"></a>idx</p>
</td>
<td class="cellrowborder" valign="top" width="22.52%" headers="mcps1.1.4.1.2 "><p id="p64603663"><a name="p64603663"></a><a name="p64603663"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="59.160000000000004%" headers="mcps1.1.4.1.3 "><p id="p5048751"><a name="p5048751"></a><a name="p5048751"></a>Shape维度的索引，索引从0开始。</p>
</td>
</tr>
<tr id="row45438767"><td class="cellrowborder" valign="top" width="18.32%" headers="mcps1.1.4.1.1 "><p id="p56661507"><a name="p56661507"></a><a name="p56661507"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="22.52%" headers="mcps1.1.4.1.2 "><p id="p26179384"><a name="p26179384"></a><a name="p26179384"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="59.160000000000004%" headers="mcps1.1.4.1.3 "><p id="p31360484"><a name="p31360484"></a><a name="p31360484"></a>需设置的值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section66825666"></a>

graphStatus类型：设置成功返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理<a name="section64560089"></a>

无。

## 约束说明<a name="section44169889"></a>

使用SetDim接口前，只能使用Shape\(const std::vector<int64\_t\>& dims\)构造shape对象。如果使用Shape\(\)构造shape对象，使用SetDim接口将返回失败。

