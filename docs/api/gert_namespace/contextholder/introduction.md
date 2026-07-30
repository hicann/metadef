# 简介

Context是算子Host侧实现函数执行时的上下文，由于构造出来的Context存储的都是指针类型，为了方便进行生命周期和所有权管理，提供ContextHolder类进行资源管理。

Context允许在算子Host侧实现函数执行时通过该上下文获取必要的输入输出数据。算子Host侧实现包括：Tiling、InferShape、InferShapeRange、InferDataType、InferFormat等。每种实现函数都有对应的Context类型作为入参，例如Tiling实现函数的入参是TilingContext，InferShape实现函数的入参是InferShapeContext，以此类推。

为了方便在算子Host侧执行时构造上下文Context，我们提供了各种Context的构造方法，称之为OpxxxContextBuilder类，以屏蔽底层数据结构的复杂性，简化构造过程。例如对于TilingContext的构造，我们会提供OpTilingContextBuilder类构造TilingContext。

OpxxxContextBuilder系列接口列表如下：

- [OpInferDataTypeContextBuilder](../opinferdatatypecontextbuilder/OpInferDataTypeContextBuilder.md)，用于构造[InferDataTypeContext](../inferdatatypecontext/InferDataTypeContext.md)；
- [OpInferShapeContextBuilder](../opinfershapecontextbuilder/OpInferShapeContextBuilder.md)，用于构造[InferShapeContext](../infershapecontext/InferShapeContext.md)；
- [OpInferShapeRangeContextBuilder](../opinfershaperangecontextbuilder/OpInferShapeRangeContextBuilder.md)，用于构造[InferShapeRangeContext](../infershaperangecontext/InferShapeRangeContext.md)；
- [OpKernelContextBuilder](../opkernelcontextbuilder/OpKernelContextBuilder.md)，用于构造[KernelContext](../internal_interface.md#kernelcontext类)；
- [OpTilingContextBuilder](../optilingcontextbuilder/OpTilingContextBuilder.md)，用于构造[TilingContext](../tilingcontext/TilingContext.md)；
- [OpTilingParseContextBuilder](../optilingparsecontextbuilder/OpTilingParseContextBuilder.md)，用于构造[TilingParseContext](../internal_interface.md#tilingparsecontext类)。

OpxxxContextBuilder用于创建ContextHolder，而ContextHolder负责管理Context中指针所指向的内存资源。通过ContextHolder，可以获取相应的Context。

## 需要包含的头文件

```cpp
#include "base/context_builder/context_holder.h"
```
