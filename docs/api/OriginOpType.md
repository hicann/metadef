# OriginOpType<a name="ZH-CN_TOPIC_0000002079121229"></a>

## 函数功能<a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_section61880099"></a>

设置原始模型的算子类型或算子类型列表。

## 函数原型<a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_section20049984"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
OpRegistrationData &OriginOpType(const std::vector<ge::AscendString> &ori_op_type_list)
OpRegistrationData &OriginOpType(const char_t *ori_op_type)
OpRegistrationData &OriginOpType(const std::initializer_list<std::string> &ori_optype_list)
OpRegistrationData &OriginOpType(const std::string &ori_optype)
```

## 参数说明<a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_section46232128"></a>

<a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_table23516190"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_row52223563"><th class="cellrowborder" valign="top" width="29.722972297229727%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p2250249"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p2250249"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p2250249"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="23.732373237323735%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p48052491"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p48052491"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p48052491"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="46.54465446544654%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p67046586"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p67046586"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p67046586"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_row62064381"><td class="cellrowborder" valign="top" width="29.722972297229727%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p61158973"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p61158973"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p61158973"></a>ori_op_type_list/ori_optype_list</p>
</td>
<td class="cellrowborder" valign="top" width="23.732373237323735%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p54929761"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p54929761"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p54929761"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46.54465446544654%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p20125650"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p20125650"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p20125650"></a>原始模型算子类型列表。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_row468473095818"><td class="cellrowborder" valign="top" width="29.722972297229727%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p9296266"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p9296266"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p9296266"></a>ori_op_type/ori_optype</p>
</td>
<td class="cellrowborder" valign="top" width="23.732373237323735%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p14800081"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p14800081"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p14800081"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46.54465446544654%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p57955904"><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p57955904"></a><a name="zh-cn_topic_0000001312631149_zh-cn_topic_0204328136_p57955904"></a>原始模型算子类型。</p>
</td>
</tr>
</tbody>
</table>

