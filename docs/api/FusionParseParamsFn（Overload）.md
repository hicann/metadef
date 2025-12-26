# FusionParseParamsFn（Overload）<a name="ZH-CN_TOPIC_0000002079121233"></a>

## 函数功能<a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_section37097208"></a>

注册解析融合算子属性的函数，为[FusionParseParamsFn](FusionParseParamsFn.md)的重载函数。

## 函数原型<a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_section65439422"></a>

```
[OpRegistrationData](OpRegistrationData.md) &FusionParseParamsFn(const FusionParseParamByOpFunc &fusion_parse_param_fn)
```

## 参数说明<a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_section1887443012563"></a>

<a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_table62872389"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_row66002319"><th class="cellrowborder" valign="top" width="35.24352435243524%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p44587619"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p44587619"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p44587619"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.23182318231823%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p54827416"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p54827416"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p54827416"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="46.524652465246525%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p11835734"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p11835734"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p11835734"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_row19170372"><td class="cellrowborder" valign="top" width="35.24352435243524%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p9296266"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p9296266"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p9296266"></a><strong id="zh-cn_topic_0000001265231138_b08211373163"><a name="zh-cn_topic_0000001265231138_b08211373163"></a><a name="zh-cn_topic_0000001265231138_b08211373163"></a>fusion_parse_param_fn</strong></p>
</td>
<td class="cellrowborder" valign="top" width="18.23182318231823%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p14800081"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p14800081"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p14800081"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46.524652465246525%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p57955904"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p57955904"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_p57955904"></a>解析融合算子属性的函数，请参见<a href="#zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_section1616524114512">回调函数FusionParseParamByOpFunc</a>。</p>
</td>
</tr>
</tbody>
</table>

## 回调函数FusionParseParamByOpFunc<a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_section1616524114512"></a>

用户自定义并实现FusionParseParamByOpFunc类函数，完成原始模型中属性到适配昇腾AI处理器的模型中的属性映射，将结果填到Operator类中。

```
Status FusionParseParamByOpFunc(const std::vector<ge::Operator> &op_src,  ge::Operator &op_dest)
```

**表 1**  参数说明

<a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_tea4eb56e24b5422d933f942744f3e44f"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_raf8a886956274b34adbc0b473b8a1686"><th class="cellrowborder" valign="top" width="24.66%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a132b98dc7f5a4e029507fff0b0b869dc"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a132b98dc7f5a4e029507fff0b0b869dc"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a132b98dc7f5a4e029507fff0b0b869dc"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.37%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p162611451392"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p162611451392"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_zh-cn_topic_0146627780_p162611451392"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="56.97%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a29b1846e29d04bdb9a05667ebe0586e9"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a29b1846e29d04bdb9a05667ebe0586e9"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a29b1846e29d04bdb9a05667ebe0586e9"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_r58000c6a6c084d248cf511e74e3432e8"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001265231138_p69144610206"><a name="zh-cn_topic_0000001265231138_p69144610206"></a><a name="zh-cn_topic_0000001265231138_p69144610206"></a>op_src</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a017d79597436477eae60095f3706527a"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a017d79597436477eae60095f3706527a"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a017d79597436477eae60095f3706527a"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="56.97%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001265231138_p2021014424327"><a name="zh-cn_topic_0000001265231138_p2021014424327"></a><a name="zh-cn_topic_0000001265231138_p2021014424327"></a>一组scope内存储原始模型中算子属性的融合算子数据结构。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_re501fa4b22e449ad867186f3f3f11fb5"><td class="cellrowborder" valign="top" width="24.66%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a6882317840f14b4a82a54733be115b20"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a6882317840f14b4a82a54733be115b20"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a6882317840f14b4a82a54733be115b20"></a>op_dest</p>
</td>
<td class="cellrowborder" valign="top" width="18.37%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a5eda2c4cf0ab4cb4b187e56611a0ed82"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a5eda2c4cf0ab4cb4b187e56611a0ed82"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a5eda2c4cf0ab4cb4b187e56611a0ed82"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="56.97%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a14e68afc13a048d8ba79f2b6f921b9af"><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a14e68afc13a048d8ba79f2b6f921b9af"></a><a name="zh-cn_topic_0000001265231138_zh-cn_topic_0204328255_a14e68afc13a048d8ba79f2b6f921b9af"></a>融合算子数据结构，保存融合算子信息。</p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001265231138_section6125153523615"></a>

```
REGISTER_CUSTOM_OP(XXXXXX)
.FrameworkType(TENSORFLOW)
.FusionParseParamsFn(FusionParseParamsFn)
.OriginOpType(XXXXX)
.ImplyType(XXXXX);
```

