# FusionParseParamsFn<a name="ZH-CN_TOPIC_0000002043200496"></a>

## 函数功能<a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_section37097208"></a>

注册解析融合算子属性的函数。

## 函数原型<a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_section65439422"></a>

```
[OpRegistrationData](OpRegistrationData.md) &FusionParseParamsFn(const FusionParseParamFunc &fusionParseParamFn)
```

## 参数说明<a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_section1887443012563"></a>

<a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_table62872389"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_row66002319"><th class="cellrowborder" valign="top" width="31.633163316331636%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p44587619"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p44587619"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p44587619"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="19.2019201920192%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p54827416"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p54827416"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p54827416"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="49.164916491649166%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p11835734"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p11835734"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p11835734"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_row19170372"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p9296266"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p9296266"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p9296266"></a>fusionParseParamFn</p>
</td>
<td class="cellrowborder" valign="top" width="19.2019201920192%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p14800081"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p14800081"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p14800081"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="49.164916491649166%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p57955904"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p57955904"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_p57955904"></a>解析融合算子属性的函数，请参见<a href="#zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_section1616524114512">回调函数FusionParseParamFunc</a>。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001265071210_section05033452010"></a>

对于融合算子插件，FusionParseParamsFn接口后续版本将会废弃，请使用[FusionParseParamsFn（Overload）](FusionParseParamsFn（Overload）.md)接口进行融合算子属性的解析。

## 回调函数FusionParseParamFunc<a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_section1616524114512"></a>

用户自定义并实现FusionParseParamFunc类函数，完成原始模型中属性到适配昇腾AI处理器的模型中属性的映射，将结果填到Operator类中。

```
Status FusionParseParamFunc(const  vector<const google::protobuf::Message *> &v_op_origin, ge::Operator  &op_dest)
```

**表 1**  参数说明

<a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_tea4eb56e24b5422d933f942744f3e44f"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_raf8a886956274b34adbc0b473b8a1686"><th class="cellrowborder" valign="top" width="24.66%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a132b98dc7f5a4e029507fff0b0b869dc"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a132b98dc7f5a4e029507fff0b0b869dc"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a132b98dc7f5a4e029507fff0b0b869dc"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="19.61%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p162611451392"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p162611451392"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p162611451392"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="55.730000000000004%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a29b1846e29d04bdb9a05667ebe0586e9"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a29b1846e29d04bdb9a05667ebe0586e9"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a29b1846e29d04bdb9a05667ebe0586e9"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_r58000c6a6c084d248cf511e74e3432e8"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p676563843918"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p676563843918"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p676563843918"></a>v_op_origin</p>
</td>
<td class="cellrowborder" valign="top" width="19.61%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a017d79597436477eae60095f3706527a"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a017d79597436477eae60095f3706527a"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a017d79597436477eae60095f3706527a"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="55.730000000000004%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001265071210_p2021014424327"><a name="zh-cn_topic_0000001265071210_p2021014424327"></a><a name="zh-cn_topic_0000001265071210_p2021014424327"></a>一组scope内的protobuf格式的数据结构（来源于原始模型的prototxt文件），包含算子属性信息。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_re501fa4b22e449ad867186f3f3f11fb5"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a6882317840f14b4a82a54733be115b20"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a6882317840f14b4a82a54733be115b20"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a6882317840f14b4a82a54733be115b20"></a>op_dest</p>
</td>
<td class="cellrowborder" valign="top" width="19.61%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a5eda2c4cf0ab4cb4b187e56611a0ed82"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a5eda2c4cf0ab4cb4b187e56611a0ed82"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a5eda2c4cf0ab4cb4b187e56611a0ed82"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="55.730000000000004%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a14e68afc13a048d8ba79f2b6f921b9af"><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a14e68afc13a048d8ba79f2b6f921b9af"></a><a name="zh-cn_topic_0000001265071210_zh-cn_topic_0204328255_a14e68afc13a048d8ba79f2b6f921b9af"></a>融合算子数据结构，保存融合算子信息。</p>
</td>
</tr>
</tbody>
</table>

