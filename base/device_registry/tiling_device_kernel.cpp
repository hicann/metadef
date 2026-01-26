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
 * \file tiling_device_kernel.cpp
 * \brief
 */

#include "tiling_device_kernel.h"
#include "device_op_impl_registry_impl.h"
#include "common/ge_common/debug/ge_log.h"
#include "tiling_aicpu_task.h"

extern "C" {
__attribute__((visibility("default"))) uint32_t RunAicpuRpcSrvLaunch(void *args) {
  GELOGI("RunAicpuRpcSrvLaunch: beginning device tiling task");
  if (args == nullptr) {
    GELOGE(ge::PARAM_INVALID, "Args is nullptr");
    return ge::GRAPH_PARAM_INVALID;
  }

  tilingsink::TilingAicpuTask *task = reinterpret_cast<tilingsink::TilingAicpuTask *>(args);
  if (task->opType == nullptr) {
    GELOGE(ge::PARAM_INVALID, "opType is nullptr");
    return ge::GRAPH_PARAM_INVALID;
  }
  std::string opType = task->opType;

  if (&CustSetCpuKernelContext != nullptr) {
    GEEVENT("Begin to set up the CPU kernel context workspace for op %s", opType.c_str());
    int32_t ret = CustSetCpuKernelContext(task->workspaceSize, task->workspaceAddr);
    if (ret != 0) {
      GELOGE(ge::INTERNAL_ERROR,
             "Failed to set CPU kernel context workspace for op %s, ret = %d, workspace = %lu, workspaceSize = %lu",
             opType.c_str(), ret, task->workspaceAddr, task->workspaceSize);
    }
    GELOGI("set up the CPU kernel context workspace for op %s succeed, ret = %d, workspace = %lu, workspaceSize = %lu",
           opType.c_str(), ret, task->workspaceAddr, task->workspaceSize);
  }

  optiling::SinkTilingFunc func = optiling::DeviceOpImplRegistry::GetSingleton().GetSinkTilingFunc(opType);
  if (func == nullptr) {
    GELOGE(ge::PARAM_INVALID, "func is nullptr, check if op %s is registered", opType.c_str());
    return ge::GRAPH_PARAM_INVALID;
  }
  if (!task->tilingContext) {
    GELOGE(ge::PARAM_INVALID, "op %s task: tilingContext parameter is nullptr", opType.c_str());
    return ge::GRAPH_PARAM_INVALID;
  }

  if ((func) (task->tilingContext) != ge::GRAPH_SUCCESS) {
    GELOGE(ge::INTERNAL_ERROR, "Tiling function for op %s executed failed", opType.c_str());
    return ge::INTERNAL_ERROR;
  }
  GELOGI("Tiling function for op %s executed successfully", opType.c_str());

  if (reinterpret_cast<uint64_t *>(task->notifyAddr) != nullptr) {
    GELOGI("Notify value of %s is %lu", opType.c_str(), *reinterpret_cast<uint64_t *>(task->notifyAddr));
    *reinterpret_cast<uint64_t *>(task->notifyAddr) = 1U;  // 将此地址置1，super kernel场景同步使用
#ifdef __aarch64__
    // 插入一句汇编，作用是等待所有存储操作及相关缓存和缓冲区维护操作完成，这里是保证写地址notifyAddr的操作完成
    __asm__ __volatile__("dsb st" : : : "memory");
#endif
    GELOGI("The notify value for op %s after tiling function execution is: %lu", opType.c_str(),
           *reinterpret_cast<uint64_t *>(task->notifyAddr));
  }
  GELOGI("RunAicpuRpcSrvLaunch: device tiling task for op %s completed", opType.c_str());

  return ge::GRAPH_SUCCESS;
}
}