#!/bin/bash
# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------
# 换成你自己的Ascend安装目录
source /usr/local/Ascend/cann/set_env.sh
cd ./tc_ge_irrun_open_api_0014; make clean; make
if [ ! -d "tc_ge_irrun_open_api_0014_npu_output_" ]; then
    mkdir tc_ge_irrun_open_api_0014_npu_output_
fi
find . -print | sed -e 's;[^/]*/;|____;g;s;____|;    |;g'
cd ..
find . -print | sed -e 's;[^/]*/;|____;g;s;____|;    |;g'
./tc_ge_irrun_open_api_0014.bin
