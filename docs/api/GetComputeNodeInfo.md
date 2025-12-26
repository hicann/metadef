# GetComputeNodeInfo<a name="ZH-CN_TOPIC_0000002042368630"></a>

## 函数功能<a name="zh-cn_topic_0000001636247401_zh-cn_topic_0000001339105492_section36583473819"></a>

获取本Kernel对应的计算节点的信息。

图执行时本质上是执行图上的一个个节点的Kernel在执行。本方法能够从KernelContext中获取保存的ComputeNodeInfo，而ComputeNodeInfo中包含InputDesc等信息。

## 函数原型<a name="zh-cn_topic_0000001636247401_zh-cn_topic_0000001339105492_section13230182415108"></a>

```
const ComputeNodeInfo *GetComputeNodeInfo() const
```

## 参数说明<a name="zh-cn_topic_0000001636247401_zh-cn_topic_0000001339105492_section75395119104"></a>

无。

## 返回值说明<a name="zh-cn_topic_0000001636247401_zh-cn_topic_0000001339105492_section25791320141317"></a>

计算节点的信息。

关于ComputeNodeInfo的定义，请参见[ComputeNodeInfo](ComputeNodeInfo.md)。

## 约束说明<a name="zh-cn_topic_0000001636247401_zh-cn_topic_0000001339105492_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001636247401_zh-cn_topic_0000001339105492_section320753512363"></a>

```
// 假设已存在KernelContext *context
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto compute_node_info = extend_context->GetComputeNodeInfo();
```

