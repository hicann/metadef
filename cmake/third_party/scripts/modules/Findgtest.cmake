# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (gtest_FOUND)
    message(STATUS "Package gtest has been found.")
    return()
endif()

find_path(GTEST_INCLUDE
        NAMES gtest/gtest.h
        NO_CMAKE_SYSTEM_PATH
        NO_CMAKE_FIND_ROOT_PATH)
find_library(GTEST_STATIC_LIBRARY
        NAMES libgtest.a
        PATH_SUFFIXES lib lib64
        NO_CMAKE_SYSTEM_PATH
        NO_CMAKE_FIND_ROOT_PATH)
find_library(GTEST_MAIN_STATIC_LIBRARY
        NAMES libgtest_main.a
        PATH_SUFFIXES lib lib64
        NO_CMAKE_SYSTEM_PATH
        NO_CMAKE_FIND_ROOT_PATH)
find_library(GMOCK_STATIC_LIBRARY
        NAMES libgmock.a
        PATH_SUFFIXES lib lib64
        NO_CMAKE_SYSTEM_PATH
        NO_CMAKE_FIND_ROOT_PATH)
find_library(GMOCK_MAIN_STATIC_LIBRARY
        NAMES libgmock_main.a
        PATH_SUFFIXES lib lib64
        NO_CMAKE_SYSTEM_PATH
        NO_CMAKE_FIND_ROOT_PATH)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(gtest
        FOUND_VAR
                gtest_FOUND
        REQUIRED_VARS
                GTEST_INCLUDE
                GTEST_STATIC_LIBRARY
                GTEST_MAIN_STATIC_LIBRARY
                GMOCK_STATIC_LIBRARY
                GMOCK_MAIN_STATIC_LIBRARY
    )

if(gtest_FOUND)
        set(GTEST_INCLUDE_DIR ${GTEST_INCLUDE})

        add_library(gtest_static STATIC IMPORTED)
        set_target_properties(gtest_static PROPERTIES
                INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE}"
                IMPORTED_LOCATION "${GTEST_STATIC_LIBRARY}"
                )

        add_library(gtest_main_static STATIC IMPORTED)
        set_target_properties(gtest_main_static PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE}"
            IMPORTED_LOCATION "${GTEST_MAIN_STATIC_LIBRARY}"
            )

        add_library(gmock_static STATIC IMPORTED)
        set_target_properties(gmock_static PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE}"
            IMPORTED_LOCATION "${GMOCK_STATIC_LIBRARY}"
            )

        add_library(gmock_main_static STATIC IMPORTED)
        set_target_properties(gmock_main_static PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE}"
            IMPORTED_LOCATION "${GMOCK_MAIN_STATIC_LIBRARY}"
            )
endif()
