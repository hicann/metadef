# TensorPlacement<a name="ZH-CN_TOPIC_0000002078447893"></a>

```
enum TensorPlacement {
    kOnDeviceHbm,  ///< Tensor位于Device
    kOnHost,       ///< Tensor位于Host
    kFollowing,    ///< Tensor位于Host，且数据紧跟在结构体后面
    kOnDeviceP2p,  ///< Tensor位于Device, P2p内存指的是Device内存透到PCIE BAR空间上可以让NPU跨PCIE访问的地址空间
    kTensorPlacementEnd
};
```

