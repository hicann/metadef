# GetShape

## 函数功能

获取Tensor的Shape，包含运行时和原始Shape。

## 函数原型

```cpp
const StorageShape &GetShape() const
StorageShape &GetShape()
```

## 参数说明

无。

## 返回值说明

- const StorageShape &GetShape\(\) const：返回只读的Shape引用。
- StorageShape &GetShape\(\)：返回Shape引用。
- 关于StorageShape类型的定义，请参见[StorageShape](../storageshape/StorageShape.md)。

## 约束说明

无。

## 调用示例

```cpp
StorageShape sh({1, 2, 3}, {2, 1, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetShape(); // sh
```
