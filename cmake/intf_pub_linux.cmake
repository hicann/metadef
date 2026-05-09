# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

# 默认开启-O2优化选项
add_library(metadef_intf_pub INTERFACE)
target_link_libraries(metadef_intf_pub INTERFACE
    $<BUILD_INTERFACE:intf_pub>
)

target_compile_definitions(metadef_intf_pub INTERFACE
    $<$<CONFIG:Release>:-D_FORTIFY_SOURCE=2>
)

target_compile_options(metadef_intf_pub INTERFACE
    $<$<CONFIG:Release>:-O2>
    $<$<CONFIG:Debug>:-g>
)

# 支持target定制-Os优化选项
add_library(metadef_intf_pub_Os INTERFACE)
target_link_libraries(metadef_intf_pub_Os INTERFACE
    $<BUILD_INTERFACE:intf_pub>
)
target_compile_options(metadef_intf_pub_Os INTERFACE
    $<$<CONFIG:Release>:-Os>
    $<$<CONFIG:Debug>:-g>
)