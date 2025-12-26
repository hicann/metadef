# SetPlacement<a name="ZH-CN_TOPIC_0000002518460613"></a>

## 函数功能<a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_section36583473819"></a>

设置Tensor的placement。

## 函数原型<a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_section13230182415108"></a>

```
void SetPlacement(const TensorPlacement placement)
```

## 参数说明<a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_section75395119104"></a>

<a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p10223674448"><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p10223674448"></a><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p645511218169"><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p645511218169"></a><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p1922337124411"><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p1922337124411"></a><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p16278151404615"><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p16278151404615"></a><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p16278151404615"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p143401361158"><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p143401361158"></a><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p1394614720462"><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p1394614720462"></a><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p1394614720462"></a>需要设置的Tensor的placement。</p>
<p id="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p336665813247"><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p336665813247"></a><a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_p336665813247"></a>关于TensorPlacement类型的定义，请参见<a href="TensorPlacement.md">TensorPlacement</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_section25791320141317"></a>

无

## 约束说明<a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001633985565_zh-cn_topic_0000001339234246_section320753512363"></a>

```
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape              
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format              
                kFollowing,                                  // placement              
                ge::DT_FLOAT16,                              //dt              
                nullptr};
tensor.SetPlacement(TensorPlacement::kOnHost);
auto placement = tensor.GetPlacement();
```

