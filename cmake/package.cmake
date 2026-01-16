# ----------------------------------------------------------------------------
# This program is free software, you can redistribute it and/or modify it.
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ----------------------------------------------------------------------------

#### CPACK to package run #####
message(STATUS "System processor: ${CMAKE_SYSTEM_PROCESSOR}")
if (CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
    message(STATUS "Detected architecture: x86_64")
    set(ARCH x86_64)
elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64|arm")
    message(STATUS "Detected architecture: ARM64")
    set(ARCH aarch64)
else ()
    message(WARNING "Unknown architecture: ${CMAKE_SYSTEM_PROCESSOR}")
    set(ARCH ${CMAKE_SYSTEM_PROCESSOR})
endif ()
# 打印路径
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
set(ARCH_LINUX_PATH "${ARCH}-linux")
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/third_party/makeself-fetch.cmake)

# ============= 组件打包 =============
function(install_public_packages)
    set(script_prefix ${CMAKE_CURRENT_SOURCE_DIR}/scripts/package/metadef/scripts)
    install(DIRECTORY ${script_prefix}/
        DESTINATION share/info/metadef/script
        FILE_PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE  # 文件权限
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
        DIRECTORY_PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE  # 目录权限
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
    )
    set(SCRIPTS_FILES
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/check_version_required.awk
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/common_func.inc
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/common_interface.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/common_interface.csh
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/common_interface.fish
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/version_compatiable.inc
    )

    install(FILES ${SCRIPTS_FILES}
        DESTINATION share/info/metadef/script
    )
    set(COMMON_FILES
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/install_common_parser.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/common_func_v2.inc
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/common_installer.inc
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/script_operator.inc
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/version_cfg.inc
    )

    set(PACKAGE_FILES
        ${COMMON_FILES}
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/multi_version.inc
    )
    set(LATEST_MANGER_FILES
        ${COMMON_FILES}
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/common_func.inc
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/version_compatiable.inc
        ${CMAKE_SOURCE_DIR}/scripts/package/common/sh/check_version_required.awk
    )
    set(CONF_FILES
        ${CMAKE_SOURCE_DIR}/scripts/package/common/cfg/path.cfg
    )
    install(FILES ${CMAKE_SOURCE_DIR}/version.info
        DESTINATION share/info/metadef
    )
    install(FILES ${CONF_FILES}
        DESTINATION metadef/conf
    )
    install(FILES ${PACKAGE_FILES}
        DESTINATION share/info/metadef/script
    )
    install(FILES ${LATEST_MANGER_FILES}
        DESTINATION latest_manager
    )
    install(DIRECTORY ${CMAKE_SOURCE_DIR}/scripts/package/latest_manager/scripts/
        DESTINATION latest_manager
    )
endfunction()

# ============= 创建install =============
install_public_packages()

message(STATUS "************Install metadef packages***************")
install(TARGETS exe_graph rt2_registry_static opp_registry metadef
        LIBRARY DESTINATION metadef/lib64
        ARCHIVE DESTINATION metadef/lib64
)
install(TARGETS stub_exe_graph stub_metadef stub_opp_registry rt2_registry_static
        LIBRARY DESTINATION metadef/lib64/stub/linux/${ARCH}
        ARCHIVE DESTINATION metadef/lib64/stub/linux/${ARCH}
)
install(TARGETS stub_exe_graph stub_metadef stub_opp_registry rt2_registry_static
        LIBRARY DESTINATION metadef/lib64/stub/minios/aarch64
        ARCHIVE DESTINATION metadef/lib64/stub/minios/aarch64
)
install(FILES
        ${METADEF_DEVICE_OUTPUT}/lib/libexe_meta_device.a
        ${METADEF_DEVICE_OUTPUT}/lib/libdevice_register.a
        DESTINATION metadef/lib64/device/lib64
)

set(EXTERNAL_RUNTIME_FILES
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/tiling_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/kernel_run_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/shape.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/compute_node_info.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/tensor_data.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/op_execute_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/op_execute_launch_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/storage_format.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/stride.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/tensor.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/continuous_vector.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/exe_res_generation_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/infer_shape_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/range.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/runtime_attrs.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/base_type.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/expand_dims_type.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/infer_datatype_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/infer_shape_range_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/context_extend.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/storage_shape.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/tiling_parse_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/kernel_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/tiling_data.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/extended_kernel_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/exe_graph/runtime/op_execute_prepare_context.h
)
install(FILES ${EXTERNAL_RUNTIME_FILES}
    DESTINATION metadef/include/exe_graph/runtime
)
set(EXTERNAL_GRAPH_FILES
    ${CMAKE_SOURCE_DIR}/inc/external/graph/tensor.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/c_types.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/ge_error_codes.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/infer_format_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/compiler_def.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/ascend_string.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/attr_value.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/inference_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/types.h
)
install(FILES ${EXTERNAL_GRAPH_FILES}
    DESTINATION metadef/include/graph
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/graph/utils/type_utils.h
    DESTINATION metadef/include/graph/utils
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/utils/extern_math_util.h
    DESTINATION metadef/include/utils
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/ge/ge_allocator.h
    DESTINATION metadef/include/ge
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/ge_common/ge_api_types.h
              ${CMAKE_SOURCE_DIR}/inc/external/ge_common/ge_api_error_codes.h
              ${CMAKE_SOURCE_DIR}/inc/external/ge_common/ge_error_codes.h
    DESTINATION metadef/include/external/ge_common
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/base/registry/op_impl_space_registry_v2.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/registry/opp_package_utils.h
    DESTINATION metadef/pkg_inc/base/registry
)
install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/err_mgr.h
    DESTINATION metadef/pkg_inc/base
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/type/ascend_string_impl.h
        DESTINATION metadef/pkg_inc/base/type
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/utils/type_utils_impl.h
        DESTINATION metadef/pkg_inc/base/utils
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/common/checker.h
        DESTINATION metadef/pkg_inc/common
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/common/ge_common/debug/ge_log.h
        DESTINATION metadef/pkg_inc/common/ge_common/debug
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/graph/any_value.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/graph/def_types.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/graph/type_utils.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/graph/op_so_bin.h
        DESTINATION metadef/pkg_inc/graph
)

install(FILES ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/context_holder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_context_builder_base.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_tiling_parse_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_tiling_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_infer_datatype_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_infer_shape_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_infer_shape_range_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_kernel_run_context_builder.h
    DESTINATION metadef/include/base/context_builder
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/base/runtime/runtime_attrs_def.h
    DESTINATION metadef/include/base/runtime
)
set(EXTERNAL_REGISTRY_FILES
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_impl_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_impl_kernel_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register_types.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register_fmk_types.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register_error_codes.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_ct_impl_kernel_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_ct_impl_registry_api.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_ct_impl_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_bin_info.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/tilingdata_base.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/device_op_impl_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register.h
)
install(FILES ${EXTERNAL_REGISTRY_FILES}
    DESTINATION metadef/include/register
)

# ============= CPack =============

set(CPACK_COMPONENTS_ALL ".;packages")
set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_NAME}")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CPACK_CMAKE_SOURCE_DIR "${CMAKE_SOURCE_DIR}")
set(CPACK_CMAKE_BINARY_DIR "${CMAKE_BINARY_DIR}")
set(CPACK_MAKESELF_PATH "${MAKESELF_PATH}")
set(CPACK_ARCH "${ARCH}")
set(CPACK_GENERATOR External)
set(CPACK_EXTERNAL_ENABLE_STAGING TRUE)
set(CPACK_EXTERNAL_PACKAGE_SCRIPT "${CMAKE_SOURCE_DIR}/cmake/makeself.cmake")

message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")
include(CPack)