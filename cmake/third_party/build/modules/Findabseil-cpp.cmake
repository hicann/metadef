# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET abseil_build)
    return()
endif ()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/abseil-cpp/abseil-cpp-20230802.1.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/abseil/abseil-cpp/archive/refs/tags/20230802.1.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/abseil-cpp/repository/archive/20230802.1.tar.gz")
endif ()

ExternalProject_Add(abseil_build
                    URL ${REQ_URL}
                    PATCH_COMMAND patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/patch/protobuf-hide_absl_symbols.patch
                    CONFIGURE_COMMAND ""
                    BUILD_COMMAND ""
                    INSTALL_COMMAND ""
                    EXCLUDE_FROM_ALL TRUE
                    DWONLOAD_NO_PROGRESS TRUE
)

ExternalProject_Get_Property(abseil_build SOURCE_DIR)

set(abseil_SOURCE_DIR ${SOURCE_DIR})
