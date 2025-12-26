# GenerateTask<a name="ZH-CN_TOPIC_0000002446110886"></a>

## 函数功能<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section36583473819"></a>

GenerateTask阶段具体Task的生成和处理。

## 函数原型<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section13230182415108"></a>

```
OpImplRegisterV2 &GenerateTask(OpGenTaskKernelFunc gen_task_func)
```

## 参数说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section75395119104"></a>

<a name="table662mcpsimp"></a>
<table><thead align="left"><tr id="row668mcpsimp"><th class="cellrowborder" valign="top" width="24%" id="mcps1.1.4.1.1"><p id="p670mcpsimp"><a name="p670mcpsimp"></a><a name="p670mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.4.1.2"><p id="p672mcpsimp"><a name="p672mcpsimp"></a><a name="p672mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="59%" id="mcps1.1.4.1.3"><p id="p674mcpsimp"><a name="p674mcpsimp"></a><a name="p674mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row676mcpsimp"><td class="cellrowborder" valign="top" width="24%" headers="mcps1.1.4.1.1 "><p id="p678mcpsimp"><a name="p678mcpsimp"></a><a name="p678mcpsimp"></a>gen_task_func</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.2 "><p id="p680mcpsimp"><a name="p680mcpsimp"></a><a name="p680mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="59%" headers="mcps1.1.4.1.3 "><p id="p682mcpsimp"><a name="p682mcpsimp"></a><a name="p682mcpsimp"></a>待注册的OpGenTaskKernelFunc函数。</p>
<p id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p7906164918157"><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p7906164918157"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_p7906164918157"></a>OpGenTaskKernelFunc类型定义如下：</p>
<a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618"></a><a name="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000002071517761_zh-cn_topic_0000001396869469_screen14824110151618">using OpGenTaskKernelFunc = UINT32 (*)(const ExeResGenerationContext *context, std::vector&lt;std::vector&lt;uint8_t&gt;&gt; &amp;tasks);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section25791320141317"></a>

返回算子的OpImplRegisterV2对象本身，该对象新增注册OpGenTaskKernelFunc函数。

## 约束说明<a name="zh-cn_topic_0000002035817652_zh-cn_topic_0000001526594958_zh-cn_topic_0000001525424352_section19165124931511"></a>

无

