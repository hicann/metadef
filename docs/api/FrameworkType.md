# FrameworkType<a name="ZH-CN_TOPIC_0000002043200492"></a>

## 函数功能<a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_section13304742"></a>

设置原始模型的框架类型。

## 函数原型<a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_section52633814"></a>

```
[OpRegistrationData](OpRegistrationData.md) &FrameworkType(const domi::FrameworkType &fmk_type)
```

## 参数说明<a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_section3942281"></a>

<a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_table32039251"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_row43625037"><th class="cellrowborder" valign="top" width="24.91249124912491%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p43967124"><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p43967124"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p43967124"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="18.961896189618958%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p4567320"><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p4567320"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p4567320"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="56.12561256125613%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p34408640"><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p34408640"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p34408640"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_row35636469"><td class="cellrowborder" valign="top" width="24.91249124912491%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p872862"><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p872862"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p872862"></a>fmk_type</p>
</td>
<td class="cellrowborder" valign="top" width="18.961896189618958%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p3592996"><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p3592996"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p3592996"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="56.12561256125613%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p22597230"><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p22597230"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p22597230"></a>框架类型：</p>
<a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_ul1747767296"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_ul1747767296"></a><ul id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_ul1747767296"><li>CAFFE</li><li>TENSORFLOW</li><li>ONNX</li></ul>
<p id="zh-cn_topic_0000001265071194_p11983176123012"><a name="zh-cn_topic_0000001265071194_p11983176123012"></a><a name="zh-cn_topic_0000001265071194_p11983176123012"></a></p>
<p id="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p18396313192910"><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p18396313192910"></a><a name="zh-cn_topic_0000001265071194_zh-cn_topic_0204328170_p18396313192910"></a>FrameworkType枚举值的定义如下：</p>
<a name="screen1659124116527"></a><a name="screen1659124116527"></a><pre class="screen" codetype="Cpp" id="screen1659124116527">enum FrameworkType {
CAFFE = 0,
MINDSPORE = 1,
TENSORFLOW = 3,
ANDROID_NN,
ONNX,
FRAMEWORK_RESERVED,
};</pre>
</td>
</tr>
</tbody>
</table>

