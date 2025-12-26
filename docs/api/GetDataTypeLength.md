# GetDataTypeLength<a name="ZH-CN_TOPIC_0000002078486533"></a>

## 函数功能<a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_section36583473819"></a>

获取数据类型所占内存大小。

使用该接口需要包含type\_utils.h头文件。

```
#include "graph/utils/type_utils.h"
```

## 函数原型<a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_section13230182415108"></a>

```
static bool GetDataTypeLength(const ge::DataType data_type, uint32_t &length)
```

## 参数说明<a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_section75395119104"></a>

<a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_row6223476444"><th class="cellrowborder" valign="top" width="17.2%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p10223674448"><a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p10223674448"></a><a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.36%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p645511218169"><a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p645511218169"></a><a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p1922337124411"><a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p1922337124411"></a><a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_row152234713443"><td class="cellrowborder" valign="top" width="17.2%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001787648310_p11254185411285"><a name="zh-cn_topic_0000001787648310_p11254185411285"></a><a name="zh-cn_topic_0000001787648310_p11254185411285"></a>data_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.36%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001787648310_p202531054192819"><a name="zh-cn_topic_0000001787648310_p202531054192819"></a><a name="zh-cn_topic_0000001787648310_p202531054192819"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001787648310_p72525546281"><a name="zh-cn_topic_0000001787648310_p72525546281"></a><a name="zh-cn_topic_0000001787648310_p72525546281"></a>数据类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001787648310_row58311349133419"><td class="cellrowborder" valign="top" width="17.2%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001787648310_p1383112492344"><a name="zh-cn_topic_0000001787648310_p1383112492344"></a><a name="zh-cn_topic_0000001787648310_p1383112492344"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="15.36%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001787648310_p2083114495342"><a name="zh-cn_topic_0000001787648310_p2083114495342"></a><a name="zh-cn_topic_0000001787648310_p2083114495342"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001787648310_p17831349203420"><a name="zh-cn_topic_0000001787648310_p17831349203420"></a><a name="zh-cn_topic_0000001787648310_p17831349203420"></a>数据类型所占内存大小，单位：字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_section25791320141317"></a>

获取成功时返回true；data\_type不支持时返回false。

## 约束说明<a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001787648310_zh-cn_topic_0000001389787301_section320753512363"></a>

```
uint32_t type_length;
ge::DataType data_type = ge::DT_INT8;
const bool ret = ge::TypeUtils::GetDataTypeLength(data_type, type_length); // type_length 1
if (!ret) {
  // ...
}
```

