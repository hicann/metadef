# ParseParamsByOperatorFn

## 函数功能

注册解析用户自定义算子属性的函数

## 函数原型

```cpp
OpRegistrationData &ParseParamsByOperatorFn(const ParseParamByOpFunc &parse_param_by_op_fn)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|parse_param_by_op_fn|输入|解析用户自定义算子属性的函数，请参见回调函数ParseParamByOpFunc。|

## 回调函数ParseParamByOpFunc

用户自定义并实现ParseParamByOpFunc类函数，完成原始模型中算子属性到适配AI处理器的模型中属性的映射，将结果填到Operator类中。

```cpp
Status ParseParamByOpFunc(const ge::Operator &op_origin, ge::Operator &op_dest)
```

**表 1**  参数说明

|参数|输入/输出|说明|
|--|--|--|
|op_origin|输入|框架定义的Operator类对象，包含解析出的原始模型中自定义算子属性信息，|
|op_dest|输出|适配AI处理器的模型中的算子数据结构，保存算子信息。|

关于Operator类详细说明请参见《[GE图引擎 API](https://gitcode.com/cann/ge/blob/9.2.0-beta.2/docs/zh/api/graph_engine_api/README.md)》。

## 约束说明

无。
