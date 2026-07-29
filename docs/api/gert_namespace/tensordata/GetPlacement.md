# GetPlacement

## 函数功能

获取tensor的placement，tensor数据所在的设备位置。

## 函数原型

```cpp
TensorPlacement GetPlacement() const
```

## 参数说明

无。

## 返回值说明

tensor的placement。关于TensorPlacement类型的定义，请参见[TensorPlacement](../TensorPlacement.md)。

## 约束说明

无。

## 调用示例

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
auto td_place = td.GetPlacement(); // kOnHost
```
