# GetCompileInfo<a name="ZH-CN_TOPIC_0000002042368514"></a>

## 函数功能<a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_section36583473819"></a>

获取编译信息CompileInfo。

本方法用以获取算子TilingParse解析出来的编译信息，具体信息看具体算子对应的CompileInfo结构体。例如，对于Add算子来说，其编译信息如下：

```
struct AddCompileInfo {
  int64_t a;  // 输入a
  int64_t b;  // 输入b
};
```

## 函数原型<a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_section13230182415108"></a>

**template<typename T\> const T \*GetCompileInfo\(\) const**

**const void \*GetCompileInfo\(\) const**

## 参数说明<a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_section75395119104"></a>

<a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_row6223476444"><th class="cellrowborder" valign="top" width="20.34%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p10223674448"><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p10223674448"></a><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="79.66%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p1922337124411"><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p1922337124411"></a><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_row152234713443"><td class="cellrowborder" valign="top" width="20.34%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p2340183613156"><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p2340183613156"></a><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p2340183613156"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="79.66%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p203577149217"><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p203577149217"></a><a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_p203577149217"></a>模板参数，CompileInfo的类型。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_section25791320141317"></a>

**template<typename T\> const T \*GetCompileInfo\(\) const；**返回一个指定类型T的CompileInfo的指针。

**const void \*GetCompileInfo\(\) const；**返回一个任意类型的CompileInfo的指针。

## 约束说明<a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001526046950_zh-cn_topic_0000001339347384_section320753512363"></a>

```
ge::graphStatus TilingForAdd(TilingContext *context) {
  auto ci = context->GetCompileInfo<AddCompileInfo>();  
  GE_ASSERT_NOTNULL(ci);
  ...
}
```

