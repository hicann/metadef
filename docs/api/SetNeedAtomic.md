# SetNeedAtomic<a name="ZH-CN_TOPIC_0000002078486189"></a>

## 函数功能<a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_section36583473819"></a>

用于设置是否需要框架来完成atomic clean操作，保证在算子kernel执行前，输出内存已经被初始化。

atomic clean是指在算子执行前对GM（Global Memory）上输出内存进行初始化的过程，以确保累加、求最大值和求最小值等操作的正确性。

-   累加场景：在执行累加操作前，需要将全局内存中的相关值清零。
-   求最大值：在执行求最大值操作前，需要将全局内存中的相关值初始化为对应数据类型的最小值。
-   求最小值：在执行求最小值操作前，需要将全局内存中的相关值初始化为对应数据类型的最大值。

算子可以选择自行执行初始化操作，或者通过设置此接口让框架通过自动插入清零算子等方式来完成初始化操作。使用框架进行初始化可以利用框架的优化能力，例如在图模式下集中分配清零地址，从而提高资源管理和分配的效率。

**SetNeedAtomic和InitValue接口配合使用，通过InitValue接口来配置初始化哪些输出和具体的初始化值。**

## 函数原型<a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_section13230182415108"></a>

**ge::graphStatus SetNeedAtomic\(const bool atomic\)**

## 参数说明<a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_section75395119104"></a>

<a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_table111938719446"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_row6223476444"><th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p10223674448"><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p10223674448"></a><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p10223674448"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="15.340000000000002%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p645511218169"><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p645511218169"></a><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p645511218169"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="67.44%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p1922337124411"><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p1922337124411"></a><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p1922337124411"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_row152234713443"><td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p1170745414160"><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p1170745414160"></a><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p1170745414160"></a>atomic</p>
</td>
<td class="cellrowborder" valign="top" width="15.340000000000002%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p143401361158"><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p143401361158"></a><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_p143401361158"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="67.44%" headers="mcps1.1.4.1.3 "><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_ul8741445112413"></a><a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_ul8741445112413"></a><ul id="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_ul8741445112413"><li>true：需要做atomic clean。</li><li>false：不需要做atomic clean。</li></ul>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_section25791320141317"></a>

设置成功时返回“ge::GRAPH\_SUCCESS”。

关于graphStatus的定义，请参见[ge::graphStatus](ge-graphStatus.md)。

## 约束说明<a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_section19165124931511"></a>

SetNeedAtomic和InitValue接口配合使用，否则会出现初始化不生效的情况。

## 调用示例<a name="zh-cn_topic_0000001591204982_zh-cn_topic_0000001390027245_section320753512363"></a>

```
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetNeedAtomic(true);
  // ...
}
```

