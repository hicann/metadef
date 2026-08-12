# GetShape

## 函数功能

获取TensorDesc所描述Tensor的Shape。

## 函数原型

```cpp
Shape GetShape() const
```

## 参数说明

无。

## 返回值

[Shape](../shape/Shape.md)类型，TensorDesc描述的Shape。

## 异常处理

无。

## 约束说明

由于返回的Shape信息为值拷贝，因此修改返回的Shape信息，不影响TensorDesc中已有的Shape信息。
