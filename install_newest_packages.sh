#!/bin/bash
# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

set -e
set -u

REPO_HOST="https://ascend-cann.obs.cn-north-4.myhuaweicloud.com"
REPO_TYPE="CANN"
HTTP_OK="200"

# get package file name from url
url="https://ascend-cann.obs.cn-north-4.myhuaweicloud.com/CANN/package_name.txt"
content=$(curl -s -k "$url")
FILE_NAME_X86=$(echo "$content" | grep "x86_64" | tr -d '\r\n')
FILE_NAME_ARM=$(echo "$content" | grep "aarch64" | tr -d '\r\n')
echo "FILE_NAME_X86: $FILE_NAME_X86"
echo "FILE_NAME_ARM: $FILE_NAME_ARM"

# default download path and install path
WORKING_DIR=$(pwd)
DEFAULT_ROOT_DIR="/usr/local/Ascend"
DEFAULT_NORMAL_DIR="${HOME}/Ascend"

usage() {
  echo "Usage:"
  echo "    bash install_newest_packages.sh [-k] [-a] [-i <path>] [-d <path>] [-t <YearMonthDay>]"
  echo "Description:"
  echo "    -h, Display this information."
  echo "    -k, Allow insecure server connections when using SSL."
  echo "    -a, Select aarch64 run package. (Default: x86_64)"
  echo "    -i <path>, Install path. (Default: /usr/local/Ascend for root, \${HOME}/Ascend for regular users)"
  echo "    -d <path>, Download path for saving packages. (Default: install path)"
  echo "    -t <YearMonthDay>, Specify the package version. (e.g., -t 20230821)"
}

checkopts() {
  CUSTOM_INSTALL_PATH=""
  NEWEST_DATE=""
  CA_OPTION=""
  CUSTOM_DOWNLOAD_PATH=""
  FILE_NAME=${FILE_NAME_X86}
  while getopts 'i:t:d:kah' opt; do
    case "${opt}" in
    i)
      CUSTOM_INSTALL_PATH=$(realpath ${OPTARG})
      ;;
    t)
      NEWEST_DATE=${OPTARG}
      ;;
    k)
      CA_OPTION="-k"
      ;;
    a)
      FILE_NAME=${FILE_NAME_ARM}
      ;;
    d)
      CUSTOM_DOWNLOAD_PATH=$(realpath ${OPTARG})
      ;;
    h)
      usage
      exit 1
      ;;
    *)
      log_error "Undefined option: ${opt}"
      usage
      exit 2
      ;;
    esac
  done
}

# ---------- logger functions ----------
log_info() {
  content="[INFO] $(date '+%Y-%m-%d %H:%M:%S') $@"
  echo -e "${content}"
}

log_error() {
  content="[ERROR] $(date '+%Y-%m-%d %H:%M:%S') $@"
  echo -e "\033[31m"${content} "\033[0m"
}

# ---------- package downloader ----------
build_local_dir() {
  echo "$1_newest"
}
build_download_url() {
  local full_time=$1
  local url="${REPO_HOST}/${REPO_TYPE}/$(build_local_dir $full_time)/${FILE_NAME}"
  echo ${url}
}

build_download_path() {
  local base_dir=$1
  local pkg_name="${2}_newest"
  local path="${base_dir}/${pkg_name}"
  echo ${path}
}

verify_url() {
  local url=$1
  local status=0
  set +e
  status=$(curl -k -I -m 5 -o /dev/null -s -w %{http_code} ${url})
  set -e
  echo ${status}
}

probe_newest_package() {
  local url=""
  local status=0
  local start=$(date +%Y%m%d)
  local end=$(date -d "-28 day ${start}" +%Y%m%d)
  log_info "Start to probe the newest package from ${start} to ${end}"
  while [ ${start} -ge ${end} ]; do
    url=$(build_download_url ${start})
    if [[ $(verify_url ${url}) -eq ${HTTP_OK} ]]; then
      # find the latest package and update the global variable
      NEWEST_DATE=${start}
      log_info "The latest package version found: [${NEWEST_DATE}_newest]"
      break
    fi
    start=$(date -d "-1 day ${start}" +%Y%m%d)
    url=""
    # set request interval to avoid potential Access Denied
    sleep 0.2
  done

  if [[ -z ${url} ]]; then
    log_error "Failed to find the newest package in the last 4 weeks, please check."
    exit 1
  fi
}

# ---------- package installer ----------
install_full_package() {
  local newest_pkg_path=$1
  local install_path="$2/$3"
  log_info "Begin to extract and install packages to ${install_path}."

  cd ${newest_pkg_path}
  chmod u+x Ascend-cann-toolkit_*.run

  CANN_INFO_FILE="${CUSTOM_INSTALL_PATH}/ascend_cann_install.info"
  if [ -f "$CANN_INFO_FILE" ]; then
      echo "File $CANN_INFO_FILE exist，deleting..."
      rm -f "$CANN_INFO_FILE"
      echo "File deleted."
  fi

  ./${FILE_NAME} --install-path=${install_path} --full --quiet

  rm -rf $2/latest
  ln -s ${install_path}/ascend-toolkit/latest $2/latest
  log_info "Complete installing full package"
}

# ---------- main procedure ----------
# check options
checkopts "$@"

# setup the package version
if [[ ${NEWEST_DATE} =~ ^20 ]]; then
  # user-specified package version
  log_info "Download package with user-specified version ${NEWEST_DATE}"
  DOWNLOAD_URL=$(build_download_url ${NEWEST_DATE})
  if [[ $(verify_url ${DOWNLOAD_URL}) -ne ${HTTP_OK} ]]; then
    log_error "Invalid package version: ${NEWEST_DATE}_newest. Please check the version and network accessibility."
    exit 1
  fi
else
  # automatically probe package version
  probe_newest_package
  DOWNLOAD_URL=$(build_download_url ${NEWEST_DATE})
fi

# check and build install path if CUSTOM_INSTALL_PATH is not specified
if [[ -z ${CUSTOM_INSTALL_PATH} ]]; then
  if [[ $(id -u) -eq 0 ]]; then
    # root user
    CUSTOM_INSTALL_PATH=${DEFAULT_ROOT_DIR}
  else
    # normal user
    CUSTOM_INSTALL_PATH=${DEFAULT_NORMAL_DIR}
  fi
fi

if [[ -z "${CUSTOM_DOWNLOAD_PATH}" ]]; then
  CUSTOM_DOWNLOAD_PATH="${CUSTOM_INSTALL_PATH}/$(build_local_dir ${NEWEST_DATE})"
fi

# check and build download path
if [[ -f ${CUSTOM_DOWNLOAD_PATH}/${FILE_NAME} ]]; then
  log_error "The newest package [${CUSTOM_DOWNLOAD_PATH}/${FILE_NAME}] already exists, please remove and retry."
  exit 1
fi

# display path info
log_info "Download packages from: ${DOWNLOAD_URL}"
log_info "Save packages to: ${CUSTOM_DOWNLOAD_PATH}/${FILE_NAME}"
log_info "Package's install path: ${CUSTOM_INSTALL_PATH}"

# make install directory and download package
mkdir -p ${CUSTOM_DOWNLOAD_PATH}

curl ${CA_OPTION} -o ${CUSTOM_DOWNLOAD_PATH}/${FILE_NAME} ${DOWNLOAD_URL}

install_full_package "${CUSTOM_DOWNLOAD_PATH}" "${CUSTOM_INSTALL_PATH}" "$(build_local_dir ${NEWEST_DATE})"

log_info "Updated CANN successfully!"
log_info "When building metadef: set cmake option -DASCEND_INSTALL_PATH=${CUSTOM_INSTALL_PATH}/latest"
log_info "When build air: set environment variable ASCEND_INSTALL_PATH=${CUSTOM_INSTALL_PATH}/latest"
