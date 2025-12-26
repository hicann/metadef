# GetWorkspaceSizes<a name="ZH-CN_TOPIC_0000002078486193"></a>

## 函数功能<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section36583473819"></a>

获取workspace sizes指针，workspace大小以字节为单位。

## 函数原型<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section13230182415108"></a>

**size\_t \*GetWorkspaceSizes\(const size\_t workspace\_count\)**

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
<tbody><tr id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p2340183613156"><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p2340183613156"></a><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p2340183613156"></a>workspace_count</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p143401361158"><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p143401361158"></a><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p109018236585"><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p109018236585"></a><a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_p109018236585"></a>workspace的个数，取值不超过<a href="GetWorkspaceNum.md">GetWorkspaceNum</a>返回的workspace个数。超出时，会返回空指针。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section25791320141317"></a>

workspace sizes指针。

## 约束说明<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001609859929_zh-cn_topic_0000001339510360_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
    auto ws = context->GetWorkspaceSizes(5);
    if (ws == nullptr) {
        return ge::GRAPH_FAILED;
    }
    // ...
}
```

