# SetBlockDim<a name="ZH-CN_TOPIC_0000002078486185"></a>

## 函数功能<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section36583473819"></a>

设置blockDim，即参与计算的Vector或者Cube核数。

## 函数原型<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section13230182415108"></a>

**ge::graphStatus SetBlockDim\(const uint32\_t block\_dim\)**

## 参数说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section75395119104"></a>

<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p10223674448"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p10223674448"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p645511218169"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p645511218169"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p1922337124411"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p1922337124411"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p2340183613156"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p2340183613156"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p2340183613156"></a>block_dim</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p143401361158"><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p143401361158"></a><a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><p id="p1859517616525"><a name="p1859517616525"></a><a name="p1859517616525"></a>blockDim是逻辑核的概念，取值范围为[1,65535]。为了充分利用硬件资源，一般设置为物理核的核数或其倍数。</p>
<a name="zh-cn_topic_0000001576727157_ul597574610319"></a><a name="zh-cn_topic_0000001576727157_ul597574610319"></a><ul id="zh-cn_topic_0000001576727157_ul597574610319"><li>对于耦合模式和分离模式，blockDim在运行时的意义和设置规则有一些区别，具体说明如下：<a name="ul1227271711522"></a><a name="ul1227271711522"></a><ul id="ul1227271711522"><li>耦合模式：由于其Vector、Cube单元是集成在一起的，blockDim用于设置启动多个AICore核实例执行，不区分Vector、Cube。AI Core的核数可以通过GetCoreNumAiv或者GetCoreNumAic获取。</li><li>分离模式<a name="zh-cn_topic_0000001576727157_ul18712432194119"></a><a name="zh-cn_topic_0000001576727157_ul18712432194119"></a><ul id="zh-cn_topic_0000001576727157_ul18712432194119"><li>针对仅包含Vector计算的算子，blockDim用于设置启动多少个Vector（AIV）实例执行，比如某款AI处理器上有40个Vector核，建议设置为40。</li><li>针对仅包含Cube计算的算子，blockDim用于设置启动多少个Cube（AIC）实例执行，比如某款AI处理器上有20个Cube核，建议设置为20。</li><li>针对Vector/Cube融合计算的算子，启动时，按照AIV和AIC组合启动，blockDim用于设置启动多少个组合执行，比如某款AI处理器上有40个Vector核和20个Cube核，一个组合是2个Vector核和1个Cube核，建议设置为20，此时会启动20个组合，即40个Vector核和20个Cube核。<strong id="zh-cn_topic_0000001576727157_b15942142918492"><a name="zh-cn_topic_0000001576727157_b15942142918492"></a><a name="zh-cn_topic_0000001576727157_b15942142918492"></a>注意：该场景下，设置的blockDim逻辑核的核数不能超过物理核（2个Vector核和1个Cube核组合为1个物理核）的核数。</strong></li><li>AIC/AIV的核数分别通过GetCoreNumAic和GetCoreNumAiv接口获取。</li></ul>
</li></ul>
</li><li>在设置Device资源限制的场景下，设置的blockDim核数不能超过通过GetCoreNumAiv等接口获取的物理核数。例如，如果使用aclrtSetStreamResLimit设置Stream级别的Device资源限制为8个核，那么blockDim不能超过8，否则会抢占其他Stream的资源，导致资源限制失效。</li><li>如果开发者使用了Device资源限制特性，那么算子设置的blockDim不应超过PlatformAscendC提供核数的API（GetCoreNum/GetCoreNumAic/GetCoreNumAiv等）返回的核数。例如，使用aclrtSetStreamResLimit设置Stream级别的Vector核数为8，那么GetCoreNumAiv接口返回值为8，针对Vector算子设置的blockDim不应超过8，否则会抢占其他Stream的资源，导致资源限制失效。</li></ul>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section19165124931511"></a>

无。

## 调用示例<a name="zh-cn_topic_0000001576727157_zh-cn_topic_0000001389787301_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetBlockDim(32);
  // ...
}
```

