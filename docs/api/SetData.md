# SetData<a name="ZH-CN_TOPIC_0000002042368654"></a>

## 函数功能<a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_section36583473819"></a>

设置Tensor的数据。

## 函数原型<a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_section13230182415108"></a>

```
void SetData(TensorData &&data)
```

## 参数说明<a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_section75395119104"></a>

<a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p10223674448"><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p10223674448"></a><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p645511218169"><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p645511218169"></a><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p1922337124411"><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p1922337124411"></a><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p51918481213"><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p51918481213"></a><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p51918481213"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p191819441211"><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p191819441211"></a><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p16171244128"><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p16171244128"></a><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p16171244128"></a>需要设置的数据。</p>
<p id="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p1780194919218"><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p1780194919218"></a><a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_p1780194919218"></a>关于TensorData类型的定义，请参见<a href="TensorData.md">TensorData</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634184889_zh-cn_topic_0000001339391874_section320753512363"></a>

```
Tensor t{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape                
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format                
              kOnHost,                                // placement                
              ge::DT_FLOAT16,                              //dt                
              nullptr};
void *a = &t;
TensorData td(a, nullptr);
t.SetData(std::move(td));
```

