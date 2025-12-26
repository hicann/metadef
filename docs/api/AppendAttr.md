# AppendAttr<a name="ZH-CN_TOPIC_0000002453821988"></a>

## 函数功能<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section36583473819"></a>

追加算子IR原型的属性信息，下标从0开始，用于构造各子类Context的基类ExtendedKernelContext中的ExtendedInfo信息。

构造完成后，通过Context的基类接口GetAttr获取到的RuntimeAttrs中属性的顺序与构造时追加的顺序一致。

例如：

```
bool attr0 = true;
int64_t attr1 = 1;
vector<int64_t> attr2 = {1, 2, 3, 4};
context_builder.AppendAttr(attr0).AppendAttr(attr1).AppendAttr(attr2);
```

Build构造完成后结果如下：

```
ctx->GetAttrs()->GetBool(0) -> attr0,
ctx->GetAttrs()->GetInt(1) -> attr1,
ctx->GetAttrs()->GetListInt(2) -> attr2
```

## 函数原型<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section13230182415108"></a>

```
T &AppendAttr(bool attr)
T &AppendAttr(int64_t attr)
T &AppendAttr(float attr)
T &AppendAttr(const ge::AscendString &attr)
T &AppendAttr(const std::vector<bool> &attr)
T &AppendAttr(const std::vector<int64_t> &attr)
T &AppendAttr(const std::vector<float> &attr)
T &AppendAttr(const std::vector<ge::AscendString> &attr)
T &AppendAttr(const std::vector<std::vector<int64_t>> &attr)
```

## 参数说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section75395119104"></a>

<a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row6223476444"><th class="cellrowborder" valign="top" width="19.2%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="11.790000000000001%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="69.01%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_row152234713443"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.4.1.1 "><p id="p1391855919199"><a name="p1391855919199"></a><a name="p1391855919199"></a>attr</p>
</td>
<td class="cellrowborder" valign="top" width="11.790000000000001%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a><a name="zh-cn_topic_0000002453637577_zh-cn_topic_0000001576806829_zh-cn_topic_0000001339187720_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.01%" headers="mcps1.1.4.1.3 "><p id="p596173013254"><a name="p596173013254"></a><a name="p596173013254"></a>属性值，当前仅支持以下类型：bool、int64_t、float、AscendString、std::vector&lt;bool&gt;、std::vector&lt;int64_t&gt;、std::vector&lt;float&gt;、std::vector&lt;AscendString&gt;、std::vector&lt;std::vector&lt;int64_t&gt;&gt;。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section25791320141317"></a>

返回子类对象T类型的引用，用于支持子类链式调用。

## 约束说明<a name="zh-cn_topic_0000002419998812_zh-cn_topic_0000001652087949_zh-cn_topic_0000001599803682_section19165124931511"></a>

无。

