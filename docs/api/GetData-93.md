# GetData<a name="ZH-CN_TOPIC_0000002042526954"></a>

## 函数功能<a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_section36583473819"></a>

获取Tensor的数据地址。

## 函数原型<a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_section13230182415108"></a>

```
template<class T>  const T *GetData() const
template<class T>  auto GetData() -> T*
```

## 参数说明<a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_section75395119104"></a>

<a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p10223674448"><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p10223674448"></a><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p645511218169"><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p645511218169"></a><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p1922337124411"><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p1922337124411"></a><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p51918481213"><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p51918481213"></a><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p51918481213"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p1394212553919"><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p1394212553919"></a><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p1394212553919"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p16171244128"><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p16171244128"></a><a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_p16171244128"></a>数据类型。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_section25791320141317"></a>

数据地址。

## 约束说明<a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001583865622_zh-cn_topic_0000001390071733_section320753512363"></a>

```
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape                
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format                              
              kFollowing,                                  // placement                
              ge::DT_FLOAT16,                              //dt                
              nullptr};
auto addr = tensor.GetData<int64_t>(); // reinterpret_cast<int64_t *>(&tensor + 1)
```

