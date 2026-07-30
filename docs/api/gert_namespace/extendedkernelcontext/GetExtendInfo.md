# GetExtendInfo

## 函数功能

获取本kernel的扩展信息。

## 函数原型

```cpp
const KernelExtendInfo *GetExtendInfo() const
```

## 参数说明

无。

## 返回值说明

本kernel的扩展信息。

关于KernelExtendInfo类型的定义，请参见[内部关联接口](../internal_interface.md)KernelExtendInfo类。

## 约束说明

无。

## 调用示例

```cpp
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto extend_info = extend_context->GetExtendInfo();
```
