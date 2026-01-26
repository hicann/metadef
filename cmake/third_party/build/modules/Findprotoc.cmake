# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET protoc_build)
    return()
endif ()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/protobuf/v25.1.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/protocolbuffers/protobuf/archive/v4.25.1.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/src-openeuler/protobuf/raw/master/protobuf-all-25.1.tar.gz")
endif ()

set(protoc_CXXFLAGS "-Wno-maybe-uninitialized -Wno-unused-parameter -fPIC -fstack-protector-all -D_FORTIFY_SOURCE=2 -D_GLIBCXX_USE_CXX11_ABI=${USE_CXX11_ABI} -O2")
set(protoc_LDFLAGS "-Wl,-z,relro,-z,now,-z,noexecstack")

ExternalProject_Add(protoc_build
                    URL ${REQ_URL}
                    PATCH_COMMAND patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/patch/protobuf_25.1_change_version.patch
                    CONFIGURE_COMMAND ${CMAKE_COMMAND}
                        -Dprotobuf_WITH_ZLIB=OFF
                        -Dprotobuf_BUILD_TESTS=OFF
                        -DBUILD_SHARED_LIBS=OFF
                        -DCMAKE_CXX_FLAGS=${protoc_CXXFLAGS}
                        -DCMAKE_CXX_LDFLAGS=${protoc_LDFLAGS}
                        -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/protoc
                        -Dprotobuf_ABSL_PROVIDER=module
                        -DABSL_ROOT_DIR=${abseil_SOURCE_DIR}
                        <SOURCE_DIR>
                    BUILD_COMMAND $(MAKE)
                    INSTALL_COMMAND $(MAKE) install
                    EXCLUDE_FROM_ALL TRUE
)

add_dependencies(protoc_build abseil_build)
