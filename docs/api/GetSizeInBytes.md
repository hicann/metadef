# GetSizeInBytes<a name="ZH-CN_TOPIC_0000001651187161"></a>

## 函数功能<a name="section8062655"></a>

根据传入的element\_count和data\_type，获取element\_count个该data\_type所占用的内存总大小。

## 函数原型<a name="section5455038"></a>

```
int64_t GetSizeInBytes(int64_t element_count, DataType data_type)
```

## 参数说明<a name="section49095346"></a>

<a name="table62441623"></a>
<table><thead align="left"><tr id="row47897641"><th class="cellrowborder" valign="top" width="24.172417241724172%" id="mcps1.1.4.1.1"><p id="p54503731"><a name="p54503731"></a><a name="p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="22.832283228322833%" id="mcps1.1.4.1.2"><p id="p52726081"><a name="p52726081"></a><a name="p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="52.995299529953%" id="mcps1.1.4.1.3"><p id="p42954172"><a name="p42954172"></a><a name="p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1619912267218"><td class="cellrowborder" valign="top" width="24.172417241724172%" headers="mcps1.1.4.1.1 "><p id="p19200202614212"><a name="p19200202614212"></a><a name="p19200202614212"></a>element_count</p>
</td>
<td class="cellrowborder" valign="top" width="22.832283228322833%" headers="mcps1.1.4.1.2 "><p id="p152001526152115"><a name="p152001526152115"></a><a name="p152001526152115"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.1.4.1.3 "><p id="p11200102619217"><a name="p11200102619217"></a><a name="p11200102619217"></a>用于标识多少个data_type。</p>
</td>
</tr>
<tr id="row56735883"><td class="cellrowborder" valign="top" width="24.172417241724172%" headers="mcps1.1.4.1.1 "><p id="p32203799"><a name="p32203799"></a><a name="p32203799"></a>data_type</p>
</td>
<td class="cellrowborder" valign="top" width="22.832283228322833%" headers="mcps1.1.4.1.2 "><p id="p58370887"><a name="p58370887"></a><a name="p58370887"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="52.995299529953%" headers="mcps1.1.4.1.3 "><p id="p30421379"><a name="p30421379"></a><a name="p30421379"></a>数据类型，请参见<a href="DataType.md">DataType</a>。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

如果传入个数为非法值或传入不支持的数据类型，返回-1。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

