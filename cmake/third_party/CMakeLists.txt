# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.14)
project (ThirdPartyPkg[CXX])

set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_LIST_DIR}/build/modules
)

include(CMakePrintHelpers)
include(CMakePackageConfigHelpers)

message(STATUS "Variables for third_party packages:")
cmake_print_variables(D_PKG_SERVER)
cmake_print_variables(ENABLE_GITHUB)
cmake_print_variables(CMAKE_INSTALL_PREFIX)
cmake_print_variables(CMAKE_MODULE_PATH)

set(INSTALL_BASE_DIR "")
set(INSTALL_LIBRARY_DIR lib)
set(INSTALL_RUNTIME_DIR bin)
set(INSTALL_INCLUDE_DIR include)
set(INSTALL_CONFIG_DIR cmake)
set(CMAKE_INSTALL_LIBDIR lib)

if (D_PKG_SERVER)
    set(CANN_PKG ${D_PKG_SERVER})
    message("Download packages from DPKG server${CANN_PKG}")
elseif (DEFINED ENV{MSLIBS_SERVER})
    set(CANN_PKG "http://$ENV{MSLIBS_SERVER}:8081")
    message("Download packages from MSPKG server")
endif ()

find_package(abseil-cpp MODULE REQUIRED)
find_package(ascend_protobuf_shared MODULE REQUIRED)
find_package(ascend_protobuf_static MODULE REQUIRED)
find_package(cares MODULE REQUIRED)
find_package(grpc MODULE REQUIRED)
find_package(gtest MODULE REQUIRED)
find_package(gtest_shared MODULE REQUIRED)
find_package(json MODULE REQUIRED)
find_package(openssl MODULE REQUIRED)
find_package(protobuf_static MODULE REQUIRED)
find_package(protoc MODULE REQUIRED)
find_package(protoc_grpc MODULE REQUIRED)
find_package(re2 MODULE REQUIRED)
find_package(zlib MODULE REQUIRED)
find_package(zlib_bin MODULE REQUIRED)
find_package(gbenchmark MODULE REQUIRED)
find_package(pybind11 MODULE REQUIRED)
find_package(jpeg MODULE REQUIRED)
find_package(boost MODULE REQUIRED)
find_package(symengine MODULE REQUIRED)

set(ALL_VALID_TARGETS
        abseil_build
        ascend_protobuf_build
        ascend_protobuf_static_build
        cares_build
        grpc_build
        gtest_build
        gtest_shared_build
        json_build
        openssl_build
        protobuf_static_build
        protoc_build
        protoc_grpc_build
        re2_build
        zlib_build
        zlib_bin_build
        benchmark_build
        pybind11_build
        jpeg_build
        boost_build
        symengine_build
)

if (BUILD_TARGETS)
    foreach (target IN LISTS BUILD_TARGETS)
        if (NOT ${target} IN_LIST ALL_VALID_TARGETS)
            message(FATAL_ERROR "Invalid target: ${target}\nValid targets are:\n  ${ALL_VALID_TARGETS}")
        endif ()
        list(APPEND selected_targets ${target})
    endforeach ()
    message(STATUS "Selected build targets: ${selected_targets}")
else ()
    set(selected_targets
            ${ALL_VALID_TARGETS}
            )
    message(STATUS "Building default targets")
endif ()

add_custom_target(select_targets)
add_dependencies(select_targets ${selected_targets})
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/scripts/modules
        DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
