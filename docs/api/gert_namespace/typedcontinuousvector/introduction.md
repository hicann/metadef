# 简介

本类继承自ContinuousVector类，与ContinuousVector类不同的是MutableData和GetData返回的是指定类型的地址，而不是void \*。因此称为Typed。

TypedContinuousVector继承关系图如下：

![](../../figures/zh-cn_image_0000002255870305.png)

## 需要包含的头文件

```cpp
#include <continuous_vector.h>
```
