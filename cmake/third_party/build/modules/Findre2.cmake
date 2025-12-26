# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET re2_build)
    return()
endif()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/re2/re2-2024-02-01.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/google/re2/archive/refs/tags/2024-02-01.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/re2/repository/archive/2024-02-01.tar.gz")
endif ()

ExternalProject_Add(re2_build
                    URL ${REQ_URL}
                    PATCH_COMMAND patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/patch/re2-add_compatible_functions.patch
                    CONFIGURE_COMMAND ""
                    BUILD_COMMAND ""
                    INSTALL_COMMAND ""
                    EXCLUDE_FROM_ALL TRUE
                    DWONLOAD_NO_PROGRESS TRUE
)
