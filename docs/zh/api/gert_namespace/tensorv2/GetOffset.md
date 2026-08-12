# GetOffset

## 函数功能

获取Tensor中的offset。

## 函数原型

```cpp
int64_t GetOffset() const
```

## 参数说明

无

## 返回值说明

Tensor中的offset。

## 约束说明

无

## 调用示例

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 10};
auto offset = t.GetOffset(); // 10
```
