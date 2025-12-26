# GetInputTdInfo<a name="ZH-CN_TOPIC_0000002078486469"></a>

## 函数功能<a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_section36583473819"></a>

根据输入索引信息，获取算子的对应输入Tensor描述，注意，编译时无法确定的shape信息不在Tensor描述中（由于编译时无法确定shape，因此该Tensor描述里不包含shape信息）。

## 函数原型<a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_section13230182415108"></a>

```
const CompileTimeTensorDesc *GetInputTdInfo(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_section75395119104"></a>

<a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p10223674448"><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p10223674448"></a><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p645511218169"><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p645511218169"></a><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p1922337124411"><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p1922337124411"></a><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p14234851154110"><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p14234851154110"></a><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p14234851154110"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p143401361158"><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p143401361158"></a><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p17901920191612"><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p17901920191612"></a><a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_p17901920191612"></a>算子的输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_section25791320141317"></a>

返回const类型的Tensor描述信息。

## 约束说明<a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585966934_zh-cn_topic_0000001340046934_section320753512363"></a>

```
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto input_td = compute_node_info->GetInputTdInfo(input_index);
```

