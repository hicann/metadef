# GetOutputTdInfo<a name="ZH-CN_TOPIC_0000002078447861"></a>

## 函数功能<a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_section36583473819"></a>

获取算子指定输出的Tensor描述，注意，编译时无法确定的shape信息不在Tensor描述中（由于编译时无法确定shape，因此该Tensor描述里不包含shape信息）。

## 函数原型<a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_section13230182415108"></a>

```
const CompileTimeTensorDesc *GetOutputTdInfo(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_section75395119104"></a>

<a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p10223674448"><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p10223674448"></a><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p645511218169"><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p645511218169"></a><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p1922337124411"><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p1922337124411"></a><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p212592715429"><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p212592715429"></a><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p212592715429"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p143401361158"><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p143401361158"></a><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p1410311123516"><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p1410311123516"></a><a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_p1410311123516"></a>算子的输出索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_section25791320141317"></a>

返回const类型的Tensor描述信息。

## 约束说明<a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586126870_zh-cn_topic_0000001390567189_section320753512363"></a>

```
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto output_td = compute_node_info->GetOutputTdInfo(output_index);
```

