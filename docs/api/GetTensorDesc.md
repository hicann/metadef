# GetTensorDesc<a name="ZH-CN_TOPIC_0000001265399802"></a>

## 函数功能<a name="section62999330"></a>

获取Tensor的描述符。

## 函数原型<a name="section11572115914156"></a>

```
TensorDesc GetTensorDesc() const
```

## 参数说明<a name="section30123063"></a>

无。

## 返回值<a name="section2672115"></a>

返回当前Tensor的描述符，[TensorDesc](TensorDesc.md)类型。

## 异常处理<a name="section24049039"></a>

无。

## 约束说明<a name="section15114764"></a>

修改返回的TensorDesc信息，不影响Tensor对象中已有的TensorDesc信息。

