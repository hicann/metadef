# HasC0Format<a name="ZH-CN_TOPIC_0000001574799352"></a>

## 函数功能<a name="section8062655"></a>

判断实际format中是否包含C0 format。

## 函数原型<a name="section5455038"></a>

```
inline bool HasC0Format(int32_t format)
```

## 参数说明<a name="section49095346"></a>

<a name="table122178917410"></a>
<table><thead align="left"><tr id="row122171695415"><th class="cellrowborder" valign="top" width="13.94139413941394%" id="mcps1.1.4.1.1"><p id="p1121799142"><a name="p1121799142"></a><a name="p1121799142"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16.051605160516054%" id="mcps1.1.4.1.2"><p id="p162171591545"><a name="p162171591545"></a><a name="p162171591545"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="70.00700070007%" id="mcps1.1.4.1.3"><p id="p1521769142"><a name="p1521769142"></a><a name="p1521769142"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row5217891047"><td class="cellrowborder" valign="top" width="13.94139413941394%" headers="mcps1.1.4.1.1 "><p id="p1321713914418"><a name="p1321713914418"></a><a name="p1321713914418"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="16.051605160516054%" headers="mcps1.1.4.1.2 "><p id="p18217191342"><a name="p18217191342"></a><a name="p18217191342"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="70.00700070007%" headers="mcps1.1.4.1.3 "><p id="p12171391442"><a name="p12171391442"></a><a name="p12171391442"></a>实际format（4字节大小，第1个字节的高四位为预留字段，低四位为C0 format，第2-3字节为子format信息，第4字节为主format信息）。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

-   true：实际format中包含C0 format。
-   false：实际format中不包含C0 format。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

