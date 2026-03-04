/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <vector>
#include <fstream>
#include "base/registry/op_impl_space_registry_v2.h"
#include "common/checker.h"
#include "common/util/mem_utils.h"
#include "mmpa/mmpa_api.h"
#include "common/ge_common/util.h"
#include "graph/debug/ge_util.h"
#include "inc/graph/utils/file_utils.h"
#include "base/registry/op_impl_space_registry_v2_impl.h"
#include "register/op_impl_registry_base.h"
#include "graph/any_value.h"
#include "base/err_msg.h"

#define MERGE_FUNCTION(merged_funcs, src_funcs, op_type, func_name)                                                    \
  if ((((merged_funcs).func_name) == nullptr) and ((src_funcs).func_name != nullptr)) {                                \
    ((merged_funcs).func_name) = ((src_funcs).func_name);                                                              \
    GELOGD("op type %s %s func registered.", (op_type), #func_name);                                                    \
  } else if (((merged_funcs).func_name) != nullptr and ((src_funcs).func_name != nullptr)) {                                                                  \
    GELOGW("op type %s %s func has been registered.", (op_type), #func_name);                                           \
  } else {                                                                                                             \
    /* 空分支，无需操作 */                                                                                             \
  }
namespace gert {
namespace {
const char_t *const kBuiltIn = "built-in";     // opp built-in directory name
void CloseHandle(void *const handle) {
  if (handle != nullptr) {
    if (mmDlclose(handle) != 0) {
      const ge::char_t *error = mmDlerror();
      error = (error == nullptr) ? "" : error;
      GELOGW("[Close][Handle] failed, reason:%s", error);
    }
  }
}
}  // namespace

ge::graphStatus OpImplSpaceRegistryImpl::AddMainExeToRegistry(const OppSoDesc &so_desc) {
  auto types_to_impl_from_holder = std::map<OpImplRegisterV2::OpType, OpImplKernelRegistry::OpImplFunctionsV2>();
  for (const auto &so_path_ascend_string : so_desc.GetSoPaths()) {
    auto so_path = so_path_ascend_string.GetString();
    GELOGI("Start to add main_exe op_impl to registry.");
    const auto om_registry_holder = ge::MakeShared<gert::OpImplRegistryHolder>();
    GE_CHECK_NOTNULL(om_registry_holder);
    if (om_registry_holder->GetOpImplFunctionsByHandle(RTLD_DEFAULT, so_path) != ge::GRAPH_SUCCESS) {
      GELOGW("Failed to get funcs from so!");
      return ge::GRAPH_FAILED;
    }
    for (const auto &type : om_registry_holder->GetTypesToImpl()) {
      types_to_impl_from_holder[type.first] = type.second;
    }
    GE_ASSERT_GRAPH_SUCCESS(AddRegistry(om_registry_holder));
    GELOGI("Save so symbol and handle in main_exe successfully!");
  }
  return ge::GRAPH_SUCCESS;
}

ge::graphStatus OpImplSpaceRegistryImpl::AddSoToRegistry(const OppSoDesc &so_desc) {
  if (so_desc.GetPackageName() == "main_exe") {
    return AddMainExeToRegistry(so_desc);
  }
  auto types_to_impl_from_holder = std::map<OpImplRegisterV2::OpType, OpImplKernelRegistry::OpImplFunctionsV2>();
  for (const auto &so_path_ascend_string : so_desc.GetSoPaths()) {
    auto so_path = so_path_ascend_string.GetString();
    GELOGI("Start to AddSoToRegistry so_path:%s, package name %s", so_path, so_desc.GetPackageName().GetString());
    uint32_t len = 0U;
    const auto so_data = metadef::GetBinDataFromFile(std::string(so_path), len);
    GE_ASSERT_NOTNULL(so_data);
    const auto create_func = [&types_to_impl_from_holder, so_path, so_desc]() -> OpImplRegistryHolderPtr {
      void *const handle = mmDlopen(
          so_path,
          static_cast<int32_t>(static_cast<uint32_t>(MMPA_RTLD_NOW) | static_cast<uint32_t>(MMPA_RTLD_GLOBAL)));
      if (handle == nullptr) {
        // 为兼顾兼容性和维测能力，此处算子so加载失败打印ERROR日志，并打屏提示用户
        std::stringstream ss;
        ss << "Failed to load " << so_desc.GetPackageName().GetString() << " library `" << so_path << "` via dlopen."
           << std::endl;
        ss << "This may cause missing functionality or reduced precision in related operations." << std::endl;
        ss << "Next steps:" << std::endl;
        ss << "  1. Diagnose: Review the specific error cause below." << std::endl;
        ss << "  2. Resolve: Ensure correct path, version, and dependencies (e.g., missing libraries)." << std::endl;
        ss << "  3. Refer to: "
              "https://gitcode.com/cann/ge/wiki/"
              "GE%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98%E5%AE%9A%E4%BD%8D%E6%89%8B%E5%86%8C.md#4-%E7%AE%97%E5%AD%90so%E5%"
              "8A%A0%E8%BD%BD%E5%A4%B1%E8%B4%A5%E7%B1%BB%E9%97%AE%E9%A2%98 for further troubleshooting."
           << std::endl;
        ss << "Error detail: " << mmDlerror() << std::endl;
        GELOGE(ge::GRAPH_FAILED, "%s", ss.str().c_str());
        std::cout << "[ERROR] " << ss.str() << std::endl;
        return nullptr;
      }
      const std::function<void()> callback = [&handle]() { CloseHandle(handle); };
      GE_DISMISSABLE_GUARD(close_handle, callback);
      auto om_registry_holder = ge::MakeShared<gert::OpImplRegistryHolder>();
      if (om_registry_holder == nullptr) {
        return nullptr;
      }
      if (om_registry_holder->GetOpImplFunctionsByHandle(handle, so_path) != ge::GRAPH_SUCCESS) {
        GELOGW("Failed to get funcs from so!");
        return nullptr;
      }
      for (const auto &type : om_registry_holder->GetTypesToImpl()) {
        types_to_impl_from_holder[type.first] = type.second;
      }
      om_registry_holder->SetHandle(handle);
      GE_DISMISS_GUARD(close_handle);
      return om_registry_holder;
    };

    const std::string str_so_data(so_data.get(), static_cast<size_t>(len));
    const auto registry_holder = OpImplRegistryHolderManager::GetInstance().GetOrCreateOpImplRegistryHolder(
        std::string(so_path), str_so_data, create_func);
    if (registry_holder == nullptr) {
      GELOGW("Nothing in so, so_path:%s, package name %s", so_path, so_desc.GetPackageName().GetString());
      continue;
    }
    GE_ASSERT_GRAPH_SUCCESS(AddRegistry(registry_holder));
    GELOGI("Save so symbol and handle in path[%s] successfully!", so_path);
  }

  const auto package_name = so_desc.GetPackageName().GetString();
  // package_name为空或为"built-in"时，不进行算子交付件校验
  if (package_name == nullptr || package_name[0] == '\0' || strcmp(package_name, kBuiltIn) == 0) {
    return ge::GRAPH_SUCCESS;
  }
  GELOGI("Start to check missing implementation for custom op package [%s]", so_desc.GetPackageName().GetString());
  for (const auto &kv : types_to_impl_from_holder) {
    const auto &op_type = kv.first;
    const auto &funcs = kv.second;
    const char *op_type_str = op_type.GetString();

    if (funcs.tiling == nullptr) {
      GELOGW("[MissOpImplementation] op [%s] has no tiling", op_type_str);
    }
  }

  return ge::GRAPH_SUCCESS;
}

const OpImplKernelRegistry::OpImplFunctionsV2 *OpImplSpaceRegistryImpl::GetOpImpl(const std::string &op_type) const {
  const auto iter = merged_types_to_impl_.find(op_type.c_str());
  if (iter == merged_types_to_impl_.cend()) {
    GELOGW("Get %s's op_impl from local registry.", op_type.c_str());
    return gert::OpImplRegistry::GetInstance().GetOpImpl(op_type.c_str());
  }
  return &iter->second;
}

void OpImplSpaceRegistryImpl::MergeFunctions(OpImplKernelRegistry::OpImplFunctionsV2 &merged_funcs,
                                             const OpImplKernelRegistry::OpImplFunctionsV2 &src_funcs,
                                             const std::string &op_type) const {
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), infer_shape)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), infer_symbol_shape)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), infer_shape_range)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), infer_datatype)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), tiling_parse)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), compile_info_creator)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), compile_info_deleter)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), tiling)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), op_execute_func)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), op_execute_prepare_func)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), op_execute_launch_func)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), gen_simplifiedkey)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), infer_format_func)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), calc_op_param)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), gen_task)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), check_support)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), op_select_format)
  if (merged_funcs.max_tiling_data_size == 0U) {
    merged_funcs.max_tiling_data_size = src_funcs.max_tiling_data_size;
  } else if (src_funcs.max_tiling_data_size != 0U) {
    GELOGW("op type %s max_tiling_data_size has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }

  if (merged_funcs.host_inputs == 0U) {
    merged_funcs.host_inputs = src_funcs.host_inputs;
  } else if (src_funcs.host_inputs != 0U) {
    GELOGW("op type %s host_inputs has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }

  if (merged_funcs.output_shape_depend_compute == 0UL) {
    merged_funcs.output_shape_depend_compute = src_funcs.output_shape_depend_compute;
  } else if (src_funcs.output_shape_depend_compute != 0UL) {
    GELOGW("op type %s output_shape_depend_compute has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }

  if (merged_funcs.inputs_dependency == 0U) {
    merged_funcs.inputs_dependency = src_funcs.inputs_dependency;
  } else if (src_funcs.inputs_dependency != 0U) {
    GELOGW("op type %s inputs_dependency has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }

  if (merged_funcs.tiling_dependency == 0U) {
    merged_funcs.tiling_dependency = src_funcs.tiling_dependency;
  } else if (src_funcs.tiling_dependency != 0U) {
    GELOGW("op type %s tiling_dependency has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }

  if (merged_funcs.tiling_dependency_placements == 0U) {
    merged_funcs.tiling_dependency_placements = src_funcs.tiling_dependency_placements;
  } else if (src_funcs.tiling_dependency_placements != 0U) {
    GELOGW("op type %s tiling_dependency_placement has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }

  if (merged_funcs.private_attrs.size() == 0U) {
    merged_funcs.private_attrs = src_funcs.private_attrs;
  } else if (src_funcs.private_attrs.size() != 0U) {
    GELOGW("op type %s private_attrs has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }
  if (merged_funcs.unique_private_attrs.size() == 0U) {
    merged_funcs.unique_private_attrs = src_funcs.unique_private_attrs;
  } else if (src_funcs.unique_private_attrs.size() != 0U) {
    GELOGW("op type %s unique_private_attrs has been registered", op_type.c_str());
  } else {
    // 已经注册且没有重复注册
  }
}

void OpImplSpaceRegistryImpl::MergeTypesToImpl(OpTypesToImplMap &merged_impl, const OpTypesToImplMap &src_impl) const {
  for (const auto &iter : src_impl) {
    const auto op_type = iter.first;
    GELOGD("Merge types to impl, op type %s", op_type.GetString());
    auto merge_iter = merged_impl.find(op_type);
    if (merge_iter == merged_impl.end()) {
      merged_impl[op_type] = iter.second;
      continue;
    }
    const auto &src_funcs = iter.second;
    MergeFunctions(merge_iter->second, src_funcs, op_type.GetString());
  }
}

void OpImplSpaceRegistryImpl::MergeCtFunctions(OpImplKernelRegistry::OpImplFunctionsV2 &merged_funcs,
                                               const OpCtImplKernelRegistry::OpCtImplFunctions &src_funcs,
                                               const std::string &op_type) const {
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), calc_op_param)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), gen_task)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), check_support)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), op_select_format)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), get_op_support_info)
  MERGE_FUNCTION(merged_funcs, src_funcs, op_type.c_str(), get_op_specific_info)
  return;
}

void OpImplSpaceRegistryImpl::MergeTypesToCtImpl(OpTypesToImplMap &merged_impl,
                                                 const OpTypesToCtImplMap &src_impl) const {
  for (const auto &iter : src_impl) {
    const auto op_type = iter.first;
    GELOGD("Merge ct types to impl, op type %s", op_type.GetString());
    auto merge_iter = merged_impl.find(op_type);
    if (merge_iter == merged_impl.end()) {
      auto &merged_funcs = merged_impl[op_type];
      merged_funcs.calc_op_param = iter.second.calc_op_param;
      merged_funcs.gen_task = iter.second.gen_task;
      merged_funcs.check_support = iter.second.check_support;
      merged_funcs.op_select_format = iter.second.op_select_format;
      merged_funcs.get_op_support_info = iter.second.get_op_support_info;
      merged_funcs.get_op_specific_info = iter.second.get_op_specific_info;
      GELOGD("Merge ct version to impl, op type %s, impl version[%zu], ct version[%zu]",
             op_type.GetString(), merged_funcs.version, iter.second.version);
      merged_funcs.version = iter.second.version;
      continue;
    } else {
      // 后续IMPL_CT_OP合并到IMPL_OP后删除
      // 当前是临时兼容，以version区分IMPL_CT_OP、IMPL_OP
      auto &merged_funcs = merged_impl[op_type];
      GELOGD("Merge ct version to impl, op type %s, impl version[%zu], ct version[%zu]",
             op_type.GetString(), merged_funcs.version, iter.second.version);
      merged_funcs.version = iter.second.version;
    }
    const auto &src_funcs = iter.second;
    MergeCtFunctions(merge_iter->second, src_funcs, op_type.GetString());
  }
}

ge::graphStatus OpImplSpaceRegistryImpl::AddRegistry(const std::shared_ptr<OpImplRegistryHolder> &registry_holder) {
  if (registry_holder != nullptr) {
    (void)op_impl_registries_.emplace_back(registry_holder);
    MergeTypesToImpl(merged_types_to_impl_, registry_holder->GetTypesToImpl());
    MergeTypesToCtImpl(merged_types_to_impl_, registry_holder->GetTypesToCtImpl());
  }
  return ge::GRAPH_SUCCESS;
}

OpImplKernelRegistry::OpImplFunctionsV2 *OpImplSpaceRegistryImpl::CreateOrGetOpImpl(const std::string &op_type) {
  return &merged_types_to_impl_[op_type.c_str()];
}
}  // namespace gert
