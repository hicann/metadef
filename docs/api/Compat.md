# Compat<a name="ZH-CN_TOPIC_0000002269214069"></a>

## 函数功能<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section36583473819"></a>

检查入参的数值是否超过指定数据类型T所能表示的数值范围。

## 函数原型<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section13230182415108"></a>

**template<typename T1\>**

**static bool Compat\(const T1 v\)**

## 参数说明<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section75395119104"></a>

**表 1**  模板参数说明

<a name="table11905175217414"></a>
<table><thead align="left"><tr id="row169051521949"><th class="cellrowborder" valign="top" width="17.02%" id="mcps1.2.3.1.1"><p id="p7905152846"><a name="p7905152846"></a><a name="p7905152846"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="82.98%" id="mcps1.2.3.1.2"><p id="p1590518525413"><a name="p1590518525413"></a><a name="p1590518525413"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row159069521342"><td class="cellrowborder" valign="top" width="17.02%" headers="mcps1.2.3.1.1 "><p id="p159063529410"><a name="p159063529410"></a><a name="p159063529410"></a>T1</p>
</td>
<td class="cellrowborder" valign="top" width="82.98%" headers="mcps1.2.3.1.2 "><p id="p538831121318"><a name="p538831121318"></a><a name="p538831121318"></a><span>表示需要检查的数值类型。支持有符号整型和无符号整型，例如：int64_t、uint32_t</span>等。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  参数说明

<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p10223674448"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p10223674448"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p645511218169"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p645511218169"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p1922337124411"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p1922337124411"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p51918481213"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p51918481213"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p51918481213"></a>v</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p191819441211"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p191819441211"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p16171244128"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p16171244128"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p16171244128"></a><span>需要检查的数值，类型为</span>T1。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section25791320141317"></a>

返回bool类型：

-   如果数值v在数据类型T的表示范围内，返回true。
-   如果数值v超出数据类型T的表示范围，返回false。

## 约束说明<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001586355282_zh-cn_topic_0000001340364674_section320753512363"></a>

```
const int64_t value = XXX;
if (!ge::IntegerChecker<int32_t>::Compat(value)) {
   // 报错
}
```

