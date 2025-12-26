# GetInputsNum<a name="ZH-CN_TOPIC_0000002042368774"></a>

## 函数功能<a name="zh-cn_topic_0000001585807530_zh-cn_topic_0000001339887282_section36583473819"></a>

获取算子在网络中的实际输入个数。

## 函数原型<a name="zh-cn_topic_0000001585807530_zh-cn_topic_0000001339887282_section13230182415108"></a>

```
size_t GetInputsNum() const
```

## 参数说明<a name="zh-cn_topic_0000001585807530_zh-cn_topic_0000001339887282_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001585807530_zh-cn_topic_0000001339887282_section25791320141317"></a>

算子的实际输入个数。

## 约束说明<a name="zh-cn_topic_0000001585807530_zh-cn_topic_0000001339887282_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585807530_zh-cn_topic_0000001339887282_section320753512363"></a>

```
size_t index = compute_node_info->GetInputsNum();
```

