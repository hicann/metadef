# AscendStringToDataType<a name="ZH-CN_TOPIC_0000002078486521"></a>

## 函数功能<a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_section36583473819"></a>

将DataType字符串表达转化为DataType类型值。

使用该接口需要包含type\_utils.h头文件。

```
#include "graph/utils/type_utils.h"
```

## 函数原型<a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_section13230182415108"></a>

```
static DataType AscendStringToDataType(const AscendString &str)
```

## 参数说明<a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_section75395119104"></a>

<a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p10223674448"><a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p10223674448"></a><a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p645511218169"><a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p645511218169"></a><a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p1922337124411"><a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p1922337124411"></a><a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002076811593_p11254185411285"><a name="zh-cn_topic_0000002076811593_p11254185411285"></a><a name="zh-cn_topic_0000002076811593_p11254185411285"></a>str</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002076811593_p202531054192819"><a name="zh-cn_topic_0000002076811593_p202531054192819"></a><a name="zh-cn_topic_0000002076811593_p202531054192819"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002076811593_p72525546281"><a name="zh-cn_topic_0000002076811593_p72525546281"></a><a name="zh-cn_topic_0000002076811593_p72525546281"></a>待转换的DataType字符串形式，<a href="AscendString.md">AscendString</a>类型。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_section25791320141317"></a>

输入合法时，返回转换后的DataType enum值，枚举定义请参考[DataType](DataType.md)；输入不合法时，返回DT\_UNDEFINED并打印报错日志。

## 约束说明<a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000002076811593_zh-cn_topic_0000001389787301_section320753512363"></a>

```
ge::AscendString type_str("DT_UINT32");
auto data_type = ge::TypeUtils::AscendStringToDataType(type_str); // 8
```

