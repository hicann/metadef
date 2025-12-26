# OpRegistrationData构造函数和析构函数<a name="ZH-CN_TOPIC_0000002043042160"></a>

## 函数功能<a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section36893359"></a>

OpRegistrationData构造函数和析构函数。

## 函数原型<a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section136951948195410"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
OpRegistrationData(const std::string &om_optype)
OpRegistrationData(const char_t *om_optype)
~OpRegistrationData()
```

## 参数说明<a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section63604780"></a>

<a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_table1802150"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_row32153279"><th class="cellrowborder" valign="top" width="27.63%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"></a><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="14.469999999999999%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"></a><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="57.9%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"></a><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_row34574683"><td class="cellrowborder" valign="top" width="27.63%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"></a><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"></a>om_optype</p>
</td>
<td class="cellrowborder" valign="top" width="14.469999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"></a><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="57.9%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"></a><a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"></a>指定适配<span id="zh-cn_topic_0000001312471161_ph1555712386204"><a name="zh-cn_topic_0000001312471161_ph1555712386204"></a><a name="zh-cn_topic_0000001312471161_ph1555712386204"></a>昇腾AI处理器</span>的模型支持的算子类型。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

OpRegistrationData构造函数返回OpRegistrationData类型的对象。

## 异常处理<a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0000001312471161_zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

