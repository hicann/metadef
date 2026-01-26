/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __INC_REGISTER_ASCENDC_TILINGDATA_BASE_IMPL_HEADER__
#define __INC_REGISTER_ASCENDC_TILINGDATA_BASE_IMPL_HEADER__

#include <vector>
#include <map>
#include <memory>
#include <cstring>
#include <securec.h>
#include "graph/ascend_string.h"
#include "register/tilingdata_base.h"

namespace optiling {
class TilingDefImpl {
public:
  static void SaveToBuffer(TilingDef &host, void *pdata, size_t capacity);
  static std::vector<FieldInfo> GetFieldInfo(const TilingDef &host);
  static const char *GetTilingClassName(const TilingDef &host);
  static size_t GetDataSize(const TilingDef &host);
  static void SetDataPtr(TilingDef &host, void *dataPtr);
  static void CheckAlignAndGenPlaceHolder(TilingDef &host, const char *name, size_t typeSize);
  static void InitData(TilingDef &host);
  static void GeLogError(const std::string& str);
};

class CTilingDataClassFactoryImpl {
public:
  static CTilingDataClassFactoryImpl &GetInstance();
  void RegisterTilingData(const char *op_type, const TilingDataConstructor constructor);
  std::shared_ptr<TilingDef> CreateTilingDataInstance(const char *op_type);

private:
  CTilingDataClassFactoryImpl();
  ~CTilingDataClassFactoryImpl() = default;
  CTilingDataClassFactoryImpl(const CTilingDataClassFactoryImpl &) = delete;
  CTilingDataClassFactoryImpl &operator=(const CTilingDataClassFactoryImpl &) = delete;
  std::unique_ptr<std::map<const char *, TilingDataConstructor, CharPtrCmp>> instance_;
};

class TilingDataStructBaseImpl {
public:
  static TilingDataStructBaseImpl &GetInstance();
  uint32_t __attribute__((weak)) RecordTilingStruct(const char* name, const char* file, uint32_t line);
private:
  TilingDataStructBaseImpl();
  ~TilingDataStructBaseImpl() = default;
  TilingDataStructBaseImpl(const TilingDataStructBaseImpl &) = delete;
  TilingDataStructBaseImpl &operator=(const TilingDataStructBaseImpl &) = delete;
  std::unique_ptr<std::map<const char *, std::pair<const char *, uint32_t>, CharPtrCmp>> records;
};
}  // end of namespace optiling

#endif  // __INC_REGISTER_ASCENDC_TILINGDATA_BASE_IMPL_HEADER__
