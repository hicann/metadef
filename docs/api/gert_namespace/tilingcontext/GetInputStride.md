# GetInputStride

## 函数功能

根据算子输入索引获取对应的输入Stride指针。这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。

> [!NOTE]说明
> 该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

## 函数原型

```cpp
const Stride *GetInputStride(const size_t index) const
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|index|输入|算子输入索引，从0开始计数。|

## 返回值说明

指定的输入Stride指针。关于Stride类型的定义，请参见[Stride](../stride/Stride.md)。

index非法或者Tensor不携带非连续描述信息时返回空指针。

## 约束说明

无

## 调用示例

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto input_stride_0 = *context->GetInputStride(0);
  ...
}
```
