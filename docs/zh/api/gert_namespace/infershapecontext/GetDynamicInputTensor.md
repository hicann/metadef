# GetDynamicInputTensor

## 函数功能

根据算子原型定义中的输入索引获取对应的动态输入tensor指针。

## 函数原型

```cpp
const Tensor *GetDynamicInputTensor(const size_t ir_index, const size_t relative_index) const
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|ir_index|输入|算子IR原型定义中的输入索引，从0开始计数。|
|relative_index|输入|该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的有效范围是[0,2]。|

## 返回值说明

指定的输入tensor指针，ir\_index或relative\_index非法时，返回空指针。

关于Tensor类型的定义，请参见[Tensor](../tensor/Tensor.md)。

## 约束说明

仅在设置数据依赖时可以获取tensor的数据地址。如果输入没有被设置为数据依赖，调用此接口获取tensor时，只能在tensor中获取到正确的shape、format、datatype信息，无法获取到真实的tensor数据地址（获取到的地址为nullptr）。

数据依赖：一般来说，具备输入shape后，算子可以通过InferShape推导出输出shape。然而部分算子在InferShape时，需要依赖某个输入的具体值才可以进行，这类算子被称为“数据依赖算子”，对应的输入被称为“数据依赖输入”。

## 调用示例

```cpp
ge::graphStatus InferShapeForXXX(InferShapeContext *context) {
  auto in_shape = context->GetInputShape(0);
  GE_ASSERT_NOTNULL(in_shape);
  auto axes_tensor_10 = context->GetDynamicInputTensor(1, 0);
  auto axes_tensor_11 = context->GetDynamicInputTensor(1, 1);
  ...
}
```
