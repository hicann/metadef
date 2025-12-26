# AutoMappingFn<a name="ZH-CN_TOPIC_0000002079121249"></a>

## 函数功能<a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_section34261011"></a>

自动映射回调函数。

## 函数原型<a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_section39913650"></a>

```
Status AutoMappingFn(const google::protobuf::Message *op_src, ge::Operator &op)
```

## 参数说明<a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_section23678531"></a>

<a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_table24696155"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_row1801909"><th class="cellrowborder" valign="top" width="27.002700270027002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11736918"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11736918"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11736918"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="23.92239223922392%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11166333"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11166333"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11166333"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="49.07490749074908%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p32057743"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p32057743"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p32057743"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_row46540406"><td class="cellrowborder" valign="top" width="27.002700270027002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11676570"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11676570"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p11676570"></a>op_src</p>
</td>
<td class="cellrowborder" valign="top" width="23.92239223922392%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p6278114"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p6278114"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p6278114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.07490749074908%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p38765239"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p38765239"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p38765239"></a>转换前原始模型中的算子，包含原始模型中算子的属性。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_row13342833"><td class="cellrowborder" valign="top" width="27.002700270027002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p7027716"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p7027716"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p7027716"></a>op</p>
</td>
<td class="cellrowborder" valign="top" width="23.92239223922392%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p32374103"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p32374103"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p32374103"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.07490749074908%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p5056658"><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p5056658"></a><a name="zh-cn_topic_0000001265071202_zh-cn_topic_0204328260_p5056658"></a>适配<span id="zh-cn_topic_0000001265071202_ph1555712386204"><a name="zh-cn_topic_0000001265071202_ph1555712386204"></a><a name="zh-cn_topic_0000001265071202_ph1555712386204"></a>昇腾AI处理器</span>的算子。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001265071202_section05033452010"></a>

若原始TensorFlow算子与适配昇腾AI处理器的算子属性无法一一映射，AutoMappingFn函数无法应用于回调函数[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)中，此种场景下，请在回调函数[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)中使用[AutoMappingByOpFn](AutoMappingByOpFn.md)接口进行可以映射成功的属性的自动解析，使用示例请参见[调用示例](AutoMappingByOpFn.md#zh-cn_topic_0000001312390161_section327333519322)。

