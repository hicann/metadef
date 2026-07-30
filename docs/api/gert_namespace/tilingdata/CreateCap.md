# CreateCap

## 函数功能

根据指定的最大容量创建一个TilingData类实例。

## 函数原型

**static std::unique\_ptr<uint8\_t\[\]\> CreateCap\(const size\_t cap\_size\)**

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|cap_size|输入|最大容量，单位为字节。|

## 返回值说明

TilingData的实例指针。

## 约束说明

无。

## 调用示例

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
```
