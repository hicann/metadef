# GetStreamId<a name="ZH-CN_TOPIC_0000002479435077"></a>

## 函数功能<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section36583473819"></a>

返回当前算子绑定的StreamId。

## 函数原型<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
int64_t GetStreamId() const
```

## 参数说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section25791320141317"></a>

返回当前算子绑定的StreamId。

## 约束说明<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section19165124931511"></a>

只有在每个算子只能绑定一个Stream的前提下可以使用该接口。

## 调用示例<a name="zh-cn_topic_0000001526526778_zh-cn_topic_0000001339507276_section320753512363"></a>

```
int64_t GetStreamId(ExeResGenerationContext* context) {
  auto streamId= context->GetStreamId();
  ...
}
```

