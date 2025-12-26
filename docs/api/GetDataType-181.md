# GetDataType<a name="ZH-CN_TOPIC_0000001312399917"></a>

## 函数功能<a name="section25151514"></a>

获取TensorDesc所描述Tensor的数据类型。

## 函数原型<a name="section1414418489288"></a>

```
DataType GetDataType() const
```

## 参数说明<a name="section25037038"></a>

无。

## 返回值<a name="section24006753"></a>

[DataType](DataType.md)类型，TensorDesc所描述的Tensor的数据类型。

## 异常处理<a name="section14734188"></a>

无。

## 约束说明<a name="section65498832"></a>

由于返回的DataType信息为值拷贝，因此修改返回的DataType信息，不影响TensorDesc中已有的DataType信息。

