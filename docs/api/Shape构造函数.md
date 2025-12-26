# Shape构造函数<a name="ZH-CN_TOPIC_0000002042527022"></a>

## 函数功能<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section36583473819"></a>

Shape构造函数。

## 函数原型<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section13230182415108"></a>

下文中的dim\_num\_为维度个数，即有几维；dims\_为具体的维度值信息。

-   默认构造一个shape，默认构造的shape实例中，dim\_num\_长度为0。

    ```
    Shape() : dim_num_(0), dims_{0}
    ```

-   通过dims\_值构造shape，例如：Shape\(\{8,3,224,224\}\)表示创建一个Shape实例，有4个维度，每个维度的值分别是8,3,224,224。

    ```
    Shape(const std::initializer_list<int64_t> &args) : Shape()
    ```

-   拷贝构造，为了提升性能，dims\_超过源Shape dim\_num\_的空间没有拷贝，可能有脏数据。

    ```
    Shape(const Shape &other)
    ```

-   拷贝赋值，为了提升性能，dims\_超过源Shape dim\_num\_的空间没有拷贝，可能有脏数据。

    ```
    Shape &operator=(const Shape &other)
    ```

## 参数说明<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section75395119104"></a>

<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p10223674448"><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p10223674448"></a><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p645511218169"><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p645511218169"></a><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p1922337124411"><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p1922337124411"></a><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p51918481213"><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p51918481213"></a><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p51918481213"></a>args</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p191819441211"><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p191819441211"></a><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p191819441211"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p16171244128"><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p16171244128"></a><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p16171244128"></a>shape的所有dim值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001634064981_row749918319554"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001634064981_p18499193145518"><a name="zh-cn_topic_0000001634064981_p18499193145518"></a><a name="zh-cn_topic_0000001634064981_p18499193145518"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001634064981_p10499193165511"><a name="zh-cn_topic_0000001634064981_p10499193165511"></a><a name="zh-cn_topic_0000001634064981_p10499193165511"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001634064981_p17484192115554"><a name="zh-cn_topic_0000001634064981_p17484192115554"></a><a name="zh-cn_topic_0000001634064981_p17484192115554"></a>源Shape对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section25791320141317"></a>

生成一个初始化的Shape对象。

## 约束说明<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section320753512363"></a>

```
Shape shape({3, 256, 256}); // dim_num_=3  dims_的前三维的维度为3,256,256
```

