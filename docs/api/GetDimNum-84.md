# GetDimNum<a name="ZH-CN_TOPIC_0000002486420690"></a>

## 函数功能<a name="zh-cn_topic_0000001634184909_zh-cn_topic_0000001390078141_section36583473819"></a>

获取Stride对象的维度个数。

## 函数原型<a name="zh-cn_topic_0000001634184909_zh-cn_topic_0000001390078141_section13230182415108"></a>

```
size_t GetDimNum() const
```

## 参数说明<a name="zh-cn_topic_0000001634184909_zh-cn_topic_0000001390078141_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001634184909_zh-cn_topic_0000001390078141_section25791320141317"></a>

Stride对象的维度个数。

## 约束说明<a name="zh-cn_topic_0000001634184909_zh-cn_topic_0000001390078141_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001634184909_zh-cn_topic_0000001390078141_section320753512363"></a>

```
Stride stride0({3, 256, 256});
auto dim_num = stride0.GetDimNum(); // 3
```

