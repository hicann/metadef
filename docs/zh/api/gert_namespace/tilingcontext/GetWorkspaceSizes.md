# GetWorkspaceSizes

## 函数功能

获取workspace sizes指针，workspace大小以字节为单位。

## 函数原型

```cpp
size_t *GetWorkspaceSizes(const size_t workspace_count)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|workspace_count|输入|workspace的个数，取值不超过GetWorkspaceNum返回的workspace个数。超出时，会返回空指针。|

## 返回值说明

workspace sizes指针。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
    auto ws = context->GetWorkspaceSizes(5);
    if (ws == nullptr) {
        return ge::GRAPH_FAILED;
    }
    // ...
}
```
