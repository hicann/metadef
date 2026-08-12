# TensorVersion

头文件位于CANN软件安装后文件存储路径下的include/exe\_graph/runtime/tensor.h。

```cpp
enum TensorVersion : uint8_t {
  kTensorV1 = 0, ///< 不携带非连续描述信息
  kTensorV2 = 1, ///< 携带非连续描述信息
};
```
