# GetDynamicInputShape

## 函数功能

根据算子原型定义中的输入索引获取对应的动态输入shape指针。

## 函数原型

**const StorageShape \*GetDynamicInputShape\(const size\_t ir\_index, const size\_t relative\_index\) const**

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|ir_index|输入|动态输入在算子IR原型定义中的索引，从0开始计数。|
|relative_index|输入|该输入实例化后的相对index，例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的取值范围是[0,2]。|

## 返回值说明

指定的输入shape指针，shape中包含了原始shape与运行时shape。关于StorageShape类型的定义，请参见[StorageShape](../storageshape/StorageShape.md)。

当输入ir\_index或relative\_index非法时，返回空指针。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus InferShape4ConcatD(TilingContext* context) {
  auto in_shape = context->GetDynamicInputShape(dynamic_input_idx, 0);
  ...
}
```
