# GetInputShape<a name="ZH-CN_TOPIC_0000002479435073"></a>

## 函数功能<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section36583473819"></a>

获取算子输入张量的实际存储形状。

## 函数原型<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section13230182415108"></a>

```
const gert::StorageShape* GetInputShape(int64_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section75395119104"></a>

<a name="table142mcpsimp"></a>
<table><thead align="left"><tr id="row148mcpsimp"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="p150mcpsimp"><a name="p150mcpsimp"></a><a name="p150mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.1.4.1.2"><p id="p152mcpsimp"><a name="p152mcpsimp"></a><a name="p152mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="51%" id="mcps1.1.4.1.3"><p id="p154mcpsimp"><a name="p154mcpsimp"></a><a name="p154mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row156mcpsimp"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="p158mcpsimp"><a name="p158mcpsimp"></a><a name="p158mcpsimp"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.2 "><p id="p160mcpsimp"><a name="p160mcpsimp"></a><a name="p160mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a>算子输入索引。</p>
<p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"></a>这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section25791320141317"></a>

返回[StorageShape](StorageShape.md)结构体，表示该输入张量的存储形状。

## 约束说明<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section19165124931511"></a>

使用时必须确保：不要对返回的StorageShape做修改，也不要试图释放它。

## 调用示例<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section320753512363"></a>

```
gert::StorageShape* GetInputShape(ExeResGenerationContext* context) {
  int64_t index = 9;
  gert::StorageShape* shape = context->GetInputShape(index);
  ...
}
```

