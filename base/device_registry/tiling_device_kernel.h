/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

/*!
 * \file tiling_device_kernel.h
 * \brief
 */

#ifndef DEVICE_REGISTRY_TILING_DEVICE_KERNEL_H
#define DEVICE_REGISTRY_TILING_DEVICE_KERNEL_H
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((visibility("default"))) uint32_t RunAicpuRpcSrvLaunch(void *args);

__attribute__((visibility("default"))) __attribute__((weak)) int32_t CustSetCpuKernelContext(uint64_t workspace_size,
                                                                                             uint64_t workspace_addr);

#ifdef __cplusplus
}
#endif

#endif  // DEVICE_REGISTRY_TILING_DEVICE_KERNEL_H