# GetPcieThroughFlag

## 函数功能

查询当前上下文是否启用PCIE Through。

## 函数原型

```cpp
bool GetPcieThroughFlag() const
```

## 参数说明

无

## 返回值说明

true：当前上下文已启用PCIE Through

false：当前上下文未启用PCIE Through

## 调用示例

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  bool ret = context->GetPcieThroughFlag();
  // ...
}
```
