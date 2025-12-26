# GetPlatformInfo<a name="ZH-CN_TOPIC_0000002042526814"></a>

## 函数功能<a name="zh-cn_topic_0000001651968517_zh-cn_topic_0000001599804342_section36583473819"></a>

获取PlatFormInfos指针。PlatformInfos类用于管理和查询硬件平台的相关信息，包括核数、内存带宽等。

## 函数原型<a name="zh-cn_topic_0000001651968517_zh-cn_topic_0000001599804342_section13230182415108"></a>

**fe::PlatFormInfos \*GetPlatformInfo\(\) const**

## 参数说明<a name="zh-cn_topic_0000001651968517_zh-cn_topic_0000001599804342_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001651968517_zh-cn_topic_0000001599804342_section25791320141317"></a>

PlatformInfos指针承载的是内部的硬件平台信息，这个信息作为PlatformAscendC的输入，开发者通过PlatformAscendC提供的方法获取硬件平台信息。

## 约束说明<a name="zh-cn_topic_0000001651968517_zh-cn_topic_0000001599804342_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001651968517_zh-cn_topic_0000001599804342_section320753512363"></a>

```
ge::graphStatus TilingXXX(gert::TilingContext* context) {
    auto ascendcPlatform = platform_ascendc::PlatformAscendC(context->GetPlatformInfo());
    auto coreNum = ascendcPlatform.GetCoreNum();
    // ... 根据核数自行设计Tiling策略
    context->SetBlockDim(coreNum);
    return ret;
}
```

