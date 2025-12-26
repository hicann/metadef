# OutputTensorDesc<a name="ZH-CN_TOPIC_0000002450925518"></a>

## 函数功能<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section36583473819"></a>

设置输出Tensor描述信息，用于构造TilingParseContext的基类ExtendedKernelContext中的ComputeNodeInfo等信息。

## 函数原型<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
OpTilingParseContextBuilder &OutputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## 参数说明<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section75395119104"></a>

<a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row6223476444"><th class="cellrowborder" valign="top" width="20.9%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="11.66%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row152234713443"><td class="cellrowborder" valign="top" width="20.9%" headers="mcps1.1.4.1.1 "><p id="p866123920418"><a name="p866123920418"></a><a name="p866123920418"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p1086191914210"><a name="p1086191914210"></a><a name="p1086191914210"></a>算子输出实例索引。</p>
</td>
</tr>
<tr id="row519925510524"><td class="cellrowborder" valign="top" width="20.9%" headers="mcps1.1.4.1.1 "><p id="p1020045515521"><a name="p1020045515521"></a><a name="p1020045515521"></a>dtype</p>
</td>
<td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.4.1.2 "><p id="p19200955135216"><a name="p19200955135216"></a><a name="p19200955135216"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p420065515216"><a name="p420065515216"></a><a name="p420065515216"></a>输出Tensor的数据类型。</p>
</td>
</tr>
<tr id="row2063033018412"><td class="cellrowborder" valign="top" width="20.9%" headers="mcps1.1.4.1.1 "><p id="p168311149114120"><a name="p168311149114120"></a><a name="p168311149114120"></a>origin_format</p>
</td>
<td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.4.1.2 "><p id="p196311930164111"><a name="p196311930164111"></a><a name="p196311930164111"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p083682717420"><a name="p083682717420"></a><a name="p083682717420"></a>输出Tensor的原始格式。</p>
</td>
</tr>
<tr id="row1119143464114"><td class="cellrowborder" valign="top" width="20.9%" headers="mcps1.1.4.1.1 "><p id="p1416155420418"><a name="p1416155420418"></a><a name="p1416155420418"></a>storage_format</p>
</td>
<td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.4.1.2 "><p id="p21193345411"><a name="p21193345411"></a><a name="p21193345411"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p95833211429"><a name="p95833211429"></a><a name="p95833211429"></a>输出Tensor的存储格式。</p>
</td>
</tr>
<tr id="row14199135814415"><td class="cellrowborder" valign="top" width="20.9%" headers="mcps1.1.4.1.1 "><p id="p1199712054219"><a name="p1199712054219"></a><a name="p1199712054219"></a>expand_dims_type</p>
</td>
<td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.4.1.2 "><p id="p519985810413"><a name="p519985810413"></a><a name="p519985810413"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p1046113364422"><a name="p1046113364422"></a><a name="p1046113364422"></a>输出Tensor的补维规则ExpandDimsType，默认值为{}。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section25791320141317"></a>

OpTilingParseContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002453597821_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section19165124931511"></a>

在调用Build方法之前，必须调用该接口，否则构造出的TilingParserContext将包含未定义数据。

