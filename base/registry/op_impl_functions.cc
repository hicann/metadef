/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <sstream>
#include "register/op_impl_registry_api.h"
#include "common/ge_common/debug/ge_log.h"
#include "graph/any_value.h"
#include "register/op_impl_registry_base.h"
#include "common/plugin/plugin_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

size_t GetRegisteredOpNum(void) {
  GELOGI("LocalRegistry path[%s] all impl size : %zu",
         ge::GetSoRealPathByAddr(&gert::OpImplRegistry::GetInstance()).c_str(),
         gert::OpImplRegistry::GetInstance().GetAllTypesToImpl().size());
  return gert::OpImplRegistry::GetInstance().GetAllTypesToImpl().size();
}

int32_t GetOpImplFunctions(TypesToImpl *impl, size_t impl_num) {
  auto types_to_impl = gert::OpImplRegistry::GetInstance().GetAllTypesToImpl();
  GELOGI("LocalRegistry path[%s] all impl size : %zu",
         ge::GetSoRealPathByAddr(&gert::OpImplRegistry::GetInstance()).c_str(),
         types_to_impl.size());
  if (impl_num != types_to_impl.size()) {
    GELOGE(ge::FAILED, "Get types_to_impl_ failed, impl_num[%zu] and map size[%zu] not match",
           impl_num, types_to_impl.size());
    return static_cast<int32_t>(ge::GRAPH_FAILED);
  }
  size_t cnt = 0U;
  for (auto &it : types_to_impl) {
    impl[cnt].op_type = it.first.GetString();
    impl[cnt].funcs = static_cast<gert::OpImplKernelRegistry::OpImplFunctions&>(it.second);
    cnt++;
  }
  return static_cast<int32_t>(ge::GRAPH_SUCCESS);
}

int32_t GetOpImplFunctionsV2(TypesToImplV2 *impl, size_t impl_num) {
  const auto types_to_impl = gert::OpImplRegistry::GetInstance().GetAllTypesToImpl();
  GELOGI("LocalRegistry path[%s] all impl size : %zu",
         ge::GetSoRealPathByAddr(&gert::OpImplRegistry::GetInstance()).c_str(),
         types_to_impl.size());
  if (impl_num != types_to_impl.size()) {
    GELOGE(ge::FAILED, "Get types_to_impl_ failed, impl_num[%zu] and map size[%zu] not match",
           impl_num, types_to_impl.size());
    return static_cast<int32_t>(ge::GRAPH_FAILED);
  }
  size_t cnt = 0U;
  for (auto &it : types_to_impl) {
    impl[cnt].op_type = it.first.GetString();
    impl[cnt].funcs = it.second;
    cnt++;
  }
  return static_cast<int32_t>(ge::GRAPH_SUCCESS);
}
#ifdef __cplusplus
}
#endif
