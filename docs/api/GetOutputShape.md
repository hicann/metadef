# GetOutputShape<a name="ZH-CN_TOPIC_0000002446115274"></a>

## 函数功能<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

获取算子输出张量的实际存储形状。

## 函数原型<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

```
const gert::StorageShape* GetOutputShape(int64_t index) const
```

## 参数说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section75395119104"></a>

<a name="table520mcpsimp"></a>
<table><thead align="left"><tr id="row526mcpsimp"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="p528mcpsimp"><a name="p528mcpsimp"></a><a name="p528mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.1.4.1.2"><p id="p530mcpsimp"><a name="p530mcpsimp"></a><a name="p530mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="51%" id="mcps1.1.4.1.3"><p id="p532mcpsimp"><a name="p532mcpsimp"></a><a name="p532mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row534mcpsimp"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="p536mcpsimp"><a name="p536mcpsimp"></a><a name="p536mcpsimp"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.2 "><p id="p538mcpsimp"><a name="p538mcpsimp"></a><a name="p538mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a>算子输出索引。</p>
<p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"></a>这里的输出索引是指算子实例化后实际的索引，不是原型定义中的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

返回StorageShape结构体，表示该输出Shape的存储形状。

## 约束说明<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section19165124931511"></a>

使用时必须确保：不要对返回的StorageShape做修改，也不要试图释放它。

## 调用示例<a name="zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section320753512363"></a>

```
gert::StorageShape* GetOutputShape(ExeResGenerationContext* context) {
  int64_t index = 9;
  gert::StorageShape* shape = context->GetInputShape(index);
  ...
}
```

