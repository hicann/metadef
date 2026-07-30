# GetRequiredOutputFormat

## 函数功能

根据算子原型定义中的输出索引获取对应的必选输出Format指针。

## 函数原型

```cpp
StorageFormat *GetRequiredOutputFormat(const size_t ir_index)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|ir_index|输入|IR原型定义中的index，从0开始计数。|

## 返回值说明

输出Format指针，ir\_index非法时，返回空指针。

关于StorageFormat类型的定义，请参见[StorageFormat](../storageformat/StorageFormat.md)。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto format = context->GetRequiredOutputFormat(0);
   // ...
}
```
