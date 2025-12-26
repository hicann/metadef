# GetRawTilingData<a name="ZH-CN_TOPIC_0000002042368510"></a>

## 函数功能<a name="zh-cn_topic_0000001526046962_zh-cn_topic_0000001339350472_section36583473819"></a>

获取无类型的tiling data指针。

## 函数原型<a name="zh-cn_topic_0000001526046962_zh-cn_topic_0000001339350472_section13230182415108"></a>

**TilingData \*GetRawTilingData\(\)**

## 参数说明<a name="zh-cn_topic_0000001526046962_zh-cn_topic_0000001339350472_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001526046962_zh-cn_topic_0000001339350472_section25791320141317"></a>

tiling data指针，失败时返回空指针。

## 约束说明<a name="zh-cn_topic_0000001526046962_zh-cn_topic_0000001339350472_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526046962_zh-cn_topic_0000001339350472_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_data = context->GetRawTilingData();
  // ...
}
```

