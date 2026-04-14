/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef OP_DEF_IMPL_H
#define OP_DEF_IMPL_H

#include "register/op_def.h"
#include "register/op_impl_registry.h"
#include "register/op_check_register.h"

namespace ops {
enum ListParamStatus : int32_t {
  UNSET = 0,
  LIST = 1,
  NON_LIST = 2,
};
class OpParamDefImpl {
public:
  ge::AscendString name;
  Option param_type = Option::REQUIRED;
  std::vector<ge::DataType> types;
  std::vector<ge::DataType> origin_types;
  std::vector<ge::DataType> types_list;
  std::vector<ge::Format> formats;
  std::vector<ge::Format> formats_list;
  std::vector<ge::DataType> types_for_bin;
  std::vector<ge::Format> formats_for_bin;
  ListParamStatus types_status = UNSET;
  ListParamStatus formats_status = UNSET;
  ge::AscendString need_compile = "";
  ge::AscendString reshape_type = "";
  ge::AscendString value_depend = "";
  DependScope depend_scope = DependScope::ALL;
  std::vector<ge::Format> unknown_shape_formats;
  bool ignore_contiguous = false;
  bool auto_contiguous = false;
  bool is_scalar = false;
  bool is_scalar_list = false;
  bool set_type_for_bin = false;
  bool set_format_for_bin = false;
  ge::AscendString scalar_name = "";
  ge::DataType scalar_type = ge::DT_UNDEFINED;
  uint32_t version{0};
  InitValueType init_value_type = InitValueType::INIT_VALUE_DEFAULT;
  InitValueNum init_value;
  std::vector<ScalarVar> init_value_list;
  bool is_output_shape_depend_on_compute = false;
  ge::AscendString follow_port_name = "";
  FollowType follow_type = FollowType::INVALID_TYPE;
  ge::AscendString comment = "";

  void MergeParam(OpParamDef *parent_this, const OpParamDef &def);
  OpParamDef &DataType(OpParamDef *parent_this, std::vector<ge::DataType> types);
  OpParamDef &DataTypeList(OpParamDef *parent_this, std::vector<ge::DataType> types);
  OpParamDef &Format(OpParamDef *parent_this, std::vector<ge::Format> formats);
  OpParamDef &FormatList(OpParamDef *parent_this, std::vector<ge::Format> formats);
  OpParamDef &DataTypeForBinQuery(OpParamDef *parent_this, std::vector<ge::DataType> types);
  OpParamDef &FormatForBinQuery(OpParamDef *parent_this, std::vector<ge::Format> formats);
  OpParamDef &ValueDepend(OpParamDef *parent_this, Option value_depend);
  OpParamDef &ValueDepend(OpParamDef *parent_this, Option value_depend, DependScope scope);
  OpParamDef &To(OpParamDef *parent_this, const ge::DataType type);
  OpParamDef &To(OpParamDef *parent_this, const char *name);
  OpParamDef &InitValue(OpParamDef *parent_this, uint64_t value);
  OpParamDef &InitValue(OpParamDef *parent_this, const ScalarVar &value);
  OpParamDef &InitValue(OpParamDef *parent_this, const std::vector<ScalarVar> &value);
  static void Construct(OpParamDef *parent_this, const char *name);
  static void Construct(OpParamDef *parent_this, const OpParamDef &def);
  OpParamDef &Eq(OpParamDef *parent_this, const OpParamDef &def);
  bool DoubleEq(const OpParamDef *parent_this, const OpParamDef &def) const;
  OpParamDef &ParamType(OpParamDef *parent_this, Option param_type);
  OpParamDef &UnknownShapeFormat(OpParamDef *parent_this, std::vector<ge::Format> formats);
  OpParamDef &IgnoreContiguous(OpParamDef *parent_this);
  OpParamDef &AutoContiguous(OpParamDef *parent_this);
  OpParamDef &Scalar(OpParamDef *parent_this);
  OpParamDef &ScalarList(OpParamDef *parent_this);
  OpParamDef &Version(OpParamDef *parent_this, uint32_t version);
  OpParamDef &OutputShapeDependOnCompute(OpParamDef *parent_this);
  OpParamDef &Follow(OpParamDef *parent_this, const char *paramName);
  OpParamDef &Follow(OpParamDef *parent_this, const char *paramName, FollowType ftype);
  OpParamDef &Comment(OpParamDef *parent_this, const char *comment);
  std::vector<ge::DataType> &GetDataTypes(OpParamDef *parent_this);
  std::vector<ge::DataType> &GetOriginDataTypes(OpParamDef *parent_this);
  bool IsScalarOrScalarList(const OpParamDef *parent_this) const;
};

class OpParamTrunk {
public:
  OpParamDef &Input(const char *name);
  OpParamDef &Output(const char *name);
  std::vector<OpParamDef> &GetInputs(void);
  std::vector<OpParamDef> &GetOutputs(void);

private:
  friend class OpDef;
  friend class OpProtoGenerator;

  ItemFindStatus ParamFind(const char *name, bool is_output, OpParamDef **param);
  OpParamDef &ParamAdd(OpParamDef &param, bool is_output);
  OpParamDef &ParamGetOrCreate(const char *name, bool is_output);
  OpParamDef &GetParamDef(const ge::AscendString& name, OpDef::PortStat stat);
  void FollowMapUpdate(OpParamDef &param, bool is_output);
  void FollowDataImpl(void);
  void DfsFollow(OpParamDef& op_param_def, OpDef::PortStat stat);
  void ParamFollow(OpParamDef &op_param_def, OpParamDef &target_param, OpDef::PortStat stat);
  void FollowListDataImpl(const OpDef::DfsParam &dfs_param, std::vector<OpParamDef> &input,
                          std::vector<OpParamDef> &output);
  std::map<ge::AscendString, OpDef::PortFollowInfo> GetFollowMap(void);
  std::map<ge::AscendString, std::vector<std::pair<ge::AscendString, OpDef::PortStat>>> GetShapeMap(void);
  std::map<ge::AscendString, std::vector<std::pair<ge::AscendString, OpDef::PortStat>>> GetDtypeMap(void);
  bool follow_isimpl = false;
  std::vector<OpParamDef> inputs_;
  std::vector<OpParamDef> outputs_;
  std::map<ge::AscendString, OpDef::PortFollowInfo> follow_map;
  std::vector<std::pair<ge::AscendString, OpDef::PortStat>> follow_dtypelist;
  std::vector<std::pair<ge::AscendString, OpDef::PortStat>> follow_formatlist;
  std::map<ge::AscendString, std::vector<std::pair<ge::AscendString, OpDef::PortStat>>> follow_shape_map;
  std::map<ge::AscendString, std::vector<std::pair<ge::AscendString, OpDef::PortStat>>> follow_dtype_map;
};

class OpAttrDefImpl {
public:
  ge::AscendString name;
  AttrDataType data_type = AttrDataType::ATTR_DT_BOOL;
  bool required = true;
  bool bool_value = false;
  float float_value = 0;
  int64_t int_value = 0;
  ge::AscendString str_value = "";
  std::vector<bool> list_bool = {};
  std::vector<float> list_float = {};
  std::vector<int64_t> list_int = {};
  std::vector<std::vector<int64_t>> list_list_int = {};
  ge::AscendString value = "";
  uint32_t version = 0;
  ge::AscendString comment = "";

  OpAttrDef &AttrType(OpAttrDef *parent_this, Option attr_type);
  OpAttrDef &Comment(OpAttrDef *parent_this, const char *comment);
  ge::AscendString &GetCfgDataType(const OpAttrDef *parent_this) const;
  ge::AscendString &GetProtoDataType(const OpAttrDef *parent_this) const;
  ge::AscendString &GetAttrDefaultVal(OpAttrDef *parent_this, const char *brac);
  static void Construct(OpAttrDef *parent_this, const char *name);
  static void Construct(OpAttrDef *parent_this, const OpAttrDef &attr_def);
  OpAttrDef &Eq(OpAttrDef *parent_this, const OpAttrDef &attr_def);
  bool DoubleEq(const OpAttrDef *parent_this, const OpAttrDef &attr_def) const;
  OpAttrDef &Bool(OpAttrDef *parent_this);
  OpAttrDef &Bool(OpAttrDef *parent_this, bool value);
  OpAttrDef &Float(OpAttrDef *parent_this);
  OpAttrDef &Float(OpAttrDef *parent_this, float value);
  OpAttrDef &Int(OpAttrDef *parent_this);
  OpAttrDef &Int(OpAttrDef *parent_this, int64_t value);
  OpAttrDef &String(OpAttrDef *parent_this);
  OpAttrDef &String(OpAttrDef *parent_this, const char *value);
  OpAttrDef &ListBool(OpAttrDef *parent_this);
  OpAttrDef &ListBool(OpAttrDef *parent_this, std::vector<bool> value);
  OpAttrDef &ListFloat(OpAttrDef *parent_this);
  OpAttrDef &ListFloat(OpAttrDef *parent_this, std::vector<float> value);
  OpAttrDef &ListInt(OpAttrDef *parent_this);
  OpAttrDef &ListInt(OpAttrDef *parent_this, std::vector<int64_t> value);
  OpAttrDef &ListListInt(OpAttrDef *parent_this);
  OpAttrDef &ListListInt(OpAttrDef *parent_this, std::vector<std::vector<int64_t>> value);
  OpAttrDef &Version(OpAttrDef *parent_this, uint32_t version);
};

class OpAICoreConfigImpl {
public:
  OpParamTrunk op_params;
  std::vector<ge::AscendString> cfg_keys;
  std::map<ge::AscendString, ge::AscendString> cfg_info;

  static void Construct(OpAICoreConfig *parent_this, const char *soc);
  static void Construct(OpAICoreConfig *parent_this, const OpAICoreConfig &aicore_config);
  OpAICoreConfig &Eq(OpAICoreConfig *parent_this, const OpAICoreConfig &aicore_config);
  OpAICoreConfig &DynamicCompileStaticFlag(OpAICoreConfig *parent_this, bool flag);
  OpAICoreConfig &DynamicFormatFlag(OpAICoreConfig *parent_this, bool flag);
  OpAICoreConfig &DynamicRankSupportFlag(OpAICoreConfig *parent_this, bool flag);
  OpAICoreConfig &DynamicShapeSupportFlag(OpAICoreConfig *parent_this, bool flag);
  OpAICoreConfig &NeedCheckSupportFlag(OpAICoreConfig *parent_this, bool flag);
  OpAICoreConfig &PrecisionReduceFlag(OpAICoreConfig *parent_this, bool flag);
  OpAICoreConfig &ExtendCfgInfo(OpAICoreConfig *parent_this, const char *key, const char *value);
  void AddCfgItem(OpAICoreConfig *parent_this, const char *key, const char *value);
};

class OpAICoreDefImpl {
public:
  gert::OpImplRegisterV2::TilingKernelFunc tiling_func = nullptr;
  gert::OpImplRegisterV2::TilingParseFunc tiling_parse = nullptr;
  gert::OpImplRegisterV2::CompileInfoCreatorFunc ci_creator = nullptr;
  gert::OpImplRegisterV2::CompileInfoDeleterFunc ci_deleter = nullptr;
  optiling::OP_CHECK_FUNC op_chk_support = nullptr;
  optiling::OP_CHECK_FUNC op_sel_format = nullptr;
  optiling::OP_CHECK_FUNC op_get_support = nullptr;
  optiling::OP_CHECK_FUNC op_get_spec = nullptr;
  optiling::PARAM_GENERALIZE_FUNC op_generlize_func = nullptr;
  bool zero_ele_output_launch_flag = false;
  std::map<ge::AscendString, OpAICoreConfig> aicore_configs = {};

  static void Construct(OpAICoreDef *parent_this, const OpAICoreDef &aicore_def);
  OpAICoreDef &Eq(OpAICoreDef *parent_this, const OpAICoreDef &aicore_def);
  OpAICoreDef &SetCheckSupport(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func);
  OpAICoreDef &SetOpSelectFormat(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func);
  OpAICoreDef &SetOpSupportInfo(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func);
  OpAICoreDef &SetOpSpecInfo(OpAICoreDef *parent_this, optiling::OP_CHECK_FUNC func);
  OpAICoreDef &SetParamGeneralize(OpAICoreDef *parent_this, optiling::PARAM_GENERALIZE_FUNC func);
  OpAICoreDef &AddConfig(OpAICoreDef *parent_this, const char *soc);
  OpAICoreDef &AddConfig(OpAICoreDef *parent_this, const char *soc, OpAICoreConfig &aicore_config);
  OpAICoreDef &LaunchWithZeroEleOutputTensors(OpAICoreDef *parent_this, bool launchFlag);
};

class OpAICPUDefImpl {
public:
  std::vector<ge::AscendString> cfg_keys;
  std::map<ge::AscendString, ge::AscendString> cfg_info;
};

class OpHostCPUDefImpl {
public:
  std::vector<ge::AscendString> cfg_keys;
  std::map<ge::AscendString, ge::AscendString> cfg_info;
};

class OpMC2DefImpl {
public:
  std::vector<ge::AscendString> group_list = {};
  std::map<ge::AscendString, HcclServerType> server_type_ = {};

  static void Construct(OpMC2Def *parent_this, const OpMC2Def &mc2_def);
  OpMC2Def &Eq(OpMC2Def *parent_this, const OpMC2Def &mc2_def);
  OpMC2Def &HcclGroup(OpMC2Def *parent_this, const char *value);
  OpMC2Def &HcclGroup(OpMC2Def *parent_this, std::vector<const char *> value);
  void HcclServerTypeImpl(OpMC2Def *parent_this, enum HcclServerType type, const char *soc = nullptr);
  ops::HcclServerType GetHcclServerType(const OpMC2Def *parent_this, const ge::AscendString &soc_version = "") const;
};

class OpDefImpl {
public:
  gert::OpImplRegisterV2::InferShapeKernelFunc infer_shape = nullptr;
  gert::OpImplRegisterV2::InferShapeRangeKernelFunc infer_shape_range = nullptr;
  gert::OpImplRegisterV2::InferDataTypeKernelFunc infer_data_type = nullptr;
  OpParamTrunk op_params;
  std::vector<OpAttrDef> attrs;
  OpAICoreDef op_aicore;
  OpAICPUDef op_aicpu;
  OpHostCPUDef op_hostcpu;
  ge::AscendString op_type;
  ge::AscendString category = "op_proto";
  std::map<ops::CommentSection, std::vector<ge::AscendString>> comment_map = {
    {ops::CommentSection::BRIEF, {}},
    {ops::CommentSection::CONSTRAINTS, {}},
    {ops::CommentSection::RESTRICTIONS, {}},
    {ops::CommentSection::SEE, {}},
    {ops::CommentSection::THIRDPARTYFWKCOMPAT, {}}
  };
  bool has_workspace = true;
  uint32_t non_list_len = 0;
  OpMC2Def op_mc2;
  FormatCheckOption format_mode = FormatCheckOption::MAX;
  bool enable_fall_back = false;
  OpDef &Comment(OpDef *parent_this, CommentSection section, const char *comment);
  OpDef &SetInferShape(OpDef *parent_this, gert::OpImplRegisterV2::InferShapeKernelFunc func);
  OpDef &SetInferShapeRange(OpDef *parent_this, gert::OpImplRegisterV2::InferShapeRangeKernelFunc func);
  OpDef &SetInferDataType(OpDef *parent_this, gert::OpImplRegisterV2::InferDataTypeKernelFunc func);
  
  OpAttrDef &GetOrCreateAttr(OpDef *parent_this, const char *name);
  void MergeParam(std::vector<OpParamDef> &merge, std::vector<OpParamDef> &aicore_params) const;
  void DfsFullPermutation(OpDef::DfsParam &dfs_param, const std::vector<OpParamDef> &all_param,
                          uint32_t list_idx, uint32_t non_list_idx) const;
  void DfsDataType(OpDef::DfsParam &dfs_param, const std::vector<OpParamDef> &all_param,
                   uint32_t list_idx, uint32_t non_list_idx) const;
  void DfsFormat(OpDef::DfsParam &dfs_param, const std::vector<OpParamDef> &all_param,
                 uint32_t list_idx, uint32_t non_list_idx) const;
  bool IsNonListTypes(const OpParamDef &def) const;
  uint32_t GetNonListLen(const OpDef *parent_this, std::vector<OpParamDef> &input_param, std::vector<OpParamDef> &output_param) const;
  OpAttrDef &AddAttr(OpDef *parent_this, OpAttrDef &attr);
  bool IsNonListFormats(const OpParamDef &def) const;
  void UpdateDtypeImpl(const OpDef::DfsParam &dfs_param, OpParamDef &param, const uint32_t &param_idx);
  void UpdateFormatImpl(const OpDef::DfsParam &dfs_param, OpParamDef &param, const uint32_t &param_idx);
  void UpdateInput(OpDef *parent_this, const OpDef::DfsParam &dfs_param, std::vector<OpParamDef> &input);
  void UpdateOutput(OpDef *parent_this, const OpDef::DfsParam &dfs_param, std::vector<OpParamDef> &output);
  void SetPermutedParam(OpDef *parent_this, const OpDef::DfsParam &dfs_param, std::vector<OpParamDef> &input,
                              std::vector<OpParamDef> &output);
  void CheckIncompatible(const std::vector<OpParamDef>& all) const;
  void FullPermutation(OpDef *parent_this, std::vector<OpParamDef> &input_param, std::vector<OpParamDef> &output_param);
  void SetDefaultND(std::vector<OpParamDef> &defs) const;
  std::vector<std::vector<OpParamDef>> GetMergeInputsOutputs(OpDef *parent_this, const OpAICoreConfig &aicore_config);
  std::vector<OpParamDef> GetMergeInputs(OpDef *parent_this, OpAICoreConfig &aicore_config);
  std::vector<OpParamDef> GetMergeOutputs(OpDef *parent_this, OpAICoreConfig &aicore_config);
  ItemFindStatus FindAttr(OpDef *parent_this, const char *name, OpAttrDef **attr);
  static void Construct(OpDef *parent_this, const char *type);
  static void Construct(OpDef *parent_this, const OpDef &op_def);
  OpDef &Eq(OpDef *parent_this, const OpDef &op_def);
  OpDef &FormatMatchMode(OpDef *parent_this, FormatCheckOption option);
  OpDef &EnableFallBack(OpDef *parent_this);
};
}  // namespace ops

#endif
