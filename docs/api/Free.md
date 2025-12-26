# Free<a name="ZH-CN_TOPIC_0000002042368646"></a>

## 函数功能<a name="zh-cn_topic_0000001585411738_zh-cn_topic_0000001389829057_section36583473819"></a>

释放Tensor。

## 函数原型<a name="zh-cn_topic_0000001585411738_zh-cn_topic_0000001389829057_section13230182415108"></a>

```
ge::graphStatus Free()
```

## 参数说明<a name="zh-cn_topic_0000001585411738_zh-cn_topic_0000001389829057_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001585411738_zh-cn_topic_0000001389829057_section25791320141317"></a>

成功时返回：ge::GRAPH\_SUCCESS，失败时返回manager函数返回的状态码。

关于ge::graphStatus类型的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001585411738_zh-cn_topic_0000001389829057_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585411738_zh-cn_topic_0000001389829057_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
td.Free();
```

