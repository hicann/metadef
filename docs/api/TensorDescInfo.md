# TensorDescInfo<a name="ZH-CN_TOPIC_0000001265240886"></a>

```
    struct TensorDescInfo {
        Format format_ = FORMAT_RESERVED;        /* tbe op register support format */
        DataType dataType_ = DT_UNDEFINED;       /* tbe op register support datatype */
    };
```

Format为枚举类型，定义请参考[Format](Format.md)。

DataType为枚举类型，定义请参考[DataType](DataType.md)。

