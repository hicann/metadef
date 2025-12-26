# GetParseSubgraphPostFn<a name="ZH-CN_TOPIC_0000002079199857"></a>

## 函数功能<a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328201_section8722525"></a>

根据算子类型，获取算子注册的子图中输入输出节点跟算子的输入输出的对应关系实现的函数对象。

## 函数原型<a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328201_section11393865"></a>

> [!NOTE]说明 
>GetParseSubgraphPostFn\(\)函数后续版本将废弃，建议使用GetParseSubgraphPostFn\(ParseSubgraphFuncV2 &func\)函数。

-   **ParseSubgraphFunc GetParseSubgraphPostFn\(\) const**

    该函数会返回ParseSubgraphFunc类型的函数对象，ParseSubgraphFunc函数的声明如下：

    ```
    using ParseSubgraphFunc = std::function<Status(const std::string &subgraph_name, const ge::Graph &graph)>
    ```

-   **Status GetParseSubgraphPostFn\(ParseSubgraphFuncV2 &func\) const**

    该函数会返回ParseSubgraphFuncV2类型的函数对象，ParseSubgraphFuncV2函数的声明如下：

    ```
    using ParseSubgraphFuncV2 = std::function<Status(const ge::AscendString &subgraph_name, const ge::Graph &graph)>
    ```

## 参数说明<a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328201_section35435929"></a>

-   GetParseSubgraphPostFn\(\)函数

    无。

-   GetParseSubgraphPostFn\(ParseSubgraphFuncV2 &func\)函数

    <a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_table62872389"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_row66002319"><th class="cellrowborder" valign="top" width="31.633163316331636%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p44587619"><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p44587619"></a><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p44587619"></a>参数</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.992199219921993%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p54827416"><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p54827416"></a><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p54827416"></a>输入/输出</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.374637463746375%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p11835734"><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p11835734"></a><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p11835734"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_row19170372"><td class="cellrowborder" valign="top" width="31.633163316331636%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001312711225_p0166203312249"><a name="zh-cn_topic_0000001312711225_p0166203312249"></a><a name="zh-cn_topic_0000001312711225_p0166203312249"></a>func</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.992199219921993%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p14800081"><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p14800081"></a><a name="zh-cn_topic_0000001312711225_zh-cn_topic_0204328255_p14800081"></a>输出</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.374637463746375%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001312711225_p97811246258"><a name="zh-cn_topic_0000001312711225_p97811246258"></a><a name="zh-cn_topic_0000001312711225_p97811246258"></a>实现算子注册的子图中输入输出节点跟算子的输入输出对应关系的函数对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

## 约束说明<a name="zh-cn_topic_0000001312711225_section1386084611573"></a>

无。

