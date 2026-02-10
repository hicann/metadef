/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <utility>
#include "graph/debug/ge_util.h"
#include "base/registry/op_impl_space_registry_v2.h"
#include "common/checker.h"
#include "common/util/mem_utils.h"
#include "graph/any_value.h"
#include "common/ge_common/debug/ge_log.h"
#include "register/op_impl_registry.h"
#include "register/op_impl_registry_holder_manager.h"
#include "mmpa/mmpa_api.h"
#include "register/op_impl_space_registry.h"
#include "base/registry/opp_package_utils.h"
#include "graph/ascend_string.h"
#include "inc/common/plugin/plugin_manager.h"
#include "common/ge_common/util.h"

namespace gert {
OpImplSpaceRegistry::OpImplSpaceRegistry() : std::enable_shared_from_this<OpImplSpaceRegistry>(),
                                             impl_(std::make_shared<OpImplSpaceRegistryV2>()) {}

OpImplSpaceRegistry::OpImplSpaceRegistry(OpImplSpaceRegistryV2Ptr ptr) :
  std::enable_shared_from_this<OpImplSpaceRegistry>(), impl_(std::move(ptr)) {}

ge::graphStatus OpImplSpaceRegistry::AddRegistry(const std::shared_ptr<OpImplRegistryHolder> &registry_holder) {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->AddRegistry(registry_holder);
}

OpImplKernelRegistry::OpImplFunctionsV2 *OpImplSpaceRegistry::CreateOrGetOpImpl(const std::string &op_type) {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->CreateOrGetOpImpl(op_type.c_str());
}

const OpImplKernelRegistry::OpImplFunctionsV2 *OpImplSpaceRegistry::GetOpImpl(const std::string &op_type) const {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->GetOpImpl(op_type.c_str());
}

const OpCtImplKernelRegistry::OpCtImplFunctions *OpImplSpaceRegistry::GetOpCtImpl(const std::string &op_type) const {
  auto funcs = impl_->GetOpImpl(op_type.c_str());
  if (funcs == nullptr) {
    return nullptr;
  }
  // 后续IMPL_CT_OP合并到IMPL_OP, 当前版本st_size、version均无人使用
  // 当前是临时兼容，GE后续切换到OpImplSpaceRegistryV2类使用
  auto &iter = merged_types_to_ct_impl_[op_type.c_str()];
  iter.st_size = funcs->st_size;
  iter.version = funcs->version;
  iter.calc_op_param = funcs->calc_op_param;
  iter.gen_task = funcs->gen_task;
  iter.check_support = funcs->check_support;
  iter.op_select_format = funcs->op_select_format;
  iter.get_op_support_info = funcs->get_op_support_info;
  iter.get_op_specific_info = funcs->get_op_specific_info;
  return &iter;
}

const OpImplRegisterV2::PrivateAttrList &OpImplSpaceRegistry::GetPrivateAttrs(const std::string &op_type) const {
  if (impl_ == nullptr || impl_->GetOpImpl(op_type.c_str()) == nullptr) {
    static OpImplRegisterV2::PrivateAttrList emptyPrivateAttr;
    return emptyPrivateAttr;
  }
  return impl_->GetOpImpl(op_type.c_str())->private_attrs;
}

ge::graphStatus OpImplSpaceRegistry::LoadSoAndSaveToRegistry(const std::string &so_path) {
  return ConvertSoToRegistry(so_path, ge::OppImplVersion::kOpp);
}

ge::graphStatus OpImplSpaceRegistry::ConvertSoToRegistry(const std::string &so_path,
                                                         ge::OppImplVersion opp_impl_version) {
  GELOGI("Convert so to registry, so path:%s, opp_impl_version: %d", so_path.c_str(),
         static_cast<int32_t>(opp_impl_version));
  const auto opp_version_tag = static_cast<gert::OppImplVersionTag>(opp_impl_version);
  GE_ASSERT_TRUE(opp_version_tag < gert::OppImplVersionTag::kVersionEnd);
  auto space_registry_v2 =
      gert::DefaultOpImplSpaceRegistryV2::GetInstance().GetSpaceRegistry(opp_version_tag);
  if (space_registry_v2 == nullptr) {
    space_registry_v2 = std::make_shared<gert::OpImplSpaceRegistryV2>();
    GE_CHECK_NOTNULL(space_registry_v2);
    (void)gert::DefaultOpImplSpaceRegistryV2::GetInstance().SetSpaceRegistry(space_registry_v2, opp_version_tag);
  }
  OppSoDesc opp_so_desc({ge::AscendString(so_path.c_str())},
    ge::AscendString(metadef::PluginManager::GetSoPackageName(so_path).c_str()));
  return space_registry_v2->AddSoToRegistry(opp_so_desc);
}

DefaultOpImplSpaceRegistry &DefaultOpImplSpaceRegistry::GetInstance() {
  static DefaultOpImplSpaceRegistry instance;
  return instance;
}

const OpImplSpaceRegistryArray &DefaultOpImplSpaceRegistry::GetDefaultSpaceRegistries() {
  for (size_t i = 0; i < space_registries_.size(); i++) {
    if (space_registries_[i] == nullptr) {
      space_registries_[i] = GetDefaultSpaceRegistry(static_cast<ge::OppImplVersion>(i));
    }
  }
  return space_registries_;
}

OpImplSpaceRegistryPtr &DefaultOpImplSpaceRegistry::GetDefaultSpaceRegistry(ge::OppImplVersion opp_impl_version) {
  static OpImplSpaceRegistryPtr null_ptr = nullptr;
  if (opp_impl_version > ge::OppImplVersion::kVersionEnd) {
    return null_ptr;
  }
  const auto version = static_cast<gert::OppImplVersionTag>(opp_impl_version);
  if (space_registries_[static_cast<size_t>(version)] != nullptr) {
    return space_registries_[static_cast<size_t>(version)];
  }
  auto space_registry_v2 = DefaultOpImplSpaceRegistryV2::GetInstance().GetSpaceRegistry(version);
  if (space_registry_v2 == nullptr) {
    return null_ptr;
  }
  space_registries_[static_cast<size_t>(version)] = ge::MakeShared<OpImplSpaceRegistry>(space_registry_v2);
  return space_registries_[static_cast<size_t>(version)];
}

OpImplSpaceRegistryPtr &DefaultOpImplSpaceRegistry::GetDefaultSpaceRegistry(OppImplVersionTag opp_impl_version_tag) {
  size_t opp_impl_version = static_cast<size_t>(opp_impl_version_tag);
  return GetDefaultSpaceRegistry(static_cast<ge::OppImplVersion>(opp_impl_version));
}

void DefaultOpImplSpaceRegistry::SetDefaultSpaceRegistry(const OpImplSpaceRegistryPtr &space_registry,
                                                         ge::OppImplVersion opp_impl_version) {
  if (opp_impl_version > ge::OppImplVersion::kVersionEnd) {
    return;
  }
  (void) DefaultOpImplSpaceRegistryV2::GetInstance().SetSpaceRegistry(
      space_registry != nullptr ? space_registry->impl_ : nullptr,
      static_cast<gert::OppImplVersionTag>(opp_impl_version));
  const auto version = static_cast<gert::OppImplVersionTag>(opp_impl_version);
  auto space_registry_v2 = DefaultOpImplSpaceRegistryV2::GetInstance().GetSpaceRegistry(version);
  space_registries_[static_cast<size_t>(version)] =
      space_registry_v2 == nullptr ? nullptr : ge::MakeShared<OpImplSpaceRegistry>(space_registry_v2);
  return;
}

}  // namespace gert
