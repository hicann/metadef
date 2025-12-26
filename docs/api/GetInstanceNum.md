# GetInstanceNum<a name="ZH-CN_TOPIC_0000002043377406"></a>

## 函数功能<a name="zh-cn_topic_0000001586514686_zh-cn_topic_0000001340202598_section36583473819"></a>

获取IR原型定义某个输入对应的实际输入个数。

## 函数原型<a name="zh-cn_topic_0000001586514686_zh-cn_topic_0000001340202598_section13230182415108"></a>

```
size_t GetInstanceNum() const
```

## 参数说明<a name="zh-cn_topic_0000001586514686_zh-cn_topic_0000001340202598_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001586514686_zh-cn_topic_0000001340202598_section25791320141317"></a>

IR原型定义某个输入对应的实际输入个数。

## 约束说明<a name="zh-cn_topic_0000001586514686_zh-cn_topic_0000001340202598_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586514686_zh-cn_topic_0000001340202598_section320753512363"></a>

```
AnchorInstanceInfo anchor_0(0, 10); //IR原型定义的第一个输入是动态输入，且有10个实际输入
auto input_num_0 = anchor_0.GetInstanceNum(); // input_num_0 = 10
```

