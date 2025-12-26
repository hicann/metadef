# IsValid<a name="ZH-CN_TOPIC_0000001265240878"></a>

## 函数功能<a name="section28644761"></a>

判断Tensor对象是否有效。

若实际Tensor数据的大小与TensorDesc所描述的Tensor数据大小一致，则有效。

## 函数原型<a name="section13475936115113"></a>

```
graphStatus IsValid()
```

## 参数说明<a name="section56476259"></a>

无。

## 返回值<a name="section38524289"></a>

graphStatus类型：如果Tensor对象有效，则返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理<a name="section11174282"></a>

无。

## 约束说明<a name="section33459681"></a>

无。

