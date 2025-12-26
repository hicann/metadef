# GetOutputFormat<a name="ZH-CN_TOPIC_0000002343737841"></a>

## 函数功能<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section36583473819"></a>

根据算子输出索引获取对应的输出Format指针。这里的输出索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section13230182415108"></a>

```
StorageFormat *GetOutputFormat(const size_t index)
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
<tbody><tr id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p2340183613156"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p2340183613156"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p143401361158"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p143401361158"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="66.77%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p123391362158"><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p123391362158"></a><a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_p123391362158"></a>算子输出索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section25791320141317"></a>

输出Format指针，index非法时，返回空指针。

关于StorageFormat类型的定义，请参见[StorageFormat](StorageFormat.md)。

## 约束说明<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526206866_zh-cn_topic_0000001390023301_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto format = context->GetOutputFormat(0U);        // 获取第0个输出的format
  // ...
}
```

