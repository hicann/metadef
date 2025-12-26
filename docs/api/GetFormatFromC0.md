# GetFormatFromC0<a name="ZH-CN_TOPIC_0000001601747312"></a>

## 函数功能<a name="section8062655"></a>

根据传入的format和C0 format信息得到实际的format。

实际format为4字节大小，第1个字节的高四位为预留字段，低四位为C0 format，第2-3字节为子format信息，第4字节为主format信息，如下：

/\*

\* ---------------------------------------------------

\* |     4bits     |      4bits    |        2bytes    | 1byte  |

\* |------------|------------|----------------|--------|

\* |  reserved  | C0 format |   Sub format | format |

\* ---------------------------------------------------

\*/

## 函数原型<a name="section5455038"></a>

```
inline int32_t GetFormatFromC0(int32_t format, int32_t c0_format)
```

## 参数说明<a name="section49095346"></a>

<a name="table62441623"></a>
<table><thead align="left"><tr id="row47897641"><th class="cellrowborder" valign="top" width="19.26192619261926%" id="mcps1.1.4.1.1"><p id="p54503731"><a name="p54503731"></a><a name="p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.111811181118114%" id="mcps1.1.4.1.2"><p id="p52726081"><a name="p52726081"></a><a name="p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="62.626262626262616%" id="mcps1.1.4.1.3"><p id="p42954172"><a name="p42954172"></a><a name="p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row186489437249"><td class="cellrowborder" valign="top" width="19.26192619261926%" headers="mcps1.1.4.1.1 "><p id="p1954714186111"><a name="p1954714186111"></a><a name="p1954714186111"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="18.111811181118114%" headers="mcps1.1.4.1.2 "><p id="p1454621851114"><a name="p1454621851114"></a><a name="p1454621851114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="62.626262626262616%" headers="mcps1.1.4.1.3 "><p id="p3545318191116"><a name="p3545318191116"></a><a name="p3545318191116"></a>子format与主format信息，值不超过0xffffffU。</p>
</td>
</tr>
<tr id="row56735883"><td class="cellrowborder" valign="top" width="19.26192619261926%" headers="mcps1.1.4.1.1 "><p id="p4157636192619"><a name="p4157636192619"></a><a name="p4157636192619"></a>c0_format</p>
</td>
<td class="cellrowborder" valign="top" width="18.111811181118114%" headers="mcps1.1.4.1.2 "><p id="p141491616399"><a name="p141491616399"></a><a name="p141491616399"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="62.626262626262616%" headers="mcps1.1.4.1.3 "><p id="p7149260394"><a name="p7149260394"></a><a name="p7149260394"></a>C0 format信息，值不超过0xfU。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

指定的format和c0\_format对应的实际format。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

