# SetSize<a name="ZH-CN_TOPIC_0000002078486321"></a>

## 函数功能<a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_section36583473819"></a>

设置tensor数据的内存大小。

## 函数原型<a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_section13230182415108"></a>

```
void SetSize(const size_t size)
```

## 参数说明<a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_section75395119104"></a>

<a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p10223674448"><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p10223674448"></a><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p645511218169"><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p645511218169"></a><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p1922337124411"><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p1922337124411"></a><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p2340183613156"><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p2340183613156"></a><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p2340183613156"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p88767238815"><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p88767238815"></a><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p88767238815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p123391362158"><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p123391362158"></a><a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_p123391362158"></a>tensor的内存大小，单位为字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635052317_zh-cn_topic_0000001390069001_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
td.SetSize(10U);
```

