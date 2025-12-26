# IOInstanceNum<a name="ZH-CN_TOPIC_0000002453662376"></a>

## 函数功能<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section36583473819"></a>

当输入IR原型实例个数不为1时（一般是可选输入或动态输入场景），需要设置算子每个输入IR原型的实例个数，用于构造各子类Context的基类ExtendedKernelContext中ComputeNodeInfo信息。

## 函数原型<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section13230182415108"></a>

```
T &IOInstanceNum(const std::vector<uint32_t> &input_instance_num, const std::vector<uint32_t> &output_instance_num)
```

## 参数说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section75395119104"></a>

<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row6223476444"><th class="cellrowborder" valign="top" width="19.2%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="11.790000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="69.01%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row152234713443"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.4.1.1 "><p id="p1391855919199"><a name="p1391855919199"></a><a name="p1391855919199"></a>input_instance_num</p>
</td>
<td class="cellrowborder" valign="top" width="11.790000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.01%" headers="mcps1.1.4.1.3 "><p id="p36342134202"><a name="p36342134202"></a><a name="p36342134202"></a>是一个vector数组输入，vector的size代表算子原型输入个数，vector数组上每个位置的数字代表每个IR原型输入的实例个数。</p>
</td>
</tr>
<tr id="row118165617190"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.4.1.1 "><p id="p116828382014"><a name="p116828382014"></a><a name="p116828382014"></a>output_instance_num</p>
</td>
<td class="cellrowborder" valign="top" width="11.790000000000001%" headers="mcps1.1.4.1.2 "><p id="p73541374200"><a name="p73541374200"></a><a name="p73541374200"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.01%" headers="mcps1.1.4.1.3 "><p id="p781145651911"><a name="p781145651911"></a><a name="p781145651911"></a>是一个vector数组输入，vector的size代表算子原型输出个数，vector数组上每个位置的数字代表每个IR原型输出的实例个数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section25791320141317"></a>

返回子类对象T类型的引用，用于支持子类链式调用。

## 约束说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section19165124931511"></a>

此接口与[IONum](IONum.md)接口互斥。仅需调用2种接口的一种即可，以先调用的接口为准。

