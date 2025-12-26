# GetData<a name="ZH-CN_TOPIC_0000002078486209"></a>

## 函数功能<a name="zh-cn_topic_0000001526526790_zh-cn_topic_0000001389893701_section36583473819"></a>

获取TilingData的数据指针。

## 函数原型<a name="zh-cn_topic_0000001526526790_zh-cn_topic_0000001389893701_section13230182415108"></a>

**void \*GetData\(\)**

**const void \*GetData\(\) const**

## 参数说明<a name="zh-cn_topic_0000001526526790_zh-cn_topic_0000001389893701_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001526526790_zh-cn_topic_0000001389893701_section25791320141317"></a>

data指针。

## 约束说明<a name="zh-cn_topic_0000001526526790_zh-cn_topic_0000001389893701_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526526790_zh-cn_topic_0000001389893701_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
auto tiling_data_ptr = td->GetData(); // td_buf.get() + sizeof(TilingData)
```

