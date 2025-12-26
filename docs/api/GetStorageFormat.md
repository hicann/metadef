# GetStorageFormat<a name="ZH-CN_TOPIC_0000002078486249"></a>

## 函数功能<a name="zh-cn_topic_0000001586195490_zh-cn_topic_0000001390804709_section36583473819"></a>

获取运行时Tensor中存储数据的实际排布格式。

## 函数原型<a name="zh-cn_topic_0000001586195490_zh-cn_topic_0000001390804709_section13230182415108"></a>

```
ge::Format GetStorageFormat() const
```

## 参数说明<a name="zh-cn_topic_0000001586195490_zh-cn_topic_0000001390804709_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001586195490_zh-cn_topic_0000001390804709_section25791320141317"></a>

运行时数据的实际排布格式。

## 约束说明<a name="zh-cn_topic_0000001586195490_zh-cn_topic_0000001390804709_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586195490_zh-cn_topic_0000001390804709_section320753512363"></a>

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

