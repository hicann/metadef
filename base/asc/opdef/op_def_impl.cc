/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <vector>
#include "base/asc/opdef/op_def_impl.h"
#include "common/ge_common/debug/ge_log.h"
#include "register/op_def.h"
#include "register/op_config_registry.h"

namespace ops {
OpDef &OpDefImpl::Comment(OpDef *parent_this, CommentSection section, const char *comment) {
  if (section >= CommentSection::SECTION_MAX) {
    GELOGE(ge::PARAM_INVALID, "Ops %s : Comment Section is Invalid", parent_this->GetOpType().GetString());
    return *parent_this;
  }
  if (comment == nullptr || strlen(comment) == 0) {
    GELOGE(ge::PARAM_INVALID, "Ops %s : Comment content cannot be empty", parent_this->GetOpType().GetString());
    return *parent_this;
  }
  if (section == CommentSection::CATEGORY) {
    if (strchr(comment, ' ') != nullptr) {
      GELOGE(ge::PARAM_INVALID, "Ops %s : category names cannot be split by spaces", parent_this->GetOpType().GetString());
      return *parent_this;
    }
    parent_this->impl_->category = comment;
    return *parent_this;
  }
  parent_this->impl_->comment_map[section].emplace_back(comment);
  return *parent_this;
}

OpAttrDef &OpDefImpl::GetOrCreateAttr(OpDef *parent_this, const char *name) {
  OpAttrDef *pAttr;
  if (parent_this->FindAttr(name, &pAttr) == ItemFindStatus::ITEM_FIND) {
    return *pAttr;
  } else {
    OpAttrDef attr(name);
    return parent_this->AddAttr(attr);
  }
}

void OpDefImpl::MergeParam(std::vector<OpParamDef> &merge, std::vector<OpParamDef> &aicore_params) const {
  for (auto &aicoreParam : aicore_params) {
    bool find = false;
    for (auto &mergeParam : merge) {
      if (mergeParam == aicoreParam) {
        mergeParam.MergeParam(aicoreParam);
        find = true;
        break;
      }
    }
    if (!find) {
      merge.emplace_back(aicoreParam);
    }
  }
  return;
}

void OpDefImpl::DfsDataType(OpDef::DfsParam &dfs_param, const std::vector<OpParamDef> &all_param,
                        uint32_t list_idx, uint32_t non_list_idx) const {
  constexpr uint32_t two = 2;
  const OpParamDef &def = all_param[list_idx / two];
  if (def.IsScalarOrScalarList() && (def.IsScalarTypeSet() || def.IsScalarNameSet())) {
    dfs_param.types.push_back(OpDef::ArrParam(static_cast<uint32_t>(def.GetScalarType()), false));
    DfsFullPermutation(dfs_param, all_param, list_idx + 1, non_list_idx);
    dfs_param.types.pop_back();
  } else if (def.IsDtypeList()) {
    for (uint32_t i = 0; i < def.impl_->types_list.size(); ++i) {
      dfs_param.types.push_back(OpDef::ArrParam(i, true));
      DfsFullPermutation(dfs_param, all_param, list_idx + 1, non_list_idx);
      dfs_param.types.pop_back();
    }
  } else {
    dfs_param.types.push_back(OpDef::ArrParam(non_list_idx, true));
    DfsFullPermutation(dfs_param, all_param, list_idx + 1, non_list_idx);
    dfs_param.types.pop_back();
  }
  return;
}

void OpDefImpl::DfsFormat(OpDef::DfsParam &dfs_param, const std::vector<OpParamDef> &all_param,
                      uint32_t list_idx, uint32_t non_list_idx) const {
  constexpr uint32_t two = 2;
  const OpParamDef &def = all_param[list_idx / two];
  if ((def.IsScalarOrScalarList() || def.IsValueDepend())) {
    dfs_param.formats.push_back(OpDef::ArrParam(static_cast<uint32_t>(ge::FORMAT_ND), false));
    DfsFullPermutation(dfs_param, all_param, list_idx + 1, non_list_idx);
    dfs_param.formats.pop_back();
  } else if (def.IsFormatList()) {
    for (uint32_t i = 0; i < def.impl_->formats_list.size(); ++i) {
      dfs_param.formats.push_back(OpDef::ArrParam(i, true));
      DfsFullPermutation(dfs_param, all_param, list_idx + 1, non_list_idx);
      dfs_param.formats.pop_back();
    }
  } else {
    dfs_param.formats.push_back(OpDef::ArrParam(non_list_idx, true));
    DfsFullPermutation(dfs_param, all_param, list_idx + 1, non_list_idx);
    dfs_param.formats.pop_back();
  }
  return;
}

void OpDefImpl::DfsFullPermutation(OpDef::DfsParam &dfs_param, const std::vector<OpParamDef> &all_param,
                               uint32_t list_idx, uint32_t non_list_idx) const {
  constexpr uint32_t two = 2;
  if (list_idx == all_param.size() * two) {
    dfs_param.full_types.push_back(dfs_param.types);
    dfs_param.full_formats.push_back(dfs_param.formats);
    return;
  }
  // process types while list_idx is even; process formats while list_idx is odd
  if (list_idx % two == 0) {
    DfsDataType(dfs_param, all_param, list_idx, non_list_idx);
  } else {
    DfsFormat(dfs_param, all_param, list_idx, non_list_idx);
  }
  return;
}

ItemFindStatus OpDefImpl::FindAttr(OpDef *parent_this, const char *name, OpAttrDef **attr) {
  std::vector<OpAttrDef> *attrList = &parent_this->impl_->attrs;
  for (auto it = attrList->begin(); it != attrList->end(); it++) {
    if (ge::AscendString(it->GetName()) == ge::AscendString(name)) {
      *attr = &(*it);
      return ItemFindStatus::ITEM_FIND;
    }
  }
  return ItemFindStatus::ITEM_NOEXIST;
}

bool OpDefImpl::IsNonListTypes(const OpParamDef &def) const {
  return (!def.IsScalarOrScalarList() && def.IsDtype()) ||
    (def.IsScalarOrScalarList() && (!def.IsScalarTypeSet() && !def.IsScalarNameSet()) && def.IsDtype());
}

uint32_t OpDefImpl::GetNonListLen(const OpDef *parent_this, std::vector<OpParamDef> &input_param, std::vector<OpParamDef> &output_param) const {
  std::unordered_set<uint32_t> non_list_lens;
  auto set_non_list_len = [parent_this, &non_list_lens](const std::vector<OpParamDef> &params) {
    for (auto &def : params) {
      if (parent_this->IsNonListTypes(def)) {
        non_list_lens.insert(def.impl_->types.size());
      }
      if (parent_this->IsNonListFormats(def)) {
        non_list_lens.insert(def.impl_->formats.size());
      }
    }
  };
  set_non_list_len(input_param);
  set_non_list_len(output_param);

  if (non_list_lens.empty()) {
    return 1;
  }
  if (non_list_lens.size() > 1) {
    GELOGE(ge::PARAM_INVALID, "Element num of DataType and Format is not aligned.");
    return 0;
  }
  if (*non_list_lens.begin() == 0) {
    GELOGE(ge::PARAM_INVALID, "DataType or Format cannot be empty.");
    return 0;
  }
  return *non_list_lens.begin();
}

OpAttrDef &OpDefImpl::AddAttr(OpDef *parent_this, OpAttrDef &attr) {
  parent_this->impl_->attrs.emplace_back(attr);
  return parent_this->impl_->attrs.back();
}

OpDef &OpDefImpl::SetInferShape(OpDef *parent_this, gert::OpImplRegisterV2::InferShapeKernelFunc func) {
  parent_this->impl_->infer_shape = func;
  return *parent_this;
}

OpDef &OpDefImpl::SetInferShapeRange(OpDef *parent_this, gert::OpImplRegisterV2::InferShapeRangeKernelFunc func) {
  parent_this->impl_->infer_shape_range = func;
  return *parent_this;
}

OpDef &OpDefImpl::SetInferDataType(OpDef *parent_this, gert::OpImplRegisterV2::InferDataTypeKernelFunc func) {
  parent_this->impl_->infer_data_type = func;
  return *parent_this;
}

bool OpDefImpl::IsNonListFormats(const OpParamDef &def) const {
  return (!def.IsScalarOrScalarList() && !def.IsValueDepend() && def.IsFormat());
}

void OpDefImpl::UpdateDtypeImpl(const OpDef::DfsParam &dfs_param, OpParamDef &param, const uint32_t &param_idx) {
  uint32_t param_type = dfs_param.full_types[0][param_idx].first;
  bool have_scalar_param = !(dfs_param.full_types[0][param_idx].second);
  if (have_scalar_param && static_cast<ge::DataType>(param_type) != ge::DT_UNDEFINED) {
    if (param.IsSetDtypeForBin()) {
      GELOGW("DataTypeForBinQuery is incompatible with To Type.");
      param.impl_->set_type_for_bin = false;
    }
    param.impl_->types = std::vector<ge::DataType>(dfs_param.full_types.size(), static_cast<ge::DataType>(param_type));
    return;
  }
  if (have_scalar_param && static_cast<ge::DataType>(param_type) == ge::DT_UNDEFINED) {
    return;
  }
  uint32_t num = 0;
  bool is_idx = false;
  std::vector<ge::DataType> data_types;
  std::vector<ge::DataType> data_types_for_bin;
  bool is_follow_list =
      (param.impl_->follow_type == FollowType::ALL || param.impl_->follow_type == FollowType::DTYPE) &&
      param.IsDtypeList();
  for (uint32_t type_idx = 0; type_idx < dfs_param.full_types.size(); ++type_idx) {
    std::tie(num, is_idx) = dfs_param.full_types[type_idx][param_idx];
    if (param.IsSetDtypeForBin() && is_idx && !is_follow_list) {
      data_types_for_bin.emplace_back(param.impl_->types_for_bin[num]);
    }
    if (param.IsDtype()) {
      data_types.emplace_back(param.impl_->types[num]);
    }
    if (param.IsDtypeList()) {
      data_types.emplace_back(param.impl_->types_list[num]);
    }
  }
  if (!data_types_for_bin.empty()) {
    param.impl_->types_for_bin = data_types_for_bin;
  }
  param.impl_->types = data_types;
  return;
}

void OpDefImpl::UpdateFormatImpl(const OpDef::DfsParam &dfs_param, OpParamDef &param, const uint32_t &param_idx) {
  uint32_t param_format = dfs_param.full_formats[0][param_idx].first;
  bool have_scalar_param = !(dfs_param.full_formats[0][param_idx].second);
  if (have_scalar_param) {
    if (param.IsSetFormatForBin()) {
      GELOGW("FormatForBinQuery is incompatible with Scalar/ScalarList or ValueDepend.");
      param.impl_->set_format_for_bin = false;
    }
    param.impl_->formats =
        std::vector<ge::Format>(dfs_param.full_formats.size(), static_cast<ge::Format>(param_format));
    return;
  }
  uint32_t num = 0;
  bool is_idx = false;
  std::vector<ge::Format> data_formats;
  std::vector<ge::Format> data_formats_for_bin;
  bool is_follow_list =
      (param.impl_->follow_type == FollowType::ALL || param.impl_->follow_type == FollowType::FORMAT) &&
      param.IsFormatList();
  for (uint32_t type_idx = 0; type_idx < dfs_param.full_formats.size(); ++type_idx) {
    std::tie(num, is_idx) = dfs_param.full_formats[type_idx][param_idx];
    if (param.IsSetFormatForBin() && is_idx && !is_follow_list) {
      data_formats_for_bin.emplace_back(param.impl_->formats_for_bin[num]);
    }
    if (param.IsFormat()) {
      data_formats.emplace_back(param.impl_->formats[num]);
    }
    if (param.IsFormatList()) {
      data_formats.emplace_back(param.impl_->formats_list[num]);
    }
  }
  if (!data_formats_for_bin.empty()) {
    param.impl_->formats_for_bin = data_formats_for_bin;
  }
  param.impl_->formats = data_formats;
  return;
}

void OpDefImpl::UpdateInput(OpDef *parent_this, const OpDef::DfsParam &dfs_param, std::vector<OpParamDef> &input) {
  std::vector<std::pair<uint32_t, ge::AscendString>> to_list;
  for (uint32_t param_idx = 0; param_idx < input.size(); ++param_idx) {
    if (input[param_idx].IsScalarNameSet()) {
      to_list.emplace_back(param_idx, input[param_idx].GetScalarName());
    }
    parent_this->UpdateDtypeImpl(dfs_param, input[param_idx], param_idx);
    parent_this->UpdateFormatImpl(dfs_param, input[param_idx], param_idx);
  }
  auto follow_map = parent_this->GetFollowMap();
  uint32_t input_idx = 0;
  ge::AscendString to_name = "";
  for (const auto &to : to_list) {
    std::tie(input_idx, to_name) = to;
    if (follow_map.find(to_name) == follow_map.end()) {
      GELOGE(ge::PARAM_INVALID, "Param %s : Cannot find param to be set To.",
             input[input_idx].GetParamName().GetString());
      continue;
    }
    const OpDef::PortFollowInfo &to_param = follow_map.at(to_name);
    if (to_param.port_stat == OpDef::PortStat::OUT) {
      GELOGE(ge::PARAM_INVALID, "Param %s : Cannot set To to output param.",
             input[input_idx].GetParamName().GetString());
      continue;
    }
    if (input[to_param.index_in].IsScalarNameSet()) {
      GELOGE(ge::PARAM_INVALID, "Param %s : Chained parameter setting is not supported in To with name.",
             input[input_idx].GetParamName().GetString());
      continue;
    }
    input[input_idx].impl_->types =  input[to_param.index_in].impl_->types;
    if (input[input_idx].IsSetDtypeForBin()) {
      std::vector<ge::DataType> data_types_for_bin;
      for (uint32_t type_idx = 0; type_idx < dfs_param.full_types.size(); ++type_idx) {
        uint32_t idx = dfs_param.full_types[type_idx][to_param.index_in].first;
        data_types_for_bin.emplace_back(input[input_idx].impl_->types_for_bin[idx]);
      }
      input[input_idx].impl_->types_for_bin = data_types_for_bin;
    }
  }
  return;
}

void OpDefImpl::UpdateOutput(OpDef *parent_this, const OpDef::DfsParam &dfs_param, std::vector<OpParamDef> &output) {
  for (uint32_t param_idx = 0; param_idx < output.size(); ++param_idx) {
    if (output[param_idx].IsScalarOrScalarList()) {
      GELOGE(ge::PARAM_INVALID, "Output %s : output cannot be set to Scalar or ScalarList.",
             output[param_idx].GetParamName().GetString());
      continue;
    }
    uint32_t dfs_full_idx = dfs_param.full_types[0].size() - output.size() + param_idx;
    parent_this->UpdateDtypeImpl(dfs_param, output[param_idx], dfs_full_idx);
    parent_this->UpdateFormatImpl(dfs_param, output[param_idx], dfs_full_idx);
  }
  return;
}

void OpDefImpl::SetPermutedParam(OpDef *parent_this, const OpDef::DfsParam &dfs_param,
                             std::vector<OpParamDef> &input,
                             std::vector<OpParamDef> &output) {
  parent_this->UpdateInput(dfs_param, input);
  parent_this->UpdateOutput(dfs_param, output);
  parent_this->FollowListImpl(dfs_param, input, output);
  return;
}

void OpDefImpl::CheckIncompatible(const std::vector<OpParamDef>& all) const {
  bool is_unknown_shape_format = false;
  for (auto &def : all) {
    if (!def.impl_->unknown_shape_formats.empty()) {
      is_unknown_shape_format = true;
      break;
    }
  }
  if (is_unknown_shape_format) {
    for (auto &def : all) {
      if (def.impl_->formats_list.size() > 1 || def.impl_->types_list.size() > 1) {
        GELOGW("UnknownShapeFormat is incompatible with FormatList/DataTypeList.");
        return;
      }
    }
  }
  return;
}

void OpDefImpl::FullPermutation(OpDef *parent_this, std::vector<OpParamDef> &input_param,
                            std::vector<OpParamDef> &output_param) {
  parent_this->impl_->non_list_len = parent_this->GetNonListLen(input_param, output_param);
  std::vector<OpParamDef> all_param = input_param;
  all_param.insert(all_param.end(), output_param.begin(), output_param.end());
  CheckIncompatible(all_param);
  struct OpDef::DfsParam dfs_param;
  for (uint32_t i = 0; i < parent_this->impl_->non_list_len; ++i) {
    DfsFullPermutation(dfs_param, all_param, 0, i);
  }
  if (dfs_param.full_types.empty() || dfs_param.full_formats.empty()) {
    for (auto &def : input_param) {
      def.impl_->types.clear();
      def.impl_->formats.clear();
    }
    for (auto &def : output_param) {
      def.impl_->types.clear();
      def.impl_->formats.clear();
    }
    return;
  }
  parent_this->SetPermutedParam(dfs_param, input_param, output_param);
  return;
}

void OpDefImpl::SetDefaultND(std::vector<OpParamDef> &defs) const {
  for (auto &def : defs) {
    if (def.impl_->formats.empty() && def.impl_->formats_list.empty()) {
      def.impl_->formats_status = LIST;
      def.impl_->formats_list = {ge::FORMAT_ND};
    }
  }
  return;
}

std::vector<std::vector<OpParamDef>> OpDefImpl::GetMergeInputsOutputs(OpDef *parent_this, const OpAICoreConfig &aicore_config) {
  parent_this->FollowImpl();
  std::vector<OpParamDef> inputs = parent_this->GetInputs();
  std::vector<OpParamDef> outputs = parent_this->GetOutputs();
  MergeParam(inputs, aicore_config.GetInputs());
  MergeParam(outputs, aicore_config.GetOutputs());
  SetDefaultND(inputs);
  SetDefaultND(outputs);
  parent_this->FullPermutation(inputs, outputs);
  std::vector<std::vector<OpParamDef>> inputs_outputs;
  inputs_outputs.push_back(inputs);
  inputs_outputs.push_back(outputs);
  return inputs_outputs;
}

std::vector<OpParamDef> OpDefImpl::GetMergeInputs(OpDef *parent_this, OpAICoreConfig &aicore_config) {
  std::vector<std::vector<OpParamDef>> inputs_outputs = parent_this->GetMergeInputsOutputs(aicore_config);
  return inputs_outputs[0];
}

std::vector<OpParamDef> OpDefImpl::GetMergeOutputs(OpDef *parent_this, OpAICoreConfig &aicore_config) {
  std::vector<std::vector<OpParamDef>> inputs_outputs = parent_this->GetMergeInputsOutputs(aicore_config);
  return inputs_outputs[1];
}

void OpDefImpl::Construct(OpDef *parent_this, const char *type) {
  parent_this->impl_->op_type = type;
  auto regConfigs = GetOpAllAICoreConfig(type);
  GELOGD("Aicore op[%s] configs size: %zu", type, regConfigs.size());
  for (auto it = regConfigs.cbegin(); it!= regConfigs.cend(); ++it) {
    GELOGD("Found aicore op[%s] at socVersion[%s] registerd by REGISTER_OP_AICORE_CONFIG.",
      type, it->first.GetString());
    if (it->second == nullptr) {
      GELOGE(ge::PARAM_INVALID, "Aicore func of op[%s] at socVersion[%s] registerd by REGISTER_OP_AICORE_CONFIG is nullptr.");
      return;
    }
    auto config = it->second();
    parent_this->impl_->op_aicore.AddConfig(it->first.GetString(), config);
  }
}

void OpDefImpl::Construct(OpDef *parent_this, const OpDef &op_def) {
  parent_this->impl_->op_type = op_def.impl_->op_type;
  parent_this->impl_->op_params = op_def.impl_->op_params;
  parent_this->impl_->attrs = op_def.impl_->attrs;
  parent_this->impl_->op_aicore = op_def.impl_->op_aicore;
  parent_this->impl_->op_aicpu = op_def.impl_->op_aicpu;
  parent_this->impl_->op_hostcpu = op_def.impl_->op_hostcpu;
  parent_this->impl_->has_workspace = op_def.impl_->has_workspace;
  parent_this->impl_->infer_shape = op_def.impl_->infer_shape;
  parent_this->impl_->infer_shape_range = op_def.impl_->infer_shape_range;
  parent_this->impl_->infer_data_type = op_def.impl_->infer_data_type;
  parent_this->impl_->op_mc2 = op_def.impl_->op_mc2;
  parent_this->impl_->non_list_len = op_def.impl_->non_list_len;
  parent_this->impl_->category = op_def.impl_->category;
  parent_this->impl_->comment_map = op_def.impl_->comment_map;
  parent_this->impl_->format_mode = op_def.impl_->format_mode;
  parent_this->impl_->enable_fall_back = op_def.impl_->enable_fall_back;
}

OpDef &OpDefImpl::Eq(OpDef *parent_this, const OpDef &op_def) {
  if (parent_this != &op_def) {
    *parent_this->impl_ = *op_def.impl_;
  }
  return *parent_this;
}

OpDef &OpDefImpl::FormatMatchMode(OpDef *parent_this, FormatCheckOption option) {
  parent_this->impl_->format_mode = option;
  return *parent_this;
}

OpDef &OpDefImpl::EnableFallBack(OpDef *parent_this) {
  parent_this->impl_->enable_fall_back = true;
  return *parent_this;
}

void OpAttrDefImpl::Construct(OpAttrDef *parent_this, const char *name) {
  parent_this->impl_->name = name;
}

void OpAttrDefImpl::Construct(OpAttrDef *parent_this, const OpAttrDef &attr_def) {
  parent_this->impl_->name = attr_def.impl_->name;
  parent_this->impl_->data_type = attr_def.impl_->data_type;
  parent_this->impl_->required = attr_def.impl_->required;
  parent_this->impl_->bool_value = attr_def.impl_->bool_value;
  parent_this->impl_->float_value = attr_def.impl_->float_value;
  parent_this->impl_->int_value = attr_def.impl_->int_value;
  parent_this->impl_->str_value = attr_def.impl_->str_value;
  parent_this->impl_->list_bool = attr_def.impl_->list_bool;
  parent_this->impl_->list_float = attr_def.impl_->list_float;
  parent_this->impl_->list_int = attr_def.impl_->list_int;
  parent_this->impl_->list_list_int = attr_def.impl_->list_list_int;
  parent_this->impl_->version = attr_def.impl_->version;
  parent_this->impl_->comment = attr_def.impl_->comment;
}

OpAttrDef &OpAttrDefImpl::Eq(OpAttrDef *parent_this, const OpAttrDef &attr_def) {
  if (parent_this != &attr_def) {
    *parent_this->impl_ = *attr_def.impl_;
  }
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::Bool(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_BOOL;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::Bool(OpAttrDef *parent_this, bool value) {
  parent_this->impl_->bool_value = value;
  return parent_this->Bool();
}

OpAttrDef &OpAttrDefImpl::Float(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_FLOAT;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::Float(OpAttrDef *parent_this, float value) {
  parent_this->impl_->float_value = value;
  return parent_this->Float();
}

OpAttrDef &OpAttrDefImpl::Int(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_INT;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::Int(OpAttrDef *parent_this, int64_t value) {
  parent_this->impl_->int_value = value;
  return parent_this->Int();
}

OpAttrDef &OpAttrDefImpl::String(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_STR;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::String(OpAttrDef *parent_this, const char *value) {
  parent_this->impl_->str_value = value;
  return parent_this->String();
}

OpAttrDef &OpAttrDefImpl::ListBool(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_LIST_BOOL;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::ListBool(OpAttrDef *parent_this, std::vector<bool> value) {
  parent_this->impl_->list_bool = value;
  return parent_this->ListBool();
}

OpAttrDef &OpAttrDefImpl::ListFloat(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_LIST_FLOAT;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::ListFloat(OpAttrDef *parent_this, std::vector<float> value) {
  parent_this->impl_->list_float = value;
  return parent_this->ListFloat();
}

OpAttrDef &OpAttrDefImpl::ListInt(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_LIST_INT;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::ListInt(OpAttrDef *parent_this, std::vector<int64_t> value) {
  parent_this->impl_->list_int = value;
  return parent_this->ListInt();
}

OpAttrDef &OpAttrDefImpl::ListListInt(OpAttrDef *parent_this) {
  parent_this->impl_->data_type = AttrDataType::ATTR_DT_LIST_LIST_INT;
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::ListListInt(OpAttrDef *parent_this, std::vector<std::vector<int64_t>> value) {
  parent_this->impl_->list_list_int = value;
  return parent_this->ListListInt();
}

OpAttrDef &OpAttrDefImpl::Version(OpAttrDef *parent_this, uint32_t version) {
  parent_this->impl_->version = version;
  return *parent_this;
}

bool OpAttrDefImpl::DoubleEq(const OpAttrDef *parent_this, const OpAttrDef &attr_def) const{
  if (parent_this->impl_->name == attr_def.impl_->name) {
    return true;
  }
  return false;
}

OpAttrDef &OpAttrDefImpl::AttrType(OpAttrDef *parent_this, Option attr_type) {
  if (attr_type == Option::OPTIONAL) {
    parent_this->impl_->required = false;
  }
  return *parent_this;
}

OpAttrDef &OpAttrDefImpl::Comment(OpAttrDef *parent_this, const char *comment) {
  if (comment == nullptr || strlen(comment) == 0) {
    GELOGE(ge::PARAM_INVALID, "Attr %s : Comment content cannot be empty", parent_this->GetName().GetString());
    return *parent_this;
  }
  parent_this->impl_->comment = comment;
  return *parent_this;
}

ge::AscendString &OpAttrDefImpl::GetCfgDataType(const OpAttrDef *parent_this) const {
  static ge::AscendString dtype_names[] = {"bool",     "float",     "int",     "str",
                                           "listBool", "listFloat", "listInt", "listListInt"};
  return dtype_names[static_cast<size_t>(parent_this->impl_->data_type)];
}

ge::AscendString &OpAttrDefImpl::GetProtoDataType(const OpAttrDef *parent_this) const {
  static ge::AscendString dtype_names[] = {"Bool",     "Float",     "Int",     "String",
                                           "ListBool", "ListFloat", "ListInt", "ListListInt"};
  return dtype_names[static_cast<size_t>(parent_this->impl_->data_type)];
}

template<class T>
std::string GetListStr(std::vector<T> list, const char *brac, void (*pfSout)(std::stringstream &s, T v)) {
  std::string str = "";
  std::stringstream sstream;
  if (brac == nullptr || brac[0] == '\0' || brac[1] == '\0') {
    return str.c_str();
  }
  sstream << brac[0];
  for (auto v : list) {
    pfSout(sstream, v);
  }
  str += sstream.str();
  if (list.size() > 0) {
    str.resize(str.size() - 1);
  }
  str += brac[1];
  return str;
}

ge::AscendString &OpAttrDefImpl::GetAttrDefaultVal(OpAttrDef *parent_this, const char *brac) {
  std::stringstream sstream;
  std::vector<std::string> strList;

  if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_BOOL) {
    sstream << (parent_this->impl_->bool_value ? "true" : "false");
    parent_this->impl_->value = sstream.str().c_str();
  } else if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_FLOAT) {
    sstream << parent_this->impl_->float_value;
    parent_this->impl_->value = sstream.str().c_str();
  } else if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_INT) {
    sstream << parent_this->impl_->int_value;
    parent_this->impl_->value = sstream.str().c_str();
  } else if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_STR) {
    parent_this->impl_->value = parent_this->impl_->str_value;
  } else if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_LIST_BOOL) {
    parent_this->impl_->value = GetListStr<bool>(parent_this->impl_->list_bool, brac, [](std::stringstream &s, bool v) {
                           s << (v ? "true" : "false") << ",";
                         }).c_str();
  } else if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_LIST_FLOAT) {
    parent_this->impl_->value =
        GetListStr<float>(parent_this->impl_->list_float, brac, [](std::stringstream &s, float v) { s << v << ","; }).c_str();
  } else if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_LIST_INT) {
    parent_this->impl_->value = GetListStr<int64_t>(parent_this->impl_->list_int, brac, [](std::stringstream &s, int64_t v) {
                           s << v << ",";
                         }).c_str();
  } else if (parent_this->impl_->data_type == AttrDataType::ATTR_DT_LIST_LIST_INT) {
    for (auto listInt : parent_this->impl_->list_list_int) {
      strList.emplace_back(GetListStr<int64_t>(listInt, brac, [](std::stringstream &s, int64_t v) { s << v << ","; }));
    }
    parent_this->impl_->value =
        GetListStr<std::string>(strList, brac, [](std::stringstream &s, std::string v) { s << v << ","; }).c_str();
  } else {
    parent_this->impl_->value = "";
  }
  return parent_this->impl_->value;
}

void OpParamDefImpl::Construct(OpParamDef *parent_this, const char *name) {
  parent_this->impl_->name = name;
}

void OpParamDefImpl::Construct(OpParamDef *parent_this, const OpParamDef &def) {
  parent_this->impl_->name = def.impl_->name;
  parent_this->impl_->param_type = def.impl_->param_type;
  parent_this->impl_->types = def.impl_->types;
  parent_this->impl_->origin_types = def.impl_->origin_types;
  parent_this->impl_->formats = def.impl_->formats;
  parent_this->impl_->formats_list = def.impl_->formats_list;
  parent_this->impl_->types_list = def.impl_->types_list;
  parent_this->impl_->need_compile = def.impl_->need_compile;
  parent_this->impl_->reshape_type = def.impl_->reshape_type;
  parent_this->impl_->value_depend = def.impl_->value_depend;
  parent_this->impl_->depend_scope = def.impl_->depend_scope;
  parent_this->impl_->unknown_shape_formats = def.impl_->unknown_shape_formats;
  parent_this->impl_->ignore_contiguous = def.impl_->ignore_contiguous;
  parent_this->impl_->auto_contiguous = def.impl_->auto_contiguous;
  parent_this->impl_->is_scalar = def.impl_->is_scalar;
  parent_this->impl_->is_scalar_list = def.impl_->is_scalar_list;
  parent_this->impl_->types_status = def.impl_->types_status;
  parent_this->impl_->formats_status = def.impl_->formats_status;
  parent_this->impl_->scalar_name = def.impl_->scalar_name;
  parent_this->impl_->scalar_type = def.impl_->scalar_type;
  parent_this->impl_->version = def.impl_->version;
  parent_this->impl_->init_value_type = def.impl_->init_value_type;
  parent_this->impl_->init_value = def.impl_->init_value;
  parent_this->impl_->init_value_list = def.impl_->init_value_list;
  parent_this->impl_->is_output_shape_depend_on_compute = def.impl_->is_output_shape_depend_on_compute;
  parent_this->impl_->follow_port_name = def.impl_->follow_port_name;
  parent_this->impl_->follow_type = def.impl_->follow_type;
  parent_this->impl_->comment = def.impl_->comment;
  parent_this->impl_->types_for_bin = def.impl_->types_for_bin;
  parent_this->impl_->formats_for_bin = def.impl_->formats_for_bin;
  parent_this->impl_->set_type_for_bin = def.impl_->set_type_for_bin;
  parent_this->impl_->set_format_for_bin = def.impl_->set_format_for_bin;
}

OpParamDef &OpParamDefImpl::Eq(OpParamDef *parent_this, const OpParamDef &def) {
  if (parent_this != &def) {
    *parent_this->impl_ = *def.impl_;
  }
  return *parent_this;
}

bool OpParamDefImpl::DoubleEq(const OpParamDef *parent_this, const OpParamDef &def) const {
  if (parent_this->impl_->name == def.impl_->name) {
    return true;
  }
  return false;
}

OpParamDef &OpParamDefImpl::ParamType(OpParamDef *parent_this, Option param_type) {
  parent_this->impl_->param_type = param_type;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::UnknownShapeFormat(OpParamDef *parent_this, std::vector<ge::Format> formats) {
  parent_this->impl_->unknown_shape_formats = formats;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::IgnoreContiguous(OpParamDef *parent_this) {
  parent_this->impl_->ignore_contiguous = true;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::AutoContiguous(OpParamDef *parent_this) {
  parent_this->impl_->auto_contiguous = true;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::Scalar(OpParamDef *parent_this) {
  parent_this->impl_->is_scalar = true;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::ScalarList(OpParamDef *parent_this) {
  parent_this->impl_->is_scalar_list = true;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::Version(OpParamDef *parent_this, uint32_t version) {
  parent_this->impl_->version = version;
  return *parent_this;
}

void OpParamDefImpl::MergeParam(OpParamDef *parent_this, const OpParamDef &def) {
  parent_this->impl_->param_type = def.impl_->param_type;
  if (!def.impl_->types.empty()) {
    parent_this->impl_->types = def.impl_->types;
    parent_this->impl_->origin_types = def.impl_->origin_types;
  }
  if (!def.impl_->types_list.empty()) {
    parent_this->impl_->types_list = def.impl_->types_list;
  }
  if (!def.impl_->formats.empty()) {
    parent_this->impl_->formats = def.impl_->formats;
  }
  if (!def.impl_->formats_list.empty()) {
    parent_this->impl_->formats_list = def.impl_->formats_list;
  }
  if (def.impl_->need_compile.GetLength() > 0) {
    parent_this->impl_->need_compile = def.impl_->need_compile;
  }
  if (def.impl_->reshape_type.GetLength() > 0) {
    parent_this->impl_->reshape_type = def.impl_->reshape_type;
  }
  if (def.impl_->value_depend.GetLength() > 0) {
    parent_this->impl_->value_depend = def.impl_->value_depend;
  }
  if (!def.impl_->unknown_shape_formats.empty()) {
    parent_this->impl_->unknown_shape_formats = def.impl_->unknown_shape_formats;
  }
  if (!def.impl_->types_for_bin.empty()) {
    parent_this->impl_->types_for_bin = def.impl_->types_for_bin;
    parent_this->impl_->set_type_for_bin = def.impl_->set_type_for_bin;
  }
  if (!def.impl_->formats_for_bin.empty()) {
    parent_this->impl_->formats_for_bin = def.impl_->formats_for_bin;
    parent_this->impl_->set_format_for_bin = def.impl_->set_format_for_bin;
  }
  parent_this->impl_->init_value_type = def.impl_->init_value_type;
  parent_this->impl_->init_value = def.impl_->init_value;
  parent_this->impl_->init_value_list = def.impl_->init_value_list;
  parent_this->impl_->ignore_contiguous = def.impl_->ignore_contiguous;
  parent_this->impl_->auto_contiguous = def.impl_->auto_contiguous;
  parent_this->impl_->is_scalar = def.impl_->is_scalar;
  parent_this->impl_->is_scalar_list = def.impl_->is_scalar_list;
  parent_this->impl_->types_status = def.impl_->types_status;
  parent_this->impl_->formats_status = def.impl_->formats_status;
  parent_this->impl_->scalar_name = def.impl_->scalar_name;
  parent_this->impl_->scalar_type = def.impl_->scalar_type;
  parent_this->impl_->version = def.impl_->version;
  parent_this->impl_->is_output_shape_depend_on_compute = def.impl_->is_output_shape_depend_on_compute;
  parent_this->impl_->depend_scope = def.impl_->depend_scope;
  parent_this->impl_->follow_port_name = def.impl_->follow_port_name;
  parent_this->impl_->follow_type = def.impl_->follow_type;
  parent_this->impl_->comment = def.impl_->comment;
}


OpParamDef &OpParamDefImpl::DataType(OpParamDef *parent_this, std::vector<ge::DataType> types) {
  if (parent_this->IsDtypeList()) {
    GELOGE(ge::PARAM_INVALID, "DataTypeList and DataType can not be called at the same time!");
    return *parent_this;
  }
  if (types.empty()) {
    GELOGE(ge::PARAM_INVALID, "DataType can not be empty");
    return *parent_this;
  }
  if (parent_this->impl_->set_type_for_bin && types.size() != parent_this->impl_->types_for_bin.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : DataType size is not equal to DataTypeForBinQuery size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->types_status = NON_LIST;
  parent_this->impl_->types = types;
  parent_this->impl_->origin_types = types;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::DataTypeList(OpParamDef *parent_this, std::vector<ge::DataType> types) {
  if (parent_this->IsDtype()) {
    GELOGE(ge::PARAM_INVALID, "DataTypeList and DataType can not be called at the same time!");
    return *parent_this;
  }
  if (types.empty()) {
    GELOGE(ge::PARAM_INVALID, "DataTypeList can not be empty");
    return *parent_this;
  }
  std::unordered_set<uint32_t> dtype_set(types.begin(), types.end());
  if (dtype_set.size() < types.size()) {
    GELOGE(ge::PARAM_INVALID, "Element of DataTypeList must be unique!");
    return *parent_this;
  }
  if (parent_this->impl_->set_type_for_bin && types.size() != parent_this->impl_->types_for_bin.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : DataTypeList size is not equal to DataTypeForBinQuery size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->types_status = LIST;
  parent_this->impl_->types_list = types;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::Format(OpParamDef *parent_this, std::vector<ge::Format> formats) {
  if (parent_this->IsFormatList()) {
    GELOGE(ge::PARAM_INVALID, "FormatList and Format can not be called at the same time!");
    return *parent_this;
  }
  if (formats.empty()) {
    GELOGE(ge::PARAM_INVALID, "Format can not be empty");
    return *parent_this;
  }
  if (parent_this->impl_->set_format_for_bin && formats.size() != parent_this->impl_->formats_for_bin.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : Format size is not equal to FormatForBinQuery size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->formats_status = NON_LIST;
  parent_this->impl_->formats = formats;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::FormatList(OpParamDef *parent_this, std::vector<ge::Format> formats) {
  if (parent_this->IsFormat()) {
    GELOGE(ge::PARAM_INVALID, "FormatList and Format can not be called at the same time!");
    return *parent_this;
  }
  if (formats.empty()) {
    GELOGE(ge::PARAM_INVALID, "Format can not be empty");
    return *parent_this;
  }
  std::unordered_set<uint32_t> format_set(formats.begin(), formats.end());
  if (format_set.size() < formats.size()) {
    GELOGE(ge::PARAM_INVALID, "Element of FormatList must be unique!");
    return *parent_this;
  }
  if (parent_this->impl_->set_format_for_bin && formats.size() != parent_this->impl_->formats_for_bin.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : FormatList size is not equal to FormatForBinQuery size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->formats_status = LIST;
  parent_this->impl_->formats_list = formats;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::DataTypeForBinQuery(OpParamDef *parent_this, std::vector<ge::DataType> types) {
  if (types.empty()) {
    GELOGE(ge::PARAM_INVALID, "DataTypeForBinList can not be empty!");
    return *parent_this;
  }
  if (parent_this->impl_->types_status == NON_LIST && parent_this->impl_->types.size() != types.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : DataTypeForBinQuery size is not equal to DataType size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  if (parent_this->impl_->types_status == LIST && parent_this->impl_->types_list.size() != types.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : DataTypeForBinQuery size is not equal to DataTypeList size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->types_for_bin = types;
  parent_this->impl_->set_type_for_bin = true;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::FormatForBinQuery(OpParamDef *parent_this, std::vector<ge::Format> formats) {
  if (formats.empty()) {
    GELOGE(ge::PARAM_INVALID, "FormatForBinList can not be empty!");
    return *parent_this;
  }
  if (parent_this->impl_->formats_status == NON_LIST && parent_this->impl_->formats.size() != formats.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : FormatForBinQuery size is not equal to Format size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  if (parent_this->impl_->formats_status == LIST && parent_this->impl_->formats_list.size() != formats.size()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : FormatForBinQuery size is not equal to FormatList size",
        parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->formats_for_bin = formats;
  parent_this->impl_->set_format_for_bin = true;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::ValueDepend(OpParamDef *parent_this, Option value_depend) {
  if (value_depend == Option::REQUIRED) {
    parent_this->impl_->value_depend = "required";
  } else if (value_depend == Option::OPTIONAL) {
    parent_this->impl_->value_depend = "optional";
  } else {
    parent_this->impl_->value_depend = "";
    GELOGW("Param %s : ValueDepend Option is Invalid", parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->depend_scope = DependScope::ALL;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::ValueDepend(OpParamDef *parent_this, Option value_depend, DependScope scope) {
  if (scope >= DependScope::INVALID_SCOPE) {
    GELOGE(ge::PARAM_INVALID, "Param %s : ValueDepend DependScope is Invalid", parent_this->impl_->name.GetString());
    return *parent_this;
  }
  if (parent_this->ValueDepend(value_depend).impl_->value_depend.GetLength() > 0) {
    parent_this->impl_->depend_scope = scope;
  }
  return *parent_this;
}

OpParamDef &OpParamDefImpl::To(OpParamDef *parent_this, const ge::DataType type) {
  if (!parent_this->impl_->is_scalar && !parent_this->impl_->is_scalar_list) {
    GELOGE(ge::PARAM_INVALID, "Param %s : To must be set on the Scalar/ScalarList parameter.",
           parent_this->impl_->name.GetString());
    return *parent_this;
  }
  if (parent_this->impl_->follow_type != FollowType::INVALID_TYPE) {
    GELOGE(ge::PARAM_INVALID, "Param %s : To is incompatible with Follow", parent_this->impl_->name.GetString());
    return *parent_this;
  }

  parent_this->impl_->scalar_type = type;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::To(OpParamDef *parent_this, const char *name) {
  if (!parent_this->impl_->is_scalar && !parent_this->impl_->is_scalar_list) {
    GELOGE(ge::PARAM_INVALID, "Param %s : To must be set on the Scalar/ScalarList parameter.",
           parent_this->impl_->name.GetString());
    return *parent_this;
  }
  if (parent_this->impl_->follow_type != FollowType::INVALID_TYPE) {
    GELOGE(ge::PARAM_INVALID, "Param %s : To is incompatible with Follow", parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->scalar_name = name;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::InitValue(OpParamDef *parent_this, uint64_t value) {
  parent_this->impl_->init_value.value_u64 = value;
  parent_this->impl_->init_value_type = InitValueType::INIT_VALUE_UINT64_T;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::InitValue(OpParamDef *parent_this, const ScalarVar &value) {
  if (!parent_this->impl_->init_value_list.empty()) {
    GELOGW("InitValue has been set, %s InitValue will be reset, please check whether it is correct.",
        parent_this->impl_->name.GetString());
    parent_this->impl_->init_value_list.clear();
  }
  parent_this->impl_->init_value_list.emplace_back(value);
  return *parent_this;
}

OpParamDef &OpParamDefImpl::InitValue(OpParamDef *parent_this, const std::vector<ScalarVar> &value) {
  if (!parent_this->impl_->init_value_list.empty()) {
    GELOGW("InitValue has been set, %s InitValue will be reset, please check whether it is correct.",
        parent_this->impl_->name.GetString());
    parent_this->impl_->init_value_list.clear();
  }
  parent_this->impl_->init_value_list.assign(value.begin(), value.end());
  return *parent_this;
}

OpParamDef &OpParamDefImpl::OutputShapeDependOnCompute(OpParamDef *parent_this) {
  parent_this->impl_->is_output_shape_depend_on_compute = true;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::Follow(OpParamDef *parent_this, const char *paramName)
{
  if (parent_this->IsScalarTypeSet() || parent_this->IsScalarNameSet()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : Follow is incompatible with To", parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->follow_port_name = paramName;
  parent_this->impl_->follow_type = FollowType::ALL;
  return *parent_this;
}
 
OpParamDef &OpParamDefImpl::Follow(OpParamDef *parent_this, const char *paramName, FollowType ftype)
{
  if (parent_this->IsScalarTypeSet() || parent_this->IsScalarNameSet()) {
    GELOGE(ge::PARAM_INVALID, "Param %s : Follow is incompatible with To", parent_this->impl_->name.GetString());
    return *parent_this;
  }
  if (ftype >= FollowType::INVALID_TYPE) {
    GELOGE(ge::PARAM_INVALID, "Port %s : FollowType is Invalid", parent_this->impl_->name.GetString());
    return *parent_this;
  }
  parent_this->impl_->follow_port_name = paramName;
  parent_this->impl_->follow_type = ftype;
  return *parent_this;
}

OpParamDef &OpParamDefImpl::Comment(OpParamDef *parent_this, const char *comment) {
  if (comment == nullptr || strlen(comment) == 0) {
    GELOGE(ge::PARAM_INVALID, "Param %s : Comment content cannot be empty", parent_this->GetParamName().GetString());
    return *parent_this;
  }
  parent_this->impl_->comment = comment;
  return *parent_this;
}

std::vector<ge::DataType> &OpParamDefImpl::GetDataTypes(OpParamDef *parent_this) {
  if (parent_this->impl_->types.empty()) {
    GELOGW("GetDataTypes returns types_list because types is empty!");
    return parent_this->impl_->types_list;
  }
  return parent_this->impl_->types;
}

bool OpParamDefImpl::IsScalarOrScalarList(const OpParamDef *parent_this) const {
  return parent_this->IsScalar() || parent_this->IsScalarList();
}

std::vector<ge::DataType> &OpParamDefImpl::GetOriginDataTypes(OpParamDef *parent_this) {
  if (parent_this->impl_->origin_types.empty()) {
    GELOGE(ge::PARAM_INVALID, "origin types is empty, please check!");
    return parent_this->impl_->origin_types;
  }
  return parent_this->impl_->origin_types;
}


OpParamDef &OpParamTrunk::Input(const char *name) {
  return this->ParamGetOrCreate(name, false);
}

OpParamDef &OpParamTrunk::Output(const char *name) {
  return this->ParamGetOrCreate(name, true);
}

OpParamDef &OpParamTrunk::ParamGetOrCreate(const char *name, bool is_output) {
  OpParamDef *param;
  if (this->ParamFind(name, is_output, &param) == ItemFindStatus::ITEM_FIND) {
    return *param;
  } else {
    OpParamDef addParam(name);
    return this->ParamAdd(addParam, is_output);
  }
}

ItemFindStatus OpParamTrunk::ParamFind(const char *name, bool is_output, OpParamDef **param) {
  std::vector<OpParamDef> *paramList;

  if (is_output) {
    paramList = &(this->outputs_);
  } else {
    paramList = &(this->inputs_);
  }
  for (auto it = paramList->begin(); it != paramList->end(); it++) {
    if (it->GetParamName() == name) {
      *param = &(*it);
      return ItemFindStatus::ITEM_FIND;
    }
  }
  return ItemFindStatus::ITEM_NOEXIST;
}

OpParamDef &OpParamTrunk::ParamAdd(OpParamDef &param, bool is_output) {
  FollowMapUpdate(param, is_output);
  if (is_output) {
    this->outputs_.emplace_back(param);
    return this->outputs_.back();
  } else {
    this->inputs_.emplace_back(param);
    return this->inputs_.back();
  }
}

std::vector<OpParamDef> &OpParamTrunk::GetInputs(void) {
  return this->inputs_;
}

std::vector<OpParamDef> &OpParamTrunk::GetOutputs(void) {
  return this->outputs_;
}
void OpParamTrunk::FollowMapUpdate(OpParamDef &param, bool is_output) {
  ge::AscendString& cur_name = param.GetParamName();
  if (this->follow_map.find(cur_name) != this->follow_map.end()) {
    OpDef::PortFollowInfo& follow_info = this->follow_map[param.GetParamName()];
    follow_info.port_stat = OpDef::PortStat::INOUT;
    if (is_output) {
      follow_info.index_out = this->outputs_.size();
    } else {
      follow_info.index_in = this->inputs_.size();
    }
    return;
  }
  OpDef::PortFollowInfo follow_info;
  if (is_output) {
    follow_info.port_stat = OpDef::PortStat::OUT;
    follow_info.index_out = this->outputs_.size();
  } else {
    follow_info.port_stat = OpDef::PortStat::IN;
    follow_info.index_in = this->inputs_.size();
  }
  this->follow_map.emplace(cur_name, follow_info);
  return;
}
 
OpParamDef &OpParamTrunk::GetParamDef(const ge::AscendString& name, OpDef::PortStat stat) {
  OpDef::PortFollowInfo& follow_info = this->follow_map[name];
  if (stat == OpDef::PortStat::OUT) {
    return this->outputs_[follow_info.index_out];
  } else {
    return this->inputs_[follow_info.index_in];
  }
}
 
void OpParamTrunk::FollowDataImpl(void) {
  if (this->follow_isimpl == true) {
    return;
  }
  for (auto& op_param_def : this->inputs_) {
    this->DfsFollow(op_param_def, OpDef::PortStat::IN);
  }
  for (auto& op_param_def : this->outputs_) {
    this->DfsFollow(op_param_def, OpDef::PortStat::OUT);
  }
  this->follow_isimpl = true;
  return;
}
void OpParamTrunk::ParamFollow(OpParamDef &op_param_def, OpParamDef &target_param, OpDef::PortStat stat) {
  ge::AscendString cur_name = op_param_def.GetParamName();
  FollowType ftype = op_param_def.GetFollowType();
  ge::AscendString follow_name = target_param.GetParamName();
  if (ftype == FollowType::ALL || ftype == FollowType::DTYPE) {
    this->follow_dtype_map[follow_name].emplace_back(std::make_pair(cur_name, stat));
    if (target_param.IsDtype()) {
      op_param_def.impl_->types_status = target_param.impl_->types_status;
      op_param_def.impl_->types = target_param.impl_->types;
      op_param_def.impl_->origin_types = target_param.impl_->origin_types;
    }
    if (target_param.IsDtypeList()) {
      op_param_def.impl_->types_status = target_param.impl_->types_status;
      op_param_def.impl_->types_list = std::vector<ge::DataType>(1, target_param.impl_->types_list[0]);
      this->follow_dtypelist.emplace_back(std::make_pair(cur_name, stat));
    }
  }
  if (ftype == FollowType::ALL || ftype == FollowType::FORMAT) {
    if (target_param.IsFormat()) {
      op_param_def.impl_->formats_status = target_param.impl_->formats_status;
      op_param_def.impl_->formats = target_param.impl_->formats;
    }
    if (target_param.IsFormatList()) {
      op_param_def.impl_->formats_status = target_param.impl_->formats_status;
      op_param_def.impl_->formats_list = std::vector<ge::Format>(1, target_param.impl_->formats_list[0]);
      this->follow_formatlist.emplace_back(std::make_pair(cur_name, stat));
    }
  }
  if (ftype == FollowType::ALL || ftype == FollowType::SHAPE) {
    this->follow_shape_map[follow_name].emplace_back(std::make_pair(cur_name, stat));
  }
}

void OpParamTrunk::DfsFollow(OpParamDef& op_param_def, OpDef::PortStat stat) {
  if (op_param_def.GetFollowType() >= FollowType::INVALID_TYPE ||
      op_param_def.GetFollowName() == ge::AscendString("")) {
    return;
  }
  ge::AscendString cur_name = op_param_def.GetParamName();
  ge::AscendString follow_name = op_param_def.GetFollowName();
  FollowType ftype = op_param_def.GetFollowType();
  std::map<ge::AscendString, OpDef::PortFollowInfo>& flw_mp = this->follow_map;
  OpDef::PortFollowInfo& follow_info = flw_mp[cur_name];
  if (flw_mp.find(follow_name) == flw_mp.end()) {
    GELOGE(ge::PARAM_INVALID, "PortName %s : FollowPort is Not Exist", cur_name.GetString());
    return;
  }
  if (cur_name == follow_name && flw_mp[cur_name].port_stat != OpDef::PortStat::INOUT) {
    GELOGE(ge::PARAM_INVALID, "PortName %s : FollowPort ParamData is Not Found", cur_name.GetString());
    return;
  }
  if (cur_name != follow_name) {
    std::map<ge::AscendString, int> ring_check_map;
    while (flw_mp.find(follow_name) != flw_mp.end()) {
      if (ring_check_map.find(follow_name) != ring_check_map.end()) {
        GELOGE(ge::PARAM_INVALID, "Port %s : FollowData not Found", cur_name.GetString());
        return;
      }
      if (flw_mp[follow_name].follow_port_name == ge::AscendString("")) {
        break;
      }
      if (flw_mp[follow_name].follow_type != ftype) {
        GELOGE(ge::PARAM_INVALID, "Port %s : FollowType cannot be changed.", cur_name.GetString());
        return;
      }
      ring_check_map.emplace(follow_name, 1);
      follow_name = flw_mp[follow_name].follow_port_name;
    }
  }
  OpDef::PortFollowInfo& target_follow_info = flw_mp[follow_name];
  if (target_follow_info.port_stat == OpDef::PortStat::OUT) {
    GELOGE(ge::PARAM_INVALID, "Port %s : FollowData not Found", cur_name.GetString());
    return;
  }
  follow_info.follow_port_name = follow_name;
  follow_info.follow_type = ftype;
  op_param_def.impl_->follow_port_name = follow_name;
  OpParamDef& target_param = this->inputs_[target_follow_info.index_in];
  this->ParamFollow(op_param_def, target_param, stat);
}

void OpParamTrunk::FollowListDataImpl(const OpDef::DfsParam &dfs_param, std::vector<OpParamDef> &input,
                                      std::vector<OpParamDef> &output) {
  ge::AscendString name;
  OpDef::PortStat stat;
  uint32_t idx = 0;
  auto get_param_ref = [this, &input, &output](const ge::AscendString &port_name,
                                               OpDef::PortStat port_stat) -> OpParamDef & {
    if (port_stat == OpDef::PortStat::OUT) {
      return output[this->follow_map[port_name].index_out];
    } else {
      return input[this->follow_map[port_name].index_in];
    }
  };
  for (const auto& param_pair : this->follow_dtypelist) {
    std::tie(name, stat) = param_pair;
    uint32_t target_index = this->follow_map[this->follow_map[name].follow_port_name].index_in;
    OpParamDef& target_param = input[target_index];
    OpParamDef& op_param_def = get_param_ref(name, stat);
    op_param_def.impl_->types = target_param.impl_->types;
    if (op_param_def.IsSetDtypeForBin()) {
      std::vector<ge::DataType> data_types_for_bin;
      for (uint32_t type_idx = 0; type_idx < dfs_param.full_types.size(); ++type_idx) {
        idx = dfs_param.full_types[type_idx][target_index].first;
        data_types_for_bin.emplace_back(op_param_def.impl_->types_for_bin[idx]);
      }
      op_param_def.impl_->types_for_bin = data_types_for_bin;
    }
  }
  for (const auto& param_pair : this->follow_formatlist) {
    std::tie(name, stat) = param_pair;
    uint32_t target_index = this->follow_map[this->follow_map[name].follow_port_name].index_in;
    OpParamDef& target_param = input[target_index];
    OpParamDef& op_param_def = get_param_ref(name, stat);
    op_param_def.impl_->formats = target_param.impl_->formats;
    if (op_param_def.IsSetFormatForBin()) {
      std::vector<ge::Format> data_formats_for_bin;
      for (uint32_t format_idx = 0; format_idx < dfs_param.full_formats.size(); ++format_idx) {
        idx = dfs_param.full_formats[format_idx][input.size() + target_index].first;
        data_formats_for_bin.emplace_back(op_param_def.impl_->formats_for_bin[idx]);
      }
      op_param_def.impl_->formats_for_bin = data_formats_for_bin;
    }
  }
}
std::map<ge::AscendString, OpDef::PortFollowInfo> OpParamTrunk::GetFollowMap(void) {
  return this->follow_map;
}
std::map<ge::AscendString, std::vector<std::pair<ge::AscendString, OpDef::PortStat>>> OpParamTrunk::GetShapeMap() {
  return this->follow_shape_map;
}
std::map<ge::AscendString, std::vector<std::pair<ge::AscendString, OpDef::PortStat>>> OpParamTrunk::GetDtypeMap() {
  return this->follow_dtype_map;
}

void OpAICoreConfigImpl::Construct(OpAICoreConfig *parent_this, const char *soc) {
  (void)soc;
  parent_this->AddCfgItem("dynamicCompileStatic.flag", "true");
  parent_this->AddCfgItem("dynamicFormat.flag", "true");
  parent_this->AddCfgItem("dynamicRankSupport.flag", "true");
  parent_this->AddCfgItem("dynamicShapeSupport.flag", "true");
  parent_this->AddCfgItem("needCheckSupport.flag", "false");
  parent_this->AddCfgItem("precision_reduce.flag", "true");
}

void OpAICoreConfigImpl::Construct(OpAICoreConfig *parent_this, const OpAICoreConfig &aicore_config) {
  parent_this->impl_->op_params = aicore_config.impl_->op_params;
  parent_this->impl_->cfg_keys = aicore_config.impl_->cfg_keys;
  parent_this->impl_->cfg_info = aicore_config.impl_->cfg_info;
}

OpAICoreConfig &OpAICoreConfigImpl::Eq(OpAICoreConfig *parent_this, const OpAICoreConfig &aicore_config) {
  if (parent_this != &aicore_config) {
    *parent_this->impl_ = *aicore_config.impl_;
  }
  return *parent_this;
}

OpAICoreConfig &OpAICoreConfigImpl::DynamicCompileStaticFlag(OpAICoreConfig *parent_this, bool flag) {
  parent_this->AddCfgItem("dynamicCompileStatic.flag", flag ? "true" : "false");
  return *parent_this;
}

OpAICoreConfig &OpAICoreConfigImpl::DynamicFormatFlag(OpAICoreConfig *parent_this, bool flag) {
  parent_this->AddCfgItem("dynamicFormat.flag", flag ? "true" : "false");
  return *parent_this;
}

OpAICoreConfig &OpAICoreConfigImpl::DynamicRankSupportFlag(OpAICoreConfig *parent_this, bool flag) {
  parent_this->AddCfgItem("dynamicRankSupport.flag", flag ? "true" : "false");
  return *parent_this;
}

OpAICoreConfig &OpAICoreConfigImpl::DynamicShapeSupportFlag(OpAICoreConfig *parent_this, bool flag) {
  parent_this->AddCfgItem("dynamicShapeSupport.flag", flag ? "true" : "false");
  return *parent_this;
}

OpAICoreConfig &OpAICoreConfigImpl::NeedCheckSupportFlag(OpAICoreConfig *parent_this, bool flag) {
  parent_this->AddCfgItem("needCheckSupport.flag", flag ? "true" : "false");
  return *parent_this;
}

OpAICoreConfig &OpAICoreConfigImpl::PrecisionReduceFlag(OpAICoreConfig *parent_this, bool flag) {
  parent_this->AddCfgItem("precision_reduce.flag", flag ? "true" : "false");
  return *parent_this;
}

OpAICoreConfig &OpAICoreConfigImpl::ExtendCfgInfo(OpAICoreConfig *parent_this, const char *key, const char *value) {
  parent_this->AddCfgItem(key, value);
  return *parent_this;
}

void OpAICoreConfigImpl::AddCfgItem(OpAICoreConfig *parent_this, const char *key, const char *value) {
  auto it = parent_this->impl_->cfg_info.find(key);
  if (it == parent_this->impl_->cfg_info.cend()) {
    parent_this->impl_->cfg_keys.emplace_back(key);
  } else {
    parent_this->impl_->cfg_info.erase(key);
  }
  parent_this->impl_->cfg_info.emplace(key, value);
}

void OpAICoreDefImpl::Construct(OpAICoreDef *parent_this, const OpAICoreDef &aicore_def) {
  parent_this->impl_->tiling_func = aicore_def.impl_->tiling_func;
  parent_this->impl_->tiling_parse = aicore_def.impl_->tiling_parse;
  parent_this->impl_->ci_creator = aicore_def.impl_->ci_creator;
  parent_this->impl_->ci_deleter = aicore_def.impl_->ci_deleter;
  parent_this->impl_->op_chk_support = aicore_def.impl_->op_chk_support;
  parent_this->impl_->op_sel_format = aicore_def.impl_->op_sel_format;
  parent_this->impl_->op_get_support = aicore_def.impl_->op_get_support;
  parent_this->impl_->op_get_spec = aicore_def.impl_->op_get_spec;
  parent_this->impl_->op_generlize_func = aicore_def.impl_->op_generlize_func;
  parent_this->impl_->aicore_configs = aicore_def.impl_->aicore_configs;
}

OpAICoreDef &OpAICoreDefImpl::Eq(OpAICoreDef *parent_this, const OpAICoreDef &aicore_def) {
  if (parent_this != &aicore_def) {
    *parent_this->impl_ = *aicore_def.impl_;
  }
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::SetCheckSupport(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func) {
  parent_this->impl_->op_chk_support = func;
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::SetOpSelectFormat(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func) {
  parent_this->impl_->op_sel_format = func;
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::SetOpSupportInfo(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func) {
  parent_this->impl_->op_get_support = func;
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::SetOpSpecInfo(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func) {
  parent_this->impl_->op_get_spec = func;
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::SetParamGeneralize(OpAICoreDef *parent_this, optiling::PARAM_GENERALIZE_FUNC func) {
  parent_this->impl_->op_generlize_func = func;
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::AddConfig(OpAICoreDef *parent_this, const char *soc) {
  OpAICoreConfig aicore_config(soc);
  parent_this->AddConfig(soc, aicore_config);
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::AddConfig(OpAICoreDef *parent_this, const char *soc, OpAICoreConfig &aicore_config) {
  GELOGD("Call AddConfig for soc[%s].", soc);
  parent_this->impl_->aicore_configs.erase(ge::AscendString(soc));
  parent_this->impl_->aicore_configs.emplace(ge::AscendString(soc), aicore_config);
  return *parent_this;
}

OpAICoreDef &OpAICoreDefImpl::LaunchWithZeroEleOutputTensors(OpAICoreDef *parent_this, bool launchFlag) {
  parent_this->impl_->zero_ele_output_launch_flag = launchFlag;
  return *parent_this;
}

void OpMC2DefImpl::Construct(OpMC2Def *parent_this, const OpMC2Def &mc2_def) {
  parent_this->impl_->group_list = mc2_def.impl_->group_list;
}

OpMC2Def &OpMC2DefImpl::Eq(OpMC2Def *parent_this, const OpMC2Def &mc2_def) {
  if (parent_this != &mc2_def) {
    *parent_this->impl_ = *mc2_def.impl_;
  }
  return *parent_this;
}

OpMC2Def &OpMC2DefImpl::HcclGroup(OpMC2Def *parent_this, const char *value) {
  if (std::find(parent_this->impl_->group_list.begin(), parent_this->impl_->group_list.end(), value) ==
      parent_this->impl_->group_list.end()) {
    parent_this->impl_->group_list.emplace_back(value);
  }
  return *parent_this;
}

OpMC2Def &OpMC2DefImpl::HcclGroup(OpMC2Def *parent_this, std::vector<const char *> value) {
  for (const char *val : value) {
    if (std::find(parent_this->impl_->group_list.begin(), parent_this->impl_->group_list.end(), val) ==
        parent_this->impl_->group_list.end()) {
      parent_this->impl_->group_list.emplace_back(val);
    }
  }
  return *parent_this;
}

void OpMC2DefImpl::HcclServerTypeImpl(OpMC2Def *parent_this, enum HcclServerType type, const char *soc) {
  ge::AscendString soc_version;
  if (soc == nullptr || strlen(soc) == 0) {
    soc_version = "";
  } else {
    soc_version = soc;
  }
  parent_this->impl_->server_type_[soc_version] = type;
}

enum ops::HcclServerType OpMC2DefImpl::GetHcclServerType(const OpMC2Def *parent_this, const ge::AscendString &soc_version) const {
  if (parent_this->impl_->server_type_.empty()) {
    return HcclServerType::MAX;
  }
  if (soc_version.GetLength() == 0) {
    return HcclServerType::AICPU;
  }
  if (parent_this->impl_->server_type_.find(soc_version) != parent_this->impl_->server_type_.end()) {
    return parent_this->impl_->server_type_[soc_version];
  }
  if (parent_this->impl_->server_type_.find("") != parent_this->impl_->server_type_.end()) {
    return parent_this->impl_->server_type_[""];
  }
  return HcclServerType::MAX;
}
}  // namespace ops