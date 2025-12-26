# GetWorkspaceNum<a name="ZH-CN_TOPIC_0000002078447597"></a>

## 函数功能<a name="zh-cn_topic_0000001652207309_zh-cn_topic_0000001647547005_section36583473819"></a>

获取workspace个数。

## 函数原型<a name="zh-cn_topic_0000001652207309_zh-cn_topic_0000001647547005_section13230182415108"></a>

**size\_t GetWorkspaceNum\(\) const**

## 参数说明<a name="zh-cn_topic_0000001652207309_zh-cn_topic_0000001647547005_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001652207309_zh-cn_topic_0000001647547005_section25791320141317"></a>

workspace的个数。

## 约束说明<a name="zh-cn_topic_0000001652207309_zh-cn_topic_0000001647547005_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001652207309_zh-cn_topic_0000001647547005_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ws_num = context->GetWorkspaceNum();
  // ...
}
```

