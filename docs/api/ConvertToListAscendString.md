# ConvertToListAscendString<a name="ZH-CN_TOPIC_0000002080651969"></a>

## 函数功能<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section36893359"></a>

定义了一个模板函数ConvertToListAscendString，用于将不同类型的字符串列表转换为AscendString类型的列表。

## 函数原型<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section136951948195410"></a>

```
template<typename T> std::vector<ge::AscendString> ConvertToListAscendString(T strs)
```

支持以下两种拓展：

-   template<\> inline std::vector<ge::AscendString\> ConvertToListAscendString\(std::vector<std::string\> strs\)

    对于std::vectorstd::string类型的字符串列表，先将其转换为std::vector<const char \*\>类型，然后再进行转换。

-   template<\> inline std::vector<ge::AscendString\> ConvertToListAscendString\(std::vector<ge::AscendString\> strs\)

    对于std::vector<ge::AscendString\>类型的字符串列表，直接返回原列表。

## 参数说明<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section63604780"></a>

<a name="zh-cn_topic_0000001602064312_table62441623"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001602064312_row47897641"><th class="cellrowborder" valign="top" width="24.782478247824784%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001602064312_p54503731"><a name="zh-cn_topic_0000001602064312_p54503731"></a><a name="zh-cn_topic_0000001602064312_p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="26.882688268826882%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001602064312_p52726081"><a name="zh-cn_topic_0000001602064312_p52726081"></a><a name="zh-cn_topic_0000001602064312_p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="48.33483348334833%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001602064312_p42954172"><a name="zh-cn_topic_0000001602064312_p42954172"></a><a name="zh-cn_topic_0000001602064312_p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001602064312_row56735883"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602064312_p2755144663518"><a name="zh-cn_topic_0000001602064312_p2755144663518"></a><a name="zh-cn_topic_0000001602064312_p2755144663518"></a>strs</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602064312_p58370887"><a name="zh-cn_topic_0000001602064312_p58370887"></a><a name="zh-cn_topic_0000001602064312_p58370887"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602064312_p30421379"><a name="zh-cn_topic_0000001602064312_p30421379"></a><a name="zh-cn_topic_0000001602064312_p30421379"></a>待转换的字符串列表。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

转换后的AscendString类型字符串列表。

## 异常处理<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

