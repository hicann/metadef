# SetWorkspaceBytes<a name="ZH-CN_TOPIC_0000002479435081"></a>

## 函数功能<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section36583473819"></a>

设置Workspace大小。

## 函数原型<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section13230182415108"></a>

```
void SetWorkspaceBytes(const std::vector<int64_t> &workspace_bytes) const
```

## 参数说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section75395119104"></a>

<a name="table608mcpsimp"></a>
<table><thead align="left"><tr id="row614mcpsimp"><th class="cellrowborder" valign="top" width="32%" id="mcps1.1.4.1.1"><p id="p616mcpsimp"><a name="p616mcpsimp"></a><a name="p616mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.4.1.2"><p id="p618mcpsimp"><a name="p618mcpsimp"></a><a name="p618mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="48%" id="mcps1.1.4.1.3"><p id="p620mcpsimp"><a name="p620mcpsimp"></a><a name="p620mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row622mcpsimp"><td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.1 "><p id="p624mcpsimp"><a name="p624mcpsimp"></a><a name="p624mcpsimp"></a>workspace_bytes</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p id="p626mcpsimp"><a name="p626mcpsimp"></a><a name="p626mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48%" headers="mcps1.1.4.1.3 "><p id="p628mcpsimp"><a name="p628mcpsimp"></a><a name="p628mcpsimp"></a>Workspace大小配置信息。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section25791320141317"></a>

无

## 约束说明<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001526046958_zh-cn_topic_0000001339347388_section320753512363"></a>

```
void SetWorkspaceBytes(ExeResGenerationContext* context) {
  std::vector<int64_t> workspace_bytes;
  context->SetWorkspaceBytes(workspace_bytes);
  // ...
}
```

