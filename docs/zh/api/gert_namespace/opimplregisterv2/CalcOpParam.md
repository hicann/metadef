# CalcOpParam

## 函数功能

该接口用于GenerateTask阶段的资源计算和申请。

## 函数原型

```cpp
OpImplRegisterV2 &CalcOpParam(OpCalcParamKernelFunc calc_op_param_func)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|calc_op_param_func|输入|待注册的OpCalcParamKernel函数。OpCalcParamKernelFunc类型定义如下：using OpCalcParamKernelFunc = UINT32 (*)(ExeResGenerationContext* context);|

## 返回值说明

返回算子的OpImplRegisterV2对象本身，该对象新增注册了OpCalcParamKernelFunc函数。

## 约束说明

无
