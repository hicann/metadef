# 简介

InferDataTypeContext继承自ExtendedKernelContext，是一个用于数据类型（DataType）推导的上下文类，该类的主要作用是在算子数据类型推导过程中，提供获取输入、输出数据类型的接口，并支持设置输出数据类型。

InferDataTypeContext继承关系图如下：

![](../../figures/inferdatatype_context.png)

## 需要包含的头文件

```cpp
#include <infer_datatype_context.h>
```
