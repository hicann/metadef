# ParseSubgraphPostFn<a name="ZH-CN_TOPIC_0000002043042168"></a>

## 函数功能<a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_section8722525"></a>

根据算子类型，注册算子的子图中输入输出节点跟算子的输入输出的对应关系函数实现。

## 函数原型<a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_section11393865"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
OpRegistrationData &ParseSubgraphPostFn(const ParseSubgraphFunc &subgraph_post_fn)
OpRegistrationData &ParseSubgraphPostFn(const ParseSubgraphFuncV2 &subgraph_post_fn)
```

## 参数说明<a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_section35435929"></a>

<a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_table28443956"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_row13063050"><th class="cellrowborder" valign="top" width="31.633163316331636%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p51474147"><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p51474147"></a><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p51474147"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.35183518351835%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p8656348"><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p8656348"></a><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p8656348"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="50.015001500150014%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p30075549"><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p30075549"></a><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p30075549"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_row20200399"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p25619609"><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p25619609"></a><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p25619609"></a>subgraph_post_fn</p>
</td>
<td class="cellrowborder" valign="top" width="18.35183518351835%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p61922468"><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p61922468"></a><a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328201_p61922468"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.015001500150014%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312471153_p92336130154"><a name="zh-cn_topic_0000001312471153_p92336130154"></a><a name="zh-cn_topic_0000001312471153_p92336130154"></a>子图中输入输出节点跟算子的输入输出的对应关系函数对象。</p>
<p id="zh-cn_topic_0000001312471153_p1272212818324"><a name="zh-cn_topic_0000001312471153_p1272212818324"></a><a name="zh-cn_topic_0000001312471153_p1272212818324"></a>详见<strong id="zh-cn_topic_0000001312471153_b294616453311"><a name="zh-cn_topic_0000001312471153_b294616453311"></a><a name="zh-cn_topic_0000001312471153_b294616453311"></a><a href="#zh-cn_topic_0000001312471153_zh-cn_topic_0204328255_section1616524114512">回调函数ParseSubgraphFuncV2</a>。</strong></p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001312471153_section1386084611573"></a>

无。

## 回调函数ParseSubgraphFuncV2<a name="zh-cn_topic_0000001312471153_zh-cn_topic_0204328255_section1616524114512"></a>

****用户自定义并实现ParseSubgraphFuncV2函数，完成解析子图中输入输出节点跟算子的输入输出的对应关系功能，****回调函数原型定义如下：

```
Status ParseSubgraphFuncV2(const ge::AscendString &subgraph_name, const ge::Graph &graph)
```

**表 1**  参数说明

<a name="zh-cn_topic_0000001312471153_table741321312579"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312471153_row441401375717"><th class="cellrowborder" valign="top" width="24.66%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001312471153_p194143136577"><a name="zh-cn_topic_0000001312471153_p194143136577"></a><a name="zh-cn_topic_0000001312471153_p194143136577"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="19.61%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001312471153_p10414191325719"><a name="zh-cn_topic_0000001312471153_p10414191325719"></a><a name="zh-cn_topic_0000001312471153_p10414191325719"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="55.730000000000004%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001312471153_p10414113155714"><a name="zh-cn_topic_0000001312471153_p10414113155714"></a><a name="zh-cn_topic_0000001312471153_p10414113155714"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312471153_row1941451325712"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001312471153_p12414141317577"><a name="zh-cn_topic_0000001312471153_p12414141317577"></a><a name="zh-cn_topic_0000001312471153_p12414141317577"></a>subgraph_name</p>
</td>
<td class="cellrowborder" valign="top" width="19.61%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001312471153_p124141813175716"><a name="zh-cn_topic_0000001312471153_p124141813175716"></a><a name="zh-cn_topic_0000001312471153_p124141813175716"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="55.730000000000004%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001312471153_p5414191315715"><a name="zh-cn_topic_0000001312471153_p5414191315715"></a><a name="zh-cn_topic_0000001312471153_p5414191315715"></a>子图名字。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312471153_row1041413132574"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001312471153_p0414101314571"><a name="zh-cn_topic_0000001312471153_p0414101314571"></a><a name="zh-cn_topic_0000001312471153_p0414101314571"></a>graph</p>
</td>
<td class="cellrowborder" valign="top" width="19.61%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001312471153_p74141913105712"><a name="zh-cn_topic_0000001312471153_p74141913105712"></a><a name="zh-cn_topic_0000001312471153_p74141913105712"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="55.730000000000004%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001312471153_p7626114617576"><a name="zh-cn_topic_0000001312471153_p7626114617576"></a><a name="zh-cn_topic_0000001312471153_p7626114617576"></a>构造的子图。</p>
</td>
</tr>
</tbody>
</table>

