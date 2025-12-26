# CompiledJson<a name="ZH-CN_TOPIC_0000002454911401"></a>

## 函数功能<a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section36583473819"></a>

设置算子的CompiledJson指针，json格式文件指针。

## 函数原型<a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section13230182415108"></a>

```
OpTilingParseContextBuilder &CompiledJson(const ge::char_t *compiled_json)
```

## 参数说明<a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section75395119104"></a>

<a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p3943172167"><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p3943172167"></a><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p3943172167"></a>compiled_json</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p176831930115415"><a name="p176831930115415"></a><a name="p176831930115415"></a>编译信息json文件指针。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section25791320141317"></a>

OpTilingParseContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002453637713_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_section19165124931511"></a>

通过指针传入的参数（ge::char\_t \*），其内存所有权归调用者所有；调用者必须确保指针在ContextHolder对象的生命周期内有效。

