# Append<a name="ZH-CN_TOPIC_0000002078447613"></a>

## 函数功能<a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_section36583473819"></a>

向后添加tiling data，若添加超过可容纳的最大长度，则添加失败。

## 函数原型<a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_section13230182415108"></a>

**template<typename T, typename std::enable\_if<std::is\_standard\_layout<T\>::value, int\>::type = 0\>  ge::graphStatus Append\(const T &data\)**

**template<typename T, typename std::enable\_if<std::is\_standard\_layout<T\>::value, int\>::type = 0\>  ge::graphStatus Append\(const T \*data, size\_t append\_num\)**

## 参数说明<a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_section75395119104"></a>

<a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p10223674448"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p10223674448"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p645511218169"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p645511218169"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1922337124411"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1922337124411"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p2340183613156"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p2340183613156"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p2340183613156"></a><strong id="zh-cn_topic_0000001576486705_b1793885719192"><a name="zh-cn_topic_0000001576486705_b1793885719192"></a><a name="zh-cn_topic_0000001576486705_b1793885719192"></a>T</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p88767238815"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p88767238815"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p88767238815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p123391362158"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p123391362158"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p123391362158"></a>添加的tiling data的类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_row55408581278"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p115322371820"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p115322371820"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p115322371820"></a><strong id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_b0153423131817"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_b0153423131817"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_b0153423131817"></a>data</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1154185811713"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1154185811713"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1154185811713"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><a name="zh-cn_topic_0000001576486705_ul636114518247"></a><a name="zh-cn_topic_0000001576486705_ul636114518247"></a><ul id="zh-cn_topic_0000001576486705_ul636114518247"><li>引用类型：添加的tiling data实例。</li><li>指针类型：添加的tiling data起始地址。</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_row1941483012188"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1141418302189"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1141418302189"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1141418302189"></a><strong id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_b4160140161812"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_b4160140161812"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_b4160140161812"></a>append_num</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1141414307181"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1141414307181"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1141414307181"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1841410306183"><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1841410306183"></a><a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_p1841410306183"></a>添加的tiling data的个数，共添加append_num个T类型的tiling data。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_section25791320141317"></a>

-   成功返回ge::GRAPH\_SUCCESS。
-   失败返回ge::GRAPH\_FAILED。

## 约束说明<a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_section19165124931511"></a>

添加的tiling data必须为符合standard\_layout，即内存平铺。

## 调用示例<a name="zh-cn_topic_0000001576486705_zh-cn_topic_0000001339373454_section320753512363"></a>

```
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());

// 1
struct AppendData{
  int a = 10;
  int b = 100;
};
AppendData ad;
auto ret = td->Append<AppendData>(ad); // ge::GRAPH_SUCCESS

// 2
size_t append_num = 10;
int32_t *td = new int32_t[append_num];
auto ret = td->Append<int32_t>(td, append_num); // ge::GRAPH_SUCCESS

// 3
size_t append_num = 50;
int32_t *td = new int32_t[append_num];
auto ret = td->Append<int32_t>(td, append_num); // ge::GRAPH_FAILED
```

