# SetExpandDimsRule<a name="ZH-CN_TOPIC_0000001711762529"></a>

## 函数功能<a name="section13070512"></a>

设置补维规则。补维是指在原有shape的基础上，添加一到多个维度。例如原shape\[2,2\]有两根轴，那么在两根轴中间补两维后的shape为\[2,1,1,2\]，补维后shape的第0、3根轴被称为原始轴，第1、2根轴被称为补维轴。

通过1和0描述补维规则，1代表当前轴为补维轴，0代表当前轴为原始轴，从左到右依次代表当前shape每根轴的来源，例如：

**表 1**  补维规则示例

<a name="table1537314214467"></a>
<table><thead align="left"><tr id="row19373024463"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p037319264618"><a name="p037319264618"></a><a name="p037319264618"></a>补维规则</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1337310218466"><a name="p1337310218466"></a><a name="p1337310218466"></a>补维前shape</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p537392174611"><a name="p537392174611"></a><a name="p537392174611"></a>补维后shape</p>
</th>
</tr>
</thead>
<tbody><tr id="row113731725465"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4373112174612"><a name="p4373112174612"></a><a name="p4373112174612"></a>0110</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p737320224616"><a name="p737320224616"></a><a name="p737320224616"></a>[2, 2]</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1537312214466"><a name="p1537312214466"></a><a name="p1537312214466"></a>[2, 1, 1, 2]</p>
</td>
</tr>
<tr id="row837312213464"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p9373172194618"><a name="p9373172194618"></a><a name="p9373172194618"></a>100</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p33731320467"><a name="p33731320467"></a><a name="p33731320467"></a>[2, 3]</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p19374728461"><a name="p19374728461"></a><a name="p19374728461"></a>[1, 2, 3]</p>
</td>
</tr>
<tr id="row11374321463"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1737492144618"><a name="p1737492144618"></a><a name="p1737492144618"></a>1000</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p11374162104614"><a name="p11374162104614"></a><a name="p11374162104614"></a>[2, 3]</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p73748294618"><a name="p73748294618"></a><a name="p73748294618"></a>补维规则与补维前shape不匹配，规则指定原始轴有3根，但原始shape只有2根轴，补维报错。</p>
</td>
</tr>
</tbody>
</table>

GE框架对外提供指定运行时格式（整网的输入输出节点的运行时格式）的能力，用于减少不必要的格式转换开销，获取更大的性能收益。开发者自行指定运行时格式的场景下，有两种方式来设置配套的运行时shape：

-   开发者自行指定运行时shape。
-   **框架推导运行时shape，此时，如果原始shape维度小于原始格式表达的维度，需要通过该接口同步设置补维规则，框架侧基于该补维规则设置运行时的shape。**

## 函数原型<a name="section12173916170"></a>

```
void SetExpandDimsRule(const AscendString &expand_dims_rule)
```

## 参数说明<a name="section50525752"></a>

<a name="table32237730"></a>
<table><thead align="left"><tr id="row54443429"><th class="cellrowborder" valign="top" width="23.69%" id="mcps1.1.4.1.1"><p id="p47841633"><a name="p47841633"></a><a name="p47841633"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="11.66%" id="mcps1.1.4.1.2"><p id="p49967061"><a name="p49967061"></a><a name="p49967061"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="64.64999999999999%" id="mcps1.1.4.1.3"><p id="p7092232"><a name="p7092232"></a><a name="p7092232"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row37599894"><td class="cellrowborder" valign="top" width="23.69%" headers="mcps1.1.4.1.1 "><p id="p7442104021410"><a name="p7442104021410"></a><a name="p7442104021410"></a>expand_dims_rule</p>
</td>
<td class="cellrowborder" valign="top" width="11.66%" headers="mcps1.1.4.1.2 "><p id="p720995"><a name="p720995"></a><a name="p720995"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="64.64999999999999%" headers="mcps1.1.4.1.3 "><p id="p19727653161815"><a name="p19727653161815"></a><a name="p19727653161815"></a>需设置的补维规则。AscendString类型。</p>
<p id="p10997104121911"><a name="p10997104121911"></a><a name="p10997104121911"></a>使用样例：原始shape为[2，3]，原始格式为NCHW，原始shape的维度（2）小于NCHW的维度（4），需要设置补维规则。</p>
<p id="p32830290"><a name="p32830290"></a><a name="p32830290"></a>比如，补维规则设置为“0110”，补维后shape为[2，1，1，3]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section52078584"></a>

无。

## 异常处理<a name="section66054074"></a>

无。

## 约束说明<a name="section57615760"></a>

无。

