# Release<a name="ZH-CN_TOPIC_0000002457311182"></a>

## 函数功能<a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section36583473819"></a>

释放对TensorAddress的所有权，本接口调用后，本对象不再管理TensorAddress，而且TensorAddress并没有被释放，因此调用者负责通过manager释放TensorAddress。

## 函数原型<a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section13230182415108"></a>

```
tensorAddress Release(TensorAddrManager &manager)
```

## 参数说明<a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section75395119104"></a>

<a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p10223674448"><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p10223674448"></a><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p645511218169"><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p645511218169"></a><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1922337124411"><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1922337124411"></a><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002456570120_p788181854116"><a name="zh-cn_topic_0000002456570120_p788181854116"></a><a name="zh-cn_topic_0000002456570120_p788181854116"></a>manager</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p13411757887"><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p13411757887"></a><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p13411757887"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1789018032820"><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1789018032820"></a><a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_p1789018032820"></a>tensor的管理函数。用于管理返回的TensorAddress的函数，若本对象无所有权，那么manager被设置为nullptr。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section25791320141317"></a>

本对象持有的TensorAddress指针，若本对象不持有任何指针，则返回nullptr。

## 约束说明<a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000002456570120_zh-cn_topic_0000001642575169_zh-cn_topic_0000001339709026_section320753512363"></a>

```
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
TensorAddrManager NewHostAddrManager = nullptr;
TensorAddress ta = td.Release(NewHostAddrManager);
```

