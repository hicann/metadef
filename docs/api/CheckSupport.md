# CheckSupport<a name="ZH-CN_TOPIC_0000002494990589"></a>

## 函数功能<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section36583473819"></a>

注册一个“是否支持该算子”的判断函数。

## 函数原型<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section13230182415108"></a>

```
OpImplRegisterV2 &CheckSupport(OP_CHECK_FUNC_V2 check_support_func)
```

## 参数说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section75395119104"></a>

<a name="table174mcpsimp"></a>
<table><thead align="left"><tr id="row180mcpsimp"><th class="cellrowborder" valign="top" width="31%" id="mcps1.1.4.1.1"><p id="p182mcpsimp"><a name="p182mcpsimp"></a><a name="p182mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.4.1.2"><p id="p184mcpsimp"><a name="p184mcpsimp"></a><a name="p184mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="53%" id="mcps1.1.4.1.3"><p id="p186mcpsimp"><a name="p186mcpsimp"></a><a name="p186mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row188mcpsimp"><td class="cellrowborder" valign="top" width="31%" headers="mcps1.1.4.1.1 "><p id="p190mcpsimp"><a name="p190mcpsimp"></a><a name="p190mcpsimp"></a>check_support_func</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p192mcpsimp"><a name="p192mcpsimp"></a><a name="p192mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p194mcpsimp"><a name="p194mcpsimp"></a><a name="p194mcpsimp"></a>待注册的OP_CHECK_FUNC_V2函数。OP_CHECK_FUNC_V2类型定义如下：</p>
<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618">using OP_CHECK_FUNC_V2 = ge::graphStatus (*)(const OpCheckContext *context, ge::AscendString &amp;result);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section25791320141317"></a>

返回算子的OpImplRegisterV2对象本身，该对象新增注册OP\_CHECK\_FUNC\_V2函数。

## 约束说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section19165124931511"></a>

无

