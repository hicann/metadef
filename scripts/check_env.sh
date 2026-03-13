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

# ==============================================================================
# metadef 编译环境依赖检查脚本
#
# 仓库:   https://gitcode.com/cann/metadef
# 依据:   https://gitcode.com/cann/metadef/blob/master/docs/build.md
# 用法:   bash scripts/check_env.sh
#
# 本脚本所有检查项和版本约束严格来源于 docs/build.md，
# 如 build.md 更新，请同步修改本脚本顶部的版本变量。
# ==============================================================================

# 不使用 set -e, 避免 grep 无匹配时静默退出

# ==================== 颜色定义 ====================
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# ==================== 计数器 ====================
ERROR_COUNT=0
WARNING_COUNT=0
PASS_COUNT=0

# ==============================================================================
# 版本要求 (严格来源于 docs/build.md, 请勿随意修改)
#
# build.md 原文:
#   - GCC >= 7.3.x
#   - Python3 >= 3.9.x
#   - CMake >= 3.16.0 （建议使用3.20.0版本）
#   - ccache/cov/asan
#   - graph-easy(可选)
# ==============================================================================
REQUIRED_GCC_MIN="7.3.0"         # build.md: GCC >= 7.3.x
REQUIRED_PYTHON_MIN="3.9.0"     # build.md: Python3 >= 3.9.x
REQUIRED_CMAKE_MIN="3.16.0"     # build.md: CMake >= 3.16.0
REQUIRED_CMAKE_RECOMMEND="3.20.0"  # build.md: 建议使用 3.20.0

# ==================== 工具函数 ====================
log_pass() {
    PASS_COUNT=$((PASS_COUNT + 1))
    echo -e "  ${GREEN}[PASS]${NC}    $1"
}

log_warn() {
    WARNING_COUNT=$((WARNING_COUNT + 1))
    echo -e "  ${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    ERROR_COUNT=$((ERROR_COUNT + 1))
    echo -e "  ${RED}[ERROR]${NC}   $1"
}

log_info() {
    echo -e "  ${BLUE}[INFO]${NC}    $1"
}

# 版本比较: version_ge v1 v2 → v1 >= v2
version_ge() {
    # 功能：将两个版本号按版本语义排序后，判断前者是否大于等于后者
    # 说明：printf '%s\n' 用于格式化输出版本号并换行；sort -V 为版本号自然排序；head -n1 取最小版本号
    [ "$(printf '%s\n' "$1" "$2" | sort -V | head -n1)" = "$2" ]
}

# 检查指定命令是否存在于系统环境中
# 参数 $1: 待检查的命令名称（如 gcc、python3）
# 说明：command -v 用于查找命令路径；&>/dev/null 用于静默丢弃所有输出
check_command() {
    command -v "$1" &>/dev/null
}

# 安全提取版本号
# 支持: "11" → "11.0.0",  "25.1" → "25.1.0",  "3.28.2" → "3.28.2"
# 失败返回 "0.0.0"
# 参数 $1: 待提取版本号的输入字符串
extract_version() {
    # 定义局部变量 input，接收函数传入的第一个参数（待处理的版本字符串）
    local input="$1"
    # 定义局部变量 ver，用于存储提取后的版本号
    local ver

    # 先匹配 x.x.x 或 x.x 格式的版本号
    # 说明：
    #   echo "$input"：输出待处理的版本字符串
    #   grep -oP：使用 Perl 兼容正则表达式，仅输出匹配部分
    #   \d+\.\d+(\.\d+)*：匹配 "数字.数字" 或 "数字.数字.数字..." 格式
    #   head -n1：取第一个匹配结果
    #   || true：确保匹配失败时命令返回0，不中断脚本执行
    ver=$(echo "$input" | grep -oP '\d+\.\d+(\.\d+)*' | head -n1 || true)

    # 判断第一步是否匹配到版本号（-z 表示变量为空）
    if [ -z "$ver" ]; then
        # 匹配纯数字 (如 gcc -dumpversion 在某些系统只返回 "11")
        # 说明：\d+ 正则表达式匹配一个或多个数字，其余逻辑同第一步
        ver=$(echo "$input" | grep -oP '\d+' | head -n1 || true)

        # 判断第二步是否匹配到纯数字版本号（-n 表示变量非空）
        if [ -n "$ver" ]; then
            # 补全纯数字版本号为 x.0.0 格式
            ver="${ver}.0.0"
        else
            # 无匹配结果时返回默认版本号 0.0.0
            echo "0.0.0"
            return
        fi
    fi

    # 判断版本号是否为 x.x 格式（如 "25.1"）
    if [[ "$ver" =~ ^[0-9]+\.[0-9]+$ ]]; then
        # 补全 x.x 格式为 x.x.0 格式
        ver="${ver}.0"
    fi

    # 输出最终处理后的标准格式版本号
    echo "$ver"
}

print_header() {
    echo ""
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${BLUE}  $1${NC}"
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
}

# ==============================================================================
#                          开始检查
# ==============================================================================
echo ""
echo "=================================================================="
echo "  metadef 编译环境依赖检查"
echo "  仓库: 项目源码仓库（metadef 模块）"
echo "  依据: docs/build.md"
echo "  时间: $(date '+%Y-%m-%d %H:%M:%S')"
# 输出系统信息：uname -s 获取内核名称，uname -m 获取硬件架构
echo "  系统: $(uname -s) $(uname -m)"
echo "=================================================================="

# ==================== 1. 操作系统 ====================
print_header "1. 操作系统 [可选]"

# 获取系统内核名称：uname -s 参数返回操作系统内核名称（如 Linux、Darwin）
OS_NAME=$(uname -s)
# 获取系统硬件架构：uname -m 参数返回硬件架构信息（如 x86_64、aarch64）
OS_ARCH=$(uname -m)

# 判断操作系统内核是否为Linux：仅支持Linux系统环境
if [ "$OS_NAME" = "Linux" ]; then
    log_info "操作系统: Linux"
else
    log_info "其他操作系统: $OS_NAME"
fi

# 判断硬件架构是否为x86_64或aarch64：仅验证过这两种架构的兼容性
if [ "$OS_ARCH" = "x86_64" ] || [ "$OS_ARCH" = "aarch64" ]; then
    log_info "CPU 架构: $OS_ARCH"
else
    log_info "其他CPU架构: $OS_ARCH (build.md 验证过 x86_64/aarch64)"
fi

if [ -f /etc/os-release ]; then
    # 提取Linux发行版名称：
    # grep "^ID=" /etc/os-release：匹配os-release文件中以ID=开头的行（发行版标识）
    # cut -d= -f2：以等号为分隔符，截取第二个字段（发行版名称）
    # tr -d '"'：删除字符串中的双引号（统一格式）
    DISTRO=$(grep "^ID=" /etc/os-release | cut -d'=' -f2 | tr -d '"')
    # 提取Linux发行版版本号：
    # grep "^VERSION_ID=" /etc/os-release：匹配以VERSION_ID=开头的行（版本号标识）
    # cut -d= -f2：截取等号后的版本号字段
    # tr -d '"'：删除双引号，统一版本号格式
    DISTRO_VER=$(grep "^VERSION_ID=" /etc/os-release | cut -d'=' -f2 | tr -d '"')
    log_info "发行版: $DISTRO $DISTRO_VER"
fi

# ==================== 2. GCC ====================
# build.md: GCC >= 7.3.x (无上限)
print_header "2. GCC/G++ [build.md: >= $REQUIRED_GCC_MIN]"

if check_command gcc; then
    # 获取gcc原始版本信息：gcc -dumpversion 输出gcc的主版本号（如 11.2）
    GCC_RAW=$(gcc -dumpversion)
    # 提取标准化版本号：调用extract_version函数将原始版本转为x.x.x格式（如 11 → 11.0.0）
    GCC_VER=$(extract_version "$GCC_RAW")
    log_info "gcc -dumpversion: $GCC_RAW → $GCC_VER"

    # 判断gcc版本是否满足最低要求：调用version_ge函数比较版本号（GCC_VER >= REQUIRED_GCC_MIN）
    if version_ge "$GCC_VER" "$REQUIRED_GCC_MIN"; then
        log_pass "GCC $GCC_VER (>= $REQUIRED_GCC_MIN)"
    else
        log_error "GCC 版本过低: $GCC_VER (build.md 要求 >= $REQUIRED_GCC_MIN)"
        log_info "安装 (Ubuntu): sudo apt-get install build-essential"
        log_info "安装 (CentOS): sudo yum install devtoolset-7-gcc devtoolset-7-gcc-c++"
    fi
else
    log_error "未安装 GCC (build.md 要求 >= $REQUIRED_GCC_MIN)"
    log_info "安装 (Ubuntu): sudo apt-get install build-essential"
fi

if check_command g++; then
    # 获取g++原始版本信息：g++ -dumpversion 输出g++的主版本号（如 11.2）
    GPP_RAW=$(g++ -dumpversion)
    # 提取标准化版本号：调用extract_version函数将原始版本转为x.x.x格式（如 11 → 11.0.0）
    GPP_VER=$(extract_version "$GPP_RAW")
    log_pass "G++ $GPP_VER"
else
    log_error "未安装 G++"
    log_info "安装 (Ubuntu): sudo apt-get install g++"
fi

# ==================== 3. Python3 ====================
# build.md: Python3 >= 3.9.x
print_header "3. Python3 [build.md: >= $REQUIRED_PYTHON_MIN]"

PYTHON_CMD=""
# 优先检查python3命令是否存在
if check_command python3; then
    PYTHON_CMD="python3"
    # 获取Python原始版本信息：2>&1 将标准错误重定向到标准输出（--version默认输出到stderr）
    PYTHON_RAW=$($PYTHON_CMD --version 2>&1)
    # 提取标准化版本号：调用extract_version函数从版本字符串中提取x.x.x格式版本号
    PYTHON_VER=$(extract_version "$PYTHON_RAW")
# 其次检查python命令是否存在
elif check_command python; then
    PYTHON_CMD="python"
    # 获取Python原始版本信息：2>&1 将标准错误重定向到标准输出（--version默认输出到stderr）
    PYTHON_RAW=$($PYTHON_CMD --version 2>&1)
    # 提取标准化版本号：调用extract_version函数从版本字符串中提取x.x.x格式版本号
    PYTHON_VER=$(extract_version "$PYTHON_RAW")
fi

# 判断是否获取到有效的Python命令（-n 表示变量非空）
if [ -n "$PYTHON_CMD" ]; then
    log_info "$PYTHON_CMD --version: $PYTHON_RAW → $PYTHON_VER"

    # 判断Python版本是否满足最低要求：调用version_ge函数比较版本号（PYTHON_VER >= REQUIRED_PYTHON_MIN）
    if version_ge "$PYTHON_VER" "$REQUIRED_PYTHON_MIN"; then
        log_pass "Python $PYTHON_VER (>= $REQUIRED_PYTHON_MIN)"
    else
        log_error "Python 版本过低: $PYTHON_VER (build.md 要求 >= $REQUIRED_PYTHON_MIN)"
        log_info "请安装 Python 3.9 或更高版本"
    fi

    # 获取Python头文件（include）路径：用于编译C扩展
    # 说明：
    #   $PYTHON_CMD -c：执行单行Python代码
    #   sysconfig.get_path('include')：获取Python头文件的安装路径
    #   2>/dev/null：将标准错误重定向到空（避免无权限/环境异常时输出错误信息）
    #   || true：确保命令执行失败时返回值为0，不中断脚本
    PYTHON_INCLUDE=$($PYTHON_CMD -c "import sysconfig; print(sysconfig.get_path('include'))" 2>/dev/null || true)
    # 判断Python头文件路径是否有效：
    #   -z "$PYTHON_INCLUDE"：判断变量是否为空（无路径）
    #   && [ "$PYTHON_INCLUDE" != "None" ]：同时判断路径是否不等于"None"（排除无效返回值）
    #   业务目的：校验是否存在有效的Python头文件路径（编译C扩展必需）
    if [ -n "$PYTHON_INCLUDE" ] && [ -f "$PYTHON_INCLUDE/Python.h" ]; then
        log_pass "Python 开发头文件: $PYTHON_INCLUDE/Python.h"
    else
        log_error "缺少 Python.h"
        log_info "安装 (Ubuntu): sudo apt-get install python3-dev"
        log_info "安装 (CentOS): sudo yum install python3-devel"
    fi
else
    log_error "未安装 Python3 (build.md 要求 >= $REQUIRED_PYTHON_MIN)"
    log_info "安装 (Ubuntu): sudo apt-get install python3 python3-dev"
fi

# ==================== 4. CMake ====================
# build.md: CMake >= 3.16.0 (建议使用 3.20.0 版本)
print_header "4. CMake [build.md: >= $REQUIRED_CMAKE_MIN, 建议 $REQUIRED_CMAKE_RECOMMEND]"

# 检查cmake命令是否存在
if check_command cmake; then
    # 获取cmake原始版本信息：cmake --version 输出首行包含版本号，head -n1 取首行
    CMAKE_RAW=$(cmake --version | head -n1)
    # 提取标准化版本号：调用extract_version函数将原始版本转为x.x.x格式
    CMAKE_VER=$(extract_version "$CMAKE_RAW")
    log_info "cmake --version: $CMAKE_RAW → $CMAKE_VER"

    # 判断cmake版本是否满足建议版本：调用version_ge函数（CMAKE_VER >= 建议版本）
    if version_ge "$CMAKE_VER" "$REQUIRED_CMAKE_RECOMMEND"; then
        log_pass "CMake $CMAKE_VER (>= 建议版本 $REQUIRED_CMAKE_RECOMMEND)"
    # 判断cmake版本是否满足最低要求：调用version_ge函数（CMAKE_VER >= 最低版本
    elif version_ge "$CMAKE_VER" "$REQUIRED_CMAKE_MIN"; then
        log_pass "CMake $CMAKE_VER (>= $REQUIRED_CMAKE_MIN)"
        log_warn "build.md 建议使用 CMake $REQUIRED_CMAKE_RECOMMEND, 当前 $CMAKE_VER"
    else
        log_error "CMake 版本过低: $CMAKE_VER (build.md 要求 >= $REQUIRED_CMAKE_MIN)"
        log_info "升级 (pip):  pip install cmake --upgrade"
        log_info "升级 (源码): CMake 官方下载页面获取最新版本"
    fi
else
    log_error "未安装 CMake (build.md 要求 >= $REQUIRED_CMAKE_MIN)"
    log_info "安装 (Ubuntu): sudo apt-get install cmake"
    log_info "安装 (pip):    pip install cmake"
fi

# ==================== 5. ccache ====================
# build.md: ccache (列为必需依赖)
print_header "5. ccache [build.md: 必需]"

# 检查ccache版本（build.md 必需依赖）
if check_command ccache; then
    # 获取ccache原始版本信息：ccache --version 输出首行，head -n1 取首行
    CCACHE_RAW=$(ccache --version | head -n1)
    # 提取标准化版本号：调用extract_version函数将原始版本转为x.x.x格式
    CCACHE_VER=$(extract_version "$CCACHE_RAW")
    log_info "ccache --version: $CCACHE_RAW → $CCACHE_VER"
    log_pass "ccache $CCACHE_VER"
else
    log_error "未安装 ccache (build.md 要求安装)"
    log_info "安装 (Ubuntu): sudo apt-get install ccache"
    log_info "安装 (CentOS): sudo yum install ccache"
fi

# ==================== 6. lcov (cov) ====================
# build.md: cov → lcov
print_header "6. lcov [build.md: 必需 (cov)]"

# 检查lcov版本（build.md 必需依赖，用于代码覆盖率）
if check_command lcov; then
    # 获取lcov原始版本信息：lcov --version 输出重定向（2>&1）并取首行
    LCOV_RAW=$(lcov --version 2>&1 | head -n1)
    # 提取标准化版本号：调用extract_version函数将原始版本转为x.x.x格式
    LCOV_VER=$(extract_version "$LCOV_RAW")
    log_info "lcov --version: $LCOV_RAW → $LCOV_VER"
    log_pass "lcov $LCOV_VER"
else
    log_error "未安装 lcov (build.md 要求安装, 用于代码覆盖率)"
    log_info "安装 (Ubuntu): sudo apt-get install lcov"
    log_info "安装 (CentOS): sudo yum install lcov"
fi

if check_command genhtml; then
    log_pass "genhtml 已安装 (lcov 附带)"
else
    log_warn "genhtml 未找到 (通常随 lcov 一起安装)"
fi

# ==================== 7. libasan (asan) ====================
# build.md: asan → libasan (以 gcc 7.5.0 为例: libasan4)
print_header "7. libasan [build.md: 必需 (asan)]"

# 检查 libasan 动态库
ASAN_FOUND=false
# 遍历常见的系统库路径，查找libasan.so文件
for path in /usr/lib /usr/lib64 /usr/local/lib /usr/local/lib64 \
            /usr/lib/x86_64-linux-gnu /usr/lib/aarch64-linux-gnu \
            /usr/lib/gcc/x86_64-linux-gnu/*/  /usr/lib/gcc/aarch64-linux-gnu/*/; do
    # 判断指定路径下是否存在libasan.so文件：
    #   -f "$path/libasan.so"：检查文件是否为普通文件
    #   2>/dev/null 2>&1：重定向错误输出，避免路径不存在时打印错误
    if ls "$path"/libasan.so* &>/dev/null 2>&1; then
        ASAN_FOUND=true
        # 记录找到的libasan.so所在路径：ASAN_PATH存储有效库文件路径
        ASAN_PATH="$path"
        break
    fi
done

if $ASAN_FOUND; then
    log_pass "libasan 已安装 ($ASAN_PATH)"
else
    log_error "未安装 libasan (build.md 要求安装, 用于地址消毒器)"
    log_info "build.md 原文: 'asan以gcc 7.5.0版本为例，其他版本请安装对应版本asan'"
    log_info "安装 (Ubuntu/GCC-7):  sudo apt-get install libasan4"
    log_info "安装 (Ubuntu/GCC-9):  sudo apt-get install libasan5"
    log_info "安装 (Ubuntu/GCC-11): sudo apt-get install libasan6"
    log_info "安装 (Ubuntu/GCC-12): sudo apt-get install libasan8"

    # 根据当前 GCC 版本给出更精确的建议
    if check_command gcc; then
        # 提取GCC主版本号：
        #   gcc -dumpversion：输出GCC版本号（如 11.2.0）
        #   cut -d'.' -f1：以点为分隔符，截取第一个字段（主版本号，如 11）
        GCC_MAJOR=$(gcc -dumpversion | cut -d'.' -f1)
        # 根据GCC主版本号给出libasan安装建议
        case "$GCC_MAJOR" in
            7)  log_info ">>> 当前 GCC $GCC_MAJOR, 建议: sudo apt-get install libasan4" ;;
            8)  log_info ">>> 当前 GCC $GCC_MAJOR, 建议: sudo apt-get install libasan5" ;;
            9)  log_info ">>> 当前 GCC $GCC_MAJOR, 建议: sudo apt-get install libasan5" ;;
            10) log_info ">>> 当前 GCC $GCC_MAJOR, 建议: sudo apt-get install libasan6" ;;
            11) log_info ">>> 当前 GCC $GCC_MAJOR, 建议: sudo apt-get install libasan6" ;;
            12) log_info ">>> 当前 GCC $GCC_MAJOR, 建议: sudo apt-get install libasan8" ;;
            13) log_info ">>> 当前 GCC $GCC_MAJOR, 建议: sudo apt-get install libasan8" ;;
            *)  log_info ">>> 当前 GCC $GCC_MAJOR, 请自行确认 libasan 版本" ;;
        esac
    fi
fi

# ==================== 8. graph-easy ====================
# build.md: graph-easy (可选)
print_header "8. graph-easy [build.md: 可选]"

if check_command graph-easy; then
    log_pass "graph-easy 已安装"
else
    log_info "graph-easy 未安装 (build.md 标记为可选, 不影响编译)"
    log_info "安装 (Ubuntu): sudo apt-get install libgraph-easy-perl"
fi

# ==================== 9. CANN Toolkit ====================
# build.md 步骤二: 安装社区版 CANN Toolkit 包
print_header "9. CANN Toolkit [build.md: 步骤二, 必需]"

ASCEND_HOME=""
# 判断ASCEND_HOME_PATH环境变量是否非空（-n 表示变量非空）：优先使用用户指定的路径
if [ -n "$ASCEND_HOME_PATH" ]; then
    ASCEND_HOME="$ASCEND_HOME_PATH"
# 判断系统默认路径1是否存在（-d 检查目录是否存在）：系统级CANN安装路径
elif [ -d "/usr/local/Ascend/ascend-toolkit/latest" ]; then
    ASCEND_HOME="/usr/local/Ascend/ascend-toolkit/latest"
# 判断系统默认路径2是否存在：用户级CANN安装路径
elif [ -d "$HOME/Ascend/ascend-toolkit/latest" ]; then
    ASCEND_HOME="$HOME/Ascend/ascend-toolkit/latest"
# 判断兼容路径是否存在：旧版本CANN默认安装路径
elif [ -d "/usr/local/Ascend/latest" ]; then
    ASCEND_HOME="/usr/local/Ascend/latest"
fi

# 判断ASCEND_HOME是否有效：
#   -n "$ASCEND_HOME"：路径变量非空
#   && [ -d "$ASCEND_HOME" ]：且路径为有效目录（逻辑与）
if [ -n "$ASCEND_HOME" ] && [ -d "$ASCEND_HOME" ]; then
    log_pass "CANN Toolkit 路径: $ASCEND_HOME"

    # 读取CANN版本信息：
    #   -f "$ASCEND_HOME/version.cfg"：检查版本配置文件是否存在
    if [ -f "$ASCEND_HOME/version.cfg" ]; then
        # head -n1：读取配置文件第一行内容（存储CANN版本号）
        CANN_VER=$(head -n1 "$ASCEND_HOME/version.cfg")
        log_info "CANN 版本: $CANN_VER"
    fi

    # 环境变量 (build.md 步骤二要求 source set_env.sh)
    # build.md 原文: source /usr/local/Ascend/cann/set_env.sh
    SET_ENV_FOUND=false
    # 遍历常见的set_env.sh脚本路径（按优先级排序）：
    # 1. /usr/local/Ascend/cann/set_env.sh - 系统级默认安装路径
    # 2. $HOME/Ascend/cann/set_env.sh     - 用户级自定义安装路径
    # 3. $ASCEND_HOME/bin/setenv.bash     - CANN Toolkit内置环境脚本（兼容名）
    # 4. $ASCEND_HOME/./set_env.sh        - 旧版本CANN兼容路径
    for env_script in \
        "/usr/local/Ascend/cann/set_env.sh" \
        "$HOME/Ascend/cann/set_env.sh" \
        "$ASCEND_HOME/bin/setenv.bash" \
        "$ASCEND_HOME/../set_env.sh"; do
        # 判断脚本文件是否存在（-f 检查是否为普通文件）
        if [ -f "$env_script" ]; then
            # 标记找到有效环境脚本
            SET_ENV_FOUND=true
            log_pass "set_env.sh 存在: $env_script"
            break
        fi
    done

    if ! $SET_ENV_FOUND; then
        log_warn "未找到 set_env.sh"
        log_info "build.md: source /usr/local/Ascend/cann/set_env.sh"
    fi

    # 判断ASCEND_TOOLKIT_HOME环境变量是否非空（-n 表示变量非空）：校验核心环境变量是否配置
    if [ -n "$ASCEND_TOOLKIT_HOME" ]; then
        log_pass "ASCEND_TOOLKIT_HOME 已设置: $ASCEND_TOOLKIT_HOME"
    else
        log_warn "ASCEND_TOOLKIT_HOME 未设置 (请先 source set_env.sh)"
        log_info "build.md: source /usr/local/Ascend/cann/set_env.sh"
    fi

    # 检查LD_LIBRARY_PATH是否包含Ascend相关路径：确保CANN库文件可被加载
    # 说明：
    #   echo "$LD_LIBRARY_PATH"：输出库路径环境变量
    #   grep -q Ascend：静默匹配（-q 不输出结果）是否包含"Ascend"字符串
    #   2>/dev/null：屏蔽grep匹配失败的错误输出
    if echo "$LD_LIBRARY_PATH" | grep -q "Ascend" 2>/dev/null; then
        log_pass "LD_LIBRARY_PATH 包含 Ascend 路径"
    else
        log_warn "LD_LIBRARY_PATH 未包含 Ascend 路径 (请先 source set_env.sh)"
    fi
else
    log_error "未检测到 CANN Toolkit"
    log_info "build.md 步骤二: 安装社区版 CANN Toolkit 包"
    log_info "下载: https://ascend.devcloud.huaweicloud.com/artifactory/cann-run-mirror/software/master/"
    log_info "安装: ./Ascend-cann-toolkit_xxx_linux-xxx.run --full"
    log_info "然后: source /usr/local/Ascend/cann/set_env.sh"
fi

# ==================== 10. 基础构建工具 ====================
print_header "10. 基础构建工具"

# make
if check_command make; then
    # 获取make原始版本信息：make --version 输出首行包含版本号
    MAKE_RAW=$(make --version | head -n1)
    # 提取标准化版本号：调用extract_version函数将原始版本转为x.x.x格式
    MAKE_VER=$(extract_version "$MAKE_RAW")
    log_pass "make $MAKE_VER"
else
    log_error "未安装 make"
    log_info "安装 (Ubuntu): sudo apt-get install make"
fi

# git (build.md 步骤三: git clone)
if check_command git; then
    # 获取git原始版本信息：git --version 输出版本号
    GIT_RAW=$(git --version)
    # 提取标准化版本号：调用extract_version函数将原始版本转为x.x.x格式
    GIT_VER=$(extract_version "$GIT_RAW")
    log_pass "git $GIT_VER"
else
    log_error "未安装 git (build.md 步骤三需要 git clone)"
    log_info "安装 (Ubuntu): sudo apt-get install git"
fi

# pip (安装 Python 包需要)
# 判断是否获取到有效的Python命令（-n 表示变量非空）
if [ -n "$PYTHON_CMD" ]; then
    # 检查pip是否可用：执行pip --version并屏蔽错误输出
    if $PYTHON_CMD -m pip --version &>/dev/null; then
        # 获取pip原始版本信息
        PIP_RAW=$($PYTHON_CMD -m pip --version)
        # 提取标准化版本号
        PIP_VER=$(extract_version "$PIP_RAW")
        log_pass "pip $PIP_VER"
    else
        log_warn "pip 未安装"
        log_info "安装: $PYTHON_CMD -m ensurepip --upgrade"
    fi
fi

# ==================== 11. 系统资源 ====================
print_header "11. 系统资源 [可选]"

# 获取磁盘可用空间（单位GB）：
#   df -BG：以GB为单位显示磁盘使用情况
#   2>/dev/null：屏蔽错误输出
#   tail -1：取最后一行汇总数据
#   awk '{print $4}'：提取第4列（可用空间列）
#   tr -d 'G'：移除单位字符'G'，仅保留数值
#   || echo "0"：命令失败时返回0，避免脚本中断
DISK_AVAIL=$(df -BG . 2>/dev/null | tail -1 | awk '{print $4}' | tr -d 'G' || echo "0")

# 判断磁盘可用空间是否充足：
#   -gt 10：大于10GB（充足）
if [ "$DISK_AVAIL" -gt 10 ] 2>/dev/null; then
    log_info "可用磁盘: ${DISK_AVAIL}GB"
#   -gt 5：大于5GB（偏少，建议预留>10GB）
elif [ "$DISK_AVAIL" -gt 5 ] 2>/dev/null; then
    log_info "磁盘偏少: ${DISK_AVAIL}GB (建议 >10GB)"
else
    log_info "磁盘不足: ${DISK_AVAIL}GB"
fi

# 检查系统内存（可选）
if [ -f /proc/meminfo ]; then
    # 获取总内存（单位KB）：从/proc/meminfo中提取MemTotal行的第2列数值
    MEM_KB=$(grep MemTotal /proc/meminfo | awk '{print $2}')
    # 转换为GB：KB → MB → GB（除以1024两次）
    MEM_GB=$((MEM_KB / 1024 / 1024))

    # 判断内存是否充足：
    #   -ge 8：大于等于8GB（推荐配置）
    if [ "$MEM_GB" -ge 8 ]; then
        log_info "内存: ${MEM_GB}GB"
    #   -ge 4：大于等于4GB（偏少，推荐≥8GB）
    elif [ "$MEM_GB" -ge 4 ]; then
        log_info "内存偏少: ${MEM_GB}GB (推荐 >=8GB)"
    else
        log_info "内存不足: ${MEM_GB}GB"
    fi
fi

# CPU
CPU_CORES=$(nproc 2>/dev/null || echo "unknown")
log_info "CPU 核心数: $CPU_CORES"

# ==============================================================================
#                            汇总报告
# ==============================================================================
echo ""
echo "=================================================================="
echo "  metadef 环境检查完成"
echo "  依据: https://gitcode.com/cann/metadef/blob/master/docs/build.md"
echo "=================================================================="
echo ""

[ $ERROR_COUNT -gt 0 ]   && echo -e "  ${RED}✗ ERRORS:   $ERROR_COUNT${NC}  (必须修复才能编译)"
[ $WARNING_COUNT -gt 0 ] && echo -e "  ${YELLOW}⚠ WARNINGS: $WARNING_COUNT${NC}  (建议修复)"
echo -e "  ${GREEN}✓ PASSED:   $PASS_COUNT${NC}"
echo ""

if [ $ERROR_COUNT -gt 0 ]; then
    echo -e "  ${RED}结论: 环境不满足 metadef 编译要求，请修复上述 ERROR 项。${NC}"
    echo ""
    echo "  build.md 安装命令 (Ubuntu/Debian):"
    echo "    sudo apt-get install cmake ccache lcov libasan4 libgraph-easy-perl"
    echo ""
    echo "  完整依赖一键安装:"
    echo "    sudo apt-get update && sudo apt-get install -y \\"
    echo "      build-essential cmake ccache lcov \\"
    echo "      python3 python3-dev python3-pip \\"
    echo "      git make"
    echo ""
    echo "  CANN Toolkit 安装:"
    echo "    下载: https://ascend.devcloud.huaweicloud.com/artifactory/cann-run-mirror/software/master/"
    echo "    安装: ./Ascend-cann-toolkit_xxx_linux-xxx.run --full"
    echo "    环境: source /usr/local/Ascend/cann/set_env.sh"
    echo ""
    echo "  详细说明: docs/build.md"
    echo ""
    exit 1
elif [ $WARNING_COUNT -gt 0 ]; then
    echo -e "  ${YELLOW}结论: 环境基本可用，建议关注上述 WARNING 项。${NC}"
    exit 0
else
    echo -e "  ${GREEN}结论: 环境检查全部通过！可以编译 metadef。${NC}"
    echo -e "  ${GREEN}编译命令: bash build.sh${NC}"
    exit 0
fi