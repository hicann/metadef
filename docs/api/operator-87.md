# operator=<a name="ZH-CN_TOPIC_0000002078447721"></a>

## 函数功能<a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_section36583473819"></a>

禁用拷贝赋值函数。

使用移动赋值函数。

## 函数原型<a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_section13230182415108"></a>

```
TensorData& operator= (const TensorData &other)=delete
TensorData& operator= (TensorData &&other) noexcept
```

## 参数说明<a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_section75395119104"></a>

<a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p10223674448"><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p10223674448"></a><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p645511218169"><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p645511218169"></a><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p1922337124411"><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p1922337124411"></a><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p11366855144212"><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p11366855144212"></a><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p11366855144212"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p193659558424"><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p193659558424"></a><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p193659558424"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p1436416554428"><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p1436416554428"></a><a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_p1436416554428"></a>另一个TensorData对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_section25791320141317"></a>

返回一个持有other对象资源的新TensorData对象。

## 约束说明<a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001635411641_zh-cn_topic_0000001339229474_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
TensorData new_td = td;
```

