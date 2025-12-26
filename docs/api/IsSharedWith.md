# IsSharedWith<a name="ZH-CN_TOPIC_0000002078447729"></a>

## 函数功能<a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_section36583473819"></a>

判断当前TensorData对象与另一个对象是否共享一块内存以及使用同一个内存管理函数。

## 函数原型<a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_section13230182415108"></a>

```
bool IsSharedWith(const TensorData &other) const
```

## 参数说明<a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_section75395119104"></a>

<a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p10223674448"><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p10223674448"></a><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p645511218169"><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p645511218169"></a><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p1922337124411"><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p1922337124411"></a><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p2340183613156"><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p2340183613156"></a><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p2340183613156"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p143401361158"><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p143401361158"></a><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p16535180192410"><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p16535180192410"></a><a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_p16535180192410"></a>另一个TensorData对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_section25791320141317"></a>

true代表两个对象共享一块内存以及使用同一个内存管理函数，false反之。

## 约束说明<a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001593014936_zh-cn_topic_0000001339229478_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td1(addr, HostAddrManager, 100U, kOnHost);
TensorData td2(addr, HostAddrManager, 100U, kOnHost);
bool is_shared_td = td1.IsSharedWith(td2); // true
```

