# CompiledInfo<a name="ZH-CN_TOPIC_0000002421472510"></a>

## 函数功能<a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section36583473819"></a>

设置算子的CompiledInfo指针, 用于存储TilingParse的结果即CompileInfo信息。

## 函数原型<a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section13230182415108"></a>

```
OpTilingParseContextBuilder &CompiledInfo(const void *compile_info)
```

## 参数说明<a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section75395119104"></a>

<a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p3943172167"><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p3943172167"></a><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p3943172167"></a>compile_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p143401361158"><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p143401361158"></a><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"></a><a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_p2684123934216"></a>编译信息指针。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section25791320141317"></a>

OpTilingParseContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002420158780_zh-cn_topic_0000001602767550_zh-cn_topic_0000001600123102_section19165124931511"></a>

通过指针传入的参数（void\*），其内存所有权归调用者所有；调用者必须确保指针在 ContextHolder 对象的生命周期内有效。

