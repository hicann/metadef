# RegOpLibInit<a name="ZH-CN_TOPIC_0000002119661308"></a>

## 函数功能<a name="zh-cn_topic_0000001936560960_section36583473819"></a>

注册自定义算子动态库的初始化函数。

## 函数原型<a name="zh-cn_topic_0000001936560960_section13230182415108"></a>

```
OpLibRegister &RegOpLibInit(OpLibInitFunc func)
```

## 参数说明<a name="zh-cn_topic_0000001936560960_section75395119104"></a>

<a name="zh-cn_topic_0000001936560960_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001936560960_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001936560960_p10223674448"><a name="zh-cn_topic_0000001936560960_p10223674448"></a><a name="zh-cn_topic_0000001936560960_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001936560960_p645511218169"><a name="zh-cn_topic_0000001936560960_p645511218169"></a><a name="zh-cn_topic_0000001936560960_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001936560960_p1922337124411"><a name="zh-cn_topic_0000001936560960_p1922337124411"></a><a name="zh-cn_topic_0000001936560960_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001936560960_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001936560960_p1374621162312"><a name="zh-cn_topic_0000001936560960_p1374621162312"></a><a name="zh-cn_topic_0000001936560960_p1374621162312"></a><strong id="b17738113105420"><a name="b17738113105420"></a><a name="b17738113105420"></a>func</strong></p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001936560960_p107457119238"><a name="zh-cn_topic_0000001936560960_p107457119238"></a><a name="zh-cn_topic_0000001936560960_p107457119238"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001936560960_p167457119233"><a name="zh-cn_topic_0000001936560960_p167457119233"></a><a name="zh-cn_topic_0000001936560960_p167457119233"></a>要注册的自定义初始化函数，类型为OpLibInitFunc。</p>
<a name="screen9923814261"></a><a name="screen9923814261"></a><pre class="screen" codetype="Cpp" id="screen9923814261">using OpLibInitFunc = uint32_t (*)(ge::AscendString&amp;);</pre>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001936560960_section25791320141317"></a>

返回一个OpLibRegister对象，该对象新增注册了OpLibInitFunc函数func。

## 约束说明<a name="zh-cn_topic_0000001936560960_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001936560960_section320753512363"></a>

```
uint32_t Init(ge::AscendString&) {
  // init func
  return 0;
}

REGISTER_OP_LIB(vendor_1).RegOpLibInit(Init); // 注册厂商名为vendor_1的初始化函数Init
```

