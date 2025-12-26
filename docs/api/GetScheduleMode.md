# GetScheduleMode<a name="ZH-CN_TOPIC_0000002078447601"></a>

## 函数功能<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section36583473819"></a>

获取算子在NPU上执行时的调度模式。

## 函数原型<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section13230182415108"></a>

**uint32\_t** **GetScheduleMode\(\) const**

## 参数说明<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section25791320141317"></a>

返回schedule\_mode。

-   0：普通模式，默认情况下为普通模式。
-   1：batchmode模式，仅在模型执行场景且模型中存在核间同步算子时需要设置该模式。该模式不支持直接或者间接通过单算子API执行的方式进行算子调用的场景 。

## 约束说明<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section320753512363"></a>

```
ge::graphStatus TilingForAdd(TilingContext *context) {
  auto schedule_mode = context->GetScheduleMode(); 
  ...
}
```

