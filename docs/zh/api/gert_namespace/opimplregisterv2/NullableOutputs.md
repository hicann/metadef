# NullableOutputs

## 函数功能

该接口用于标记算子可以为空的输出。

## 函数原型

```cpp
 OpImplRegisterV2 &NullableOutputs(std::initializer_list<int32_t> outputs)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|outputs|输入|指定输出index列表。举例来说，outputs={0, 3}，说明算子的第0、3个输出可以为空。|

## 返回值说明

返回算子的OpImplRegisterV2对象，该对象新增注册NullableOutput函数。
