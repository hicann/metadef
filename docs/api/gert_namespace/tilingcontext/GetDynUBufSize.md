# GetDynUBufSize

## 函数功能

SIMT算子获取所需的Dynamic Unified Buffer大小。

## 函数原型

```cpp
uint32_t GetDynUBufSize()
```

## 参数说明

无

## 返回值说明

返回Dynamic Unified Buffer大小，如果之前没有调用SetDynUBufSize进行设置，则返回0。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
    // ...
    auto dyn_ubuf_size = context->GetDynUBufSize();
}
```
