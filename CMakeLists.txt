# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.16)
project (MetaDef[CXX])

set(CMAKE_C_FLAGS_RELEASE "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(PRODUCT_SIDE "host" CACHE STRING "Build target: host or device")
set(METADEF_DEVICE_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/device_output)
# 存在`.dev_env`文件说明是蓝区开发环境，并且调用了`prepare_dev_env.sh`完成了开发环境准备
# 除了设置好`.dev_env`中有的环境变量外，还会设置其他几个蓝区开发的必要变量
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.dev_env")
    set(ENABLE_OPEN_SRC True)
    set(ENABLE_METADEF_UT True)
    set(ENABLE_METADEF_ST True)
    # Read the file into a list of lines
    file(STRINGS "${CMAKE_SOURCE_DIR}/.dev_env" DEV_ENV_LINES)

    # Process each line
    foreach(line IN LISTS DEV_ENV_LINES)
        string(STRIP "${line}" line)
        if(line MATCHES "^([^=]+)=(.*)$")
            set(var_name "${CMAKE_MATCH_1}")
            set(var_value "${CMAKE_MATCH_2}")
            # Remove any leading/trailing whitespace
            string(STRIP "${var_name}" var_name)
            string(STRIP "${var_value}" var_value)
            # Set the variable
            set(${var_name} ${var_value})
        endif()
    endforeach()

    set(ASCEND_INSTALL_PATH ${ASCEND_INSTALL_PATH}/latest)
endif()

# 编译缓存
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif(CCACHE_PROGRAM)

if (NOT DEFINED CMAKE_MODULE_PATH OR NOT DEFINED CMAKE_PREFIX_PATH)
    # In a developer environment, neither CMAKE_MODULE_PATH nor CMAKE_PREFIX_PATH is set.
    if (NOT DEFINED ASCEND_INSTALL_PATH OR NOT DEFINED ASCEND_3RD_LIB_PATH)
        message(FATAL_ERROR "Environment setup incomplete.\n"
                "To complete the setup, refer to the 'CLion配置' section in README.md.")
    endif ()
endif ()

if (NOT DEFINED CMAKE_MODULE_PATH)
    set(CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_LIST_DIR}/cmake/modules/sub_module
        ${CMAKE_CURRENT_LIST_DIR}/cmake/modules
        ${CMAKE_CURRENT_LIST_DIR}/cmake/third_party/scripts/modules
        ${ASCEND_3RD_LIB_PATH}/cmake/modules
    )
endif()

if (NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH
        ${ASCEND_3RD_LIB_PATH}/json
        ${ASCEND_3RD_LIB_PATH}/openssl
        ${ASCEND_3RD_LIB_PATH}/protoc
        ${ASCEND_3RD_LIB_PATH}/protoc_grpc
        ${ASCEND_3RD_LIB_PATH}/grpc
        ${ASCEND_3RD_LIB_PATH}/protobuf_static
        ${ASCEND_3RD_LIB_PATH}/ascend_protobuf
        ${ASCEND_3RD_LIB_PATH}/ascend_protobuf_static
        ${ASCEND_3RD_LIB_PATH}/gtest_shared/lib64/cmake/GTest
        ${ASCEND_3RD_LIB_PATH}/benchmark-1.8.3
        ${ASCEND_3RD_LIB_PATH}/pybind11
        ${ASCEND_3RD_LIB_PATH}/symengine/lib/cmake/symengine
        ${ASCEND_3RD_LIB_PATH}/boost/lib/cmake/Boost-1.87.0
        ${ASCEND_INSTALL_PATH}
    )
endif()

include(CMakePrintHelpers)
message(STATUS "Variables in metadef project:")
cmake_print_variables(ASCEND_INSTALL_PATH)
cmake_print_variables(ASCEND_3RD_LIB_PATH)
cmake_print_variables(CMAKE_SYSTEM_PROCESSOR)
cmake_print_variables(CMAKE_BUILD_TYPE)
cmake_print_variables(CMAKE_INSTALL_PREFIX)
cmake_print_variables(CMAKE_PREFIX_PATH)
cmake_print_variables(CMAKE_MODULE_PATH)
cmake_print_variables(ENABLE_OPEN_SRC ENABLE_METADEF_UT ENABLE_METADEF_ST ENABLE_METADEF_COV ENABLE_BENCHMARK GE_ONLY)

set(INSTALL_BASE_DIR "")
set(INSTALL_LIBRARY_DIR lib)
set(INSTALL_RUNTIME_DIR bin)
set(INSTALL_INCLUDE_DIR include)
set(INSTALL_CONFIG_DIR cmake)

include(CMakePackageConfigHelpers)

set(METADEF_DIR ${CMAKE_CURRENT_LIST_DIR})

option(ENABLE_OPEN_SRC "Enable graphengine compile in opensource." FALSE)

if (ENABLE_OPEN_SRC)
    set(HI_PYTHON python3)
    include(cmake/test_funcs.cmake)
    include(cmake/intf_pub_linux.cmake)

    if(ENABLE_METADEF_UT)
        include(cmake/third_party/ascend_protobuf.cmake)
        include(cmake/third_party/json.cmake)
        include(cmake/third_party/gtest.cmake)
        find_package(msprof MODULE REQUIRED)
    else()
        include(cmake/third_party/json.cmake)	
    endif()

    # 自研软件包
    find_package(securec MODULE REQUIRED)
    find_package(unified_dlog MODULE REQUIRED)
    if (NOT (ENABLE_METADEF_UT OR ENABLE_METADEF_ST))
        find_package(mmpa MODULE REQUIRED)
    endif()
    find_package(runtime MODULE REQUIRED)
    find_package(platform MODULE REQUIRED)
endif()

include(cmake/common_funcs.cmake)
add_subdirectory(inc)
add_subdirectory(error_manager)
add_subdirectory(base)

if (ENABLE_METADEF_UT OR ENABLE_METADEF_ST OR ENABLE_BENCHMARK)
    include(cmake/third_party/benchmark.cmake)
    add_subdirectory(tests)
endif()

install(TARGETS exe_graph error_manager opp_registry rt2_registry_static metadef
    EXPORT metadef-targets
    LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR} OPTIONAL COMPONENT opensdk
    ARCHIVE DESTINATION ${INSTALL_LIBRARY_DIR} OPTIONAL COMPONENT opensdk
    RUNTIME DESTINATION ${INSTALL_RUNTIME_DIR} OPTIONAL COMPONENT opensdk
)

# 下列头文件发布是非法的，需要在后续整改中删掉
# --------------------start------------------------
install(FILES   ${METADEF_DIR}/register/op_tiling/op_tiling_constants.h
                ${METADEF_DIR}/register/op_tiling/op_compile_info_manager.h
                ${METADEF_DIR}/register/op_tiling/op_tiling_utils.h
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/register/op_tiling COMPONENT opensdk EXCLUDE_FROM_ALL
)
install(FILES   ${METADEF_DIR}/graph/normal_graph/operator_impl.h
                ${METADEF_DIR}/graph/normal_graph/op_io.h
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/graph COMPONENT opensdk EXCLUDE_FROM_ALL
)
install(FILES   ${METADEF_DIR}/inc/graph/debug/ge_log.h
                ${METADEF_DIR}/inc/graph/debug/ge_util.h # 被air使用
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/graph/debug COMPONENT opensdk EXCLUDE_FROM_ALL
)
install(FILES   ${METADEF_DIR}/graph/utils/dumper/ge_graph_dumper.h
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/graph/utils/dumper COMPONENT opensdk EXCLUDE_FROM_ALL
)
# ---------------------end-------------------------

install(DIRECTORY ${METADEF_DIR}/inc/ DESTINATION ${INSTALL_INCLUDE_DIR}/metadef
    COMPONENT opensdk EXCLUDE_FROM_ALL FILES_MATCHING PATTERN "*.h"
)

install(DIRECTORY ${METADEF_DIR}/pkg_inc/ DESTINATION ${INSTALL_INCLUDE_DIR}/metadef
        COMPONENT opensdk EXCLUDE_FROM_ALL FILES_MATCHING PATTERN "*.h"
)

if (PACKAGE STREQUAL "opensdk")
    install(EXPORT metadef-targets DESTINATION ${INSTALL_CONFIG_DIR}
        FILE metadef-targets.cmake COMPONENT opensdk EXCLUDE_FROM_ALL
    )
    set(PKG_NAME metadef)
    configure_package_config_file(${TOP_DIR}/cmake/config/pkg_config_template.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/metadef-config.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIG_DIR}
        PATH_VARS INSTALL_BASE_DIR INSTALL_INCLUDE_DIR INSTALL_LIBRARY_DIR INSTALL_RUNTIME_DIR INSTALL_CONFIG_DIR
        INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}
    )
    unset(PKG_NAME)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/metadef-config.cmake
        DESTINATION ${INSTALL_CONFIG_DIR} COMPONENT opensdk EXCLUDE_FROM_ALL
    )
endif()

if (ENABLE_OPEN_SRC AND "${PRODUCT_SIDE}" STREQUAL "host")
    set(TOOLCHAIN_DIR ${ASCEND_INSTALL_PATH}/toolkit/toolchain/hcc)
    include(ExternalProject)
    ExternalProject_add(metadef_device_ep
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
        CONFIGURE_COMMAND ${CMAKE_COMMAND}
            -G ${CMAKE_GENERATOR}
            -DPRODUCT_SIDE=device
            -DTOOLCHAIN_DIR=${TOOLCHAIN_DIR}
            -DCMAKE_TOOLCHAIN_FILE=${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain/aarch64-hcc-toolchain.cmake
            -DGE_ONLY=${GE_ONLY}
            -DENABLE_OPEN_SRC=${ENABLE_OPEN_SRC}
            -DENABLE_METADEF_UT=${ENABLE_METADEF_UT}
            -DENABLE_METADEF_ST=${ENABLE_METADEF_ST}
            -DENABLE_METADEF_COV=${DENABLE_METADEF_COV}
            -DENABLE_BENCHMARK=${ENABLE_BENCHMARK}
            -DBUILD_WITHOUT_AIR=${BUILD_WITHOUT_AIR}
            -DASCEND_INSTALL_PATH=${ASCEND_INSTALL_PATH}
            -DASCEND_3RD_LIB_PATH=${ASCEND_3RD_LIB_PATH}
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DENABLE_SYMENGINE=${ENABLE_SYMENGINE}
            -DCMAKE_INSTALL_PREFIX=${METADEF_DEVICE_OUTPUT}
            -DFORCE_REBUILD_CANN_3RD=${FORCE_REBUILD_CANN_3RD}
            <SOURCE_DIR>
        BUILD_COMMAND $(MAKE) metadef_device
        INSTALL_COMMAND $(MAKE) install CMAKE_INSTALL_COMPONENT=metadef_device
        BUILD_ALWAYS TRUE
    )
endif()

if (ENABLE_OPEN_SRC AND "${PRODUCT_SIDE}" STREQUAL "host")
    set(ARCH_LINX_PATH "${CMAKE_SYSTEM_PROCESSOR}-linux")

    install(TARGETS error_manager
                    exe_graph
                    opp_registry
                    rt2_registry_static
                    metadef
        LIBRARY DESTINATION ${ARCH_LINX_PATH}/lib64 OPTIONAL COMPONENT packages EXCLUDE_FROM_ALL
        ARCHIVE DESTINATION ${ARCH_LINX_PATH}/lib64 OPTIONAL COMPONENT packages EXCLUDE_FROM_ALL
        RUNTIME DESTINATION ${ARCH_LINX_PATH}/bin OPTIONAL COMPONENT packages EXCLUDE_FROM_ALL
    )

     if(EXISTS "${ASCEND_INSTALL_PATH}/share/info/runtime")
        set(RUNTIME_PKG_PATH "${ASCEND_INSTALL_PATH}/share/info/runtime")
    else()
        set(RUNTIME_PKG_PATH "${ASCEND_INSTALL_PATH}/runtime")
    endif()
 
    set(version_info "${RUNTIME_PKG_PATH}/version.info")
    set(install_script_dir "${CMAKE_CURRENT_BINARY_DIR}/install_scripts/")
 
    set(ASCEND_SCRIPT_DIR "${RUNTIME_PKG_PATH}/script")
    add_custom_target(generate_install_script_metadef ALL
        COMMAND rm -rf ${install_script_dir}
        COMMAND cp -rf ${ASCEND_SCRIPT_DIR} ${install_script_dir}
        COMMAND chmod -R u+w ${install_script_dir}
        COMMAND echo "base_package=runtime\;compiler" > ${install_script_dir}/version.info
        COMMAND echo "backup_dir=metadef" >> ${install_script_dir}/version.info
        COMMAND grep -iE "'^(version|version_dir)='" ${version_info} >> ${install_script_dir}/version.info
    )

    install(DIRECTORY ${install_script_dir}
        DESTINATION . OPTIONAL
        FILE_PERMISSIONS OWNER_EXECUTE OWNER_READ GROUP_READ
        COMPONENT . EXCLUDE_FROM_ALL
    )
    
    if(NOT ENABLE_METADEF_UT)
        include(cmake/package.cmake)
    endif()
endif()
