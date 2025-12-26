# GetIrInputInstanceInfo<a name="ZH-CN_TOPIC_0000002078486305"></a>

## 函数功能<a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_section36583473819"></a>

根据算子原型定义中的输入索引获取对应输入的实例化信息。

## 函数原型<a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_section13230182415108"></a>

```
const AnchorInstanceInfo *GetIrInputInstanceInfo (const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_section75395119104"></a>

<a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p10223674448"><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p10223674448"></a><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="14.610000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p645511218169"><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p645511218169"></a><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="68.17%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p1922337124411"><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p1922337124411"></a><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p2340183613156"><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p2340183613156"></a><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="14.610000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p143401361158"><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p143401361158"></a><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="68.17%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p17783144418158"><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p17783144418158"></a><a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_p17783144418158"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_section25791320141317"></a>

指定输入的实例化信息。

关于AnchorInstanceInfo的定义，请参见[AnchorInstanceInfo](AnchorInstanceInfo.md)。

## 约束说明<a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585807514_zh-cn_topic_0000001389625397_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeInfo()->GetIrInputsNum(); ++idx) {
  auto input_td = extend_context->GetIrInputInstanceInfo(idx);  
  ...
}
```

