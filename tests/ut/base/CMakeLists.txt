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
include_directories(${METADEF_DIR}/inc/common/util/trace_manager)
include_directories(${CMAKE_BINARY_DIR}/proto/metadef_protos)
include_directories(${CMAKE_BINARY_DIR}/proto/metadef_protos/proto)
include_directories(${METADEF_DIR})
include_directories(${METADEF_DIR}/inc/external)
include_directories(${METADEF_DIR}/graph)
include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_BINARY_DIR}/proto/ge)
include_directories(${CMAKE_BINARY_DIR}/proto/ge/proto)

file(GLOB_RECURSE UT_FILES CONFIGURE_DEPENDS
        "${METADEF_DIR}/tests/ut/base/testcase/*.cc"
        )

file(GLOB_RECURSE FAKER_SRCS CONFIGURE_DEPENDS "${METADEF_DIR}/tests/depends/faker/kernel_run_context_faker*.cc"
        "${METADEF_DIR}/tests/depends/faker/allocator_*.cc"
        )

add_executable(ut_metadef ${UT_FILES} ${FAKER_SRCS})

target_compile_options(ut_metadef PRIVATE
    -g --coverage -fprofile-arcs -ftest-coverage
    -Wno-deprecated-declarations
    -Wall -Wfloat-equal -Werror
    -fno-access-control
)

target_compile_definitions(ut_metadef PRIVATE
    $<$<STREQUAL:${ENABLE_OPEN_SRC},True>:ONLY_COMPILE_OPEN_SRC>
    google=ascend_private
    FUNC_VISIBILITY
)

target_link_libraries(ut_metadef PRIVATE
    intf_pub -lgcov
    -Wl,--no-as-needed
    slog_headers
    metadef_headers metadef opp_registry error_manager
    GTest::gtest GTest::gtest_main ascend_protobuf slog_stub c_sec json mmpa_stub -lrt -ldl
    pthread
)

target_link_options(ut_metadef PRIVATE
        -Wl,--disable-new-dtags
        -Wl,-rpath,${CMAKE_CURRENT_LIST_DIR}
        )

target_include_directories(ut_metadef PRIVATE
    ${METADEF_DIR}/tests/depends
)
