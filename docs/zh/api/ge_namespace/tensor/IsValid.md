# IsValid

## 函数功能

判断Tensor对象是否有效。

若实际Tensor数据的大小与TensorDesc所描述的Tensor数据大小一致，则有效。

## 函数原型

```cpp
graphStatus IsValid()
```

## 参数说明

无。

## 返回值

graphStatus类型：如果Tensor对象有效，则返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理

无。

## 约束说明

无。
