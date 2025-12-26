# GetData<a name="ZH-CN_TOPIC_0000002042368714"></a>

## 函数功能<a name="zh-cn_topic_0000001642455777_zh-cn_topic_0000001340348314_section36583473819"></a>

获取首个元素的指针地址，\[GetData\(\),  reinterpret\_cast<T \*\>\(GetData\(\)\)  + GetSize\(\)\) 中的数据即为当前容器中保存的数据。

## 函数原型<a name="zh-cn_topic_0000001642455777_zh-cn_topic_0000001340348314_section13230182415108"></a>

**const T \*GetData\(\) const**

## 参数说明<a name="zh-cn_topic_0000001642455777_zh-cn_topic_0000001340348314_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001642455777_zh-cn_topic_0000001340348314_section25791320141317"></a>

首个元素的指针地址。

## 约束说明<a name="zh-cn_topic_0000001642455777_zh-cn_topic_0000001340348314_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642455777_zh-cn_topic_0000001340348314_section320753512363"></a>

```
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<TypedContinuousVector *>(cv_holder.get());
auto cap = cv->GetData<int64_t>(); 
```

