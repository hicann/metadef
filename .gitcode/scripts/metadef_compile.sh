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

set -e
function LOG_DO() {
    local date_time
    local BPurple='\e[1;35m'
    local Purple='\e[0;35m'
    local Color_Off='\e[0m'
    date_time=$(date +%Y%m%d-%H%M%S)
    echo -e "${BPurple}[Command]${Color_Off} ${date_time} ${Purple}$*${Color_Off}"
    "$@"
}

cd "${WORKSPACE}" || exit 1
grep -E "^VERSION_ID=" /etc/os-release | cut -d'"' -f2

if [[ "${task_name}" == *ubuntu24* ]]; then
    sudo update-alternatives --set gcc /usr/bin/gcc-14
    if ! head -1 "CMakeLists.txt" | grep -q "CMAKE_EXPORT_COMPILE_COMMANDS"; then
        sed -i "1i set(CMAKE_EXPORT_COMPILE_COMMANDS ON)" "CMakeLists.txt"
    fi
else
    if [[ -f "/opt/rh/devtoolset-7/enable" ]]; then
        echo "source devtoolset"
        source /opt/rh/devtoolset-7/enable
    fi
fi

gcc --version
source /home/jenkins/Ascend/cann/bin/setenv.bash

if [[ "${task_name}" =~ Compile_Asend_ARM_ubuntu24 ]]; then
    echo "api-check=compile" >> "${ATOMGIT_OUTPUT}"
else
    echo "api-check=continue" >> "${ATOMGIT_OUTPUT}"
fi

set +e
LOG_DO bash build.sh --cann_3rd_lib_path="/home/jenkins/opensource"
ret=$?
set -e

if [ $ret -ne 0 ]; then
    echo "Build failed with exit code $ret"
    exit $ret
fi

# 重命名产物
compile_package_name=$(ls "${WORKSPACE}/output" | grep -E '\.run$' | head -n1)
if [[ -z "${compile_package_name}" ]]; then
    echo "No .run package found in output!"
    exit 1
fi

if [[ "${task_name}" == *ubuntu24* ]]; then
    target_name="cann-metadef_linux-aarch64_ubuntu24.run"
else
    target_name="cann-metadef_linux-aarch64.run"
fi

mv "${WORKSPACE}/output/${compile_package_name}" "${WORKSPACE}/output/${target_name}"
