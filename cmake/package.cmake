# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

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
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/third_party/build/modules/makeself-fetch.cmake)

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
        COMPONENT metadef
    )
    set(SCRIPTS_FILES
        ${CANN_CMAKE_DIR}/scripts/install/check_version_required.awk
        ${CANN_CMAKE_DIR}/scripts/install/common_func.inc
        ${CANN_CMAKE_DIR}/scripts/install/common_interface.sh
        ${CANN_CMAKE_DIR}/scripts/install/common_interface.csh
        ${CANN_CMAKE_DIR}/scripts/install/common_interface.fish
        ${CANN_CMAKE_DIR}/scripts/install/version_compatiable.inc
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/cleanup.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/help.info
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/install.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/run_metadef_install.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/run_metadef_uninstall.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/run_metadef_upgrade.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/uninstall.sh
        ${CMAKE_SOURCE_DIR}/scripts/package/metadef/scripts/ver_check.sh
    )

    install(FILES ${SCRIPTS_FILES}
        DESTINATION share/info/metadef/script
        COMPONENT metadef
        PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE  # 文件权限
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE
    )
    set(COMMON_FILES
        ${CANN_CMAKE_DIR}/scripts/install/install_common_parser.sh
        ${CANN_CMAKE_DIR}/scripts/install/common_func_v2.inc
        ${CANN_CMAKE_DIR}/scripts/install/common_installer.inc
        ${CANN_CMAKE_DIR}/scripts/install/script_operator.inc
        ${CANN_CMAKE_DIR}/scripts/install/version_cfg.inc
    )

    set(PACKAGE_FILES
        ${COMMON_FILES}
        ${CANN_CMAKE_DIR}/scripts/install/multi_version.inc
    )
    set(CONF_FILES
        ${CANN_CMAKE_DIR}/scripts/package/cfg/path.cfg
    )
    install(FILES ${CMAKE_BINARY_DIR}/version.metadef.info
        DESTINATION share/info/metadef
        RENAME version.info
        COMPONENT metadef
    )
    install(FILES ${CONF_FILES}
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/conf
        COMPONENT metadef
    )
    install(FILES ${PACKAGE_FILES}
        DESTINATION share/info/metadef/script
        COMPONENT metadef
    )
endfunction()

# ============= 创建install =============
install_public_packages()

message(STATUS "************Install metadef packages***************")
install(TARGETS exe_graph rt2_registry_static opp_registry metadef
        LIBRARY DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/lib64 COMPONENT metadef
        ARCHIVE DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/lib64 COMPONENT metadef
)
install(TARGETS stub_exe_graph stub_metadef stub_opp_registry rt2_registry_static
        LIBRARY DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/devlib/linux/${ARCH} COMPONENT metadef
        ARCHIVE DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/devlib/linux/${ARCH} COMPONENT metadef
)
install(TARGETS stub_exe_graph stub_metadef stub_opp_registry
        LIBRARY DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/devlib/minios/aarch64 COMPONENT metadef
        ARCHIVE DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/devlib/minios/aarch64 COMPONENT metadef
)
install(TARGETS stub_exe_graph stub_metadef stub_opp_registry rt2_registry_static
        LIBRARY DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/devlib COMPONENT metadef
        ARCHIVE DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/devlib COMPONENT metadef
)

if(ENABLE_BUILD_DEVICE)
    # 非MDC编译
    install(FILES
            ${METADEF_DEVICE_OUTPUT}/${INSTALL_DEVICE_LIBRARY_DIR}/libtilingdata_base.a
            ${METADEF_DEVICE_OUTPUT}/${INSTALL_DEVICE_LIBRARY_DIR}/libexe_meta_device.a
            ${METADEF_DEVICE_OUTPUT}/${INSTALL_DEVICE_LIBRARY_DIR}/libdevice_register.a
            DESTINATION ${INSTALL_DEVICE_LIBRARY_DIR}
            COMPONENT metadef
    )
endif()

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
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/exe_graph/runtime
    COMPONENT metadef
)
set(EXTERNAL_GRAPH_FILES
    ${CMAKE_SOURCE_DIR}/inc/external/graph/tensor.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/c_types.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/ge_error_codes.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/infer_format_context.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/compiler_def.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/ascend_string.h
    ${CMAKE_SOURCE_DIR}/inc/external/graph/types.h
)
install(FILES ${EXTERNAL_GRAPH_FILES}
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/graph
    COMPONENT metadef
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/graph/utils/type_utils.h
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/graph/utils
    COMPONENT metadef
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/utils/extern_math_util.h
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/utils
    COMPONENT metadef
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/ge/ge_allocator.h
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/ge
    COMPONENT metadef
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/ge_common/ge_api_types.h
              ${CMAKE_SOURCE_DIR}/inc/external/ge_common/ge_api_error_codes.h
              ${CMAKE_SOURCE_DIR}/inc/external/ge_common/ge_error_codes.h
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/external/ge_common
    COMPONENT metadef
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/base/registry/op_impl_space_registry_v2.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/registry/opp_package_utils.h
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/registry
    COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/type/ascend_string_impl.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/type
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/asc/opcheck/op_check_register_impl.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/asc/opcheck
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/asc/opdef/op_config_registry_impl.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/asc/opdef
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/asc/opdef/op_def_factory_impl.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/asc/opdef
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/asc/opdef/op_def_impl.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/asc/opdef
        COMPONENT metadef 
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/utils/type_utils_impl.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/utils
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/common/checker.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/common
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/common/ge_common/error_codes_define.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/common/ge_common/scope_guard.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/common/ge_common
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/common/ge_common/debug/ge_log.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/common/ge_common/debug
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/exe_graph/runtime/gert_mem_allocator.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/exe_graph/runtime/gert_mem_block.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/exe_graph/runtime/gert_tensor_data.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/exe_graph/runtime
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/graph/any_value.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/graph/def_types.h
              ${CMAKE_SOURCE_DIR}/pkg_inc/graph/type_utils.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/graph
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/pkg_inc/base/asc/tilingdata_base_impl.h
        DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/pkg_inc/base/asc
        COMPONENT metadef
)

install(FILES ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/context_holder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_context_builder_base.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_tiling_parse_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_tiling_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_infer_datatype_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_infer_shape_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_infer_shape_range_context_builder.h
              ${CMAKE_SOURCE_DIR}/inc/external/base/context_builder/op_kernel_run_context_builder.h
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/base/context_builder
    COMPONENT metadef
)
install(FILES ${CMAKE_SOURCE_DIR}/inc/external/base/runtime/runtime_attrs_def.h
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/base/runtime
    COMPONENT metadef
)
set(EXTERNAL_REGISTRY_FILES
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_impl_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_impl_kernel_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register_types.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register_fmk_types.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register_error_codes.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/op_bin_info.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/tilingdata_base.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/device_op_impl_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/register/register.h
)
install(FILES ${EXTERNAL_REGISTRY_FILES}
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/register
    COMPONENT metadef
)

set(EXTERNAL_ASC_REGISTRY_FILES
    ${CMAKE_SOURCE_DIR}/inc/external/asc/register/op_config_registry.h
    ${CMAKE_SOURCE_DIR}/inc/external/asc/register/op_def_factory.h
    ${CMAKE_SOURCE_DIR}/inc/external/asc/register/op_def.h
    ${CMAKE_SOURCE_DIR}/inc/external/asc/register/op_def_registry.h
)
install(FILES ${EXTERNAL_ASC_REGISTRY_FILES}
    DESTINATION ${CMAKE_SYSTEM_PROCESSOR}-linux/include/register/asc
    COMPONENT metadef
)

if (NOT ENABLE_COV AND NOT ENABLE_UT)
    set_cann_cpack_config(metadef ENABLE_DEVICE ${ENABLE_DEVICE} SHARE_INFO_NAME metadef)
endif()