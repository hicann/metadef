# GetExecuteMode<a name="ZH-CN_TOPIC_0000002479355293"></a>

## 函数功能<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section36583473819"></a>

返回当前算子运行的执行模式。

## 函数原型<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section13230182415108"></a>

```
ExecuteMode GetExecuteMode() const
```

## 参数说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section75395119104"></a>

无

## 返回值说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section25791320141317"></a>

返回ExecuteMode枚举值，表示当前算子的运行模式。

```
enum class ExecuteMode {
  kStaticOffloadExecute, // 静态图模式执行
  kDynamicExecute, //动态图模式执行
  kEnd  //end
};
```

## 约束说明<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_section320753512363"></a>

```
ExecuteMode  GetExecuteMode(ExeResGenerationContext *context) {
  ExecuteMode mode = *context->GetExecuteMode();
  ...
}
```

