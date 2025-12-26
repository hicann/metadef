# InferShapeRange<a name="ZH-CN_TOPIC_0000002078486537"></a>

## 函数功能<a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_section36583473819"></a>

注册算子的InferShapeRange函数。

用户需要为算子编写一个InferShapeRangeKernelFunc类型的函数，并使用该接口进行注册。

InferShapeRangeKernelFunc类型定义如下：

```
using InferShapeRangeKernelFunc = UINT32 (*)(InferShapeRangeContext *);
```

InferShapeRange函数的原型是确定的，其接受一个InferShapeRangeContext类型作为输入，在此context上，可以获取到输入、输出的shape指针等内容（算子原型定义上的输入、输出、属性信息）。InferShapeRange成功后，返回ge::GRAPH\_SUCCESS，其他返回值被认为推导失败。推导失败后，执行过程结束退出。

## 函数原型<a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_section13230182415108"></a>

```
OpImplRegisterV2 &InferShapeRange(InferShapeRangeKernelFunc infer_shape_range_func)
```

## 参数说明<a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_section189014013619"></a>

<a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_row6223476444"><th class="cellrowborder" valign="top" width="20.09%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p10223674448"><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p10223674448"></a><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="12.47%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p645511218169"><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p645511218169"></a><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p1922337124411"><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p1922337124411"></a><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_row152234713443"><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p17770136956"><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p17770136956"></a><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p17770136956"></a>infer_shape_range_func</p>
</td>
<td class="cellrowborder" valign="top" width="12.47%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p167701536957"><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p167701536957"></a><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p18143182218380"><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p18143182218380"></a><a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_p18143182218380"></a>要注册的自定义infer_shape_range_func函数，类型为InferShapeRangeKernelFunc。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了InferShapeRange函数infer\_shape\_range\_func。

## 约束说明<a name="zh-cn_topic_0000002071517757_zh-cn_topic_0000001502850402_section19165124931511"></a>

无。

