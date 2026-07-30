# SetFormat

## 函数功能

设置Tensor的Format。

## 函数原型

```cpp
graphStatus SetFormat(const ge::Format &format)
```

## 参数说明

|参数名|输入/输出|描述|
|--|--|--|
|format|输入|需设置的Format值。关于Format类型，请参见Format。|

## 返回值

graphStatus类型：设置成功返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理

无。

## 约束说明

无。
