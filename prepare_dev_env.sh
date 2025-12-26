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

# 这是一个交互式脚本，帮助开发者完成开发环境的准备工作，包括cann包和third party包的安装路径。
# 本脚本整体分为两步，第一步完成安装包路径的配置，第二步完成cann包和third party包的安装。
# 第一步，分别确定cann包和third party包的安装路径，具体逻辑如下：
# 0. cann包和third party包的安装路径保存在.dev_env文件中，如果该文件存在，则读取文件中的路径，否则认为路径不存在。
# 1. 如果cann包和third party包的安装路径已经存在，则提示用户包路径已经存在，是xxx，是需要更新包到最新版本，还是更换路径，如果要更换路径，则询问用户输入新的路径。
# 2. 如果cann包和third party包的安装路径不存在，则询问用户输入路径。
# 3. 允许用户输入空路径，表示不安装cann包或third party包。
# 4. 如果用户选择了更新或者更换路径，则记录路径到cann_path(cann包）和third_party_path（third party包）中；如果用户选择了不安装，则将路径设置为空。
# 第二步，完成cann包和third party包的安装，具体逻辑如下：
# 1. 安装third party包（如果用户选择了安装），调用脚本bash build_third_party.sh --output_path=$third_party_path。
# 2. 安装cann包（如果用户选择了安装），调用脚本bash ./base/metadef/install_newest_packages.sh -i $cann_path。
# 第三步，记录用户选择的cann包和third party包的安装路径到文件.dev_env中，该文件中，使用等号定义了如下变量：
# 1. ASCEND_3RD_LIB_PATH：third party包的安装路径。
# 2. ASCEND_INSTALL_PAT：cann包的安装路径。

WORKDIR=$(pwd)
SCRIPT_DIR=$(dirname "$0")
SCRIPT_DIR=$(realpath "$SCRIPT_DIR")

DEV_ENV_FILE="${WORKDIR}/.dev_env"

# Step 1: Determine the installation paths for 'cann' and 'third party' packages.

# Check if .dev_env file exists and source existing paths
if [ -f "$DEV_ENV_FILE" ]; then
    source "$DEV_ENV_FILE"
else
    ASCEND_3RD_LIB_PATH=""
    ASCEND_INSTALL_PATH=""
fi

# Function to handle user choices for package paths
handle_package() {
    local package_name="$1"
    local env_var_name="$2"
    local current_path="${!env_var_name}"
    local new_path=""

    if [ -n "$current_path" ]; then
        # 将多行提示信息合并成一个字符串，避免被调用测捕获
        prompt="The installation path for the $package_name package already exists: $current_path.\n"
        prompt+="Do you want to update the package to the latest version, or change the path?\n"
        prompt+="1) Update to latest version\n"
        prompt+="2) Change path\n"
        prompt+="3) Do not install\n"
        prompt+="Please enter your choice [1/2/3]: "
        read -p "$(echo -e "$prompt")" -r choice
        case "$choice" in
            1)
                new_path="$current_path"
                ;;
            2)
                read -p "Please enter the new installation path for the $package_name package (leave empty to skip installation): " new_path
                ;;
            3)
                new_path=""
                ;;
            *)
                echo "Invalid choice. Skipping installation of $package_name package."
                new_path=""
                ;;
        esac
    else
        read -p "Please enter the installation path for the $package_name package (leave empty to skip installation): " new_path
    fi

    # Convert to absolute path if not empty
    if [ -n "$new_path" ]; then
        new_path="$(realpath -m "$new_path")"
    fi

    echo "$new_path"
}

# Process 'third party' package
third_party_path=$(handle_package "third party" "ASCEND_3RD_LIB_PATH")

# Process 'cann' package
cann_path=$(handle_package "cann" "ASCEND_INSTALL_PATH")

# Step 2: Install 'third party' and 'cann' packages.

if [ -n "$third_party_path" ]; then
    echo "Installing third party package to $third_party_path..."
    mkdir -p "$third_party_path"
    bash "${SCRIPT_DIR}/build_third_party.sh" --output_path="$third_party_path"
else
    third_party_path=${ASCEND_3RD_LIB_PATH}
    echo "Skipping installation of third party package, current third party path: ${third_party_path}"
fi

if [ -n "$cann_path" ]; then
    echo "Installing cann package to $cann_path..."
    mkdir -p "$cann_path"
    bash "${SCRIPT_DIR}/install_newest_packages.sh" -i "$cann_path"
else
    cann_path=${ASCEND_INSTALL_PATH}
    echo "Skipping installation of cann package, current cann path: ${cann_path}"
fi

# Step 3: Record the installation paths to '.dev_env' file with absolute paths.

echo "Recording installation paths to $DEV_ENV_FILE..."
cat > "$DEV_ENV_FILE" <<EOL
ASCEND_3RD_LIB_PATH=$third_party_path
ASCEND_INSTALL_PATH=$cann_path
EOL

echo "Setup completed."
