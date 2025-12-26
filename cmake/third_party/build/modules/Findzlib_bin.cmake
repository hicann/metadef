# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET zlib_bin_build)
    return()
endif()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/zlib/zlib-v1.2.13.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/madler/zlib/archive/refs/tags/v1.2.13.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/zlib/repository/archive/v1.2.13.tar.gz")
endif ()

set(ZLIB_C_FLAGS "-fPIC -fexceptions -O2")

ExternalProject_Add(zlib_bin_build
                    URL ${REQ_URL}
                    CONFIGURE_COMMAND ${CMAKE_COMMAND}
                        -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/zlib
                        -DCMAKE_C_FLAGS=${ZLIB_C_FLAGS}
                        <SOURCE_DIR>
                    BUILD_COMMAND $(MAKE)
                    EXCLUDE_FROM_ALL TRUE
)
