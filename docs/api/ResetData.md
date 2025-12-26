# ResetData<a name="ZH-CN_TOPIC_0000001651814845"></a>

## 函数功能<a name="section63978914"></a>

释放Tensor中数据内存。

## 函数原型<a name="section97881446182514"></a>

```
std::unique_ptr<uint8_t[], Tensor::DeleteFunc> ResetData()
```

## 参数说明<a name="section38939322"></a>

无

## 返回值<a name="section14909584"></a>

返回释放后的内存地址和删除器。

## 异常处理<a name="section67077397"></a>

无。

## 约束说明<a name="section66825666"></a>

无。

