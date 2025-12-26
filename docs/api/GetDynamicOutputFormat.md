# GetDynamicOutputFormat<a name="ZH-CN_TOPIC_0000002346462741"></a>

## 函数功能<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section36583473819"></a>

根据算子原型定义中的输出索引获取对应的动态输出Format指针。

## 函数原型<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section13230182415108"></a>

```
StorageFormat *GetDynamicOutputFormat(const size_t ir_index, const size_t relative_index)
```

## 参数说明<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section75395119104"></a>

<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p10223674448"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p10223674448"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p645511218169"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p645511218169"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="66.77%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p1922337124411"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p1922337124411"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p2340183613156"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p2340183613156"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p2340183613156"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p143401361158"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p143401361158"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.77%" headers="mcps1.1.4.1.3 "><p id="p123187011568"><a name="p123187011568"></a><a name="p123187011568"></a>IR原型定义中的索引，从0开始计数。</p>
</td>
</tr>
<tr id="row1292614363559"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p892653685518"><a name="p892653685518"></a><a name="p892653685518"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.4.1.2 "><p id="p139261536155513"><a name="p139261536155513"></a><a name="p139261536155513"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.77%" headers="mcps1.1.4.1.3 "><p id="p153765011558"><a name="p153765011558"></a><a name="p153765011558"></a>该算子输出实例化后的相对index，例如某个动态输出实例化了3个输出，那么relative_index的有效范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section25791320141317"></a>

返回输出Format指针，ir\_index或relative\_index非法时，返回空指针。

关于StorageFormat类型的定义，请参见[StorageFormat](StorageFormat.md)。

## 约束说明<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto format = context->GetDynamicOutputFormat(0U, 0U);
  // ...
}
```

