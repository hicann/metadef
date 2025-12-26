# GetOutputShape<a name="ZH-CN_TOPIC_0000002078486181"></a>

## 函数功能<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section36583473819"></a>

根据算子输出索引获取对应的输出shape指针。这里的输出索引是指算子实例化后实际的索引，不是原型定义中的索引。

## 函数原型<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section13230182415108"></a>

**const StorageShape \*GetOutputShape\(size\_t index\) const**

## 参数说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section75395119104"></a>

<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p2340183613156"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p93131410493"><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p93131410493"></a><a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_p93131410493"></a>算子输出索引，从0开始计数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section25791320141317"></a>

指定的输出shape指针，index非法时，返回空指针。

关于StorageShape类型的定义，请参见[StorageShape](StorageShape.md)。

## 约束说明<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576486693_zh-cn_topic_0000001390027241_section320753512363"></a>

```
ge::graphStatus Tiling4ConcatD(TilingContext* context) {
  auto out_shape = context->GetOutputShape(0);
  ...
}
```

