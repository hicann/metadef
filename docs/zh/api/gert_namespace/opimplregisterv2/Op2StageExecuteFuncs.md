# Op2StageExecuteFuncs

## 函数功能

单个算子包含多Kernel组合执行逻辑的场景下，算子可以通过该接口设置算子级的回调函数，包含下发准备回调函数和下发回调函数，下发准备回调函数完成Kernel下发使用到的参数的准备，下发回调函数内实现多Kernel的下发。本接口为内部关联接口，开发者不会直接调用，暂时无需关注。

## 函数原型

```cpp
OpImplRegisterV2 &Op2StageExecuteFuncs(OpExecPrepareFunc prepare_func, OpExecLaunchFunc launch_func)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|prepare_func|输入|注册的自定义OpExecPrepareFunc函数，类型为OpExecPrepareFunc。OpExecPrepareFunc类型定义如下：<br>`using OpExecPrepareFunc = UINT32 (*)(OpExecutePrepareContext *);`|
|launch_func|输入|注册的自定义OpExecLaunchFunc函数，类型为OpExecLaunchFunc。OpExecLaunchFunc类型定义如下：<br>`using OpExecLaunchFunc = UINT32 (*)(OpExecuteLaunchContext *);`|

## 返回值说明

返回算子的OpImplRegisterV2对象，该对象新增注册了算子级的回调函数。

## 约束说明

无。
