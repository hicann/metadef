# SetPlacement<a name="ZH-CN_TOPIC_0000002042526946"></a>

## 函数功能<a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_section36583473819"></a>

设置tensor的placement。

## 函数原型<a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_section13230182415108"></a>

```
void SetPlacement(const TensorPlacement placement)
```

## 参数说明<a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_section75395119104"></a>

<a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p10223674448"><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p10223674448"></a><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p645511218169"><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p645511218169"></a><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p1922337124411"><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p1922337124411"></a><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p2340183613156"><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p2340183613156"></a><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p2340183613156"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p143401361158"><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p143401361158"></a><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p14151132861"><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p14151132861"></a><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p14151132861"></a>tensor的placement。</p>
<p id="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p165152310619"><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p165152310619"></a><a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_p165152310619"></a>关于TensorPlacement类型的定义，请参见<a href="TensorPlacement.md">TensorPlacement</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001585251798_zh-cn_topic_0000001389909401_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
auto td_place = td.SetPlacement(kOnHost);
```

