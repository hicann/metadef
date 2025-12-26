# GetCapacity<a name="ZH-CN_TOPIC_0000002042527006"></a>

## 函数功能<a name="zh-cn_topic_0000001642575173_zh-cn_topic_0000001340326216_section36583473819"></a>

获取最大可保存的元素个数。

## 函数原型<a name="zh-cn_topic_0000001642575173_zh-cn_topic_0000001340326216_section13230182415108"></a>

```
size_t GetCapacity() const
```

## 参数说明<a name="zh-cn_topic_0000001642575173_zh-cn_topic_0000001340326216_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001642575173_zh-cn_topic_0000001340326216_section25791320141317"></a>

最大可保存的元素个数。

## 约束说明<a name="zh-cn_topic_0000001642575173_zh-cn_topic_0000001340326216_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642575173_zh-cn_topic_0000001340326216_section320753512363"></a>

```
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<ContinuousVector *>(cv_holder.get());
auto cap = cv->GetCapacity(); // 100U
```

