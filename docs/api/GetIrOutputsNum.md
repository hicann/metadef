# GetIrOutputsNum<a name="ZH-CN_TOPIC_0000002078447857"></a>

## 函数功能<a name="zh-cn_topic_0000001886856113_zh-cn_topic_0000001628658402_section36583473819"></a>

获取算子IR原型定义中的输出个数。

## 函数原型<a name="zh-cn_topic_0000001886856113_zh-cn_topic_0000001628658402_section13230182415108"></a>

```
size_t GetIrOutputsNum() const
```

## 参数说明<a name="zh-cn_topic_0000001886856113_zh-cn_topic_0000001628658402_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001886856113_zh-cn_topic_0000001628658402_section25791320141317"></a>

IR原型中定义的输出个数，size\_t类型。

## 约束说明<a name="zh-cn_topic_0000001886856113_zh-cn_topic_0000001628658402_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001886856113_zh-cn_topic_0000001628658402_section320753512363"></a>

```
size_t index = compute_node_info->GetIrOutputsNum();
```

