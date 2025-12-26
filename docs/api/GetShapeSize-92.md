# GetShapeSize<a name="ZH-CN_TOPIC_0000002078447733"></a>

## 函数功能<a name="zh-cn_topic_0000001583705838_zh-cn_topic_0000001389831777_section36583473819"></a>

获取当前Tensor运行时的shape大小，即此Tensor中包含的元素的数量。

## 函数原型<a name="zh-cn_topic_0000001583705838_zh-cn_topic_0000001389831777_section13230182415108"></a>

```
int64_t GetShapeSize() const
```

## 参数说明<a name="zh-cn_topic_0000001583705838_zh-cn_topic_0000001389831777_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001583705838_zh-cn_topic_0000001389831777_section25791320141317"></a>

返回执行时shape的大小。

## 约束说明<a name="zh-cn_topic_0000001583705838_zh-cn_topic_0000001389831777_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001583705838_zh-cn_topic_0000001389831777_section320753512363"></a>

```
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape                
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format                              
              kFollowing,                                  // placement                
              ge::DT_FLOAT16,                              //dt                
              nullptr};
auto shape_size = tensor.GetShapeSize(); // 16*3*224*224
```

