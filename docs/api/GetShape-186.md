# GetShape<a name="ZH-CN_TOPIC_0000001264921074"></a>

## 函数功能<a name="section48806003"></a>

获取TensorDesc所描述Tensor的Shape。

## 函数原型<a name="section413831542619"></a>

```
Shape GetShape() const
```

## 参数说明<a name="section36600850"></a>

无。

## 返回值<a name="section60972199"></a>

[Shape](Shape-176.md)类型，TensorDesc描述的Shape。

## 异常处理<a name="section11878883"></a>

无。

## 约束说明<a name="section39801087"></a>

由于返回的Shape信息为值拷贝，因此修改返回的Shape信息，不影响TensorDesc中已有的Shape信息。

