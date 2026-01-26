# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

# include directories
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_BINARY_DIR}/proto/ge)
include_directories(${CMAKE_BINARY_DIR}/proto/metadef_protos)
include_directories(${CMAKE_BINARY_DIR}/proto/metadef_protos/proto)
include_directories(${METADEF_DIR})
include_directories(${METADEF_DIR}/pkg_inc)
include_directories(${METADEF_DIR}/register)
include_directories(${METADEF_DIR}/inc/external)

file(GLOB_RECURSE REGISTER_UT_FILES CONFIGURE_DEPENDS "${METADEF_DIR}/tests/ut/register/*.cc" )

add_executable(ut_register
    ${REGISTER_UT_FILES}
)
add_compile_definitions(CMAKE_BINARY_DIR=\"${CMAKE_BINARY_DIR}\")
target_compile_options(ut_register PRIVATE
    -g --coverage -fprofile-arcs -ftest-coverage -fno-access-control
    -Wno-deprecated-declarations
    -Wall -Wfloat-equal -Werror
    -fno-access-control
)

target_compile_definitions(ut_register PRIVATE
    google=ascend_private
    $<$<STREQUAL:${ENABLE_OPEN_SRC},True>:ONLY_COMPILE_OPEN_SRC>
)

target_link_libraries(ut_register
    intf_pub
    metadef_headers
    runtime_headers
    slog_headers
    msprof_headers
    metadef exe_graph mmpa
    opp_registry
    tilingdata_base
    GTest::gtest
    GTest::gtest_main
    pthread
    ascend_protobuf
    slog_stub
    platform_stub
    json
    c_sec
    error_manager
    mmpa_stub
    -lrt
    -ldl
    -lgcov
    -Wl,--whole-archive
    rt2_registry_static
    -Wl,--no-whole-archive
)

target_link_options(ut_register PRIVATE
        -Wl,--disable-new-dtags
        -Wl,-rpath,${CMAKE_CURRENT_LIST_DIR}
        )

target_include_directories(ut_register PRIVATE
        ${METADEF_DIR}/base/registry
        )
