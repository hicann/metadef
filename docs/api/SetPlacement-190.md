# SetPlacement<a name="ZH-CN_TOPIC_0000001312640933"></a>

## 函数功能<a name="section1189413510313"></a>

设置Tensor的数据存放的位置。

## 函数原型<a name="section6188134993114"></a>

```
void SetPlacement(Placement placement)
```

## 参数说明<a name="section5130551310"></a>

<a name="table6398952111810"></a>
<table><thead align="left"><tr id="row039835212181"><th class="cellrowborder" valign="top" width="15.160000000000002%" id="mcps1.1.4.1.1"><p id="p13398252181816"><a name="p13398252181816"></a><a name="p13398252181816"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.1.4.1.2"><p id="p139825241814"><a name="p139825241814"></a><a name="p139825241814"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="65.35%" id="mcps1.1.4.1.3"><p id="p14398145251816"><a name="p14398145251816"></a><a name="p14398145251816"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1439818522182"><td class="cellrowborder" valign="top" width="15.160000000000002%" headers="mcps1.1.4.1.1 "><p id="p1052161193016"><a name="p1052161193016"></a><a name="p1052161193016"></a><strong id="b1124411121575"><a name="b1124411121575"></a><a name="b1124411121575"></a>placement</strong></p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.4.1.2 "><p id="p125201411133014"><a name="p125201411133014"></a><a name="p125201411133014"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="65.35%" headers="mcps1.1.4.1.3 "><p id="p65172113306"><a name="p65172113306"></a><a name="p65172113306"></a>需设置的数据地址的值。</p>
<p id="p184021035142712"><a name="p184021035142712"></a><a name="p184021035142712"></a>枚举值定义如下：</p>
<a name="screen13416130182913"></a><a name="screen13416130182913"></a><pre class="screen" codetype="Cpp" id="screen13416130182913">enum Placement {
  kPlacementHost = 0,   // host data addr
  kPlacementDevice = 1, // device data addr
};</pre>
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

