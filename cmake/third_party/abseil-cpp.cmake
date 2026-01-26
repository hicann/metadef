# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

include(ExternalProject)

set(REQ_URL "${ASCEND_3RD_LIB_PATH}/abseil-cpp/abseil-cpp-20230802.1.tar.gz")
# 初始化可选参数列表
set(ABSEIL_EXTRA_ARGS "")
if(EXISTS ${REQ_URL})
  message(STATUS "[ThirdPartyLib][abseil-cpp] ${REQ_URL} found.")
else()
  message(STATUS "[ThirdPartyLib][abseil-cpp] ${REQ_URL} not found, need download.")
  set(REQ_URL "https://gitcode.com/cann-src-third-party/abseil-cpp/releases/download/20230802.1/abseil-cpp-20230802.1.tar.gz")
  list(APPEND ABSEIL_EXTRA_ARGS
      DOWNLOAD_DIR ${ASCEND_3RD_LIB_PATH}/abseil-cpp
  )
endif()

ExternalProject_Add(abseil_build
                    URL ${REQ_URL}
                    ${ABSEIL_EXTRA_ARGS}
                    PATCH_COMMAND patch -p1 < ${CMAKE_CURRENT_LIST_DIR}/build/modules/patch/protobuf-hide_absl_symbols.patch
                    CONFIGURE_COMMAND ""
                    BUILD_COMMAND ""
                    INSTALL_COMMAND ""
                    EXCLUDE_FROM_ALL TRUE 
)