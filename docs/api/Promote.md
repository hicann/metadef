# Promote<a name="ZH-CN_TOPIC_0000001878068781"></a>

## 函数功能<a name="section8062655"></a>

Promote类用于表示输出数据类型为输入或属性指定的数据类型间的提升类型。

## 函数原型<a name="section5455038"></a>

```
class Promote {
 public:
  Promote(const std::initializer_list<const char *> &syms);
  std::vector<const char *> Syms() const; // 返回参与类型提升的符号名
  Promote(const Promote &other) = delete;
  Promote &operator=(const Promote &other) = delete;
  Promote(Promote &&other) noexcept;
  Promote &operator=(Promote &&other) noexcept;
 private:
  std::shared_ptr<void> data_;
};
```

## 参数说明<a name="section49095346"></a>

<a name="table62441623"></a>
<table><thead align="left"><tr id="row47897641"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.4.1.1"><p id="p54503731"><a name="p54503731"></a><a name="p54503731"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="20.842084208420843%" id="mcps1.1.4.1.2"><p id="p52726081"><a name="p52726081"></a><a name="p52726081"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="63.316331633163315%" id="mcps1.1.4.1.3"><p id="p42954172"><a name="p42954172"></a><a name="p42954172"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row56735883"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.4.1.1 "><p id="p16154261330"><a name="p16154261330"></a><a name="p16154261330"></a>syms</p>
</td>
<td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.4.1.2 "><p id="p1998218473411"><a name="p1998218473411"></a><a name="p1998218473411"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="63.316331633163315%" headers="mcps1.1.4.1.3 "><p id="p58370887"><a name="p58370887"></a><a name="p58370887"></a>参与提升的类型符号列表。</p>
<p id="p30421379"><a name="p30421379"></a><a name="p30421379"></a>符号包括输入类型的符号或者属性指定的符号。</p>
</td>
</tr>
<tr id="row7240111720414"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.4.1.1 "><p id="p1024113171418"><a name="p1024113171418"></a><a name="p1024113171418"></a>other</p>
</td>
<td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.4.1.2 "><p id="p12241417184114"><a name="p12241417184114"></a><a name="p12241417184114"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="63.316331633163315%" headers="mcps1.1.4.1.3 "><p id="p024119171415"><a name="p024119171415"></a><a name="p024119171415"></a>另一个Promote对象。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section35572112"></a>

无。

## 异常处理<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636384_section62768825"></a>

无。

