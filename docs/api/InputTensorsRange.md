# InputTensorsRange<a name="ZH-CN_TOPIC_0000002454911361"></a>

## 函数功能<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section36583473819"></a>

设置输入Tensor的Range指针，用于在Shape Range推导时，可通过该Builder类构造的上下文InferShapeRangeContext获取相应的输入Tensor Range指针，即可以获得最大Shape的Tensor和最小Shape的Tensor。

## 函数原型<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section13230182415108"></a>

```
OpInferShapeRangeContextBuilder &InputTensorsRange(const std::vector<gert::Range<gert::Tensor> *> &inputs)
```

## 参数说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section75395119104"></a>

<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p3943172167"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p3943172167"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p3943172167"></a>inputs</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p2684123934216"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p2684123934216"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p2684123934216"></a>gert::Range&lt;gert::Tensor&gt; *类型的数组，存储各算子输入的Tensor Range指针，Tensor Range包含最大Shape的Tensor和最小Shape的Tensor。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section25791320141317"></a>

OpInferShapeRangeContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section19165124931511"></a>

-   在调用Build方法之前，必须调用该接口，否则构造出的InferShapeRangeContext将包含未定义数据。
-   通过指针传入的参数 \(gert::Tensor \*\)，其内存所有权归调用者所有；调用者必须确保指针在ContextHolder对象的生命周期内有效。

