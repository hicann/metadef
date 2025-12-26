# ge::graphStatus<a name="ZH-CN_TOPIC_0000002078447901"></a>

graphStatus类型即uint32\_t类型，其不同的状态说明如下：

<a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_table18159174418020"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_row3160044802"><th class="cellrowborder" valign="top" width="30.243024302430243%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p616015441700"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p616015441700"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p616015441700"></a>状态</p>
</th>
<th class="cellrowborder" valign="top" width="11.701170117011701%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p101601844601"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p101601844601"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p101601844601"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="58.055805580558065%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p1316016441704"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p1316016441704"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p1316016441704"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_row15160744305"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p12160134415015"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p12160134415015"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p12160134415015"></a>ge::GRAPH_SUCCESS</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p716004414012"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p716004414012"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p716004414012"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p61602441509"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p61602441509"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p61602441509"></a>对应函数执行成功。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_row61601344708"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p181600442004"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p181600442004"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p181600442004"></a>ge::GRAPH_FAILED</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p81608442020"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p81608442020"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p81608442020"></a>0xFFFFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p9160134415014"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p9160134415014"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p9160134415014"></a>对应函数执行失败。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_row13160444801"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p31607448017"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p31607448017"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p31607448017"></a>ge::GRAPH_PARAM_INVALID</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p9160134413017"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p9160134413017"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p9160134413017"></a>50331649</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p18817619259"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p18817619259"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p18817619259"></a>对应函数执行失败，执行时存在参数无法通过校验的情况。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_row13160204410015"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p216074414016"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p216074414016"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p216074414016"></a>ge::GRAPH_NOT_CHANGED</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p1716019441603"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p1716019441603"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p1716019441603"></a>1343242304</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p101607441302"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p101607441302"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p101607441302"></a>不符合常量折叠的条件时的错误码。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_row716015441307"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p21602044905"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p21602044905"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p21602044905"></a>ge::GRAPH_NODE_WITHOUT_CONST_INPUT</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p17160144415020"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p17160144415020"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p17160144415020"></a>50331648</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p61601444608"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p61601444608"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p61601444608"></a>检测到网络中的某个算子的输入没有const数据的场景。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_row1348264719"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p54833413116"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p54833413116"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p54833413116"></a>ge::GRAPH_NODE_NEED_REPASS</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p13483548112"><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p13483548112"></a><a name="zh-cn_topic_0000001600322793_zh-cn_topic_0000001341606836_p13483548112"></a>50331647</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p687618348475"><a name="p687618348475"></a><a name="p687618348475"></a>图节点需要被重新处理或遍历，常见于infershape阶段。</p>
</td>
</tr>
<tr id="row4961353917"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p12961035898"><a name="p12961035898"></a><a name="p12961035898"></a>ge::GRAPH_INVALID_IR_DEF</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p5961035897"><a name="p5961035897"></a><a name="p5961035897"></a>50331646</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p187643417471"><a name="p187643417471"></a><a name="p187643417471"></a>无效的IR定义。</p>
</td>
</tr>
<tr id="row383116367913"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p1783113361894"><a name="p1783113361894"></a><a name="p1783113361894"></a>ge::OP_WITHOUT_IR_DATATYPE_INFER_RULE</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p78313365916"><a name="p78313365916"></a><a name="p78313365916"></a>50331645</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p1087623417470"><a name="p1087623417470"></a><a name="p1087623417470"></a>算子缺少IR数据类型推断规则。</p>
</td>
</tr>
<tr id="row33035381595"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p7303238896"><a name="p7303238896"></a><a name="p7303238896"></a>ge::GRAPH_PARAM_OUT_OF_RANGE</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p33032381492"><a name="p33032381492"></a><a name="p33032381492"></a>50331644</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p188767346473"><a name="p188767346473"></a><a name="p188767346473"></a>函数参数的值超出了允许的有效范围。</p>
</td>
</tr>
<tr id="row18110401691"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p123405915"><a name="p123405915"></a><a name="p123405915"></a>ge::GRAPH_MEM_OPERATE_FAILED</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p1626401912"><a name="p1626401912"></a><a name="p1626401912"></a>50331539</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p11876834154713"><a name="p11876834154713"></a><a name="p11876834154713"></a>内存操作（如分配或释放）失败。</p>
</td>
</tr>
<tr id="row175491671015"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p13754616201012"><a name="p13754616201012"></a><a name="p13754616201012"></a>ge::GRAPH_NULL_PTR</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p975421621015"><a name="p975421621015"></a><a name="p975421621015"></a>50331538</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p8876113424714"><a name="p8876113424714"></a><a name="p8876113424714"></a>函数内部遇到了非法的空指针。</p>
</td>
</tr>
<tr id="row191621919108"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p1316121961020"><a name="p1316121961020"></a><a name="p1316121961020"></a>ge::GRAPH_MEMCPY_FAILED</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p216419121010"><a name="p216419121010"></a><a name="p216419121010"></a>50331537</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p19876113464715"><a name="p19876113464715"></a><a name="p19876113464715"></a>内存拷贝操作失败。</p>
</td>
</tr>
<tr id="row17656182213107"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p8656112216105"><a name="p8656112216105"></a><a name="p8656112216105"></a>ge::GRAPH_MEMSET_FAILED</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p3656622191011"><a name="p3656622191011"></a><a name="p3656622191011"></a>50331536</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p1287613345476"><a name="p1287613345476"></a><a name="p1287613345476"></a>内存设置操作失败。</p>
</td>
</tr>
<tr id="row6656922171019"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p1965614226107"><a name="p1965614226107"></a><a name="p1965614226107"></a>ge::GRAPH_MATH_CAL_FAILED</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p136561722161010"><a name="p136561722161010"></a><a name="p136561722161010"></a>50331429</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p2876153417475"><a name="p2876153417475"></a><a name="p2876153417475"></a>数学计算（如卷积、矩阵乘）失败。</p>
</td>
</tr>
<tr id="row11072621010"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p510826161013"><a name="p510826161013"></a><a name="p510826161013"></a>ge::GRAPH_ADD_OVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p3101826161017"><a name="p3101826161017"></a><a name="p3101826161017"></a>50331428</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p1887643412478"><a name="p1887643412478"></a><a name="p1887643412478"></a>加法运算结果溢出。</p>
</td>
</tr>
<tr id="row161014269109"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p2010152615103"><a name="p2010152615103"></a><a name="p2010152615103"></a>ge::GRAPH_MUL_OVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p18101826151012"><a name="p18101826151012"></a><a name="p18101826151012"></a>50331427</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p987653414470"><a name="p987653414470"></a><a name="p987653414470"></a>乘法运算结果溢出。</p>
</td>
</tr>
<tr id="row19105267103"><td class="cellrowborder" valign="top" width="30.243024302430243%" headers="mcps1.1.4.1.1 "><p id="p1410626161018"><a name="p1410626161018"></a><a name="p1410626161018"></a>ge::GRAPH_RoundUp_Overflow</p>
</td>
<td class="cellrowborder" valign="top" width="11.701170117011701%" headers="mcps1.1.4.1.2 "><p id="p1810926181020"><a name="p1810926181020"></a><a name="p1810926181020"></a>50331426</p>
</td>
<td class="cellrowborder" valign="top" width="58.055805580558065%" headers="mcps1.1.4.1.3 "><p id="p148766345471"><a name="p148766345471"></a><a name="p148766345471"></a>向上取整运算导致溢出。</p>
</td>
</tr>
</tbody>
</table>

