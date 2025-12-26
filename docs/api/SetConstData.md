# SetConstData<a name="ZH-CN_TOPIC_0000001651933573"></a>

## 函数功能<a name="section63978914"></a>

如果TensorDesc是常量节点的描述，向TensorDesc中设置权重值。

## 函数原型<a name="section97881446182514"></a>

```
void SetConstData(std::unique_ptr<uint8_t[]> const_data_buffer, const size_t &const_data_len)
```

## 参数说明<a name="section38939322"></a>

<a name="table1802150"></a>
<table><thead align="left"><tr id="row32153279"><th class="cellrowborder" valign="top" width="17.09%" id="mcps1.1.4.1.1"><p id="p54278838"><a name="p54278838"></a><a name="p54278838"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="16.12%" id="mcps1.1.4.1.2"><p id="p34509720"><a name="p34509720"></a><a name="p34509720"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="66.79%" id="mcps1.1.4.1.3"><p id="p60079171"><a name="p60079171"></a><a name="p60079171"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row34574683"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.1.4.1.1 "><p id="p49085952"><a name="p49085952"></a><a name="p49085952"></a>const_data_buffer</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.4.1.2 "><p id="p16539161"><a name="p16539161"></a><a name="p16539161"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.79%" headers="mcps1.1.4.1.3 "><p id="p65514185"><a name="p65514185"></a><a name="p65514185"></a>权重地址。</p>
</td>
</tr>
<tr id="row52756755"><td class="cellrowborder" valign="top" width="17.09%" headers="mcps1.1.4.1.1 "><p id="p1461695441412"><a name="p1461695441412"></a><a name="p1461695441412"></a>const_data_len</p>
</td>
<td class="cellrowborder" valign="top" width="16.12%" headers="mcps1.1.4.1.2 "><p id="p56661507"><a name="p56661507"></a><a name="p56661507"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.79%" headers="mcps1.1.4.1.3 "><p id="p40155382"><a name="p40155382"></a><a name="p40155382"></a>权重长度。</p>
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

