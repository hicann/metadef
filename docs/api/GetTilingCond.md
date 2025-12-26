# GetTilingCond<a name="ZH-CN_TOPIC_0000002042368506"></a>

## 函数功能<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section36583473819"></a>

获取[GetTilingCond](GetTilingCond.md)中设置的tiling cond。

## 函数原型<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section13230182415108"></a>

**int32\_t GetTilingCond\(\) const**

## 参数说明<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section25791320141317"></a>

若返回值大于等于0，代表此tiling cond为有效的tiling cond。

若返回值为-1，代表此tiling cond为无效的tiling cond。

## 约束说明<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_cond = context->GetTilingCond();
  // ...
}
```

