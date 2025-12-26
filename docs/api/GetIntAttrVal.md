# GetIntAttrVal<a name="ZH-CN_TOPIC_0000002446115286"></a>

## 函数功能<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section36583473819"></a>

获取算子整数类型的属性值。

## 函数原型<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section13230182415108"></a>

```
bool GetIntAttrVal(const char *attr_name, int64_t &val) const
```

## 参数说明<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section75395119104"></a>

<a name="table720mcpsimp"></a>
<table><thead align="left"><tr id="row726mcpsimp"><th class="cellrowborder" valign="top" width="24.75%" id="mcps1.1.4.1.1"><p id="p728mcpsimp"><a name="p728mcpsimp"></a><a name="p728mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="24.75%" id="mcps1.1.4.1.2"><p id="p730mcpsimp"><a name="p730mcpsimp"></a><a name="p730mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="50.5%" id="mcps1.1.4.1.3"><p id="p732mcpsimp"><a name="p732mcpsimp"></a><a name="p732mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row734mcpsimp"><td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.1 "><p id="p736mcpsimp"><a name="p736mcpsimp"></a><a name="p736mcpsimp"></a>attr_name</p>
</td>
<td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.2 "><p id="p738mcpsimp"><a name="p738mcpsimp"></a><a name="p738mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="50.5%" headers="mcps1.1.4.1.3 "><p id="p740mcpsimp"><a name="p740mcpsimp"></a><a name="p740mcpsimp"></a>属性名。</p>
</td>
</tr>
<tr id="row741mcpsimp"><td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.1 "><p id="p743mcpsimp"><a name="p743mcpsimp"></a><a name="p743mcpsimp"></a>val</p>
</td>
<td class="cellrowborder" valign="top" width="24.75%" headers="mcps1.1.4.1.2 "><p id="p745mcpsimp"><a name="p745mcpsimp"></a><a name="p745mcpsimp"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="50.5%" headers="mcps1.1.4.1.3 "><p id="p747mcpsimp"><a name="p747mcpsimp"></a><a name="p747mcpsimp"></a>接收获取到的整数值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section25791320141317"></a>

表示是否成功获取到该属性。

## 约束说明<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section320753512363"></a>

```
bool GetIntAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  int64_t val; 
  auto result = context->GetStrAttrVal(attr_name.c_str(),val);
  // ...
}
```

