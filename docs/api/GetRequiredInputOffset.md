# GetRequiredInputOffset<a name="ZH-CN_TOPIC_0000002519126115"></a>

## 函数功能<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的必选输入Tensor的offset。

>![](public_sys-resources/icon-note.gif) **说明：** 
>该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

## 函数原型<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section13230182415108"></a>

```
int64_t GetRequiredInputOffset(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section75395119104"></a>

<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p10223674448"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p10223674448"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p645511218169"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p645511218169"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p1922337124411"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p1922337124411"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p2340183613156"><a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p2340183613156"></a><a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"><a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"></a><a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p131917964515"><a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p131917964515"></a><a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p131917964515"></a>必选输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section25791320141317"></a>

指定的输入Tensor的offset。当输入ir\_index非法或Tensor不携带非连续描述信息时，返回-1。

## 约束说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section320753512363"></a>

```
ge::graphStatus TilingForMul(TilingContext *context) {
  auto required_input_offset_0 = context->GetRequiredInputOffset(0);
  ...
}
```

