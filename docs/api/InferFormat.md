# InferFormat<a name="ZH-CN_TOPIC_0000002358400385"></a>

## 函数功能<a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_section36583473819"></a>

注册算子的InferFormat函数。

对于部分格式敏感的Cube算子，使用更适应底层硬件的内部格式，可以带来较大的性能收益，所以开发者需要实现InferFormat函数并注册。

## 函数原型<a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_section13230182415108"></a>

```
OpImplRegisterV2 &InferFormat(InferFormatFunc infer_format_func)
```

## 参数说明<a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_section75395119104"></a>

<a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p10223674448"><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p10223674448"></a><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p645511218169"><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p645511218169"></a><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p1922337124411"><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p1922337124411"></a><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p17770136956"><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p17770136956"></a><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p17770136956"></a>infer_format_func</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p167701536957"><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p167701536957"></a><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p17695364517"><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p17695364517"></a><a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_p17695364517"></a>要注册的自定义InferFormat函数，类型为InferFormatFunc。</p>
<p id="p131203920340"><a name="p131203920340"></a><a name="p131203920340"></a>InferFormatFunc类型定义如下：</p>
<pre class="screen" id="screen478218231341"><a name="screen478218231341"></a><a name="screen478218231341"></a>using InferFormatFunc = UINT32 (*)(InferFormatContext *context);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了InferFormat函数infer\_format\_func。

## 约束说明<a name="zh-cn_topic_0000002035516796_zh-cn_topic_0000001346389756_section19165124931511"></a>

无。

