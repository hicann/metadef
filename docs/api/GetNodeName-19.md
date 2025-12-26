# GetNodeName<a name="ZH-CN_TOPIC_0000002042526934"></a>

## 函数功能<a name="zh-cn_topic_0000001586126854_zh-cn_topic_0000001338945520_section36583473819"></a>

获取算子的名称。

## 函数原型<a name="zh-cn_topic_0000001586126854_zh-cn_topic_0000001338945520_section13230182415108"></a>

```
const ge::char_t *GetNodeName() const
```

## 参数说明<a name="zh-cn_topic_0000001586126854_zh-cn_topic_0000001338945520_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001586126854_zh-cn_topic_0000001338945520_section25791320141317"></a>

算子的名称。

## 约束说明<a name="zh-cn_topic_0000001586126854_zh-cn_topic_0000001338945520_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586126854_zh-cn_topic_0000001338945520_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto node_name = extend_context->GetNodeName();
```

