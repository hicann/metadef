# SetTilingKey<a name="ZH-CN_TOPIC_0000002042526802"></a>

## 函数功能<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section36583473819"></a>

设置TilingKey。

不同的kernel实现分支可以通过TilingKey来标识，host侧设置TilingKey后，可以选择对应的分支。例如，一个算子在不同的shape下，有不同的算法逻辑，kernel侧可以通过TilingKey来选择不同的算法逻辑，在host侧Tiling算法也有差异，host/kernel侧通过相同的TilingKey进行关联。

## 函数原型<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section13230182415108"></a>

**ge::graphStatus SetTilingKey\(const uint64\_t tiling\_key\)**

## 参数说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section75395119104"></a>

<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p10223674448"><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p10223674448"></a><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p645511218169"><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p645511218169"></a><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p1922337124411"><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p1922337124411"></a><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p2340183613156"><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p2340183613156"></a><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p2340183613156"></a>tiling_key</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p143401361158"><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p143401361158"></a><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p19544204917121"><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p19544204917121"></a><a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_p19544204917121"></a>需要设置的tiling key。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section25791320141317"></a>

成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section19165124931511"></a>

tiling\_key的取值范围在uint64\_t数据类型范围内，但不可以取值为UINT64\_MAX。

## 调用示例<a name="zh-cn_topic_0000001526206878_zh-cn_topic_0000001389707209_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetTilingKey(20);
  // ...
}
```

