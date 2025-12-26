# GetTilingKey<a name="ZH-CN_TOPIC_0000002042368502"></a>

## 函数功能<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section36583473819"></a>

获取tiling key。

## 函数原型<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section13230182415108"></a>

**uint64\_t GetTilingKey\(\) const**

## 参数说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section25791320141317"></a>

返回tiling key。

## 约束说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_key = context->GetTilingKey();
  // ...
}
```

