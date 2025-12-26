# GetInputShape<a name="ZH-CN_TOPIC_0000002494507365"></a>

## 函数功能<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

获取算子输入张量的实际存储形状。

## 函数原型<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

```
const gert::StorageShape* GetInputShape(int64_t index) const
```

## 参数说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section75395119104"></a>

<a name="table305mcpsimp"></a>
<table><thead align="left"><tr id="row311mcpsimp"><th class="cellrowborder" valign="top" width="19%" id="mcps1.1.4.1.1"><p id="p313mcpsimp"><a name="p313mcpsimp"></a><a name="p313mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="30%" id="mcps1.1.4.1.2"><p id="p315mcpsimp"><a name="p315mcpsimp"></a><a name="p315mcpsimp"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="51%" id="mcps1.1.4.1.3"><p id="p317mcpsimp"><a name="p317mcpsimp"></a><a name="p317mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row319mcpsimp"><td class="cellrowborder" valign="top" width="19%" headers="mcps1.1.4.1.1 "><p id="p321mcpsimp"><a name="p321mcpsimp"></a><a name="p321mcpsimp"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.4.1.2 "><p id="p323mcpsimp"><a name="p323mcpsimp"></a><a name="p323mcpsimp"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="51%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p2684123934216"></a>算子输入索引。</p>
<p id="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"></a><a name="zh-cn_topic_0000001576727153_zh-cn_topic_0000001389787297_p109721059143918"></a>这里的输入索引是指算子实例化后实际的索引，不是原型定义中的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

返回[StorageShape](StorageShape.md)结构体，表示该输入张量的存储形状。

## 约束说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section19165124931511"></a>

使用时必须确保：不要对返回的StorageShape做修改，也不要试图释放它。

## 调用示例<a name="zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section320753512363"></a>

```
gert::StorageShape* GetInputShape(OpCheckContext* context) {
  int64_t index = 9;
  gert::StorageShape* shape = context->GetInputShape(index);
  ...
}
```

