# SetOriginShapeDim<a name="ZH-CN_TOPIC_0000001831112400"></a>

## 函数功能<a name="section13070512"></a>

设置原始shape第idx维度。

## 函数原型<a name="section12173916170"></a>

```
graphStatus SetOriginShapeDim(const size_t idx, const int64_t dim_value)
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
<tbody><tr id="row37599894"><td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.4.1.1 "><p id="p1741312436205"><a name="p1741312436205"></a><a name="p1741312436205"></a>idx</p>
</td>
<td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.4.1.2 "><p id="p7412154362013"><a name="p7412154362013"></a><a name="p7412154362013"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.84%" headers="mcps1.1.4.1.3 "><p id="p184119431208"><a name="p184119431208"></a><a name="p184119431208"></a>维度的索引，索引从0开始。</p>
</td>
</tr>
<tr id="row198337112820"><td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.4.1.1 "><p id="p1498173752819"><a name="p1498173752819"></a><a name="p1498173752819"></a>dim_value</p>
</td>
<td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.4.1.2 "><p id="p89873712810"><a name="p89873712810"></a><a name="p89873712810"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.84%" headers="mcps1.1.4.1.3 "><p id="p8981379282"><a name="p8981379282"></a><a name="p8981379282"></a>需设置的值。</p>
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

