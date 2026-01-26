/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <cstring>
#include <securec.h>
#ifndef ASCENDC_DEVICE_REG_STATIC
#include "common/ge_common/debug/ge_log.h"
#endif
#include "graph/ascend_string.h"
#include "register/tilingdata_base.h"
#include "base/asc/tilingdata_base_impl.h"

namespace optiling {
bool CheckPathIsHeader(std::string file) {
  const std::string suffix = ".h";
  if (suffix.size() > file.size()) {
    return false;
  }
  return file.substr(file.size() - suffix.size()) == suffix;
}

const char* GetFileName(const char* path) {
  const char* file_name = strrchr(path, '/');
  if (!file_name) {
    return path;
  } else {
    file_name++;
    return file_name;
  }
}

/*--------------------TilingDefImpl-------------------------*/

std::vector<FieldInfo> TilingDefImpl::GetFieldInfo(const TilingDef& tiling) {
  return tiling.field_info_;
}

const char *TilingDefImpl::GetTilingClassName(const TilingDef& tiling) {
  return tiling.class_name_;
}

size_t TilingDefImpl::GetDataSize(const TilingDef& tiling) {
  return tiling.data_size_;
}

void TilingDefImpl::GeLogError(const std::string &str) {
#ifndef ASCENDC_DEVICE_REG_STATIC
  GELOGE(ge::GRAPH_FAILED, "%s", str.c_str());
#endif
  (void)str; // to avoid unused parameter warning
}

void TilingDefImpl::SetDataPtr(TilingDef& tiling, void *dataPtr) {
  if (!tiling.inited_data_ptr && tiling.data_ptr_ != nullptr) {
    delete[] tiling.data_ptr_;
  }
  tiling.inited_data_ptr = true;
  tiling.data_ptr_ = (uint8_t*)dataPtr;
  for (auto &ptr : tiling.saveBufferPtr) {
    TilingDef* sub_ptr = (TilingDef *)ptr.first;
    size_t offset = ptr.second;
    uint8_t* struct_ptr = tiling.data_ptr_ + offset;
    sub_ptr->SetDataPtr(struct_ptr);
  }
}

void TilingDefImpl::SaveToBuffer(TilingDef& tiling, void *pdata, size_t capacity) {
  if (tiling.inited_data_ptr) {
#ifndef ASCENDC_DEVICE_REG_STATIC
    GELOGD("TilingDef::SaveToBuffer, op %s, data had been saved.", tiling.class_name_);
#endif
    return;
  }
  // copy tilingdata to buffer without struct tiling data.
  auto mem_ret = memcpy_s(pdata, capacity, tiling.data_ptr_, tiling.data_size_);
  if (mem_ret != EOK) {
#ifndef ASCENDC_DEVICE_REG_STATIC
    GELOGE(ge::GRAPH_FAILED,
           "TilingDef::SaveToBuffer failed: memcpy_s return op [%s] [%d], capacity = [%zu], data_size_ = [%zu].",
           tiling.class_name_, mem_ret, capacity, tiling.data_size_);
#endif
  }
}

void TilingDefImpl::CheckAlignAndGenPlaceHolder(TilingDef& tiling, const char *name, size_t typeSize) {
  if (tiling.data_size_ % typeSize == 0) {
    return;
  }
  size_t alignSize = typeSize - (tiling.data_size_ % typeSize);
  tiling.field_info_.emplace_back(FieldInfo("uint8_t", name, alignSize));
  tiling.data_size_ += alignSize;
  return;
}

void TilingDefImpl::InitData(TilingDef& tiling) {
#ifndef ASCENDC_DEVICE_REG_STATIC
    GELOGD("TilingDef::InitData, op %s, data size %d.", tiling.class_name_, tiling.data_size_);
#endif
    tiling.data_ptr_ = new (std::nothrow)uint8_t[tiling.data_size_]();
    if (tiling.data_ptr_ == nullptr) {
#ifndef ASCENDC_DEVICE_REG_STATIC
          GELOGE(ge::GRAPH_FAILED, "TilingDef::InitData failed: op %s, init data size %d.", tiling.class_name_, tiling.data_size_);
#endif
          return;
    }
    for (auto &ptr : tiling.saveBufferPtr) {
      TilingDef* sub_ptr = (TilingDef *)ptr.first;
      size_t offset = ptr.second;
      uint8_t* struct_ptr = tiling.data_ptr_ + offset;
      sub_ptr->SetDataPtr(struct_ptr);
    }
}

/*--------------------TilingDef-------------------------*/

void TilingDef::SaveToBuffer(void *pdata, size_t capacity) {
	TilingDefImpl::SaveToBuffer(*this, pdata, capacity);
}

std::vector<FieldInfo> TilingDef::GetFieldInfo() const {
  return TilingDefImpl::GetFieldInfo(*this);
}

const char *TilingDef::GetTilingClassName() const {
  return TilingDefImpl::GetTilingClassName(*this);
}

size_t TilingDef::GetDataSize() const {
  return TilingDefImpl::GetDataSize(*this);
}

void TilingDef::SetDataPtr(void *dataPtr) {
	TilingDefImpl::SetDataPtr(*this, dataPtr);
}

void TilingDef::CheckAlignAndGenPlaceHolder(const char *name, size_t typeSize) {
  TilingDefImpl::CheckAlignAndGenPlaceHolder(*this, name, typeSize);
}

void TilingDef::InitData() {
	TilingDefImpl::InitData(*this);
}

void TilingDef::GeLogError(const std::string &str) const {
  TilingDefImpl::GeLogError(str);
}

/*--------------------CTilingDataClassFactoryImpl-------------------------*/
CTilingDataClassFactoryImpl &CTilingDataClassFactoryImpl::GetInstance()
{
  static CTilingDataClassFactoryImpl instance;
  return instance;
}

void CTilingDataClassFactoryImpl::RegisterTilingData(const char *op_type,
                                                 const TilingDataConstructor constructor) {
  instance_->emplace(op_type, constructor);
#ifndef ASCENDC_DEVICE_REG_STATIC
  GELOGD("op_type: %s, registered count: %zu.", op_type, instance_->size());
#endif
}

std::shared_ptr<TilingDef> CTilingDataClassFactoryImpl::CreateTilingDataInstance(const char *op_type) {
  const auto it = instance_->find(op_type);
  if (it == instance_->end()) {
#ifndef ASCENDC_DEVICE_REG_STATIC
    GELOGW("cannot find op_type:%s.", op_type);
#endif
    return nullptr;
  }

  const TilingDataConstructor constructor = it->second;
  if (constructor == nullptr) {
#ifndef ASCENDC_DEVICE_REG_STATIC
    GELOGW("CreateTilingDataInstance: constructor is nullptr.");
#endif
    return nullptr;
  }

  return (*constructor)();
}

CTilingDataClassFactoryImpl::CTilingDataClassFactoryImpl()
    : instance_(std::make_unique<std::map<const char *, TilingDataConstructor, CharPtrCmp>>()) {}

/*--------------------CTilingDataClassFactory-------------------------*/
CTilingDataClassFactory &CTilingDataClassFactory::GetInstance()
{
  static CTilingDataClassFactory instance;
  return instance;
}

void CTilingDataClassFactory::RegisterTilingData(const char *op_type,
                                                 const TilingDataConstructor constructor) {
  CTilingDataClassFactoryImpl::GetInstance().RegisterTilingData(op_type, constructor);
}

std::shared_ptr<TilingDef> CTilingDataClassFactory::CreateTilingDataInstance(const char *op_type) {
  return CTilingDataClassFactoryImpl::GetInstance().CreateTilingDataInstance(op_type);
}

/*--------------------TilingDataStructBaseImpl-------------------------*/
TilingDataStructBaseImpl& TilingDataStructBaseImpl::GetInstance() {
	static TilingDataStructBaseImpl instance;
	return instance;
}

uint32_t __attribute__((weak)) TilingDataStructBaseImpl::RecordTilingStruct(const char* name, const char* file, \
    uint32_t line) {
  const char* file_name = GetFileName(file);
  bool is_header = CheckPathIsHeader(std::string(file_name));
  auto it = records->find(name);
  if (it != records->end()) {
    std::pair<const char *, uint32_t> item = it->second;
    if (!is_header) {
      if (item.second != line) {
          printf("[Warning]: tiling struct [%s] is conflict with one in file %s, line %d\n", \
              name, item.first, item.second);
      }
      return 0;
    }
    if (!CheckPathIsHeader(std::string(item.first))) {
      return 0;
    }
    if ((strcmp(item.first, file_name) == 0) && item.second == line) {
      return 0;
    }
    printf("[Warning]: tiling struct [%s] is conflict with one in file %s, line %d\n", \
        name, item.first, item.second);
  } else {
    records->emplace(name, std::make_pair(file_name, line));
  }
  return 0;
}

TilingDataStructBaseImpl::TilingDataStructBaseImpl()
    : records(std::make_unique<std::map<const char *, std::pair<const char *, uint32_t>, CharPtrCmp>>()) {}

/*--------------------TilingDataStructBase-------------------------*/

uint32_t __attribute__((weak)) TilingDataStructBase::RecordTilingStruct(const char* name, const char* file, \
    uint32_t line) {
  return TilingDataStructBaseImpl::GetInstance().RecordTilingStruct(name, file, line);
}
}  // end of namespace optiling
