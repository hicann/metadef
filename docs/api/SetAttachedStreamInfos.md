# SetAttachedStreamInfos<a name="ZH-CN_TOPIC_0000002479355297"></a>

## 函数功能<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section36583473819"></a>

为当前算子附着一组Stream信息，用于指定该算子在哪个执行流（Stream）上运行。

## 函数原型<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
ge::graphStatus SetAttachedStreamInfos(std::vector<StreamInfo> &stream_info_vec) const
```

## 参数说明<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section75395119104"></a>

<a name="table411mcpsimp"></a>
<table><thead align="left"><tr id="row417mcpsimp"><th class="cellrowborder" valign="top" width="32.67326732673268%" id="mcps1.1.4.1.1"><p id="p419mcpsimp"><a name="p419mcpsimp"></a><a name="p419mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="20.792079207920793%" id="mcps1.1.4.1.2"><p id="p421mcpsimp"><a name="p421mcpsimp"></a><a name="p421mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="46.53465346534653%" id="mcps1.1.4.1.3"><p id="p423mcpsimp"><a name="p423mcpsimp"></a><a name="p423mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row425mcpsimp"><td class="cellrowborder" valign="top" width="32.67326732673268%" headers="mcps1.1.4.1.1 "><p id="p427mcpsimp"><a name="p427mcpsimp"></a><a name="p427mcpsimp"></a>stream_info_vec</p>
</td>
<td class="cellrowborder" valign="top" width="20.792079207920793%" headers="mcps1.1.4.1.2 "><p id="p429mcpsimp"><a name="p429mcpsimp"></a><a name="p429mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46.53465346534653%" headers="mcps1.1.4.1.3 "><p id="p431mcpsimp"><a name="p431mcpsimp"></a><a name="p431mcpsimp"></a>执行流信息。std::vector&lt;<a href="StreamInfo.md">StreamInfo</a>&gt;类型。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section25791320141317"></a>

返回[graphStatus](ge-graphStatus.md)状态码。

## 约束说明<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000002027834817_zh-cn_topic_0000001339507276_section320753512363"></a>

```
ge::graphStatus SetAttachedStreamInfos(ExeResGenerationContext* context) {
  std::vector<StreamInfo> stream_info_vec;
  auto status = context->SetAttachedStreamInfos(stream_info_vec);
  ...
}
```

