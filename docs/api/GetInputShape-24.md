# GetInputShape<a name="ZH-CN_TOPIC_0000002078447621"></a>

## 函数功能<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section36583473819"></a>

根据算子输入索引获取对应的输入shape指针。这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section13230182415108"></a>

```
const Shape *GetInputShape(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section75395119104"></a>

<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2340183613156"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2340183613156"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2684123934216"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2684123934216"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p2684123934216"></a>算子输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section25791320141317"></a>

输入shape指针，index非法时，返回空指针。

关于Shape类型的定义，请参见[Shape](Shape.md)。

## 约束说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section320753512363"></a>

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

