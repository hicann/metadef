# Free<a name="ZH-CN_TOPIC_0000001600776156"></a>

## 函数功能<a name="section3729174918713"></a>

根据指定的MemBlock释放内存到内存池。

## 函数原型<a name="section84161445741"></a>

```
virtual void Free(MemBlock *block) = 0
```

## 参数说明<a name="zh-cn_topic_0182636394_section63604780"></a>

<a name="zh-cn_topic_0182636394_table47561922"></a>
<table><thead align="left"><tr id="zh-cn_topic_0182636394_row29169897"><th class="cellrowborder" valign="top" width="20.59%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0182636394_p13951479"><a name="zh-cn_topic_0182636394_p13951479"></a><a name="zh-cn_topic_0182636394_p13951479"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="21.78%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0182636394_p56327989"><a name="zh-cn_topic_0182636394_p56327989"></a><a name="zh-cn_topic_0182636394_p56327989"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="57.63%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0182636394_p66531170"><a name="zh-cn_topic_0182636394_p66531170"></a><a name="zh-cn_topic_0182636394_p66531170"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0182636394_row20315681"><td class="cellrowborder" valign="top" width="20.59%" headers="mcps1.1.4.1.1 "><p id="p766429183217"><a name="p766429183217"></a><a name="p766429183217"></a>block</p>
</td>
<td class="cellrowborder" valign="top" width="21.78%" headers="mcps1.1.4.1.2 "><p id="p1166317973216"><a name="p1166317973216"></a><a name="p1166317973216"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.63%" headers="mcps1.1.4.1.3 "><p id="p56621496323"><a name="p56621496323"></a><a name="p56621496323"></a>内存block指针。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section413535858"></a>

无。

## 异常处理<a name="section1548781517515"></a>

无。

## 约束说明<a name="section2021419196520"></a>

纯虚函数用户必须实现。

