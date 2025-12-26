# SetSyncResInfos<a name="ZH-CN_TOPIC_0000002446115278"></a>

## 函数功能<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section36583473819"></a>

将传入的同步资源信息列表（sync\_info\_vec）设置到当前对象中，用于配置图执行时的同步资源行为。

## 函数原型<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section13230182415108"></a>

```
ge::graphStatus SetSyncResInfos(std::vector<SyncResInfo> &sync_info_vec) const
```

## 参数说明<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section75395119104"></a>

<a name="table102mcpsimp"></a>
<table><thead align="left"><tr id="row108mcpsimp"><th class="cellrowborder" valign="top" width="33%" id="mcps1.1.4.1.1"><p id="p110mcpsimp"><a name="p110mcpsimp"></a><a name="p110mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.2"><p id="p112mcpsimp"><a name="p112mcpsimp"></a><a name="p112mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="44%" id="mcps1.1.4.1.3"><p id="p114mcpsimp"><a name="p114mcpsimp"></a><a name="p114mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row116mcpsimp"><td class="cellrowborder" valign="top" width="33%" headers="mcps1.1.4.1.1 "><p id="p118mcpsimp"><a name="p118mcpsimp"></a><a name="p118mcpsimp"></a>sync_info_vec</p>
</td>
<td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.2 "><p id="p120mcpsimp"><a name="p120mcpsimp"></a><a name="p120mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="44%" headers="mcps1.1.4.1.3 "><p id="p122mcpsimp"><a name="p122mcpsimp"></a><a name="p122mcpsimp"></a>同步资源信息列表。std::vector&lt;<a href="SyncResInfo.md">SyncResInfo</a>&gt;类型。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section25791320141317"></a>

返回[graphStatus](ge-graphStatus.md)状态码。

## 约束说明<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001991395366_zh-cn_topic_0000001339507276_section320753512363"></a>

```
ge::graphStatus SetSyncResInfos(ExeResGenerationContext* context) {
  std::vector<SyncResInfo> sync_info_vec;
  ge::graphStatus status= context->SetSyncResInfos(sync_info_vec);
  ...
}
```

