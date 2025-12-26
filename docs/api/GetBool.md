# GetBool<a name="ZH-CN_TOPIC_0000002078486369"></a>

## 函数功能<a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_section36583473819"></a>

获取bool类型的属性值。

## 函数原型<a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_section13230182415108"></a>

```
const bool *GetBool(const size_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_section75395119104"></a>

<a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_row6223476444"><th class="cellrowborder" valign="top" width="17.04%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p10223674448"><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p10223674448"></a><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.52%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p645511218169"><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p645511218169"></a><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p1922337124411"><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p1922337124411"></a><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_row152234713443"><td class="cellrowborder" valign="top" width="17.04%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p2340183613156"><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p2340183613156"></a><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.52%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p143401361158"><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p143401361158"></a><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p8146419129"><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p8146419129"></a><a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_p8146419129"></a>属性在IR原型定义中以及在OP_IMPL注册中的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_section25791320141317"></a>

指向属性值的指针。

## 约束说明<a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001590890306_zh-cn_topic_0000001390100429_section320753512363"></a>

```
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const bool *attr0 = runtime_attrs->GetBool(0);
```

