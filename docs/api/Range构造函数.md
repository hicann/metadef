# Range构造函数<a name="ZH-CN_TOPIC_0000002042368734"></a>

## 函数功能<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_section36583473819"></a>

Range构造函数，对应如下3种构造方法：

-   可以默认构造一个上下界为nullptr的range实例;
-   也可以构造一个通过指定上下界的range实例;
-   还可以只传入一个任意类型的指针构造一个上下界相同的range实例。

## 函数原型<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_section13230182415108"></a>

```
Range() // 默认构造函数，上下界均为空指针
Range(T *min, T* max) : min_(min), max_(max) // 用户指定上界max，下界min
explicit Range(T *same_ele) : min_(same_ele), max_(same_ele) // 上下界均为same_ele
```

## 参数说明<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_section75395119104"></a>

<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p10223674448"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p10223674448"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p645511218169"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p645511218169"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p1922337124411"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p1922337124411"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p51918481213"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p51918481213"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p51918481213"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p191819441211"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p191819441211"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p16171244128"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p16171244128"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p16171244128"></a>下界的指针，类型为T*。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_row11511195195217"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p127621656105218"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p127621656105218"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p127621656105218"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p976235614521"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p976235614521"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p976235614521"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p776225685219"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p776225685219"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p776225685219"></a>上界的指针，类型为T*。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_row106181568532"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p06188675314"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p06188675314"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p06188675314"></a>same_ele</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p2061866195312"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p2061866195312"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p2061866195312"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p66181964532"><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p66181964532"></a><a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_p66181964532"></a>构造相同上下界range实例时使用，上下界均使用same_ele赋值，类型为T*。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_section25791320141317"></a>

返回用户指定构造的range对象。

## 约束说明<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001602766098_zh-cn_topic_0000001646166109_section320753512363"></a>

```
// 1. 默认构造
Range<int> range1; // 上下界均为nullptr
// 2. 用户指定上下界
int min = 0;
int max = 1024;
Range<int> range2(&min, &max); // 上界为1024，下界为0
// 3. 构造上下界相同的range
Range<int> range3(&min); // 上下界均为0
```

