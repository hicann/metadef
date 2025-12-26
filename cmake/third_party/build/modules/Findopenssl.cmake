# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET openssl_build)
    return()
endif()

include(ExternalProject)

if (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL x86_64)
    set(OPENSSL_HOST_LOCAL_ARCH linux-x86_64)
elseif(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL aarch64)
    set(OPENSSL_HOST_LOCAL_ARCH linux-aarch64)
elseif(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL arm)
    set(OPENSSL_HOST_LOCAL_ARCH linux-armv4)
endif ()

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/openssl/openssl-3.0.9.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/openssl/openssl/archive/refs/tags/openssl-3.0.9.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/mirrors/openssl/repository/archive/refs/tags/openssl-3.0.9.tar.gz")
endif ()

set(SAFE_SP_OPTIONS -fstack-protector-strong)
set(COMPILE_OPTIONE -D_FORFIFY_SOURCE=2 -O2 -Wl,-z,relro,-z,now,-z,noexecstack$<$<CONFIG:Release>:,--build-id=none>)

ExternalProject_Add(openssl_build
                    URL ${REQ_URL}
                    TLS_VERIFY OFF
                    CONFIGURE_COMMAND <SOURCE_DIR>/Configure
                        ${OPENSSL_HOST_LOCAL_ARCH} no-afalgeng no-asm no-shared threads enable-ssl3-method no-tests
                        ${SAFE_SP_OPTIONS} ${COMPILE_OPTIONE}
                        --prefix=${CMAKE_INSTALL_PREFIX}/openssl
                        --libdir=lib64
                    BUILD_COMMAND $(MAKE)
                    INSTALL_COMMAND $(MAKE) install_dev
                    EXCLUDE_FROM_ALL TRUE
)

ExternalProject_Add_Step(openssl_build extra_install
    COMMAND ${CMAKE_COMMAND} -E copy_directory <SOURCE_DIR>/include/crypto ${CMAKE_INSTALL_PREFIX}/openssl/include/crypto
    COMMAND ${CMAKE_COMMAND} -E copy_directory <SOURCE_DIR>/include/internal ${CMAKE_INSTALL_PREFIX}/openssl/include/internal
    COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_INSTALL_PREFIX}/openssl ${CMAKE_COMMAND} -E create_symlink lib64 ${CMAKE_INSTALL_LIBDIR}
    DEPENDEES install
)
