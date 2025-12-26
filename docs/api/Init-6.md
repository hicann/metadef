# Init<a name="ZH-CN_TOPIC_0000002042368706"></a>

## 函数功能<a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_section36583473819"></a>

初始化ContinuousVectorVector类。

## 函数原型<a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_section13230182415108"></a>

```
void Init(const size_t capacity)
```

## 参数说明<a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_section75395119104"></a>

<a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_row6223476444"><th class="cellrowborder" valign="top" width="19.29%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p10223674448"><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p10223674448"></a><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p645511218169"><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p645511218169"></a><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1922337124411"><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1922337124411"></a><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_row14829163161614"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p4829133121620"><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p4829133121620"></a><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p4829133121620"></a>capacity</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1082983131619"><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1082983131619"></a><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1082983131619"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1769121516311"><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1769121516311"></a><a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_p1769121516311"></a>实例的最大容量。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001702266358_zh-cn_topic_0000001340006336_section320753512363"></a>

```
size_t total_length = 1000U; // 需根据实际存放的数据量进行设置 
size_t capacity = 100U;
std::vector<uint8_t> buf(total_length);
auto cvv = new (buf.data()) ContinuousVectorVector();
cvv->Init(capacity);
```

