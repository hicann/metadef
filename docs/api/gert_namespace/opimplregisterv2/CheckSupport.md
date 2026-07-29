# CheckSupport

## 函数功能

注册一个“是否支持该算子”的判断函数。

## 函数原型

```cpp
OpImplRegisterV2 &CheckSupport(OP_CHECK_FUNC_V2 check_support_func)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|check_support_func|输入|待注册的OP_CHECK_FUNC_V2函数。OP_CHECK_FUNC_V2类型定义如下：<br>`using OP_CHECK_FUNC_V2 = ge::graphStatus (*)(const OpCheckContext *context, ge::AscendString &result);`|

## 返回值说明

返回算子的OpImplRegisterV2对象本身，该对象新增注册OP\_CHECK\_FUNC\_V2函数。

## 约束说明

无
