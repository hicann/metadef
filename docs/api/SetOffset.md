# SetOffset<a name="ZH-CN_TOPIC_0000002487041628"></a>

## 函数功能<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section36583473819"></a>

设置Tensor中的offset。

## 函数原型<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section13230182415108"></a>

```
void SetOffset(const int64_t offset)
```

## 参数说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section75395119104"></a>

Tensor的offset。

## 返回值说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section25791320141317"></a>

无

## 约束说明<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001583865634_zh-cn_topic_0000001389833813_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 0};
t.SetOffset(10);
auto offset = t.GetOffset(); // 10
```

