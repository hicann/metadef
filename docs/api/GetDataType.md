# GetDataType<a name="ZH-CN_TOPIC_0000002078447649"></a>

## 函数功能<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section36583473819"></a>

获取CompileTimeTensorDesc所描述的Tensor的数据类型。

## 函数原型<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section13230182415108"></a>

```
ge::DataType GetDataType() const
```

## 参数说明<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section25791320141317"></a>

返回Tensor的数据类型。

关于ge::DataType的定义，请参见[DataType](DataType.md)。

## 约束说明<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section320753512363"></a>

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

