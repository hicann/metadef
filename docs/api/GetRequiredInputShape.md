# GetRequiredInputShape<a name="ZH-CN_TOPIC_0000002309618938"></a>

## 函数功能<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的必选输入Shape指针。

## 函数原型<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section13230182415108"></a>

```
const Shape *GetRequiredInputShape(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section75395119104"></a>

<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p10223674448"><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p10223674448"></a><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p645511218169"><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p645511218169"></a><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p1922337124411"><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p1922337124411"></a><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p47512024373"><a name="p47512024373"></a><a name="p47512024373"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p320343694214"><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p320343694214"></a><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p118621512143718"><a name="p118621512143718"></a><a name="p118621512143718"></a>IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section25791320141317"></a>

输入Shape指针，ir\_index非法时，返回空指针。

关于Shape类型的定义，请参见[Shape](Shape.md)。

## 调用示例<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto shape= context->GetRequiredInputShape(0);        // 获取第0个输入的shape
  GE_ASSERT_NOTNULL(shape);
  // ...
}
```

