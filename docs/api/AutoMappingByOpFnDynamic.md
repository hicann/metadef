# AutoMappingByOpFnDynamic<a name="ZH-CN_TOPIC_0000002043200516"></a>

## 函数功能<a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_section34261011"></a>

动态输入/输出算子的自动映射回调函数。

## 函数原型<a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_section39913650"></a>

```
Status AutoMappingByOpFnDynamic(const ge::Operator &op_src, ge::Operator &op, const std::vector<DynamicInputOutputInfo> &dynamic_name_attr_value)
```

## 参数说明<a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_section23678531"></a>

<a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_table24696155"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_row1801909"><th class="cellrowborder" valign="top" width="31.633163316331636%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11736918"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11736918"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11736918"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="19.931993199319933%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11166333"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11166333"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11166333"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="48.434843484348434%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p32057743"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p32057743"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p32057743"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_row46540406"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11676570"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11676570"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p11676570"></a>op_src</p>
</td>
<td class="cellrowborder" valign="top" width="19.931993199319933%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p6278114"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p6278114"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p6278114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.434843484348434%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p38765239"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p38765239"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p38765239"></a>转换前原始模型中的算子，包含原始模型中算子的属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_row13342833"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p7027716"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p7027716"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p7027716"></a>op</p>
</td>
<td class="cellrowborder" valign="top" width="19.931993199319933%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p32374103"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p32374103"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p32374103"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.434843484348434%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p5056658"><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p5056658"></a><a name="zh-cn_topic_0000001312471157_zh-cn_topic_0204328260_p5056658"></a>适配<span id="zh-cn_topic_0000001312471157_ph1555712386204"><a name="zh-cn_topic_0000001312471157_ph1555712386204"></a><a name="zh-cn_topic_0000001312471157_ph1555712386204"></a>昇腾AI处理器</span>的算子。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312471157_row20522216192719"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312471157_p1616385216275"><a name="zh-cn_topic_0000001312471157_p1616385216275"></a><a name="zh-cn_topic_0000001312471157_p1616385216275"></a>dynamic_name_attr_value</p>
</td>
<td class="cellrowborder" valign="top" width="19.931993199319933%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312471157_p1523716182710"><a name="zh-cn_topic_0000001312471157_p1523716182710"></a><a name="zh-cn_topic_0000001312471157_p1523716182710"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.434843484348434%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312471157_p0826915112813"><a name="zh-cn_topic_0000001312471157_p0826915112813"></a><a name="zh-cn_topic_0000001312471157_p0826915112813"></a>描述动态输入输出实际个数，<strong id="zh-cn_topic_0000001312471157_b093194812490"><a name="zh-cn_topic_0000001312471157_b093194812490"></a><a name="zh-cn_topic_0000001312471157_b093194812490"></a>DynamicInputOutputInfo</strong>数据结构请参见<a href="#zh-cn_topic_0000001312471157_section78486175398">DynamicInputOutputInfo数据结构说明</a>。</p>
</td>
</tr>
</tbody>
</table>

## DynamicInputOutputInfo数据结构说明<a name="zh-cn_topic_0000001312471157_section78486175398"></a>

```
constexpr int64_t kMaxNameLength = 1048576; // 1M
enum DynamicType : int16_t {
  kInvalid = 0,
  kInput = 1,
  kOutput = 2
};
struct DynamicInputOutputInfo {
  DynamicType type; // input/output
  const char_t *port_name;
  int64_t port_name_len;
  const char_t *attr_name;
  int64_t attr_name_len;
  DynamicInputOutputInfo(const DynamicType type_instance, const char_t *const port_name_instance,
                         const int64_t port_name_len_instance, const char_t *const attr_name_instance,
                         const int64_t attr_name_len_instance)
      : type(type_instance), port_name(port_name_instance), port_name_len(port_name_len_instance),
        attr_name(attr_name_instance), attr_name_len(attr_name_len_instance) {}
  DynamicInputOutputInfo() : DynamicInputOutputInfo(kInvalid, nullptr, 0L, nullptr, 0L) {}
};
```

<a name="zh-cn_topic_0000001312471157_table188904407426"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312471157_row889016401428"><th class="cellrowborder" valign="top" width="36.05%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001312471157_p689094016420"><a name="zh-cn_topic_0000001312471157_p689094016420"></a><a name="zh-cn_topic_0000001312471157_p689094016420"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="63.949999999999996%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001312471157_p16891204019421"><a name="zh-cn_topic_0000001312471157_p16891204019421"></a><a name="zh-cn_topic_0000001312471157_p16891204019421"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312471157_row1889194064219"><td class="cellrowborder" valign="top" width="36.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001312471157_p68051049134211"><a name="zh-cn_topic_0000001312471157_p68051049134211"></a><a name="zh-cn_topic_0000001312471157_p68051049134211"></a><strong id="zh-cn_topic_0000001312471157_b08057496424"><a name="zh-cn_topic_0000001312471157_b08057496424"></a><a name="zh-cn_topic_0000001312471157_b08057496424"></a>type</strong></p>
</td>
<td class="cellrowborder" valign="top" width="63.949999999999996%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001312471157_p87721840104314"><a name="zh-cn_topic_0000001312471157_p87721840104314"></a><a name="zh-cn_topic_0000001312471157_p87721840104314"></a>指定是动态输入或输出。</p>
<p id="zh-cn_topic_0000001312471157_p1318791125214"><a name="zh-cn_topic_0000001312471157_p1318791125214"></a><a name="zh-cn_topic_0000001312471157_p1318791125214"></a>0：无效值</p>
<p id="zh-cn_topic_0000001312471157_p44488735215"><a name="zh-cn_topic_0000001312471157_p44488735215"></a><a name="zh-cn_topic_0000001312471157_p44488735215"></a>1：输入</p>
<p id="zh-cn_topic_0000001312471157_p113779165219"><a name="zh-cn_topic_0000001312471157_p113779165219"></a><a name="zh-cn_topic_0000001312471157_p113779165219"></a>2：输出</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312471157_row19891184094210"><td class="cellrowborder" valign="top" width="36.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001312471157_p1389124054216"><a name="zh-cn_topic_0000001312471157_p1389124054216"></a><a name="zh-cn_topic_0000001312471157_p1389124054216"></a><strong id="zh-cn_topic_0000001312471157_b1069751064315"><a name="zh-cn_topic_0000001312471157_b1069751064315"></a><a name="zh-cn_topic_0000001312471157_b1069751064315"></a>port_name</strong></p>
</td>
<td class="cellrowborder" valign="top" width="63.949999999999996%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001312471157_p389110407421"><a name="zh-cn_topic_0000001312471157_p389110407421"></a><a name="zh-cn_topic_0000001312471157_p389110407421"></a>端口名字，输入或者输出的Name。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312471157_row389119405422"><td class="cellrowborder" valign="top" width="36.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001312471157_p11891440194218"><a name="zh-cn_topic_0000001312471157_p11891440194218"></a><a name="zh-cn_topic_0000001312471157_p11891440194218"></a><strong id="zh-cn_topic_0000001312471157_b11201132014313"><a name="zh-cn_topic_0000001312471157_b11201132014313"></a><a name="zh-cn_topic_0000001312471157_b11201132014313"></a>port_name_len</strong></p>
</td>
<td class="cellrowborder" valign="top" width="63.949999999999996%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001312471157_p15538137144418"><a name="zh-cn_topic_0000001312471157_p15538137144418"></a><a name="zh-cn_topic_0000001312471157_p15538137144418"></a>端口名字长度，最大长度为<strong id="zh-cn_topic_0000001312471157_b86711055184411"><a name="zh-cn_topic_0000001312471157_b86711055184411"></a><a name="zh-cn_topic_0000001312471157_b86711055184411"></a>kMaxNameLength</strong>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312471157_row1116272774314"><td class="cellrowborder" valign="top" width="36.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001312471157_p81621827154312"><a name="zh-cn_topic_0000001312471157_p81621827154312"></a><a name="zh-cn_topic_0000001312471157_p81621827154312"></a><strong id="zh-cn_topic_0000001312471157_b848614352436"><a name="zh-cn_topic_0000001312471157_b848614352436"></a><a name="zh-cn_topic_0000001312471157_b848614352436"></a>attr_name</strong></p>
</td>
<td class="cellrowborder" valign="top" width="63.949999999999996%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001312471157_p12162202714438"><a name="zh-cn_topic_0000001312471157_p12162202714438"></a><a name="zh-cn_topic_0000001312471157_p12162202714438"></a>属性名字。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312471157_row6915123044318"><td class="cellrowborder" valign="top" width="36.05%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001312471157_p15915133016439"><a name="zh-cn_topic_0000001312471157_p15915133016439"></a><a name="zh-cn_topic_0000001312471157_p15915133016439"></a><strong id="zh-cn_topic_0000001312471157_b10676438204517"><a name="zh-cn_topic_0000001312471157_b10676438204517"></a><a name="zh-cn_topic_0000001312471157_b10676438204517"></a>attr_name_len</strong></p>
</td>
<td class="cellrowborder" valign="top" width="63.949999999999996%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001312471157_p17915133013439"><a name="zh-cn_topic_0000001312471157_p17915133013439"></a><a name="zh-cn_topic_0000001312471157_p17915133013439"></a>属性名字长度，最大长度为<strong id="zh-cn_topic_0000001312471157_b15438174211454"><a name="zh-cn_topic_0000001312471157_b15438174211454"></a><a name="zh-cn_topic_0000001312471157_b15438174211454"></a>kMaxNameLength</strong>。</p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001312471157_section10601131863619"></a>

```
Status QueueDequeueUpToMapping(const  ge::Operator& op_src, ge::Operator& op) {
vector<DynamicInputOutputInfo> dynamic_name_attr_value;
string port_name = "components";
string attr_name = "component_types";
DynamicInputOutputInfo name_attr(kOutput, port_name.c_str(), port_name.size(), attr_name.c_str(), attr_name.size());
dynamic_name_attr_value.push_back(name_attr);
AutoMappingByOpFnDynamic(op_src, op, dynamic_name_attr_value);
return SUCCESS;
}

REGISTER_CUSTOM_OP("QueueDequeueUpTo")
.FrameworkType(TENSORFLOW)
.OriginOpType("QueueDequeueUpToV2")
.ParseParamsByOperatorFn(QueueDequeueUpToMapping)
.ImplyType(ImplyType::AI_CPU);
```

