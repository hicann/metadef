# Init<a name="ZH-CN_TOPIC_0000002078486213"></a>

## 函数功能<a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_section36583473819"></a>

初始化TilingData。

## 函数原型<a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_section13230182415108"></a>

**void Init\(const size\_t cap\_size, void \*const data\)**

## 参数说明<a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_section75395119104"></a>

<a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p10223674448"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p10223674448"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p645511218169"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p645511218169"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p1922337124411"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p1922337124411"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p74416406373"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p74416406373"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p74416406373"></a>cap_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p143401361158"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p143401361158"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p19544204917121"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p19544204917121"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p19544204917121"></a>最大容量。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_row6432942133712"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p94327422373"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p94327422373"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p94327422373"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p14432134216376"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p14432134216376"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p14432134216376"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p124321542193711"><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p124321542193711"></a><a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_p124321542193711"></a>tiling data的地址。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001593174624_zh-cn_topic_0000001339213782_section320753512363"></a>

```
size_t cap_size = 100U;
size_t total_size = cap_size + sizeof(TilingData);
auto td_buf = std::unique_ptr<uint8_t[]>(new (std::nothrow) uint8_t[total_size]());
auto td = reinterpret_cast<TilingData *>(td_buf.get());
td->Init(cap_size, td_buf.get() + sizeof(TilingData)); // 内存平铺
```

