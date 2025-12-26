# ParseParamsFn<a name="ZH-CN_TOPIC_0000002043042164"></a>

## 函数功能<a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_section37097208"></a>

注册解析算子属性的函数。

## 函数原型<a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_section65439422"></a>

```
[OpRegistrationData](OpRegistrationData.md) &ParseParamsFn(const ParseParamFunc &parseParamFn)
```

## 参数说明<a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_section1887443012563"></a>

<a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_table62872389"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_row66002319"><th class="cellrowborder" valign="top" width="26.142614261426147%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p44587619"><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p44587619"></a><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p44587619"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="17.731773177317734%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p54827416"><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p54827416"></a><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p54827416"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="56.12561256125613%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p11835734"><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p11835734"></a><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p11835734"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_row19170372"><td class="cellrowborder" valign="top" width="26.142614261426147%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p9296266"><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p9296266"></a><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p9296266"></a>parseParamFn</p>
</td>
<td class="cellrowborder" valign="top" width="17.731773177317734%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p14800081"><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p14800081"></a><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p14800081"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="56.12561256125613%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p57955904"><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p57955904"></a><a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_p57955904"></a>解析算子属性的函数ParseParamFunc，请参见<a href="#zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_section1616524114512">回调函数ParseParamFunc</a>。</p>
<p id="zh-cn_topic_0000001312631145_p117841357135613"><a name="zh-cn_topic_0000001312631145_p117841357135613"></a><a name="zh-cn_topic_0000001312631145_p117841357135613"></a>针对<span id="zh-cn_topic_0000001312631145_ph9399315144315"><a name="zh-cn_topic_0000001312631145_ph9399315144315"></a><a name="zh-cn_topic_0000001312631145_ph9399315144315"></a>TensorFlow</span>框架，若原始<span id="zh-cn_topic_0000001312631145_ph16498414184416"><a name="zh-cn_topic_0000001312631145_ph16498414184416"></a><a name="zh-cn_topic_0000001312631145_ph16498414184416"></a>TensorFlow</span>框架算子属性与适配<span id="zh-cn_topic_0000001312631145_ph169871310634"><a name="zh-cn_topic_0000001312631145_ph169871310634"></a><a name="zh-cn_topic_0000001312631145_ph169871310634"></a>昇腾AI处理器</span>的模型中算子属性一一对应（属性个数与顺序一致），可直接使用<a href="AutoMappingFn.md">AutoMappingFn</a>函数自动实现映射。</p>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001312631145_section05033452010"></a>

对于自定义算子插件，ParseParamsFn后续版本将会废弃，请使用[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)接口进行算子属性的解析。

若用户已使用ParseParamsFn接口进行了算子插件的开发，请执行如下操作进行新接口适配：

1.  请重新使用[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)接口进行算子插件的开发。
2.  请基于新版本自定义算子样例工程的编译脚本重新进行自定义算子工程的编译。

## 回调函数ParseParamFunc<a name="zh-cn_topic_0000001312631145_zh-cn_topic_0204328255_section1616524114512"></a>

用户自定义并实现FusionParseParamFunc类函数，完成原始模型中算子属性到适配昇腾AI处理器的模型中算子属性映射，将结果填到Operator类中。

```
using ParseParamFunc = std::function<domi::Status(const google::protobuf::Message *, ge::Operator &)>
```

-   第一个参数为输入，protobuf格式的数据结构（来源于原始模型的prototxt文件），包含算子属性信息。
-   第二个参数为输出，适配昇腾AI处理器的模型的算子数据结构，保存算子信息。

