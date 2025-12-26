# MemBlock构造函数和析构函数<a name="ZH-CN_TOPIC_0000001600456724"></a>

## 函数功能<a name="zh-cn_topic_0204328165_zh-cn_topic_0182636384_section36893359"></a>

MemBlock构造函数和析构函数。

## 函数原型<a name="zh-cn_topic_0204328165_zh-cn_topic_0182636384_section136951948195410"></a>

```
MemBlock(Allocator &allocator, void *addr, size_t block_size)
: allocator_(allocator), addr_(addr), count_(1U), block_size_(block_size) {}
virtual ~MemBlock() = default
```

## 参数说明<a name="zh-cn_topic_0204328165_zh-cn_topic_0182636384_section63604780"></a>

<a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_table1802150"></a>
<table><thead align="left"><tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row32153279"><th class="cellrowborder" valign="top" width="19.08%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p54278838"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p34509720"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="61.980000000000004%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p60079171"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row34574683"><td class="cellrowborder" valign="top" width="19.08%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p49085952"></a>allocator</p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p16539161"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="61.980000000000004%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p65514185"></a>用户根据<a href="Allocator.md">Allocator</a>派生的类的引用。</p>
</td>
</tr>
<tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row52756755"><td class="cellrowborder" valign="top" width="19.08%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p45438767"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p45438767"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p45438767"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p56661507"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p56661507"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p56661507"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="61.980000000000004%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p12276181811190"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p12276181811190"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p12276181811190"></a>device内存地址。</p>
</td>
</tr>
<tr id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_row25854119"><td class="cellrowborder" valign="top" width="19.08%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p13808900"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p13808900"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p13808900"></a>block_size</p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p44779134"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p44779134"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p44779134"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="61.980000000000004%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p285824051918"><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p285824051918"></a><a name="zh-cn_topic_0204328235_zh-cn_topic_0182636399_p285824051918"></a>device内存addr的大小。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="zh-cn_topic_0204328165_zh-cn_topic_0182636384_section35572112"></a>

MemBlock构造函数返回MemBlock类型的对象。

## 异常处理<a name="zh-cn_topic_0204328165_zh-cn_topic_0182636384_section51713556"></a>

无。

## 约束说明<a name="zh-cn_topic_0204328165_zh-cn_topic_0182636384_section62768825"></a>

用户继承[Allocator](Allocator.md)后，申请内存需要返回MemBlock类型指针，用户只需按构造函数构造MemBlock对象即可，析构函数根据用户需求可以自定义，避免内存泄露。

