# GetDynamicInputStride

## 函数功能

根据算子原型定义中的输入索引获取对应的动态输入Tensor的Stride指针。

> [!NOTE]说明
> 该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

## 函数原型

```cpp
const Stride *GetDynamicInputStride(const size_t ir_index, const size_t relative_index) const
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|ir_index|输入|算子IR原型定义中的输入索引，从0开始计数。|
|relative_index|输入|该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的有效范围是[0,2]。|

## 返回值说明

指定的输入Tensor的stride指针。ir\_index或relative\_index非法或Tensor不携带非连续描述信息时，返回空指针。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto dynamic_input_stride_0 = *context->GetDynamicInputStride(0);
  ...
}
```
