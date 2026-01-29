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

BASEPATH=$(cd "$(dirname $0)/.."; pwd)
OUTPUT_PATH="${BASEPATH}/output"
BUILD_RELATIVE_PATH="build"

# print usage message
usage() {
  echo "Usage:"
  echo "  sh run_test.sh [-h | --help] [-v | --verbose] [-j<N>]"
  echo "                 [-u | --ut] [-b | --benchmark] [-c | --cov]"
  echo "                 [--cann_3rd_lib_path=<PATH>]"
  echo ""
  echo "Options:"
  echo "    -h, --help       Print usage"
  echo "    -v, --verbose    Display build command"
  echo "    -j<N>            Set the number of threads used for building Metadef llt, default 8"
  echo "    -u, --ut         Build and execute ut"
  echo "    -b, --benchmark  Run Benchmark test"
  echo "    -c, --cov        Build ut with coverage tag"
  echo "                     Please ensure that the environment has correctly installed lcov, gcov, and genhtml."
  echo "                     and the version matched gcc/g++."
  echo "    --cann_3rd_lib_path=<PATH>"
  echo "                     Set third_party package install path, default ./output/third_party"
  echo ""
}

# parse and set options
checkopts() {
  VERBOSE=""
  THREAD_NUM=8
  ENABLE_METADEF_UT="off"
  ENABLE_METADEF_ST="off"
  ENABLE_METADEF_COV="off"
  ENABLE_BENCHMARK="off"
  GE_ONLY="on"
  CANN_3RD_LIB_PATH="$BASEPATH/output/third_party"
  CMAKE_BUILD_TYPE="Release"

  # Process the options
  parsed_args=$(getopt -a -o ubcj:hv -l ut,benchmark,cov,help,verbose,cann_3rd_lib_path: -- "$@") || {
    usage
    exit 1
  }

  eval set -- "$parsed_args"

  while true; do
    case "$1" in
      -u | --ut)
        ENABLE_METADEF_UT="on"
        GE_ONLY="off"
        shift
        ;;
      -b | --benchmark)
        ENABLE_BENCHMARK="on"
        GE_ONLY="off"
        shift
        ;;
      -c | --cov)
        ENABLE_METADEF_COV="on"
        GE_ONLY="off"
        shift
        ;;
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
      --cann_3rd_lib_path)
        CANN_3RD_LIB_PATH="$(realpath $2)"
        shift 2
        ;;
      --)
        shift
        break
        ;;
      *)
        echo "Undefined option: $1"
        usage
        exit 1
        ;;
    esac
  done

  if [ -n "$ASCEND_HOME_PATH" ]; then
    ASCEND_INSTALL_PATH="$ASCEND_HOME_PATH"
  else
    echo "Error: No environment variable 'ASCEND_HOME_PATH' was found, please check the cann environment configuration."
    exit 1
  fi
}

mk_dir() {
  local create_dir="$1"  # the target to make
  mkdir -pv "${create_dir}"
  echo "created ${create_dir}"
}

# Metadef llt build start
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
  echo "create build directory and build Metadef llt"
  cd "${BASEPATH}"

  if [[ "X$ENABLE_METADEF_UT" = "Xon" || "X$ENABLE_METADEF_COV" = "Xon" || "X$ENABLE_BENCHMARK" = "Xon" ]]; then
    BUILD_RELATIVE_PATH="build_gcov"
    CMAKE_BUILD_TYPE="GCOV"
  fi

  BUILD_PATH="${BASEPATH}/${BUILD_RELATIVE_PATH}/"
  CMAKE_ARGS="-D GE_ONLY=$GE_ONLY \
              -D ENABLE_OPEN_SRC=True \
              -D ENABLE_METADEF_UT=${ENABLE_METADEF_UT} \
              -D ENABLE_METADEF_ST=${ENABLE_METADEF_ST} \
              -D ENABLE_METADEF_COV=${ENABLE_METADEF_COV} \
              -D ENABLE_BENCHMARK=${ENABLE_BENCHMARK} \
              -D BUILD_WITHOUT_AIR=True \
              -D ASCEND_INSTALL_PATH=${ASCEND_INSTALL_PATH} \
              -D ASCEND_3RD_LIB_PATH=${CANN_3RD_LIB_PATH} \
              -D CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} \
              -D CMAKE_INSTALL_PREFIX=${OUTPUT_PATH}"

  echo "CMAKE_ARGS is: $CMAKE_ARGS"
  cmake_generate_make "${BUILD_PATH}" "${CMAKE_ARGS}"

  if [[ "X$ENABLE_METADEF_UT" = "Xon" || "X$ENABLE_METADEF_COV" = "Xon" ]]; then
    make ut_metadef ut_register ut_error_manager ut_exe_meta_device ut_sc_check ${VERBOSE} -j${THREAD_NUM}
  fi

  if [ 0 -ne $? ]; then
    echo "execute command: make ${VERBOSE} -j${THREAD_NUM} && make install failed."
    return 1
  fi
  echo "Metadef build success!"
}

main() {
  cd "${BASEPATH}"
  checkopts "$@"

  if [ "X$ENABLE_METADEF_UT" != "Xon" ] && [ "X$ENABLE_BENCHMARK" != "Xon" ]; then
    ENABLE_METADEF_UT=on
  fi

  g++ -v
  mk_dir ${OUTPUT_PATH}
  echo "---------------- Metadef llt build start ----------------"
  build_metadef || { echo "Metadef llt build failed."; exit 1; }
  echo "---------------- Metadef llt build finished ----------------"

  if [[ "X$ENABLE_METADEF_UT" = "Xon" || "X$ENABLE_METADEF_COV" = "Xon" ]]; then
    cp ${BUILD_PATH}/tests/ut/base/ut_metadef ${OUTPUT_PATH}
    cp ${BUILD_PATH}/tests/ut/register/ut_register ${OUTPUT_PATH}
    cp ${BUILD_PATH}/tests/ut/error_manager/ut_error_manager ${OUTPUT_PATH}
    cp ${BUILD_PATH}/tests/ut/sc_check/ut_sc_check ${OUTPUT_PATH}
    export ASAN_OPTIONS=detect_container_overflow=0
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_metadef && ${RUN_TEST_CASE} &&
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_register && ${RUN_TEST_CASE} &&
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_error_manager && ${RUN_TEST_CASE} &&
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_sc_check && ${RUN_TEST_CASE}
    if [[ "$?" -ne 0 ]]; then
      echo "!!! UT FAILED, PLEASE CHECK YOUR CHANGES !!!"
      echo -e "\033[31m${RUN_TEST_CASE}\033[0m"
      exit 1
    fi
    unset ASAN_OPTIONS

    if [[ "X$ENABLE_METADEF_COV" = "Xon" ]]; then
      echo "Generating coverage statistics, please wait..."
      cd "${BASEPATH}"
      rm -rf ${BASEPATH}/cov
      mk_dir ${BASEPATH}/cov
      lcov -c \
        -d ${BUILD_RELATIVE_PATH}/base/CMakeFiles/metadef.dir \
        -d ${BUILD_RELATIVE_PATH}/base/CMakeFiles/opp_registry.dir \
        -d ${BUILD_RELATIVE_PATH}/base/CMakeFiles/tilingdata_base.dir \
        -d ${BUILD_RELATIVE_PATH}/error_manager/CMakeFiles/error_manager.dir \
        -d ${BUILD_RELATIVE_PATH}/base/CMakeFiles/exe_graph.dir \
        -d ${BUILD_RELATIVE_PATH}/base/CMakeFiles/rt2_registry_objects.dir \
        -o cov/tmp.info
      lcov -r cov/tmp.info '*/output/*' \
                           '/usr/*' \
                           -o cov/coverage.info
      cd "${BASEPATH}/cov"
      genhtml coverage.info
    fi
  fi

  echo "---------------- Metadef llt finished ----------------"
}

main "$@"
