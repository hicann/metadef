# GetKernelType

## 函数功能

获取本kernel的类型。

## 函数原型

```cpp
const ge::char_t *GetKernelType() const
```

## 参数说明

无。

## 返回值说明

本kernel的type。

## 约束说明

无。

## 调用示例

```cpp
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto kernel_type = extend_context->GetKernelType();
```
