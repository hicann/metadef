# CreateFollowing<a name="ZH-CN_TOPIC_0000002486260730"></a>

## 函数功能<a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_section36583473819"></a>

创建一个指定数据类型以及大小的Tensor，其数据在TensorV2对象后连续排布。

## 函数原型<a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_section13230182415108"></a>

-   传入元素个数和数据类型，创建Tensor

    ```
    static std::unique_ptr<uint8_t[]> CreateFollowing(const int64_t shape_size, const ge::DataType dt, size_t &total_size)
    ```

-   传入数据类型和Tensor长度，创建Tensor

    ```
    static std::unique_ptr<uint8_t[]> CreateFollowing(const ge::DataType dt, const size_t tensor_size, size_t &total_size)
    ```

## 参数说明<a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_section75395119104"></a>

**表 1**  参数说明（传入元素个数和数据类型，创建Tensor）

<a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p10223674448"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p10223674448"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p645511218169"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p645511218169"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p1922337124411"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p1922337124411"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p2340183613156"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p2340183613156"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p2340183613156"></a>shape_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p143401361158"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p143401361158"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p19544204917121"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p19544204917121"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p19544204917121"></a>元素个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_row1373295819193"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p4732135801918"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p4732135801918"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p4732135801918"></a>dt</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p073218586199"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p073218586199"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p073218586199"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p1973245818195"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p1973245818195"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p1973245818195"></a>数据类型，<a href="DataType.md">DataType</a>类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_row1953018872015"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p453010811204"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p453010811204"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p453010811204"></a>total_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p129315474138"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p129315474138"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p129315474138"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p35316852019"><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p35316852019"></a><a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_p35316852019"></a>创建出的Tensor在内存中的长度。包含Tensor对象的长度和Tensor数据的长度。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  参数说明（传入数据类型和Tensor长度，创建Tensor）

<a name="zh-cn_topic_0000001642694565_table137001916182710"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001642694565_row11700141615270"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001642694565_p127003165274"><a name="zh-cn_topic_0000001642694565_p127003165274"></a><a name="zh-cn_topic_0000001642694565_p127003165274"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001642694565_p13700161662715"><a name="zh-cn_topic_0000001642694565_p13700161662715"></a><a name="zh-cn_topic_0000001642694565_p13700161662715"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001642694565_p9700111614272"><a name="zh-cn_topic_0000001642694565_p9700111614272"></a><a name="zh-cn_topic_0000001642694565_p9700111614272"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001642694565_row18700171662711"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001642694565_p20700131613271"><a name="zh-cn_topic_0000001642694565_p20700131613271"></a><a name="zh-cn_topic_0000001642694565_p20700131613271"></a>dt</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001642694565_p970118166276"><a name="zh-cn_topic_0000001642694565_p970118166276"></a><a name="zh-cn_topic_0000001642694565_p970118166276"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001642694565_p270171642712"><a name="zh-cn_topic_0000001642694565_p270171642712"></a><a name="zh-cn_topic_0000001642694565_p270171642712"></a>数据类型，<a href="DataType.md">DataType</a>类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001642694565_row10760155502720"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001642694565_p16760255132710"><a name="zh-cn_topic_0000001642694565_p16760255132710"></a><a name="zh-cn_topic_0000001642694565_p16760255132710"></a>tensor_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001642694565_p0760155522718"><a name="zh-cn_topic_0000001642694565_p0760155522718"></a><a name="zh-cn_topic_0000001642694565_p0760155522718"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001642694565_p27606557279"><a name="zh-cn_topic_0000001642694565_p27606557279"></a><a name="zh-cn_topic_0000001642694565_p27606557279"></a>Tensor数据的长度。单位为字节。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001642694565_row1970118167278"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001642694565_p570111682715"><a name="zh-cn_topic_0000001642694565_p570111682715"></a><a name="zh-cn_topic_0000001642694565_p570111682715"></a>total_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001642694565_p14701121615275"><a name="zh-cn_topic_0000001642694565_p14701121615275"></a><a name="zh-cn_topic_0000001642694565_p14701121615275"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001642694565_p1670114161273"><a name="zh-cn_topic_0000001642694565_p1670114161273"></a><a name="zh-cn_topic_0000001642694565_p1670114161273"></a>创建出的Tensor在内存中的长度。和tensor_size参数不同，total_size包含Tensor对象的长度和Tensor数据的长度。单位为字节。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_section25791320141317"></a>

创建的Tensor指针。

## 约束说明<a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001642694565_zh-cn_topic_0000001389831781_section320753512363"></a>

```
size_t total_size;
auto tensor_holder = TensorV2::CreateFollowing(32, ge::DataType::DT_INT8, total_size);
```

