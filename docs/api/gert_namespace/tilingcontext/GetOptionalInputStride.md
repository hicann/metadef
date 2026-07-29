# GetOptionalInputStride

## 函数功能

根据算子原型定义中的输入索引获取对应的可选输入Tensor的Stride指针。

> [!NOTE]说明
> 该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

## 函数原型

```cpp
const Stride *GetOptionalInputStride(const size_t ir_index) const
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|ir_index|输入|可选输入在算子IR原型定义中的索引，从0开始计数。|

## 返回值说明

指定ir\_index的输入Tensor的Stride指针。关于Stride类型的定义，请参见[Stride](../stride/Stride.md)。

当输入ir\_index非法或该INPUT没有实例化或该Tensor未携带非连续描述信息时，返回空指针。

## 约束说明

无

## 调用示例

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto option_input_stride_0 = *context->GetOptionalInputStride(0);
  ...
}
```
