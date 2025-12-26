# TilingData<a name="ZH-CN_TOPIC_0000002454911393"></a>

## 函数功能<a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section36583473819"></a>

设置算子的TilingData指针, 用于算子Tiling计算时，向该指针中写入TilingData数据。

## 函数原型<a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
OpTilingContextBuilder &TilingData(const gert::TilingData *tiling_data, gert::Chain::Deleter deleter = nullptr)
```

## 参数说明<a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section75395119104"></a>

<a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p10223674448"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p10223674448"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p645511218169"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p645511218169"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p1922337124411"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p1922337124411"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p2340183613156"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p2340183613156"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p2340183613156"></a>tiling_data</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p88767238815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p131917964515"><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p131917964515"></a><a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_p131917964515"></a>TilingData数据指针。</p>
</td>
</tr>
<tr id="row1036817285581"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p6378113213583"><a name="p6378113213583"></a><a name="p6378113213583"></a>deleter</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p5369428185816"><a name="p5369428185816"></a><a name="p5369428185816"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p1924319418587"><a name="p1924319418587"></a><a name="p1924319418587"></a>Tiling数据的删除器，如果用户显式传入删除器deleter，ContextHolder析构时会调用删除器释放Tiling数据，默认不传入。建议使用<a href="TilingDataSize.md">TilingDataSize</a>接口。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section25791320141317"></a>

OpTilingContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002420158752_zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section19165124931511"></a>

-   在调用Build方法之前，必须设置TilingData或TilingDataSize，否则构造出的TilingContext将包含未定义数据。
-   通过指针传入的参数（void\*），其内存所有权归调用者所有；调用者必须确保指针在 ContextHolder 对象的生命周期内有效。

