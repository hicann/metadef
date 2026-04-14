/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef INC_REGISTER_OP_CHECK_REGISTER_IMPL_H_
#define INC_REGISTER_OP_CHECK_REGISTER_IMPL_H_

#include <map>

#include "graph/ascend_string.h"
#include "graph/ge_error_codes.h"
#include "register/op_def.h"
#include "register/op_check_register.h"

namespace ge {
  class Operator;
}

namespace optiling {
class OpCheckFuncRegistryImpl {
public:
  static OpCheckFuncRegistryImpl& GetInstance();
  void RegisterOpCapability(const ge::AscendString &check_type, const ge::AscendString &op_type,
                                   OP_CHECK_FUNC func);

  OP_CHECK_FUNC GetOpCapability(const ge::AscendString &check_type, const ge::AscendString &op_type);

  void RegisterGenSimplifiedKeyFunc(const ge::AscendString &op_type, GEN_SIMPLIFIEDKEY_FUNC func);

  GEN_SIMPLIFIEDKEY_FUNC GetGenSimplifiedKeyFun(const ge::AscendString &op_type);

  PARAM_GENERALIZE_FUNC GetParamGeneralize(const ge::AscendString &op_type);

  void RegisterParamGeneralize(const ge::AscendString &op_type, PARAM_GENERALIZE_FUNC func);

  void RegisterReplay(const ge::AscendString &op_type, const ge::AscendString &soc_version, REPLAY_FUNC func);
  REPLAY_FUNC GetReplay(const ge::AscendString &op_type, const ge::AscendString &soc_version);
private:
  OpCheckFuncRegistryImpl() = default;
  ~OpCheckFuncRegistryImpl() = default;

  std::map<ge::AscendString, std::map<ge::AscendString, OP_CHECK_FUNC>> check_op_capability_instance_;
  std::map<ge::AscendString, GEN_SIMPLIFIEDKEY_FUNC> gen_simplifiedkey_instance_;
  std::map<ge::AscendString, PARAM_GENERALIZE_FUNC> param_generalize_instance_;
  std::map<ge::AscendString, std::map<ge::AscendString, REPLAY_FUNC>> replay_instance_;
};

}  // end of namespace optiling
#endif  // INC_REGISTER_OP_CHECK_REGISTER_H_
