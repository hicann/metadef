# GetAttrNum<a name="ZH-CN_TOPIC_0000002042368694"></a>

## 函数功能<a name="zh-cn_topic_0000001640332725_zh-cn_topic_0000001339260924_section36583473819"></a>

获取属性的数量。

## 函数原型<a name="zh-cn_topic_0000001640332725_zh-cn_topic_0000001339260924_section13230182415108"></a>

```
size_t GetAttrNum() const
```

## 参数说明<a name="zh-cn_topic_0000001640332725_zh-cn_topic_0000001339260924_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001640332725_zh-cn_topic_0000001339260924_section25791320141317"></a>

属性的数量。

## 约束说明<a name="zh-cn_topic_0000001640332725_zh-cn_topic_0000001339260924_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001640332725_zh-cn_topic_0000001339260924_section320753512363"></a>

```
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
size_t attr_num = runtime_attrs->GetAttrNum();
```

