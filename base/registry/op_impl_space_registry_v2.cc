/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <memory>
#include "common/checker.h"
#include "common/util/mem_utils.h"
#include "base/registry/op_impl_space_registry_v2.h"
#include "graph/debug/ge_util.h"
#include "base/registry/op_impl_space_registry_v2_impl.h"
#include "graph/any_value.h"

namespace gert {

OpImplSpaceRegistryV2::OpImplSpaceRegistryV2() {
  impl_ = ge::MakeShared<OpImplSpaceRegistryImpl>();
}

ge::graphStatus OpImplSpaceRegistryV2::AddSoToRegistry(const OppSoDesc &so_desc) {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->AddSoToRegistry(so_desc);
}

const OpImplKernelRegistry::OpImplFunctionsV2 *OpImplSpaceRegistryV2::GetOpImpl(const char_t *op_type) const {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->GetOpImpl(op_type);
}

OpImplKernelRegistry::OpImplFunctionsV2 *OpImplSpaceRegistryV2::CreateOrGetOpImpl(const char_t *op_type) {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->CreateOrGetOpImpl(op_type);
}

ge::graphStatus OpImplSpaceRegistryV2::AddRegistry(const std::shared_ptr<OpImplRegistryHolder> &registry_holder) {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->AddRegistry(registry_holder);
}

class DefaultOpImplSpaceRegistryV2Impl {
 public:
  DefaultOpImplSpaceRegistryV2Impl() = default;
  using OpImplSpaceRegistryV2Array =
      std::array<std::shared_ptr<OpImplSpaceRegistryV2>, static_cast<size_t>(gert::OppImplVersionTag::kVersionEnd)>;
  OpImplSpaceRegistryV2Array space_registries_;
};


DefaultOpImplSpaceRegistryV2::DefaultOpImplSpaceRegistryV2() {
  impl_ = ge::ComGraphMakeUnique<DefaultOpImplSpaceRegistryV2Impl>();
}

DefaultOpImplSpaceRegistryV2 &DefaultOpImplSpaceRegistryV2::GetInstance() {
  static DefaultOpImplSpaceRegistryV2 instance;
  return instance;
}

const std::shared_ptr<OpImplSpaceRegistryV2> DefaultOpImplSpaceRegistryV2::GetSpaceRegistry(
    gert::OppImplVersionTag opp_impl_version) const {
  GE_ASSERT_NOTNULL(impl_);
  GE_ASSERT_TRUE(opp_impl_version < gert::OppImplVersionTag::kVersionEnd);
  return impl_->space_registries_[static_cast<size_t>(opp_impl_version)];
}

ge::graphStatus DefaultOpImplSpaceRegistryV2::SetSpaceRegistry(
    const std::shared_ptr<OpImplSpaceRegistryV2> &space_registry_v2, gert::OppImplVersionTag version_tag) {
  GE_ASSERT_NOTNULL(impl_);
  GE_ASSERT_TRUE(version_tag < gert::OppImplVersionTag::kVersionEnd);
  impl_->space_registries_[static_cast<size_t>(version_tag)] = space_registry_v2;
  return ge::GRAPH_SUCCESS;
}

void DefaultOpImplSpaceRegistryV2::ClearSpaceRegistry() {
  for (auto &space_registry_v2 : impl_->space_registries_) {
    space_registry_v2.reset();
  }
}
}  // namespace gert
