# MutableStorageShape<a name="ZH-CN_TOPIC_0000002042368662"></a>

## 函数功能<a name="zh-cn_topic_0000001634184897_zh-cn_topic_0000001339393882_section36583473819"></a>

获取运行时Tensor的shape，此shape对象是可变的。

## 函数原型<a name="zh-cn_topic_0000001634184897_zh-cn_topic_0000001339393882_section13230182415108"></a>

**Shape &MutableStorageShape\(\)**

## 参数说明<a name="zh-cn_topic_0000001634184897_zh-cn_topic_0000001339393882_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001634184897_zh-cn_topic_0000001339393882_section25791320141317"></a>

运行时shape的引用。

## 约束说明<a name="zh-cn_topic_0000001634184897_zh-cn_topic_0000001339393882_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634184897_zh-cn_topic_0000001339393882_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {2, 1, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.MutableStorageShape(); // 2,1,3
```

