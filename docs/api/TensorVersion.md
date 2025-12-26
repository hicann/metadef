# TensorVersion<a name="ZH-CN_TOPIC_0000002487046886"></a>

头文件位于CANN软件安装后文件存储路径下的include/exe\_graph/runtime/tensor.h。

```
enum TensorVersion : uint8_t {
  kTensorV1 = 0, ///< 不携带非连续描述信息
  kTensorV2 = 1, ///< 携带非连续描述信息
};
```

