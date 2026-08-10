# GetInputShape

## 函数功能

根据算子输入索引获取对应的输入shape指针。这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型

```cpp
const StorageShape *GetInputShape(const size_t index) const
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|index|输入|算子输入索引，从0开始计数。|

## 返回值说明

指定的输入shape指针，输入shape中包含了原始shape与运行时shape信息。关于StorageShape类型的定义，请参见[StorageShape](../storageshape/StorageShape.md)。

当输入index非法时返回空指针。

## 约束说明

无。

## 调用示例

- 调用示例

  ```cpp
  ge::graphStatus TilingForMul(TilingContext *context) {
    auto input_shape_0 = *context->GetInputShape(0);
    auto input_shape_1 = *context->GetInputShape(1);
    auto output_shape = context->GetOutputShape(0);
    ...
  }
  ```

- 获取算子实例化后实际索引相关示例

  ```cpp
  ge::graphStatus TilingForXXX(TilingContext *context) {
    // 开发者可以根据ExtendedKernelContext::GetIrInputInstanceInfo接口获取ir_index对应的实例化信息。
    // 该接口返回AnchorInstanceInfo结构，可以通过GetInstanceNum和GetInstanceStart接口获取首个实例化index以及本输入的实例化个数。
    auto ctx = reinterpret_cast<const ExtendedKernelContext *>(context);
    auto instance_info = ctx->GetIrInputInstanceInfo(0); // 0为ir index
    auto instance_num = instance_info->GetInstanceNum(); // 获取该输入的实例个数
    auto instance_start = instance_info->GetInstanceStart(); // 获取该输入的首个实例化index
    ...
    // 另外TilingContext也提供了基于ir_index获取输入的接口
    auto shape = context->GetOptionalInputShape(0); // 根据算子原型定义中的输入索引获取对应的可选输入shape指针
    auto shape = context->GetDynamicInputShape(0, 1); // 根据算子原型定义中的输入索引获取对应的动态输入shape指针
    auto shape = context->GetRequiredInputShape(0); // 根据算子原型定义中的输入索引获取对应的必选输入shape指针
  }
  ```
