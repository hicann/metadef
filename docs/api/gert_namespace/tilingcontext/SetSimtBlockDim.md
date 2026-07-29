# SetSimtBlockDim

## 函数功能

设置SIMT线程块的维度，即参与计算的Vector运算单元的线程块内部的线程数量，用Dim3结构体表示。Dim3是包含了x、y、z三个uint32的字段的结构体，表示一个Block线程块在x、y、z三个维度上的线程数量。

例如：block\_dim.x、block\_dim.y、block\_dim.z分别表示线程块在x、y、z三个维度上的线程数量。

## 函数原型

```cpp
ge::graphStatus SetSimtBlockDim(const Dim3 &block_dim)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|block_dim|输入|线程块的维度；用Dim3结构体表示。Dim3是包含了x、y、z三个uint32的字段的结构体，表示一个Block线程块在x、y、z三个维度上的线程数量。|

## 返回值说明

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](../../ge_namespace/ge-graphStatus.md)。

## 约束说明

无

## 调用示例

```cpp
gert::Dim3 block_dim(2, 3);
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetSimtBlockDim(block_dim);
  // ...
}
```
