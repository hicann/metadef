# Create<a name="ZH-CN_TOPIC_0000002042527002"></a>

## 函数功能<a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_section36583473819"></a>

创建一个ContinuousVector实例，ContinuousVector不支持动态扩容。

## 函数原型<a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_section13230182415108"></a>

```
template<typename T>  static std::unique_ptr<uint8_t[]> Create(size_t capacity, size_t &total_size)
template<typename T>  static std::unique_ptr<uint8_t[]> Create(const size_t capacity)
```

## 参数说明<a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_section75395119104"></a>

<a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_row6223476444"><th class="cellrowborder" valign="top" width="19.29%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p10223674448"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p10223674448"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p645511218169"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p645511218169"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1922337124411"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1922337124411"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_row152234713443"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p18984952202910"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p18984952202910"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p18984952202910"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p191819441211"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p191819441211"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p744014109162"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p744014109162"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p744014109162"></a>实例中包含的元素类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_row14829163161614"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p4829133121620"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p4829133121620"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p4829133121620"></a>capacity</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1082983131619"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1082983131619"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1082983131619"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1769121516311"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1769121516311"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p1769121516311"></a>实例的最大容量。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_row161871264183"><td class="cellrowborder" valign="top" width="19.29%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p53181521434"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p53181521434"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p53181521434"></a>total_size</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p131882691812"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p131882691812"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p131882691812"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p364017251032"><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p364017251032"></a><a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_p364017251032"></a>本实例的总长度。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_section25791320141317"></a>

指向本实例的指针。

## 约束说明<a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001592697024_zh-cn_topic_0000001340006336_section320753512363"></a>

```
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity); // 创建了一个可以存放100个int64_t数据的内存。
```

