# IsConstInput<a name="ZH-CN_TOPIC_0000002445955422"></a>

## 函数功能<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section36583473819"></a>

用于判断某个输入张量是否为常量数据。

## 函数原型<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section13230182415108"></a>

```
bool IsConstInput(const ge::AscendString &name) const
```

## 参数说明<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section75395119104"></a>

<a name="table498mcpsimp"></a>
<table><thead align="left"><tr id="row504mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.1.4.1.1"><p id="p506mcpsimp"><a name="p506mcpsimp"></a><a name="p506mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="31%" id="mcps1.1.4.1.2"><p id="p508mcpsimp"><a name="p508mcpsimp"></a><a name="p508mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="53%" id="mcps1.1.4.1.3"><p id="p510mcpsimp"><a name="p510mcpsimp"></a><a name="p510mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row512mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.4.1.1 "><p id="p514mcpsimp"><a name="p514mcpsimp"></a><a name="p514mcpsimp"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="31%" headers="mcps1.1.4.1.2 "><p id="p516mcpsimp"><a name="p516mcpsimp"></a><a name="p516mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="53%" headers="mcps1.1.4.1.3 "><p id="p518mcpsimp"><a name="p518mcpsimp"></a><a name="p518mcpsimp"></a>输入张量的名称。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section25791320141317"></a>

true表示该输入是常量；false表示是动态输入（如输入数据、中间结果等）。

## 约束说明<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section320753512363"></a>

```
bool IsConstInput(ExeResGenerationContext *context) {
  ge::AscendString name = "XXX";
  bool status = *context->IsConstInput(name);
  ...
}
```

