# 基础数据结构和接口列表<a name="ZH-CN_TOPIC_0000002079785425"></a>

本文档提供了进行算子开发和图开发时依赖的基础数据结构和接口说明，分类如下：

-   **ge（Graph Engine）** 命名空间

    ge是Graph Engine的缩写，代表一个通用的命名空间，专注于构图和图编译处理。此命名空间提供了一套丰富的API，用于构建和管理复杂的图结构。它的核心优势在于其通用性和灵活性，能够满足各种图处理需求，无论是在设计阶段还是在编译过程中。

-   **gert（GE Runtime）** 命名空间

    gert是GE Runtime的缩写，这个命名空间专门为运行时环境而设计，提供了一系列的高性能数据结构，以确保在执行时能够提供最佳性能。

-   **C接口**

    用于算子和图开发的C语言接口。

## gert命名空间<a name="section1498490112017"></a>

**表 1**  gert命名空间

<a name="table107281858237"></a>
<table><thead align="left"><tr id="row1372812592319"><th class="cellrowborder" valign="top" width="14.760000000000002%" id="mcps1.2.4.1.1"><p id="p28543193914"><a name="p28543193914"></a><a name="p28543193914"></a>分类</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.2.4.1.2"><p id="p147285552316"><a name="p147285552316"></a><a name="p147285552316"></a>数据结构/接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="65.75%" id="mcps1.2.4.1.3"><p id="p17281151239"><a name="p17281151239"></a><a name="p17281151239"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1972815510234"><td class="cellrowborder" rowspan="33" valign="top" width="14.760000000000002%" headers="mcps1.2.4.1.1 "><p id="p28542192920"><a name="p28542192920"></a><a name="p28542192920"></a>类和结构体</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.2.4.1.2 "><p id="p1363104074916"><a name="p1363104074916"></a><a name="p1363104074916"></a><a href="AnchorInstanceInfo.md">AnchorInstanceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.75%" headers="mcps1.2.4.1.3 "><p id="p14728115122318"><a name="p14728115122318"></a><a name="p14728115122318"></a>用来描述一个算子的IR原型定义的输入信息与实际输入之间的关系。</p>
<p id="p1414816528417"><a name="p1414816528417"></a><a name="p1414816528417"></a>头文件位于<span id="ph17279164704115"><a name="ph17279164704115"></a><a name="ph17279164704115"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/compute_node_info.h。</p>
</td>
</tr>
<tr id="row77297582318"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p163638404494"><a name="p163638404494"></a><a name="p163638404494"></a><a href="CompileTimeTensorDesc.md">CompileTimeTensorDesc</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001936566892_p16772114119230"><a name="zh-cn_topic_0000001936566892_p16772114119230"></a><a name="zh-cn_topic_0000001936566892_p16772114119230"></a>用于描述编译时的Tensor描述信息，包含dtype信息以及format信息。</p>
<p id="p162162021194310"><a name="p162162021194310"></a><a name="p162162021194310"></a>头文件位于<span id="ph52162219437"><a name="ph52162219437"></a><a name="ph52162219437"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/compute_node_info.h。</p>
</td>
</tr>
<tr id="row095531611435"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3363194034916"><a name="p3363194034916"></a><a name="p3363194034916"></a><a href="ComputeNodeInfo.md">ComputeNodeInfo</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001585966930_zh-cn_topic_0000001390567173_p167811575587"><a name="zh-cn_topic_0000001585966930_zh-cn_topic_0000001390567173_p167811575587"></a><a name="zh-cn_topic_0000001585966930_zh-cn_topic_0000001390567173_p167811575587"></a>用于将算子的相关编译信息进行序列化保存，以便可以在图执行阶段能够高效地获取这些信息。</p>
<p id="p1739943374312"><a name="p1739943374312"></a><a name="p1739943374312"></a>头文件位于<span id="ph93996332438"><a name="ph93996332438"></a><a name="ph93996332438"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/compute_node_info.h。</p>
</td>
</tr>
<tr id="row511511575710"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1211595719717"><a name="p1211595719717"></a><a name="p1211595719717"></a><a href="ContextHolder.md">ContextHolder</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p62581949594"><a name="p62581949594"></a><a name="p62581949594"></a>Context是算子Host侧实现函数执行时的上下文，由于构造出来的Context存储的都是指针类型，为了方便进行生命周期和所有权管理，提供ContextHolder类进行资源管理。</p>
<p id="p299611428818"><a name="p299611428818"></a><a name="p299611428818"></a>头文件位于<span id="ph179962423813"><a name="ph179962423813"></a><a name="ph179962423813"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/context_holder.h。</p>
</td>
</tr>
<tr id="row1698614591910"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p20363840134916"><a name="p20363840134916"></a><a name="p20363840134916"></a><a href="ContinuousVectorVector.md">ContinuousVectorVector</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p698612594920"><a name="p698612594920"></a><a name="p698612594920"></a>在内存中开辟一块连续的空间，用于存储数据的描述信息以及实际的数据元素，元素类型为ContinuousVector结构。</p>
<p id="p10301052164315"><a name="p10301052164315"></a><a name="p10301052164315"></a>头文件位于<span id="ph930135224314"><a name="ph930135224314"></a><a name="ph930135224314"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/continuous_vector.h。</p>
</td>
</tr>
<tr id="row204721719184318"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1236354013492"><a name="p1236354013492"></a><a name="p1236354013492"></a><a href="ContinuousVector.md">ContinuousVector</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001592855212_zh-cn_topic_0000001390366241_p12937161142617"><a name="zh-cn_topic_0000001592855212_zh-cn_topic_0000001390366241_p12937161142617"></a><a name="zh-cn_topic_0000001592855212_zh-cn_topic_0000001390366241_p12937161142617"></a>本类是一个POD类，在内存中开辟一块连续的空间用于存储描述信息以及实际内存数据。</p>
<p id="p10243172611443"><a name="p10243172611443"></a><a name="p10243172611443"></a>头文件位于<span id="ph924313263449"><a name="ph924313263449"></a><a name="ph924313263449"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/continuous_vector.h。</p>
</td>
</tr>
<tr id="row975519111306"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14756121133015"><a name="p14756121133015"></a><a name="p14756121133015"></a><a href="CtInferShapeContext.md">CtInferShapeContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18756151123013"><a name="p18756151123013"></a><a name="p18756151123013"></a><span id="ph2142149193117"><a name="ph2142149193117"></a><a name="ph2142149193117"></a>CtInferShapeContext继承自InferShapeContext，用于编译期Shape推导，提供编译期使用的接口。</span></p>
<p id="p637116304365"><a name="p637116304365"></a><a name="p637116304365"></a>头文件位于<span id="ph1189133053619"><a name="ph1189133053619"></a><a name="ph1189133053619"></a>CANN软件安装后文件存储路径</span>下的include/graph/ct_infer_shape_context.h。</p>
</td>
</tr>
<tr id="row167714413017"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4774419300"><a name="p4774419300"></a><a name="p4774419300"></a><a href="CtInferShapeRangeContext.md">CtInferShapeRangeContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p47724153013"><a name="p47724153013"></a><a name="p47724153013"></a><span id="ph393531633114"><a name="ph393531633114"></a><a name="ph393531633114"></a>CtInferShapeRangeContext继承自InferShapeRangeContext，用于编译期ShapeRange推导，提供编译期使用的接口。</span></p>
<p id="p698294611360"><a name="p698294611360"></a><a name="p698294611360"></a>头文件位于<span id="ph343494743610"><a name="ph343494743610"></a><a name="ph343494743610"></a>CANN软件安装后文件存储路径</span>下的include/graph/ct_infer_shape_range_context.h。</p>
</td>
</tr>
<tr id="row1263518197432"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1236314004917"><a name="p1236314004917"></a><a name="p1236314004917"></a><a href="ExpandDimsType.md">ExpandDimsType</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1163651916435"><a name="p1163651916435"></a><a name="p1163651916435"></a>ExpandDimsType类基于补维后的shape，描述了补维规则。</p>
<p id="p125632124514"><a name="p125632124514"></a><a name="p125632124514"></a>头文件位于<span id="ph725642118458"><a name="ph725642118458"></a><a name="ph725642118458"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/expand_dims_type.h。</p>
</td>
</tr>
<tr id="row1194312197431"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1363154014916"><a name="p1363154014916"></a><a name="p1363154014916"></a><a href="ExtendedKernelContext.md">ExtendedKernelContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1358715569312"><a name="p1358715569312"></a><a name="p1358715569312"></a><a href="InferShapeContext.md">InferShapeContext</a>、<a href="TilingContext.md">TilingContext</a>等的基类，ExtendedKernelContext中提供的方法如获取算子type、name、属性等接口均可以在InferShape、Tiling时调用。</p>
<p id="p2369165864520"><a name="p2369165864520"></a><a name="p2369165864520"></a>头文件位于<span id="ph2894185864514"><a name="ph2894185864514"></a><a name="ph2894185864514"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/extended_kernel_context.h。</p>
</td>
</tr>
<tr id="row11951420124314"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1736311404495"><a name="p1736311404495"></a><a name="p1736311404495"></a><a href="InferDataTypeContext.md">InferDataTypeContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1998216819332"><a name="p1998216819332"></a><a name="p1998216819332"></a>用于datatype推导的上下文结构。</p>
<p id="p737151114715"><a name="p737151114715"></a><a name="p737151114715"></a>头文件位于<span id="ph1740153214919"><a name="ph1740153214919"></a><a name="ph1740153214919"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/infer_datatype_context.h。</p>
</td>
</tr>
<tr id="row19906179401"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p69901317144012"><a name="p69901317144012"></a><a name="p69901317144012"></a><a href="InferFormatContext.md">InferFormatContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p199041714015"><a name="p199041714015"></a><a name="p199041714015"></a><span id="ph204111647174018"><a name="ph204111647174018"></a><a name="ph204111647174018"></a>InferFormatContext继承自ExtendedKernelContext，是一个用于Format推导的上下文类。</span></p>
<p id="p575414216416"><a name="p575414216416"></a><a name="p575414216416"></a>头文件位于<span id="ph102011743204118"><a name="ph102011743204118"></a><a name="ph102011743204118"></a>CANN软件安装后文件存储路径</span>下的</p>
<p id="p163841311104217"><a name="p163841311104217"></a><a name="p163841311104217"></a>include/graph/<span>infer_format_context.h</span>。</p>
</td>
</tr>
<tr id="row687313439911"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p036318401492"><a name="p036318401492"></a><a name="p036318401492"></a><a href="InferShapeContext.md">InferShapeContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p144251127203317"><a name="p144251127203317"></a><a name="p144251127203317"></a>用于shape推导的上下文结构。</p>
<p id="p139211474490"><a name="p139211474490"></a><a name="p139211474490"></a>头文件位于<span id="ph2069034764918"><a name="ph2069034764918"></a><a name="ph2069034764918"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/infer_shape_context.h。</p>
</td>
</tr>
<tr id="row1874810244362"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1736334018496"><a name="p1736334018496"></a><a name="p1736334018496"></a><a href="InferShapeRangeContext.md">InferShapeRangeContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1773814911334"><a name="p1773814911334"></a><a name="p1773814911334"></a>用于shape range推导的上下文结构。</p>
<p id="p321712055015"><a name="p321712055015"></a><a name="p321712055015"></a>头文件位于<span id="ph121782035019"><a name="ph121782035019"></a><a name="ph121782035019"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/infer_shape_range_context.h。</p>
</td>
</tr>
<tr id="row238911283125"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p173899283121"><a name="p173899283121"></a><a name="p173899283121"></a><a href="OpContextBuilderBase.md">OpContextBuilderBase</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1240295105711"><a name="p1240295105711"></a><a name="p1240295105711"></a>OpContextBuilderBase是各ContextBuilder的基类，用于构造子类context中算子信息，包括算子类型、名称、输入输出原型个数、输入输出实例个数、属性等信息。</p>
<p id="p152882514199"><a name="p152882514199"></a><a name="p152882514199"></a>头文件位于<span id="ph12288125113191"><a name="ph12288125113191"></a><a name="ph12288125113191"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/op_context_builder_base.h。</p>
</td>
</tr>
<tr id="row1291015249364"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1436374084910"><a name="p1436374084910"></a><a name="p1436374084910"></a><a href="OpImplRegisterV2.md">OpImplRegisterV2</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p791052483612"><a name="p791052483612"></a><a name="p791052483612"></a>OpImplRegisterV2类作为注册接口类，提供了一系列算子原型注册接口，供用户注册指定算子类型的Tiling函数、Infershape函数、私有属性等信息。用户调用算子原型注册接口进行注册时会间接使用到该类。</p>
<p id="p18746105165019"><a name="p18746105165019"></a><a name="p18746105165019"></a>头文件位于<span id="ph1577124115115"><a name="ph1577124115115"></a><a name="ph1577124115115"></a>CANN软件安装后文件存储路径</span>下的include/register/op_impl_registry.h。</p>
</td>
</tr>
<tr id="row526153215126"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p195254175131"><a name="p195254175131"></a><a name="p195254175131"></a><a href="OpInferDataTypeContextBuilder.md">OpInferDataTypeContextBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p28242032488"><a name="p28242032488"></a><a name="p28242032488"></a>OpInferDataTypeContextBuilder用于构建InferDataTypeContext 。构造出的Context在算子数据类型推导过程中作为入参，<span>用于获取必要的算子输入输出数据。推导完成后，结果会被写入回</span>上下文中。</p>
<p id="p934017349182"><a name="p934017349182"></a><a name="p934017349182"></a>头文件位于<span id="ph3569134419184"><a name="ph3569134419184"></a><a name="ph3569134419184"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/op_infer_datatype_context_builder.h。</p>
</td>
</tr>
<tr id="row7705834151210"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6948152101316"><a name="p6948152101316"></a><a name="p6948152101316"></a><a href="OpInferShapeContextBuilder.md">OpInferShapeContextBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9830105961317"><a name="p9830105961317"></a><a name="p9830105961317"></a>OpInferShapeContextBuilder用于构建InferShapeContext。构造出的Context在算子Shape推导过程中作为入参，<span>用于获取必要的算子输入输出数据。推导完成后，结果会被写入回</span>上下文中。</p>
<p id="p9682101617205"><a name="p9682101617205"></a><a name="p9682101617205"></a>头文件位于<span id="ph19682111672015"><a name="ph19682111672015"></a><a name="ph19682111672015"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/op_infer_shape_context_builder.h。</p>
</td>
</tr>
<tr id="row117031340171213"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4525317181314"><a name="p4525317181314"></a><a name="p4525317181314"></a><a href="OpInferShapeRangeContextBuilder.md">OpInferShapeRangeContextBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1664244510536"><a name="p1664244510536"></a><a name="p1664244510536"></a>OpInferShapeRangeContextBuilder用于构建InferShapeRangeContext。构造出的Context在算子ShapeRange推导过程中作为输入，<span>用于获取必要的算子输入输出数据。推导完成后，结果会被写回</span>上下文中。</p>
<p id="p04514512207"><a name="p04514512207"></a><a name="p04514512207"></a>头文件位于<span id="ph1545104510209"><a name="ph1545104510209"></a><a name="ph1545104510209"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/op_infer_shape_range_context_builder.h。</p>
</td>
</tr>
<tr id="row1467094219121"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p852519179132"><a name="p852519179132"></a><a name="p852519179132"></a><a href="OpKernelContextBuilder.md">OpKernelContextBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p344493161011"><a name="p344493161011"></a><a name="p344493161011"></a>用于构建一个通用的KernelContext对象，该上下文作为算子Host实现实际执行阶段的输入上下文。</p>
<p id="p17662181112119"><a name="p17662181112119"></a><a name="p17662181112119"></a>头文件位于<span id="ph7663611102114"><a name="ph7663611102114"></a><a name="ph7663611102114"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/op_kernel_run_context_builder.h。</p>
</td>
</tr>
<tr id="row2770184410123"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p0525111715136"><a name="p0525111715136"></a><a name="p0525111715136"></a><a href="OpTilingContextBuilder.md">OpTilingContextBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16770744111211"><a name="p16770744111211"></a><a name="p16770744111211"></a>OpTilingContextBuilder用于构建TilingContext。构造出的Context在算子Tiling计算过程中作为入参，<span>用于获取必要的算子输入输出等数据。Tiling计算完成后，结果会被写回</span>上下文中。</p>
<p id="p181391939182111"><a name="p181391939182111"></a><a name="p181391939182111"></a>头文件位于<span id="ph13139173912212"><a name="ph13139173912212"></a><a name="ph13139173912212"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/op_tiling_context_builder.h。</p>
</td>
</tr>
<tr id="row17393114861214"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p58025395135"><a name="p58025395135"></a><a name="p58025395135"></a><a href="OpTilingParseContextBuilder.md">OpTilingParseContextBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p187071637112213"><a name="p187071637112213"></a><a name="p187071637112213"></a>OpTilingParseContextBuilder用于构建TilingParseContext。构造出的Context在算子TilingParse计算过程中作为输入，<span>用于获取必要的算子输入输出数据。完成Parser计算后，结果会被写回到</span>上下文中。</p>
<p id="p164534942216"><a name="p164534942216"></a><a name="p164534942216"></a>头文件位于<span id="ph1745164992220"><a name="ph1745164992220"></a><a name="ph1745164992220"></a>CANN软件安装后文件存储路径</span>下的include/base/context_builder/op_tiling_parse_context_builder.h。</p>
</td>
</tr>
<tr id="row81121256363"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8363154016490"><a name="p8363154016490"></a><a name="p8363154016490"></a><a href="Range.md">Range</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p191131256368"><a name="p191131256368"></a><a name="p191131256368"></a>Range类用于描述一个对象的上下界。</p>
<p id="p136075135310"><a name="p136075135310"></a><a name="p136075135310"></a>头文件位于<span id="ph14360145155317"><a name="ph14360145155317"></a><a name="ph14360145155317"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/range.h。</p>
</td>
</tr>
<tr id="row152552025153613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3364104015490"><a name="p3364104015490"></a><a name="p3364104015490"></a><a href="RuntimeAttrs.md">RuntimeAttrs</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1325552515362"><a name="p1325552515362"></a><a name="p1325552515362"></a>用于保存算子属性。</p>
<p id="p41551913195420"><a name="p41551913195420"></a><a name="p41551913195420"></a>头文件位于<span id="ph15214197544"><a name="ph15214197544"></a><a name="ph15214197544"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/runtime_attrs.h。</p>
</td>
</tr>
<tr id="row104017250363"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2364174018498"><a name="p2364174018498"></a><a name="p2364174018498"></a><a href="Shape.md">Shape</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p389445174112"><a name="p389445174112"></a><a name="p389445174112"></a>Shape结构体用于描述一个tensor的shape。</p>
<p id="p029110085517"><a name="p029110085517"></a><a name="p029110085517"></a>头文件位于<span id="ph073715055514"><a name="ph073715055514"></a><a name="ph073715055514"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/shape.h。</p>
</td>
</tr>
<tr id="row855712515365"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5364194054910"><a name="p5364194054910"></a><a name="p5364194054910"></a><a href="StorageFormat.md">StorageFormat</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001339250874_p1775574215191"><a name="zh-cn_topic_0000001339250874_p1775574215191"></a><a name="zh-cn_topic_0000001339250874_p1775574215191"></a>StorageFormat格式包括原始格式、运行时格式、补维规则。</p>
<p id="p2584101005519"><a name="p2584101005519"></a><a name="p2584101005519"></a>头文件位于<span id="ph058421015511"><a name="ph058421015511"></a><a name="ph058421015511"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/storage_format.h。</p>
</td>
</tr>
<tr id="row19695152573617"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p133641540164918"><a name="p133641540164918"></a><a name="p133641540164918"></a><a href="StorageShape.md">StorageShape</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17348124922015"><a name="p17348124922015"></a><a name="p17348124922015"></a>该类描述了tensor的shape，包含两个信息：origin_shape以及storage_shape。</p>
<p id="p1069545111557"><a name="p1069545111557"></a><a name="p1069545111557"></a>头文件位于<span id="ph2069535155516"><a name="ph2069535155516"></a><a name="ph2069535155516"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/storage_shape.h。</p>
</td>
</tr>
<tr id="row15953122533617"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p133643406497"><a name="p133643406497"></a><a name="p133643406497"></a><a href="TensorData.md">TensorData</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1131469134319"><a name="p1131469134319"></a><a name="p1131469134319"></a>用于存储Tensor数据。</p>
<p id="p51058278561"><a name="p51058278561"></a><a name="p51058278561"></a>头文件位于<span id="ph1521013318566"><a name="ph1521013318566"></a><a name="ph1521013318566"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/tensor_data.h。</p>
</td>
</tr>
<tr id="row16141192653616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9364340204919"><a name="p9364340204919"></a><a name="p9364340204919"></a><a href="TensorPlacementUtils.md">TensorPlacementUtils</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p162284242318"><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p162284242318"></a><a name="zh-cn_topic_0000001957261985_zh-cn_topic_0000001390105721_p162284242318"></a>提供一组函数，用于判断TensorPlacement的位置。</p>
<p id="p582793175710"><a name="p582793175710"></a><a name="p582793175710"></a>头文件位于<span id="ph118271031155714"><a name="ph118271031155714"></a><a name="ph118271031155714"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/tensor_data.h。</p>
</td>
</tr>
<tr id="row977016176378"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13364104010495"><a name="p13364104010495"></a><a name="p13364104010495"></a><a href="Tensor.md">Tensor</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001633985549_zh-cn_topic_0000001339551770_p1350955724012"><a name="zh-cn_topic_0000001633985549_zh-cn_topic_0000001339551770_p1350955724012"></a><a name="zh-cn_topic_0000001633985549_zh-cn_topic_0000001339551770_p1350955724012"></a>Tensor类用来描述一个tensor对象的信息以及行为，包含：shape信息、format信息、datatype信息以及tensor数据内容tensordata。</p>
<p id="p1191185211579"><a name="p1191185211579"></a><a name="p1191185211579"></a>头文件位于<span id="ph1191115217575"><a name="ph1191115217575"></a><a name="ph1191115217575"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/tensor.h。</p>
</td>
</tr>
<tr id="row17935161713713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14364104017490"><a name="p14364104017490"></a><a name="p14364104017490"></a><a href="TilingContext.md">TilingContext</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8493179459"><a name="p8493179459"></a><a name="p8493179459"></a>用于算子Tiling的上下文结构。</p>
<p id="p1217510419583"><a name="p1217510419583"></a><a name="p1217510419583"></a>头文件位于<span id="ph417612410581"><a name="ph417612410581"></a><a name="ph417612410581"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/tiling_context.h。</p>
</td>
</tr>
<tr id="row138841816370"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9364540134916"><a name="p9364540134916"></a><a name="p9364540134916"></a><a href="TilingData-153.md">TilingData</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p158818183378"><a name="p158818183378"></a><a name="p158818183378"></a>用于存储Tiling数据。</p>
<p id="p135104117583"><a name="p135104117583"></a><a name="p135104117583"></a>头文件位于<span id="ph754411582"><a name="ph754411582"></a><a name="ph754411582"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/tiling_data.h。</p>
</td>
</tr>
<tr id="row193701818163720"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p175781844102711"><a name="p175781844102711"></a><a name="p175781844102711"></a><a href="TypedContinuousVector.md">TypedContinuousVector</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001592697028_zh-cn_topic_0000001390668229_p1952831015116"><a name="zh-cn_topic_0000001592697028_zh-cn_topic_0000001390668229_p1952831015116"></a><a name="zh-cn_topic_0000001592697028_zh-cn_topic_0000001390668229_p1952831015116"></a>本类继承自ContinuousVector类，与ContinuousVector类不同的是MutableData和GetData返回的是指定类型的地址，而不是void *。因此称为Typed。</p>
<p id="p1848995817227"><a name="p1848995817227"></a><a name="p1848995817227"></a>头文件位于<span id="ph6489858152213"><a name="ph6489858152213"></a><a name="ph6489858152213"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/continuous_vector.h。</p>
</td>
</tr>
<tr id="row61828281024"><td class="cellrowborder" valign="top" width="14.760000000000002%" headers="mcps1.2.4.1.1 "><p id="p818214281124"><a name="p818214281124"></a><a name="p818214281124"></a>枚举</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.2.4.1.2 "><p id="p1873693411213"><a name="p1873693411213"></a><a name="p1873693411213"></a><a href="TensorPlacement.md">TensorPlacement</a></p>
</td>
<td class="cellrowborder" valign="top" width="65.75%" headers="mcps1.2.4.1.3 "><p id="p673610345217"><a name="p673610345217"></a><a name="p673610345217"></a>表达Tensor存储位置的枚举值。</p>
<p id="p837174652313"><a name="p837174652313"></a><a name="p837174652313"></a>头文件位于<span id="ph84153466231"><a name="ph84153466231"></a><a name="ph84153466231"></a>CANN软件安装后文件存储路径</span>下的include/exe_graph/runtime/tensor_data.h。</p>
</td>
</tr>
</tbody>
</table>

## ge命名空间<a name="section1740161272017"></a>

**表 2**  ge命名空间

<a name="table14480302486"></a>
<table><thead align="left"><tr id="row24803013488"><th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.2.4.1.1"><p id="p548018014820"><a name="p548018014820"></a><a name="p548018014820"></a>分类</p>
</th>
<th class="cellrowborder" valign="top" width="27.139999999999997%" id="mcps1.2.4.1.2"><p id="p4481203481"><a name="p4481203481"></a><a name="p4481203481"></a>数据结构/接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="59.01%" id="mcps1.2.4.1.3"><p id="p74811602485"><a name="p74811602485"></a><a name="p74811602485"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row5481206480"><td class="cellrowborder" rowspan="12" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p148114034818"><a name="p148114034818"></a><a name="p148114034818"></a>类和结构体</p>
<p id="p554519315377"><a name="p554519315377"></a><a name="p554519315377"></a></p>
<p id="p1954518383719"><a name="p1954518383719"></a><a name="p1954518383719"></a></p>
<p id="p2546135375"><a name="p2546135375"></a><a name="p2546135375"></a></p>
<p id="p6546133143714"><a name="p6546133143714"></a><a name="p6546133143714"></a></p>
<p id="p854693153713"><a name="p854693153713"></a><a name="p854693153713"></a></p>
<p id="p2054611311371"><a name="p2054611311371"></a><a name="p2054611311371"></a></p>
<p id="p95464393715"><a name="p95464393715"></a><a name="p95464393715"></a></p>
<p id="p1254616333713"><a name="p1254616333713"></a><a name="p1254616333713"></a></p>
<p id="p154693193715"><a name="p154693193715"></a><a name="p154693193715"></a></p>
<p id="p1054653103715"><a name="p1054653103715"></a><a name="p1054653103715"></a></p>
<p id="p254611318377"><a name="p254611318377"></a><a name="p254611318377"></a></p>
<p id="p1154610393711"><a name="p1154610393711"></a><a name="p1154610393711"></a></p>
<p id="p3546831374"><a name="p3546831374"></a><a name="p3546831374"></a></p>
<p id="p854614310372"><a name="p854614310372"></a><a name="p854614310372"></a></p>
<p id="p154619318377"><a name="p154619318377"></a><a name="p154619318377"></a></p>
<p id="p1954653103710"><a name="p1954653103710"></a><a name="p1954653103710"></a></p>
<p id="p1954633133716"><a name="p1954633133716"></a><a name="p1954633133716"></a></p>
<p id="p654633113718"><a name="p654633113718"></a><a name="p654633113718"></a></p>
<p id="p6546183143717"><a name="p6546183143717"></a><a name="p6546183143717"></a></p>
<p id="p135464317373"><a name="p135464317373"></a><a name="p135464317373"></a></p>
<p id="p1754611320376"><a name="p1754611320376"></a><a name="p1754611320376"></a></p>
<p id="p16546134370"><a name="p16546134370"></a><a name="p16546134370"></a></p>
<p id="p1154610312375"><a name="p1154610312375"></a><a name="p1154610312375"></a></p>
<p id="p054616318379"><a name="p054616318379"></a><a name="p054616318379"></a></p>
<p id="p175466318377"><a name="p175466318377"></a><a name="p175466318377"></a></p>
</td>
<td class="cellrowborder" valign="top" width="27.139999999999997%" headers="mcps1.2.4.1.2 "><p id="p10300450124817"><a name="p10300450124817"></a><a name="p10300450124817"></a><a href="Allocator.md">Allocator</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.01%" headers="mcps1.2.4.1.3 "><p id="p20841143419248"><a name="p20841143419248"></a><a name="p20841143419248"></a>支持使用用户注册的外置allocator功能。</p>
<p id="p96413389126"><a name="p96413389126"></a><a name="p96413389126"></a>头文件位于<span id="ph274811571976"><a name="ph274811571976"></a><a name="ph274811571976"></a>CANN软件安装后文件存储路径</span>下的include/ge/ge_allocator.h。</p>
</td>
</tr>
<tr id="row1548180104818"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p173001450114810"><a name="p173001450114810"></a><a name="p173001450114810"></a><a href="AscendString.md">AscendString</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p961334812588"><a name="p961334812588"></a><a name="p961334812588"></a>用于存储字符串。</p>
<a name="ul28571154153311"></a><a name="ul28571154153311"></a><ul id="ul28571154153311"><li>头文件位于<span id="ph16330347101515"><a name="ph16330347101515"></a><a name="ph16330347101515"></a>CANN软件安装后文件存储路径</span>下的include/graph/ascend_string.h。</li><li>库文件：libgraph.so。</li></ul>
</td>
</tr>
<tr id="row14481001484"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p03001050134814"><a name="p03001050134814"></a><a name="p03001050134814"></a><a href="AutoMappingSubgraphIOIndexFuncRegister.md">AutoMappingSubgraphIOIndexFuncRegister</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1880411622314"><a name="p1880411622314"></a><a name="p1880411622314"></a>内部关联接口，插件适配API调用时间接调用，开发者不直接感知。</p>
</td>
</tr>
<tr id="row2048180124818"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14300195010486"><a name="p14300195010486"></a><a name="p14300195010486"></a><a href="FrameworkRegistry.md">FrameworkRegistry</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1961010481582"><a name="p1961010481582"></a><a name="p1961010481582"></a>内部关联接口，插件适配API调用时间接调用，开发者不直接感知。</p>
</td>
</tr>
<tr id="row09821810551"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13446124325511"><a name="p13446124325511"></a><a name="p13446124325511"></a><a href="IntegerChecker.md">IntegerChecker</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p56514535559"><a name="p56514535559"></a><a name="p56514535559"></a><span>IntegerChecker是一个模板类，带有模板参数T，用于检查一个整数是否在指定数据类型T的合法范围内。</span></p>
<p id="p247123610171"><a name="p247123610171"></a><a name="p247123610171"></a>头文件位于<span id="ph19980134431712"><a name="ph19980134431712"></a><a name="ph19980134431712"></a>CANN软件安装后文件存储路径</span>下的include/utils/extern_math_util.h。</p>
</td>
</tr>
<tr id="row45331038181217"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18374184615123"><a name="p18374184615123"></a><a name="p18374184615123"></a><a href="KernelLaunchInfo.md">KernelLaunchInfo</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19534173891211"><a name="p19534173891211"></a><a name="p19534173891211"></a><span>KernelLaunchInfo类为开发者提供创建和管理下发给Device的任务接口</span>，允许开发者设置或者获取当前待下发Device任务的相关Launch信息。</p>
<p id="p1485411138"><a name="p1485411138"></a><a name="p1485411138"></a>头文件位于<span id="ph234524161313"><a name="ph234524161313"></a><a name="ph234524161313"></a>CANN软件安装后文件存储路径</span>下的include/graph/kernel_launch_info.h。</p>
</td>
</tr>
<tr id="row12482706485"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5301205012487"><a name="p5301205012487"></a><a name="p5301205012487"></a><a href="ListTensorType.md">ListTensorType</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14606848115817"><a name="p14606848115817"></a><a name="p14606848115817"></a>ListTensorType类用以定义输入或者输出支持的数据类型，是TensorType的封装，用于标识支持多个数据类型的情况。</p>
<p id="p1921911268349"><a name="p1921911268349"></a><a name="p1921911268349"></a>头文件位于<span id="ph1219122653415"><a name="ph1219122653415"></a><a name="ph1219122653415"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row1048260174817"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p030115509486"><a name="p030115509486"></a><a name="p030115509486"></a><a href="MemBlock.md">MemBlock</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p458184703510"><a name="p458184703510"></a><a name="p458184703510"></a>配合<a href="Allocator.md">Allocator</a>类使用，支持使用用户注册的外置allocator功能。</p>
<p id="p186395719311"><a name="p186395719311"></a><a name="p186395719311"></a>头文件位于<span id="ph1011712476292"><a name="ph1011712476292"></a><a name="ph1011712476292"></a>CANN软件安装后文件存储路径</span>下的include/ge/ge_allocator.h。</p>
</td>
</tr>
<tr id="row4482140114810"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15301135012486"><a name="p15301135012486"></a><a name="p15301135012486"></a><a href="OpReceiver.md">OpReceiver</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1894543313396"><a name="p1894543313396"></a><a name="p1894543313396"></a>用于算子编写适配插件进行AI框架适配时，接收自定义算子的注册信息。</p>
<p id="p133181419411"><a name="p133181419411"></a><a name="p133181419411"></a>头文件位于<span id="ph19568814134113"><a name="ph19568814134113"></a><a name="ph19568814134113"></a>CANN软件安装后文件存储路径</span>下的include/register/register.h。</p>
</td>
</tr>
<tr id="row64821404480"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1130195054815"><a name="p1130195054815"></a><a name="p1130195054815"></a><a href="OpRegistrationData.md">OpRegistrationData</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p796085753616"><a name="p796085753616"></a><a name="p796085753616"></a>用于算子编写适配插件进行AI框架适配时，进行映射关系注册。</p>
<p id="p645815559418"><a name="p645815559418"></a><a name="p645815559418"></a>头文件位于<span id="ph64591455134110"><a name="ph64591455134110"></a><a name="ph64591455134110"></a>CANN软件安装后文件存储路径</span>下的include/register/register.h。</p>
</td>
</tr>
<tr id="row78711114152518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6871101418251"><a name="p6871101418251"></a><a name="p6871101418251"></a><a href="PassReceiver.md">PassReceiver</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p125161125154117"><a name="p125161125154117"></a><a name="p125161125154117"></a>用于自定义Pass时，接收Pass的注册信息。</p>
<a name="ul1451710255411"></a><a name="ul1451710255411"></a><ul id="ul1451710255411"><li>头文件：/include/register/register_custom_pass.h</li><li>库文件：libregister.so</li></ul>
</td>
</tr>
<tr id="row654392002512"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1554312082516"><a name="p1554312082516"></a><a name="p1554312082516"></a><a href="PassRegistrationData.md">PassRegistrationData</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1590111184110"><a name="p1590111184110"></a><a name="p1590111184110"></a>用于自定义Pass时，进行映射关系注册。</p>
<a name="ul1190316115416"></a><a name="ul1190316115416"></a><ul id="ul1190316115416"><li>头文件：/include/register/register_custom_pass.h</li><li>库文件：libregister.so</li></ul>
</td>
</tr>
<tr id="row54831104488"><td class="cellrowborder" rowspan="7" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1654793163719"><a name="p1654793163719"></a><a name="p1654793163719"></a>类和结构体</p>
<p id="p654763183716"><a name="p654763183716"></a><a name="p654763183716"></a></p>
<p id="p6547133183711"><a name="p6547133183711"></a><a name="p6547133183711"></a></p>
<p id="p1554719317377"><a name="p1554719317377"></a><a name="p1554719317377"></a></p>
<p id="p1454793173710"><a name="p1454793173710"></a><a name="p1454793173710"></a></p>
<p id="p16547338373"><a name="p16547338373"></a><a name="p16547338373"></a></p>
<p id="p18547038379"><a name="p18547038379"></a><a name="p18547038379"></a></p>
<p id="p3547163163714"><a name="p3547163163714"></a><a name="p3547163163714"></a></p>
<p id="p25479311376"><a name="p25479311376"></a><a name="p25479311376"></a></p>
</td>
<td class="cellrowborder" valign="top" width="27.139999999999997%" headers="mcps1.2.4.1.2 "><p id="p4301165014816"><a name="p4301165014816"></a><a name="p4301165014816"></a><a href="Promote.md">Promote</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.01%" headers="mcps1.2.4.1.3 "><p id="p310351185616"><a name="p310351185616"></a><a name="p310351185616"></a>Promote类用于表示输出数据类型为输入或属性指定的数据类型间的提升类型。</p>
<p id="p63218229420"><a name="p63218229420"></a><a name="p63218229420"></a>头文件位于<span id="ph7321172212424"><a name="ph7321172212424"></a><a name="ph7321172212424"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row1748350184812"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3301250114816"><a name="p3301250114816"></a><a name="p3301250114816"></a><a href="Shape-176.md">Shape</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p146011548195810"><a name="p146011548195810"></a><a name="p146011548195810"></a>用于存储Tensor的shape信息。</p>
<a name="ul14376118143517"></a><a name="ul14376118143517"></a><ul id="ul14376118143517"><li>头文件位于<span id="ph20696131810416"><a name="ph20696131810416"></a><a name="ph20696131810416"></a>CANN软件安装后文件存储路径</span>下的include/graph/tensor.h。</li><li>库文件：libgraph_base.so。</li></ul>
</td>
</tr>
<tr id="row1048315074815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16301450194811"><a name="p16301450194811"></a><a name="p16301450194811"></a><a href="TensorDescInfo.md">TensorDescInfo</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p760074817581"><a name="p760074817581"></a><a name="p760074817581"></a>存储Tensor描述信息。</p>
<p id="p7701916185915"><a name="p7701916185915"></a><a name="p7701916185915"></a>头文件位于<span id="ph270131645910"><a name="ph270131645910"></a><a name="ph270131645910"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row1348319064820"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p153011050184812"><a name="p153011050184812"></a><a name="p153011050184812"></a><a href="TensorDesc.md">TensorDesc</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16599104895816"><a name="p16599104895816"></a><a name="p16599104895816"></a>用于存取、管理Tensor描述信息。</p>
<a name="ul188201731184412"></a><a name="ul188201731184412"></a><ul id="ul188201731184412"><li>头文件位于<span id="ph78208317444"><a name="ph78208317444"></a><a name="ph78208317444"></a>CANN软件安装后文件存储路径</span>下的include/graph/tensor.h。</li><li>库文件：libgraph_base.so。</li></ul>
</td>
</tr>
<tr id="row1848350164814"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1130155014819"><a name="p1130155014819"></a><a name="p1130155014819"></a><a href="TensorType.md">TensorType</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10599154875810"><a name="p10599154875810"></a><a name="p10599154875810"></a>TensorType类用以定义输入或者输出支持的数据类型。</p>
<p id="p18231121105916"><a name="p18231121105916"></a><a name="p18231121105916"></a>头文件位于<span id="ph1223521115920"><a name="ph1223521115920"></a><a name="ph1223521115920"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row189812280481"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1230135044816"><a name="p1230135044816"></a><a name="p1230135044816"></a><a href="Tensor-192.md">Tensor</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1759814487581"><a name="p1759814487581"></a><a name="p1759814487581"></a>Tensor结构。</p>
<a name="ul13134131817447"></a><a name="ul13134131817447"></a><ul id="ul13134131817447"><li>头文件位于<span id="ph613411854411"><a name="ph613411854411"></a><a name="ph613411854411"></a>CANN软件安装后文件存储路径</span>下的include/graph/tensor.h</li><li>库文件：libgraph_base.so</li></ul>
</td>
</tr>
<tr id="row11638102813486"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17301050184819"><a name="p17301050184819"></a><a name="p17301050184819"></a><a href="TypeUtils.md">TypeUtils</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p35983484582"><a name="p35983484582"></a><a name="p35983484582"></a>类型转换工具类。</p>
<p id="p333510488446"><a name="p333510488446"></a><a name="p333510488446"></a>头文件位于<span id="ph921635519441"><a name="ph921635519441"></a><a name="ph921635519441"></a>CANN软件安装后文件存储路径</span>下的include/graph/utils/type_utils.h。</p>
</td>
</tr>
<tr id="row37417101571"><td class="cellrowborder" rowspan="16" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p14741151018577"><a name="p14741151018577"></a><a name="p14741151018577"></a>函数</p>
<p id="p189892523585"><a name="p189892523585"></a><a name="p189892523585"></a></p>
</td>
<td class="cellrowborder" valign="top" width="27.139999999999997%" headers="mcps1.2.4.1.2 "><p id="p188111401570"><a name="p188111401570"></a><a name="p188111401570"></a><a href="AddOverflow.md">AddOverflow</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.01%" headers="mcps1.2.4.1.3 "><p id="p573081263118"><a name="p573081263118"></a><a name="p573081263118"></a><span>该模板函数用于判断两个数值相加是否会发生溢出，并在不溢出的情况下返回正确的计算结果。</span></p>
<p id="p102341217189"><a name="p102341217189"></a><a name="p102341217189"></a>头文件位于<span id="ph1223410111815"><a name="ph1223410111815"></a><a name="ph1223410111815"></a>CANN软件安装后文件存储路径</span>下的include/utils/extern_math_util.h。</p>
</td>
</tr>
<tr id="row1546417599309"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p13461717105818"><a name="p13461717105818"></a><a name="p13461717105818"></a><a href="ConvertToAscendString.md">ConvertToAscendString</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p66111848185811"><a name="p66111848185811"></a><a name="p66111848185811"></a>模板函数，接受一个模板参数T，并将其转换为AscendString类型。这个函数的主要功能是将不同类型的字符串转换为AscendString类型。</p>
<p id="p6478151154815"><a name="p6478151154815"></a><a name="p6478151154815"></a>头文件位于<span id="ph10541104954813"><a name="ph10541104954813"></a><a name="ph10541104954813"></a>CANN软件安装后文件存储路径</span>下的include/graph/operator_reg.h</p>
</td>
</tr>
<tr id="row721911214314"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p46856328586"><a name="p46856328586"></a><a name="p46856328586"></a><a href="ConvertToListAscendString.md">ConvertToListAscendString</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p686174814552"><a name="p686174814552"></a><a name="p686174814552"></a>定义了一个模板函数ConvertToListAscendString，用于将不同类型的字符串列表转换为AscendString类型的列表。</p>
<p id="p773432894912"><a name="p773432894912"></a><a name="p773432894912"></a>头文件位于<span id="ph57349284491"><a name="ph57349284491"></a><a name="ph57349284491"></a>CANN软件安装后文件存储路径</span>下的include/graph/operator_reg.h</p>
</td>
</tr>
<tr id="row1908628164817"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p193014507483"><a name="p193014507483"></a><a name="p193014507483"></a><a href="GetC0Format.md">GetC0Format</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1190802811489"><a name="p1190802811489"></a><a name="p1190802811489"></a>根据实际format获取C0 format的值。</p>
<p id="p11572833114718"><a name="p11572833114718"></a><a name="p11572833114718"></a>头文件位于<span id="ph2057213339472"><a name="ph2057213339472"></a><a name="ph2057213339472"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row204417292489"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19301145064812"><a name="p19301145064812"></a><a name="p19301145064812"></a><a href="GetC0Value.md">GetC0Value</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p62392836"><a name="p62392836"></a><a name="p62392836"></a>从实际format中解析出C0 format信息。</p>
<p id="p17413133511472"><a name="p17413133511472"></a><a name="p17413133511472"></a>头文件位于<span id="ph18413235184717"><a name="ph18413235184717"></a><a name="ph18413235184717"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row181851229114818"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9302850204811"><a name="p9302850204811"></a><a name="p9302850204811"></a><a href="GetFormatFromC0.md">GetFormatFromC0</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p151851329184812"><a name="p151851329184812"></a><a name="p151851329184812"></a>根据传入的format和C0 format信息得到实际的format。</p>
<p id="p20156173713473"><a name="p20156173713473"></a><a name="p20156173713473"></a>头文件位于<span id="ph715613754713"><a name="ph715613754713"></a><a name="ph715613754713"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row103484297483"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p130295011481"><a name="p130295011481"></a><a name="p130295011481"></a><a href="GetFormatFromSub.md">GetFormatFromSub</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p640652620467"><a name="p640652620467"></a><a name="p640652620467"></a>根据传入的主format和子format信息得到实际的format。</p>
<p id="p615016395478"><a name="p615016395478"></a><a name="p615016395478"></a>头文件位于<span id="ph71511439204713"><a name="ph71511439204713"></a><a name="ph71511439204713"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row12487029184815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1930245011484"><a name="p1930245011484"></a><a name="p1930245011484"></a><a href="GetFormatFromSubAndC0.md">GetFormatFromSubAndC0</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p745320114464"><a name="p745320114464"></a><a name="p745320114464"></a>根据传入的主format，子format和C0 format信息得到实际的format。</p>
<p id="p151541241164713"><a name="p151541241164713"></a><a name="p151541241164713"></a>头文件位于<span id="ph1315474118471"><a name="ph1315474118471"></a><a name="ph1315474118471"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row479382974816"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7302165064818"><a name="p7302165064818"></a><a name="p7302165064818"></a><a href="GetFormatName.md">GetFormatName</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p99011115124617"><a name="p99011115124617"></a><a name="p99011115124617"></a>根据传入的format类型，获取format的字符串描述。</p>
<p id="p18524204311470"><a name="p18524204311470"></a><a name="p18524204311470"></a>头文件位于<span id="ph25241043164714"><a name="ph25241043164714"></a><a name="ph25241043164714"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row994362994820"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1930285014819"><a name="p1930285014819"></a><a name="p1930285014819"></a><a href="GetPrimaryFormat.md">GetPrimaryFormat</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p720122014617"><a name="p720122014617"></a><a name="p720122014617"></a>从实际format中解析出主format信息。</p>
<p id="p128712453475"><a name="p128712453475"></a><a name="p128712453475"></a>头文件位于<span id="ph152870457472"><a name="ph152870457472"></a><a name="ph152870457472"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row17931130154817"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1530275004812"><a name="p1530275004812"></a><a name="p1530275004812"></a><a href="GetSizeByDataType.md">GetSizeByDataType</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2023919319463"><a name="p2023919319463"></a><a name="p2023919319463"></a>根据传入的data_type，获取该data_type所占用的内存大小。</p>
<p id="p18141355174715"><a name="p18141355174715"></a><a name="p18141355174715"></a>头文件位于<span id="ph118711184813"><a name="ph118711184813"></a><a name="ph118711184813"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row13258830154811"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3302165011480"><a name="p3302165011480"></a><a name="p3302165011480"></a><a href="GetSizeInBytes.md">GetSizeInBytes</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1025993015480"><a name="p1025993015480"></a><a name="p1025993015480"></a>根据传入的element_count和data_type，获取element_count个该data_type所占用的内存总大小。</p>
<p id="p692416244815"><a name="p692416244815"></a><a name="p692416244815"></a>头文件位于<span id="ph345363124819"><a name="ph345363124819"></a><a name="ph345363124819"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row173936306486"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1430219502481"><a name="p1430219502481"></a><a name="p1430219502481"></a><a href="GetSubFormat.md">GetSubFormat</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3393193019489"><a name="p3393193019489"></a><a name="p3393193019489"></a>从实际format中解析出子format信息。</p>
<p id="p11865171564812"><a name="p11865171564812"></a><a name="p11865171564812"></a>头文件位于<span id="ph13505192217485"><a name="ph13505192217485"></a><a name="ph13505192217485"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row9535113015481"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16302155014489"><a name="p16302155014489"></a><a name="p16302155014489"></a><a href="HasC0Format.md">HasC0Format</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1753503018484"><a name="p1753503018484"></a><a name="p1753503018484"></a>判断实际format中是否包含C0 format。</p>
<p id="p1163362314815"><a name="p1163362314815"></a><a name="p1163362314815"></a>头文件位于<span id="ph421612417480"><a name="ph421612417480"></a><a name="ph421612417480"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row10693183012488"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p53025503481"><a name="p53025503481"></a><a name="p53025503481"></a><a href="HasSubFormat.md">HasSubFormat</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10913452204617"><a name="p10913452204617"></a><a name="p10913452204617"></a>判断实际format中是否包含子format。</p>
<p id="p6757225184814"><a name="p6757225184814"></a><a name="p6757225184814"></a>头文件位于<span id="ph672172624811"><a name="ph672172624811"></a><a name="ph672172624811"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row1698965285819"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19894523582"><a name="p19894523582"></a><a name="p19894523582"></a><a href="MulOverflow.md">MulOverflow</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p99397135598"><a name="p99397135598"></a><a name="p99397135598"></a><span>该模板函数用于判断两个数值相乘是否会发生溢出，并在不溢出的情况下返回正确的计算结果。</span></p>
<p id="p6135175741716"><a name="p6135175741716"></a><a name="p6135175741716"></a>头文件位于<span id="ph12135557171713"><a name="ph12135557171713"></a><a name="ph12135557171713"></a>CANN软件安装后文件存储路径</span>下的include/utils/extern_math_util.h。</p>
</td>
</tr>
<tr id="row1843113019488"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p4843163084812"><a name="p4843163084812"></a><a name="p4843163084812"></a>类型定义</p>
</td>
<td class="cellrowborder" valign="top" width="27.139999999999997%" headers="mcps1.2.4.1.2 "><p id="p230210506487"><a name="p230210506487"></a><a name="p230210506487"></a><a href="ge-graphStatus.md">ge::graphStatus</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.01%" headers="mcps1.2.4.1.3 "><p id="p1184310301483"><a name="p1184310301483"></a><a name="p1184310301483"></a>返回码状态说明。</p>
<p id="p66519312519"><a name="p66519312519"></a><a name="p66519312519"></a>头文件位于<span id="ph166519315515"><a name="ph166519315515"></a><a name="ph166519315515"></a>CANN软件安装后文件存储路径</span>下的include/graph/ge_error_codes.h。</p>
</td>
</tr>
<tr id="row1805311488"><td class="cellrowborder" rowspan="2" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p077146185018"><a name="p077146185018"></a><a name="p077146185018"></a>枚举</p>
<p id="p177776145011"><a name="p177776145011"></a><a name="p177776145011"></a></p>
</td>
<td class="cellrowborder" valign="top" width="27.139999999999997%" headers="mcps1.2.4.1.2 "><p id="p8302350134814"><a name="p8302350134814"></a><a name="p8302350134814"></a><a href="DataType.md">DataType</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.01%" headers="mcps1.2.4.1.3 "><p id="p171133154818"><a name="p171133154818"></a><a name="p171133154818"></a>数据类型枚举值。</p>
<p id="p1272091216572"><a name="p1272091216572"></a><a name="p1272091216572"></a>头文件位于<span id="ph1629312139577"><a name="ph1629312139577"></a><a name="ph1629312139577"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row0144163118486"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p19302050134817"><a name="p19302050134817"></a><a name="p19302050134817"></a><a href="Format.md">Format</a></p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p01441231154814"><a name="p01441231154814"></a><a name="p01441231154814"></a>数据格式枚举值。</p>
<p id="p657711121596"><a name="p657711121596"></a><a name="p657711121596"></a>头文件位于<span id="ph1971141311590"><a name="ph1971141311590"></a><a name="ph1971141311590"></a>CANN软件安装后文件存储路径</span>下的include/graph/types.h。</p>
</td>
</tr>
<tr id="row20594531154817"><td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.2.4.1.1 "><p id="p1732163317501"><a name="p1732163317501"></a><a name="p1732163317501"></a>宏</p>
</td>
<td class="cellrowborder" valign="top" width="27.139999999999997%" headers="mcps1.2.4.1.2 "><p id="p5302185024816"><a name="p5302185024816"></a><a name="p5302185024816"></a><a href="DECLARE_ERRORNO.md">DECLARE_ERRORNO</a></p>
</td>
<td class="cellrowborder" valign="top" width="59.01%" headers="mcps1.2.4.1.3 "><p id="p1459473119483"><a name="p1459473119483"></a><a name="p1459473119483"></a>错误码及描述注册宏。</p>
<p id="p181514221315"><a name="p181514221315"></a><a name="p181514221315"></a>头文件位于<span id="ph15956113510115"><a name="ph15956113510115"></a><a name="ph15956113510115"></a>CANN软件安装后文件存储路径</span>下的include/register/register_error_codes.h。</p>
</td>
</tr>
</tbody>
</table>

## C接口<a name="section1622916497387"></a>

<a name="table1293161117395"></a>
<table><thead align="left"><tr id="row179311110395"><th class="cellrowborder" valign="top" width="31.5%" id="mcps1.1.3.1.1"><p id="p1293111120399"><a name="p1293111120399"></a><a name="p1293111120399"></a>数据结构/接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="68.5%" id="mcps1.1.3.1.2"><p id="p169371115392"><a name="p169371115392"></a><a name="p169371115392"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row293011173918"><td class="cellrowborder" valign="top" width="31.5%" headers="mcps1.1.3.1.1 "><p id="p11848155511398"><a name="p11848155511398"></a><a name="p11848155511398"></a><a href="C_DataType.md">C_DataType</a></p>
</td>
<td class="cellrowborder" valign="top" width="68.5%" headers="mcps1.1.3.1.2 "><p id="p984816558392"><a name="p984816558392"></a><a name="p984816558392"></a>数据类型枚举值。</p>
<p id="p5848105533919"><a name="p5848105533919"></a><a name="p5848105533919"></a>头文件位于<span id="ph1484815583910"><a name="ph1484815583910"></a><a name="ph1484815583910"></a>CANN软件安装后文件存储路径</span>下的include/graph/c_types.h。</p>
</td>
</tr>
<tr id="row1294141116390"><td class="cellrowborder" valign="top" width="31.5%" headers="mcps1.1.3.1.1 "><p id="p1848115523920"><a name="p1848115523920"></a><a name="p1848115523920"></a><a href="C_Format.md">C_Format</a></p>
</td>
<td class="cellrowborder" valign="top" width="68.5%" headers="mcps1.1.3.1.2 "><p id="p9848125511392"><a name="p9848125511392"></a><a name="p9848125511392"></a>数据格式枚举值。</p>
<p id="p7848155573915"><a name="p7848155573915"></a><a name="p7848155573915"></a>头文件位于<span id="ph1984814555397"><a name="ph1984814555397"></a><a name="ph1984814555397"></a>CANN软件安装后文件存储路径</span>下的include/graph/c_types.h。</p>
</td>
</tr>
</tbody>
</table>

