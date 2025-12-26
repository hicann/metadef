# NeedAtomic<a name="ZH-CN_TOPIC_0000002078447593"></a>

## 函数功能<a name="zh-cn_topic_0000001640325005_zh-cn_topic_0000001339190800_section36583473819"></a>

获取是否需要atomic clean的标识值。

## 函数原型<a name="zh-cn_topic_0000001640325005_zh-cn_topic_0000001339190800_section13230182415108"></a>

**bool NeedAtomic\(\) const**

## 参数说明<a name="zh-cn_topic_0000001640325005_zh-cn_topic_0000001339190800_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001640325005_zh-cn_topic_0000001339190800_section25791320141317"></a>

-   true：代表需要做atomic clean。
-   false：代表不需要做atomic clean。

## 约束说明<a name="zh-cn_topic_0000001640325005_zh-cn_topic_0000001339190800_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001640325005_zh-cn_topic_0000001339190800_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  bool is_need_atomic = context->NeedAtomic();
  // ...
}
```

