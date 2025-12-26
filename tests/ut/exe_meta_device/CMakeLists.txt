# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

add_executable(ut_exe_meta_device ${CMAKE_CURRENT_LIST_DIR}/main.cc)
target_link_libraries(ut_exe_meta_device PRIVATE exe_meta_device)
target_link_libraries(ut_exe_meta_device PRIVATE
        intf_pub
        -Wl,--no-as-needed
        -lrt -ldl -lgcov
        -Wl,--as-needed
        slog_stub
        c_sec
)
