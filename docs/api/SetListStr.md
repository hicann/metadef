# SetListStr<a name="ZH-CN_TOPIC_0000002479355305"></a>

## 函数功能<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section36583473819"></a>

设置字符串列表类型的属性值到算子中。

## 函数原型<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section13230182415108"></a>

```
ge::graphStatus SetListStr(const std::string &attr_name, const std::vector<std::string> &list) const
```

## 参数说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section75395119104"></a>

<a name="table691mcpsimp"></a>
<table><thead align="left"><tr id="row697mcpsimp"><th class="cellrowborder" valign="top" width="24.75%" id="mcps1.1.4.1.1"><p id="p699mcpsimp"><a name="p699mcpsimp"></a><a name="p699mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="24.75%" id="mcps1.1.4.1.2"><p id="p701mcpsimp"><a name="p701mcpsimp"></a><a name="p701mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="50.5%" id="mcps1.1.4.1.3"><p id="p703mcpsimp"><a name="p703mcpsimp"></a><a name="p703mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row705mcpsimp"><td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.1 "><p id="p707mcpsimp"><a name="p707mcpsimp"></a><a name="p707mcpsimp"></a>attr_name</p>
</td>
<td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.2 "><p id="p709mcpsimp"><a name="p709mcpsimp"></a><a name="p709mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.5%" headers="mcps1.1.4.1.3 "><p id="p711mcpsimp"><a name="p711mcpsimp"></a><a name="p711mcpsimp"></a>属性名。</p>
</td>
</tr>
<tr id="row712mcpsimp"><td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.1 "><p id="p714mcpsimp"><a name="p714mcpsimp"></a><a name="p714mcpsimp"></a>list</p>
</td>
<td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.2 "><p id="p716mcpsimp"><a name="p716mcpsimp"></a><a name="p716mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.5%" headers="mcps1.1.4.1.3 "><p id="p718mcpsimp"><a name="p718mcpsimp"></a><a name="p718mcpsimp"></a>要设置的字符串列表。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section25791320141317"></a>

返回[graphStatus](ge-graphStatus.md)状态码。

## 约束说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section320753512363"></a>

```
ge::graphStatus SetListStr(ExeResGenerationContext* context) {
  std::string attr_name = "";
  std::vector<std::string> list;  
  ge::graphStatus status = context->SetListStr(attr_name ,list);
  // ...
}
```

