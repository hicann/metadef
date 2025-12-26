# TensorPlacementUtils<a name="ZH-CN_TOPIC_0000002042527118"></a>

## 函数功能<a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_section36583473819"></a>

提供一组函数，判断TensorPlacement的位置。

## 函数原型<a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_section13230182415108"></a>

```
class TensorPlacementUtils {
 public:
  // 判断Tensor是否位于Device上的内存
  static bool IsOnDevice(TensorPlacement placement) {
    ...
  }
  // 判断Tensor是否位于Host上
  static bool IsOnHost(TensorPlacement placement) {
    ...
  }
  // 判断Tensor是否位于Host上，且数据紧跟在结构体后面
  static bool IsOnHostFollowing(TensorPlacement placement) {
    ...
  }
  // 判断Tensor是否位于Host上，且数据不紧跟在结构体后面
  static bool IsOnHostNotFollowing(TensorPlacement placement) {
    ...
  }
  // 判断Tensor是否位于Device上的内存
  static bool IsOnDeviceHbm(TensorPlacement placement) {
    ...
  }
  // 判断Tensor是否位于Device上的P2p内存
  static bool IsOnDeviceP2p(TensorPlacement placement) {
    ...
  }
};
```

## 参数说明<a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_section75395119104"></a>

<a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p10223674448"><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p10223674448"></a><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p645511218169"><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p645511218169"></a><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p1922337124411"><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p1922337124411"></a><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p865117470342"><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p865117470342"></a><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p865117470342"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p796912238145"><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p796912238145"></a><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p796912238145"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p14151132861"><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p14151132861"></a><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p14151132861"></a>需要进行判断的TensorPlacement枚举。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_section25791320141317"></a>

true表示是；false表示不是。

## 约束说明<a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_section320753512363"></a>

```
TensorData tensor_data;
tensor_data.SetPlacement(TensorPlacement::kOnHost);
auto on_host = TensorPlacementUtils::IsOnHost(tensor_data.GetPlacement()); // on_host is true
```

