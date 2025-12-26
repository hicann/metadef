# SetSize<a name="ZH-CN_TOPIC_0000002042526962"></a>

## 函数功能<a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_section36583473819"></a>

设置Tensor的内存大小。

## 函数原型<a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_section13230182415108"></a>

**void SetSize\(const size\_t size\)**

## 参数说明<a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_section75395119104"></a>

<a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_row6223476444"><th class="cellrowborder" valign="top" width="11.93%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p10223674448"><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p10223674448"></a><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16.61%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p645511218169"><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p645511218169"></a><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="71.46000000000001%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p1922337124411"><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p1922337124411"></a><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_row152234713443"><td class="cellrowborder" valign="top" width="11.93%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p2340183613156"><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p2340183613156"></a><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p2340183613156"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p143401361158"><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p143401361158"></a><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="71.46000000000001%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p14151132861"><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p14151132861"></a><a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_p14151132861"></a>Tensor的内存大小，单位是字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_section25791320141317"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001584184950_zh-cn_topic_0000001339232198_section320753512363"></a>

```
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetSize(0U); 
```

