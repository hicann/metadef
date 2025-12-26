# AddOverflow<a name="ZH-CN_TOPIC_0000002234353510"></a>

## 函数功能<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section36893359"></a>

该模板函数用于判断两个数值相加是否会发生溢出，并在不溢出的情况下返回正确的计算结果。

## 函数原型<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section136951948195410"></a>

```
template<typename TLhs, typename TRhs, typename TRet>
bool AddOverflow(TLhs lhs, TRhs rhs, TRet &ret)
```

## 参数说明<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section63604780"></a>

**表 1**  模板参数说明

<a name="table1156602844113"></a>
<table><thead align="left"><tr id="row155661228144114"><th class="cellrowborder" valign="top" width="24.65%" id="mcps1.2.3.1.1"><p id="p75671428174117"><a name="p75671428174117"></a><a name="p75671428174117"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="75.35%" id="mcps1.2.3.1.2"><p id="p756717286416"><a name="p756717286416"></a><a name="p756717286416"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8567172844120"><td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.3.1.1 "><p id="p11567132824117"><a name="p11567132824117"></a><a name="p11567132824117"></a>TLhs</p>
</td>
<td class="cellrowborder" valign="top" width="75.35%" headers="mcps1.2.3.1.2 "><p id="p556710286418"><a name="p556710286418"></a><a name="p556710286418"></a>加法左操作数的数据类型。</p>
</td>
</tr>
<tr id="row756712824119"><td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.3.1.1 "><p id="p85671728164112"><a name="p85671728164112"></a><a name="p85671728164112"></a>TRhs</p>
</td>
<td class="cellrowborder" valign="top" width="75.35%" headers="mcps1.2.3.1.2 "><p id="p47879186196"><a name="p47879186196"></a><a name="p47879186196"></a>加法右操作数的数据类型。</p>
</td>
</tr>
<tr id="row256732824115"><td class="cellrowborder" valign="top" width="24.65%" headers="mcps1.2.3.1.1 "><p id="p16690052114118"><a name="p16690052114118"></a><a name="p16690052114118"></a>TRet</p>
</td>
<td class="cellrowborder" valign="top" width="75.35%" headers="mcps1.2.3.1.2 "><p id="p456717281414"><a name="p456717281414"></a><a name="p456717281414"></a>加法计算结果的数据类型。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  参数说明

<a name="zh-cn_topic_0000001602064312_table62441623"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001602064312_row47897641"><th class="cellrowborder" valign="top" width="24.782478247824784%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001602064312_p54503731"><a name="zh-cn_topic_0000001602064312_p54503731"></a><a name="zh-cn_topic_0000001602064312_p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="26.882688268826882%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001602064312_p52726081"><a name="zh-cn_topic_0000001602064312_p52726081"></a><a name="zh-cn_topic_0000001602064312_p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="48.33483348334833%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001602064312_p42954172"><a name="zh-cn_topic_0000001602064312_p42954172"></a><a name="zh-cn_topic_0000001602064312_p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001602064312_row56735883"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001602064312_p2755144663518"><a name="zh-cn_topic_0000001602064312_p2755144663518"></a><a name="zh-cn_topic_0000001602064312_p2755144663518"></a>lhs</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001602064312_p58370887"><a name="zh-cn_topic_0000001602064312_p58370887"></a><a name="zh-cn_topic_0000001602064312_p58370887"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.2.4.1.3 "><p id="p28911141193412"><a name="p28911141193412"></a><a name="p28911141193412"></a>加法左操作数。</p>
</td>
</tr>
<tr id="row975411634014"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.2.4.1.1 "><p id="p8754361400"><a name="p8754361400"></a><a name="p8754361400"></a>rhs</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.2.4.1.2 "><p id="p1375416144018"><a name="p1375416144018"></a><a name="p1375416144018"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.2.4.1.3 "><p id="p18937184511347"><a name="p18937184511347"></a><a name="p18937184511347"></a>加法右操作数。</p>
</td>
</tr>
<tr id="row1133899184011"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.2.4.1.1 "><p id="p93381795408"><a name="p93381795408"></a><a name="p93381795408"></a>ret</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.2.4.1.2 "><p id="p1338119184016"><a name="p1338119184016"></a><a name="p1338119184016"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.2.4.1.3 "><p id="p63381196401"><a name="p63381196401"></a><a name="p63381196401"></a>左右操作数相加的结果，只有函数返回值为true时，该结果才有效。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

true表示计算失败，ret返回值无效；false表示计算成功，ret返回值有效。

## 约束说明<a name="zh-cn_topic_0000001836249772_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001636247413_zh-cn_topic_0000001390806829_section320753512363"></a>

```
// ...
ge::DataType out_data_type = ge::DT_FLOAT;
GE_ASSERT_GRAPH_SUCCESS(GetOutputDataType(context, out_data_type), "get data type failed");
GE_ASSERT_TRUE(out_data_type == ge::DataType::DT_INT32 || out_data_type == ge::DataType::DT_INT64,
               "only support DT_INT32 and DT_INT64, but out_data_type is %s",
               ge::TypeUtils::DataTypeToSerialString(out_data_type).c_str());
const auto is_malloc = (out_data_type == ge::DataType::DT_INT32);
const auto data_type_size = ge::GetSizeByDataType(out_data_type);
if (data_type_size <= 0) {
  // 报错
}
size_t malloc_buffer_size = 0U;
if (ge::MulOverflow(static_cast<size_t>(data_type_size), Shape::kMaxDimNum, malloc_buffer_size)) {
  // 报错
}
if (ge::AddOverflow(malloc_buffer_size, sizeof(GertTensorData), malloc_buffer_size)) {
  // 报错
}
```

