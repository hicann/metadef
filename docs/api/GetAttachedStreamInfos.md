# GetAttachedStreamInfos<a name="ZH-CN_TOPIC_0000002445955426"></a>

## 函数功能<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section36583473819"></a>

返回当前算子绑定的所有StreamInfo列表。

## 函数原型<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section13230182415108"></a>

```
std::vector<StreamInfo> GetAttachedStreamInfos() const
```

## 参数说明<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section25791320141317"></a>

返回当前算子绑定的所有[StreamInfo](StreamInfo.md)列表。

## 约束说明<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section320753512363"></a>

```
std::vector<StreamInfo> GetAttachedStreamInfos(ExeResGenerationContext* context) {
  std::vector<StreamInfo> streamInfoList = context->GetAttachedStreamInfos();
  ...
}
```

