# SetIntAttrVal<a name="ZH-CN_TOPIC_0000002479355309"></a>

## 函数功能<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section36583473819"></a>

设置一个整数类型的属性值到算子中。

## 函数原型<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section13230182415108"></a>

```
bool SetIntAttrVal(const char *attr_name, const int64_t val) const
```

## 参数说明<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section75395119104"></a>

<a name="table196mcpsimp"></a>
<table><thead align="left"><tr id="row202mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.4.1.1"><p id="p204mcpsimp"><a name="p204mcpsimp"></a><a name="p204mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.1.4.1.2"><p id="p206mcpsimp"><a name="p206mcpsimp"></a><a name="p206mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="46%" id="mcps1.1.4.1.3"><p id="p208mcpsimp"><a name="p208mcpsimp"></a><a name="p208mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row210mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p212mcpsimp"><a name="p212mcpsimp"></a><a name="p212mcpsimp"></a>attr_name</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.2 "><p id="p214mcpsimp"><a name="p214mcpsimp"></a><a name="p214mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.4.1.3 "><p id="p216mcpsimp"><a name="p216mcpsimp"></a><a name="p216mcpsimp"></a>属性名。</p>
</td>
</tr>
<tr id="row217mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p219mcpsimp"><a name="p219mcpsimp"></a><a name="p219mcpsimp"></a>val</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.2 "><p id="p221mcpsimp"><a name="p221mcpsimp"></a><a name="p221mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.4.1.3 "><p id="p223mcpsimp"><a name="p223mcpsimp"></a><a name="p223mcpsimp"></a>要设置的整数值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section25791320141317"></a>

表示是否成功设置该属性值。

## 约束说明<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001640083137_zh-cn_topic_0000001339507280_section320753512363"></a>

```
bool SetIntAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  int64_t val = 6; 
  auto result = context->SetIntAttrVal(attr_name.c_str(),val);
  // ...
}
```

