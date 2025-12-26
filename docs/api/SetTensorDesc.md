# SetTensorDesc<a name="ZH-CN_TOPIC_0000001312399933"></a>

## 函数功能<a name="section13070512"></a>

设置Tensor的描述符（TensorDesc）。

## 函数原型<a name="section12173916170"></a>

```
graphStatus SetTensorDesc(const TensorDesc &tensor_desc)
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
<tbody><tr id="row37599894"><td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.4.1.1 "><p id="p25692540"><a name="p25692540"></a><a name="p25692540"></a>tensor_desc</p>
</td>
<td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.4.1.2 "><p id="p720995"><a name="p720995"></a><a name="p720995"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.84%" headers="mcps1.1.4.1.3 "><p id="p32830290"><a name="p32830290"></a><a name="p32830290"></a>需设置的Tensor描述符。</p>
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

