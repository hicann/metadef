# GetOpId<a name="ZH-CN_TOPIC_0000002446115282"></a>

## 函数功能<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section36583473819"></a>

获取当前算子的唯一标识ID。

## 函数原型<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section13230182415108"></a>

```
int64_t GetOpId() const
```

## 参数说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section25791320141317"></a>

返回一个int64\_t类型的整数，代表这个算子在计算图中的唯一编号。

## 约束说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section320753512363"></a>

```
int64_t GetOpId(ExeResGenerationContext* context) {
  auto opId= context->GetOpId();
  // ...
}
```

