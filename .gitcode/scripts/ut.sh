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

set -ex

function LOG_DO() {
    local date_time
    local BPurple='\e[1;35m'
    local Purple='\e[0;35m'
    local Color_Off='\e[0m'
    date_time=$(date +%Y%m%d-%H%M%S)
    echo -e "${BPurple}[Command]${Color_Off} ${date_time} ${Purple}$*${Color_Off}"
    "$@"
}

if [ "${GIT_TARGET_BRANCH}" == "master" ] || [ "${GIT_TARGET_BRANCH}" == "develop" ]; then
    sudo update-alternatives --set gcc /usr/bin/gcc-15
else
    sudo update-alternatives --set gcc /usr/bin/gcc-14
fi
if gcc --version | head -n1 | grep -q "15\."; then
    rm -rf /home/jenkins/opensource/lib_cache
    if [ -d /home/jenkins/opensource/gcc15 ]; then
        rm -rf /home/jenkins/opensource/gcc15/lib_cache/abseil-cpp
        rm -rf /home/jenkins/opensource/gcc15/lib_cache/device/abseil-cpp
        ln -s /home/jenkins/opensource/gcc15/lib_cache/ /home/jenkins/opensource/lib_cache
    elif [ -d /home/jenkins/opensource/gcc15x86 ]; then
        rm -rf /home/jenkins/opensource/gcc15x86/lib_cache/abseil-cpp
        rm -rf /home/jenkins/opensource/gcc15x86/lib_cache/device/abseil-cpp
        ln -s /home/jenkins/opensource/gcc15x86/lib_cache/ /home/jenkins/opensource/lib_cache
    fi
elif gcc --version | head -n1 | grep -q "14\."; then
    gcc --version
else
    gcc --version
    rm -rf /home/jenkins/opensource/lib_cache
    ln -s /home/jenkins/opensource/ubuntu20/lib_cache /home/jenkins/opensource/lib_cache
fi
gcc --version
source /home/jenkins/Ascend/cann/bin/setenv.bash || { echo "setenv failed"; exit 1; }

set +e
echo "Start run c++ testcase"
cd "${WORKSPACE}/tests" || exit 1

LOG_DO bash run_test.sh -ut -c --cann_3rd_lib_path="/home/jenkins/opensource"
ret=$?
set -e

if [ "$ret" -ne 200 ] && [ "$ret" -ne 0 ]; then
    echo "run ut fail, exit code: $ret"
    exit 1
fi

if [ -z "${ATOMGIT_OUTPUT:-}" ]; then
    echo "ATOMGIT_OUTPUT is not set"
    exit 1
fi
echo "ut_process=ut_cov" >> "$ATOMGIT_OUTPUT"
exit 0
