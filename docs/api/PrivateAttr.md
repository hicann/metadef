# PrivateAttr<a name="ZH-CN_TOPIC_0000002042368858"></a>

## 函数功能<a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_section36583473819"></a>

用于注册算子的私有属性。

算子的属性包含属性名以及属性值。

通常情况下，注册算子的私有属性时用户需要同时指定私有属性的名字**private\_attr**以及该属性的值**private\_attr\_val**，此处称为场景一。但是考虑到算子可能已经存在某个属性的场景，因此也支持用户在设置该属性时只设置属性名的做法，称为场景二。所以提供了两种类型的注册函数，分别对应上述两种场景。

对于场景一，若算子已存在某个属性，且用户重新设置了该属性值，那么该算子的已有属性值将被用户注册的属性覆盖。

对于场景二，如果算子不存在某个属性，且用户仅设置了属性名，那么在后续获取算子私有属性列表流程时会存在该属性无法找到的错误。

## 函数原型<a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_section13230182415108"></a>

-   仅设置私有属性名的接口

    ```
    OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr)
    ```

-   同时设置属性名以及属性值的接口

    ```
    OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, int64_t private_attr_val)
    OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, const std::vector<int64_t> &private_attr_val)
    OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, const ge::char_t *private_attr_val)
    OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, ge::float32_t private_attr_val)
    OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, bool private_attr_val)
    OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, const std::vector<ge::float32_t> &private_attr_val)
    ```

## 参数说明<a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_section1695217571276"></a>

<a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p10223674448"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p10223674448"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p645511218169"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p645511218169"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p1922337124411"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p1922337124411"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p17770136956"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p17770136956"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p17770136956"></a>private_attr</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p167701536957"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p167701536957"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p167701536957"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p17695364517"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p17695364517"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p17695364517"></a>需要注册的私有属性名。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_row118751155183513"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p13999751165117"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p13999751165117"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p13999751165117"></a>private_attr_val</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p1875855143515"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p1875855143515"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p1875855143515"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p19688172220525"><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p19688172220525"></a><a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_p19688172220525"></a>需要注册的私有属性名对应的属性值。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_section25791320141317"></a>

返回算子的OpImplRegisterV2对象，该对象新增注册了私有属性。

## 约束说明<a name="zh-cn_topic_0000002071436357_zh-cn_topic_0000001397069429_section19165124931511"></a>

无。

