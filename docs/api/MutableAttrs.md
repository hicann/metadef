# MutableAttrs<a name="ZH-CN_TOPIC_0000002042368790"></a>

## 函数功能<a name="zh-cn_topic_0000001840616852_zh-cn_topic_0000001340046950_section36583473819"></a>

获取算子的属性值，仅在算子IR原型定义和调用IMPL\_OP宏注册的属性值会被返回，其他属性值被丢弃。

本方法与[GetAttrs](GetAttrs.md)的区别在于可以返回非const的属性对象。

## 函数原型<a name="zh-cn_topic_0000001840616852_zh-cn_topic_0000001340046950_section13230182415108"></a>

```
RuntimeAttrs *MutableAttrs() const
```

## 参数说明<a name="zh-cn_topic_0000001840616852_zh-cn_topic_0000001340046950_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001840616852_zh-cn_topic_0000001340046950_section25791320141317"></a>

所有IR原型定义过的属性值以及通过IMPL\_OP宏注册的属性值，属性值按照IR原型定义的顺序依次保存。返回对象为非const。

## 约束说明<a name="zh-cn_topic_0000001840616852_zh-cn_topic_0000001340046950_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001840616852_zh-cn_topic_0000001340046950_section320753512363"></a>

```
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto attrs = compute_node_info->MutableAttrs();
```

