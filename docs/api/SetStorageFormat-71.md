# SetStorageFormat<a name="ZH-CN_TOPIC_0000002042368754"></a>

## 函数功能<a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_section36583473819"></a>

设置运行时format。

## 函数原型<a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_section13230182415108"></a>

```
void SetStorageFormat(const ge::Format storage_format)
```

## 参数说明<a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_section75395119104"></a>

<a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p10223674448"><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p10223674448"></a><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p645511218169"><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p645511218169"></a><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p1922337124411"><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p1922337124411"></a><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p44560512817"><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p44560512817"></a><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p44560512817"></a>storage_format</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p191819441211"><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p191819441211"></a><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p2045541414350"><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p2045541414350"></a><a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_p2045541414350"></a>运行时format。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635304929_zh-cn_topic_0000001390090413_section320753512363"></a>

```
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
format.SetStorageFormat(ge::Format::FORMAT_NC);
```

