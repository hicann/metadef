# GetAttrs<a name="ZH-CN_TOPIC_0000002078486309"></a>

## 函数功能<a name="zh-cn_topic_0000001636046749_zh-cn_topic_0000001389265529_section36583473819"></a>

获取算子的属性值，仅在算子IR原型定义中的属性值会被返回，其他属性值被丢弃。

## 函数原型<a name="zh-cn_topic_0000001636046749_zh-cn_topic_0000001389265529_section13230182415108"></a>

```
const RuntimeAttrs *GetAttrs() const
```

## 参数说明<a name="zh-cn_topic_0000001636046749_zh-cn_topic_0000001389265529_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001636046749_zh-cn_topic_0000001389265529_section25791320141317"></a>

所有IR原型定义的属性值，为const类型的对象，属性值按照IR原型定义的顺序依次保存。

## 约束说明<a name="zh-cn_topic_0000001636046749_zh-cn_topic_0000001389265529_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001636046749_zh-cn_topic_0000001389265529_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto rt_attrs = extend_context->GetAttrs();
```

