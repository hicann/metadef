# GetInferenceContext<a name="ZH-CN_TOPIC_0000002343618625"></a>

## 函数功能<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section36583473819"></a>

获取InferenceContext指针。

## 函数原型<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section13230182415108"></a>

```
ge::InferenceContext *GetInferenceContext() const
```

## 参数说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section25791320141317"></a>

输出InferenceContext指针。

## 约束说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section320753512363"></a>

```
ge::graphStatus InferShapeForXXX(CtInferShapeContext *context) {
  const auto &read_inference_context = ct_context->GetInferenceContext();
  // ...
}
```

