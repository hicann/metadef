# 简介

InferShapeRangeContext继承自ExtendedKernelContext，主要用于获取算子的输入输出ShapeRange和输入TensorRange，其中ShapeRange和TensorRange分别是Range<T\>模板的特化类型，记录了算子Shape和Tensor值的上下限。部分算子（例如，NonZero算子）在进行shape推导时，无法推导出具体的输出shape，只能通过ShapeRange信息预估最大shape。

InferShapeRangeContext继承关系图如下：

![](../../figures/zh-cn_image_0000002220499246.png)

## 需要包含的头文件

```cpp
#include <infer_shape_range_context.h>
```
