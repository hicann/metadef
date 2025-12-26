# Tensor构造函数和析构函数<a name="ZH-CN_TOPIC_0000001264921070"></a>

## 函数功能<a name="zh-cn_topic_0204328222_zh-cn_topic_0182636384_section36893359"></a>

Tensor构造函数和析构函数。

## 函数原型<a name="zh-cn_topic_0204328222_zh-cn_topic_0182636384_section136951948195410"></a>

```
Tensor()
~Tensor() = default
explicit Tensor(const TensorDesc &tensor_desc)
Tensor(const TensorDesc &tensor_desc, const std::vector<uint8_t> &data)
Tensor(const TensorDesc &tensor_desc, const uint8_t *data, size_t size)
Tensor(TensorDesc &&tensor_desc, std::vector<uint8_t> &&data)
```

## 参数说明<a name="zh-cn_topic_0204328222_zh-cn_topic_0182636384_section63604780"></a>

<a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_table1802150"></a>
<table><thead align="left"><tr id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_row32153279"><th class="cellrowborder" valign="top" width="25.369999999999997%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p54278838"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p54278838"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p54278838"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="16.73%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p34509720"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p34509720"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p34509720"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="57.9%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p60079171"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p60079171"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p60079171"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_row34574683"><td class="cellrowborder" valign="top" width="25.369999999999997%" headers="mcps1.1.4.1.1 "><p id="p47081416527"><a name="p47081416527"></a><a name="p47081416527"></a>tensor_desc</p>
</td>
<td class="cellrowborder" valign="top" width="16.73%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p16539161"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p16539161"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p16539161"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.9%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p65514185"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p65514185"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p65514185"></a>TensorDesc对象，需设置的Tensor描述符。</p>
</td>
</tr>
<tr id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_row52756755"><td class="cellrowborder" valign="top" width="25.369999999999997%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p45438767"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p45438767"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p45438767"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="16.73%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p56661507"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p56661507"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p56661507"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.9%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636416_p63883391"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636416_p63883391"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636416_p63883391"></a>需设置的数据。</p>
</td>
</tr>
<tr id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_row25854119"><td class="cellrowborder" valign="top" width="25.369999999999997%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p13808900"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p13808900"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p13808900"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="16.73%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p44779134"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p44779134"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636399_p44779134"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.9%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328222_zh-cn_topic_0182636416_p3964177236"><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636416_p3964177236"></a><a name="zh-cn_topic_0204328222_zh-cn_topic_0182636416_p3964177236"></a>数据的长度，单位为字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328222_zh-cn_topic_0182636384_section35572112"></a>

Tensor构造函数返回Tensor类型的对象。

## 异常处理<a name="zh-cn_topic_0204328222_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328222_zh-cn_topic_0182636384_section62768825"></a>

无。

