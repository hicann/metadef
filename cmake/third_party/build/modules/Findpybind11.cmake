# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET pybind11_build)
    return()
endif()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/pybind11/v2.10.3.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/pybind/pybind11/archive/refs/tags/v2.10.3.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/pybind11/repository/archive/v2.10.3.tar.gz")
endif ()

ExternalProject_Add(pybind11_build
                    URL ${REQ_URL}
                    CONFIGURE_COMMAND ${CMAKE_COMMAND}
                        -DPYBIND11_INSTALL=ON
                        -DPYBIND11_TEST=OFF
                        -DPYBIND11_NOPYTHON=ON
                        -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/pybind11
                        <SOURCE_DIR>
                    BUILD_COMMAND $(MAKE)
                    INSTALL_COMMAND $(MAKE) install
                    EXCLUDE_FROM_ALL TRUE
)
