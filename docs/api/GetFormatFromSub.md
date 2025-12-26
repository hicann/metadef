# GetFormatFromSub<a name="ZH-CN_TOPIC_0000001312399925"></a>

## 函数功能<a name="section8062655"></a>

根据传入的主format和子format信息得到实际的format。

实际format为4字节大小，第1个字节的高四位为预留字段，低四位为C0 format，第2-3字节为子format信息，第4字节为主format信息，如下：

/\*

\* ---------------------------------------------------

\* |     4bits     |      4bits    |        2bytes     | 1byte  |

\* |------------|------------|----------------|--------|

\* |  reserved  | C0 format |   Sub format | format |

\* ---------------------------------------------------

\*/

## 函数原型<a name="section5455038"></a>

```
inline int32_t GetFormatFromSub(int32_t primary_format, int32_t sub_format)
```

## 参数说明<a name="section49095346"></a>

<a name="table62441623"></a>
<table><thead align="left"><tr id="row47897641"><th class="cellrowborder" valign="top" width="20.8020802080208%" id="mcps1.1.4.1.1"><p id="p54503731"><a name="p54503731"></a><a name="p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.201820182018203%" id="mcps1.1.4.1.2"><p id="p52726081"><a name="p52726081"></a><a name="p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="60.99609960996099%" id="mcps1.1.4.1.3"><p id="p42954172"><a name="p42954172"></a><a name="p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row56735883"><td class="cellrowborder" valign="top" width="20.8020802080208%" headers="mcps1.1.4.1.1 "><p id="p1954714186111"><a name="p1954714186111"></a><a name="p1954714186111"></a>primary_format</p>
</td>
<td class="cellrowborder" valign="top" width="18.201820182018203%" headers="mcps1.1.4.1.2 "><p id="p1454621851114"><a name="p1454621851114"></a><a name="p1454621851114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="60.99609960996099%" headers="mcps1.1.4.1.3 "><p id="p3545318191116"><a name="p3545318191116"></a><a name="p3545318191116"></a>主format信息，值不超过0xffU。</p>
</td>
</tr>
<tr id="row2149136113914"><td class="cellrowborder" valign="top" width="20.8020802080208%" headers="mcps1.1.4.1.1 "><p id="p91496616391"><a name="p91496616391"></a><a name="p91496616391"></a>sub_format</p>
</td>
<td class="cellrowborder" valign="top" width="18.201820182018203%" headers="mcps1.1.4.1.2 "><p id="p141491616399"><a name="p141491616399"></a><a name="p141491616399"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="60.99609960996099%" headers="mcps1.1.4.1.3 "><p id="p7149260394"><a name="p7149260394"></a><a name="p7149260394"></a>子format信息，值不超过0xffffU。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

指定的主format和子format对应的实际format。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

