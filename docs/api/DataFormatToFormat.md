# DataFormatToFormat<a name="ZH-CN_TOPIC_0000002042368842"></a>

## 函数功能<a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_section36583473819"></a>

将数据格式字符串转化为Format类型值。

使用该接口需要包含type\_utils.h头文件。

```
#include "graph/utils/type_utils.h"
```

## 函数原型<a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_section13230182415108"></a>

```
static Format DataFormatToFormat(const AscendString &str)
static Format DataFormatToFormat(const std::string &str)
```

## 参数说明<a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_section75395119104"></a>

<a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_row6223476444"><th class="cellrowborder" valign="top" width="17.2%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p10223674448"><a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p10223674448"></a><a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.36%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p645511218169"><a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p645511218169"></a><a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p1922337124411"><a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p1922337124411"></a><a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_row152234713443"><td class="cellrowborder" valign="top" width="17.2%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001787648306_p11254185411285"><a name="zh-cn_topic_0000001787648306_p11254185411285"></a><a name="zh-cn_topic_0000001787648306_p11254185411285"></a>str</p>
</td>
<td class="cellrowborder" valign="top" width="15.36%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001787648306_p202531054192819"><a name="zh-cn_topic_0000001787648306_p202531054192819"></a><a name="zh-cn_topic_0000001787648306_p202531054192819"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001787648306_p72525546281"><a name="zh-cn_topic_0000001787648306_p72525546281"></a><a name="zh-cn_topic_0000001787648306_p72525546281"></a>待转换的Format字符串形式。</p>
<p id="p171447174188"><a name="p171447174188"></a><a name="p171447174188"></a>从GCC 5.1版本开始，libstdc++为了更好的实现C++11规范，更改了std::string和std::list的一些接口，导致新老版本ABI不兼容。所以推荐使用入参为<strong id="b20545223191811"><a name="b20545223191811"></a><a name="b20545223191811"></a>AscendString</strong>类型的接口。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_section25791320141317"></a>

输入合法时，返回转换后的Format enum值，枚举定义请参考[Format](Format.md)，仅支持部分格式，详见[约束说明](#zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_section19165124931511)；输入不合法时，返回FORMAT\_RESERVED，并打印报错信息。

## 约束说明<a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_section19165124931511"></a>

只支持以下几种格式：

"NCHW": FORMAT\_NCHW

"NHWC": FORMAT\_NHWC

"NDHWC": FORMAT\_NDHWC

"NCDHW": FORMAT\_NCDHW

"ND": FORMAT\_ND

## 调用示例<a name="zh-cn_topic_0000001787648306_zh-cn_topic_0000001389787301_section320753512363"></a>

```
// 如果使用的是AscendString入参的接口(建议使用)
ge::AscendString format_str = "NHWC";
auto format = ge::TypeUtils::DataFormatToFormat(format_str); // 1

// 如果使用的是std:string入参的接口(不建议使用)
std::string format_str = "NHWC";
auto format = ge::TypeUtils::DataFormatToFormat(format_str); // 1
```

