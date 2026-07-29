# AscendStringToDataType

## 函数功能

将DataType字符串表达转化为DataType类型值。

使用该接口需要包含type\_utils.h头文件。

```cpp
#include "graph/utils/type_utils.h"
```

## 函数原型

```cpp
static DataType AscendStringToDataType(const AscendString &str)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|str|输入|待转换的DataType字符串形式，AscendString类型。|

## 返回值说明

输入合法时，返回转换后的DataType enum值，枚举定义请参考[DataType](../DataType.md)；输入不合法时，返回DT\_UNDEFINED并打印报错日志。

## 约束说明

无。

## 调用示例

```cpp
ge::AscendString type_str("DT_UINT32");
auto data_type = ge::TypeUtils::AscendStringToDataType(type_str); // 8
```
