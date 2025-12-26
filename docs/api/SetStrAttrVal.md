# SetStrAttrVal<a name="ZH-CN_TOPIC_0000002479435085"></a>

## 函数功能<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section36583473819"></a>

设置一个字符串类型的属性值到算子中。

## 函数原型<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section13230182415108"></a>

```
bool SetStrAttrVal(const char *attr_name, const char *val) const
```

## 参数说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section75395119104"></a>

<a name="table542mcpsimp"></a>
<table><thead align="left"><tr id="row548mcpsimp"><th class="cellrowborder" valign="top" width="27%" id="mcps1.1.4.1.1"><p id="p550mcpsimp"><a name="p550mcpsimp"></a><a name="p550mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.1.4.1.2"><p id="p552mcpsimp"><a name="p552mcpsimp"></a><a name="p552mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="46%" id="mcps1.1.4.1.3"><p id="p554mcpsimp"><a name="p554mcpsimp"></a><a name="p554mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row556mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p558mcpsimp"><a name="p558mcpsimp"></a><a name="p558mcpsimp"></a>attr_name</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.2 "><p id="p560mcpsimp"><a name="p560mcpsimp"></a><a name="p560mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.4.1.3 "><p id="p562mcpsimp"><a name="p562mcpsimp"></a><a name="p562mcpsimp"></a>属性名。</p>
</td>
</tr>
<tr id="row563mcpsimp"><td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.1 "><p id="p565mcpsimp"><a name="p565mcpsimp"></a><a name="p565mcpsimp"></a>val</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.1.4.1.2 "><p id="p567mcpsimp"><a name="p567mcpsimp"></a><a name="p567mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="46%" headers="mcps1.1.4.1.3 "><p id="p569mcpsimp"><a name="p569mcpsimp"></a><a name="p569mcpsimp"></a>要设置的字符串。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section25791320141317"></a>

表示是否成功设置该属性值。

## 约束说明<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001576806833_zh-cn_topic_0000001339187724_section320753512363"></a>

```
bool SetStrAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  std::string val = ""; 
  bool result = context->SetStrAttrVal(attr_name.c_str(),val.c_str());
  // ...
}
```

