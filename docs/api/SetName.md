# SetName<a name="ZH-CN_TOPIC_0000001265240898"></a>

## 函数功能<a name="section1919095241718"></a>

向TensorDesc中设置Tensor的名称。

## 函数原型<a name="section679315440172"></a>

> [!NOTE]说明 
>数据类型为string的接口后续版本会废弃，建议使用数据类型为非string的接口。

```
void SetName(const std::string &name)
void SetName(const char_t *name)
```

## 参数说明<a name="section732613016184"></a>

<a name="table17729965"></a>
<table><thead align="left"><tr id="row25940419"><th class="cellrowborder" valign="top" width="22.11%" id="mcps1.1.4.1.1"><p id="p20799233"><a name="p20799233"></a><a name="p20799233"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="23.84%" id="mcps1.1.4.1.2"><p id="p7016323"><a name="p7016323"></a><a name="p7016323"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="54.05%" id="mcps1.1.4.1.3"><p id="p64528501"><a name="p64528501"></a><a name="p64528501"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row59426101"><td class="cellrowborder" valign="top" width="22.11%" headers="mcps1.1.4.1.1 "><p id="p48784857"><a name="p48784857"></a><a name="p48784857"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="23.84%" headers="mcps1.1.4.1.2 "><p id="p59259338"><a name="p59259338"></a><a name="p59259338"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="54.05%" headers="mcps1.1.4.1.3 "><p id="p103391706126"><a name="p103391706126"></a><a name="p103391706126"></a>需设置的Tensor的名称。</p>
</td>
</tr>
</tbody>
</table>

## 返回值<a name="section176321777180"></a>

无。

## 异常处理<a name="section1647961061815"></a>

无。

## 约束说明<a name="section034617131188"></a>

无。

