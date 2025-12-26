# Shape构造函数和析构函数<a name="ZH-CN_TOPIC_0000001265080934"></a>

## 函数功能<a name="zh-cn_topic_0204328120_zh-cn_topic_0182636384_section36893359"></a>

Shape构造函数和析构函数。

## 函数原型<a name="zh-cn_topic_0204328120_zh-cn_topic_0182636384_section136951948195410"></a>

```
Shape()
~Shape() = default
explicit Shape(const std::vector<int64_t> &dims)
```

## 参数说明<a name="zh-cn_topic_0204328120_zh-cn_topic_0182636384_section63604780"></a>

<a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_table47561922"></a>
<table><thead align="left"><tr id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_row29169897"><th class="cellrowborder" valign="top" width="17.7%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p13951479"><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p13951479"></a><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p13951479"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="16.33%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p56327989"><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p56327989"></a><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p56327989"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="65.97%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p66531170"><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p66531170"></a><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p66531170"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_row20315681"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p34957489"><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p34957489"></a><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p34957489"></a>dims</p>
</td>
<td class="cellrowborder" valign="top" width="16.33%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p12984378"><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p12984378"></a><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p12984378"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="65.97%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p15921183410"><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p15921183410"></a><a name="zh-cn_topic_0204328120_zh-cn_topic_0182636394_p15921183410"></a>Shape的取值内容。</p>
<p id="p8484121717101"><a name="p8484121717101"></a><a name="p8484121717101"></a>Shape表征张量数据的维度大小，用std::vector&lt;int64_t&gt;表征每一个维度的具体大小。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328120_zh-cn_topic_0182636384_section35572112"></a>

Shape构造函数返回Shape类型的对象。

## 异常处理<a name="zh-cn_topic_0204328120_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328120_zh-cn_topic_0182636384_section62768825"></a>

无。

