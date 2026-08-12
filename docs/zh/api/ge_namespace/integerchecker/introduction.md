# 简介

IntegerChecker是一个模板类，带有模板参数T，用于检查一个整数是否在指定数据类型T的合法范围内。

## 需要包含的头文件

```cpp
#include <extern_math_util.h>
```

## Public成员函数

```cpp
template<typename T>
class IntegerChecker {
 public:
  template<typename T1>
  static bool Compat(const T1 v) {
  // 具体实现
  }
};
```
