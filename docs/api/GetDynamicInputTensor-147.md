# GetDynamicInputTensor<a name="ZH-CN_TOPIC_0000002042368494"></a>

## 函数功能<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入Tensor指针。

## 函数原型<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

**const Tensor \*GetDynamicInputTensor\(const size\_t ir\_index, const size\_t relative\_index\) const**

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
<tr id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_row12431522375"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p7431152163717"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p7431152163717"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p7431152163717"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p14311128375"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1543292143715"><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1543292143715"></a><a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_p1543292143715"></a>该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的有效范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

指定的输入tensor指针，ir\_index或relative\_index非法时，返回空指针。

关于Tensor类型的定义，请参见[Tensor](Tensor.md)。

## 约束说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section19165124931511"></a>

仅在设置数据依赖时可以获取tensor的数据地址。如果输入没有被设置为数据依赖，调用此接口获取tensor时，只能在tensor中获取到正确的shape、format、datatype信息，无法获取到真实的tensor数据地址（获取到的地址为nullptr）。

## 调用示例<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section320753512363"></a>

```
ge::graphStatus Tiling4ReduceCommon(TilingContext* context) {
  auto in_shape = context->GetInputShape(0);
  GE_ASSERT_NOTNULL(in_shape);
  auto axes_tensor_10 = context->GetDynamicInputTensor(1, 0);
  auto axes_tensor_11 = context->GetDynamicInputTensor(1, 1);
  ...
}
```

