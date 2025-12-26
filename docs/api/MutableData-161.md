# MutableData<a name="ZH-CN_TOPIC_0000002042527018"></a>

## 函数功能<a name="zh-cn_topic_0000001642297045_zh-cn_topic_0000001339868782_section36583473819"></a>

获取首个元素的指针地址，\[MutableData\(\),  reinterpret\_cast<T \*\>\(MutableData\(\)\)  + GetSize\(\)\) 中的数据即为当前容器中保存的数据。

与[GetData](GetData-162.md)接口相比，指针地址指向的内容可以修改。

## 函数原型<a name="zh-cn_topic_0000001642297045_zh-cn_topic_0000001339868782_section13230182415108"></a>

**T \*MutableData\(\)**

## 参数说明<a name="zh-cn_topic_0000001642297045_zh-cn_topic_0000001339868782_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001642297045_zh-cn_topic_0000001339868782_section25791320141317"></a>

首个元素的指针地址。

## 约束说明<a name="zh-cn_topic_0000001642297045_zh-cn_topic_0000001339868782_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642297045_zh-cn_topic_0000001339868782_section320753512363"></a>

```
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<TypedContinuousVector *>(cv_holder.get());
auto cap = cv->MutableData<int64_t>(); 
```

