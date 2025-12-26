# GetSyncResInfos<a name="ZH-CN_TOPIC_0000002479355301"></a>

## 函数功能<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section36583473819"></a>

返回当前对象中保存的全部同步资源信息（SyncResInfo列表），用于查询或外部使用。

## 函数原型<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section13230182415108"></a>

```
std::vector<SyncResInfo> GetSyncResInfos() const
```

## 参数说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section25791320141317"></a>

返回当前对象中保存的全部同步资源信息（[SyncResInfo](SyncResInfo.md)列表）。

## 约束说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section320753512363"></a>

```
std::vector<SyncResInfo> GetSyncResInfos(ExeResGenerationContext* context) {
  std::vector<SyncResInfo> syncResInfoList = context->GetSyncResInfos();
  ...
}
```

