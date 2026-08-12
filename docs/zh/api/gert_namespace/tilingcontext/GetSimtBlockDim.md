# GetSimtBlockDim

## 函数功能

获取SIMT线程块的维度，即参与计算的Vector运算单元的线程块内部的线程数量，用Dim3结构体表示。Dim3是包含了x、y、z三个uint32的字段的结构体，表示一个Block线程块在x、y、z三个维度上的线程数量。

例如：block\_dim.x、block\_dim.y、block\_dim.z分别表示线程块在x、y、z三个维度上的线程数量。

## 函数原型

```cpp
const Dim3 *GetSimtBlockDim() const
```

## 参数说明

无

## 返回值说明

返回block\_dim。

## 约束说明

无

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetSimtBlockDim();
  // ...
}
```
