# AppendConvertedAttrVal<a name="ZH-CN_TOPIC_0000002078447617"></a>

## 函数功能<a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_section36583473819"></a>

将RuntimeAttrs内存中的第index个属性，从src\_type数据类型转成dst\_type数据类型后，追加在当前的tilingdata后面。

## 函数原型<a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_section13230182415108"></a>

**ge::graphStatus AppendConvertedAttrVal\(const RuntimeAttrs \*attrs, const size\_t attr\_index, const AttrDataType src\_type, const AttrDataType dst\_type\)**

## 参数说明<a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_section75395119104"></a>

**表 1**  参数列表

<a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p10223674448"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p10223674448"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p645511218169"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p645511218169"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1922337124411"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1922337124411"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p31071321114018"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p31071321114018"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p31071321114018"></a>attrs</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1210652116402"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1210652116402"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1210652116402"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p13106202194014"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p13106202194014"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p13106202194014"></a>图执行时的属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_row6432942133712"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p11051216406"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p11051216406"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p11051216406"></a>attr_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p410422164012"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p410422164012"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p410422164012"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1310219213405"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1310219213405"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1310219213405"></a>属性的序号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_row196221228154020"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p10622128154015"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p10622128154015"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p10622128154015"></a>src_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p76221287407"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p76221287407"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p76221287407"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001592855200_p1848891153315"><a name="zh-cn_topic_0000001592855200_p1848891153315"></a><a name="zh-cn_topic_0000001592855200_p1848891153315"></a>属性的原始dtype。AttrDataType类型，具体定义如下：</p>
<pre class="screen" id="zh-cn_topic_0000001592855200_screen1222105519503"><a name="zh-cn_topic_0000001592855200_screen1222105519503"></a><a name="zh-cn_topic_0000001592855200_screen1222105519503"></a>enum class AttrDataType : int32_t {
  kBool = 0,
  kString,
  kInt32,
  kInt64,
  kUint32,
  kFloat32,
  kFloat16,
  kListBool,
  kListString,
  kListInt32,
  kListInt64,
  kListUint32,
  kListFloat32,
  kListFloat16,
  kListListInt32,
  kListListInt64,
  kBfloat16,
  kInt8,
  kInt16,
  kListInt8,
  kListInt16,
  kTypeEnd
};</pre>
<p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1162282813404"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1162282813404"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1162282813404"></a>src_type和dst_type支持的取值范围和对应关系见<a href="#zh-cn_topic_0000001592855200_table410454711314">表2</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_row13472113064016"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p14728307406"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p14728307406"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p14728307406"></a>dst_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1847210306406"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1847210306406"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p1847210306406"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p147263094019"><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p147263094019"></a><a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_p147263094019"></a>属性的目标dtype。</p>
<p id="zh-cn_topic_0000001592855200_p2062255873213"><a name="zh-cn_topic_0000001592855200_p2062255873213"></a><a name="zh-cn_topic_0000001592855200_p2062255873213"></a>src_type和dst_type支持的取值范围和对应关系见<a href="#zh-cn_topic_0000001592855200_table410454711314">表2</a>。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  src\_type和dst\_type支持的取值范围和对应关系

<a name="zh-cn_topic_0000001592855200_table410454711314"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001592855200_row710420478311"><th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001592855200_p10104154723117"><a name="zh-cn_topic_0000001592855200_p10104154723117"></a><a name="zh-cn_topic_0000001592855200_p10104154723117"></a>src_type</p>
</th>
<th class="cellrowborder" valign="top" width="86.83%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001592855200_p11104184711316"><a name="zh-cn_topic_0000001592855200_p11104184711316"></a><a name="zh-cn_topic_0000001592855200_p11104184711316"></a>dst_type</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001592855200_row7104204713119"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p580782043413"><a name="zh-cn_topic_0000001592855200_p580782043413"></a><a name="zh-cn_topic_0000001592855200_p580782043413"></a>kInt64</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p580722033418"><a name="zh-cn_topic_0000001592855200_p580722033418"></a><a name="zh-cn_topic_0000001592855200_p580722033418"></a>kInt32、kUint32</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_row1110494743116"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p48071020143412"><a name="zh-cn_topic_0000001592855200_p48071020143412"></a><a name="zh-cn_topic_0000001592855200_p48071020143412"></a>kListInt64</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p178071420103417"><a name="zh-cn_topic_0000001592855200_p178071420103417"></a><a name="zh-cn_topic_0000001592855200_p178071420103417"></a>kListInt32、kListUint32</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_row202841046193913"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p469102616377"><a name="zh-cn_topic_0000001592855200_p469102616377"></a><a name="zh-cn_topic_0000001592855200_p469102616377"></a>kInt32</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p17691426153716"><a name="zh-cn_topic_0000001592855200_p17691426153716"></a><a name="zh-cn_topic_0000001592855200_p17691426153716"></a>kInt32</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_row97931848123916"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p16691152623712"><a name="zh-cn_topic_0000001592855200_p16691152623712"></a><a name="zh-cn_topic_0000001592855200_p16691152623712"></a>kListInt32</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p669172617377"><a name="zh-cn_topic_0000001592855200_p669172617377"></a><a name="zh-cn_topic_0000001592855200_p669172617377"></a>kListInt32</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_row15105647133110"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p7807182023415"><a name="zh-cn_topic_0000001592855200_p7807182023415"></a><a name="zh-cn_topic_0000001592855200_p7807182023415"></a>kFloat32</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p18807920163417"><a name="zh-cn_topic_0000001592855200_p18807920163417"></a><a name="zh-cn_topic_0000001592855200_p18807920163417"></a>kFloat32、kFloat16、kBfloat16、kInt64、kInt32、kInt16、kInt8</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_row21701140113613"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p3807920193414"><a name="zh-cn_topic_0000001592855200_p3807920193414"></a><a name="zh-cn_topic_0000001592855200_p3807920193414"></a>kListFloat32</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p15807132063418"><a name="zh-cn_topic_0000001592855200_p15807132063418"></a><a name="zh-cn_topic_0000001592855200_p15807132063418"></a>kListFloat32、kListFloat16、kListInt64、kListInt32、kListInt16、kListInt8</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_row631503411354"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p69991635134019"><a name="zh-cn_topic_0000001592855200_p69991635134019"></a><a name="zh-cn_topic_0000001592855200_p69991635134019"></a>kBool</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p1599953517402"><a name="zh-cn_topic_0000001592855200_p1599953517402"></a><a name="zh-cn_topic_0000001592855200_p1599953517402"></a>kBool</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592855200_row1647793412357"><td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001592855200_p09991335174016"><a name="zh-cn_topic_0000001592855200_p09991335174016"></a><a name="zh-cn_topic_0000001592855200_p09991335174016"></a>kString</p>
</td>
<td class="cellrowborder" valign="top" width="86.83%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001592855200_p299963518401"><a name="zh-cn_topic_0000001592855200_p299963518401"></a><a name="zh-cn_topic_0000001592855200_p299963518401"></a>kString</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_section25791320141317"></a>

-   成功返回：ge::GRAPH\_SUCCESS。
-   失败返回：ge::GRAPH\_FAILED。

## 约束说明<a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001592855200_zh-cn_topic_0000001339693320_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());

auto holder = BuildTestContext();
auto context = holder.GetContext<TilingContext>();
auto ret = td->AppendConvertedAttrVal(context->GetAttrs(), 1, AttrDataType::kString, AttrDataType::kString)


FakeKernelContextHolder BuildTestContext() {
  auto holder = gert::KernelRunContextFaker()
                    .NodeIoNum(1, 1)
                    .IrInputNum(1)
                    .NodeInputTd(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_ND)
                    .NodeOutputTd(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .NodeAttrs({{"int", ge::AnyValue::CreateFrom<int64_t>(0x7fffffffUL)},
                                {"str", ge::AnyValue::CreateFrom<std::string>("Hello!")},
                                {"bool", ge::AnyValue::CreateFrom<bool>(true)},
                                {"float", ge::AnyValue::CreateFrom<float>(10.101)},
                                {"list_int", ge::AnyValue::CreateFrom<std::vector<int64_t>>({1, 2, 3})},
                                {"list_int2", ge::AnyValue::CreateFrom<std::vector<int64_t>>({4, 5, 6})},
                                {"list_float", ge::AnyValue::CreateFrom<std::vector<float>>({1.2, 3.4, 4.5})}})
                    .Build();
  return holder;
}
```

