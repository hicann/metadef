# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

############ exe_meta_device ############
set(STUB_ERROR_MANAGER_SRC
        ${CMAKE_CURRENT_BINARY_DIR}/stub_error_manager.cc
        ${CMAKE_CURRENT_BINARY_DIR}/stub_err_msg.cc
        )
add_custom_command(
        OUTPUT ${STUB_ERROR_MANAGER_SRC}
        COMMAND echo "Generating stub files."
        && ${HI_PYTHON} ${CMAKE_CURRENT_LIST_DIR}/../error_manager/stub/gen_stubapi.py ${METADEF_DIR}/inc/common/util ${CMAKE_CURRENT_BINARY_DIR}
        && ${HI_PYTHON} ${CMAKE_CURRENT_LIST_DIR}/../error_manager/stub/gen_stubapi.py ${METADEF_DIR}/inc/external ${CMAKE_CURRENT_BINARY_DIR}
        && echo "Generating stub files end."
)
add_library(exe_meta_device STATIC
        "${METADEF_DIR}/base/runtime/tiling_data.cc"
        "${METADEF_DIR}/base/runtime/runtime_attrs.cc"
        "${METADEF_DIR}/base/runtime/compute_node_info.cc"
        "${STUB_ERROR_MANAGER_SRC}")
target_include_directories(exe_meta_device PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${METADEF_DIR}/inc/common/util
        ${METADEF_DIR}/inc/external
        ${METADEF_DIR}/pkg_inc
        )
add_library(exe_meta_device_headers INTERFACE)
target_include_directories(exe_meta_device_headers INTERFACE
        $<BUILD_INTERFACE:${METADEF_DIR}/inc>
        $<BUILD_INTERFACE:${METADEF_DIR}/inc/external>
        )
target_link_libraries(exe_meta_device PRIVATE intf_pub slog_headers c_sec_headers)
target_link_libraries(exe_meta_device PUBLIC exe_meta_device_headers)
target_compile_options(exe_meta_device PRIVATE
        -O2
        -fPIC
        -Wextra
        -Wfloat-equal
        -D_FORTIFY_SOURCE=2
        )

install(TARGETS exe_meta_device ${INSTALL_OPTIONAL}
        ARCHIVE DESTINATION ${INSTALL_DEVICE_LIBRARY_DIR}
        COMPONENT metadef
        )

##################device_register##########################
add_library(device_register STATIC
  "${METADEF_DIR}/base/device_registry/device_op_impl_registry.cpp"
  "${METADEF_DIR}/base/device_registry/tiling_device_kernel.cpp"
)

target_include_directories(device_register PRIVATE
  ${METADEF_DIR}/pkg_inc
  ${METADEF_DIR}/inc/external
)

target_link_libraries(device_register PRIVATE
  $<BUILD_INTERFACE:intf_pub>
  -Wl,--no-as-needed
  -Wl,--whole-archive
  slog_headers
  ascend_protobuf_static
  mmpa
  exe_meta_device
  c_sec
  -Wl,--no-whole-archive
  -ldl
  -Wl,--as-needed
)

target_compile_definitions(device_register PRIVATE
    DEVICE_OP_TILING_LIB
)


target_compile_definitions(device_register PRIVATE
    _FORTIFY_SOURCE=2
    google=ascend_private
)

target_compile_options(device_register PRIVATE
    -O2
    -std=c++17
    -fstack-protector-all
    -fvisibility-inlines-hidden
    -fvisibility=hidden
    -frename-registers
    -fpeel-loops
    -Wextra
    -fno-common
    -Wfloat-equal
)

target_link_options(device_register PRIVATE
    -Wl,--exclude-libs=libascend_protobuf.a
    -Wl,-z,relro,-z,now
    -Wl,-Bsymbolic
)

install(TARGETS device_register ${INSTALL_OPTIONAL}
  ARCHIVE DESTINATION ${INSTALL_DEVICE_LIBRARY_DIR}
  COMPONENT metadef
)

##################tilingdata_base##########################
add_library(tilingdata_base STATIC
  "${METADEF_DIR}/base/asc/tilingdata_base_impl.cc"
)

target_include_directories(tilingdata_base PRIVATE
  ${METADEF_DIR}/pkg_inc/
  ${METADEF_DIR}/inc/external
)

target_link_libraries(tilingdata_base PRIVATE
  $<$<BOOL:${ENABLE_GCOV}>:-lgcov>
  -lpthread
  -Wl,--no-as-needed
  c_sec
)

target_compile_definitions(tilingdata_base PRIVATE
    ASCENDC_DEVICE_REG_STATIC
    _FORTIFY_SOURCE=2
    $<$<CONFIG:Release>:CFG_BUILD_NDEBUG>
    $<$<CONFIG:Debug>:CFG_BUILD_DEBUG>
    LINUX=0
    $<$<BOOL:${ENABLE_TEST}>:SUPPORT_LARGE_MODEL_ENABLE=1>
    $<$<BOOL:${ENABLE_METADEF_UT}>:_GLIBCXX_USE_CXX11_ABI=${USE_CXX11_ABI}>
)

target_compile_options(tilingdata_base PRIVATE
    -O2
    -std=c++17
    -fvisibility-inlines-hidden
    -fvisibility=hidden
    -frename-registers
    -fpeel-loops
    -fPIC
    -Wextra
    -Wfloat-equal
    $<IF:$<STREQUAL:${CMAKE_SYSTEM_NAME},centos>,-fstack-protector-all,-fstack-protector-strong>
    $<$<CONFIG:Debug>:-g>
    $<$<BOOL:${ENABLE_ASAN}>:-fsanitize=address -fsanitize=leak -fsanitize-recover=address,all -fno-stack-protector -fno-omit-frame-pointer -g>
    $<$<BOOL:${ENABLE_GCOV}>:-fprofile-arcs -ftest-coverage>
)

target_link_options(tilingdata_base PRIVATE
    -Wl,-z,relro,-z,now
    -Wl,-z,noexecstack
    -Wl,-Bsymbolic
    -Wl,--no-undefined
    $<$<CONFIG:Release>:-Wl,--build-id=none>
    $<$<CONFIG:Release>:-s>
    $<$<BOOL:${ENABLE_ASAN}>:-fsanitize=address -fsanitize=leak -fsanitize-recover=address>
    $<$<BOOL:${ENABLE_GCOV}>:-fprofile-arcs -ftest-coverage>
)

install(TARGETS tilingdata_base ${INSTALL_OPTIONAL}
  ARCHIVE DESTINATION ${INSTALL_DEVICE_LIBRARY_DIR}
  COMPONENT metadef
)
