# OpName<a name="ZH-CN_TOPIC_0000002486941729"></a>

## 函数功能<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

设置算子名称，用于构造各子类Context的基类ExtendedKernelContext中ComputeNodeInfo信息。

## 函数原型<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

```
T &OpName(const ge::AscendString &op_name)
```

## 参数说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section75395119104"></a>

<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p1652031015105"><a name="p1652031015105"></a><a name="p1652031015105"></a>op_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p12128195515218"><a name="p12128195515218"></a><a name="p12128195515218"></a>算子名称。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

返回子类对象T类型的引用，用于支持子类链式调用。

## 约束说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section19165124931511"></a>

无

