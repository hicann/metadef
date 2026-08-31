# SetPcieThroughFlag

## 函数功能

设置是否支持PCIE Through。

## 函数原型

```cpp
OpTilingContextBuilder &SetPcieThroughFlag(bool flag);
```

## 参数说明

|参数|输入/输出| 说明                                                             |
|--|--|----------------------------------------------------------------|
|flag|输入| 设置是否支持PCIE Through（true为支持PCIE Through，false为不支持PCIE Through）。 |

## 返回值说明

OpTilingContextBuilder对象本身，用于链式调用。
