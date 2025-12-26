# GetFullSize<a name="ZH-CN_TOPIC_0000002042368810"></a>

## 函数功能<a name="zh-cn_topic_0000001635065529_zh-cn_topic_0000001339425876_section36583473819"></a>

获取补维后的dim数。

## 函数原型<a name="zh-cn_topic_0000001635065529_zh-cn_topic_0000001339425876_section13230182415108"></a>

```
AxisIndex GetFullSize() const
```

## 参数说明<a name="zh-cn_topic_0000001635065529_zh-cn_topic_0000001339425876_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001635065529_zh-cn_topic_0000001339425876_section25791320141317"></a>

返回补维规则的长度，或者说是补维规则描述的维度。

## 约束说明<a name="zh-cn_topic_0000001635065529_zh-cn_topic_0000001339425876_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635065529_zh-cn_topic_0000001339425876_section320753512363"></a>

```
ExpandDimsType type1("1001");
auto dim_num = type1.GetFullSize(); // dim_num=4
```

