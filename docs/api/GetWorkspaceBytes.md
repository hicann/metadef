# GetWorkspaceBytes<a name="ZH-CN_TOPIC_0000002445955430"></a>

## 函数功能<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section36583473819"></a>

获取Workspace大小。

## 函数原型<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section13230182415108"></a>

```
std::vector<int64_t> GetWorkspaceBytes() const
```

## 参数说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section25791320141317"></a>

返回Workspace大小配置信息。

## 约束说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section320753512363"></a>

```
std::vector<int64_t> GetWorkspaceBytes(ExeResGenerationContext* context) {
  std::vector<int64_t> workspaceList = context->GetWorkspaceBytes();
  // ...
}
```

