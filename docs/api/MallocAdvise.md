# MallocAdvise<a name="ZH-CN_TOPIC_0000001600616444"></a>

## 函数功能<a name="section3729174918713"></a>

在用户内存池中根据指定size大小申请device内存，建议申请的内存地址为addr。

## 函数原型<a name="section84161445741"></a>

```
virtual MemBlock *MallocAdvise(size_t size, void *addr)
```

## 参数说明<a name="zh-cn_topic_0182636394_section63604780"></a>

<a name="zh-cn_topic_0182636394_table47561922"></a>
<table><thead align="left"><tr id="zh-cn_topic_0182636394_row29169897"><th class="cellrowborder" valign="top" width="20.25%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0182636394_p13951479"><a name="zh-cn_topic_0182636394_p13951479"></a><a name="zh-cn_topic_0182636394_p13951479"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="21.36%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0182636394_p56327989"><a name="zh-cn_topic_0182636394_p56327989"></a><a name="zh-cn_topic_0182636394_p56327989"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="58.39%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0182636394_p66531170"><a name="zh-cn_topic_0182636394_p66531170"></a><a name="zh-cn_topic_0182636394_p66531170"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0182636394_row20315681"><td class="cellrowborder" valign="top" width="20.25%" headers="mcps1.1.4.1.1 "><p id="p766429183217"><a name="p766429183217"></a><a name="p766429183217"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="21.36%" headers="mcps1.1.4.1.2 "><p id="p1166317973216"><a name="p1166317973216"></a><a name="p1166317973216"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="58.39%" headers="mcps1.1.4.1.3 "><p id="p56621496323"><a name="p56621496323"></a><a name="p56621496323"></a>指定需要申请内存大小。</p>
</td>
</tr>
<tr id="row275173542018"><td class="cellrowborder" valign="top" width="20.25%" headers="mcps1.1.4.1.1 "><p id="p075143513202"><a name="p075143513202"></a><a name="p075143513202"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="21.36%" headers="mcps1.1.4.1.2 "><p id="p3751135102013"><a name="p3751135102013"></a><a name="p3751135102013"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="58.39%" headers="mcps1.1.4.1.3 "><p id="p1075183542016"><a name="p1075183542016"></a><a name="p1075183542016"></a>建议申请的内存地址为addr。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section413535858"></a>

返回[MemBlock](MemBlock.md)指针。

## 异常处理<a name="section1548781517515"></a>

无。

## 约束说明<a name="section2021419196520"></a>

虚函数需要用户实现，如若未实现，默认同[Malloc](Malloc.md)功能相同。

