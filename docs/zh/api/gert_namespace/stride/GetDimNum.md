# GetDimNum

## 函数功能

获取Stride对象的维度个数。

## 函数原型

```cpp
size_t GetDimNum() const
```

## 参数说明

无

## 返回值说明

Stride对象的维度个数。

## 约束说明

无

## 调用示例

```cpp
Stride stride0({3, 256, 256});
auto dim_num = stride0.GetDimNum(); // 3
```
