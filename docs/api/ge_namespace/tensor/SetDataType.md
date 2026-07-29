# SetDataType

## 函数功能

设置Tensor的Datatype。

## 函数原型

```cpp
graphStatus SetDataType(const ge::DataType &dtype)
```

## 参数说明

|参数名|输入/输出|描述|
|--|--|--|
|dtype|输入|需设置的DataType值。关于DataType类型，请参见DataType。|

## 返回值

graphStatus类型：设置成功返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理

无。

## 约束说明

无。
