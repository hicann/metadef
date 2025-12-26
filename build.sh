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
  parsed_args=$(getopt -a -o j:hv -l help,verbose,enable_symengine,ascend_install_path:,ascend_3rd_lib_path:,cann_3rd_lib_path:,build-type:,asan,cov,output_path: -- "$@") || {
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
              -D FORCE_REBUILD_CANN_3RD=False"

  echo "CMAKE_ARGS is: $CMAKE_ARGS"
  cmake_generate_make "${BUILD_PATH}" "${CMAKE_ARGS}"

  make exe_graph error_manager error_manager_static ${VERBOSE} -j${THREAD_NUM} && \
    make install && make package

  if [ 0 -ne $? ]; then
    echo "execute command: make ${VERBOSE} -j${THREAD_NUM} && make install failed."
    return 1
  fi
  mv ${BUILD_PATH}_CPack_Packages/makeself_staging/cann-*.run ${BUILD_OUT_PATH}/
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
