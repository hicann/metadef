# ShareFrom<a name="ZH-CN_TOPIC_0000002042526950"></a>

## 函数功能<a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section36583473819"></a>

使当前的TensorData对象共享另一个对象的内存以及内存管理函数。

## 函数原型<a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section13230182415108"></a>

```
ge::graphStatus ShareFrom(const TensorData &other)
```

## 参数说明<a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section75395119104"></a>

<a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p10223674448"><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p10223674448"></a><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p645511218169"><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p645511218169"></a><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1922337124411"><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1922337124411"></a><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p64117574812"><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p64117574812"></a><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p64117574812"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p13411757887"><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p13411757887"></a><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p13411757887"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1789018032820"><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1789018032820"></a><a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1789018032820"></a>另一个TensorData对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section25791320141317"></a>

成功时返回ge::GRAPH\_SUCCESS。

## 约束说明<a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td1(addr, HostAddrManager, 100U, kOnHost);
TensorData td2(addr, nullptr);
td2.ShareFrom(td1);
```

