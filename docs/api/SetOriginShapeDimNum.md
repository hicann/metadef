# SetOriginShapeDimNum<a name="ZH-CN_TOPIC_0000001831272204"></a>

## 函数功能<a name="section13070512"></a>

设置原始shape的维度大小，即rank大小。

## 函数原型<a name="section12173916170"></a>

```
graphStatus SetOriginShapeDimNum(const size_t dim_num)
```

## 参数说明<a name="section50525752"></a>

<a name="table32237730"></a>
<table><thead align="left"><tr id="row54443429"><th class="cellrowborder" valign="top" width="15.82%" id="mcps1.1.4.1.1"><p id="p47841633"><a name="p47841633"></a><a name="p47841633"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.12%" id="mcps1.1.4.1.2"><p id="p49967061"><a name="p49967061"></a><a name="p49967061"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="70.06%" id="mcps1.1.4.1.3"><p id="p7092232"><a name="p7092232"></a><a name="p7092232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row37599894"><td class="cellrowborder" valign="top" width="15.82%" headers="mcps1.1.4.1.1 "><p id="p1741312436205"><a name="p1741312436205"></a><a name="p1741312436205"></a>dim_num</p>
</td>
<td class="cellrowborder" valign="top" width="14.12%" headers="mcps1.1.4.1.2 "><p id="p7412154362013"><a name="p7412154362013"></a><a name="p7412154362013"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="70.06%" headers="mcps1.1.4.1.3 "><p id="p184119431208"><a name="p184119431208"></a><a name="p184119431208"></a>原始shape的维度大小，即原始shape的rank。</p>
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

