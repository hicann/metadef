# IsScalar<a name="ZH-CN_TOPIC_0000002042527030"></a>

## 函数功能<a name="zh-cn_topic_0000001583705862_zh-cn_topic_0000001389918557_section36583473819"></a>

判断本shape是否为标量，所谓标量，是指GetDimNum\(\)为0。

## 函数原型<a name="zh-cn_topic_0000001583705862_zh-cn_topic_0000001389918557_section13230182415108"></a>

```
bool IsScalar() const
```

## 参数说明<a name="zh-cn_topic_0000001583705862_zh-cn_topic_0000001389918557_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001583705862_zh-cn_topic_0000001389918557_section25791320141317"></a>

true/false。

## 约束说明<a name="zh-cn_topic_0000001583705862_zh-cn_topic_0000001389918557_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001583705862_zh-cn_topic_0000001389918557_section320753512363"></a>

```
Shape shape0({3, 256, 256});
Shape shape2;
shape0.IsScalar(); // false
shape2.IsScalar(); // true
```

