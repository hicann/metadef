# GetMin<a name="ZH-CN_TOPIC_0000002042368738"></a>

## 函数功能<a name="zh-cn_topic_0000001651967085_zh-cn_topic_0000001596868932_section36583473819"></a>

获取最小的T对象指针。

## 函数原型<a name="zh-cn_topic_0000001651967085_zh-cn_topic_0000001596868932_section13230182415108"></a>

```
const T *GetMin() const
T *GetMin()
```

## 参数说明<a name="zh-cn_topic_0000001651967085_zh-cn_topic_0000001596868932_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001651967085_zh-cn_topic_0000001596868932_section25791320141317"></a>

返回最小的T对象指针。

## 约束说明<a name="zh-cn_topic_0000001651967085_zh-cn_topic_0000001596868932_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001651967085_zh-cn_topic_0000001596868932_section320753512363"></a>

```
int min = -1;
int max = 1024;
Range<int> range(&min, &max);

auto ret = range.GetMin(); // ret指针指向min
```

