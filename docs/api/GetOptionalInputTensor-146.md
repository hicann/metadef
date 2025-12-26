# GetOptionalInputTensor<a name="ZH-CN_TOPIC_0000002042526794"></a>

## 函数功能<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的可选输入tensor指针。

## 函数原型<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section13230182415108"></a>

**const Tensor \*GetOptionalInputTensor\(const size\_t ir\_index\) const**

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
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"></a><a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"></a>可选输入在算子IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section25791320141317"></a>

指定ir\_index的输入tensor指针，当输入ir\_index非法或该INPUT没有实例化时，返回空指针。

关于Tensor类型的定义，请参见[Tensor](Tensor.md)。

## 约束说明<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section19165124931511"></a>

仅在设置数据依赖时可以获取tensor的数据地址。如果输入没有被设置为数据依赖，调用此接口获取tensor时，只能在tensor中获取到正确的shape、format、datatype信息，无法获取到真实的tensor数据地址（获取到的地址为nullptr）。

## 调用示例<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section320753512363"></a>

```
ge::graphStatus Tiling4ReduceCommon(TilingContext* context) {
  auto in_shape = context->GetInputShape(0);
  GE_ASSERT_NOTNULL(in_shape);
  auto axes_tensor = context->GetOptionalInputTensor(1);
  ...
}
```

