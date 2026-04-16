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

# 编译缓存
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif(CCACHE_PROGRAM)

enable_testing()

if (NOT DEFINED CMAKE_MODULE_PATH OR NOT DEFINED CMAKE_PREFIX_PATH)
    # In a developer environment, neither CMAKE_MODULE_PATH nor CMAKE_PREFIX_PATH is set.
    if (NOT DEFINED ASCEND_INSTALL_PATH OR NOT DEFINED CANN_3RD_LIB_PATH)
        message(FATAL_ERROR "Environment setup incomplete.\n"
                "To complete the setup, please refer to https://gitcode.com/cann/metadef/blob/master/docs/build.md#2-%E5%AE%89%E8%A3%85%E8%BD%AF%E4%BB%B6%E5%8C%85.")
    endif ()
endif ()

if (NOT DEFINED CMAKE_MODULE_PATH)
    set(CMAKE_MODULE_PATH
        ${CMAKE_CURRENT_LIST_DIR}/cmake/modules
        ${CMAKE_CURRENT_LIST_DIR}/cmake/third_party/scripts/modules
        ${CANN_3RD_LIB_PATH}/cmake/modules
    )
endif()

if (NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH
        ${CANN_3RD_LIB_PATH}/json
        ${CANN_3RD_LIB_PATH}/openssl
        ${CANN_3RD_LIB_PATH}/protoc
        ${CANN_3RD_LIB_PATH}/protoc_grpc
        ${CANN_3RD_LIB_PATH}/grpc
        ${CANN_3RD_LIB_PATH}/protobuf_static
        ${CANN_3RD_LIB_PATH}/ascend_protobuf
        ${CANN_3RD_LIB_PATH}/ascend_protobuf_static
        ${CANN_3RD_LIB_PATH}/gtest_shared/lib64/cmake/GTest
        ${CANN_3RD_LIB_PATH}/benchmark-1.8.3
        ${CANN_3RD_LIB_PATH}/pybind11
        ${CANN_3RD_LIB_PATH}/symengine/lib/cmake/symengine
        ${CANN_3RD_LIB_PATH}/boost/lib/cmake/Boost-1.87.0
        ${ASCEND_INSTALL_PATH}
    )
endif()

include(CMakePrintHelpers)
message(STATUS "Variables in metadef project:")
cmake_print_variables(ASCEND_INSTALL_PATH)
cmake_print_variables(CANN_3RD_LIB_PATH)
cmake_print_variables(CMAKE_SYSTEM_PROCESSOR)
cmake_print_variables(CMAKE_BUILD_TYPE)
cmake_print_variables(CMAKE_INSTALL_PREFIX)
cmake_print_variables(CMAKE_PREFIX_PATH)
cmake_print_variables(CMAKE_MODULE_PATH)
cmake_print_variables(ENABLE_OPEN_SRC ENABLE_METADEF_UT ENABLE_METADEF_ST ENABLE_METADEF_COV ENABLE_BENCHMARK GE_ONLY)
cmake_print_variables(ENABLE_BUILD_DEVICE USE_CXX11_ABI CMAKE_TOOLCHAIN_FILE)
cmake_print_variables(CMAKE_CXX_COMPILER_ID)

set(INSTALL_BASE_DIR "")
set(INSTALL_LIBRARY_DIR lib)
set(INSTALL_RUNTIME_DIR bin)
set(INSTALL_INCLUDE_DIR include)
set(INSTALL_CONFIG_DIR cmake)
set(INSTALL_DEVICE_LIBRARY_DIR ${CMAKE_SYSTEM_PROCESSOR}-linux/lib64/device/lib64)

include(CMakePackageConfigHelpers)

set(METADEF_DIR ${CMAKE_CURRENT_LIST_DIR})

option(ENABLE_OPEN_SRC "Enable graphengine compile in opensource." FALSE)

if(ENABLE_BUILD_DEVICE)
    # 非MDC编译流程
    set(USE_CXX11_ABI 0)
else()
    string(FIND "${CMAKE_TOOLCHAIN_FILE}" "ubuntu18.04-x86_64-llvm-toolchain.cmake" SUBSTRING_FOUND)
    if(SUBSTRING_FOUND GREATER_EQUAL 0)
        set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY false)
        # MDC编译运行态
        message("MDC compile runtime state.")
        add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=${USE_CXX11_ABI})
    else()
        # MDC编译开发态
        message("MDC compile develop state.")
        set(USE_CXX11_ABI 0)
    endif()
endif()

# 针对 GCC/Clang 编译器, 开启编译告警转报错
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Werror)
endif()
# 针对 Clang 编译器，关闭特定警告（避免 -Werror 触发编译错误）
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(STATUS "Add compile option for Clang.")
    add_compile_options(-Wno-error=unknown-warning-option)
    add_compile_options(-Wno-unused)
    add_compile_options(-Wno-unused-private-field)
    add_compile_options(-Wno-inconsistent-missing-override)
    add_compile_options(-Wno-vla)
    add_compile_options(-Wno-error=inconsistent-missing-override)
    add_compile_options(-Wno-error=vla)
    add_compile_options(-Wno-error=unused)
    add_compile_options(-Wno-error=unused-private-field)
    add_compile_options(-Wno-error)
endif()

# 查看三方软件目录，并尝试调整目录结构
execute_process(
    COMMAND bash scripts/prepare_third_party.sh ${CANN_3RD_LIB_PATH}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE SCRIPT_RESULT
    OUTPUT_VARIABLE SCRIPT_OUTPUT
    ERROR_VARIABLE SCRIPT_ERROR
)

if (ENABLE_OPEN_SRC)
    set(HI_PYTHON python3)
    include(cmake/test_funcs.cmake)
    include(cmake/intf_pub_linux.cmake)

    if(ENABLE_METADEF_UT)
        include(cmake/third_party/build/modules/ascend_protobuf.cmake)
        include(cmake/third_party/build/modules/json.cmake)
        include(cmake/third_party/build/modules/gtest.cmake)
        find_package(msprof MODULE REQUIRED)
    else()
        include(cmake/third_party/build/modules/json.cmake)	
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
set_common_params()
add_subdirectory(inc)
add_subdirectory(error_manager)
add_subdirectory(base)

if (ENABLE_METADEF_UT OR ENABLE_METADEF_ST OR ENABLE_BENCHMARK)
    include(cmake/third_party/build/modules/benchmark.cmake)
    add_subdirectory(tests)
endif()

install(TARGETS exe_graph error_manager opp_registry rt2_registry_static metadef
    EXPORT metadef-targets
    LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR} ${INSTALL_OPTIONAL}
    ARCHIVE DESTINATION ${INSTALL_LIBRARY_DIR} ${INSTALL_OPTIONAL}
    RUNTIME DESTINATION ${INSTALL_RUNTIME_DIR} ${INSTALL_OPTIONAL}
)

# 下列头文件发布是非法的，需要在后续整改中删掉
# --------------------start------------------------
install(FILES   ${METADEF_DIR}/register/op_tiling/op_tiling_constants.h
                ${METADEF_DIR}/register/op_tiling/op_compile_info_manager.h
                ${METADEF_DIR}/register/op_tiling/op_tiling_utils.h
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/register/op_tiling EXCLUDE_FROM_ALL
)
install(FILES   ${METADEF_DIR}/graph/normal_graph/operator_impl.h
                ${METADEF_DIR}/graph/normal_graph/op_io.h
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/graph EXCLUDE_FROM_ALL
)
install(FILES   ${METADEF_DIR}/inc/graph/debug/ge_log.h
                ${METADEF_DIR}/inc/graph/debug/ge_util.h # 被air使用
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/graph/debug EXCLUDE_FROM_ALL
)
install(FILES   ${METADEF_DIR}/graph/utils/dumper/ge_graph_dumper.h
        DESTINATION ${INSTALL_INCLUDE_DIR}/metadef/graph/utils/dumper EXCLUDE_FROM_ALL
)
# ---------------------end-------------------------

install(DIRECTORY ${METADEF_DIR}/inc/ DESTINATION ${INSTALL_INCLUDE_DIR}/metadef
    EXCLUDE_FROM_ALL FILES_MATCHING PATTERN "*.h"
)

install(DIRECTORY ${METADEF_DIR}/pkg_inc/ DESTINATION ${INSTALL_INCLUDE_DIR}/metadef
        EXCLUDE_FROM_ALL FILES_MATCHING PATTERN "*.h"
)

if (PACKAGE STREQUAL "opensdk")
    install(EXPORT metadef-targets DESTINATION ${INSTALL_CONFIG_DIR}
        FILE metadef-targets.cmake EXCLUDE_FROM_ALL
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
        DESTINATION ${INSTALL_CONFIG_DIR} EXCLUDE_FROM_ALL
    )
endif()

if (ENABLE_OPEN_SRC AND "${PRODUCT_SIDE}" STREQUAL "host" AND ENABLE_BUILD_DEVICE)
    set(TOOLCHAIN_DIR ${ASCEND_INSTALL_PATH}/toolkit/toolchain/hcc)
    include(ExternalProject)
    ExternalProject_Add(metadef_device_ep
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
            -DCANN_3RD_LIB_PATH=${CANN_3RD_LIB_PATH}
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DENABLE_SYMENGINE=${ENABLE_SYMENGINE}
            -DCMAKE_INSTALL_PREFIX=${METADEF_DEVICE_OUTPUT}
            -DFORCE_REBUILD_CANN_3RD=${FORCE_REBUILD_CANN_3RD}
            <SOURCE_DIR>
        BUILD_COMMAND $(MAKE) metadef_device
        INSTALL_COMMAND ${CMAKE_COMMAND} --install <BINARY_DIR> --component metadef_device
        BUILD_ALWAYS TRUE
    )
endif()

include(version.cmake)
if(ENABLE_OPEN_SRC)
    check_pkg_build_deps("metadef")
endif()
add_version_info_targets()

if (ENABLE_OPEN_SRC AND "${PRODUCT_SIDE}" STREQUAL "host")
    set(ARCH_LINX_PATH "${CMAKE_SYSTEM_PROCESSOR}-linux")

    install(TARGETS error_manager
                    exe_graph
                    opp_registry
                    rt2_registry_static
                    metadef
        LIBRARY DESTINATION ${ARCH_LINX_PATH}/lib64 OPTIONAL EXCLUDE_FROM_ALL
        ARCHIVE DESTINATION ${ARCH_LINX_PATH}/lib64 OPTIONAL EXCLUDE_FROM_ALL
        RUNTIME DESTINATION ${ARCH_LINX_PATH}/bin OPTIONAL EXCLUDE_FROM_ALL
    )

     if(EXISTS "${ASCEND_INSTALL_PATH}/share/info/runtime")
        set(RUNTIME_PKG_PATH "${ASCEND_INSTALL_PATH}/share/info/runtime")
    else()
        set(RUNTIME_PKG_PATH "${ASCEND_INSTALL_PATH}/runtime")
    endif()
    
    if(NOT ENABLE_METADEF_UT)
        include(cmake/package.cmake)
    endif()
endif()
