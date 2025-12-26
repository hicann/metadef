# OutputTensorDesc<a name="ZH-CN_TOPIC_0000002455031425"></a>

## 函数功能<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section36583473819"></a>

设置算子输出的Tensor描述信息，用于构造InferShapeContext的基类ExtendedKernelContext中的ComputeNodeInfo等信息。

## 函数原型<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section13230182415108"></a>

```
OpInferShapeContextBuilder &OutputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## 参数说明<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section75395119104"></a>

<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p104548532128"><a name="p104548532128"></a><a name="p104548532128"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p8584431111318"><a name="p8584431111318"></a><a name="p8584431111318"></a>输出的索引，对应的是算子输出实例索引。</p>
</td>
</tr>
<tr id="row829845112713"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p1313559191210"><a name="p1313559191210"></a><a name="p1313559191210"></a>dtype</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p1129916519278"><a name="p1129916519278"></a><a name="p1129916519278"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p761573681317"><a name="p761573681317"></a><a name="p761573681317"></a>输出Tensor的数据类型。</p>
</td>
</tr>
<tr id="row878389271"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p18250249134"><a name="p18250249134"></a><a name="p18250249134"></a>origin_format</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p0780815277"><a name="p0780815277"></a><a name="p0780815277"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p2397163161419"><a name="p2397163161419"></a><a name="p2397163161419"></a>输出Tensor的原始格式。</p>
</td>
</tr>
<tr id="row1480161113277"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p221713941318"><a name="p221713941318"></a><a name="p221713941318"></a>storage_format</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p1080811152711"><a name="p1080811152711"></a><a name="p1080811152711"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p114591536111419"><a name="p114591536111419"></a><a name="p114591536111419"></a>输出Tensor的存储格式。</p>
</td>
</tr>
<tr id="row561918146136"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p1375431715133"><a name="p1375431715133"></a><a name="p1375431715133"></a>expand_dims_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p76195148137"><a name="p76195148137"></a><a name="p76195148137"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p2229134011414"><a name="p2229134011414"></a><a name="p2229134011414"></a>输出Tensor的补维规则ExpandDimsType。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section25791320141317"></a>

OpInferShapeContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section19165124931511"></a>

在调用Build方法之前，必须调用该接口，否则构造出的InferShapeContext将包含未定义数据。

