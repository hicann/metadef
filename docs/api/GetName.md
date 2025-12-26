# GetName<a name="ZH-CN_TOPIC_0000001312720957"></a>

## 函数功能<a name="section9203174713160"></a>

获取TensorDesc所描述Tensor的名称。

## 函数原型<a name="section19546162911159"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
std::string GetName() const
graphStatus GetName(AscendString &name)
graphStatus GetName(AscendString &name) const
```

## 参数说明<a name="section13183157161610"></a>

<a name="table34019058"></a>
<table><thead align="left"><tr id="row16856419"><th class="cellrowborder" valign="top" width="21.83%" id="mcps1.1.4.1.1"><p id="p23192694"><a name="p23192694"></a><a name="p23192694"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="24.2%" id="mcps1.1.4.1.2"><p id="p66668934"><a name="p66668934"></a><a name="p66668934"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="53.97%" id="mcps1.1.4.1.3"><p id="p66410939"><a name="p66410939"></a><a name="p66410939"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row10576944"><td class="cellrowborder" valign="top" width="21.83%" headers="mcps1.1.4.1.1 "><p id="p51426113"><a name="p51426113"></a><a name="p51426113"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="24.2%" headers="mcps1.1.4.1.2 "><p id="p4765656"><a name="p4765656"></a><a name="p4765656"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="53.97%" headers="mcps1.1.4.1.3 "><p id="p61847473"><a name="p61847473"></a><a name="p61847473"></a>算子名称。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section1598675141718"></a>

graphStatus类型：获取name成功，返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理<a name="section67066196172"></a>

无。

## 约束说明<a name="section244552231716"></a>

无。

