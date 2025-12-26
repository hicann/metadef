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
USE_ASAN=$(gcc -print-file-name=libasan.so)

# print usage message
usage() {
  echo "Usage:"
  echo "  sh run_test.sh [-h | --help] [-v | --verbose] [-j<N>]"
  echo "                 [-u | --ut] [-c | --cov]"
  echo "                 [--cann_3rd_lib_path=<PATH>]"
  echo ""
  echo "Options:"
  echo "    -h, --help       Print usage"
  echo "    -v, --verbose    Show detailed build commands during the build process"
  echo "    -j<N>            Set the number of threads used for building Metadef llt, default 8"
  echo "    -u, --ut         Build and execute ut"
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
  ASCEND_3RD_LIB_PATH="$BASEPATH/output/third_party"
  CMAKE_BUILD_TYPE="Release"

  # Process the options
  parsed_args=$(getopt -a -o ubcj:hv -l ut,benchmark,cov,help,verbose,ascend_install_path:,ascend_3rd_lib_path:,cann_3rd_lib_path: -- "$@") || {
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
        ASCEND_3RD_LIB_PATH="$(realpath $2)"
        shift 2
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

  if [ -n "$ASCEND_HOME_PATH" ]; then
    ASCEND_INSTALL_PATH="$ASCEND_HOME_PATH"
  else
    ASCEND_INSTALL_PATH="/usr/local/Ascend/cann"
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
              -D ASCEND_3RD_LIB_PATH=${ASCEND_3RD_LIB_PATH} \
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

# 安全地打印测试统计信息（不受 ASAN/LD_PRELOAD 影响）
# 参数：test_names数组元素... -- output_files数组元素...
print_test_summary_safe() {
  local test_names=()
  local output_files=()
  local found_separator=false
  
  # 解析参数：在 "--" 之前的是 test_names，之后的是 output_files
  for arg in "$@"; do
    if [ "${arg}" = "--" ]; then
      found_separator=true
      continue
    fi
    if [ "${found_separator}" = false ]; then
      test_names+=("${arg}")
    else
      output_files+=("${arg}")
    fi
  done

  echo ""
  echo "=========================================="
  echo "           测试结果汇总"
  echo "=========================================="
  
  local executed_count=0
  local total_all=0
  local passed_all=0
  
  # 收集所有数据行
  local output_lines=()
  output_lines+=("测试套件|已执行|总用例数|通过")
  
  for i in "${!output_files[@]}"; do
    local output_file="${output_files[$i]}"
    local test_name="${test_names[$i]}"
    local executed="否"
    local total_tests="0"
    local passed_tests="0"

    # 安全地读取文件内容，避免受 ASAN 影响
    # 只要文件存在就标记为已执行（即使为空，段错误时可能文件未完全写入）
    if [ -f "${output_file}" ]; then
      executed="是"
      executed_count=$((executed_count + 1))
      local ok_count=0
      # 尝试读取文件内容（即使文件可能为空）
      if [ -s "${output_file}" ]; then
        while IFS= read -r line || [ -n "${line}" ]; do
          # 解析总测试数
          if [[ "${line}" =~ Running[[:space:]]+([0-9]+)[[:space:]]+test[s]? ]]; then
            total_tests="${BASH_REMATCH[1]}"
          fi
          # 解析通过的测试数（汇总行）
          if [[ "${line}" =~ \[[[:space:]]+PASSED[[:space:]]+\][[:space:]]+([0-9]+)[[:space:]]+test[s]? ]]; then
            passed_tests="${BASH_REMATCH[1]}"
          fi
          # 统计每个 [ OK ] 行（段错误时可能没有汇总行，需要逐个统计）
          if [[ "${line}" =~ \[[[:space:]]+OK[[:space:]]+\] ]]; then
            ok_count=$((ok_count + 1))
          fi
        done < "${output_file}"
        # 如果没有找到汇总行，使用统计的 [ OK ] 数量
        if [ "${passed_tests}" -eq 0 ] && [ "${ok_count}" -gt 0 ]; then
          passed_tests=${ok_count}
        fi
      fi
    fi

    total_tests=${total_tests:-0}
    passed_tests=${passed_tests:-0}
    total_tests=$((total_tests + 0))
    passed_tests=$((passed_tests + 0))

    # 如果没有找到Running行，使用passed_tests作为total_tests
    if [ "${total_tests}" -eq 0 ] && [ "${passed_tests}" -gt 0 ]; then
      total_tests=${passed_tests}
    fi

    total_all=$((total_all + total_tests))
    passed_all=$((passed_all + passed_tests))
    output_lines+=("${test_name}|${executed}|${total_tests}|${passed_tests}")
  done
  
  output_lines+=("总计|${executed_count}|${total_all}|${passed_all}")
  
  # 纯 bash 实现对齐：计算每列的最大宽度, 不引入额外的column等依赖
  local col_widths=(0 0 0 0)  # 4列：测试套件、已执行、总用例数、通过
  for line in "${output_lines[@]}"; do
    IFS='|' read -ra fields <<< "${line}"
    for i in "${!fields[@]}"; do
      local field="${fields[$i]}"
      local len=${#field}  # 字符长度（对中文也适用）
      if [ "${len}" -gt "${col_widths[$i]}" ]; then
        col_widths[$i]=${len}
      fi
    done
  done
  
  # 打印对齐后的表格
  for line in "${output_lines[@]}"; do
    IFS='|' read -ra fields <<< "${line}"
    # 使用 printf 格式化，每列之间留 2 个空格
    printf "%-*s  %-*s  %-*s  %-*s\n" \
      "${col_widths[0]}" "${fields[0]}" \
      "${col_widths[1]}" "${fields[1]}" \
      "${col_widths[2]}" "${fields[2]}" \
      "${col_widths[3]}" "${fields[3]}"
  done
  
  echo "=========================================="
  echo ""
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
    
    # 创建临时文件保存每个测试的输出
    local temp_output_metadef="${OUTPUT_PATH}/.test_output_ut_metadef_$$.tmp"
    local temp_output_register="${OUTPUT_PATH}/.test_output_ut_register_$$.tmp"
    local temp_output_error_manager="${OUTPUT_PATH}/.test_output_ut_error_manager_$$.tmp"
    local temp_output_sc_check="${OUTPUT_PATH}/.test_output_ut_sc_check_$$.tmp"
    
    # 运行所有测试用例，使用 && 连接，成功才执行下一个
    # 测试程序显式指定 LD_PRELOAD 和 ASAN_OPTIONS
    # 使用 env -u 完全清除 LD_PRELOAD，确保 tee 不受影响
    set -o pipefail
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_metadef && (ASAN_OPTIONS=detect_container_overflow=0 LD_PRELOAD="${USE_ASAN}" ${RUN_TEST_CASE}) 2>&1 | env -u LD_PRELOAD -u ASAN_OPTIONS tee "${temp_output_metadef}" &&
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_register && (ASAN_OPTIONS=detect_container_overflow=0 LD_PRELOAD="${USE_ASAN}" ${RUN_TEST_CASE}) 2>&1 | env -u LD_PRELOAD -u ASAN_OPTIONS tee "${temp_output_register}" &&
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_error_manager && (ASAN_OPTIONS=detect_container_overflow=0 LD_PRELOAD="${USE_ASAN}" ${RUN_TEST_CASE}) 2>&1 | env -u LD_PRELOAD -u ASAN_OPTIONS tee "${temp_output_error_manager}" &&
    RUN_TEST_CASE=${OUTPUT_PATH}/ut_sc_check && (ASAN_OPTIONS=detect_container_overflow=0 LD_PRELOAD="${USE_ASAN}" ${RUN_TEST_CASE}) 2>&1 | env -u LD_PRELOAD -u ASAN_OPTIONS tee "${temp_output_sc_check}"
    local test_status=$?
    set +o pipefail

    # 给tee一点时间刷新缓冲区（段错误时可能需要）
    sleep 0.1

    # 无论成功还是失败，都尝试打印统计信息（安全的方式）
    local test_names=("ut_metadef" "ut_register" "ut_error_manager" "ut_sc_check")
    print_test_summary_safe "${test_names[@]}" -- "${temp_output_metadef}" "${temp_output_register}" "${temp_output_error_manager}" "${temp_output_sc_check}"

    # 清理临时文件
    rm -f "${temp_output_metadef}" "${temp_output_register}" "${temp_output_error_manager}" "${temp_output_sc_check}" 2>/dev/null || true

    # 检查测试是否失败（保持原来的逻辑）
    if [[ "${test_status}" -ne 0 ]]; then
      echo "!!! UT FAILED, PLEASE CHECK YOUR CHANGES !!!"
      echo -e "\033[31m${RUN_TEST_CASE}\033[0m"
      exit 1
    fi
    if [[ "X$ENABLE_METADEF_COV" = "Xon" ]]; then
      echo "Generating coverage statistics, please wait..."
      cd "${BASEPATH}"
      rm -rf ${BASEPATH}/cov
      mk_dir ${BASEPATH}/cov
      lcov -c \
        -d ${BUILD_RELATIVE_PATH}/base/CMakeFiles/metadef.dir \
        -d ${BUILD_RELATIVE_PATH}/base/CMakeFiles/opp_registry.dir \
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
