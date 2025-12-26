# GetNodeType<a name="ZH-CN_TOPIC_0000002078486461"></a>

## 函数功能<a name="zh-cn_topic_0000001636247413_zh-cn_topic_0000001390806829_section36583473819"></a>

获取算子的类型。

## 函数原型<a name="zh-cn_topic_0000001636247413_zh-cn_topic_0000001390806829_section13230182415108"></a>

```
const ge::char_t *GetNodeType() const
```

## 参数说明<a name="zh-cn_topic_0000001636247413_zh-cn_topic_0000001390806829_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001636247413_zh-cn_topic_0000001390806829_section25791320141317"></a>

算子的类型。

## 约束说明<a name="zh-cn_topic_0000001636247413_zh-cn_topic_0000001390806829_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001636247413_zh-cn_topic_0000001390806829_section320753512363"></a>

```
auto node_type = compute_node_info.GetNodeType();
```

