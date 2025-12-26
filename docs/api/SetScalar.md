# SetScalar<a name="ZH-CN_TOPIC_0000002042368726"></a>

## 函数功能<a name="zh-cn_topic_0000001583865638_zh-cn_topic_0000001389838197_section36583473819"></a>

设置shape为标量。

## 函数原型<a name="zh-cn_topic_0000001583865638_zh-cn_topic_0000001389838197_section13230182415108"></a>

```
void SetScalar()
```

## 参数说明<a name="zh-cn_topic_0000001583865638_zh-cn_topic_0000001389838197_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001583865638_zh-cn_topic_0000001389838197_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001583865638_zh-cn_topic_0000001389838197_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001583865638_zh-cn_topic_0000001389838197_section320753512363"></a>

```
Shape shape0({3, 256, 256});
shape0.IsScalar(); // false
shape0.SetScalar();
shape0.IsScalar(); // true
```

