# ImplyType<a name="ZH-CN_TOPIC_0000002043200500"></a>

## 函数功能<a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_section14545133"></a>

设置算子执行方式。

## 函数原型<a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_section63797335"></a>

```
OpRegistrationData &ImplyType(const domi::ImplyType &imply_type)
```

## 参数说明<a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_section37305106"></a>

<a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_table16018311"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_row28184154"><th class="cellrowborder" valign="top" width="26.882688268826882%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p1215151"><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p1215151"></a><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p1215151"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="16.99169916991699%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p31318392"><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p31318392"></a><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p31318392"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="56.12561256125613%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p53761822"><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p53761822"></a><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p53761822"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_row59740296"><td class="cellrowborder" valign="top" width="26.882688268826882%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p7125790"><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p7125790"></a><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p7125790"></a>imply_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99169916991699%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p40318154"><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p40318154"></a><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p40318154"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="56.12561256125613%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p44545009"><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p44545009"></a><a name="zh-cn_topic_0000001312711229_zh-cn_topic_0204328173_p44545009"></a>算子执行方式。</p>
<a name="zh-cn_topic_0000001312711229_screen894110205711"></a><a name="zh-cn_topic_0000001312711229_screen894110205711"></a><pre class="screen" codetype="Cpp" id="zh-cn_topic_0000001312711229_screen894110205711">enum class ImplyType : unsigned int
{
BUILDIN = 0,// 内置算子，由OME正常执行
TVM,        // 编译成tvm bin文件执行
CUSTOM,     // 由用户自定义计算逻辑，通过CPU执行
AI_CPU,      // AI CPU 自定义算子类型
INVALID = 0xFFFFFFFF,
};</pre>
</td>
</tr>
</tbody>
</table>

