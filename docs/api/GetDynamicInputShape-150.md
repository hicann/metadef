# GetDynamicInputShape<a name="ZH-CN_TOPIC_0000002042526798"></a>

## 函数功能<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入shape指针。

## 函数原型<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section13230182415108"></a>

**const StorageShape \*GetDynamicInputShape\(const size\_t ir\_index, const size\_t relative\_index\) const**

## 参数说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section75395119104"></a>

<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p10223674448"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p10223674448"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p645511218169"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p645511218169"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1922337124411"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1922337124411"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p2340183613156"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p2340183613156"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p88767238815"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p88767238815"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p88767238815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p131917964515"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p131917964515"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p131917964515"></a>动态输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_row55408581278"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p11541175810712"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p11541175810712"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p11541175810712"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1154185811713"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1154185811713"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p1154185811713"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p201910915458"><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p201910915458"></a><a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_p201910915458"></a>该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的取值范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section25791320141317"></a>

指定的输入shape指针，shape中包含了原始shape与运行时shape。关于StorageShape类型的定义，请参见[StorageShape](StorageShape.md)。

当输入ir\_index或relative\_index非法时，返回空指针。

## 约束说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section320753512363"></a>

```
ge::graphStatus InferShape4ConcatD(TilingContext* context) {
  auto in_shape = context->GetDynamicInputShape(dynamic_input_idx, 0);
  ...
}
```

