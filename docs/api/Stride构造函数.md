# Stride构造函数<a name="ZH-CN_TOPIC_0000002518460593"></a>

## 函数功能<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section36583473819"></a>

Stride构造函数。

## 函数原型<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section13230182415108"></a>

下文中的dim\_num\_为维度个数，即有几维；strides\_为具体的步长信息。

-   默认构造一个Stride对象，默认构造的Stride对象中，dim\_num\_长度为0。

    ```
    Stride() : dim_num_(0), strides_{0}
    ```

-   通过strides\_值构造Stride，例如：Stride\(\{18,9,3,1\}\)表示创建一个Stride对象，Stride对象有4个维度，每个维度的步长分别是18,9,3,1。

    ```
    Stride(const std::initializer_list<int64_t> &args) : Stride()
    ```

-   拷贝构造，为了提升性能，strides\_超过源Stride对象 dim\_num\_的空间没有拷贝，可能有脏数据。

    ```
    Stride(const Stride &other)
    ```

-   拷贝赋值，为了提升性能，strides\_超过源Stride对象 dim\_num\_的空间没有拷贝，可能有脏数据。

    ```
    Stride &operator=(const Stride &other)
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
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p16171244128"><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p16171244128"></a><a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_p16171244128"></a>Stride对象的所有步长值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001634064981_row749918319554"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001634064981_p18499193145518"><a name="zh-cn_topic_0000001634064981_p18499193145518"></a><a name="zh-cn_topic_0000001634064981_p18499193145518"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001634064981_p10499193165511"><a name="zh-cn_topic_0000001634064981_p10499193165511"></a><a name="zh-cn_topic_0000001634064981_p10499193165511"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001634064981_p17484192115554"><a name="zh-cn_topic_0000001634064981_p17484192115554"></a><a name="zh-cn_topic_0000001634064981_p17484192115554"></a>源Stride对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section25791320141317"></a>

生成一个初始化的Stride对象。

## 约束说明<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001634064981_zh-cn_topic_0000001339718178_section320753512363"></a>

```
Stride stride({3, 256, 256}); // dim_num_=3  strides_描述张量的前三维的步长为3,256,256
```

