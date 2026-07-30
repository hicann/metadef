# 简介

Stride结构体用于描述一个张量的步长，包含两个信息：

```cpp
size_t dim_num_;
int64_t strides_[kMaxDimNum];
```

其中，dim\_num\_表示stride的维度个数，和描述张量的维度个数一致，strides\_数组表示张量的每个维度的步长。

```cpp
size_t kMaxDimNum = 25;
```

kMaxDimNum表示能支持的最大维度数（此数值为最大可支持规格，具体支持情况以实际算子为准）。

> [!NOTE]说明
> 该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

## 需要包含的头文件

```cpp
#include <stride.h>
```
