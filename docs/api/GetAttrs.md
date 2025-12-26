# GetAttrs<a name="ZH-CN_TOPIC_0000002042527086"></a>

## 函数功能<a name="zh-cn_topic_0000001636247417_zh-cn_topic_0000001390806845_section36583473819"></a>

获取算子的属性值。

## 函数原型<a name="zh-cn_topic_0000001636247417_zh-cn_topic_0000001390806845_section13230182415108"></a>

```
const RuntimeAttrs *GetAttrs() const
```

## 参数说明<a name="zh-cn_topic_0000001636247417_zh-cn_topic_0000001390806845_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001636247417_zh-cn_topic_0000001390806845_section25791320141317"></a>

所有IR原型定义的属性值，为const类型的对象，属性值按照IR原型定义的顺序依次保存。

## 约束说明<a name="zh-cn_topic_0000001636247417_zh-cn_topic_0000001390806845_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001636247417_zh-cn_topic_0000001390806845_section320753512363"></a>

```
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto attrs = compute_node_info->GetAttrs();
```

