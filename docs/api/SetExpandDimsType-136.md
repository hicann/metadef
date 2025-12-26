# SetExpandDimsType<a name="ZH-CN_TOPIC_0000002518580603"></a>

## 函数功能<a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_section36583473819"></a>

设置形状的补维规则。

## 函数原型<a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_section13230182415108"></a>

```
void SetExpandDimsType(const ExpandDimsType &expand_dims_type)
```

## 参数说明<a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_section75395119104"></a>

<a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_row6223476444"><th class="cellrowborder" valign="top" width="22.85%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p10223674448"><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p10223674448"></a><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.84%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p645511218169"><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p645511218169"></a><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="63.31%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p1922337124411"><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p1922337124411"></a><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_row152234713443"><td class="cellrowborder" valign="top" width="22.85%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p2340183613156"><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p2340183613156"></a><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p2340183613156"></a>expand_dims_type</p>
</td>
<td class="cellrowborder" valign="top" width="13.84%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p143401361158"><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p143401361158"></a><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="63.31%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p19544204917121"><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p19544204917121"></a><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p19544204917121"></a>需要设置的补维规则。</p>
<p id="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p1943184216170"><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p1943184216170"></a><a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_p1943184216170"></a>关于ExpandDimsType类型的定义，可参见<a href="ExpandDimsType.md">ExpandDimsType</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_section25791320141317"></a>

无

## 约束说明<a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_section19165124931511"></a>

无

## 调用示例<a name="zh-cn_topic_0000001584184958_zh-cn_topic_0000001390073757_section320753512363"></a>

```
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape              
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format              
                kFollowing,                                  // placement              
                ge::DT_FLOAT16,                              //dt              
                nullptr};
ExpandDimsType type("1001");
tensor.SetExpandDimsType(type);
auto expand_dims_type = tensor.GetExpandDimsType();   // type
```

