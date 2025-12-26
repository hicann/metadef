# IsExpandIndex<a name="ZH-CN_TOPIC_0000002078447889"></a>

## 函数功能<a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_section36583473819"></a>

基于补维后的shape，判断指定的index轴是否为补维轴。

## 函数原型<a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_section13230182415108"></a>

```
bool IsExpandIndex(const AxisIndex index) const
```

## 参数说明<a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_section75395119104"></a>

<a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_row6223476444"><th class="cellrowborder" valign="top" width="19.29%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p10223674448"><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p10223674448"></a><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p645511218169"><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p645511218169"></a><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p1922337124411"><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p1922337124411"></a><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_row152234713443"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p42071411143112"><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p42071411143112"></a><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p42071411143112"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p191819441211"><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p191819441211"></a><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p192211258192913"><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p192211258192913"></a><a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_p192211258192913"></a>指定轴的索引。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_section25791320141317"></a>

-   true代表指定的轴为补维轴。
-   false代表指定的轴为原始轴。

## 约束说明<a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585264988_zh-cn_topic_0000001339745760_section320753512363"></a>

```
ExpandDimsType type1("1001");
bool is_expand_index0 = type1.IsExpandIndex(0); // true
bool is_expand_index1 = type1.IsExpandIndex(1); // false
```

