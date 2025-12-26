# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

if (TARGET protoc_grpc_build)
    return()
endif()

include(ExternalProject)

if (CANN_PKG)
    set(REQ_URL "${CANN_PKG}/libs/grpc/grpc-v1.60.0.tar.gz")
elseif (ENABLE_GITHUB)
    set(REQ_URL "https://github.com/grpc/grpc/archive/refs/tags/v1.60.0.tar.gz")
else ()
    set(REQ_URL "https://gitee.com/src-openeuler/grpc/raw/master/grpc-1.60.0.tar.gz")
endif ()

set(GRPC_CXX_FLAGS "-Wl,-z,relro,-z,now,-z,noexecstack -D_FORTIFY_SOURCE=2 -O2 -fstack-protector-all -s -D_GLIBCXX_USE_CXX11_ABI=0")

ExternalProject_Add(protoc_grpc_build
                    URL ${REQ_URL}
                    PATCH_COMMAND ${CMAKE_COMMAND} -E make_directory <SOURCE_DIR>/third_party/opencensus-proto/src
                          COMMAND patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/patch/grpc-fix-compile-bug-in-device.patch
                    CONFIGURE_COMMAND ${CMAKE_COMMAND}
                        # zlib
                        -DgRPC_ZLIB_PROVIDER=none
                        # cares
                        -DgRPC_CARES_PROVIDER=module
                        -DCARES_ROOT_DIR=${CMAKE_BINARY_DIR}/cares_build-prefix/src/cares_build
                        # re2
                        -DgRPC_RE2_PROVIDER=module
                        -DRE2_ROOT_DIR=${CMAKE_BINARY_DIR}/re2_build-prefix/src/re2_build
                        # absl
                        -DgRPC_ABSL_PROVIDER=module
                        -DABSL_ROOT_DIR=${CMAKE_BINARY_DIR}/abseil_build-prefix/src/abseil_build
                        # protobuf
                        -DgRPC_PROTOBUF_PROVIDER=module
                        -DPROTOBUF_ROOT_DIR=${CMAKE_BINARY_DIR}/protobuf_static_build-prefix/src/protobuf_static_build
                        # ssl
                        -DgRPC_SSL_PROVIDER=none
                        # grpc option
                        -DCMAKE_CXX_FLAGS=${GRPC_CXX_FLAGS}
                        -DCMAKE_BUILD_TYPE=Release
                        -DgRPC_BUILD_TESTS=OFF
                        -DCMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_LIBDIR}
                        -DgRPC_BUILD_CSHARP_EXT=OFF
                        -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}/protoc_grpc
                        <SOURCE_DIR>
                    BUILD_COMMAND $(MAKE) protoc grpc_cpp_plugin
                    INSTALL_COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/protoc_grpc && ${CMAKE_COMMAND} -E copy <BINARY_DIR>/grpc_cpp_plugin ${CMAKE_INSTALL_PREFIX}/protoc_grpc
                    EXCLUDE_FROM_ALL TRUE
)

add_dependencies(protoc_grpc_build re2_build cares_build abseil_build protobuf_static_build)
