# MutableStride

## 函数功能

获取Tensor中的Stride引用，该Stride可修改。

## 函数原型

```cpp
Stride &MutableStride()
```

## 参数说明

无

## 返回值说明

可写的Tensor Stride引用。

关于Stride类型的定义，请参见[Stride](../stride/Stride.md)。

## 约束说明

无

## 调用示例

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 0};
t.MutableStride() = Stride({6, 1, 1});
auto stride = t.GetStride(); // Stride({6, 1, 1})
```
