# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------
ASCEND_PATH := /usr/local/Ascend/cann/

LOCAL_DIR := ./
FWK_INCLUDE_DIR := $(ASCEND_PATH)/aarch64-linux/include

LOCAL_MODULE_NAME := tc_ge_irrun_open_api_0014.bin
CC := g++
CFLAGS := -std=c++11 -Wall -D_GLIBCXX_USE_CXX11_ABI=0
SRCS := $(wildcard $(LOCAL_DIR)*.cpp)

INCLUDES := -I $(ASCEND_PATH)/opp/built-in/op_graph/inc \
            -I $(FWK_INCLUDE_DIR)/ \
            -I $(FWK_INCLUDE_DIR)/graph \
            -I $(FWK_INCLUDE_DIR)/ge \
            -I $(ASCEND_PATH)/include/acl \
            -I $(ASCEND_PATH)/compiler/include \
            -I $(LOCAL_DIR)

LIBS := -L ${ASCEND_PATH}/compiler/lib64 \
    -L ${ASCEND_PATH}/lib64 \
    -L ${ASCEND_PATH}/runtime/lib64 \
    -L ${ASCEND_PATH}/compiler/lib64/stub \
    -lascendcl \
    -lgraph \
    -lge_runner \
    -lgraph_base \
    -lmetadef \
    -lge_compiler \
    -lruntime \
    -lge_common_base

tc_ge_irrun_open_api_0014.bin:
	$(CC) $(SRCS) $(INCLUDES) $(LIBS) $(CFLAGS) -o ../$(LOCAL_MODULE_NAME)
clean:
	rm -f ../$(LOCAL_MODULE_NAME); rm -rf ./kernel_meta
