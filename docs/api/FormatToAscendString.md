# FormatToAscendString<a name="ZH-CN_TOPIC_0000002078447905"></a>

## 函数功能<a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_section36583473819"></a>

将Format类型值转化为字符串表达。

使用该接口需要包含type\_utils.h头文件。

```
#include "graph/utils/type_utils.h"
```

## 函数原型<a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_section13230182415108"></a>

```
static AscendString FormatToAscendString(const Format &format)
```

## 参数说明<a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_section75395119104"></a>

<a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p10223674448"><a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p10223674448"></a><a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p645511218169"><a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p645511218169"></a><a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p1922337124411"><a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p1922337124411"></a><a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002040572492_p11254185411285"><a name="zh-cn_topic_0000002040572492_p11254185411285"></a><a name="zh-cn_topic_0000002040572492_p11254185411285"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002040572492_p202531054192819"><a name="zh-cn_topic_0000002040572492_p202531054192819"></a><a name="zh-cn_topic_0000002040572492_p202531054192819"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002040572492_p72525546281"><a name="zh-cn_topic_0000002040572492_p72525546281"></a><a name="zh-cn_topic_0000002040572492_p72525546281"></a>待转换的Format，支持的Format请参考<a href="Format.md">Format</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_section25791320141317"></a>

转换后的Format字符串，[AscendString](AscendString.md)类型。

## 约束说明<a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000002040572492_zh-cn_topic_0000001389787301_section320753512363"></a>

```
ge::Format format = ge::Format::FORMAT_NHWC;
auto format_str = ge::TypeUtils::FormatToAscendString(format);
const char *ptr = format_str.GetString();
```

