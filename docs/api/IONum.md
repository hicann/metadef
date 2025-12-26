# IONum<a name="ZH-CN_TOPIC_0000002486901693"></a>

## 函数功能<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section36583473819"></a>

设置算子输入输出IR原型个数，用于构造各子类Context的基类ExtendedKernelContext中ComputeNodeInfo信息。该接口默认每个IR原型输入输出的实例个数为1。

## 函数原型<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section13230182415108"></a>

```
T &IONum(size_t input_ir_num, size_t output_ir_num)
```

## 参数说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section75395119104"></a>

<a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p16169141619128"><a name="p16169141619128"></a><a name="p16169141619128"></a>input_ir_num</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453637493_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p18461143120122"><a name="p18461143120122"></a><a name="p18461143120122"></a>输入IR原型个数。</p>
</td>
</tr>
<tr id="row2063033018412"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p2905719101216"><a name="p2905719101216"></a><a name="p2905719101216"></a>output_ir_num</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p196311930164111"><a name="p196311930164111"></a><a name="p196311930164111"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p53331138151215"><a name="p53331138151215"></a><a name="p53331138151215"></a>输出IR原型个数。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section25791320141317"></a>

返回子类对象T类型的引用，用于支持子类链式调用。

## 约束说明<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section19165124931511"></a>

此接口与[IOInstanceNum](IOInstanceNum.md)接口互斥。仅需调用2种接口的一种即可，以先调用的接口为准。

