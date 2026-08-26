# AutoMappingFn

## 函数功能

自动映射回调函数。

## 函数原型

```cpp
Status AutoMappingFn(const google::protobuf::Message *op_src, ge::Operator &op)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|op_src|输入|转换前原始模型中的算子，包含原始模型中算子的属性。|
|op|输入|适配AI处理器的算子。|

关于Operator类详细说明请参见《[GE图引擎 API](https://gitcode.com/cann/ge/blob/9.2.0-beta.2/docs/zh/api/graph_engine_api/README.md)》。

## 约束说明

若原始TensorFlow算子与适配AI处理器的算子属性无法一一映射，AutoMappingFn函数无法应用于回调函数[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)中，此种场景下，请在回调函数[ParseParamsByOperatorFn](ParseParamsByOperatorFn.md)中使用[AutoMappingByOpFn](AutoMappingByOpFn.md)接口进行可以映射成功的属性的自动解析，使用示例请参见[调用示例](AutoMappingByOpFn.md#调用示例)。
