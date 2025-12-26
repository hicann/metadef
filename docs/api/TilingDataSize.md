# TilingDataSize<a name="ZH-CN_TOPIC_0000002450765882"></a>

## 函数功能<a name="zh-cn_topic_0000002420158756_zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section36583473819"></a>

设置算子TilingData的大小, 设置该大小后，会申请相应大小的内存用于存储算子的TilingData。相较于[TilingData](TilingData.md)，调用此接口时生成的TilingData指针所有权归属ContextHolder，调用者无需关注TilingData的生命周期。

注意该接口与TilingData互斥，如果同时调用TilingDataSize和TilingData接口，后调用的接口会覆盖前一次调用的结果，以最新的为准。

## 函数原型<a name="zh-cn_topic_0000002420158756_zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section13230182415108"></a>

```
OpTilingContextBuilder &TilingDataSize(size_t tiling_data_size)
```

## 参数说明<a name="zh-cn_topic_0000002420158756_zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section75395119104"></a>

<a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p10223674448"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p10223674448"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p645511218169"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p645511218169"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p1922337124411"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p1922337124411"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p482415353010"><a name="p482415353010"></a><a name="p482415353010"></a>tiling_data_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p19981125717012"><a name="p19981125717012"></a><a name="p19981125717012"></a>Tiling数据大小。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002420158756_zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section25791320141317"></a>

TilingContextBuilder对象用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002420158756_zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section19165124931511"></a>

在调用Build方法之前，必须设置TilingData或TilingDataSize，否则构造出的TilingContext将包含未定义数据。

