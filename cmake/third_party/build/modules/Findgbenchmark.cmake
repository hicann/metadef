# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET benchmark_build)
    return()
endif()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/benchmark/v1.5.5.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/google/benchmark/archive/v1.5.5.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/benchmark/repository/archive/v1.5.5.tar.gz")
endif ()

set(benchmark_CXXFLAGS "-D_GLIBCXX_USE_CXX11_ABI=0 -D_FORTIFY_SOURCE=2 -O2 -fstack-protector-all -Wl,-z,relro,-z,now,-z,noexecstack")

ExternalProject_Add(benchmark_build
                    URL ${REQ_URL}
                    TLS_VERIFY OFF
                    CONFIGURE_COMMAND ${CMAKE_COMMAND}
                        -DBENCHMARK_ENABLE_GTEST_TESTS=OFF
                        -DCMAKE_BUILD_TYPE=Release
                        -DCMAKE_CXX_FLAGS=${benchmark_CXXFLAGS}
                        -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/benchmark
                        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
                        -DCMAKE_POSITION_INDEPENDENT_CODE=ON
                        -DBUILD_SHARED_LIBS=ON
                        -DCMAKE_MACOSX_RPATH=TRUE
                        <SOURCE_DIR>
                    BUILD_COMMAND $(MAKE)
                    INSTALL_COMMAND $(MAKE) install
                    EXCLUDE_FROM_ALL TRUE
)
