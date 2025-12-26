# GetAddr<a name="ZH-CN_TOPIC_0000002042526942"></a>

## 函数功能<a name="zh-cn_topic_0000001584932622_zh-cn_topic_0000001339709022_section36583473819"></a>

获取tensor数据地址。若存在manager函数，则由manager函数给出地址。

## 函数原型<a name="zh-cn_topic_0000001584932622_zh-cn_topic_0000001339709022_section13230182415108"></a>

```
TensorAddress GetAddr() const
```

## 参数说明<a name="zh-cn_topic_0000001584932622_zh-cn_topic_0000001339709022_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001584932622_zh-cn_topic_0000001339709022_section25791320141317"></a>

tensor地址。

## 约束说明<a name="zh-cn_topic_0000001584932622_zh-cn_topic_0000001339709022_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584932622_zh-cn_topic_0000001339709022_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
auto addr = td.GetAddr(); // 0x10
```

