# GetOutputDesc<a name="ZH-CN_TOPIC_0000002078486301"></a>

## 函数功能<a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_section36583473819"></a>

根据算子输出索引获取对应输出的tensor描述信息。这里的输出索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_section13230182415108"></a>

```
const CompileTimeTensorDesc *GetOutputDesc(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_section75395119104"></a>

<a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p10223674448"><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p10223674448"></a><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p645511218169"><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p645511218169"></a><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p1922337124411"><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p1922337124411"></a><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p2340183613156"><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p2340183613156"></a><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p320343694214"><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p320343694214"></a><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p2684123934216"><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p2684123934216"></a><a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_p2684123934216"></a>算子输出索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_section25791320141317"></a>

输出TensorDesc的指针，当输入index非法时，返回空指针。

关于CompileTimeTensorDesc的定义，请参见[CompileTimeTensorDesc](CompileTimeTensorDesc.md)。

## 约束说明<a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635886841_zh-cn_topic_0000001389505453_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeInfo()->GetOutputsNum(); ++idx) {
  auto output_td = extend_context->GetOutputDesc(idx);
  ...
}
```

