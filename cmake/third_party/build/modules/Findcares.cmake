# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET cares_build)
    return()
endif()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/cares/c-ares-cares-1_19_1.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/c-ares/c-ares/archive/refs/tags/cares-1_19_1.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/c-ares/repository/archive/cares-1_19_1.tar.gz")
endif ()

ExternalProject_Add(cares_build
                    URL ${REQ_URL}
                    CONFIGURE_COMMAND ""
                    BUILD_COMMAND ""
                    INSTALL_COMMAND ""
                    EXCLUDE_FROM_ALL TRUE
                    DWONLOAD_NO_PROGRESS TRUE
)
