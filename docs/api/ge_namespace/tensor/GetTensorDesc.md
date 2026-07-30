# GetTensorDesc

## 函数功能

获取Tensor的描述符。

## 函数原型

```cpp
TensorDesc GetTensorDesc() const
```

## 参数说明

无。

## 返回值

返回当前Tensor的描述符，[TensorDesc](../tensordesc/TensorDesc.md)类型。

## 异常处理

无。

## 约束说明

修改返回的TensorDesc信息，不影响Tensor对象中已有的TensorDesc信息。
