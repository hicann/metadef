# GetDynamicInputShape<a name="ZH-CN_TOPIC_0000002343618001"></a>

## 函数功能<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入Shape指针。

## 函数原型<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section13230182415108"></a>

```
const Shape *GetDynamicInputShape(const size_t ir_index, const size_t relative_index) const
```

## 参数说明<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section75395119104"></a>

<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p3943172167"><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p3943172167"></a><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p3943172167"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p143401361158"><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p143401361158"></a><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"></a><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"></a>动态输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
<tr id="row687018573910"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p131381713143914"><a name="p131381713143914"></a><a name="p131381713143914"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p8870185203920"><a name="p8870185203920"></a><a name="p8870185203920"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p118422963915"><a name="p118422963915"></a><a name="p118422963915"></a>该输入实例化后的相对index，例如某个动态输入实例化了3个输入，那么relative_index的有效范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section25791320141317"></a>

输入Shape指针，ir\_index或relative\_index非法时，返回空指针。

关于Shape类型的定义，请参见[Shape](Shape.md)。

## 调用示例<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto shape= context->GetDynamicInputShape(1U, 0U); 
  GE_ASSERT_NOTNULL(shape);
  // ...
}
```

