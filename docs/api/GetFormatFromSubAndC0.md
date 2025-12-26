# GetFormatFromSubAndC0<a name="ZH-CN_TOPIC_0000001602066728"></a>

## 函数功能<a name="section8062655"></a>

根据传入的主format，子format和C0 format信息得到实际的format。

实际format为4字节大小，第1个字节的高四位为预留字段，低四位为C0 format，第2-3字节为子format信息，第4字节为主format信息，如下：

/\*

\* ---------------------------------------------------

\* |     4bits    |      4bits      |        2bytes    | 1byte  |

\* |------------|-------------|----------------|--------|

\* |  reserved  | C0 format |   Sub format   | format |

\* ---------------------------------------------------

\*/

## 函数原型<a name="section5455038"></a>

```
inline int32_t GetFormatFromSubAndC0(int32_t primary_format, int32_t sub_format, int32_t c0_format)
```

## 参数说明<a name="section49095346"></a>

<a name="table62441623"></a>
<table><thead align="left"><tr id="row47897641"><th class="cellrowborder" valign="top" width="19.69196919691969%" id="mcps1.1.4.1.1"><p id="p54503731"><a name="p54503731"></a><a name="p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="20.862086208620862%" id="mcps1.1.4.1.2"><p id="p52726081"><a name="p52726081"></a><a name="p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="59.445944594459455%" id="mcps1.1.4.1.3"><p id="p42954172"><a name="p42954172"></a><a name="p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row56735883"><td class="cellrowborder" valign="top" width="19.69196919691969%" headers="mcps1.1.4.1.1 "><p id="p291520328293"><a name="p291520328293"></a><a name="p291520328293"></a>primary_format</p>
</td>
<td class="cellrowborder" valign="top" width="20.862086208620862%" headers="mcps1.1.4.1.2 "><p id="p791433272912"><a name="p791433272912"></a><a name="p791433272912"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="59.445944594459455%" headers="mcps1.1.4.1.3 "><p id="p3545318191116"><a name="p3545318191116"></a><a name="p3545318191116"></a>主format信息，值不超过0xffU。</p>
</td>
</tr>
<tr id="row14805338102918"><td class="cellrowborder" valign="top" width="19.69196919691969%" headers="mcps1.1.4.1.1 "><p id="p38054383298"><a name="p38054383298"></a><a name="p38054383298"></a>sub_format</p>
</td>
<td class="cellrowborder" valign="top" width="20.862086208620862%" headers="mcps1.1.4.1.2 "><p id="p24451956202913"><a name="p24451956202913"></a><a name="p24451956202913"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="59.445944594459455%" headers="mcps1.1.4.1.3 "><p id="p7149260394"><a name="p7149260394"></a><a name="p7149260394"></a>子format信息，值不超过0xffffU。</p>
</td>
</tr>
<tr id="row713310364297"><td class="cellrowborder" valign="top" width="19.69196919691969%" headers="mcps1.1.4.1.1 "><p id="p20133936162912"><a name="p20133936162912"></a><a name="p20133936162912"></a>c0_format</p>
</td>
<td class="cellrowborder" valign="top" width="20.862086208620862%" headers="mcps1.1.4.1.2 "><p id="p132445792919"><a name="p132445792919"></a><a name="p132445792919"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="59.445944594459455%" headers="mcps1.1.4.1.3 "><p id="p13133936192920"><a name="p13133936192920"></a><a name="p13133936192920"></a>C0 format信息，值不超过0xfU。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

指定的primary\_format、sub\_format和c0\_format对应的实际format。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

