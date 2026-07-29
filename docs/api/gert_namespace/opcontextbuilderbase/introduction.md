# 简介

OpContextBuilderBase是各ContextBuilder的基类，用于构造子类context中算子信息，包括算子类型、名称、输入输出原型个数、输入输出实例个数、属性等信息。

OpContextBuilderBase继承关系图如下：

![](../../figures/zh-cn_image_0000002488398321.png)

> [!NOTE]说明
> 不可单独构造OpContextBuilderBase基类对象，只能通过子类构造。

## 需要包含的头文件

```cpp
#include "base/context_builder/op_context_builder_base.h"
```
