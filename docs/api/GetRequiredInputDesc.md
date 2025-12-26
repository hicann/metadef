# GetRequiredInputDesc<a name="ZH-CN_TOPIC_0000002042368622"></a>

## 函数功能<a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_section36583473819"></a>

根据算子原型定义中的输入索引获取对应必选输入的tensor描述信息。

## 函数原型<a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_section13230182415108"></a>

```
const CompileTimeTensorDesc *GetRequiredInputDesc(const size_t ir_index) const
```

## 参数说明<a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_section75395119104"></a>

<a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p10223674448"><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p10223674448"></a><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p645511218169"><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p645511218169"></a><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p1922337124411"><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p1922337124411"></a><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p2340183613156"><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p2340183613156"></a><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p320343694214"><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p320343694214"></a><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p2684123934216"><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p2684123934216"></a><a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_p2684123934216"></a>算子IR原型定义中的输入索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_section25791320141317"></a>

CompileTimeTensorDesc指针，index非法时，返回空指针。

关于CompileTimeTensorDesc的定义，请参见[CompileTimeTensorDesc](CompileTimeTensorDesc.md)。

## 约束说明<a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000002024916010_zh-cn_topic_0000001596622188_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
// 假设某个算子的IR原型的第0个输入是普通输入，且实际有1个输入
auto optional_input_td = extend_context->GetRequiredInputDesc(0); // 拿到第0个输入的tensor描述
```

