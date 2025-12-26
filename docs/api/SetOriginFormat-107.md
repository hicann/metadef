# SetOriginFormat<a name="ZH-CN_TOPIC_0000002042526974"></a>

## 函数功能<a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_section36583473819"></a>

设置Tensor的原始format。

## 函数原型<a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_section13230182415108"></a>

**void SetOriginFormat\(const ge::Format origin\_format\)**

## 参数说明<a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_section75395119104"></a>

<a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p10223674448"><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p10223674448"></a><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p645511218169"><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p645511218169"></a><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p1922337124411"><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p1922337124411"></a><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p2340183613156"><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p2340183613156"></a><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p2340183613156"></a>origin_format</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p143401361158"><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p143401361158"></a><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p19544204917121"><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p19544204917121"></a><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p19544204917121"></a>原始format。</p>
<p id="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p5407917105"><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p5407917105"></a><a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_p5407917105"></a>关于ge::Format类型的定义，请参见<a href="Format.md">Format</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001583865630_zh-cn_topic_0000001389833809_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetOriginFormat(ge::FORMAT_NHWC);
t.SetStorageFormat(ge::FORMAT_NC1HWC0);
auto fmt = t.GetOriginFormat(); // ge::FORMAT_NHWC
```

