# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.16)
include(../fetch_cann_cmake.cmake)
project (MetaDef[CXX])

init_cann_project()

set(METADEF_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../" CACHE PATH "Project top directory")

set(CMAKE_C_FLAGS_RELEASE "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(PRODUCT_SIDE "device")

if (NOT DEFINED CMAKE_MODULE_PATH OR NOT DEFINED CMAKE_PREFIX_PATH)
    # In a developer environment, neither CMAKE_MODULE_PATH nor CMAKE_PREFIX_PATH is set.
    if (NOT DEFINED ASCEND_INSTALL_PATH OR NOT DEFINED CANN_3RD_LIB_PATH)
        message(FATAL_ERROR "Environment setup incomplete.\n"
                "To complete the setup, please refer to https://gitcode.com/cann/metadef/blob/master/docs/build.md#2-%E5%AE%89%E8%A3%85%E8%BD%AF%E4%BB%B6%E5%8C%85.")
    endif ()
endif ()

if (NOT DEFINED CMAKE_MODULE_PATH)
    set(CMAKE_MODULE_PATH
        ${METADEF_DIR}/cmake/modules
        ${METADEF_DIR}/cmake/third_party/scripts/modules
        ${CANN_3RD_LIB_PATH}/cmake/modules
    )
endif()

if (NOT DEFINED CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH
        ${ASCEND_INSTALL_PATH}
    )
endif()

set(INSTALL_DEVICE_LIBRARY_DIR ${CMAKE_HOST_SYSTEM_PROCESSOR}-linux/lib64/device/lib64)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Werror)
endif()

set(HI_PYTHON python3)
set(USE_CXX11_ABI 0)
include(${METADEF_DIR}/cmake/intf_pub_linux.cmake)

# 自研软件包
find_package(securec MODULE REQUIRED)
find_package(unified_dlog MODULE REQUIRED)

add_cann_subdirectories_relative(${METADEF_DIR}
    ${METADEF_DIR}/base
)
