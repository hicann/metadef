/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <string>
#include "inc/common/plugin/plugin_manager.h"
#include "common/ge_common/debug/ge_log.h"
#include "mmpa/mmpa_api.h"
#include "register/op_impl_space_registry.h"
#include "register/opp_so_manager.h"
#include "base/registry/op_impl_space_registry_v2.h"
#include "external/ge_common/ge_api_types.h"

namespace ge {
namespace {
constexpr const char_t *const kBuiltIn = "built-in";
constexpr const char_t *const kSoSuffix = ".so";
constexpr const char_t *const kRt2SoSuffix = "rt2.0.so";
constexpr const char_t *const kCtSoSuffix = "ct.so";
constexpr const char_t *const kRtSoSuffix = "rt.so";
constexpr const char_t *const kLegacySoSuffix = "_legacy.so";
const std::string kOpsProtoPath = "/op_proto/lib/";
const std::string kOpsGraphPath = "/op_graph/lib/";
const std::string kOpMasterPath = "/op_impl/ai_core/tbe/op_tiling/lib/";
const std::string kOpHostPath = "/op_impl/ai_core/tbe/op_host/lib/";

using GetPathFunc = std::function<Status(std::string &)>;
const std::map<gert::OppImplVersionTag, GetPathFunc> kVersion2GetProtoPathFunc = {
  {gert::OppImplVersionTag::kOpp, [](std::string &path) {
    return metadef::PluginManager::GetOpsProtoPath(path);
  }},
 {gert::OppImplVersionTag::kOppKernel, [](std::string &path) {
   return metadef::PluginManager::GetUpgradedOpsProtoPath(path);
 }}
};

const std::map<gert::OppImplVersionTag, GetPathFunc> kVersion2GetMasterPathFunc = {
  {gert::OppImplVersionTag::kOpp, [](std::string &path) {
    return metadef::PluginManager::GetOpTilingForwardOrderPath(path);
  }},
 {gert::OppImplVersionTag::kOppKernel, [](std::string &path) {
   return metadef::PluginManager::GetUpgradedOpMasterPath(path);
 }}
};

gert::OppSoDesc* GetOppSoDescPtr(std::vector<std::pair<std::string, gert::OppSoDesc>> &vec, const std::string &package_name) {
  for (auto &item : vec) {
    if (item.first == package_name) {
      return &item.second;
    }
  }
  return nullptr;
}

void GetOppSoList(const std::string &opp_so_path, const std::vector<std::string>& so_suffix_list, std::vector<std::pair<std::string, gert::OppSoDesc>> &package_to_opp_so_desc,
                  gert::OppImplVersionTag opp_version_tag) {
  std::vector<std::string> so_list;
  for (auto &so_suffix : so_suffix_list) {
    metadef::PluginManager::GetFileListWithSuffix(opp_so_path, so_suffix, so_list);
  }
  // 排序，将"_legacy.so"移到到最后
  (void)std::stable_partition(so_list.begin(), so_list.end(), [](const std::string &so_name) {
    return so_name.size() < std::strlen(kLegacySoSuffix) ||
           so_name.compare((so_name.size() - std::strlen(kLegacySoSuffix)), std::strlen(kLegacySoSuffix), kLegacySoSuffix) != 0;
  });
  for (const auto &so_name : so_list) {
    GELOGD("GetOppSoList from path %s, so_name is %s", opp_so_path.c_str(), so_name.c_str());
  }

  // 合并到so_list到package_to_opp_so_desc对应的值中
  std::string package_name = metadef::PluginManager::GetSoPackageName(opp_so_path);
  if (opp_version_tag >= gert::OppImplVersionTag::kVersionEnd) {
    GELOGE(ge::FAILED, "Invalid opp_impl_version: %d", static_cast<int32_t>(opp_version_tag));
    return;
  }
  std::vector<ge::AscendString> new_so_path_vector;
  new_so_path_vector.reserve(so_list.size());
  (void)std::transform(so_list.begin(), so_list.end(),
                 std::back_inserter(new_so_path_vector),
                 [](const std::string &s) {
                     return ge::AscendString(s.c_str());
                 });

  auto opp_so_desc_ptr = GetOppSoDescPtr(package_to_opp_so_desc, package_name);
  if (opp_so_desc_ptr == nullptr) {
    GELOGI("Created new opp so list for package [%s], so num is [%zu], opp_impl_version: [%d]",
           package_name.c_str(), new_so_path_vector.size(), static_cast<int32_t>(opp_version_tag));
    // 无则创建
    gert::OppSoDesc opp_so_desc = gert::OppSoDesc(new_so_path_vector, AscendString(package_name.c_str()));
    (void)package_to_opp_so_desc.emplace_back(package_name, opp_so_desc);
  } else {
    GELOGI("Merged opp so list for package [%s], so num is [%zu], opp_impl_version: [%d]",
           package_name.c_str(), so_list.size(), static_cast<int32_t>(opp_version_tag));
    // 有则追加合并
    auto existing_so_path_vector = opp_so_desc_ptr->GetSoPaths();
    (void)existing_so_path_vector.insert(existing_so_path_vector.end(),
                                   new_so_path_vector.begin(),
                                   new_so_path_vector.end());
    *opp_so_desc_ptr = gert::OppSoDesc(existing_so_path_vector, AscendString(package_name.c_str()));
  }
}
}  // namespace

void OppSoManager::LoadSoAndInitDefault(const std::vector<AscendString> &so_list, gert::OppImplVersionTag opp_version_tag, const std::string &package_name) const {
  GELOGI("Start to LoadSoAndInitDefault, opp_impl_version: %d, package name:%s", static_cast<int32_t>(opp_version_tag), package_name.c_str());
  gert::OppSoDesc opp_so_desc(so_list, AscendString(package_name.c_str()));
  auto space_registry_v2 =
      gert::DefaultOpImplSpaceRegistryV2::GetInstance().GetSpaceRegistry(opp_version_tag);
  if (space_registry_v2 == nullptr) {
    space_registry_v2 = std::make_shared<gert::OpImplSpaceRegistryV2>();
    (void)gert::DefaultOpImplSpaceRegistryV2::GetInstance().SetSpaceRegistry(space_registry_v2, opp_version_tag);
  }

  if (space_registry_v2->AddSoToRegistry(opp_so_desc) != ge::SUCCESS) {
    GELOGW("AddSoToRegistry failed, package name is %s", package_name.c_str());
  }
}

void OppSoManager::LoadOpsProtoPackage() const {
  const std::lock_guard<std::mutex> lock(mutex_);
  bool is_split = metadef::PluginManager::IsSplitOpp();
  GELOGI("Start to load ops proto package, is_split:[%d].", is_split);
  for (int32_t v = 0; v < static_cast<int32_t>(gert::OppImplVersionTag::kVersionEnd); ++v) {
    const auto version = static_cast<gert::OppImplVersionTag>(v);
    std::vector<std::pair<std::string, gert::OppSoDesc>> package_to_opp_so_desc;
    is_split = metadef::PluginManager::IsSplitOpp();
    if (version == gert::OppImplVersionTag::kOppKernel && !is_split) {
      // 非拆分模式下，无需加载OppKernel目录下so
      continue;
    }
    LoadOpsProtoSo(version, package_to_opp_so_desc, is_split);
    for (const auto &item : package_to_opp_so_desc) {
      auto package_name = item.first;
      auto so_list_opp = item.second;
      LoadSoAndInitDefault(so_list_opp.GetSoPaths(), version, package_name);
    }
  }
}

void OppSoManager::LoadOppPackage() const {
  const std::lock_guard<std::mutex> lock(mutex_);
  for (int32_t v = 0; v < static_cast<int32_t>(gert::OppImplVersionTag::kVersionEnd); ++v) {
    const auto version = static_cast<gert::OppImplVersionTag>(v);
    std::vector<std::pair<std::string, gert::OppSoDesc>> package_to_opp_so_desc_opp;
    const bool is_split = metadef::PluginManager::IsSplitOpp();
    if (version == gert::OppImplVersionTag::kOppKernel && !is_split) {
      // 非拆分模式下，无需加载OppKernel目录下so
      continue;
    }
    GELOGI("Start to load opp package, opp_impl_version: %d, is_split:[%d].", v, is_split);
    LoadOpsProtoSo(version, package_to_opp_so_desc_opp, is_split);
    LoadOpMasterSo(version, package_to_opp_so_desc_opp, is_split);
    for (const auto &item : package_to_opp_so_desc_opp) {
      auto package_name = item.first;
      auto so_list_opp = item.second;
      LoadSoAndInitDefault(so_list_opp.GetSoPaths(), version, package_name);
    }
  }
}

void OppSoManager::LoadOpsProtoSo(gert::OppImplVersionTag version, std::vector<std::pair<std::string, gert::OppSoDesc>> &package_to_opp_so_desc, bool is_split) const {
  std::string ops_proto_path;
  auto it = kVersion2GetProtoPathFunc.find(version);
  if (it == kVersion2GetProtoPathFunc.end()) {
    GELOGW("[LoadOpsProtoSo] Not find get ops proto function with version:%d", static_cast<int32_t>(version));
    return;
  }
  GELOGI("Start to load ops proto package, opp_impl_version: %d, is_split:[%d].", static_cast<int32_t>(version), is_split);
  if (it->second(ops_proto_path) != ge::SUCCESS) {
    GELOGW("[LoadOpsProtoSo] Get ops proto path failed, opp_impl_version: %d", static_cast<int32_t>(version));
    return;
  }

  std::string os_type;
  std::string cpu_type;
  metadef::PluginManager::GetCurEnvPackageOsAndCpuType(os_type, cpu_type);

  std::vector<std::string> v_path;
  metadef::PluginManager::SplitPath(ops_proto_path, v_path);
  for (size_t i = 0UL; i < v_path.size(); ++i) {
    if (v_path[i].back() != '/') {
       v_path[i] += '/';
    }
    std::array<char_t, MMPA_MAX_PATH> resolved_path{};
    // 加载自定义算子so
    const auto idx = v_path[i].find(kBuiltIn);
    if (idx == std::string::npos) {
      std::string path = v_path[i] + "lib/" + os_type + "/" + cpu_type + "/";
      const INT32 result = mmRealPath(path.c_str(), &(resolved_path[0U]), MMPA_MAX_PATH);
      if (result != EN_OK) {
        GELOGW("[FindSo][Check] Get path with os&cpu type [%s] failed, reason:%s", path.c_str(), strerror(errno));
        continue;
      }
      GetOppSoList(path, {kSoSuffix}, package_to_opp_so_desc, version);
      continue;
    }
    // 加载built-in算子so
    std::string path = v_path[i].substr(0, idx) + kBuiltIn;
    bool is_sub_pkg = false;
    path = metadef::PluginManager::GetOppPkgPath(path, kOpsProtoPath, kOpsGraphPath, os_type + "/" + cpu_type + "/", is_sub_pkg);
    if (is_sub_pkg) {
      GetOppSoList(path, {kSoSuffix}, package_to_opp_so_desc, version);
    } else {
      if (mmRealPath(path.c_str(), &(resolved_path[0U]), MMPA_MAX_PATH) != EN_OK) {
        GELOGW("[FindSo][Check] Get path with os&cpu type [%s] failed, reason:%s", path.c_str(), strerror(errno));
        continue;
      }
      if (is_split) {
        GetOppSoList(path, {kCtSoSuffix, kRtSoSuffix}, package_to_opp_so_desc, version);
      } else {
        GetOppSoList(path, {kCtSoSuffix, kRt2SoSuffix}, package_to_opp_so_desc, version);
      }
    }
  }
}

void OppSoManager::LoadOpMasterSo(gert::OppImplVersionTag version, std::vector<std::pair<std::string, gert::OppSoDesc>> &package_to_opp_so_desc, bool is_split) const {
  std::string op_tiling_path;
  auto it = kVersion2GetMasterPathFunc.find(version);
  if (it == kVersion2GetMasterPathFunc.end()) {
    GELOGW("[LoadOpsProtoSo] Not find get ops proto function with version:%d", static_cast<int32_t>(version));
    return;
  }
  GELOGI("Start to load ops master package, opp_impl_version: %d, is_split:[%d].", static_cast<int32_t>(version), is_split);
  if (it->second(op_tiling_path) != ge::SUCCESS) {
    GELOGW("[LoadOpsProtoSo] Get ops proto path failed, opp_impl_version: %d", static_cast<int32_t>(version));
    return;
  }

  std::string os_type;
  std::string cpu_type;
  metadef::PluginManager::GetCurEnvPackageOsAndCpuType(os_type, cpu_type);

  std::vector<std::string> path_vec;
  metadef::PluginManager::SplitPath(op_tiling_path, path_vec);
  for (auto &path : path_vec) {
    if (path.back() != '/') {
      path += '/';
    }
    // 加载自定义算子so
    std::array<char_t, MMPA_MAX_PATH> resolved_path{};
    const auto idx = path.find(kBuiltIn);
    if (idx == std::string::npos) {
      std::string root_path = path + "op_master/lib/" + os_type + "/" + cpu_type + "/";
      if (mmRealPath(root_path.c_str(), &(resolved_path[0U]), MMPA_MAX_PATH) != EN_OK) {
        GELOGW("Get path with op_master path [%s] failed, reason:%s", root_path.c_str(), strerror(errno));
        root_path = path + "op_tiling/lib/" + os_type + "/" + cpu_type + "/";
        if (mmRealPath(root_path.c_str(), &(resolved_path[0U]), MMPA_MAX_PATH) != EN_OK) {
          GELOGW("Get path with op_tiling path [%s] failed, reason:%s", root_path.c_str(), strerror(errno));
          continue;
        }
      }
      GetOppSoList(root_path, {kSoSuffix}, package_to_opp_so_desc, version);
      continue;
    }
    // 加载built-in算子so
    std::string root_path = path.substr(0, idx) + kBuiltIn;
    bool is_sub_pkg = false;
    root_path = metadef::PluginManager::GetOppPkgPath(root_path, kOpMasterPath, kOpHostPath, os_type + "/" + cpu_type + "/",
                                             is_sub_pkg);
    if (is_sub_pkg) {
      GetOppSoList(root_path, {kSoSuffix}, package_to_opp_so_desc, version);
    } else {
      if (mmRealPath(root_path.c_str(), &(resolved_path[0U]), MMPA_MAX_PATH) != EN_OK) {
        GELOGW("Get path with op_tiling path [%s] failed, reason:%s", root_path.c_str(), strerror(errno));
        continue;
      }
      if (is_split) {
        GetOppSoList(root_path, {kCtSoSuffix, kRtSoSuffix}, package_to_opp_so_desc, version);
      } else {
        GetOppSoList(root_path, {kCtSoSuffix, kRt2SoSuffix}, package_to_opp_so_desc, version);
      }
    }
  }
}

OppSoManager &OppSoManager::GetInstance() {
  static OppSoManager instance;
  return instance;
}
}  // namespace ge
