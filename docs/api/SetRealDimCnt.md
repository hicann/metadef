# SetRealDimCnt<a name="ZH-CN_TOPIC_0000001265240894"></a>

## 函数功能<a name="section1189413510313"></a>

向TensorDesc中设置Tensor的实际维度数目。

通过[GetShape](GetShape-186.md)接口返回的Shape的维度可能存在补1的场景，因此可以通过该接口设置Shape的实际维度个数。

## 函数原型<a name="section6188134993114"></a>

```
void SetRealDimCnt(const int64_t real_dim_cnt)
```

## 参数说明<a name="section5130551310"></a>

<a name="table6398952111810"></a>
<table><thead align="left"><tr id="row039835212181"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p13398252181816"><a name="p13398252181816"></a><a name="p13398252181816"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="15.709999999999999%" id="mcps1.1.4.1.2"><p id="p139825241814"><a name="p139825241814"></a><a name="p139825241814"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="65.83%" id="mcps1.1.4.1.3"><p id="p14398145251816"><a name="p14398145251816"></a><a name="p14398145251816"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1439818522182"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p83981952171814"><a name="p83981952171814"></a><a name="p83981952171814"></a>real_dim_cnt</p>
</td>
<td class="cellrowborder" valign="top" width="15.709999999999999%" headers="mcps1.1.4.1.2 "><p id="p73980528182"><a name="p73980528182"></a><a name="p73980528182"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="65.83%" headers="mcps1.1.4.1.3 "><p id="p123981952121818"><a name="p123981952121818"></a><a name="p123981952121818"></a>需设置的TensorDesc的实际数据维度数目信息。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section126151758163117"></a>

无。

## 异常处理<a name="section1954620111323"></a>

无。

## 约束说明<a name="section949485193218"></a>

无。

