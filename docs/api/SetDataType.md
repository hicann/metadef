# SetDataType<a name="ZH-CN_TOPIC_0000002042526906"></a>

## 函数功能<a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_section36583473819"></a>

向CompileTimeTensorDesc中设置Tensor的数据类型。

## 函数原型<a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_section13230182415108"></a>

```
void SetDataType(const ge::DataType data_type)
```

## 参数说明<a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_section75395119104"></a>

<a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p10223674448"><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p10223674448"></a><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p645511218169"><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p645511218169"></a><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p1922337124411"><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p1922337124411"></a><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p2340183613156"><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p2340183613156"></a><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p2340183613156"></a>data_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p143401361158"><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p143401361158"></a><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p48615318225"><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p48615318225"></a><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p48615318225"></a>需设置的CompileTimeTensorDesc所描述的Tensor的数据类型信息。</p>
<p id="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p10907161853511"><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p10907161853511"></a><a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_p10907161853511"></a>关于ge::DataType类型，请参见<a href="DataType.md">DataType</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642575165_zh-cn_topic_0000001390565049_section320753512363"></a>

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

