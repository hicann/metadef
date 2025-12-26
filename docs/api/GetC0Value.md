# GetC0Value<a name="ZH-CN_TOPIC_0000001575118272"></a>

## 函数功能<a name="section8062655"></a>

从实际format中解析出C0 format信息。

## 函数原型<a name="section5455038"></a>

```
inline int64_t GetC0Value(int32_t format)
```

## 参数说明<a name="section49095346"></a>

<a name="table122178917410"></a>
<table><thead align="left"><tr id="row122171695415"><th class="cellrowborder" valign="top" width="15.57155715571557%" id="mcps1.1.4.1.1"><p id="p1121799142"><a name="p1121799142"></a><a name="p1121799142"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="14.85148514851485%" id="mcps1.1.4.1.2"><p id="p162171591545"><a name="p162171591545"></a><a name="p162171591545"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="69.57695769576956%" id="mcps1.1.4.1.3"><p id="p1521769142"><a name="p1521769142"></a><a name="p1521769142"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row5217891047"><td class="cellrowborder" valign="top" width="15.57155715571557%" headers="mcps1.1.4.1.1 "><p id="p1321713914418"><a name="p1321713914418"></a><a name="p1321713914418"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="14.85148514851485%" headers="mcps1.1.4.1.2 "><p id="p18217191342"><a name="p18217191342"></a><a name="p18217191342"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="69.57695769576956%" headers="mcps1.1.4.1.3 "><p id="p12171391442"><a name="p12171391442"></a><a name="p12171391442"></a>实际format（4字节大小，第1个字节的高四位为预留字段，低四位为C0 format，第2-3字节为子format信息，第4字节为主format信息）。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

-   如果包含C0 format，返回实际format中包含的C0 format。
-   如果不包含C0 format，返回-1。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

设置实际format格式时，第一个字节低四位的C0 format的范围只支持x=\(0001\~1111\)，实际获取的C0 value为2^x-1。

