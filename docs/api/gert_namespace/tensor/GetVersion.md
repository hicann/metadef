# GetVersion

## 函数功能

获取Tensor中的版本。kTensorV1：不携带view和offset信息，kTensorV2：携带view和offset信息

> [!NOTE]说明
> 该接口为预留接口，为后续的功能做保留，当前版本暂不支持。

## 函数原型

```cpp
TensorVersion GetVersion () const
```

## 参数说明

无

## 返回值说明

获取Tensor的version。

关于TensorVersion类型的定义，请参见[TensorVersion](../TensorVersion.md)。

## 约束说明

无

## 调用示例

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
               {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
               kFollowing,                                  // placement
               ge::DT_FLOAT16,                              //dt
               nullptr};
auto version = tensor.GetVersion(); // kTensorV1
```
