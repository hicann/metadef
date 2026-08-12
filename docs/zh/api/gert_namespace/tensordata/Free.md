# Free

## 函数功能

释放Tensor。

## 函数原型

```cpp
ge::graphStatus Free()
```

## 参数说明

无。

## 返回值说明

成功时返回：ge::GRAPH\_SUCCESS，失败时返回manager函数返回的状态码。

关于ge::graphStatus类型的定义，请参见[ge::graphStatus](../../ge_namespace/ge-graphStatus.md)。

## 约束说明

无。

## 调用示例

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
td.Free();
```
