# GetFormat<a name="ZH-CN_TOPIC_0000002042526866"></a>

## 函数功能<a name="zh-cn_topic_0000001636315153_zh-cn_topic_0000001390684581_section36583473819"></a>

获取编译时Tensor的数据排布格式。

## 函数原型<a name="zh-cn_topic_0000001636315153_zh-cn_topic_0000001390684581_section13230182415108"></a>

```
const StorageFormat &GetFormat() const
```

## 参数说明<a name="zh-cn_topic_0000001636315153_zh-cn_topic_0000001390684581_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001636315153_zh-cn_topic_0000001390684581_section25791320141317"></a>

返回数据排布格式。[StorageFormat](StorageFormat.md)类型，包括原始format和存储format。

## 约束说明<a name="zh-cn_topic_0000001636315153_zh-cn_topic_0000001390684581_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001636315153_zh-cn_topic_0000001390684581_section320753512363"></a>

```
StorageFormat storageFormat(ge::Format::FORMAT_NC, ge::FORMAT_NCHW, {});
gert::CompileTimeTensorDesc compileTimeTensorDesc;
compileTimeTensorDesc.SetStorageFormat(storageFormat.GetStorageFormat());
auto storage_fmt = compileTimeTensorDesc.GetFormat(); // ge::FORMAT_NCHW
compileTimeTensorDesc.SetOriginFormat(storageFormat.GetOriginFormat());
auto origin_fmt = compileTimeTensorDesc.GetOriginFormat(); // ge::Format::FORMAT_NC
```

