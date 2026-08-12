# SetOffset

## 函数功能

设置Tensor中的offset。

## 函数原型

```cpp
void SetOffset(const int64_t offset)
```

## 参数说明

Tensor的offset。

## 返回值说明

无

## 约束说明

无

## 调用示例

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 0};
t.SetOffset(10);
auto offset = t.GetOffset(); // 10
```
