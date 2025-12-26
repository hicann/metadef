# AutoMappingSubgraphIndex<a name="ZH-CN_TOPIC_0000002079121253"></a>

## 函数功能<a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_section8722525"></a>

设置子图的输入输出和主图对应父节点输入输出的对应关系。

## 函数原型<a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_section11393865"></a>

```
Status AutoMappingSubgraphIndex(const ge::Graph &graph,
const std::function<int32_t(int32_t data_index)> &input,
const std::function<int32_t(int32_t netoutput_index)> &output)
Status AutoMappingSubgraphIndex(const ge::Graph &graph,
const std::function<Status(int32_t data_index, int32_t &parent_input_index)> &input,
const std::function<Status(int32_t netoutput_index, int32_t &parent_output_index)> &output)
```

## 参数说明<a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_section35435929"></a>

<a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_table28443956"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_row13063050"><th class="cellrowborder" valign="top" width="25.402540254025403%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p51474147"><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p51474147"></a><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p51474147"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="26.512651265126514%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p8656348"><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p8656348"></a><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p8656348"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="48.08480848084808%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p30075549"><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p30075549"></a><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p30075549"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_row20200399"><td class="cellrowborder" valign="top" width="25.402540254025403%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p25619609"><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p25619609"></a><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p25619609"></a>graph</p>
</td>
<td class="cellrowborder" valign="top" width="26.512651265126514%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p61922468"><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p61922468"></a><a name="zh-cn_topic_0000001312631157_zh-cn_topic_0204328201_p61922468"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.08480848084808%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312631157_p92336130154"><a name="zh-cn_topic_0000001312631157_p92336130154"></a><a name="zh-cn_topic_0000001312631157_p92336130154"></a>子图对象。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312631157_row254511280318"><td class="cellrowborder" valign="top" width="25.402540254025403%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312631157_p15545152873117"><a name="zh-cn_topic_0000001312631157_p15545152873117"></a><a name="zh-cn_topic_0000001312631157_p15545152873117"></a>input</p>
</td>
<td class="cellrowborder" valign="top" width="26.512651265126514%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312631157_p892714963110"><a name="zh-cn_topic_0000001312631157_p892714963110"></a><a name="zh-cn_topic_0000001312631157_p892714963110"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.08480848084808%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312631157_p11545142816310"><a name="zh-cn_topic_0000001312631157_p11545142816310"></a><a name="zh-cn_topic_0000001312631157_p11545142816310"></a>输入对应关系函数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312631157_row121151232133118"><td class="cellrowborder" valign="top" width="25.402540254025403%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312631157_p14116532183111"><a name="zh-cn_topic_0000001312631157_p14116532183111"></a><a name="zh-cn_topic_0000001312631157_p14116532183111"></a>output</p>
</td>
<td class="cellrowborder" valign="top" width="26.512651265126514%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312631157_p1569345033118"><a name="zh-cn_topic_0000001312631157_p1569345033118"></a><a name="zh-cn_topic_0000001312631157_p1569345033118"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.08480848084808%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312631157_p1435145112320"><a name="zh-cn_topic_0000001312631157_p1435145112320"></a><a name="zh-cn_topic_0000001312631157_p1435145112320"></a>输出对应关系函数。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001312631157_section1386084611573"></a>

无。

