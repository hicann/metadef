# GetFormat

## 函数功能

获取Tensor的数据格式，包含运行时数据格式和原始数据格式，返回的Format对象都是只读的。

## 函数原型

```cpp
const StorageFormat &GetFormat() const
```

## 参数说明

无

## 返回值说明

只读的Format引用。

关于StorageFormat类型的定义，请参见[StorageFormat](../storageformat/StorageFormat.md)。

## 约束说明

无

## 调用示例

```cpp
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                kFollowing,                                  // placement
                ge::DT_FLOAT16,                              //dt
                nullptr};
auto fmt = tensor.GetFormat();
```
