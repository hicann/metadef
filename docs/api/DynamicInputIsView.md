# DynamicInputIsView<a name="ZH-CN_TOPIC_0000002519046123"></a>

## 函数功能<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入Tensor是否携带非连续描述信息。

>![](public_sys-resources/icon-note.gif) **说明：** 
>该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

## 函数原型<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section13230182415108"></a>

```
bool DynamicInputIsView(const size_t ir_index, const size_t relative_index) const
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
<tbody><tr id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p3943172167"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p3943172167"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p3943172167"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p15663137127"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p15663137127"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p15663137127"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
<tr id="row9601165571515"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p7431152163717"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p7431152163717"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p7431152163717"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1543292143715"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1543292143715"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1543292143715"></a>该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的有效范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section25791320141317"></a>

返回指定ir\_index的输入Tensor是否携带非连续描述信息：

-   true：指定ir\_index的输入Tensor携带非连续描述信息。
-   false：输入ir\_index非法或该INPUT没有实例化或该Tensor未携带非连续描述信息。

## 约束说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section320753512363"></a>

```
ge::graphStatus TilingForMul(TilingContext *context) {
  bool dynamic_input_is_view_0 = context->DynamicInputIsView(0);
  ...
}
```

