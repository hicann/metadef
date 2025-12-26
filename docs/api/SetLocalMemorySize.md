# SetLocalMemorySize<a name="ZH-CN_TOPIC_0000002104774485"></a>

## 函数功能<a name="zh-cn_topic_0000001705949065_zh-cn_topic_0000001339347384_section36583473819"></a>

用于设置需要使用的Local Memory大小。不设置的情况下，默认为0，即算子不需要使用Local Memory。

**该接口为预留接口，为后续功能做保留，不建议开发者使用，开发者无需关注。**

## 函数原型<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section13230182415108"></a>

**ge::graphStatus SetLocalMemorySize\(const uint32\_t local\_memory\_size\)**

## 参数说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section75395119104"></a>

<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p10223674448"><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p10223674448"></a><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p645511218169"><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p645511218169"></a><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p1922337124411"><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p1922337124411"></a><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p0523842193510"><a name="p0523842193510"></a><a name="p0523842193510"></a>local_memory_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p143401361158"><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p143401361158"></a><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p8234133625"><a name="p8234133625"></a><a name="p8234133625"></a>Local Memory大小。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
    // ...
    auto ret = context->SetLocalMemorySize(1024 * 128);
}
```

