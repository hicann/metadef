# SetDynUBufSize

## 函数功能

SIMT算子用于设置需要使用的Dynamic Unified Buffer大小。不设置的情况下，默认为0，即算子不需要使用Dynamic Unified Buffer。

## 函数原型

```cpp
ge::graphStatus SetDynUBufSize(const uint32_t dyn_ubuf_size)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|local_memory_size|输入|Dynamic Unified Buffer大小。|

## 返回值说明

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](../../ge_namespace/ge-graphStatus.md)。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
    // ...
    auto ret = context->SetDynUBufSize(1024 * 128);
}
```
