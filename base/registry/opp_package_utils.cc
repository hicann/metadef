/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "common/checker.h"
#include "graph/debug/ge_util.h"
#include "register/opp_so_manager.h"
#include "base/registry/opp_package_utils.h"

namespace gert {
class OppSoDescImpl {
public:
  OppSoDescImpl(const std::vector<ge::AscendString> &so_path_vector, const ge::AscendString &pkg_name)
      : so_paths(so_path_vector), package_name(pkg_name) {}
  ~OppSoDescImpl() = default;
  std::vector<ge::AscendString> so_paths;
  ge::AscendString package_name;
};

OppSoDesc::OppSoDesc(const std::vector<ge::AscendString> &so_paths, const ge::AscendString &package_name) {
  impl_ = ge::ComGraphMakeUnique<OppSoDescImpl>(so_paths, package_name);
  if (impl_ == nullptr) {
    return;
  }
}

OppSoDesc::~OppSoDesc() = default;

OppSoDesc::OppSoDesc(const OppSoDesc &other) {
  if (other.impl_ == nullptr) {
    return;
  }
  impl_ = ge::ComGraphMakeUnique<OppSoDescImpl>(other.impl_->so_paths, other.impl_->package_name);
}

OppSoDesc &OppSoDesc::operator=(const OppSoDesc &other) {
  if (this == &other) {
    return *this;
  }
  impl_ = ge::ComGraphMakeUnique<OppSoDescImpl>(other.impl_->so_paths, other.impl_->package_name);
  return *this;
}

OppSoDesc::OppSoDesc(OppSoDesc &&other) noexcept {
  impl_ = std::move(other.impl_);
}

OppSoDesc &OppSoDesc::operator=(OppSoDesc &&other) noexcept {
  if (this == &other) {
    return *this;
  }
  impl_ = std::move(other.impl_);
  return *this;
}

std::vector<ge::AscendString> OppSoDesc::GetSoPaths() const {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->so_paths;
}

ge::AscendString OppSoDesc::GetPackageName() const {
  GE_ASSERT_NOTNULL(impl_);
  return impl_->package_name;
}

void OppPackageUtils::LoadAllOppPackage() {
  ge::OppSoManager::GetInstance().LoadOppPackage();
}

}  // namespace gert
