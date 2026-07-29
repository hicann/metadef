# GetBlockDim

## 函数功能

获取blockDim，即参与计算的Vector或者Cube核数。blockDim的详细概念和设置方式请参考[SetBlockDim](SetBlockDim.md)。

该参数后续版本会废弃，建议使用[GetSimdNumBlocks](GetSimdNumBlocks.md)。

## 函数原型

**uint32\_t GetBlockDim\(\) const**

## 参数说明

无。

## 返回值说明

返回blockDim。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetBlockDim();
  // ...
}
```
