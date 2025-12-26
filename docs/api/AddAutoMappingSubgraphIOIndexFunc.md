# AddAutoMappingSubgraphIOIndexFunc<a name="ZH-CN_TOPIC_0000002043200576"></a>

## 函数功能<a name="zh-cn_topic_0000001601744668_section8062655"></a>

注册的具体网络类型的自动映射函数。

## 函数原型<a name="zh-cn_topic_0000001601744668_section5455038"></a>

```
void AddAutoMappingSubgraphIOIndexFunc(domi::FrameworkType framework, AutoMappingSubgraphIOIndexFunc fun)
```

## 参数说明<a name="zh-cn_topic_0000001601744668_section49095346"></a>

<a name="zh-cn_topic_0000001601744668_table62441623"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001601744668_row47897641"><th class="cellrowborder" valign="top" width="24.782478247824784%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001601744668_p54503731"><a name="zh-cn_topic_0000001601744668_p54503731"></a><a name="zh-cn_topic_0000001601744668_p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="26.882688268826882%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001601744668_p52726081"><a name="zh-cn_topic_0000001601744668_p52726081"></a><a name="zh-cn_topic_0000001601744668_p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="48.33483348334833%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001601744668_p42954172"><a name="zh-cn_topic_0000001601744668_p42954172"></a><a name="zh-cn_topic_0000001601744668_p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001601744668_row56735883"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001601744668_p2755144663518"><a name="zh-cn_topic_0000001601744668_p2755144663518"></a><a name="zh-cn_topic_0000001601744668_p2755144663518"></a>framework</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001601744668_p58370887"><a name="zh-cn_topic_0000001601744668_p58370887"></a><a name="zh-cn_topic_0000001601744668_p58370887"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001601744668_p30421379"><a name="zh-cn_topic_0000001601744668_p30421379"></a><a name="zh-cn_topic_0000001601744668_p30421379"></a>网络类型，FrameworkType类型定义请参考<a href="FrameworkType.md">FrameworkType</a>。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001601744668_row153631853115115"><td class="cellrowborder" valign="top" width="24.782478247824784%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001601744668_p1467815394017"><a name="zh-cn_topic_0000001601744668_p1467815394017"></a><a name="zh-cn_topic_0000001601744668_p1467815394017"></a>fun</p>
</td>
<td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001601744668_p1983811394367"><a name="zh-cn_topic_0000001601744668_p1983811394367"></a><a name="zh-cn_topic_0000001601744668_p1983811394367"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="48.33483348334833%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001601744668_p10838183993616"><a name="zh-cn_topic_0000001601744668_p10838183993616"></a><a name="zh-cn_topic_0000001601744668_p10838183993616"></a>自动映射输入输出函数，函数类型详见<a href="AutoMappingSubgraphIndex.md">AutoMappingSubgraphIndex</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0000001601744668_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

无。

## 异常处理<a name="zh-cn_topic_0000001601744668_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001601744668_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

