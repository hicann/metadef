# operator<<<a name="ZH-CN_TOPIC_0000002042526834"></a>

## 函数功能<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_section36583473819"></a>

使用<<运算符重载的方式，实现向后添加tiling data的功能。若添加超过可容纳的最大长度，则忽略本次操作。

使用<<添加tiling data，可以实现和[Append](Append.md)相同的功能，使用该运算符更加直观方便。

## 函数原型<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_section13230182415108"></a>

**template<typename T\>**

**TilingData &operator<<\(TilingData &out, const T &data\)**

## 参数说明<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_section75395119104"></a>

<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p10223674448"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p10223674448"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p645511218169"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p645511218169"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1922337124411"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1922337124411"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p2340183613156"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p2340183613156"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p2340183613156"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p143401361158"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p143401361158"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p19544204917121"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p19544204917121"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p19544204917121"></a>添加的tiling data的类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_row125412192439"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p62543195430"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p62543195430"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p62543195430"></a>out</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p4254151964319"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p4254151964319"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p4254151964319"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p125421911434"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p125421911434"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p125421911434"></a>TilingData类实例。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_row65831331194318"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1758333112431"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1758333112431"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1758333112431"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p195832314439"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p195832314439"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p195832314439"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1258373194310"><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1258373194310"></a><a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_p1258373194310"></a>添加的tiling data的实例。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_section25791320141317"></a>

追加完data的TilingData对象。

## 约束说明<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576806845_zh-cn_topic_0000001389733241_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());

struct AppendData{
  int a = 10;
  int b = 100;
};
AppendData ad;
(*td) << ad;
auto data_size = td.GetDataSize(); // 2 * sizeof(int)
```

