# TilingParse<a name="ZH-CN_TOPIC_0000002078486541"></a>

## 函数功能<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_section36583473819"></a>

注册算子的TilingParse函数，用于解析算子编译阶段生成的算子信息JSON文件，在注册时需要注册算子自行指定数据类型T，该数据类型用于保存解析后的算子信息。

用户需要为算子编写一个KernelFunc类型或者TilingParseFunc类型的函数，并使用下列对应的接口进行注册。

KernelFunc类型定义如下：

```
using KernelFunc = UINT32 (*)(KernelContext *context);
```

TilingParseFunc类型定义如下：

```
using TilingParseFunc = UINT32 (*)(TilingParseContext *context);
```

## 函数原型<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_section13230182415108"></a>

```
template<typename T>
OpImplRegisterV2 &TilingParse(KernelFunc const tiling_parse_func)
template<typename T>
OpImplRegisterV2 &TilingParse(TilingParseFunc const tiling_parse_func)
```

## 参数说明<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_section5945162084"></a>

<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p10223674448"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p10223674448"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p645511218169"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p645511218169"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p1922337124411"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p1922337124411"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_row1714012111413"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p10140102110413"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p10140102110413"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p10140102110413"></a>tiling_parse_func</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p614032194111"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p614032194111"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p614032194111"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p214020215413"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p214020215413"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p214020215413"></a>待注册的TilingParse函数，类型支持2种：KernelFunc、TilingParseFunc。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了TilingParse函数。

## 约束说明<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_section19165124931511"></a>

无。

