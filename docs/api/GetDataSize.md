# GetDataSize<a name="ZH-CN_TOPIC_0000002042526826"></a>

## 函数功能<a name="zh-cn_topic_0000001576806841_zh-cn_topic_0000001389813337_section36583473819"></a>

获取tiling data长度。

## 函数原型<a name="zh-cn_topic_0000001576806841_zh-cn_topic_0000001389813337_section13230182415108"></a>

**size\_t GetDataSize\(\) const**

## 参数说明<a name="zh-cn_topic_0000001576806841_zh-cn_topic_0000001389813337_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001576806841_zh-cn_topic_0000001389813337_section25791320141317"></a>

tiling data长度。

## 约束说明<a name="zh-cn_topic_0000001576806841_zh-cn_topic_0000001389813337_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576806841_zh-cn_topic_0000001389813337_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
size_t data_size = td->GetDataSize(); // 0

td->SetDataSize(100U);
data_size = td->GetDataSize(); // 100
```

