# SetData<a name="ZH-CN_TOPIC_0000001264921058"></a>

## 函数功能<a name="section18697032"></a>

向Tensor中设置数据。

## 函数原型<a name="section46684408184"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
graphStatus SetData(std::vector<uint8_t> &&data)
graphStatus SetData(const std::vector<uint8_t> &data)
graphStatus SetData(const uint8_t *data, size_t size)
graphStatus SetData(const std::string &data)
graphStatus SetData(const char_t *data)
graphStatus SetData(const std::vector<std::string> &data)
graphStatus SetData(const std::vector<AscendString> &datas)
graphStatus SetData(uint8_t *data, size_t size, const Tensor::DeleteFunc &deleter_func)
```

## 参数说明<a name="section34055563"></a>

<a name="table53729511"></a>
<table><thead align="left"><tr id="row37418306"><th class="cellrowborder" valign="top" width="21.13%" id="mcps1.1.4.1.1"><p id="p10983950"><a name="p10983950"></a><a name="p10983950"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="22.869999999999997%" id="mcps1.1.4.1.2"><p id="p17284754"><a name="p17284754"></a><a name="p17284754"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="56.00000000000001%" id="mcps1.1.4.1.3"><p id="p58405349"><a name="p58405349"></a><a name="p58405349"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row33212803"><td class="cellrowborder" valign="top" width="21.13%" headers="mcps1.1.4.1.1 "><p id="p5882489"><a name="p5882489"></a><a name="p5882489"></a>data/datas</p>
</td>
<td class="cellrowborder" valign="top" width="22.869999999999997%" headers="mcps1.1.4.1.2 "><p id="p6719600"><a name="p6719600"></a><a name="p6719600"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p63883391"><a name="p63883391"></a><a name="p63883391"></a>需设置的数据。</p>
</td>
</tr>
<tr id="row1018445942214"><td class="cellrowborder" valign="top" width="21.13%" headers="mcps1.1.4.1.1 "><p id="p99681752312"><a name="p99681752312"></a><a name="p99681752312"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="22.869999999999997%" headers="mcps1.1.4.1.2 "><p id="p39671762313"><a name="p39671762313"></a><a name="p39671762313"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p3964177236"><a name="p3964177236"></a><a name="p3964177236"></a>数据的长度，单位为字节。</p>
</td>
</tr>
<tr id="row75514361261"><td class="cellrowborder" valign="top" width="21.13%" headers="mcps1.1.4.1.1 "><p id="p45617363263"><a name="p45617363263"></a><a name="p45617363263"></a>deleter_func</p>
</td>
<td class="cellrowborder" valign="top" width="22.869999999999997%" headers="mcps1.1.4.1.2 "><p id="p195663619263"><a name="p195663619263"></a><a name="p195663619263"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p105653672613"><a name="p105653672613"></a><a name="p105653672613"></a>用于释放data数据。</p>
<pre class="screen" id="screen295117617271"><a name="screen295117617271"></a><a name="screen295117617271"></a>using DeleteFunc = std::function&lt;void(uint8_t *)&gt;;</pre>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section38064613"></a>

graphStatus类型：设置成功返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理<a name="section11521646202311"></a>

无。

## 约束说明<a name="section14008765"></a>

无。

