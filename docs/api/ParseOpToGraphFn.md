# ParseOpToGraphFn<a name="ZH-CN_TOPIC_0000002079199845"></a>

## 函数功能<a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_section8722525"></a>

注册实现算子一对多子图映射的函数，即将算子映射为多个算子。

## 函数原型<a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_section11393865"></a>

```
[OpRegistrationData](OpRegistrationData.md) &ParseOpToGraphFn(const ParseOpToGraphFunc &parse_op_to_graph_fn)
```

## 参数说明<a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_section35435929"></a>

<a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_table28443956"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_row13063050"><th class="cellrowborder" valign="top" width="31.633163316331636%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p51474147"><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p51474147"></a><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p51474147"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.35183518351835%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p8656348"><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p8656348"></a><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p8656348"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="50.015001500150014%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p30075549"><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p30075549"></a><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p30075549"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_row20200399"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p25619609"><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p25619609"></a><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p25619609"></a>parse_op_to_graph_fn</p>
</td>
<td class="cellrowborder" valign="top" width="18.35183518351835%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p61922468"><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p61922468"></a><a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328201_p61922468"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.015001500150014%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265390050_p1237621211510"><a name="zh-cn_topic_0000001265390050_p1237621211510"></a><a name="zh-cn_topic_0000001265390050_p1237621211510"></a>实现算子一对多映射，进行子图构造的函数。</p>
<p id="zh-cn_topic_0000001265390050_p92336130154"><a name="zh-cn_topic_0000001265390050_p92336130154"></a><a name="zh-cn_topic_0000001265390050_p92336130154"></a>请参见<a href="#zh-cn_topic_0000001265390050_zh-cn_topic_0204328255_section1616524114512">回调函数ParseOpToGraphFunc </a>。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001265390050_section1386084611573"></a>

实现一对多子图映射时，插件注册时首先需要将原始框架中的算子映射成昇腾AI处理器中的PartitionedCall算子，并在[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)函数中使用“SetAttr”接口设置original\_type。

实现样例请参见[调用示例](#zh-cn_topic_0000001265390050_section1072072914166)。

## 回调函数ParseOpToGraphFunc<a name="zh-cn_topic_0000001265390050_zh-cn_topic_0204328255_section1616524114512"></a>

****用户自定义并实现ParseOpToGraphFunc函数，通过IR模型构建方式完成一对多子图的构造，构图详细介绍请参考《图模式开发指南》****。

回调函数原型定义如下：

```
Status  ParseOpToGraphFunc(const ge::Operator &op,  ge::Graph &graph)
```

**表 1**  参数说明

<a name="zh-cn_topic_0000001265390050_table741321312579"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265390050_row441401375717"><th class="cellrowborder" valign="top" width="24.66%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001265390050_p194143136577"><a name="zh-cn_topic_0000001265390050_p194143136577"></a><a name="zh-cn_topic_0000001265390050_p194143136577"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="19.61%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001265390050_p10414191325719"><a name="zh-cn_topic_0000001265390050_p10414191325719"></a><a name="zh-cn_topic_0000001265390050_p10414191325719"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="55.730000000000004%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001265390050_p10414113155714"><a name="zh-cn_topic_0000001265390050_p10414113155714"></a><a name="zh-cn_topic_0000001265390050_p10414113155714"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265390050_row1941451325712"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001265390050_p12414141317577"><a name="zh-cn_topic_0000001265390050_p12414141317577"></a><a name="zh-cn_topic_0000001265390050_p12414141317577"></a>op</p>
</td>
<td class="cellrowborder" valign="top" width="19.61%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001265390050_p124141813175716"><a name="zh-cn_topic_0000001265390050_p124141813175716"></a><a name="zh-cn_topic_0000001265390050_p124141813175716"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="55.730000000000004%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001265390050_p5414191315715"><a name="zh-cn_topic_0000001265390050_p5414191315715"></a><a name="zh-cn_topic_0000001265390050_p5414191315715"></a>PartitionedCall算子数据结构，Operator类对象。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001265390050_row1041413132574"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001265390050_p0414101314571"><a name="zh-cn_topic_0000001265390050_p0414101314571"></a><a name="zh-cn_topic_0000001265390050_p0414101314571"></a>graph</p>
</td>
<td class="cellrowborder" valign="top" width="19.61%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001265390050_p74141913105712"><a name="zh-cn_topic_0000001265390050_p74141913105712"></a><a name="zh-cn_topic_0000001265390050_p74141913105712"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="55.730000000000004%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001265390050_p7626114617576"><a name="zh-cn_topic_0000001265390050_p7626114617576"></a><a name="zh-cn_topic_0000001265390050_p7626114617576"></a>构造的子图。</p>
</td>
</tr>
</tbody>
</table>

子图输入输出关系构建方式如下：

-   输入：通过添加Data节点标识，Data节点的index属性表示原节点的第index个输入边。
-   输出：通过Graph::SetOutputs\(\)接口设置，该接口的入参为**std::vector<std::pair<Operator, std::vector<size\_t\>\>\>**，输出边按照设置的输出顺序相连。

## 调用示例<a name="zh-cn_topic_0000001265390050_section1072072914166"></a>

以将Add算子转换成AddN+Abs为例。

实现Add算子到PartitionedCall算子的映射函数示例如下所示：

```
Status ParseParams(const ge::Operator &op_src, ge::Operator& op_dest)
{
    ...
    op_dest.SetAttr("original_type", "ai.onnx::11::Add");
}
```

一对多子图构造函数实现示例如下所示：

```
static Status ParseOpToGraph(const Operator &op, Graph &graph) {
  auto data_0 = op::Data().set_attr_index(0);
  auto data_1 = op::Data().set_attr_index(1);
  auto addn = op::AddN("addn_sum").create_dynamic_input_x(2)
      .set_dynamic_input_x(0, data_0)
      .set_dynamic_input_x(1, data_1)
      .set_attr_N(2);
  auto abs = op::Abs("abs_sum").set_input_x(addn);
  std::vector<Operator> inputs{data_0, data_1};
  std::vector<std::pair<Operator, std::vector<size_t>>> output_indexs;
  output_indexs.emplace_back(abs, vector<std::size_t>{0});
  graph.SetInputs(inputs).SetOutputs(output_indexs);
  return domi::SUCCESS;
}
```

进行注册：

```
REGISTER_CUSTOM_OP("PartitionedCall")
.FrameworkType(xx)
.OriginOpType(xx)
.ParseParamsByOperatorFn(ParseParams)
.ParseOpToGraphFn(ParseOpToGraph)
.ImplyType(ImplyType::TVM);
```

[图1](#zh-cn_topic_0000001265390050_fig203579115392)为将Add算子进行一对多子图映射后的示例。

**图 1**  一对多转换示意图<a name="zh-cn_topic_0000001265390050_fig203579115392"></a>  
![](figures/一对多转换示意图.png "一对多转换示意图")

