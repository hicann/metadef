# HasSubFormat<a name="ZH-CN_TOPIC_0000001265240906"></a>

## 函数功能<a name="section8062655"></a>

判断实际format中是否包含子format。

## 函数原型<a name="section5455038"></a>

```
inline bool HasSubFormat(int32_t format)
```

## 参数说明<a name="section49095346"></a>

<a name="table62441623"></a>
<table><thead align="left"><tr id="row47897641"><th class="cellrowborder" valign="top" width="15.661566156615661%" id="mcps1.1.4.1.1"><p id="p54503731"><a name="p54503731"></a><a name="p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16.13161316131613%" id="mcps1.1.4.1.2"><p id="p52726081"><a name="p52726081"></a><a name="p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="68.20682068206821%" id="mcps1.1.4.1.3"><p id="p42954172"><a name="p42954172"></a><a name="p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row56735883"><td class="cellrowborder" valign="top" width="15.661566156615661%" headers="mcps1.1.4.1.1 "><p id="p1954714186111"><a name="p1954714186111"></a><a name="p1954714186111"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="16.13161316131613%" headers="mcps1.1.4.1.2 "><p id="p1454621851114"><a name="p1454621851114"></a><a name="p1454621851114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="68.20682068206821%" headers="mcps1.1.4.1.3 "><p id="p3545318191116"><a name="p3545318191116"></a><a name="p3545318191116"></a>实际format（4字节大小，第1个字节的高四位为预留字段，低四位为C0 format，第2-3字节为子format信息，第4字节为主format信息）。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

-   true：实际format中包含子format。
-   false：实际format中不包含子format。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

