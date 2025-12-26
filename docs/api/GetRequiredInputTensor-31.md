# GetRequiredInputTensor<a name="ZH-CN_TOPIC_0000002078447625"></a>

## 函数功能<a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的必选输入tensor指针。

## 函数原型<a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_section13230182415108"></a>

```
const Tensor *GetRequiredInputTensor(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_section75395119104"></a>

<a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_row6223476444"><th class="cellrowborder" valign="top" width="18.38%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p10223674448"><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p10223674448"></a><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p645511218169"><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p645511218169"></a><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.77%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p1922337124411"><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p1922337124411"></a><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_row152234713443"><td class="cellrowborder" valign="top" width="18.38%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p2340183613156"><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p2340183613156"></a><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p143401361158"><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p143401361158"></a><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p131917964515"><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p131917964515"></a><a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_p131917964515"></a>必选输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_section25791320141317"></a>

返回指定输入的tensor指针，若输入的ir\_index非法，返回空指针。

关于Tensor类型的定义，请参见[Tensor](Tensor.md)。

## 约束说明<a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_section19165124931511"></a>

仅在设置数据依赖时可以获取tensor的数据地址。如果输入没有被设置为数据依赖，调用此接口获取tensor时，只能在tensor中获取到正确的shape、format、datatype信息，无法获取到真实的tensor数据地址（获取到的地址为nullptr）。

## 调用示例<a name="zh-cn_topic_0000002027911741_zh-cn_topic_0000001339343452_section320753512363"></a>

```
ge::graphStatus InferShapeForXXX(InferShapeContext *context) {
  auto in_shape = context->GetRequiredInputTensor(2);
  // ...
}
```

