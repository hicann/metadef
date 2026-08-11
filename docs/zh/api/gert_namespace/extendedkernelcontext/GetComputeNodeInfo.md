# GetComputeNodeInfo

## 函数功能

获取本Kernel对应的计算节点的信息。

图执行时本质上是执行图上的一个个节点的Kernel在执行。本方法能够从KernelContext中获取保存的ComputeNodeInfo，而ComputeNodeInfo中包含InputDesc等信息。

## 函数原型

```cpp
const ComputeNodeInfo *GetComputeNodeInfo() const
```

## 参数说明

无。

## 返回值说明

计算节点的信息。

关于ComputeNodeInfo的定义，请参见[ComputeNodeInfo](../computenodeinfo/ComputeNodeInfo.md)。

## 约束说明

无。

## 调用示例

```cpp
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto compute_node_info = extend_context->GetComputeNodeInfo();
```
