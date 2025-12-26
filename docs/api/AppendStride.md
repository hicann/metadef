# AppendStride<a name="ZH-CN_TOPIC_0000002486420692"></a>

## 函数功能<a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_section36583473819"></a>

向后扩展一个步长值，如果扩展的步长数量超出Stride的最大限制，那么本函数不做任何事情。

## 函数原型<a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_section13230182415108"></a>

```
Stride& AppendStride(const int64_t value)
```

## 参数说明<a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_section75395119104"></a>

<a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p10223674448"><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p10223674448"></a><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p645511218169"><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p645511218169"></a><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p1922337124411"><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p1922337124411"></a><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p2340183613156"><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p2340183613156"></a><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p2340183613156"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p143401361158"><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p143401361158"></a><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p19544204917121"><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p19544204917121"></a><a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_p19544204917121"></a>扩展的步长值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_section25791320141317"></a>

this引用。

## 约束说明<a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001584025022_zh-cn_topic_0000001339558198_section320753512363"></a>

```
Stride stride0({3, 256, 256});
stride0.AppendStride(1024); // 3,256,256,1024
```

