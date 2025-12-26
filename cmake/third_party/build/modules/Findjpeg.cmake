# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET jpeg_build)
    return()
endif ()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/libjpeg-turbo/2.1.1.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/libjpeg-turbo/libjpeg-turbo/archive/2.1.1.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/libjpeg-turbo/repository/archive/2.1.1.tar.gz")
endif ()

ExternalProject_Add(jpeg_build
                    URL ${REQ_URL}
                    TLS_VERIFY OFF
                    CONFIGURE_COMMAND ${CMAKE_COMMAND}
                        -DWITH_JPEG8=ON
                        -DWITH_SIMD=ON
                        -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/jpeg
                        -DENABLE_SHARED=FALSE
                        -DCMAKE_C_FLAGS=-fPIC\ -fexceptions\ -D_FORTIFY_SOURCE=2\ -O2
                        <SOURCE_DIR>
                    BUILD_COMMAND $(MAKE)
                    INSTALL_COMMAND $(MAKE) install
                    EXCLUDE_FROM_ALL TRUE
)
