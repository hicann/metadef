# SetShapeRange<a name="ZH-CN_TOPIC_0000001265080966"></a>

## 函数功能<a name="section48806003"></a>

设置shape的变化范围。

## 函数原型<a name="section413831542619"></a>

```
graphStatus SetShapeRange(const std::vector<std::pair<int64_t,int64_t>> &range)
```

## 参数说明<a name="section36600850"></a>

<a name="table10309404"></a>
<table><thead align="left"><tr id="row47530006"><th class="cellrowborder" valign="top" width="13.15%" id="mcps1.1.4.1.1"><p id="p24725298"><a name="p24725298"></a><a name="p24725298"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="15.299999999999999%" id="mcps1.1.4.1.2"><p id="p56592155"><a name="p56592155"></a><a name="p56592155"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="71.55%" id="mcps1.1.4.1.3"><p id="p54897010"><a name="p54897010"></a><a name="p54897010"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row17472816"><td class="cellrowborder" valign="top" width="13.15%" headers="mcps1.1.4.1.1 "><p id="p6011995"><a name="p6011995"></a><a name="p6011995"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="15.299999999999999%" headers="mcps1.1.4.1.2 "><p id="p17209562"><a name="p17209562"></a><a name="p17209562"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="71.55%" headers="mcps1.1.4.1.3 "><p id="p34829302"><a name="p34829302"></a><a name="p34829302"></a>shape代表的变化范围。vector中的每一个元素为一个pair，pair的第一个值为该维度上的dim最小值，第二个值为该维度上dim的最大值。举例如下：</p>
<p id="p157251940121117"><a name="p157251940121117"></a><a name="p157251940121117"></a>该tensor的shape为{1,1,-1,2}，第三个轴的最大值为100，则range可设置为{{1,1},{1,1},{1,100},{2,2}}。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section60972199"></a>

graphStatus类型：若成功，则该值为GRAPH\_SUCCESS\(即0\)，其他值则为执行失败。

## 异常处理<a name="section11878883"></a>

无。

## 约束说明<a name="section39801087"></a>

无。

