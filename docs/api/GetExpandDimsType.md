# GetExpandDimsType<a name="ZH-CN_TOPIC_0000002078447669"></a>

## 函数功能<a name="zh-cn_topic_0000001586514678_zh-cn_topic_0000001339885134_section36583473819"></a>

获取原始Format向运行时Format转换时的补维规则。

## 函数原型<a name="zh-cn_topic_0000001586514678_zh-cn_topic_0000001339885134_section13230182415108"></a>

```
ExpandDimsType GetExpandDimsType() const
```

## 参数说明<a name="zh-cn_topic_0000001586514678_zh-cn_topic_0000001339885134_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001586514678_zh-cn_topic_0000001339885134_section25791320141317"></a>

补维规则，请参考[ExpandDimsType](ExpandDimsType.md)。

## 约束说明<a name="zh-cn_topic_0000001586514678_zh-cn_topic_0000001339885134_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586514678_zh-cn_topic_0000001339885134_section320753512363"></a>

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

