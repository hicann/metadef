# ----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ----------------------------------------------------------------------------------------------------------
include(ExternalProject)

set(ASCEND_PROTOBUF_DIR ${ASCEND_3RD_LIB_PATH}/ascend_protobuf)
# 从已经下载好的路径找
find_path(ASCEND_PROTOBUF_SHARED_INCLUDE
    NAMES google/protobuf/api.pb.h
    NO_CMAKE_SYSTEM_PATH
    NO_CMAKE_FIND_ROOT_PATH)
find_library(ASCEND_PROTOBUF_SHARED_LIBRARY
    NAMES libascend_protobuf.so
    PATH_SUFFIXES lib lib64
    PATHS ${ASCEND_PROTOBUF_DIR}
    NO_DEFAULT_PATH)

if(ASCEND_PROTOBUF_SHARED_INCLUDE AND ASCEND_PROTOBUF_SHARED_LIBRARY)
    set(ascend_protobuf_FOUND TRUE)
else()
    set(ascend_protobuf_FOUND FALSE)
endif()

if(ascend_protobuf_FOUND AND NOT FORCE_REBUILD_CANN_3RD)
    message(STATUS "[ThirdPartyLib][ascend protobuf] ascend_protobuf_shared found, skip compile.")
    cmake_print_variables(ASCEND_PROTOBUF_SHARED_INCLUDE)
    cmake_print_variables(ASCEND_PROTOBUF_SHARED_LIBRARY)
    add_library(ascend_protobuf SHARED IMPORTED)
    set_target_properties(ascend_protobuf PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${ASCEND_PROTOBUF_SHARED_INCLUDE}"
        IMPORTED_LOCATION             "${ASCEND_PROTOBUF_SHARED_LIBRARY}"
    )
    set(ASCEND_PROTOBUF_SHARED_INCLUDE_DIR ${ASCEND_PROTOBUF_SHARED_INCLUDE})
    get_filename_component(ASCEND_PROTOBUF_SHARED_LIBRARY_DIR ${ASCEND_PROTOBUF_SHARED_INCLUDE_DIR}/../lib ABSOLUTE)
    add_library(ascend_protobuf_shared_headers INTERFACE IMPORTED)
    target_include_directories(ascend_protobuf_shared_headers INTERFACE ${ASCEND_PROTOBUF_SHARED_INCLUDE})
else()
    message(STATUS "[ThirdPartyLib][ascend protobuf] ascend protobuf shared not found, finding binary file.")

    set(REQ_URL "${ASCEND_3RD_LIB_PATH}/protobuf/protobuf-all-25.1.tar.gz")
    set(REQ_URL_BACK "${ASCEND_3RD_LIB_PATH}/protobuf/protobuf-25.1.tar.gz")
    # 初始化可选参数列表
    set(PROTOBUF_EXTRA_ARGS "")
    if(EXISTS ${REQ_URL})
        message(STATUS "[ThirdPartyLib][ascend protobuf] ${REQ_URL} found, start compile.")
    elseif(EXISTS ${REQ_URL_BACK})
        message(STATUS "[ThirdPartyLib][ascend protobuf] ${REQ_URL_BACK} found, start compile.")
        set(REQ_URL ${REQ_URL_BACK})
    else()
        message(STATUS "[ThirdPartyLib][ascend protobuf] ${REQ_URL} not found, need download.")
        set(REQ_URL "https://gitcode.com/cann-src-third-party/protobuf/releases/download/v25.1/protobuf-25.1.tar.gz")
        list(APPEND PROTOBUF_EXTRA_ARGS
            DOWNLOAD_DIR ${ASCEND_PROTOBUF_DIR}
        )
    endif()
    
    set(protobuf_CXXFLAGS "-Wno-maybe-uninitialized -Wno-unused-parameter -fPIC -fstack-protector-all -D_FORTIFY_SOURCE=2 -D_GLIBCXX_USE_CXX11_ABI=${USE_CXX11_ABI} -O2 -Dgoogle=ascend_private")
    set(protobuf_LDFLAGS "-Wl,-z,relro,-z,now,-z,noexecstack")

    ExternalProject_Add(ascend_protobuf_build
                        URL ${REQ_URL}
                        ${PROTOBUF_EXTRA_ARGS}
                        PATCH_COMMAND patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/build/modules/patch/protobuf_25.1_change_version.patch
                        CONFIGURE_COMMAND ${CMAKE_COMMAND}
                            -DCMAKE_INSTALL_LIBDIR=lib
                            -Dprotobuf_WITH_ZLIB=OFF
                            -DLIB_PREFIX=ascend_
                            -DCMAKE_SKIP_RPATH=TRUE
                            -Dprotobuf_BUILD_TESTS=OFF
                            -DBUILD_SHARED_LIBS=ON
                            -DCMAKE_CXX_STANDARD=14
                            -DCMAKE_CXX_FLAGS=${protobuf_CXXFLAGS}
                            -DCMAKE_CXX_LDFLAGS=${protobuf_LDFLAGS}
                            -DCMAKE_C_COMPILER_LAUNCHER=${CMAKE_C_COMPILER_LAUNCHER}
                            -DCMAKE_CXX_COMPILER_LAUNCHER=${CMAKE_CXX_COMPILER_LAUNCHER}
                            -DCMAKE_INSTALL_PREFIX=${ASCEND_PROTOBUF_DIR}
                            -Dprotobuf_BUILD_PROTOC_BINARIES=OFF
                            -Dprotobuf_ABSL_PROVIDER=module
                            -DABSL_ROOT_DIR=${CMAKE_BINARY_DIR}/abseil_build-prefix/src/abseil_build
                            <SOURCE_DIR>
                        BUILD_COMMAND $(MAKE)
                        INSTALL_COMMAND $(MAKE) install
                        EXCLUDE_FROM_ALL TRUE
    )
    include(${CMAKE_CURRENT_LIST_DIR}/abseil-cpp.cmake)
    add_dependencies(ascend_protobuf_build abseil_build)

    if (NOT EXISTS ${ASCEND_PROTOBUF_DIR}/include)
        file(MAKE_DIRECTORY "${ASCEND_PROTOBUF_DIR}/include")
    endif ()
    set(ASCEND_PROTOBUF_SHARED_INCLUDE_DIR ${ASCEND_PROTOBUF_DIR}/include)
    add_library(ascend_protobuf SHARED IMPORTED)
    add_dependencies(ascend_protobuf ascend_protobuf_build)
    set_target_properties(ascend_protobuf PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${ASCEND_PROTOBUF_DIR}/include
        IMPORTED_LOCATION             ${ASCEND_PROTOBUF_DIR}/lib/libascend_protobuf.so
    )
    get_filename_component(ASCEND_PROTOBUF_SHARED_LIBRARY_DIR ${ASCEND_PROTOBUF_DIR}/lib ABSOLUTE)
    add_library(ascend_protobuf_shared_headers INTERFACE IMPORTED)
    target_include_directories(ascend_protobuf_shared_headers INTERFACE ${ASCEND_PROTOBUF_DIR}/include)
endif()