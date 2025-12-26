# Workspace<a name="ZH-CN_TOPIC_0000002421472502"></a>

## 函数功能<a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section36583473819"></a>

设置Workspace内存指针，可以传多块Workspace地址。

## 函数原型<a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section13230182415108"></a>

```
OpTilingContextBuilder &Workspace(const gert::ContinuousVector *workspace)
```

## 参数说明<a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section75395119104"></a>

<a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p10223674448"><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p10223674448"></a><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.329999999999998%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p645511218169"><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p645511218169"></a><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.45%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p1922337124411"><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p1922337124411"></a><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p2340183613156"><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p2340183613156"></a><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p2340183613156"></a>workspace</p>
</td>
<td class="cellrowborder" valign="top" width="15.329999999999998%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p143401361158"><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p143401361158"></a><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.45%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p2684123934216"><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p2684123934216"></a><a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_p2684123934216"></a>ContinuousVector *结构，每一个元素对应一个Workspace指针。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section25791320141317"></a>

OpTilingContextBuilder对象本身，用于链式调用。

## 约束说明<a name="zh-cn_topic_0000002419998912_zh-cn_topic_0000001526366794_zh-cn_topic_0000001389867689_section19165124931511"></a>

-   在调用Build方法之前，必须调用该接口，否则构造出的TilingContext将包含未定义数据。
-   通过指针传入的参数（void\*），其内存所有权归调用者所有；调用者必须确保指针在ContextHolder对象的生命周期内有效。

