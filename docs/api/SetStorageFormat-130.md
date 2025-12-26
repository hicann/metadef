# SetStorageFormat<a name="ZH-CN_TOPIC_0000002518460609"></a>

## 函数功能<a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_section36583473819"></a>

设置运行时Tensor的数据格式。

## 函数原型<a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_section13230182415108"></a>

```
void SetStorageFormat(const ge::Format storage_format)
```

## 参数说明<a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_section75395119104"></a>

<a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_row6223476444"><th class="cellrowborder" valign="top" width="20.74%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p10223674448"><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p10223674448"></a><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.489999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p645511218169"><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p645511218169"></a><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="65.77%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p1922337124411"><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p1922337124411"></a><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_row152234713443"><td class="cellrowborder" valign="top" width="20.74%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p16748133312291"><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p16748133312291"></a><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p16748133312291"></a>storage_format</p>
</td>
<td class="cellrowborder" valign="top" width="13.489999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p143401361158"><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p143401361158"></a><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="65.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p56403992918"><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p56403992918"></a><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p56403992918"></a>运行时数据格式。</p>
<p id="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p51401841195815"><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p51401841195815"></a><a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_p51401841195815"></a>关于ge::Format类型的定义，请参见<a href="Format.md">Format</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_section25791320141317"></a>

无

## 约束说明<a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001633985561_zh-cn_topic_0000001339234242_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetOriginFormat(ge::FORMAT_NHWC);
t.SetStorageFormat(ge::FORMAT_NC1HWC0);
auto fmt = t.GetStorageFormat(); // ge::FORMAT_NC1HWC0
```

