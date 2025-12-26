# GetDynamicInputFormat<a name="ZH-CN_TOPIC_0000002343617957"></a>

## 函数功能<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section36583473819"></a>

根据算子原型定义中的输入索引获取对应的动态输入Format指针。

## 函数原型<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section13230182415108"></a>

```
StorageFormat *GetDynamicInputFormat(const size_t ir_index, const size_t relative_index)
```

## 参数说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section75395119104"></a>

<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p1968683917322"><a name="p1968683917322"></a><a name="p1968683917322"></a>ir_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"></a><a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_p320343694214"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p1575155663210"><a name="p1575155663210"></a><a name="p1575155663210"></a>IR原型定义中的index。</p>
</td>
</tr>
<tr id="row11713193553218"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="p059924563219"><a name="p059924563219"></a><a name="p059924563219"></a>relative_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="p1571416356329"><a name="p1571416356329"></a><a name="p1571416356329"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p1362449113314"><a name="p1362449113314"></a><a name="p1362449113314"></a>该输入实例化后的相对index，例如某个动态输入实例化了3个输入，那么relative_index的有效范围是[0,2]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section25791320141317"></a>

输入Format指针，ir\_index或relative\_index非法时，返回空指针。

关于StorageFormat类型的定义，请参见[StorageFormat](StorageFormat.md)。

## 约束说明<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526366782_zh-cn_topic_0000001389783361_section320753512363"></a>

```
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto format = context->GetDynamicInputFormat(1U, 0U);
  GE_ASSERT_NOTNULL(format);
  // ...
}
```

