# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

# 注意： op_impl_functions.cc 不能被包含在opp_registry.so里，该文件只能被librt2_registry.a包含
file(GLOB_RECURSE OPP_REGISTRY_SRC_LIST
        registry/op_ct_impl_registry.cc
        registry/op_impl_register_v2_impl.cc
        registry/op_impl_registry.cc
        registry/op_impl_registry_holder_manager.cc
        registry/op_impl_space_registry.cc
        registry/op_impl_space_registry_v2.cc
        registry/op_impl_space_registry_v2_impl.cc
        registry/opp_package_utils.cc
        registry/opp_so_manager.cc
        asc/tilingdata_base_impl.cc
)

set(OP_DEF_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_config_registry.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_aicore.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_aicpu.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_attr.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_factory.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_hostcpu.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_mc2.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_param.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_impl.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_config_registry_impl.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_def_factory_impl.cc
)

set(OP_CHECK_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opdef/op_config_registry.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opcheck/op_check_register_impl.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/asc/opcheck/op_check.cc
)

############ libopp_registry.so ############
add_library(opp_registry SHARED
        ${OPP_REGISTRY_SRC_LIST}
        ${OP_DEF_FILES}
        ${OP_CHECK_FILES}
)

target_compile_options(opp_registry PRIVATE
        $<$<OR:$<STREQUAL:${TARGET_SYSTEM_NAME},Linux>,$<STREQUAL:${TARGET_SYSTEM_NAME},Android>>: -fno-common -Wextra -Wfloat-equal>
        $<$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>:/utf-8>
        $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Debug>>:/MTd>
        $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Release>>:/MT>
)

target_compile_definitions(opp_registry PRIVATE
        google=ascend_private
        $<IF:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,OS_TYPE=WIN,OS_TYPE=0>
        $<$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>:SECUREC_USING_STD_SECURE_LIB=0 NOMINMAX>
)

target_compile_options(opp_registry PRIVATE -O2 -DNO_METADEF_ABI_COMPATIABLE -DNO_OPERATOR_IMPL)

target_include_directories(opp_registry PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${METADEF_DIR}/inc/
        ${METADEF_DIR}/pkg_inc
        ${METADEF_DIR}/inc/external/asc
        ${METADEF_DIR}/inc/external/base
)

target_link_options(opp_registry PRIVATE
        -Wl,-Bsymbolic
)

target_link_libraries(opp_registry
        PRIVATE
        $<BUILD_INTERFACE:intf_pub>
        $<BUILD_INTERFACE:error_manager_headers>
        c_sec
        unified_dlog
        platform
        metadef
        static_mmpa
        PUBLIC
        metadef_headers
)

############ librt2_registry.a ############
add_library(rt2_registry_objects OBJECT
        "${METADEF_DIR}/base/registry/op_impl_registry.cc"
        "${METADEF_DIR}/base/registry/op_ct_impl_registry.cc"
        "${METADEF_DIR}/base/registry/op_impl_functions.cc"
        "${METADEF_DIR}/base/registry/op_bin_info.cc"
        )

target_compile_options(rt2_registry_objects PRIVATE
        $<$<OR:$<STREQUAL:${TARGET_SYSTEM_NAME},Linux>,$<STREQUAL:${TARGET_SYSTEM_NAME},Android>>: -fvisibility=hidden -fno-common -fPIC -O2 -Werror -Wextra -Wfloat-equal>
        $<$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>:/utf-8>
        $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Debug>>:/MTd>
        $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Release>>:/MT>
        )

target_compile_definitions(rt2_registry_objects PRIVATE
        $<IF:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,OS_TYPE=WIN,OS_TYPE=0>
        $<$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>:SECUREC_USING_STD_SECURE_LIB=0 NOMINMAX>
        )

target_include_directories(rt2_registry_objects PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${METADEF_DIR}/inc
        ${METADEF_DIR}/inc/external
        ${TOP_DIR}/ace/npuruntime/runtime/platform/inc
        )

set_target_properties(rt2_registry_objects PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS TRUE
        OUTPUT_NAME $<IF:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,librt2_registry,rt2_registry>
        )

target_link_libraries(rt2_registry_objects
        PRIVATE
        $<BUILD_INTERFACE:intf_pub>
        $<BUILD_INTERFACE:error_manager_headers>
        c_sec
        unified_dlog
        static_mmpa
        PUBLIC
        metadef_headers
        )

############ librt2_registry.a ############
add_library(rt2_registry_static STATIC
        $<TARGET_OBJECTS:rt2_registry_objects>
        )

set_target_properties(rt2_registry_static PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS TRUE
        OUTPUT_NAME $<IF:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,librt2_registry,rt2_registry>
        )

target_link_libraries(rt2_registry_static
        PUBLIC
        metadef_headers
        )

install(TARGETS rt2_registry_static
        ARCHIVE DESTINATION ${INSTALL_LIBRARY_DIR}/${CMAKE_SYSTEM_PROCESSOR} ${INSTALL_OPTIONAL}
        )
##############################################################
set(STUB_HEADER_LIST
    ${METADEF_DIR}/inc/external/base/registry/op_impl_space_registry_v2.h
    ${METADEF_DIR}/inc/external/base/registry/opp_package_utils.h
    ${METADEF_DIR}/inc/external/register/tilingdata_base.h
)

if (NOT "${PRODUCT}" STREQUAL "ascend031")
    list(APPEND STUB_HEADER_LIST
    )
endif ()

list(TRANSFORM STUB_HEADER_LIST
        REPLACE "^.*/([^/]+)\\.h$" "${CMAKE_CURRENT_BINARY_DIR}/stub_\\1.cc"
        OUTPUT_VARIABLE STUB_SRC_LIST
)

add_custom_command(
        OUTPUT ${STUB_SRC_LIST}
        COMMAND echo "Generating stub files."
        && ${HI_PYTHON} ${METADEF_DIR}/tests/stub/gen_stubapi.py ${CMAKE_CURRENT_BINARY_DIR} ${STUB_HEADER_LIST}
        && echo "Generating stub files end."
)

add_custom_target(opp_registry_stub DEPENDS ${STUB_SRC_LIST})

############ stub/libopp_registry.so ############
add_library(stub_opp_registry SHARED ${STUB_SRC_LIST})

add_dependencies(stub_opp_registry opp_registry_stub)

target_include_directories(stub_opp_registry PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_BINARY_DIR}
        ${METADEF_DIR}/
)

target_compile_options(stub_opp_registry PRIVATE
        -Wfloat-equal
        -fno-common
        -Os
        -Werror=return-type
        -Wno-unused-parameter
)

target_link_libraries(stub_opp_registry
        PRIVATE
        intf_pub
        slog_headers
        c_sec_headers
        c_sec
        unified_dlog
        PUBLIC
        metadef_headers
)

set_target_properties(stub_opp_registry PROPERTIES
        OUTPUT_NAME opp_registry
        LIBRARY_OUTPUT_DIRECTORY stub
)

############ install ############
install(TARGETS stub_opp_registry ${INSTALL_OPTIONAL}
        LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR}/${CMAKE_SYSTEM_PROCESSOR}/stub
)

set(SRC_LIST
    "type/ascend_string_impl.cc"
    "type/types_impl.cc"
    "utils/type_utils_impl.cc"
    "utils/aligned_ptr.cc"
    "utils/file_utils.cc"
    "any_value.cc"
    "common/plugin/plugin_manager.cc"
    "runtime/compute_node_info.cc"
    "runtime/op_execute_context.cc"
    "runtime/runtime_attrs.cc"
    "runtime/tiling_data.cc"
    context_builder/op_context_builder_impl.cc
    context_builder/context_holder.cc
    context_builder/op_kernel_run_context_builder.cc
    context_builder/op_tiling_context_builder.cc
    context_builder/op_tiling_parse_context_builder.cc
    context_builder/op_infer_datatype_context_builder.cc
    context_builder/op_infer_shape_context_builder.cc
    context_builder/op_infer_shape_range_context_builder.cc
    context_builder/op_context_builder_base.cc
)

############ libmetadef.so ############
add_library(metadef SHARED
    ${SRC_LIST}
)

target_compile_options(metadef PRIVATE
    $<$<OR:$<STREQUAL:${TARGET_SYSTEM_NAME},Linux>,$<STREQUAL:${TARGET_SYSTEM_NAME},Android>>: -fno-common -Wextra -Wfloat-equal>
    $<$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>:/utf-8>
    $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Debug>>:/MTd>
    $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Release>>:/MT>
)

target_compile_definitions(metadef PRIVATE
    google=ascend_private
    $<IF:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,OS_TYPE=WIN,OS_TYPE=0>
    $<$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>:SECUREC_USING_STD_SECURE_LIB=0 NOMINMAX>
)

target_include_directories(metadef PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${METADEF_DIR}
    ${METADEF_DIR}/inc
    ${METADEF_DIR}/pkg_inc
    ${CMAKE_BINARY_DIR}
    ${CMAKE_BINARY_DIR}/proto/metadef_protos

    ${METADEF_DIR}/exe_graph/runtime
    ${METADEF_DIR}/graph/debug
    ${METADEF_DIR}/inc/common
    ${METADEF_DIR}/inc/base/attrs
    ${METADEF_DIR}/inc/common/util
    ${METADEF_DIR}/inc/common/ge_common
    ${METADEF_DIR}/inc/common/ge_common/debug
    ${METADEF_DIR}/inc/graph
    ${METADEF_DIR}/inc/graph/debug

    ${METADEF_DIR}/inc/external
    ${METADEF_DIR}/inc/external/base/context_builder
    ${METADEF_DIR}/inc/external/graph
    ${METADEF_DIR}/inc/external/exe_graph
    ${METADEF_DIR}/inc/external/exe_graph/runtime
)

target_link_options(metadef PRIVATE
    -Wl,-Bsymbolic
)

target_link_libraries(metadef
    PRIVATE
        intf_pub
        error_manager
        -Wl,--no-as-needed
        c_sec
        unified_dlog
        static_mmpa
        -Wl,--as-needed
        json
    PUBLIC
        metadef_headers
)

target_compile_options(metadef PRIVATE -O2 -DNO_METADEF_ABI_COMPATIABLE)

############ libmetadef.a ############
if (NOT ENABLE_OPEN_SRC)
    target_clone(metadef metadef_static STATIC)

    target_compile_options(metadef_static PRIVATE
            -Os
            -fvisibility=hidden
            -fvisibility-inlines-hidden
            -ffunction-sections
            -fdata-sections
            )

    set_target_properties(metadef_static PROPERTIES
            OUTPUT_NAME metadef
            )
endif ()

##############################################################
set(STUB_HEADER_LIST
    ${METADEF_DIR}/pkg_inc/base/type/ascend_string_impl.h
    ${METADEF_DIR}/inc/base/type/types_impl.h
    ${METADEF_DIR}/pkg_inc/base/utils/type_utils_impl.h
    ${METADEF_DIR}/inc/external/exe_graph/runtime/compute_node_info.h
    ${METADEF_DIR}/inc/external/exe_graph/runtime/runtime_attrs.h
    ${METADEF_DIR}/inc/external/exe_graph/runtime/tiling_data.h
)

if (NOT "${PRODUCT}" STREQUAL "ascend031")
    list(APPEND STUB_HEADER_LIST
            )
endif ()

list(TRANSFORM STUB_HEADER_LIST
    REPLACE "^.*/([^/]+)\\.h$" "${CMAKE_CURRENT_BINARY_DIR}/stub_\\1.cc"
    OUTPUT_VARIABLE STUB_SRC_LIST
)

add_custom_command(
    OUTPUT ${STUB_SRC_LIST}
    COMMAND echo "Generating stub files."
            && ${HI_PYTHON} ${METADEF_DIR}/tests/stub/gen_stubapi.py ${CMAKE_CURRENT_BINARY_DIR} ${STUB_HEADER_LIST}
            && echo "Generating stub files end."
)

add_custom_target(metadef_stub DEPENDS ${STUB_SRC_LIST})

############ stub/libmetadef.so ############
add_library(stub_metadef SHARED ${STUB_SRC_LIST})

add_dependencies(stub_metadef metadef_stub)

target_include_directories(stub_metadef PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_BINARY_DIR}
    ${METADEF_DIR}/
)

target_compile_options(stub_metadef PRIVATE
    -Wfloat-equal
    -fno-common
    -Os
    -Werror=return-type
    -Wno-unused-parameter
)

target_link_libraries(stub_metadef
    PRIVATE
        intf_pub
        slog_headers
        c_sec_headers
        c_sec
        unified_dlog
        json
    PUBLIC
        metadef_headers
)

set_target_properties(stub_metadef PROPERTIES
    OUTPUT_NAME metadef
    LIBRARY_OUTPUT_DIRECTORY stub
)

############ stub/metadef.a ############
if (NOT ENABLE_OPEN_SRC)
    target_clone(stub_metadef stub_metadef_static STATIC)

    add_dependencies(stub_metadef_static metadef_stub)

    target_compile_options(stub_metadef_static PRIVATE
        $<$<STREQUAL:${TARGET_SYSTEM_NAME},Linux>:-O2 -fPIC -Wextra -Wfloat-equal>)

    set_target_properties(stub_metadef_static PROPERTIES
        OUTPUT_NAME metadef
        ARCHIVE_OUTPUT_DIRECTORY stub
    )
    install(TARGETS stub_metadef_static ${INSTALL_OPTIONAL}
            ARCHIVE DESTINATION ${INSTALL_LIBRARY_DIR}/${CMAKE_SYSTEM_PROCESSOR}/stub
            )
endif ()

############ install ############
install(TARGETS stub_metadef ${INSTALL_OPTIONAL}
        LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR}/${CMAKE_SYSTEM_PROCESSOR}/stub
)

######### 因为兼容性需要保留原有的libexe_graph.so #############
set(EXE_GRAPH_SRCS
        runtime/compute_node_info.cc
        runtime/op_execute_context.cc
        runtime/runtime_attrs.cc
        runtime/tiling_data.cc
        )

add_library(exe_graph SHARED ${EXE_GRAPH_SRCS})

target_include_directories(exe_graph PRIVATE
        ${METADEF_DIR}
        ${METADEF_DIR}/pkg_inc
        )

target_include_directories(exe_graph PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_BINARY_DIR}
        ${CMAKE_BINARY_DIR}/proto/metadef_protos
        )

target_link_libraries(exe_graph PRIVATE
        intf_pub
        mmpa_headers
        metadef_headers
        error_manager
        c_sec
        unified_dlog
        $<$<NOT:$<STREQUAL:${TARGET_SYSTEM_NAME},Android>>:-lrt>
        -ldl
        )

target_compile_definitions(exe_graph PRIVATE
        google=ascend_private
        $<IF:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,OS_TYPE=WIN,OS_TYPE=0>
        $<$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>:SECUREC_USING_STD_SECURE_LIB=0 NOMINMAX>
        )

target_compile_options(exe_graph PRIVATE
        $<$<STREQUAL:${TARGET_SYSTEM_NAME},Linux>:-O2 -fPIC -Wextra -Wfloat-equal -fno-common>
        $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Debug>>:/MTd>
        $<$<AND:$<STREQUAL:${TARGET_SYSTEM_NAME},Windows>,$<STREQUAL:${CMAKE_CONFIGURATION_TYPES},Release>>:/MT>
        )

if (NOT ENABLE_OPEN_SRC)
    ######### libexe_graph_static.a #############
    target_clone(exe_graph exe_graph_static STATIC)
    target_compile_options(exe_graph_static PRIVATE $<$<STREQUAL:${TARGET_SYSTEM_NAME},Linux>:-O2 -fPIC -Wextra -Wfloat-equal>)
    set_target_properties(exe_graph_static PROPERTIES OUTPUT_NAME exe_graph)

    ############ install ############
    install(TARGETS exe_graph_static ${INSTALL_OPTIONAL}
            ARCHIVE DESTINATION ${INSTALL_LIBRARY_DIR}
            )
endif()

##############################################################
set(STUB_HEADER_LIST_EXE_GRAPH
        ${METADEF_DIR}/inc/external/exe_graph/runtime/compute_node_info.h
        ${METADEF_DIR}/inc/external/exe_graph/runtime/runtime_attrs.h
        ${METADEF_DIR}/inc/external/exe_graph/runtime/tiling_data.h
        )

list(TRANSFORM STUB_HEADER_LIST_EXE_GRAPH
        REPLACE "^.*/([^/]+)\\.h$" "${CMAKE_CURRENT_BINARY_DIR}/stub_\\1.cc"
        OUTPUT_VARIABLE STUB_SRC_LIST_EXE_GRAPH
        )

add_custom_command(
        OUTPUT ${STUB_SRC_LIST_EXE_GRAPH}
        COMMAND echo "Generating stub files."
        && ${HI_PYTHON} ${METADEF_DIR}/tests/stub/gen_stubapi.py ${CMAKE_CURRENT_BINARY_DIR} ${STUB_HEADER_LIST_EXE_GRAPH}
        && echo "Generating stub files end."
)

add_custom_target(exe_graph_stub DEPENDS ${STUB_SRC_LIST_EXE_GRAPH})

############ stub/libexe_graph.so ############
add_library(stub_exe_graph SHARED ${STUB_SRC_LIST_EXE_GRAPH})

add_dependencies(stub_exe_graph exe_graph_stub)

target_include_directories(stub_exe_graph PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_BINARY_DIR}
        ${CMAKE_BINARY_DIR}/proto/metadef_protos
        )

target_compile_options(stub_exe_graph PRIVATE
        -Wfloat-equal
        -fno-common
        -Os
        -Werror=return-type
        -Wno-unused-parameter
        )

target_link_libraries(stub_exe_graph
        PRIVATE
        intf_pub
        c_sec_headers
        PUBLIC
        metadef_headers
        )

set_target_properties(stub_exe_graph PROPERTIES
        OUTPUT_NAME exe_graph
        LIBRARY_OUTPUT_DIRECTORY stub
        )

############ stub/libexe_graph.a ############
if (NOT ENABLE_OPEN_SRC)
    target_clone(stub_exe_graph stub_exe_graph_static STATIC)

    add_dependencies(stub_exe_graph_static exe_graph_stub)

    target_compile_options(stub_exe_graph_static PRIVATE
            -ffunction-sections
            -fdata-sections
            )
    set_target_properties(stub_exe_graph_static PROPERTIES
            OUTPUT_NAME exe_graph
            ARCHIVE_OUTPUT_DIRECTORY stub
            )

    ############ install ############
    install(TARGETS stub_exe_graph_static ${INSTALL_OPTIONAL}
            ARCHIVE DESTINATION ${INSTALL_LIBRARY_DIR}/${CMAKE_SYSTEM_PROCESSOR}/stub
            )
endif ()

############ install ############
install(TARGETS stub_exe_graph ${INSTALL_OPTIONAL}
        LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR}/${CMAKE_SYSTEM_PROCESSOR}/stub
        )
