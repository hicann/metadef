# InferOutDataTypeSameWithFirstInput<a name="ZH-CN_TOPIC_0000002042527146"></a>

## 函数功能<a name="zh-cn_topic_0000002035545058_zh-cn_topic_0000001346709604_section36583473819"></a>

注册一种datatype推导规则，该规则将算子第一个输入的datatype作为所有输出的datatype。

## 函数原型<a name="zh-cn_topic_0000002035545058_zh-cn_topic_0000001346709604_section13230182415108"></a>

```
OpImplRegisterV2 &InferOutDataTypeSameWithFirstInput()
```

## 参数说明<a name="zh-cn_topic_0000002035545058_zh-cn_topic_0000001346709604_section181917342085"></a>

无

## 返回值说明<a name="zh-cn_topic_0000002035545058_zh-cn_topic_0000001346709604_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了算子datatype推导规则。

## 约束说明<a name="zh-cn_topic_0000002035545058_zh-cn_topic_0000001346709604_section19165124931511"></a>

-   注册此规则，可以不用再注册自定义推导规则。若同时注册了InferDataType和InferOutDataTypeByFirstInput，将使能最后注册的规则。
-   若算子无输入或第一个输入datatype为未定义（DT\_UNDEFINED），推导将报错。

