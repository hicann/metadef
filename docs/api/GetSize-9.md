# GetSize<a name="ZH-CN_TOPIC_0000002078486381"></a>

## 函数功能<a name="zh-cn_topic_0000001642455773_zh-cn_topic_0000001340166236_section36583473819"></a>

获取当前保存的元素个数。

## 函数原型<a name="zh-cn_topic_0000001642455773_zh-cn_topic_0000001340166236_section13230182415108"></a>

```
size_t GetSize() const
```

## 参数说明<a name="zh-cn_topic_0000001642455773_zh-cn_topic_0000001340166236_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001642455773_zh-cn_topic_0000001340166236_section25791320141317"></a>

当前保存的元素个数。

## 约束说明<a name="zh-cn_topic_0000001642455773_zh-cn_topic_0000001340166236_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642455773_zh-cn_topic_0000001340166236_section320753512363"></a>

```
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<ContinuousVector *>(cv_holder.get());
auto size = cv->GetSize(); // 0U
```

