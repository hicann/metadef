# GetDynamicInputShape<a name="ZH-CN_TOPIC_0000002078486221"></a>

## 函数功能<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入shape指针。

## 函数原型<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section13230182415108"></a>

```
const Shape *GetDynamicInputShape(const size_t ir_index, const size_t relative_index) const
```

## 参数说明<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section75395119104"></a>

<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_row6223476444"><th class="cellrowborder" valign="top" width="18.38%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p10223674448"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p10223674448"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p645511218169"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p645511218169"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.77%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p1922337124411"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p1922337124411"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_row152234713443"><td class="cellrowborder" valign="top" width="18.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p2340183613156"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p2340183613156"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p143401361158"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p143401361158"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p131917964515"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p131917964515"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p131917964515"></a>动态输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_row188425379530"><td class="cellrowborder" valign="top" width="18.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p13842113775313"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p13842113775313"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p13842113775313"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p08426376538"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p08426376538"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p08426376538"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p201910915458"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p201910915458"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p201910915458"></a>该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的取值范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section25791320141317"></a>

返回指定输入的shape指针，若输入的ir\_index或者relative\_index非法，返回空指针。

关于Shape类型的定义，请参见[Shape](Shape.md)。

## 约束说明<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section320753512363"></a>

```
ge::graphStatus InferShapeForXXX(InferShapeContext *context) {
  auto in_shape = context->GetDynamicInputShape(2, 2);
  // ...
}
```

