# GetInstanceNum

## 函数功能

获取当前输入/输出Anchor被实例化的实例个数（即instantiation\_num\_字段）。

## 函数原型

```cpp
size_t GetInstanceNum() const
```

## 参数说明

无。

## 返回值说明

该输入/输出Anchor被实例化的实例个数。

## 约束说明

无。

## 调用示例

```cpp
AnchorInstanceInfo anchor_0(0, 10); //IR原型定义的第一个输入是动态输入，且有10个实际输入
auto input_num_0 = anchor_0.GetInstanceNum(); // input_num_0 = 10
```
