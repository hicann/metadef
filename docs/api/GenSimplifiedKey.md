# GenSimplifiedKey<a name="ZH-CN_TOPIC_0000002042368866"></a>

## 函数功能<a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_section36583473819"></a>

注册算子的GenSimplifiedKey函数，以提供一个更加快速的二进制匹配key值。

用户需要为算子编写一个GenSimplifiedKey类型的函数，并使用该接口进行注册。

GenSimplifiedKey类型定义如下：

```
using GenSimplifiedKeyKernelFunc = UINT32 (*)(TilingContext *, ge::char_t *);
```

GenSimplifiedKey函数接受一个TilingContext类型参数和ge::char\_t类型参数作为输入，通过该输入算子可自定义simplified key生成逻辑。

## 函数原型<a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_section13230182415108"></a>

```
OpImplRegisterV2 &GenSimplifiedKey(GenSimplifiedKeyKernelFunc gen_simplifiedkey_func)
```

## 参数说明<a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_section181917342085"></a>

<a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_row6223476444"><th class="cellrowborder" valign="top" width="22.23%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p10223674448"><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p10223674448"></a><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="10.33%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p645511218169"><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p645511218169"></a><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p1922337124411"><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p1922337124411"></a><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_row152234713443"><td class="cellrowborder" valign="top" width="22.23%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002035386742_p1416315381913"><a name="zh-cn_topic_0000002035386742_p1416315381913"></a><a name="zh-cn_topic_0000002035386742_p1416315381913"></a>gen_simplifiedkey_func</p>
</td>
<td class="cellrowborder" valign="top" width="10.33%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p167701536957"><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p167701536957"></a><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p17695364517"><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p17695364517"></a><a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_p17695364517"></a>要注册的自定义GenSimplifiedKey函数，类型为GenSimplifiedKeyKernelFunc。</p>
<p id="zh-cn_topic_0000002035386742_p20159143801517"><a name="zh-cn_topic_0000002035386742_p20159143801517"></a><a name="zh-cn_topic_0000002035386742_p20159143801517"></a>GenSimplifiedKeyKernelFunc类型定义如下：</p>
<a name="zh-cn_topic_0000002035386742_screen10159133817159"></a><a name="zh-cn_topic_0000002035386742_screen10159133817159"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000002035386742_screen10159133817159">using GenSimplifiedKeyKernelFunc = UINT32 (*)(TilingContext *, ge::char_t *);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了生成二进制简化匹配key函数。

## 约束说明<a name="zh-cn_topic_0000002035386742_zh-cn_topic_0000001346709604_section19165124931511"></a>

无。

