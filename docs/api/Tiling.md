# Tiling<a name="ZH-CN_TOPIC_0000002042527142"></a>

## 函数功能<a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_section36583473819"></a>

注册算子的Tiling函数。

用户需要为算子编写一个TilingKernelFunc类型的函数，并使用该接口进行注册。同时可以指定tiling数据的最大长度，缺省值为2048字节。

TilingKernelFunc类型定义如下：

```
using TilingKernelFunc = UINT32 (*)(TilingContext *);
```

## 函数原型<a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_section13230182415108"></a>

```
OpImplRegisterV2 &Tiling(TilingKernelFunc tiling_func, size_t max_tiling_data_size = 2048)
```

## 参数说明<a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_section973071710713"></a>

<a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_row6223476444"><th class="cellrowborder" valign="top" width="17.18%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p10223674448"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p10223674448"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.379999999999999%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p645511218169"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p645511218169"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p1922337124411"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p1922337124411"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_row152234713443"><td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p17770136956"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p17770136956"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p17770136956"></a>tiling_func</p>
</td>
<td class="cellrowborder" valign="top" width="15.379999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p167701536957"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p167701536957"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p19227201772818"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p19227201772818"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p19227201772818"></a>待注册的自定义Tiling函数，类型为TilingKernelFunc。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_row87417374283"><td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p97493722816"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p97493722816"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p97493722816"></a>max_tiling_data_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.379999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p1174153732815"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p1174153732815"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p1174153732815"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p67412371282"><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p67412371282"></a><a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_p67412371282"></a>tiling数据的最大长度，默认值为2048字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了Tiling函数tiling\_func。

## 约束说明<a name="zh-cn_topic_0000002035358448_zh-cn_topic_0000001396949921_section19165124931511"></a>

无。

