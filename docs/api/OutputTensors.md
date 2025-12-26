# OutputTensors<a name="ZH-CN_TOPIC_0000002455031465"></a>

## 函数功能<a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section36583473819"></a>

设置输出Tensor 。

## 函数原型<a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
OpTilingContextBuilder &OutputTensors(const std::vector<gert::Tensor *> &outputs)
```

## 参数说明<a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section75395119104"></a>

<a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p10223674448"><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p10223674448"></a><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p645511218169"><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p645511218169"></a><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p1922337124411"><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p1922337124411"></a><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p2340183613156"><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p2340183613156"></a><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p2340183613156"></a>outputs</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p88767238815"><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p88767238815"></a><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p88767238815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p131917964515"><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p131917964515"></a><a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_p131917964515"></a>输出Tensor的指针数组。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section25791320141317"></a>

OpTilingContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002453637689_zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section19165124931511"></a>

-   在调用Build方法之前，必须设置OutputTensors，否则构造出的TilingContext将包含未定义数据。
-   通过指针传入的参数（void\*），其内存所有权归调用者所有；调用者必须确保指针在ContextHolder对象的生命周期内有效。

