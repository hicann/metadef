# 简介

Shape结构体用于描述一个tensor的shape，包含两个信息：

```cpp
size_t dim_num_;
int64_t dims_[kMaxDimNum];
```

其中，dim\_num\_表示shape的维数，dims\_数组表示tensor具体的shape。

```cpp
size_t kMaxDimNum = 25;
```

kMaxDimNum表示能支持的最大维度数（此数值为最大可支持规格，具体支持情况以实际算子为准）。

## 需要包含的头文件

```cpp
#include <shape.h>
```
