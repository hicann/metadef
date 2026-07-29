# SetAicpuBlockDim

## 函数功能

设置可以调度的AI CPU核数。

在使用HCCL高阶API的BatchWrite接口时，可以通过合理设置AI CPU核数获得更好的性能。

该参数后续版本会废弃，建议使用[SetAicpuNumBlocks](SetAicpuNumBlocks.md)。

## 函数原型

**ge::graphStatus SetAicpuBlockDim\(uint32\_t block\_dim\)**

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|block_dim|输入|可以调度的AI CPU核数。|

## 返回值说明

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](../../ge_namespace/ge-graphStatus.md)。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetAicpuBlockDim(5U);
  // ...
}
```
