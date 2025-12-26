# GetSize<a name="ZH-CN_TOPIC_0000002042527014"></a>

## 函数功能<a name="zh-cn_topic_0000001749986325_zh-cn_topic_0000001390446193_section36583473819"></a>

获取当前存放的实际元素数量。

## 函数原型<a name="zh-cn_topic_0000001749986325_zh-cn_topic_0000001390446193_section13230182415108"></a>

```
size_t GetSize() const
```

## 参数说明<a name="zh-cn_topic_0000001749986325_zh-cn_topic_0000001390446193_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001749986325_zh-cn_topic_0000001390446193_section25791320141317"></a>

当前存放的实际元素数量。

## 约束说明<a name="zh-cn_topic_0000001749986325_zh-cn_topic_0000001390446193_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001749986325_zh-cn_topic_0000001390446193_section320753512363"></a>

```
// 创建ContinuousVectorVector对象cvv
...
// 增加元素
...
auto cv = cvv->add(inner_vector_capacity);
...
// 获取当前存放的实际元素数量
auto size = cvv->GetSize();
```

