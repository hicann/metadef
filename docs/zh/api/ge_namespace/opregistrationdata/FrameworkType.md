# FrameworkType

## 函数功能

设置原始模型的框架类型。

## 函数原型

```cpp
OpRegistrationData &FrameworkType(const domi::FrameworkType &fmk_type)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|fmk_type|输入|枚举值的定义如下：enum FrameworkType {CAFFE = 0,MINDSPORE = 1,TENSORFLOW = 3,ANDROID_NN,ONNX,FRAMEWORK_RESERVED,};|
