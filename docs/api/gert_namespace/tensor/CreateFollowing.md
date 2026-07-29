# CreateFollowing

## 函数功能

创建一个指定数据类型以及大小的Tensor，其数据在Tensor对象后连续排布。

## 函数原型

- 传入元素个数和数据类型，创建Tensor

  **static std::unique\_ptr<uint8\_t\[\]\> CreateFollowing\(const int64\_t shape\_size, const ge::DataType dt, size\_t &total\_size\)**

- 传入数据类型和Tensor长度，创建Tensor

  **static std::unique\_ptr<uint8\_t\[\]\> CreateFollowing\(const ge::DataType dt, const size\_t tensor\_size, size\_t &total\_size\)**

## 参数说明

**表 1**  参数说明（传入元素个数和数据类型，创建Tensor）

|参数|输入/输出|说明|
|--|--|--|
|shape_size|输入|元素个数。|
|dt|输入|数据类型，DataType类型。|
|total_size|输出|创建出的Tensor在内存中的长度。包含Tensor对象的长度和Tensor数据的长度。|

**表 2**  参数说明（传入数据类型和Tensor长度，创建Tensor）

|参数|输入/输出|说明|
|--|--|--|
|dt|输入|数据类型，DataType类型。|
|tensor_size|输入|Tensor数据的长度。单位为字节。|
|total_size|输出|创建出的Tensor在内存中的长度。和tensor_size参数不同，total_size包含Tensor对象的长度和Tensor数据的长度。单位为字节。|

## 返回值说明

创建的Tensor指针。

## 约束说明

无。

## 调用示例

```cpp
size_t total_size;
auto tensor_holder = Tensor::CreateFollowing(shape_size, tensor_desc.GetDataType(), total_size);
```
