# 头文件和库文件说明

基础数据结构和结构头文件在如下目录：

- Graph运行时相关接口：$\{INSTALL\_DIR\}/include/exe\_graph/runtime/
- Graph、GE与公共类型类接口：
  - $\{INSTALL\_DIR\}/include/graph/
  - $\{INSTALL\_DIR\}/include/utils/
  - $\{INSTALL\_DIR\}/include/external/ge\_common/

- 注册内部接口与基础支撑类接口：$\{INSTALL\_DIR\}/pkg\_inc/
- Context Builder与Runtime定义类接口：$\{INSTALL\_DIR\}/include/base/
- 算子注册类接口：$\{INSTALL\_DIR\}/include/register/

库文件在`$\{INSTALL\_DIR\}/lib64/`目录下，`$\{INSTALL\_DIR\}`请替换为CANN软件安装后文件存储路径。以root用户安装为例，安装后文件默认存储路径为：/usr/local/Ascend/cann。

## Graph运行时相关接口

| 定义接口的头文件 | 用途 | 对应的库文件 |
| --- | --- | --- |
| exe_graph/runtime/tiling_context.h | Tiling函数输入、输出、属性及平台信息上下文。 | Header-only上下文；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/kernel_run_context.h | Kernel执行上下文的C结构定义。 | Header-only定义；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/shape.h | Runtime Shape维度描述与访问。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/compute_node_info.h | 执行节点、输入输出描述和编译期节点信息。 | libmetadef.so、libexe_graph.so（兼容库） |
| exe_graph/runtime/tensor_data.h | Tensor地址、大小、Placement和数据视图。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/op_execute_context.h | 算子执行输入、输出、Stream、Workspace上下文。 | libmetadef.so、libexe_graph.so（兼容库） |
| exe_graph/runtime/op_execute_launch_context.h | 两阶段算子Launch阶段上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/storage_format.h | Tensor存储Format与扩展子格式。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/stride.h | Tensor各维步长描述。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/tensor.h | Runtime Tensor、StorageShape和TensorData聚合对象。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/continuous_vector.h | 连续内存上的变长向量容器。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/exe_res_generation_context.h | 执行资源、Stream和同步资源生成上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/infer_shape_context.h | 算子Shape推导上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/range.h | Shape维度取值范围。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/runtime_attrs.h | Runtime属性的类型化读取接口。 | libmetadef.so、libexe_graph.so（兼容库） |
| exe_graph/runtime/base_type.h | Runtime基础类型、常量及安全转换工具。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/expand_dims_type.h | 补维规则的保存与查询。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/infer_datatype_context.h | 算子输出数据类型推导上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/infer_shape_range_context.h | 算子Shape Range推导上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/context_extend.h | Kernel上下文扩展信息与链式扩展能力。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/storage_shape.h | Origin Shape与Storage Shape组合描述。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/tiling_parse_context.h | Tiling编译信息解析上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/kernel_context.h | Kernel输入输出指针和上下文基类。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/tiling_data.h | TilingData Buffer写入与容量管理。 | libmetadef.so、libexe_graph.so（兼容库） |
| exe_graph/runtime/extended_kernel_context.h | 支持扩展信息的Kernel/Tiling执行上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |
| exe_graph/runtime/op_execute_prepare_context.h | 两阶段算子Prepare阶段上下文。 | Header-only；主要消费库 libmetadef.so/libexe_graph.so |

## Graph、GE与公共类型类接口

| 定义接口的头文件 | 用途 | 对应的库文件 |
| --- | --- | --- |
| graph/tensor.h | Shape、TensorDesc、Tensor公共接口。 | libgraph_base.so（实现位于GE/Air） |
| graph/c_types.h | 跨平台C基础类型定义。 | Header-only定义头 |
| graph/ge_error_codes.h | Graph状态码、可见性和废弃接口宏。 | Header-only定义头 |
| graph/infer_format_context.h | 算子Format推导上下文。 | Header-only；主要消费库libmetadef.so |
| graph/compiler_def.h | 编译器公共宏和数据类型定义。 | Header-only定义头 |
| graph/ascend_string.h | AscendString字符串接口。 | libmetadef.so |
| graph/types.h | Format、DataType、TensorType等公共类型接口。 | libmetadef.so |
| graph/utils/type_utils.h | Format/DataType字符串转换和合法性检查。 | libmetadef.so |
| utils/extern_math_util.h | 整数加减乘除溢出检查工具。 | Header-only工具头 |
| ge/ge_allocator.h | GE内存块和分配器抽象接口。 | Header-only抽象接口；主要消费库libgert.so（实现位于GE/Air） |
| external/ge_common/ge_api_types.h | GE公共枚举、状态和模型数据结构。 | Header-only定义头 |
| external/ge_common/ge_api_error_codes.h | GE错误码定义、注册和文本查询。 | Header-only/内联实现 |
| external/ge_common/ge_error_codes.h | GE错误码基础类型及符号可见性宏。 | Header-only定义头 |

## 注册内部接口与基础支撑类接口

| 定义接口的头文件 | 用途 | 对应的库文件 |
| --- | --- | --- |
| pkg_inc/base/registry/op_impl_space_registry_v2.h | 算子实现空间的创建、合并和查询。 | libopp_registry.so |
| pkg_inc/base/registry/opp_package_utils.h | OPP包路径、版本和SO描述查询。 | libopp_registry.so |
| pkg_inc/base/type/ascend_string_impl.h | AscendString PImpl实现接口。 | libmetadef.so |
| pkg_inc/base/asc/opcheck/op_check_register_impl.h | 算子校验函数注册实现。 | libopp_registry.so |
| pkg_inc/base/asc/opdef/op_config_registry_impl.h | 算子配置注册实现。 | libopp_registry.so |
| pkg_inc/base/asc/opdef/op_def_factory_impl.h | 算子定义工厂实现。 | libopp_registry.so |
| pkg_inc/base/asc/opdef/op_def_impl.h | 算子、参数、属性定义的内部实现。 | libopp_registry.so |
| pkg_inc/base/utils/type_utils_impl.h | Format/DataType转换工具实现。 | libmetadef.so |
| pkg_inc/common/checker.h | 参数校验和错误返回宏。 | Header-only工具头 |
| pkg_inc/common/ge_common/error_codes_define.h | 内部错误码编码及解析定义。 | Header-only定义头 |
| pkg_inc/common/ge_common/scope_guard.h | 作用域退出回调工具。 | Header-only/内联实现 |
| pkg_inc/common/ge_common/debug/ge_log.h | GE日志与检查宏。 | Header-only/内联封装 |
| pkg_inc/exe_graph/runtime/gert_mem_allocator.h | GERT多流内存分配器抽象接口。 | Header-only抽象接口；主要消费库libgert.so（实现位于GE/Air） |
| pkg_inc/exe_graph/runtime/gert_mem_block.h | GERT引用计数内存块抽象接口。 | Header-only抽象接口；主要消费库libgert.so（实现位于GE/Air） |
| pkg_inc/exe_graph/runtime/gert_tensor_data.h | 带所有权和多流共享能力的TensorData。 | libgert.so（实现位于GE/Air） |
| pkg_inc/graph/any_value.h | 类型擦除属性值容器。 | libmetadef.so |
| pkg_inc/graph/def_types.h | Graph内部基础类型和智能指针别名。 | Header-only定义头 |
| pkg_inc/graph/type_utils.h | AnyValue类型标识及特化接口。 | libmetadef.so |
| pkg_inc/base/asc/tilingdata_base_impl.h | TilingData定义、字段布局和工厂内部实现。 | libopp_registry.so |

## Context Builder与Runtime定义类接口

| 定义接口的头文件 | 用途 | 对应的库文件 |
| --- | --- | --- |
| base/context_builder/context_holder.h | Kernel Context内存所有权和生命周期管理。 | libmetadef.so |
| base/context_builder/op_context_builder_base.h | 算子Context Builder公共基类。 | libmetadef.so |
| base/context_builder/op_tiling_parse_context_builder.h | 构造TilingParseContext。 | libmetadef.so |
| base/context_builder/op_tiling_context_builder.h | 构造TilingContext。 | libmetadef.so |
| base/context_builder/op_infer_datatype_context_builder.h | 构造InferDataTypeContext。 | libmetadef.so |
| base/context_builder/op_infer_shape_context_builder.h | 构造InferShapeContext。 | libmetadef.so |
| base/context_builder/op_infer_shape_range_context_builder.h | 构造InferShapeRangeContext。 | libmetadef.so |
| base/context_builder/op_kernel_run_context_builder.h | 构造KernelContext。 | libmetadef.so |
| base/runtime/runtime_attrs_def.h | RuntimeAttrs的C内存布局定义。 | Header-only定义头；主要消费库 libmetadef.so/libexe_graph.so |

## 算子注册类接口

| 定义接口的头文件 | 用途 | 对应的库文件 |
| --- | --- | --- |
| register/op_impl_registry.h | Host侧算子Tiling、推导和执行函数注册。 | libopp_registry.so（同时编入librt2_registry.a） |
| register/op_impl_kernel_registry.h | 算子实现函数表和查询接口。 | libopp_registry.so（同时编入librt2_registry.a） |
| register/register_types.h | 算子注册公共结构和函数类型。 | Header-only定义头 |
| register/register_fmk_types.h | 框架类型和解析注册类型。 | Header-only定义头 |
| register/register_error_codes.h | 注册模块状态码。 | Header-only定义头 |
| register/op_bin_info.h | 算子二进制信息生成与校验。 | 无对应SO；librt2_registry.a |
| register/tilingdata_base.h | TilingData字段定义、序列化和类工厂。 | libopp_registry.so（Device侧同时编入 libtilingdata_base.a） |
| register/device_op_impl_registry.h | Device侧算子Tiling函数注册。 | 无对应SO；libdevice_register.a |
| register/register.h | 自定义算子解析、Framework和映射函数注册。 | libregister.so（实现位于GE/Air） |
| register/asc/op_config_registry.h | 算子AICore配置注册。 | libopp_registry.so |
| register/asc/op_def_factory.h | 算子定义创建、查询和Tiling Sink注册。 | libopp_registry.so |
| register/asc/op_def.h | 算子输入、输出、属性和执行能力定义。 | libopp_registry.so |
| register/asc/op_def_registry.h | 算子定义注册宏。 | Header-only注册入口；调用libopp_registry.so |
