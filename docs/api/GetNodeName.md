# GetNodeName<a name="ZH-CN_TOPIC_0000002078447853"></a>

## 函数功能<a name="zh-cn_topic_0000001636087417_zh-cn_topic_0000001390486777_section36583473819"></a>

获取算子的名称。

## 函数原型<a name="zh-cn_topic_0000001636087417_zh-cn_topic_0000001390486777_section13230182415108"></a>

```
const ge::char_t *GetNodeName() const
```

## 参数说明<a name="zh-cn_topic_0000001636087417_zh-cn_topic_0000001390486777_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001636087417_zh-cn_topic_0000001390486777_section25791320141317"></a>

返回算子的名称。

## 约束说明<a name="zh-cn_topic_0000001636087417_zh-cn_topic_0000001390486777_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001636087417_zh-cn_topic_0000001390486777_section320753512363"></a>

```
auto node_name = compute_node_info.GetNodeName();
```

