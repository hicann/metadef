# Malloc<a name="ZH-CN_TOPIC_0000001649901837"></a>

## 函数功能<a name="section3729174918713"></a>

在用户内存池中根据指定size大小申请device内存。

## 函数原型<a name="section84161445741"></a>

```
virtual MemBlock *Malloc(size_t size) = 0
```

## 参数说明<a name="zh-cn_topic_0182636394_section63604780"></a>

<a name="zh-cn_topic_0182636394_table47561922"></a>
<table><thead align="left"><tr id="zh-cn_topic_0182636394_row29169897"><th class="cellrowborder" valign="top" width="21.759999999999998%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0182636394_p13951479"><a name="zh-cn_topic_0182636394_p13951479"></a><a name="zh-cn_topic_0182636394_p13951479"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="24.81%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0182636394_p56327989"><a name="zh-cn_topic_0182636394_p56327989"></a><a name="zh-cn_topic_0182636394_p56327989"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="53.43%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0182636394_p66531170"><a name="zh-cn_topic_0182636394_p66531170"></a><a name="zh-cn_topic_0182636394_p66531170"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0182636394_row20315681"><td class="cellrowborder" valign="top" width="21.759999999999998%" headers="mcps1.1.4.1.1 "><p id="p766429183217"><a name="p766429183217"></a><a name="p766429183217"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="24.81%" headers="mcps1.1.4.1.2 "><p id="p1166317973216"><a name="p1166317973216"></a><a name="p1166317973216"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="53.43%" headers="mcps1.1.4.1.3 "><p id="p56621496323"><a name="p56621496323"></a><a name="p56621496323"></a>指定需要申请内存大小。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section413535858"></a>

返回[MemBlock](MemBlock.md)指针。

## 异常处理<a name="section1548781517515"></a>

无。

## 约束说明<a name="section2021419196520"></a>

纯虚函数用户必须实现。

