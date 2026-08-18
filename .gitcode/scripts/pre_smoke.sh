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

set -euo pipefail

echo "start run test case, please wait ..."
cd ${WORKSPACE}

export ASCEND_GLOBAL_LOG_LEVEL=2
export ASCEND_SLOG_PRINT_TO_STDOUT=0
source /usr/local/Ascend/cann/set_env.sh

log() {
  local dt
  dt=$(date '+%Y%m%d.%H%M%S')
  echo "===================================================================="
  echo "$dt : $*"
  echo "===================================================================="
}

log "init test case, please wait ..."
rm -rf /root/ascend/log

# ==============================
# 下载 single.tar.gz
# ==============================
log "start run test case, please wait ..."

if [ -z "${run_url:-}" ]; then
    echo "run_url is empty, no need to execute smoke test task"
    exit 0
fi

DOWNLOAD_FILE=$(basename "${run_url}")
echo "Starting to download file: ${DOWNLOAD_FILE}"
wget -nv --no-clobber "${run_url}"

if [ ! -f "${DOWNLOAD_FILE}" ]; then
    echo "File ${DOWNLOAD_FILE} does not exist, no need to execute smoke test task"
    exit 0
fi

FILE_SIZE=$(stat -c%s "${DOWNLOAD_FILE}" 2>/dev/null || echo 0)
if [ "${FILE_SIZE}" -eq 0 ]; then
    echo "No compiled operators, no need to execute smoke test task"
    rm -f "${DOWNLOAD_FILE}"
    exit 0
fi


# ==============================
# 运行测试
# ==============================

# bash CI/cann/public/install_miniconda.sh
# source ~/.bashrc
pip3 install numpy
echo 'y' | bash "${DOWNLOAD_FILE}" --full --install-path=/usr/local/Ascend 2>&1 | tee -a ./run_test.log && source /usr/local/Ascend/cann/set_env.sh
cd example || exit 1
bash run_example.sh 2>&1 | tee -a "${WORKSPACE}/run_test.log"
cd - || exit 1

# ==============================
# 打包log
# ==============================
mkdir -p /root/ascend
slog_name="slog.tar.gz"
cd ${WORKSPACE}
tar -zcf "${slog_name}" -C /root/ascend log

# upload plog
# if python3 /home/upload.py --bucket-name "ascend-ci" --action upload  --local-file "slog.tar.gz" --obs-object-key "${repo_name}/package/${pr_id}/${slog_name}"; then
#   echo "::set-output var=plog_url:https://ascend-ci.obs.cn-north-4.myhuaweicloud.com/${repo_name}/package/${pr_id}/slog.tar.gz"
# fi

# ==============================
# 检查 NPU 状态
# ==============================
log "checking NPU status ..."
mkdir -p ./npu_log
npu-smi info  2>&1 | tee ./npu_log/npu_info.log

# ==============================
# 检查测试结果
# ==============================
log "checking test results ..."

date_time=$(date +%Y%m%d)"."$(date +%H%M%S)
if grep -iE '\b(FAIL|failed|error:)\b' "./run_test.log" | grep -viE "error\)"; then
    echo "$date_time : run test case failed"
    exit 1
fi
