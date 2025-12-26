# SetExpandDimsType<a name="ZH-CN_TOPIC_0000002078447697"></a>

## 函数功能<a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_section36583473819"></a>

设置原始Format向运行时Format转换时的补维规则。

## 函数原型<a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_section13230182415108"></a>

```
void SetExpandDimsType(const ExpandDimsType &expand_dims_type)
```

## 参数说明<a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_section75395119104"></a>

<a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_row6223476444"><th class="cellrowborder" valign="top" width="20.919999999999998%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p10223674448"><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p10223674448"></a><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.52%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p645511218169"><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p645511218169"></a><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="60.56%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1922337124411"><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1922337124411"></a><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_row152234713443"><td class="cellrowborder" valign="top" width="20.919999999999998%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1365516713431"><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1365516713431"></a><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1365516713431"></a>expand_dims_type</p>
</td>
<td class="cellrowborder" valign="top" width="18.52%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p143401361158"><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p143401361158"></a><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="60.56%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1410311123516"><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1410311123516"></a><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p1410311123516"></a>需要设置的补维规则。</p>
<p id="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p693580143712"><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p693580143712"></a><a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_p693580143712"></a>关于ExpandDimsType的说明，请参见<a href="ExpandDimsType.md">ExpandDimsType</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001592855208_zh-cn_topic_0000001340364678_section320753512363"></a>

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

