# GetPlacement<a name="ZH-CN_TOPIC_0000002078447725"></a>

## 函数功能<a name="zh-cn_topic_0000001635291741_zh-cn_topic_0000001339389154_section36583473819"></a>

获取tensor的placement，tensor数据所在的设备位置。

## 函数原型<a name="zh-cn_topic_0000001635291741_zh-cn_topic_0000001339389154_section13230182415108"></a>

```
TensorPlacement GetPlacement() const
```

## 参数说明<a name="zh-cn_topic_0000001635291741_zh-cn_topic_0000001339389154_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001635291741_zh-cn_topic_0000001339389154_section25791320141317"></a>

tensor的placement。关于TensorPlacement类型的定义，请参见[TensorPlacement](TensorPlacement.md)。

## 约束说明<a name="zh-cn_topic_0000001635291741_zh-cn_topic_0000001339389154_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635291741_zh-cn_topic_0000001339389154_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
auto td_place = td.GetPlacement(); // kOnHost
```

