# InputTensors<a name="ZH-CN_TOPIC_0000002454911357"></a>

## 函数功能<a name="zh-cn_topic_0000002453637549_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

设置输入Tensor指针。Shape推导时，可通过该Builder类构造的InferShapeContext获取相应的输入Tensor指针。对于数据依赖的算子，对应数据依赖的输入Tensor中的TensorData需要设置为正确的Host地址；对于非数据依赖算子，Tensor的TensorData需要设置为空指针。

## 函数原型<a name="zh-cn_topic_0000002453637549_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

```
OpInferShapeContextBuilder &InputTensors(const std::vector<gert::Tensor *> &inputs)
```

## 参数说明<a name="zh-cn_topic_0000002453637549_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section75395119104"></a>

<a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p11838633161614"><a name="p11838633161614"></a><a name="p11838633161614"></a>inputs</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453597649_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p13371184815167"><a name="p13371184815167"></a><a name="p13371184815167"></a>输入Tensor指针数组，所有权归调用者管理，调用者需要保证输入指针生命周期长于Build产生的ContextHolder对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453637549_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

OpInferShapeContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002453637549_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section19165124931511"></a>

在调用Build方法之前，必须调用该接口，否则构造出的InferShapeContext将包含未定义数据。

