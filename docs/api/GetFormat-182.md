# GetFormat<a name="ZH-CN_TOPIC_0000001265080962"></a>

## 函数功能<a name="section10385171"></a>

获取TensorDesc所描述的Tensor的Format。

## 函数原型<a name="section8862140202714"></a>

```
Format GetFormat() const
```

## 参数说明<a name="section26357682"></a>

无。

## 返回值<a name="section35892552"></a>

[Format](Format.md)类型，TensorDesc所描述的Tensor的Format信息。

## 异常处理<a name="section54597518"></a>

无。

## 约束说明<a name="section21615622"></a>

由于返回的Format信息为值拷贝，因此修改返回的Format信息，不影响TensorDesc中已有的Format信息。

