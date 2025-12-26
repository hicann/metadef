# GetIrInputsNum<a name="ZH-CN_TOPIC_0000002042527074"></a>

## 函数功能<a name="zh-cn_topic_0000001635886857_zh-cn_topic_0000001390686717_section36583473819"></a>

获取算子IR原型定义中的输入个数。

## 函数原型<a name="zh-cn_topic_0000001635886857_zh-cn_topic_0000001390686717_section13230182415108"></a>

```
size_t GetIrInputsNum() const
```

## 参数说明<a name="zh-cn_topic_0000001635886857_zh-cn_topic_0000001390686717_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001635886857_zh-cn_topic_0000001390686717_section25791320141317"></a>

IR原型中定义的输入个数，size\_t类型。

## 约束说明<a name="zh-cn_topic_0000001635886857_zh-cn_topic_0000001390686717_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635886857_zh-cn_topic_0000001390686717_section320753512363"></a>

```
size_t index = compute_node_info->GetIrInputsNum();
```

