/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "register/op_impl_registry.h"
#include <sstream>
#include "common/ge_common/debug/ge_log.h"
#include "graph/any_value.h"
#include "register/op_impl_registry_base.h"
#include "base/registry/op_impl_register_v2_impl.h"
#include "common/checker.h"
#include "common/plugin/plugin_manager.h"

namespace gert {
namespace {
void RegisterOpImplToRegistry(const OpImplRegisterV2Impl *rd) {
  if (rd == nullptr) {
    GELOGW("The register data is invalid, the impl is nullptr");
    return;
  }
  auto &funcs = OpImplRegistry::GetInstance().CreateOrGetOpImpl(rd->op_type.GetString());
  std::stringstream ss;
  if (rd->functions.infer_shape != nullptr) {
    ss << "[InferShape]";
    funcs.infer_shape = rd->functions.infer_shape;
  }
  if (rd->functions.infer_shape_range != nullptr) {
    ss << "[InferShapeRange]";
    funcs.infer_shape_range = rd->functions.infer_shape_range;
  }
  if (rd->functions.infer_datatype != nullptr) {
    ss << "[InferDataType]";
    funcs.infer_datatype = rd->functions.infer_datatype;
  }
  if (rd->functions.tiling != nullptr) {
    ss << "[Tiling]";
    funcs.tiling = rd->functions.tiling;
    funcs.max_tiling_data_size = rd->functions.max_tiling_data_size;
  }
  if (rd->functions.gen_simplifiedkey != nullptr) {
    ss << "[GenSimplifiedKey]";
    funcs.gen_simplifiedkey = rd->functions.gen_simplifiedkey;
  }
  if (rd->functions.inputs_dependency != 0U) {
    ss << "[InputsDependency]";
    funcs.inputs_dependency = rd->functions.inputs_dependency;
  }
  if (rd->functions.host_inputs != 0U) {
    ss << "[HostInputs]";
    funcs.host_inputs = rd->functions.host_inputs;
  }
  if (rd->functions.tiling_dependency != 0U) {
    ss << "[TilingDependency]";
    funcs.tiling_dependency = rd->functions.tiling_dependency;
  }
  if (rd->functions.tiling_dependency_placements != 0U) {
    ss << "[TilingDependencyPlacement]";
    funcs.tiling_dependency_placements = rd->functions.tiling_dependency_placements;
  }
  if (rd->functions.op_execute_func != nullptr) {
    ss << "[OpExecuteFunc]";
    funcs.op_execute_func = rd->functions.op_execute_func;
  }
  if ((rd->functions.op_execute_prepare_func != nullptr) && (rd->functions.op_execute_launch_func != nullptr)) {
    ss << "[Op2StageExecuteFuncs]";
    funcs.op_execute_prepare_func = rd->functions.op_execute_prepare_func;
    funcs.op_execute_launch_func = rd->functions.op_execute_launch_func;
  }
  if (rd->functions.tiling_parse != nullptr) {
    ss << "[TilingParse]";
    funcs.tiling_parse = rd->functions.tiling_parse;
    funcs.compile_info_creator = rd->functions.compile_info_creator;
    funcs.compile_info_deleter = rd->functions.compile_info_deleter;
  }
  if (rd->is_private_attr_registered) {
    ss << "[PrivateAtrr]";
    funcs.private_attrs = rd->functions.private_attrs;
    funcs.unique_private_attrs = rd->functions.unique_private_attrs;
  }
  if (rd->functions.output_shape_depend_compute != 0U) {
    ss << "[OutputShapeDependCompute]";
    funcs.output_shape_depend_compute = rd->functions.output_shape_depend_compute;
  }
  if (rd->functions.infer_format_func != nullptr) {
    ss << "[InferFormat]";
    funcs.infer_format_func = rd->functions.infer_format_func;
  }
  if (rd->functions.calc_op_param != nullptr) {
    ss << "[CalcOpParam]";
    funcs.calc_op_param = rd->functions.calc_op_param;
  }
  if (rd->functions.gen_task != nullptr) {
    ss << "[GenTask]";
    funcs.gen_task = rd->functions.gen_task;
  }
  if (rd->functions.check_support != nullptr) {
    ss << "[CheckSupport]";
    funcs.check_support = rd->functions.check_support;
  }
  if (rd->functions.op_select_format != nullptr) {
    ss << "[OpSelectFormat]";
    funcs.op_select_format = rd->functions.op_select_format;
  }
  if (rd->functions.exception_func != nullptr) {
    ss << "[ExceptionFunc]";
    funcs.exception_func = rd->functions.exception_func;
  }

  GELOGI("LocalRegistry[%zu] Op type[%s] register OP_IMPL : %s",
         std::hash<std::string>()(metadef::GetModelPathByAddr(&OpImplRegistry::GetInstance())),
         rd->op_type.GetString(), ss.str().c_str());
}

ge::graphStatus InferOutDataTypeSameWithFirstInputFunc(InferDataTypeContext *context) {
  const auto compute_node_info = context->GetComputeNodeInfo();
  GE_ASSERT_TRUE(compute_node_info != nullptr, "Get null compute_node_info.");

  const auto input0_dtype = context->GetInputDataType(0);
  GE_ASSERT_TRUE(input0_dtype != ge::DT_UNDEFINED, "Get undefined datatype of input_0, op_name:[%s], op_type:[%s].",
                 context->GetComputeNodeInfo()->GetNodeName(), context->GetComputeNodeInfo()->GetNodeType());

  const auto output_num = context->GetComputeNodeOutputNum();
  for (size_t i = 0U; i < output_num; ++i) {
    GE_ASSERT_GRAPH_SUCCESS(context->SetOutputDataType(i, input0_dtype),
                            "Failed to set datatype of output_%zu, op_name:[%s], op_type:[%s].", i,
                            compute_node_info->GetNodeName(), compute_node_info->GetNodeType());
  }
  return ge::GRAPH_SUCCESS;
}
} // namespace

OpImplRegisterV2 &OpImplRegisterV2::ExceptionDumpParseFunc(ExcepitonDumpFunc exception_func) {
  if (impl_ != nullptr && exception_func != nullptr) {
    impl_->functions.exception_func = exception_func;
    GELOGI("Register exception function for op type %s", impl_->op_type.GetString());
  } else {
    GELOGW("Failed to register exception function for op type%s", impl_->op_type.GetString());
  }
  return *this;
}

gert::OpImplKernelRegistry::OpImplFunctions &gert::OpImplKernelRegistry::OpImplFunctions::operator=(
    gert::OpImplKernelRegistry::OpImplFunctionsV2 &func) {
  *this = static_cast<OpImplFunctions &>(func);
  return *this;
}

gert::OpImplKernelRegistry::OpImplFunctionsV2 &gert::OpImplKernelRegistry::OpImplFunctionsV2::operator=(
    gert::OpImplKernelRegistry::OpImplFunctions &func) {
  static_cast<gert::OpImplKernelRegistry::OpImplFunctions&>(*this) = func;
  return *this;
}

gert::OpImplKernelRegistry::OpImplFunctionsV2::OpImplFunctionsV2(
    gert::OpImplKernelRegistry::OpImplFunctions &func) :
    gert::OpImplKernelRegistry::OpImplFunctions(func) {}

gert::OpImplKernelRegistry::OpImplFunctionsV2::OpImplFunctionsV2 (
    const gert::OpImplKernelRegistry::OpImplFunctions &func) :
    gert::OpImplKernelRegistry::OpImplFunctions(func) {}

OpImplRegistry &OpImplRegistry::GetInstance() {
  static OpImplRegistry instance;
  return instance;
}

OpImplRegistry::OpImplFunctionsV2 &OpImplRegistry::CreateOrGetOpImpl(const ge::char_t *op_type) {
  (void)reserved_;
  return types_to_impl_[op_type];
}
const OpImplRegistry::OpImplFunctionsV2 *OpImplRegistry::GetOpImpl(const ge::char_t *op_type) const {
  const auto iter = types_to_impl_.find(op_type);
  if (iter == types_to_impl_.end()) {
    return nullptr;
  }
  return &iter->second;
}
const OpImplRegisterV2::PrivateAttrList &OpImplRegistry::GetPrivateAttrs(const ge::char_t *op_type) const {
  const auto op_impl_ptr = GetOpImpl(op_type);
  if (op_impl_ptr == nullptr) {
    static OpImplRegisterV2::PrivateAttrList emptyPrivateAttr;
    return emptyPrivateAttr;
  }
  return op_impl_ptr->private_attrs;
}
const std::map<OpImplRegisterV2::OpType, OpImplRegistry::OpImplFunctionsV2> &OpImplRegistry::GetAllTypesToImpl() const {
  return types_to_impl_;
}
std::map<OpImplRegisterV2::OpType, OpImplRegistry::OpImplFunctionsV2> &OpImplRegistry::GetAllTypesToImpl() {
  return types_to_impl_;
}
OpImplRegisterV2::OpImplRegisterV2(const ge::char_t *op_type) : impl_(new(std::nothrow) OpImplRegisterV2Impl) {
  if (impl_ == nullptr) {
    return;
  }

  GELOGD("op type: %s", op_type);
  impl_->op_type = op_type;
  impl_->functions.infer_shape = nullptr;
  impl_->functions.infer_symbol_shape = nullptr;
  impl_->functions.infer_shape_range = nullptr;
  impl_->functions.infer_datatype = nullptr;
  impl_->functions.inputs_dependency = 0U;
  impl_->functions.op_execute_func = nullptr;
  impl_->functions.op_execute_prepare_func = nullptr;
  impl_->functions.op_execute_launch_func = nullptr;
  impl_->functions.host_inputs = 0U;
  impl_->functions.tiling_dependency = 0U;
  impl_->functions.tiling_dependency_placements = 0U;
  impl_->functions.gen_simplifiedkey = nullptr;
  impl_->functions.calc_op_param = nullptr;
  impl_->functions.gen_task = nullptr;
  impl_->functions.check_support = nullptr;
  impl_->functions.op_select_format = nullptr;
  impl_->functions.exception_func = nullptr;
  // two fields controlled by tiling func
  impl_->functions.tiling = nullptr;
  impl_->functions.max_tiling_data_size = std::numeric_limits<size_t>::max();

  // 3 fields controlled by tiling_parse func
  impl_->functions.tiling_parse = nullptr;
  impl_->functions.compile_info_creator = nullptr;
  impl_->functions.compile_info_deleter = nullptr;
  impl_->functions.gen_simplifiedkey = nullptr;
  impl_->functions.output_shape_depend_compute = 0U;
  impl_->functions.infer_format_func = nullptr;

  // private attr controlled by is_private_attr_registered
  (void)OpImplRegistry::GetInstance().CreateOrGetOpImpl(op_type);
}

OpImplRegisterV2::~OpImplRegisterV2() = default;
OpImplRegisterV2::OpImplRegisterV2(const OpImplRegisterV2 &register_data) {
  RegisterOpImplToRegistry(register_data.impl_.get());
}
OpImplRegisterV2::OpImplRegisterV2(OpImplRegisterV2 &&register_data) noexcept {
  RegisterOpImplToRegistry(register_data.impl_.get());
}
OpImplRegisterV2 &OpImplRegisterV2::TilingParse(OpImplRegisterV2::KernelFunc tiling_parse_func,
                                                OpImplRegisterV2::CompileInfoCreatorFunc creator_func,
                                                OpImplRegisterV2::CompileInfoDeleterFunc deleter_func) {
  if (impl_ != nullptr) {
    impl_->functions.tiling_parse = tiling_parse_func;
    impl_->functions.compile_info_creator = creator_func;
    impl_->functions.compile_info_deleter = deleter_func;
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::InferShape(OpImplRegisterV2::InferShapeKernelFunc infer_shape_func) {
  if (impl_ != nullptr) {
    impl_->functions.infer_shape = infer_shape_func;
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::InferShapeRange(
    OpImplRegisterV2::InferShapeRangeKernelFunc infer_shape_range_func) {
  if (impl_ != nullptr) {
    impl_->functions.infer_shape_range = infer_shape_range_func;
  }
  return *this;
}
OpImplRegisterV2 &OpImplRegisterV2::InferDataType(OpImplRegisterV2::InferDataTypeKernelFunc infer_datatype_func) {
  if (impl_ != nullptr) {
    impl_->functions.infer_datatype = infer_datatype_func;
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::InferOutDataTypeSameWithFirstInput() {
  return InferDataType(&InferOutDataTypeSameWithFirstInputFunc);
}

OpImplRegisterV2 &OpImplRegisterV2::Tiling(OpImplRegisterV2::TilingKernelFunc tiling_func,
                                           size_t max_tiling_data_size) {
  if (impl_ != nullptr) {
    impl_->functions.tiling = tiling_func;
    impl_->functions.max_tiling_data_size = max_tiling_data_size;
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::GenSimplifiedKey(
    OpImplRegisterV2::GenSimplifiedKeyKernelFunc gen_simplifiedkey_func) {
  if (impl_ != nullptr) {
    impl_->functions.gen_simplifiedkey = gen_simplifiedkey_func;
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::InputsDataDependency(std::initializer_list<int32_t> inputs) {
  if (impl_ != nullptr) {
    for (const int32_t index : inputs) {
      if (impl_->functions.IsInputDataDependency(static_cast<size_t>(index))) {
        continue;
      }
      if (impl_->functions.SetInputDataDependency(static_cast<size_t>(index)) != ge::GRAPH_SUCCESS) {
        GELOGE(ge::FAILED, "Failed to set data dependency for node %s, the input index %d", impl_->op_type.GetString(),
               index);
        return *this;
      }
    }
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::TilingInputsDataDependency(std::initializer_list<int32_t> inputs) {
  return TilingInputsDataDependency(inputs, {TilingPlacement::TILING_ON_HOST});
}

OpImplRegisterV2 &OpImplRegisterV2::TilingInputsDataDependency(
    std::initializer_list<int32_t> inputs, std::initializer_list<TilingPlacement> placements) {
  if (impl_ != nullptr) {
    for (const int32_t index : inputs) {
      if (impl_->functions.IsTilingInputDataDependency(static_cast<size_t>(index))) {
        continue;
      }
      if (impl_->functions.SetTilingInputDataDependency(static_cast<size_t>(index)) != ge::GRAPH_SUCCESS) {
        GELOGE(ge::FAILED, "Failed to set tiling dependency for node %s, the input index %d",
               impl_->op_type.GetString(), index);
        return *this;
      }
    }

    for (const auto placement : placements) {
      if (impl_->functions.IsSupportTilingDependencyPlacement(static_cast<uint32_t>(placement))) {
        continue;
      }
      if (impl_->functions.SetTilingDependencyPlacement(static_cast<uint32_t>(placement)) != ge::GRAPH_SUCCESS) {
        GELOGE(ge::FAILED, "Failed to set tiling dependency placement for node %s, the placement %d",
               impl_->op_type.GetString(), placement);
        return *this;
      }
    }
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::CalcOpParam(OpCalcParamKernelFunc calc_op_param_func) {
  if (impl_ != nullptr) {
    impl_->functions.calc_op_param = calc_op_param_func;
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::GenerateTask(OpGenTaskKernelFunc gen_task_func) {
  if (impl_ != nullptr) {
    impl_->functions.gen_task = gen_task_func;
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::CheckSupport(OP_CHECK_FUNC_V2 check_support_func) {
  if (impl_ != nullptr) {
    impl_->functions.check_support = check_support_func;
  }
  return *this;
}
OpImplRegisterV2 &OpImplRegisterV2::OpSelectFormat(OP_CHECK_FUNC_V2 op_select_format_func) {
  if (impl_ != nullptr) {
    impl_->functions.op_select_format = op_select_format_func;
  }
  return *this;
}
OpImplRegisterV2 &OpImplRegisterV2::OutputShapeDependOnCompute(std::initializer_list<int32_t> outputs) {
  if (impl_ != nullptr) {
    for (const int32_t index : outputs) {
      if (impl_->functions.IsOutputShapeDependOnCompute(static_cast<size_t>(index))) {
        continue;
      }
      if (impl_->functions.SetOutputShapeDependOnCompute(static_cast<size_t>(index)) != ge::GRAPH_SUCCESS) {
        GELOGE(ge::FAILED, "Failed to set output shape depend compute for node %s, the output index %d", impl_->op_type.GetString(),
               index);
        return *this;
      }
    }
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr, ge::AnyValue private_attr_av) {
  if (private_attr == nullptr) {
    GELOGW("Failed to set private attr name using nullptr!");
    return *this;
  }
  if (strncmp(private_attr, "", 1U) == 0) {
    GELOGW("Failed to set private attr name using empty string!");
    return *this;
  }
  if (impl_ != nullptr) {
    impl_->is_private_attr_registered = true;
    if (impl_->functions.unique_private_attrs.insert(private_attr).second) {
      (void)impl_->functions.private_attrs.emplace_back(std::make_pair(private_attr, std::move(private_attr_av)));
    } else {
      GELOGW("The private attr name: %s has already existed.", private_attr);
    }
  }
  return *this;
}
OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr) {
  static ge::AnyValue empty;
  return PrivateAttr(private_attr, empty);
}
OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr, int64_t private_attr_val) {
  return PrivateAttr(private_attr, ge::AnyValue::CreateFrom<int64_t>(private_attr_val));
}
OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr,
                                                const std::vector<int64_t> &private_attr_val) {
  return PrivateAttr(private_attr, ge::AnyValue::CreateFrom<std::vector<int64_t>>(private_attr_val));
}
OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr, const ge::char_t *private_attr_val) {
  return PrivateAttr(private_attr, ge::AnyValue::CreateFrom<std::string>(private_attr_val));
}
OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr, ge::float32_t private_attr_val) {
  return PrivateAttr(private_attr, ge::AnyValue::CreateFrom<ge::float32_t>(private_attr_val));
}
OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr, bool private_attr_val) {
  return PrivateAttr(private_attr, ge::AnyValue::CreateFrom<bool>(private_attr_val));
}
OpImplRegisterV2 &OpImplRegisterV2::PrivateAttr(const ge::char_t *private_attr,
                                                const std::vector<ge::float32_t> &private_attr_val) {
  return PrivateAttr(private_attr, ge::AnyValue::CreateFrom<std::vector<ge::float32_t>>(private_attr_val));
}
OpImplRegisterV2 &OpImplRegisterV2::OpExecuteFunc(OpImplRegisterV2::OpExecFunc op_execute_func) {
  if (impl_ != nullptr) {
    impl_->functions.op_execute_func = op_execute_func;
  }
  return *this;
}
OpImplRegisterV2 &OpImplRegisterV2::Op2StageExecuteFuncs(OpExecPrepareFunc prepare_func,
                                                         OpExecLaunchFunc launch_func) {
  if (impl_ != nullptr) {
    impl_->functions.op_execute_prepare_func = prepare_func;
    impl_->functions.op_execute_launch_func = launch_func;
  }
  return *this;
}
OpImplRegisterV2 &OpImplRegisterV2::HostInputs(std::initializer_list<int32_t> inputs) {
  if (impl_ != nullptr) {
    impl_->functions.host_inputs = 0UL;
    for (const int32_t index : inputs) {
      if (impl_->functions.SetHostInputs(static_cast<size_t>(index)) != ge::GRAPH_SUCCESS) {
        GELOGE(ge::FAILED, "Failed to set host input for node %s, the input index %d", impl_->op_type.GetString(),
               index);
        return *this;
      }
    }
  }
  return *this;
}

OpImplRegisterV2 &OpImplRegisterV2::InferFormat(InferFormatFunc infer_format_func) {
  if (impl_ != nullptr) {
    impl_->functions.infer_format_func = infer_format_func;
  }
  return *this;
}
}  // namespace gert
