# GetInputTensor<a name="ZH-CN_TOPIC_0000002343737833"></a>

## 函数功能<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section36583473819"></a>

根据算子输入索引获取对应的输入Tensor指针。这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section13230182415108"></a>

```
const Tensor *GetInputTensor(const size_t index) const
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
<tbody><tr id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_row152234713443"><td class="cellrowborder" valign="top" width="18.38%" headers="mcps1.1.4.1.1 "><p id="p118841738144212"><a name="p118841738144212"></a><a name="p118841738144212"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p143401361158"><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p143401361158"></a><a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.77%" headers="mcps1.1.4.1.3 "><p id="p126358154219"><a name="p126358154219"></a><a name="p126358154219"></a>输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section25791320141317"></a>

输入Tensor指针，index非法时，返回空指针。

关于Tensor类型的定义，请参见[Tensor](Tensor.md)。

## 约束说明<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576606637_zh-cn_topic_0000001339343452_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto data = context->GetInputTensor(1U)->GetData<uint8_t>();
  EXPECT_EQ(data[0], 85);
  // ...
}
```

