# SetTilingCond<a name="ZH-CN_TOPIC_0000002042526806"></a>

## 函数功能<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section36583473819"></a>

设置tiling cond。tiling cond是一个整型值，用于选择算子实际使用的Tiling实现。

## 函数原型<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section13230182415108"></a>

**ge::graphStatus SetTilingCond\(int32\_t tiling\_cond\)**

## 参数说明<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section75395119104"></a>

<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p10223674448"><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p10223674448"></a><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p645511218169"><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p645511218169"></a><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p1922337124411"><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p1922337124411"></a><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p2340183613156"><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p2340183613156"></a><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p2340183613156"></a>tiling_cond</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p143401361158"><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p143401361158"></a><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p123391362158"><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p123391362158"></a><a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_p123391362158"></a>需要设置的tiling cond。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001590522890_zh-cn_topic_0000001389867693_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetTilingCond(10);
  // ...
}
```

