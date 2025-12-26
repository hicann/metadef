# GetRequiredInputFormat<a name="ZH-CN_TOPIC_0000002309618902"></a>

## 函数功能<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的必选输入Format指针。

## 函数原型<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section13230182415108"></a>

```
StorageFormat *GetRequiredInputFormat(const size_t ir_index)
```

## 参数说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section75395119104"></a>

<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.329999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.45%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2340183613156"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2340183613156"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.45%" headers="mcps1.1.4.1.3 "><p id="p83481219273"><a name="p83481219273"></a><a name="p83481219273"></a>IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section25791320141317"></a>

输入Format指针，ir\_index非法时，返回空指针。

关于StorageFormat类型的定义，请参见[StorageFormat](StorageFormat.md)。

## 约束说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto format = context->GetRequiredInputFormat(0);        // 获取第0个输入的format
  GE_ASSERT_NOTNULL(format);
  // ...
}
```

