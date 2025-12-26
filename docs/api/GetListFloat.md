# GetListFloat<a name="ZH-CN_TOPIC_0000002078447769"></a>

## 函数功能<a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_section36583473819"></a>

获取list\_float32类型的属性值。

## 函数原型<a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_section13230182415108"></a>

```
const TypedContinuousVector<float> *GetListFloat(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_section75395119104"></a>

<a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_row6223476444"><th class="cellrowborder" valign="top" width="17.19%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p10223674448"><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p10223674448"></a><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p645511218169"><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p645511218169"></a><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p1922337124411"><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p1922337124411"></a><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_row152234713443"><td class="cellrowborder" valign="top" width="17.19%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p2340183613156"><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p2340183613156"></a><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p143401361158"><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p143401361158"></a><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p2116135318312"><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p2116135318312"></a><a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_p2116135318312"></a>属性在IR原型定义中以及在OP_IMPL注册中的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_section25791320141317"></a>

指向属性值的指针。

## 约束说明<a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001591212702_zh-cn_topic_0000001389940845_section320753512363"></a>

```
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const TypedContinuousVector<float> *attr0 = runtime_attrs->GetListFloat(0);
```

