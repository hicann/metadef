# GetStrAttrVal<a name="ZH-CN_TOPIC_0000002445955434"></a>

## 函数功能<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section36583473819"></a>

获取算子的字符串类型的属性值。

## 函数原型<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section13230182415108"></a>

```
bool GetStrAttrVal(const char *attr_name, ge::AscendString &val) const
```

## 参数说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section75395119104"></a>

<a name="table434mcpsimp"></a>
<table><thead align="left"><tr id="row440mcpsimp"><th class="cellrowborder" valign="top" width="23.23%" id="mcps1.1.4.1.1"><p id="p442mcpsimp"><a name="p442mcpsimp"></a><a name="p442mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="23.23%" id="mcps1.1.4.1.2"><p id="p444mcpsimp"><a name="p444mcpsimp"></a><a name="p444mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="53.54%" id="mcps1.1.4.1.3"><p id="p446mcpsimp"><a name="p446mcpsimp"></a><a name="p446mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row448mcpsimp"><td class="cellrowborder" valign="top" width="23.23%" headers="mcps1.1.4.1.1 "><p id="p450mcpsimp"><a name="p450mcpsimp"></a><a name="p450mcpsimp"></a>attr_name</p>
</td>
<td class="cellrowborder" valign="top" width="23.23%" headers="mcps1.1.4.1.2 "><p id="p452mcpsimp"><a name="p452mcpsimp"></a><a name="p452mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="53.54%" headers="mcps1.1.4.1.3 "><p id="p454mcpsimp"><a name="p454mcpsimp"></a><a name="p454mcpsimp"></a>属性名。</p>
</td>
</tr>
<tr id="row455mcpsimp"><td class="cellrowborder" valign="top" width="23.23%" headers="mcps1.1.4.1.1 "><p id="p457mcpsimp"><a name="p457mcpsimp"></a><a name="p457mcpsimp"></a>val</p>
</td>
<td class="cellrowborder" valign="top" width="23.23%" headers="mcps1.1.4.1.2 "><p id="p459mcpsimp"><a name="p459mcpsimp"></a><a name="p459mcpsimp"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="53.54%" headers="mcps1.1.4.1.3 "><p id="p461mcpsimp"><a name="p461mcpsimp"></a><a name="p461mcpsimp"></a>接收获取到的字符串值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section25791320141317"></a>

表示是否成功获取到该属性。

## 约束说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section320753512363"></a>

```
bool GetStrAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  ge::AscendString val; 
  auto result = context->GetStrAttrVal(attr_name.c_str(),val);
  // ...
}
```

