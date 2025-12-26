# InputReorderVector<a name="ZH-CN_TOPIC_0000002043042188"></a>

## 函数功能<a name="zh-cn_topic_0000001312390165_section8062655"></a>

支持在算子插件中调整算子的输入参数顺序，此接口为内部使用接口，外部开发者无需关注。

## 函数原型<a name="zh-cn_topic_0000001312390165_section5455038"></a>

```
OpRegistrationData &InputReorderVector(const std::vector<int32_t> &input_order)
```

## 参数说明<a name="zh-cn_topic_0000001312390165_section49095346"></a>

<a name="zh-cn_topic_0000001312390165_table62441623"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312390165_row47897641"><th class="cellrowborder" valign="top" width="24.782478247824784%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312390165_p54503731"><a name="zh-cn_topic_0000001312390165_p54503731"></a><a name="zh-cn_topic_0000001312390165_p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="26.882688268826882%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312390165_p52726081"><a name="zh-cn_topic_0000001312390165_p52726081"></a><a name="zh-cn_topic_0000001312390165_p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="48.33483348334833%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312390165_p42954172"><a name="zh-cn_topic_0000001312390165_p42954172"></a><a name="zh-cn_topic_0000001312390165_p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312390165_row56735883"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312390165_p075571185917"><a name="zh-cn_topic_0000001312390165_p075571185917"></a><a name="zh-cn_topic_0000001312390165_p075571185917"></a>input_order</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312390165_p58370887"><a name="zh-cn_topic_0000001312390165_p58370887"></a><a name="zh-cn_topic_0000001312390165_p58370887"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312390165_p30421379"><a name="zh-cn_topic_0000001312390165_p30421379"></a><a name="zh-cn_topic_0000001312390165_p30421379"></a>算子输入的调整列表， 下标表示原输入索引，下标对应的值表示调整后新的输入索引。例如：第三方框架的算子A对应的<span id="zh-cn_topic_0000001312390165_ph1555712386204"><a name="zh-cn_topic_0000001312390165_ph1555712386204"></a><a name="zh-cn_topic_0000001312390165_ph1555712386204"></a>昇腾AI处理器</span>算子为AD，原输入0为in0， 原输入1为in1，原输入2为in2，插件调用接口传入input_order = {1，0，2}，那么解析后算子AD的输入0为in1， 输入1为in0，输入2为in2。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0000001312390165_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

OpRegistrationData类的引用。

## 异常处理<a name="zh-cn_topic_0000001312390165_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001312390165_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

