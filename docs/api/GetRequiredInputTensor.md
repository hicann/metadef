# GetRequiredInputTensor<a name="ZH-CN_TOPIC_0000002309618950"></a>

## 函数功能<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的必选输入Tensor指针。

## 函数原型<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

```
const Tensor *GetRequiredInputTensor(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section75395119104"></a>

<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p10223674448"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p10223674448"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p645511218169"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p645511218169"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1922337124411"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1922337124411"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p3943172167"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p3943172167"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p3943172167"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p143401361158"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p143401361158"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p2684123934216"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p2684123934216"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p2684123934216"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

输入Tensor指针，ir\_index非法时，返回空指针。

关于Tensor类型的定义，请参见[Tensor](Tensor.md)。

## 调用示例<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto data = context->GetRequiredInputTensor(1U)->GetData<uint8_t>();
  EXPECT_EQ(data[0], 85);
  // ...
}
```

