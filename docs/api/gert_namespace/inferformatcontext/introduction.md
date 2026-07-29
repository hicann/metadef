# 简介

InferFormatContext继承自ExtendedKernelContext，是一个用于Format推导的上下文类。该类的主要作用是在推导算子输出Format的过程中，提供必要的输入输出Format、输入输出Shape和输入Tensor访问接口。InferFormatContext是Format推导函数的入参，Format推导函数的相关解释请参考[InferFormat](../opimplregisterv2/InferFormat.md)。

InferFormatContext继承关系图如下：

![](../../figures/zh-cn_image_0000002309618966.png)

## 需要包含的头文件

```cpp
#include <infer_format_context.h>
```
