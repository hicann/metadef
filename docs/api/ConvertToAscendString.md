# ConvertToAscendString<a name="ZH-CN_TOPIC_0000002079199921"></a>

## 函数功能<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section36893359"></a>

模板函数，接受一个模板参数T，并将其转换为AscendString类型。这个函数的主要功能是将不同类型的字符串转换为AscendString类型。

## 函数原型<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section136951948195410"></a>

```
template<typename T> ge::AscendString ConvertToAscendString(T str)
```

支持以下几种拓展：

-   template<\> inline ge::AscendString ConvertToAscendString<const char \*\>\(const char \*str\)

    对于const char \*类型的字符串，直接使用AscendString的构造函数进行转换。

-   template<\> inline ge::AscendString ConvertToAscendString<std::string\>\(std::string str\)

    对于std::string类型的字符串，先将其转换为const char \*类型，然后再进行转换。

-   template<\> inline ge::AscendString ConvertToAscendString<ge::AscendString\>\(ge::AscendString str\)

    对于AscendString类型的字符串，直接返回AscendString类型字符串。

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
<tbody><tr id="zh-cn_topic_0000001602064312_row56735883"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602064312_p2755144663518"><a name="zh-cn_topic_0000001602064312_p2755144663518"></a><a name="zh-cn_topic_0000001602064312_p2755144663518"></a>str</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602064312_p58370887"><a name="zh-cn_topic_0000001602064312_p58370887"></a><a name="zh-cn_topic_0000001602064312_p58370887"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602064312_p30421379"><a name="zh-cn_topic_0000001602064312_p30421379"></a><a name="zh-cn_topic_0000001602064312_p30421379"></a>待转换的字符串。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

转换后的AscendString类型字符串。

## 异常处理<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

