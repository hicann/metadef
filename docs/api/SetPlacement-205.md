# SetPlacement<a name="ZH-CN_TOPIC_0000001935371964"></a>

## 函数功能<a name="section13070512"></a>

设置Tensor的数据存放的位置。

## 函数原型<a name="section12173916170"></a>

```
graphStatus SetPlacement(const ge::Placement &placement)
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
<tbody><tr id="row37599894"><td class="cellrowborder" valign="top" width="21.14%" headers="mcps1.1.4.1.1 "><p id="p2270151718"><a name="p2270151718"></a><a name="p2270151718"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.4.1.2 "><p id="p1530018402505"><a name="p1530018402505"></a><a name="p1530018402505"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.84%" headers="mcps1.1.4.1.3 "><p id="p77422181116"><a name="p77422181116"></a><a name="p77422181116"></a>需设置的数据地址的值。</p>
<p id="p184021035142712"><a name="p184021035142712"></a><a name="p184021035142712"></a>枚举值定义如下：</p>
<a name="screen13416130182913"></a><a name="screen13416130182913"></a><pre class="screen" codetype="Cpp" id="screen13416130182913">enum Placement {
  kPlacementHost = 0,   // host data addr
  kPlacementDevice = 1, // device data addr
};</pre>
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

