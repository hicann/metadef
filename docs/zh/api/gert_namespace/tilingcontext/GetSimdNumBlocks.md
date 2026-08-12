# GetSimdNumBlocks

## 函数功能

获取SIMD Blocks数量，即参与计算的Vector或者Cube核数。num\_blocks的详细概念和设置方式请参考[SetSimdNumBlocks](SetSimdNumBlocks.md)。

## 函数原型

```cpp
uint32_t GetSimdNumBlocks() const
```

## 参数说明

无

## 返回值说明

返回num\_blocks。

## 约束说明

无

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetSimdNumBlocks();
  // ...
}
```
