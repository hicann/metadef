# GetSize<a name="ZH-CN_TOPIC_0000002042368638"></a>

## 函数功能<a name="zh-cn_topic_0000001585092402_zh-cn_topic_0000001390148945_section36583473819"></a>

获取tensor数据的内存大小。

## 函数原型<a name="zh-cn_topic_0000001585092402_zh-cn_topic_0000001390148945_section13230182415108"></a>

```
size_t GetSize() const
```

## 参数说明<a name="zh-cn_topic_0000001585092402_zh-cn_topic_0000001390148945_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001585092402_zh-cn_topic_0000001390148945_section25791320141317"></a>

tensor所占内存大小，单位为字节。

## 约束说明<a name="zh-cn_topic_0000001585092402_zh-cn_topic_0000001390148945_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585092402_zh-cn_topic_0000001390148945_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
auto td_size = td.GetSize(); // 100U
```

