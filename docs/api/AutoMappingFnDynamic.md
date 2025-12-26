# AutoMappingFnDynamic<a name="ZH-CN_TOPIC_0000002079199861"></a>

## 函数功能<a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_section34261011"></a>

动态输入/输出算子的自动映射回调函数。

## 函数原型<a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_section39913650"></a>

```
Status AutoMappingFnDynamic(const google::protobuf::Message *op_src, ge::Operator &op, std::map<std::string, std::pair<std::string, std::string>> dynamic_name_attr_value, int32_t in_pos = -1, int32_t out_pos = -1)
```

## 参数说明<a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_section23678531"></a>

<a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_table24696155"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_row1801909"><th class="cellrowborder" valign="top" width="31.633163316331636%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11736918"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11736918"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11736918"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="19.2019201920192%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11166333"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11166333"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11166333"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="49.164916491649166%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p32057743"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p32057743"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p32057743"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_row46540406"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11676570"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11676570"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p11676570"></a>op_src</p>
</td>
<td class="cellrowborder" valign="top" width="19.2019201920192%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p6278114"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p6278114"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p6278114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.164916491649166%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p38765239"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p38765239"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p38765239"></a>转换前原始模型中的算子，包含原始模型中算子的属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_row13342833"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p7027716"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p7027716"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p7027716"></a>op</p>
</td>
<td class="cellrowborder" valign="top" width="19.2019201920192%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p32374103"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p32374103"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p32374103"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.164916491649166%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p5056658"><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p5056658"></a><a name="zh-cn_topic_0000001265390046_zh-cn_topic_0204328260_p5056658"></a>适配<span id="zh-cn_topic_0000001265390046_ph1555712386204"><a name="zh-cn_topic_0000001265390046_ph1555712386204"></a><a name="zh-cn_topic_0000001265390046_ph1555712386204"></a>昇腾AI处理器</span>的算子。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001265390046_row20522216192719"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265390046_p1616385216275"><a name="zh-cn_topic_0000001265390046_p1616385216275"></a><a name="zh-cn_topic_0000001265390046_p1616385216275"></a>dynamic_name_attr_value</p>
</td>
<td class="cellrowborder" valign="top" width="19.2019201920192%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265390046_p1523716182710"><a name="zh-cn_topic_0000001265390046_p1523716182710"></a><a name="zh-cn_topic_0000001265390046_p1523716182710"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.164916491649166%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265390046_p0826915112813"><a name="zh-cn_topic_0000001265390046_p0826915112813"></a><a name="zh-cn_topic_0000001265390046_p0826915112813"></a>描述动态输入输出实际个数，key表示动态端口是输入还是输出，key的取值：</p>
<a name="zh-cn_topic_0000001265390046_ul1885834315916"></a><a name="zh-cn_topic_0000001265390046_ul1885834315916"></a><ul id="zh-cn_topic_0000001265390046_ul1885834315916"><li>in：代表算子的输入。</li><li>out：代表算子的输出。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001265390046_row174272082718"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265390046_p17742152010274"><a name="zh-cn_topic_0000001265390046_p17742152010274"></a><a name="zh-cn_topic_0000001265390046_p17742152010274"></a>in_pos</p>
</td>
<td class="cellrowborder" valign="top" width="19.2019201920192%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265390046_p374262013279"><a name="zh-cn_topic_0000001265390046_p374262013279"></a><a name="zh-cn_topic_0000001265390046_p374262013279"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.164916491649166%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265390046_p1874232042715"><a name="zh-cn_topic_0000001265390046_p1874232042715"></a><a name="zh-cn_topic_0000001265390046_p1874232042715"></a>动态输入的端口id。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001265390046_row36192183292"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265390046_p96191918132912"><a name="zh-cn_topic_0000001265390046_p96191918132912"></a><a name="zh-cn_topic_0000001265390046_p96191918132912"></a>out_pos</p>
</td>
<td class="cellrowborder" valign="top" width="19.2019201920192%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265390046_p1661921842912"><a name="zh-cn_topic_0000001265390046_p1661921842912"></a><a name="zh-cn_topic_0000001265390046_p1661921842912"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.164916491649166%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265390046_p15619201832916"><a name="zh-cn_topic_0000001265390046_p15619201832916"></a><a name="zh-cn_topic_0000001265390046_p15619201832916"></a>动态输出的端口id。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001265390046_section05033452010"></a>

若原始TensorFlow算子与适配昇腾AI处理器的算子属性无法一一映射，AutoMappingFnDynamic函数无法应用于回调函数[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)中，此种场景下，请在回调函数[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)中使用[AutoMappingByOpFnDynamic](AutoMappingByOpFnDynamic.md)接口进行可以映射成功的属性的自动解析，使用示例请参见[调用示例](AutoMappingByOpFnDynamic.md#zh-cn_topic_0000001312471157_section10601131863619)。

## 代码示例<a name="zh-cn_topic_0000001265390046_section165866101951"></a>

动态输入的代码示例：

```
// register MapStage op to GE
Status MapStageMapping(const google::protobuf::Message* op_src, ge::Operator& op) {
  map<string, pair<string, string>> value;
  value["in"] = pair<string, string>("values", "fake_dtypes");
  AutoMappingFnDynamic(op_src, op, value);
  return SUCCESS;
}

REGISTER_CUSTOM_OP("MapStage")
    .FrameworkType(TENSORFLOW)
    .OriginOpType("MapStage")
    .ParseParamsFn(MapStageMapping)
    .ImplyType(ImplyType::AI_CPU);
```

动态输出的代码示例：

```
Status AutoMappingFnSplit(const google::protobuf::Message* op_src, ge::Operator& op) {
  map<string, pair<string, string>> value;
  value["out"] = pair<string, string>("y", "num_split");
  AutoMappingFnDynamic(op_src, op, value);
  return SUCCESS;
}

REGISTER_CUSTOM_OP("Split")
    .FrameworkType(TENSORFLOW)
    .OriginOpType("Split")
    .ParseParamsFn(AutoMappingFnSplit)
    .ImplyType(ImplyType::TVM);
```

