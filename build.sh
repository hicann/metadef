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

BASEPATH=$(cd "$(dirname $0)"; pwd)
OUTPUT_PATH="${BASEPATH}/output"
BUILD_OUT_PATH="${BASEPATH}/build_out"
BUILD_RELATIVE_PATH="build"

# MDC build para
ENABLE_BUILD_DEVICE=ON
USE_CXX11_ABI=0
CMAKE_TOOLCHAIN_FILE_VAL=""

# print usage message
usage() {
  echo "Usage:"
  echo "  sh build.sh [-h | --help] [-v | --verbose] [-j<N>]"
  echo "              [--output_path=<PATH>] [--cann_3rd_lib_path=<PATH>]"
  echo "              [--enable_symengine] [--build-type]"
  echo "              [--asan] [--cov]"
  echo ""
  echo "Options:"
  echo "    -h, --help     Print usage"
  echo "    -v, --verbose  Show detailed build commands during the build process"
  echo "    -j<N>          Set the number of threads used for building Metadef, default is 8"
  echo "    --asan         Enable AddressSanitizer"
  echo "    --cov          Enable Coverage"
  echo "    --output_path=<PATH>"
  echo "                   Set output path, default ./output"
  echo "    --enable_symengine"
  echo "                   find symengine and boost"
  echo "    --build-type=<TYPE>"
  echo "                   Specify build type (TYPE option: Release/Debug), Default: Release"
  echo "    --cann_3rd_lib_path=<PATH>"
  echo "                      Set third_party package install path, default ./output/third_party"
  echo "                      (Third_party package will cost a little time during the first compilation," 
  echo "                      it will skip compilation to save time during subsequent builds)" 
  echo ""
}

parse_cmake_extra_args() {
    echo "Parse cmake extra args."
    # para check
    local args_str="$1"
    if [[ -z "$args_str" ]]; then
        echo "The parsed parameter string is empty."
        return 0
    fi

    IFS=',' read -ra kv_pairs <<< "$args_str"

    for kv_pair in "${kv_pairs[@]}"; do
        if [[ -z "$kv_pair" ]]; then
            continue
        fi

        local key="${kv_pair%%=*}"
        local value="${kv_pair#*=}"

        case "$key" in
            "ENABLE_BUILD_DEVICE")
                ENABLE_BUILD_DEVICE="$value"
                echo "Set ENABLE_BUILD_DEVICE to ${ENABLE_BUILD_DEVICE}."
                ;;
            "USE_CXX11_ABI")
                USE_CXX11_ABI="$value"
                echo "Set USE_CXX11_ABI to ${USE_CXX11_ABI}."
                ;;
            "CMAKE_TOOLCHAIN_FILE")
                CMAKE_TOOLCHAIN_FILE_VAL=$(realpath -s "$value")
                echo "Set CMAKE_TOOLCHAIN_FILE_VAL to ${CMAKE_TOOLCHAIN_FILE_VAL}."
                ;;
            *)
                echo "invalid parameter key: $key"
                ;;
        esac
    done

    if [[ "X$(echo "$USE_CXX11_ABI" | tr '[:upper:]' '[:lower:]')" == "xon" || "$USE_CXX11_ABI" == "1" ]]; then
      USE_CXX11_ABI=1
    elif [[ "X$(echo "$USE_CXX11_ABI" | tr '[:upper:]' '[:lower:]')" == "xoff" || "$USE_CXX11_ABI" == "0" ]]; then
      USE_CXX11_ABI=0
    fi
}

# parse and set options
checkopts() {
  VERBOSE=""
  THREAD_NUM=$(grep -c ^processor /proc/cpuinfo)
  ENABLE_METADEF_UT="off"
  ENABLE_SYMENGINE="off"
  ENABLE_METADEF_ST="off"
  ENABLE_METADEF_COV="off"
  ENABLE_BENCHMARK="off"
  GE_ONLY="on"
  ASCEND_INSTALL_PATH="$ASCEND_HOME_PATH"
  CANN_3RD_LIB_PATH="$BASEPATH/output/third_party"
  CMAKE_BUILD_TYPE="Release"

  # Process the options
  parsed_args=$(getopt -a -o j:hv -l help,verbose,enable_symengine,ascend_install_path:,ascend_3rd_lib_path:,cann_3rd_lib_path:,extra-cmake-args:,build-type:,asan,cov,output_path: -- "$@") || {
    usage
    exit 1
  }

  eval set -- "$parsed_args"

  while true; do
    case "$1" in
      -h | --help)
        usage
        exit 0
        ;;
      -j)
        THREAD_NUM="$2"
        shift 2
        ;;
      -v | --verbose)
        VERBOSE="VERBOSE=1"
        shift
        ;;
      --ascend_install_path)
        ASCEND_INSTALL_PATH="$(realpath $2)"
        shift 2
        ;;
      --ascend_3rd_lib_path)
        CANN_3RD_LIB_PATH="$(realpath $2)"
        shift 2
        ;;
      --cann_3rd_lib_path)
        ASCEND_INSTALL_PATH="$ASCEND_HOME_PATH"
        CANN_3RD_LIB_PATH="$(realpath $2)"
        shift 2
        ;;
      --output_path)
        OUTPUT_PATH="$(realpath $2)"
        shift 2
        ;;
      --enable_symengine)
        ENABLE_SYMENGINE="on"
        shift
        ;;
      --build-type)
        if [ "X$2" != "XRelease" ] && [ "X$2" != "XDebug" ]; then
          usage && echo "Error: Invalid value '$2' for option '$1'" && exit 1
        fi
        CMAKE_BUILD_TYPE="$2"
        shift 2
        ;;
      --extra-cmake-args)
        parse_cmake_extra_args "$2"
        shift 2
        ;;
      --asan)
        ENABLE_ASAN="on"
        shift
        ;;
      --cov)
        ENABLE_GCOV="on"
        shift
        ;;
      --)
        shift
        if [ $# -ne 0 ]; then
          echo "ERROR: Undefined parameter detected: $*"
          usage
          exit 1
        fi
        break
        ;;
      *)
        echo "Undefined option: $1"
        usage
        exit 1
        ;;
    esac
  done
}

mk_dir() {
  local create_dir="$1"  # the target to make
  mkdir -pv "${create_dir}"
  echo "created ${create_dir}"
}

# Metadef build start
cmake_generate_make() {
  local build_path="$1"
  local cmake_args="$2"
  mk_dir "${build_path}"
  cd "${build_path}"
  echo "${cmake_args}"
  cmake ${cmake_args} ..
  if [ 0 -ne $? ]; then
    echo "execute command: cmake ${cmake_args} .. failed."
    exit 1
  fi
}

copy_pkg() {
  if [ "${ENABLE_BUILD_DEVICE}" = "ON" ]; then
    mv ${BUILD_PATH}_CPack_Packages/makeself_staging/cann-*.run ${BUILD_OUT_PATH}/
  elif [[ ${CMAKE_TOOLCHAIN_FILE_VAL} == "${BASEPATH}/cmake/llvm_toolchain.cmake" ]]; then
    local aoskernel_file=$(basename "$(echo "$(ls ${BUILD_PATH}_CPack_Packages/makeself_staging/cann-*.run)" | sed 's/_linux-/-aoskernel./g')")
    mv ${BUILD_PATH}_CPack_Packages/makeself_staging/cann-*.run ${BUILD_OUT_PATH}/${aoskernel_file}
  else
    if [ -f "/etc/lsb-release" ]; then
      ubuntu_version=$(grep -E '^DISTRIB_RELEASE=' /etc/lsb-release | cut -d'=' -f2 | xargs)
      ubuntu_version="-ubuntu${ubuntu_version}."
      local runtime_file=$(basename "$(echo "$(ls ${BUILD_PATH}_CPack_Packages/makeself_staging/cann-*.run)" | sed "s/_linux-/${ubuntu_version}/g")")
      mv ${BUILD_PATH}_CPack_Packages/makeself_staging/cann-*.run ${BUILD_OUT_PATH}/${runtime_file}
    else
      echo "Error: operate enviroment is not ubuntu."
      exit 1
    fi
  fi
}

# create build path
build_metadef() {
  echo "create build directory and build Metadef"
  cd "${BASEPATH}"

  BUILD_PATH="${BASEPATH}/${BUILD_RELATIVE_PATH}/"
  CMAKE_ARGS="-D GE_ONLY=$GE_ONLY \
              -D ENABLE_OPEN_SRC=True \
              -D ENABLE_METADEF_UT=${ENABLE_METADEF_UT} \
              -D ENABLE_METADEF_ST=${ENABLE_METADEF_ST} \
              -D ENABLE_METADEF_COV=${ENABLE_METADEF_COV} \
              -D ENABLE_BENCHMARK=${ENABLE_BENCHMARK} \
              -D ENABLE_ASAN=${ENABLE_ASAN} \
              -D ENABLE_GCOV=${ENABLE_GCOV} \
              -D BUILD_WITHOUT_AIR=True \
              -D ASCEND_INSTALL_PATH=${ASCEND_INSTALL_PATH} \
              -D ASCEND_3RD_LIB_PATH=${CANN_3RD_LIB_PATH} \
              -D CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} \
              -D CMAKE_INSTALL_PREFIX=${OUTPUT_PATH} \
              -D ENABLE_SYMENGINE=${ENABLE_SYMENGINE} \
              -D ENABLE_BUILD_DEVICE=${ENABLE_BUILD_DEVICE} \
              -D USE_CXX11_ABI=${USE_CXX11_ABI} \
              -D CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE_VAL} \
              -D FORCE_REBUILD_CANN_3RD=False"

  echo "CMAKE_ARGS is: $CMAKE_ARGS"
  cmake_generate_make "${BUILD_PATH}" "${CMAKE_ARGS}"

  make exe_graph error_manager error_manager_static ${VERBOSE} -j${THREAD_NUM} && \
    make install && make package

  if [ 0 -ne $? ]; then
    echo "execute command: make ${VERBOSE} -j${THREAD_NUM} && make install failed."
    return 1
  fi
  copy_pkg
  echo "Metadef build success!"
}

main() {
  cd "${BASEPATH}"
  checkopts "$@"

  g++ -v
  mk_dir ${OUTPUT_PATH}
  mk_dir ${BUILD_OUT_PATH}
  echo "---------------- Metadef build start ----------------"
  build_metadef || { echo "Metadef build failed."; exit 1; }
  echo "---------------- Metadef build finished ----------------"
}

main "$@"
