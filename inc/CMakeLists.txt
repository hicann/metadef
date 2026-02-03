# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------


add_library(metadef_headers INTERFACE)
target_include_directories(metadef_headers INTERFACE
    $<BUILD_INTERFACE:${METADEF_DIR}>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/common>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/exe_graph>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/external>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/external/base>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/external/op_common>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/graph>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/register>
    $<BUILD_INTERFACE:${METADEF_DIR}/inc/base>
    $<BUILD_INTERFACE:${METADEF_DIR}/pkg_inc>

    $<BUILD_INTERFACE:${METADEF_DIR}/pkg_inc/common>
    $<BUILD_INTERFACE:${METADEF_DIR}/pkg_inc/common/ge_common>
    $<BUILD_INTERFACE:${METADEF_DIR}/pkg_inc/graph>
    $<BUILD_INTERFACE:${METADEF_DIR}/pkg_inc/exe_graph/runtime>
    $<BUILD_INTERFACE:${METADEF_DIR}/pkg_inc/base/registry>
    $<BUILD_INTERFACE:${METADEF_DIR}/pkg_inc/base/runtime>

    # 下列头文件包含路径是非法的，需要在后续整改中删掉
    # --------------------start------------------------
    $<BUILD_INTERFACE:${TOP_DIR}/ace/npuruntime/runtime/platform/inc>
    $<BUILD_INTERFACE:${TOP_DIR}/runtime/pkg_inc>
    # ---------------------end-----------------------

    $<INSTALL_INTERFACE:include>
    $<INSTALL_INTERFACE:include/metadef>
    $<INSTALL_INTERFACE:include/metadef/common>
    $<INSTALL_INTERFACE:include/metadef/external>
    $<INSTALL_INTERFACE:include/metadef/external/base>
    $<INSTALL_INTERFACE:include/metadef/external/exe_graph>
    $<INSTALL_INTERFACE:include/metadef/external/op_common>
    $<INSTALL_INTERFACE:include/metadef/graph>
    $<INSTALL_INTERFACE:include/metadef/register>
    $<INSTALL_INTERFACE:include/metadef/base>
    $<INSTALL_INTERFACE:include/metadef/transformer>

    $<INSTALL_INTERFACE:pkg_inc>
    $<INSTALL_INTERFACE:pkg_inc/common>
    $<INSTALL_INTERFACE:pkg_inc/common/ge_common>
    $<INSTALL_INTERFACE:pkg_inc/graph>
    $<INSTALL_INTERFACE:pkg_inc/exe_graph/runtime>
    $<INSTALL_INTERFACE:pkg_inc/base/registry>
    $<INSTALL_INTERFACE:pkg_inc/base/runtime>
)

