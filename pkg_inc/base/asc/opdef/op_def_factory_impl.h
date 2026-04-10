/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef OP_DEF_FACTORY_IMPL_H
#define OP_DEF_FACTORY_IMPL_H

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include "register/op_def.h"

namespace ops {
using OpDefCreator = std::function<OpDef(const char *)>;
using OpDefFuncPtr = OpDef(*)(const char *);

class OpDefFactoryImpl {
public:
  static OpDefFactoryImpl& GetInstance();
  int OpDefRegister(const char *name, OpDefCreator creator);
  int OpDefRegisterV2(const char *name, OpDefFuncPtr ptr);
  OpDef OpDefCreate(const char *name);
  std::vector<ge::AscendString> &GetAllOp(void);
  void OpTilingSinkRegister(const char *opType);
  bool OpIsTilingSink(const char *opType);

private:
  std::map<ge::AscendString, OpDefCreator> g_opsdef_creator;
  std::map<ge::AscendString, OpDefFuncPtr> g_opsdef_creator_v2;
  std::vector<ge::AscendString> g_ops_list;
  std::set<ge::AscendString> g_ops_sink_list;
};
}  // namespace ops

#endif
