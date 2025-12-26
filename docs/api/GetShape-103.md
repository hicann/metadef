# GetShape<a name="ZH-CN_TOPIC_0000002042526970"></a>

## 函数功能<a name="zh-cn_topic_0000001584184954_zh-cn_topic_0000001390073753_section36583473819"></a>

获取Tensor的shape，包含运行时和原始shape。

## 函数原型<a name="zh-cn_topic_0000001584184954_zh-cn_topic_0000001390073753_section13230182415108"></a>

**const StorageShape &GetShape\(\) const**

**StorageShape &GetShape\(\)**

## 参数说明<a name="zh-cn_topic_0000001584184954_zh-cn_topic_0000001390073753_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001584184954_zh-cn_topic_0000001390073753_section25791320141317"></a>

-   const StorageShape &GetShape\(\) const：返回只读的shape引用。
-   StorageShape &GetShape\(\)：返回shape引用。

关于StorageShape类型的定义，请参见[StorageShape](StorageShape.md)。

## 约束说明<a name="zh-cn_topic_0000001584184954_zh-cn_topic_0000001390073753_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584184954_zh-cn_topic_0000001390073753_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {2, 1, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetShape(); // sh
```

