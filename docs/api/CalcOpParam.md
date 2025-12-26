# CalcOpParam<a name="ZH-CN_TOPIC_0000002445951018"></a>

## 函数功能<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section36583473819"></a>

该接口用于GenerateTask阶段的资源计算和申请。

## 函数原型<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section13230182415108"></a>

```
OpImplRegisterV2 &CalcOpParam(OpCalcParamKernelFunc calc_op_param_func)
```

## 参数说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section75395119104"></a>

<a name="table640mcpsimp"></a>
<table><thead align="left"><tr id="row646mcpsimp"><th class="cellrowborder" valign="top" width="31%" id="mcps1.1.4.1.1"><p id="p648mcpsimp"><a name="p648mcpsimp"></a><a name="p648mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.4.1.2"><p id="p650mcpsimp"><a name="p650mcpsimp"></a><a name="p650mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="53%" id="mcps1.1.4.1.3"><p id="p652mcpsimp"><a name="p652mcpsimp"></a><a name="p652mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row654mcpsimp"><td class="cellrowborder" valign="top" width="31%" headers="mcps1.1.4.1.1 "><p id="p656mcpsimp"><a name="p656mcpsimp"></a><a name="p656mcpsimp"></a>calc_op_param_func</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.2 "><p id="p658mcpsimp"><a name="p658mcpsimp"></a><a name="p658mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p660mcpsimp"><a name="p660mcpsimp"></a><a name="p660mcpsimp"></a>待注册的OpCalcParamKernel函数。</p>
<p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p7906164918157"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p7906164918157"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p7906164918157"></a>OpCalcParamKernelFunc类型定义如下：</p>
<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618">using OpCalcParamKernelFunc = UINT32 (*)(ExeResGenerationContext* context);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section25791320141317"></a>

返回算子的OpImplRegisterV2对象本身，该对象新增注册了OpCalcParamKernelFunc函数。

## 约束说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section19165124931511"></a>

无

