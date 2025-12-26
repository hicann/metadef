# GetTilingData<a name="ZH-CN_TOPIC_0000002042526810"></a>

## 函数功能<a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_section36583473819"></a>

获取有类型的tiling data指针。

## 函数原型<a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_section13230182415108"></a>

**template<typename T\> auto GetTilingData\(\) -\> T\***

## 参数说明<a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_section75395119104"></a>

<a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_row6223476444"><th class="cellrowborder" valign="top" width="20.34%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p10223674448"><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p10223674448"></a><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="79.66%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p1922337124411"><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p1922337124411"></a><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_row152234713443"><td class="cellrowborder" valign="top" width="20.34%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p2340183613156"><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p2340183613156"></a><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p2340183613156"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="79.66%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p18391222141819"><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p18391222141819"></a><a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_p18391222141819"></a>tiling data类型，sizeof(T)不可以大于编译结果中指定的最大tiling data长度。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_section25791320141317"></a>

tiling data指针，失败时返回空指针。

## 约束说明<a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_section19165124931511"></a>

sizeof\(T\)不可以大于编译结果中指定的最大tiling data长度。

## 调用示例<a name="zh-cn_topic_0000001526206882_zh-cn_topic_0000001389790369_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_data = context->GetTilingData<int64_t>();
  // ...
}
```

