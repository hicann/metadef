# GetPlatformInfo

## 函数功能

获取PlatFormInfos指针。PlatformInfos类用于管理和查询硬件平台的相关信息，包括核数、内存带宽等。

## 函数原型

```cpp
fe::PlatFormInfos *GetPlatformInfo() const
```

## 参数说明

无。

## 返回值说明

返回内部硬件平台信息的指针，供PlatformAscendC获取硬件平台信息；若无法获取计算节点信息、对应输入，或该输入中保存的平台信息指针为空，则返回nullptr。

PlatformAscendC接口详细说明请参见《[Ascend C API](https://gitcode.com/cann/asc-devkit/blob/9.3.0/docs/zh/api/README.md)》。

## 约束说明

无。

## 调用示例

```cpp
ge::graphStatus TilingXXX(gert::TilingContext* context) {
    auto platformInfo = context->GetPlatformInfo();
    if (platformInfo == nullptr) {
        return ge::GRAPH_FAILED;
    }
    auto ascendcPlatform = platform_ascendc::PlatformAscendC(platformInfo);
    auto coreNum = ascendcPlatform.GetCoreNum();
    // ... 根据核数自行设计Tiling策略
    context->SetBlockDim(coreNum);
    return ret;
}
```
