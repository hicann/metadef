# GetContext<a name="ZH-CN_TOPIC_0000002455031413"></a>

## 函数功能<a name="zh-cn_topic_0000002420158524_zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section36583473819"></a>

根据指定类型获取对应的Context指针。

## 函数原型<a name="zh-cn_topic_0000002420158524_zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section13230182415108"></a>

```
template<typename ContextTypeT>
ContextTypeT *GetContext()
```

## 参数说明<a name="zh-cn_topic_0000002420158524_zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section75395119104"></a>

ContextTypeT是一个泛型，包括以下类型的Context：

-   InferDataTypeContext；
-   InferShapeContext；
-   InferShapeRangeContext；
-   KernelContext；
-   TilingContext；
-   TilingParseContext。

## 返回值说明<a name="zh-cn_topic_0000002420158524_zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section25791320141317"></a>

返回指向Context的指针，ContextBuilder、ContextHolder以及Context之间的关系如下表所示：

**表 1**  ContextBuilder、ContextHolder以及Context之间的关系

<a name="table179857131577"></a>
<table><thead align="left"><tr id="row18985181319576"><th class="cellrowborder" valign="top" width="30.853085308530854%" id="mcps1.2.4.1.1"><p id="p1698511315716"><a name="p1698511315716"></a><a name="p1698511315716"></a>ContextBuilder</p>
</th>
<th class="cellrowborder" valign="top" width="39.06390639063906%" id="mcps1.2.4.1.2"><p id="p15985121345720"><a name="p15985121345720"></a><a name="p15985121345720"></a>Holder</p>
</th>
<th class="cellrowborder" valign="top" width="30.083008300830084%" id="mcps1.2.4.1.3"><p id="p119851613195717"><a name="p119851613195717"></a><a name="p119851613195717"></a>Context</p>
</th>
</tr>
</thead>
<tbody><tr id="row1198591315710"><td class="cellrowborder" valign="top" width="30.853085308530854%" headers="mcps1.2.4.1.1 "><p id="p698873214589"><a name="p698873214589"></a><a name="p698873214589"></a>OpInferDataTypeContextBuilder</p>
</td>
<td class="cellrowborder" valign="top" width="39.06390639063906%" headers="mcps1.2.4.1.2 "><p id="p49854139574"><a name="p49854139574"></a><a name="p49854139574"></a>ContextHolder&lt;InferDataTypeContext&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="30.083008300830084%" headers="mcps1.2.4.1.3 "><p id="p10985171315715"><a name="p10985171315715"></a><a name="p10985171315715"></a>InferDataTypeContext</p>
</td>
</tr>
<tr id="row159868134572"><td class="cellrowborder" valign="top" width="30.853085308530854%" headers="mcps1.2.4.1.1 "><p id="p69784510571"><a name="p69784510571"></a><a name="p69784510571"></a>OpInferShapeContextBuilder</p>
</td>
<td class="cellrowborder" valign="top" width="39.06390639063906%" headers="mcps1.2.4.1.2 "><p id="p1483114111015"><a name="p1483114111015"></a><a name="p1483114111015"></a>ContextHolder&lt;InferShapeContext&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="30.083008300830084%" headers="mcps1.2.4.1.3 "><p id="p119861213125710"><a name="p119861213125710"></a><a name="p119861213125710"></a>InferShapeContext</p>
</td>
</tr>
<tr id="row17986131335716"><td class="cellrowborder" valign="top" width="30.853085308530854%" headers="mcps1.2.4.1.1 "><p id="p8986131375713"><a name="p8986131375713"></a><a name="p8986131375713"></a>OpInferShapeRangeContextBuilder</p>
</td>
<td class="cellrowborder" valign="top" width="39.06390639063906%" headers="mcps1.2.4.1.2 "><p id="p1758619215018"><a name="p1758619215018"></a><a name="p1758619215018"></a>ContextHolder&lt;InferShapeRangeContext&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="30.083008300830084%" headers="mcps1.2.4.1.3 "><p id="p139861713155714"><a name="p139861713155714"></a><a name="p139861713155714"></a>InferShapeRangeContext</p>
</td>
</tr>
<tr id="row9986013105716"><td class="cellrowborder" valign="top" width="30.853085308530854%" headers="mcps1.2.4.1.1 "><p id="p17898619586"><a name="p17898619586"></a><a name="p17898619586"></a>OpKernelContextBuilder</p>
</td>
<td class="cellrowborder" valign="top" width="39.06390639063906%" headers="mcps1.2.4.1.2 "><p id="p81312311014"><a name="p81312311014"></a><a name="p81312311014"></a>ContextHolder&lt;KernelContext&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="30.083008300830084%" headers="mcps1.2.4.1.3 "><p id="p17986113195716"><a name="p17986113195716"></a><a name="p17986113195716"></a>KernelContext</p>
</td>
</tr>
<tr id="row980414176587"><td class="cellrowborder" valign="top" width="30.853085308530854%" headers="mcps1.2.4.1.1 "><p id="p9804101714587"><a name="p9804101714587"></a><a name="p9804101714587"></a>OpTilingContextBuilder</p>
</td>
<td class="cellrowborder" valign="top" width="39.06390639063906%" headers="mcps1.2.4.1.2 "><p id="p19500256303"><a name="p19500256303"></a><a name="p19500256303"></a>ContextHolder&lt;TilingContext&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="30.083008300830084%" headers="mcps1.2.4.1.3 "><p id="p168041817125815"><a name="p168041817125815"></a><a name="p168041817125815"></a>TilingContext</p>
</td>
</tr>
<tr id="row11587181116584"><td class="cellrowborder" valign="top" width="30.853085308530854%" headers="mcps1.2.4.1.1 "><p id="p558711120589"><a name="p558711120589"></a><a name="p558711120589"></a>OpTilingParseContextBuilder</p>
</td>
<td class="cellrowborder" valign="top" width="39.06390639063906%" headers="mcps1.2.4.1.2 "><p id="p88431031907"><a name="p88431031907"></a><a name="p88431031907"></a>ContextHolder&lt;TilingParseContext&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="30.083008300830084%" headers="mcps1.2.4.1.3 "><p id="p145871711165815"><a name="p145871711165815"></a><a name="p145871711165815"></a>TilingParseContext</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000002420158524_zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000002420158524_zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section320753512363"></a>

```
OpInferDataTypeContextBuilder ctx_builder;
ge::DataType dtype0 = ge::DT_FLOAT;
ge::DataType dtype1 = ge::DT_FLOAT16;
ge::DataType dtype2 = ge::DT_FLOAT;
ge::DataType dtype3 = ge::DT_FLOAT16;
ge::DataType dtype4 = ge::DT_FLOAT16;
std::vector<ge::DataType> input_dtype_ref = {dtype0, dtype1, dtype2, dtype3};
std::vector<ge::DataType *> output_dtype_ref = {&dtype4};
auto holder = ctx_builder.OpType("Concat")
                  .OpName("concat_1")
                  .IOInstanceNum({4}, {1})
                  .InputTensorDesc(0, dtype0, ge::FORMAT_ND, ge::FORMAT_ND)
                  .InputTensorDesc(1, dtype1, ge::FORMAT_ND, ge::FORMAT_ND)
                  .InputTensorDesc(2, dtype2, ge::FORMAT_ND, ge::FORMAT_ND)
                  .InputTensorDesc(3, dtype3, ge::FORMAT_ND, ge::FORMAT_ND)
                  .OutputTensorDesc(0, ge::FORMAT_ND, ge::FORMAT_ND)
                  .Build();
auto ctx = holder.GetContext();
EXPECT_NE(ctx, nullptr);
```

