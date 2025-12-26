# GetInputTensor<a name="ZH-CN_TOPIC_0000002042526838"></a>

## 函数功能<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section36583473819"></a>

根据算子输入索引获取对应的输入tensor指针。这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section13230182415108"></a>

```
const Tensor *GetInputTensor(const size_t index) const
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
<tbody><tr id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p318615392613"><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p318615392613"></a><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p318615392613"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p320343694214"><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p320343694214"></a><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p17783144418158"><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p17783144418158"></a><a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_p17783144418158"></a>算子输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section25791320141317"></a>

返回指向输入Tensor指针，当输入index非法时，返回空指针。

关于Tensor类型的定义，请参见[Tensor](Tensor.md)。

## 约束说明<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section19165124931511"></a>

仅在设置数据依赖时可以获取tensor的数据地址。如果输入没有被设置为数据依赖，调用此接口获取tensor时，只能在tensor中获取到正确的shape、format、datatype信息，无法获取到真实的tensor数据地址（获取到的地址为nullptr）。

## 调用示例<a name="zh-cn_topic_0000001526526766_zh-cn_topic_0000001389703253_section320753512363"></a>

```
ge::graphStatus InferShapeForReshape(InferShapeContext *context) {
  const gert::Shape *x_shape = context->GetInputShape(0);        // 获取第0个输入的shape
  const gert::Tensor *shape_tensor = context->GetInputTensor(1); // 获取第1个输入的tensor  数据依赖
  gert::Shape *output_shape = context->GetOutputShape(0);
  if (x_shape == nullptr || shape_tensor == nullptr || output_shape == nullptr) {
    // 防御式编程，不应该出现的场景，打印错误并返回失败
    return ge::GRAPH_FAILED;
  }
  // ...
}
```

