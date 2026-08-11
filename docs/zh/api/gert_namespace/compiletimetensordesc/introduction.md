# 简介

CompileTimeTensorDesc用于描述编译时张量的基本信息，包括数据类型（ge::DataType）、数据排布格式（gert::StorageFormat，包括原始格式和运行时格式）以及原始格式向运行时格式转换时的补维规则。该类提供了对张量数据类型的获取和设置方法，同时支持对原始格式和运行时格式的管理。

## 需要包含的头文件

```cpp
#include <compute_node_info.h>
```
