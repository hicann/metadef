# SetStorageFormat<a name="ZH-CN_TOPIC_0000002042368606"></a>

## 函数功能<a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_section36583473819"></a>

向CompileTimeTensorDesc中设置运行时Tensor的数据排布格式。

## 函数原型<a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_section13230182415108"></a>

```
void SetStorageFormat(const ge::Format format)
```

## 参数说明<a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_section75395119104"></a>

<a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p10223674448"><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p10223674448"></a><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p645511218169"><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p645511218169"></a><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p1922337124411"><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p1922337124411"></a><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p14234851154110"><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p14234851154110"></a><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p14234851154110"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p143401361158"><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p143401361158"></a><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p1410311123516"><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p1410311123516"></a><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p1410311123516"></a>需要设置的运行时数据排布格式信息。</p>
<p id="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p19829418123416"><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p19829418123416"></a><a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_p19829418123416"></a>关于ge::Format的定义，请参见<a href="Format.md">Format</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642694561_zh-cn_topic_0000001340204698_section320753512363"></a>

```
auto dtype_ = ge::DataType::DT_INT32;
StorageFormat fmt_(ge::Format::FORMAT_NC, ge::FORMAT_NCHW, {});
ExpandDimsType type_("1001");
gert::CompileTimeTensorDesc td;
td.SetDataType(dtype_);
auto dtype = td.GetDataType(); // ge::DataType::DT_INT32;
td.SetStorageFormat(fmt_.GetStorageFormat());
auto storage_fmt = td.GetStorageFormat(); // ge::FORMAT_NCHW
td.SetOriginFormat(fmt_.GetOriginFormat());
auto origin_fmt = td.GetOriginFormat(); // ge::Format::FORMAT_NC
td.SetExpandDimsType(type_);
auto type = td.GetExpandDimsType(); // type_("1001")
```

