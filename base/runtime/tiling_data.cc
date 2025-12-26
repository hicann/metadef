/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/tiling_data.h"
#include "common/util/tiling_utils.h"
#include "graph/def_types.h"
#include "common/ge_common/util.h"

namespace gert {
namespace {
using AppendAttrFunc = std::function<ge::graphStatus(TilingData *, const RuntimeAttrs *, const size_t)>;

template<typename T1, typename T2>
T2 GetValue(const T1 attr) {
  return static_cast<T2>(attr);
}

template<>
bool GetValue(const float attr) {
  return (std::abs(attr) > std::numeric_limits<float>::epsilon());
}

template<typename T>
ge::graphStatus CheckOverFlow(const size_t attr_size, const size_t tiling_data_size, const size_t capacity) {
  size_t append_size;
  if (ge::MulOverflow(sizeof(T), attr_size, append_size)) {
    GELOGE(ge::GRAPH_FAILED, "Mul over flow. Attr size is %zu", attr_size);
    return ge::GRAPH_FAILED;
  }
  size_t after_size;
  if (ge::AddOverflow(tiling_data_size, append_size, after_size)) {
    GELOGE(ge::GRAPH_FAILED, "Add over flow. Tiling data size is [%zu], append size is [%zu].", tiling_data_size,
           append_size);
    return ge::GRAPH_FAILED;
  }
  if (after_size > capacity) {
    GELOGE(ge::GRAPH_FAILED, "After size [%zu] is out of range, tiling data capacity is [%zu].", after_size, capacity);
    return ge::GRAPH_FAILED;
  }
  return ge::GRAPH_SUCCESS;
}

// get basic type attr and append
template<typename T>
ge::graphStatus AppendAttr(TilingData *tiling_data, const RuntimeAttrs *attrs, const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const T *attr = attrs->GetAttrPointer<T>(attr_index);
  GE_CHECK_NOTNULL(attr);
  return tiling_data->Append<T>(*attr);
}

// get basic list type attr and append
template<typename T>
ge::graphStatus AppendListAttr(TilingData *tiling_data, const RuntimeAttrs *attrs, const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVector *attr = attrs->GetAttrPointer<ContinuousVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  return tiling_data->Append<T>(ge::PtrToPtr<const void, const T>(attr->GetData()), attr->GetSize());
}

// get basic list list type attr and append
template<typename T>
ge::graphStatus AppendListListAttr(TilingData *tiling_data, const RuntimeAttrs *attrs, const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVectorVector *attr = attrs->GetAttrPointer<ContinuousVectorVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    const ContinuousVector *attr_data = attr->Get(i);
    GE_CHECK_NOTNULL(attr_data);
    const auto ret = tiling_data->Append<T>(ge::PtrToPtr<const void, const T>(attr_data->GetData()),
                                            attr_data->GetSize());
    GE_RETURN_IF_ERROR(ret);
  }
  return ge::GRAPH_SUCCESS;
}

// get basic type attr to convert and append
template<typename T1, typename T2>
ge::graphStatus AppendConvertedAttr(TilingData *tiling_data, const RuntimeAttrs *attrs, const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const T1 *attr = attrs->GetAttrPointer<T1>(attr_index);
  GE_CHECK_NOTNULL(attr);
  if (!ge::IntegerChecker<T2>::Compat(*attr)) {
    GELOGW("[Check][Param] attr[%zu] overflow, large than max dst type", attr_index);
  }
  T2 attr_data = GetValue<T1, T2>(*attr);
  return tiling_data->Append<T2>(attr_data);
}

// get basic list type attr to convert and append
template<typename T1, typename T2>
ge::graphStatus AppendConvertedListAttr(TilingData *tiling_data, const RuntimeAttrs *attrs, const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVector *attr = attrs->GetAttrPointer<ContinuousVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const auto ret = CheckOverFlow<T2>(attr->GetSize(), tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  const T1 *attr_data = ge::PtrToPtr<const void, const T1>(attr->GetData());
  GE_CHECK_NOTNULL(attr_data);
  T2 *tiling_data_ptr = ge::PtrToPtr<uint8_t, T2>(ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
  GE_CHECK_NOTNULL(tiling_data_ptr);
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    tiling_data_ptr[i] = GetValue<T1, T2>(attr_data[i]);
  }
  data_size += attr->GetSize() * sizeof(T2);
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// get basic list list type attr to convert and append
template<typename T1, typename T2>
ge::graphStatus AppendConvertedListListAttr(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                            const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVectorVector *attr = attrs->GetAttrPointer<ContinuousVectorVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  size_t attr_size = 0UL;
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    attr_size += attr->Get(i)->GetSize();
  }
  const auto ret = CheckOverFlow<T2>(attr_size, tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    const ContinuousVector *attr_data = attr->Get(i);
    GE_CHECK_NOTNULL(attr_data);
    const T1 *attr_data_data = ge::PtrToPtr<const void, const T1>(attr_data->GetData());
    GE_CHECK_NOTNULL(attr_data_data);
    T2 *tiling_data_ptr = ge::PtrToPtr<uint8_t, T2>(ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
    GE_CHECK_NOTNULL(tiling_data_ptr);
    for (size_t j = 0UL; j < attr_data->GetSize(); ++j) {
      tiling_data_ptr[j] = GetValue<T1, T2>(attr_data_data[j]);
    }
    data_size += attr_data->GetSize() * sizeof(T2);
  }
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// get char * attr type to append
ge::graphStatus AppendStrAttr(TilingData *tiling_data, const RuntimeAttrs *attrs, const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const char *attr = attrs->GetAttrPointer<char>(attr_index);
  GE_CHECK_NOTNULL(attr);
  return tiling_data->Append<char>(attr, strlen(attr));
}

// convert float32 attr to float16 and append
ge::graphStatus AppendConvertedF32AttrToF16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                            const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const float *attr = attrs->GetAttrPointer<float>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const uint16_t target_attr_val = optiling::Float32ToFloat16(*attr);
  return tiling_data->Append<uint16_t>(target_attr_val);
}

// convert list_float32 attr to list_float16 and append
ge::graphStatus AppendConvertedListF32AttrToF16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                                const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVector *attr = attrs->GetAttrPointer<ContinuousVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const auto ret = CheckOverFlow<uint16_t>(attr->GetSize(), tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  const float *attr_data = ge::PtrToPtr<const void, const float>(attr->GetData());
  GE_CHECK_NOTNULL(attr_data);
  uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
      ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
  GE_CHECK_NOTNULL(tiling_data_ptr);
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    tiling_data_ptr[i] = optiling::Float32ToFloat16(attr_data[i]);
  }
  data_size += attr->GetSize() * sizeof(uint16_t);
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// convert list_list_float32 attr to list_list_float16 and append
ge::graphStatus AppendConvertedListListF32AttrToF16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                                    const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVectorVector *attr = attrs->GetAttrPointer<ContinuousVectorVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  size_t attr_size = 0UL;
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    attr_size += attr->Get(i)->GetSize();
  }
  const auto ret = CheckOverFlow<uint16_t>(attr_size, tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    const ContinuousVector *attr_data = attr->Get(i);
    GE_CHECK_NOTNULL(attr_data);
    const float *attr_data_data = ge::PtrToPtr<const void, const float>(attr_data->GetData());
    GE_CHECK_NOTNULL(attr_data_data);
    uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
        ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
    GE_CHECK_NOTNULL(tiling_data_ptr);
    for (size_t j = 0UL; j < attr_data->GetSize(); ++j) {
      tiling_data_ptr[j] = optiling::Float32ToFloat16(attr_data_data[j]);
    }
    data_size += attr_data->GetSize() * sizeof(uint16_t);
  }
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// convert float32 attr to Bfloat16 and append
ge::graphStatus AppendConvertedF32AttrToBf16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                             const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const float *attr = attrs->GetAttrPointer<float>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const uint16_t target_attr_val = optiling::Float32ToBfloat16(*attr);
  return tiling_data->Append<uint16_t>(target_attr_val);
}

// convert List_float32 attr to List_Bfloat16 and append
ge::graphStatus AppendConvertedListF32AttrToBf16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                                 const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVector *attr = attrs->GetAttrPointer<ContinuousVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const auto ret = CheckOverFlow<uint16_t>(attr->GetSize(), tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  const float *attr_data = ge::PtrToPtr<const void, const float>(attr->GetData());
  GE_CHECK_NOTNULL(attr_data);
  uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
      ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
  GE_CHECK_NOTNULL(tiling_data_ptr);
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    tiling_data_ptr[i] = optiling::Float32ToBfloat16(attr_data[i]);
  }
  data_size += attr->GetSize() * sizeof(uint16_t);
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// convert List_List_float32 attr to List_List_Bfloat16 and append
ge::graphStatus AppendConvertedListListF32AttrToBf16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                                     const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVectorVector *attr = attrs->GetAttrPointer<ContinuousVectorVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  size_t attr_size = 0UL;
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    attr_size += attr->Get(i)->GetSize();
  }
  const auto ret = CheckOverFlow<uint16_t>(attr_size, tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    const ContinuousVector *attr_data = attr->Get(i);
    GE_CHECK_NOTNULL(attr_data);
    const float *attr_data_data = ge::PtrToPtr<const void, const float>(attr_data->GetData());
    GE_CHECK_NOTNULL(attr_data_data);
    uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
        ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
    GE_CHECK_NOTNULL(tiling_data_ptr);
    for (size_t j = 0UL; j < attr_data->GetSize(); ++j) {
      tiling_data_ptr[j] = optiling::Float32ToBfloat16(attr_data_data[j]);
    }
    data_size += attr_data->GetSize() * sizeof(uint16_t);
  }
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// convert attr to float16 and append
template<typename T>
ge::graphStatus AppendConvertedAttrToF16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                         const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const T *attr = attrs->GetAttrPointer<T>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const uint16_t target_attr_val = optiling::OtherToFloat16<T>(*attr);
  return tiling_data->Append<uint16_t>(target_attr_val);
}

// convert list attr to list_float16 and append
template<typename T>
ge::graphStatus AppendConvertedListAttrToF16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                             const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVector *attr = attrs->GetAttrPointer<ContinuousVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const auto ret = CheckOverFlow<uint16_t>(attr->GetSize(), tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  const T *attr_data = ge::PtrToPtr<const void, const T>(attr->GetData());
  GE_CHECK_NOTNULL(attr_data);
  uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
      ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
  GE_CHECK_NOTNULL(tiling_data_ptr);
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    tiling_data_ptr[i] = optiling::OtherToFloat16<T>(attr_data[i]);
  }
  data_size += attr->GetSize() * sizeof(uint16_t);
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// convert list_list attr to list_list_float16 and append
template<typename T>
ge::graphStatus AppendConvertedListListAttrToF16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                                 const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVectorVector *attr = attrs->GetAttrPointer<ContinuousVectorVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  size_t attr_size = 0UL;
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    attr_size += attr->Get(i)->GetSize();
  }
  const auto ret = CheckOverFlow<uint16_t>(attr_size, tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    const ContinuousVector *attr_data = attr->Get(i);
    GE_CHECK_NOTNULL(attr_data);
    const T *attr_data_data = ge::PtrToPtr<const void, const T>(attr_data->GetData());
    GE_CHECK_NOTNULL(attr_data_data);
    uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
        ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
    GE_CHECK_NOTNULL(tiling_data_ptr);
    for (size_t j = 0UL; j < attr_data->GetSize(); ++j) {
      tiling_data_ptr[j] = optiling::OtherToFloat16<T>(attr_data_data[j]);
    }
    data_size += attr_data->GetSize() * sizeof(uint16_t);
  }
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// convert attr to Bfloat16 and append
template<typename T>
ge::graphStatus AppendConvertedAttrToBf16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                          const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const T *attr = attrs->GetAttrPointer<T>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const uint16_t target_attr_val = optiling::OtherToBfloat16<T>(*attr);
  return tiling_data->Append<uint16_t>(target_attr_val);
}

// convert List attr to List_Bfloat16 and append
template<typename T>
ge::graphStatus AppendConvertedListAttrToBf16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                              const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVector *attr = attrs->GetAttrPointer<ContinuousVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  const auto ret = CheckOverFlow<uint16_t>(attr->GetSize(), tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  const T *attr_data = ge::PtrToPtr<const void, const T>(attr->GetData());
  GE_CHECK_NOTNULL(attr_data);
  uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
      ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
  GE_CHECK_NOTNULL(tiling_data_ptr);
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    tiling_data_ptr[i] = optiling::OtherToBfloat16<T>(attr_data[i]);
  }
  data_size += attr->GetSize() * sizeof(uint16_t);
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

// convert List_List attr to List_List_Bfloat16 and append
template<typename T>
ge::graphStatus AppendConvertedListListAttrToBf16(TilingData *tiling_data, const RuntimeAttrs *attrs,
                                                  const size_t attr_index) {
  GE_CHECK_NOTNULL(tiling_data);
  const ContinuousVectorVector *attr = attrs->GetAttrPointer<ContinuousVectorVector>(attr_index);
  GE_CHECK_NOTNULL(attr);
  size_t attr_size = 0UL;
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    attr_size += attr->Get(i)->GetSize();
  }
  const auto ret = CheckOverFlow<uint16_t>(attr_size, tiling_data->GetDataSize(), tiling_data->GetCapacity());
  GE_RETURN_IF_ERROR(ret);

  auto data_size = tiling_data->GetDataSize();
  for (size_t i = 0UL; i < attr->GetSize(); ++i) {
    const ContinuousVector *attr_data = attr->Get(i);
    GE_CHECK_NOTNULL(attr_data);
    const T *attr_data_data = ge::PtrToPtr<const void, const T>(attr_data->GetData());
    GE_CHECK_NOTNULL(attr_data_data);
    uint16_t *tiling_data_ptr = ge::PtrToPtr<uint8_t, uint16_t>(
        ge::PtrToPtr<void, uint8_t>(tiling_data->GetData()) + data_size);
    GE_CHECK_NOTNULL(tiling_data_ptr);
    for (size_t j = 0UL; j < attr_data->GetSize(); ++j) {
      tiling_data_ptr[j] = optiling::OtherToBfloat16<T>(attr_data_data[j]);
    }
    data_size += attr_data->GetSize() * sizeof(uint16_t);
  }
  tiling_data->SetDataSize(data_size);
  return ge::GRAPH_SUCCESS;
}

template<AttrDataType SRC, AttrDataType DST>
class AttrTable {
public:
  explicit AttrTable(const AppendAttrFunc default_val) {
    for (size_t i = 0UL; i < static_cast<size_t>(SRC); ++i) {
      for (size_t j = 0UL; j < static_cast<size_t>(DST); ++j) {
        elements[i][j] = default_val;
      }
    }
  }

  AppendAttrFunc Find(AttrDataType src, AttrDataType dst) const {
    if (src >= SRC || dst >= DST) {
      return nullptr;
    }
    return elements[static_cast<size_t>(src)][static_cast<size_t>(dst)];
  }

  AttrTable &Add(AttrDataType src, AttrDataType dst, AppendAttrFunc func) {
    elements[static_cast<size_t>(src)][static_cast<size_t>(dst)] = func;
    return *this;
  }

private:
  AppendAttrFunc elements[static_cast<size_t>(SRC)][static_cast<size_t>(DST)];
};

const auto kAttrTable =
    AttrTable<AttrDataType::kTypeEnd, AttrDataType::kTypeEnd>(nullptr)
        // convert string attr to string type
        .Add(AttrDataType::kString, AttrDataType::kString, AppendStrAttr)
        // convert bool attr to other types
        .Add(AttrDataType::kBool, AttrDataType::kBool, AppendAttr<bool>)
        .Add(AttrDataType::kListBool, AttrDataType::kListBool, AppendListAttr<bool>)
        .Add(AttrDataType::kBool, AttrDataType::kFloat16, AppendConvertedAttrToF16<bool>)
        .Add(AttrDataType::kListBool, AttrDataType::kListFloat16, AppendConvertedListAttrToF16<bool>)
        .Add(AttrDataType::kBool, AttrDataType::kBfloat16, AppendConvertedAttrToBf16<bool>)
        .Add(AttrDataType::kListBool, AttrDataType::kListBfloat16, AppendConvertedListAttrToBf16<bool>)
        .Add(AttrDataType::kBool, AttrDataType::kFloat32, AppendConvertedAttr<bool, float>)
        .Add(AttrDataType::kListBool, AttrDataType::kListFloat32, AppendConvertedListAttr<bool, float>)
        .Add(AttrDataType::kBool, AttrDataType::kInt8, AppendConvertedAttr<bool, int8_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListInt8, AppendConvertedListAttr<bool, int8_t>)
        .Add(AttrDataType::kBool, AttrDataType::kInt16, AppendConvertedAttr<bool, int16_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListInt16, AppendConvertedListAttr<bool, int16_t>)
        .Add(AttrDataType::kBool, AttrDataType::kInt32, AppendConvertedAttr<bool, int32_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListInt32, AppendConvertedListAttr<bool, int32_t>)
        .Add(AttrDataType::kBool, AttrDataType::kInt64, AppendConvertedAttr<bool, int64_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListInt64, AppendConvertedListAttr<bool, int64_t>)
        .Add(AttrDataType::kBool, AttrDataType::kUint8, AppendConvertedAttr<bool, uint8_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListUint8, AppendConvertedListAttr<bool, uint8_t>)
        .Add(AttrDataType::kBool, AttrDataType::kUint16, AppendConvertedAttr<bool, uint16_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListUint16, AppendConvertedListAttr<bool, uint16_t>)
        .Add(AttrDataType::kBool, AttrDataType::kUint32, AppendConvertedAttr<bool, uint32_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListUint32, AppendConvertedListAttr<bool, uint32_t>)
        .Add(AttrDataType::kBool, AttrDataType::kUint64, AppendConvertedAttr<bool, uint64_t>)
        .Add(AttrDataType::kListBool, AttrDataType::kListUint64, AppendConvertedListAttr<bool, uint64_t>)
        // convert float attr to other types
        .Add(AttrDataType::kFloat32, AttrDataType::kBool, AppendConvertedAttr<float, bool>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListBool, AppendConvertedListAttr<float, bool>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListBool, AppendConvertedListListAttr<float, bool>)
        .Add(AttrDataType::kFloat32, AttrDataType::kFloat16, AppendConvertedF32AttrToF16)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListFloat16, AppendConvertedListF32AttrToF16)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListFloat16, AppendConvertedListListF32AttrToF16)
        .Add(AttrDataType::kFloat32, AttrDataType::kBfloat16, AppendConvertedF32AttrToBf16)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListBfloat16, AppendConvertedListF32AttrToBf16)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListBfloat16, AppendConvertedListListF32AttrToBf16)
        .Add(AttrDataType::kFloat32, AttrDataType::kFloat32, AppendAttr<float>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListFloat32, AppendListAttr<float>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListFloat32, AppendListListAttr<float>)
        .Add(AttrDataType::kFloat32, AttrDataType::kInt8, AppendConvertedAttr<float, int8_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListInt8, AppendConvertedListAttr<float, int8_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListInt8, AppendConvertedListListAttr<float, int8_t>)
        .Add(AttrDataType::kFloat32, AttrDataType::kInt16, AppendConvertedAttr<float, int16_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListInt16, AppendConvertedListAttr<float, int16_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListInt16, AppendConvertedListListAttr<float, int16_t>)
        .Add(AttrDataType::kFloat32, AttrDataType::kInt32, AppendConvertedAttr<float, int32_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListInt32, AppendConvertedListAttr<float, int32_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListInt32, AppendConvertedListListAttr<float, int32_t>)
        .Add(AttrDataType::kFloat32, AttrDataType::kInt64, AppendConvertedAttr<float, int64_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListInt64, AppendConvertedListAttr<float, int64_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListInt64, AppendConvertedListListAttr<float, int64_t>)
        .Add(AttrDataType::kFloat32, AttrDataType::kUint8, AppendConvertedAttr<float, uint8_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListUint8, AppendConvertedListAttr<float, uint8_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListUint8, AppendConvertedListListAttr<float, uint8_t>)
        .Add(AttrDataType::kFloat32, AttrDataType::kUint16, AppendConvertedAttr<float, uint16_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListUint16, AppendConvertedListAttr<float, uint16_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListUint16, AppendConvertedListListAttr<float, uint16_t>)
        .Add(AttrDataType::kFloat32, AttrDataType::kUint32, AppendConvertedAttr<float, uint32_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListUint32, AppendConvertedListAttr<float, uint32_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListUint32, AppendConvertedListListAttr<float, uint32_t>)
        .Add(AttrDataType::kFloat32, AttrDataType::kUint64, AppendConvertedAttr<float, uint64_t>)
        .Add(AttrDataType::kListFloat32, AttrDataType::kListUint64, AppendConvertedListAttr<float, uint64_t>)
        .Add(AttrDataType::kListListFloat32, AttrDataType::kListListUint64, AppendConvertedListListAttr<float, uint64_t>)
        // convert int32 attr to other types
        .Add(AttrDataType::kInt32, AttrDataType::kBool, AppendConvertedAttr<int32_t, bool>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListBool, AppendConvertedListAttr<int32_t, bool>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListBool, AppendConvertedListListAttr<int32_t, bool>)
        .Add(AttrDataType::kInt32, AttrDataType::kFloat16, AppendConvertedAttrToF16<int32_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListFloat16, AppendConvertedListAttrToF16<int32_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListFloat16, AppendConvertedListListAttrToF16<int32_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kBfloat16, AppendConvertedAttrToBf16<int32_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListBfloat16, AppendConvertedListAttrToBf16<int32_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListBfloat16, AppendConvertedListListAttrToBf16<int32_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kFloat32, AppendConvertedAttr<int32_t, float>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListFloat32, AppendConvertedListAttr<int32_t, float>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListFloat32, AppendConvertedListListAttr<int32_t, float>)
        .Add(AttrDataType::kInt32, AttrDataType::kInt8, AppendConvertedAttr<int32_t, int8_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListInt8, AppendConvertedListAttr<int32_t, int8_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListInt8, AppendConvertedListListAttr<int32_t, int8_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kInt16, AppendConvertedAttr<int32_t, int16_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListInt16, AppendConvertedListAttr<int32_t, int16_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListInt16, AppendConvertedListListAttr<int32_t, int16_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kInt32, AppendAttr<int32_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListInt32, AppendListAttr<int32_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListInt32, AppendListListAttr<int32_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kInt64, AppendConvertedAttr<int32_t, int64_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListInt64, AppendConvertedListAttr<int32_t, int64_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListInt64, AppendConvertedListListAttr<int32_t, int64_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kUint8, AppendConvertedAttr<int32_t, uint8_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListUint8, AppendConvertedListAttr<int32_t, uint8_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListUint8, AppendConvertedListListAttr<int32_t, uint8_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kUint16, AppendConvertedAttr<int32_t, uint16_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListUint16, AppendConvertedListAttr<int32_t, uint16_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListUint16, AppendConvertedListListAttr<int32_t, uint16_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kUint32, AppendConvertedAttr<int32_t, uint32_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListUint32, AppendConvertedListAttr<int32_t, uint32_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListUint32, AppendConvertedListListAttr<int32_t, uint32_t>)
        .Add(AttrDataType::kInt32, AttrDataType::kUint64, AppendConvertedAttr<int32_t, uint64_t>)
        .Add(AttrDataType::kListInt32, AttrDataType::kListUint64, AppendConvertedListAttr<int32_t, uint64_t>)
        .Add(AttrDataType::kListListInt32, AttrDataType::kListListUint64, AppendConvertedListListAttr<int32_t, uint64_t>)
        // convert int64 attr to other types
        .Add(AttrDataType::kInt64, AttrDataType::kBool, AppendConvertedAttr<int64_t, bool>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListBool, AppendConvertedListAttr<int64_t, bool>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListBool, AppendConvertedListListAttr<int64_t, bool>)
        .Add(AttrDataType::kInt64, AttrDataType::kFloat16, AppendConvertedAttrToF16<int64_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListFloat16, AppendConvertedListAttrToF16<int64_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListFloat16, AppendConvertedListListAttrToF16<int64_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kBfloat16, AppendConvertedAttrToBf16<int64_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListBfloat16, AppendConvertedListAttrToBf16<int64_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListBfloat16, AppendConvertedListListAttrToBf16<int64_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kFloat32, AppendConvertedAttr<int64_t, float>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListFloat32, AppendConvertedListAttr<int64_t, float>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListFloat32, AppendConvertedListListAttr<int64_t, float>)
        .Add(AttrDataType::kInt64, AttrDataType::kInt8, AppendConvertedAttr<int64_t, int8_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListInt8, AppendConvertedListAttr<int64_t, int8_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListInt8, AppendConvertedListListAttr<int64_t, int8_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kInt16, AppendConvertedAttr<int64_t, int16_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListInt16, AppendConvertedListAttr<int64_t, int16_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListInt16, AppendConvertedListListAttr<int64_t, int16_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kInt32, AppendConvertedAttr<int64_t, int32_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListInt32, AppendConvertedListAttr<int64_t, int32_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListInt32, AppendConvertedListListAttr<int64_t, int32_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kInt64, AppendAttr<int64_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListInt64, AppendListAttr<int64_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListInt64, AppendListListAttr<int64_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kUint8, AppendConvertedAttr<int64_t, uint8_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListUint8, AppendConvertedListAttr<int64_t, uint8_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListUint8, AppendConvertedListListAttr<int64_t, uint8_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kUint16, AppendConvertedAttr<int64_t, uint16_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListUint16, AppendConvertedListAttr<int64_t, uint16_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListUint16, AppendConvertedListListAttr<int64_t, uint16_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kUint32, AppendConvertedAttr<int64_t, uint32_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListUint32, AppendConvertedListAttr<int64_t, uint32_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListUint32, AppendConvertedListListAttr<int64_t, uint32_t>)
        .Add(AttrDataType::kInt64, AttrDataType::kUint64, AppendConvertedAttr<int64_t, uint64_t>)
        .Add(AttrDataType::kListInt64, AttrDataType::kListUint64, AppendConvertedListAttr<int64_t, uint64_t>)
        .Add(AttrDataType::kListListInt64, AttrDataType::kListListUint64, AppendConvertedListListAttr<int64_t, uint64_t>);
}  // namespace

// src type and dst type are enum data
ge::graphStatus TilingData::AppendConvertedAttrVal(const RuntimeAttrs *attrs, const size_t attr_index,
                                                   const AttrDataType src_type, const AttrDataType dst_type) {
  GE_CHECK_NOTNULL(attrs);
  if (attr_index >= attrs->GetAttrNum()) {
    GELOGE(ge::GRAPH_FAILED, "Attr index is invalid, out of range %zu.", attrs->GetAttrNum());
    return ge::GRAPH_FAILED;
  }
  auto func = kAttrTable.Find(src_type, dst_type);
  if (func == nullptr) {
    GELOGE(ge::GRAPH_FAILED, "Get attr index[%zu] and transform from [%d] to [%d] is not supported.", attr_index,
           static_cast<int32_t>(src_type), static_cast<int32_t>(dst_type));
    return ge::GRAPH_FAILED;
  }
  GELOGD("Get attr index[%zu] success and begin to transform from [%d] to [%d].", attr_index,
         static_cast<int32_t>(src_type), static_cast<int32_t>(dst_type));
  return func(this, attrs, attr_index);
}
}  // namespace gert
