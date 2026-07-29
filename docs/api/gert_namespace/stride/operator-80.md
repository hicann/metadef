# operator\[\]

## 函数功能

获取指定idx轴的步长值。

## 函数原型

```cpp
const int64_t &operator[](const size_t idx) const
int64_t &operator[](const size_t idx)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|idx|输入|维度的索引，调用者需要保证索引合法。|

## 返回值说明

- const int64\_t &operator\[\]\(const size\_t idx\) const：步长值，在idx\>=kMaxDimNum时，行为未定义。
- int64\_t &operator\[\]\(const size\_t idx\)：dim值，在idx\>=kMaxDimNum时，行为未定义。

## 约束说明

调用者需要保证index合法，即idx<kMaxDimNum。

## 调用示例

```cpp
Stride stride({3, 256, 256});
auto str0 = stride[0]; // 3
auto str5 = stride[5]; // 0
auto invalid_str = stride[Stride::kMaxDimNum]; // 行为未定义
```
