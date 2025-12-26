# GetMax<a name="ZH-CN_TOPIC_0000002078486421"></a>

## 函数功能<a name="zh-cn_topic_0000001602606402_zh-cn_topic_0000001596870872_section36583473819"></a>

获取最大的T对象指针。

## 函数原型<a name="zh-cn_topic_0000001602606402_zh-cn_topic_0000001596870872_section13230182415108"></a>

```
const T *GetMax() const
T *GetMax()
```

## 参数说明<a name="zh-cn_topic_0000001602606402_zh-cn_topic_0000001596870872_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001602606402_zh-cn_topic_0000001596870872_section25791320141317"></a>

返回最大的T对象指针。

## 约束说明<a name="zh-cn_topic_0000001602606402_zh-cn_topic_0000001596870872_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001602606402_zh-cn_topic_0000001596870872_section320753512363"></a>

```
int min = -1;
int max = 1024;
Range<int> range(&min, &max);

auto ret = range.GetMax(); // ret指针指向max
```

