# GetInstanceStart<a name="ZH-CN_TOPIC_0000002079495021"></a>

## 函数功能<a name="zh-cn_topic_0000001586674626_zh-cn_topic_0000001340362562_section36583473819"></a>

获取算子某个IR输入在实际输入中的起始序号（index）。

## 函数原型<a name="zh-cn_topic_0000001586674626_zh-cn_topic_0000001340362562_section13230182415108"></a>

```
size_t GetInstanceStart() const
```

## 参数说明<a name="zh-cn_topic_0000001586674626_zh-cn_topic_0000001340362562_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001586674626_zh-cn_topic_0000001340362562_section25791320141317"></a>

算子某个IR输入在实际输入中的起始序号（index）。

## 约束说明<a name="zh-cn_topic_0000001586674626_zh-cn_topic_0000001340362562_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586674626_zh-cn_topic_0000001340362562_section320753512363"></a>

```
AnchorInstanceInfo anchor_0(0, 10); //IR原型定义的第1个输入是动态输入，动态输入的实际输入个数为10
AnchorInstanceInfo anchor_1(10, 1); //IR原型定义的第2个输入是必选输入，必选输入的实际输入个数必须为1，该输入排在实际输入的第10个
auto start_of_anchor_1 = anchor_1.GetInstanceStart(); // start_of_anchor_1 = 10
```

