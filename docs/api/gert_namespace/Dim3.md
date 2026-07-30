# Dim3

Dim3结构体定义如下：

```cpp
struct Dim3 {
  uint32_t x, y, z;
  Dim3(const uint32_t dim3_x, const uint32_t dim3_y = 1, const uint32_t dim3_z = 1) : x(dim3_x), y(dim3_y), z(dim3_z) {
  }
};
```

Dim3是包含了x、y、z三个uint32字段的结构体。在SIMT中，可以表示一个Block线程块在x、y、z三个维度上的线程数量；也可以表示一个Grid线程格在x、y、z三个维度上的线程块数量。
