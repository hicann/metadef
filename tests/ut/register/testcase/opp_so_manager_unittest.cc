/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <gtest/gtest.h>

#include "register/opp_so_manager.h"
#include "common/plugin/plugin_manager.h"
#include "register/op_impl_space_registry.h"
#include "registry/opp_package_utils.h"
#include "tests/depends/mmpa/src/mmpa_stub.h"

using namespace testing;
using namespace std;

namespace ge {
namespace {
const char *const kEnvName = "ASCEND_OPP_PATH";
const char *const kAscendHomePath = "ASCEND_HOME_PATH";
const string kInner = "built-in";
const string kx86OpTilingPath = "/op_impl/ai_core/tbe/op_tiling/lib/linux/x86_64/";
const string kx86OpHostPath = "/op_impl/ai_core/tbe/op_host/lib/linux/x86_64/";
const string kx86OpProtoPath = "/op_proto/lib/linux/x86_64/";
const string kx86OpGraphPath = "/op_graph/lib/linux/x86_64/";

void SetRt2OpImplSo(std::set<std::string> &temp_paths, bool flag = true) {
  std::string opp_path = "./";
  mmSetEnv(kEnvName, opp_path.c_str(), 1);

  std::string path ="./opp";
  temp_paths.insert(path);
  system(("mkdir -p " + path).c_str());
  path += "/scene.info";
  system(("touch " + path).c_str());
  system(("echo 'os=linux' > " + path).c_str());
  system(("echo 'arch=x86_64' >> " + path).c_str());

  std::string path1 = "./../../opp";
  temp_paths.insert(path1);
  system(("mkdir -p " + path1).c_str());
  path1 += "/scene.info";
  system(("touch " + path1).c_str());
  system(("echo 'os=linux' > " + path1).c_str());
  system(("echo 'arch=x86_64' >> " + path1).c_str());

  system("pwd");
  system(("realpath " + path).c_str());
  system(("realpath " + path1).c_str());

  std::string path_vendors = opp_path + "vendors";
  temp_paths.insert(path_vendors);
  std::string path_config = path_vendors + "/config.ini";
  system(("mkdir -p " + path_vendors).c_str());
  system(("echo 'load_priority=customize' > " + path_config).c_str());

  std::string opmaster_rt2_path = opp_path + kInner + kx86OpTilingPath;
  temp_paths.insert(opp_path + kInner);
  std::string command = "mkdir -p " + opmaster_rt2_path;
  system(command.c_str());
  GELOGD("command: %s", command.c_str());
  system(("realpath " + opmaster_rt2_path).c_str());
  if (flag) {
    opmaster_rt2_path += "libopmaster_success_rt2.0.so";
    command = "touch " + opmaster_rt2_path;
    GELOGD("command: %s", command.c_str());
    system(("realpath " + opmaster_rt2_path).c_str());
    system(command.c_str());
  } else {
    opmaster_rt2_path += "libopmaster_error_rt2.0.so";
    command = "touch " + opmaster_rt2_path;
    GELOGD("command: %s", command.c_str());
    system(("realpath " + opmaster_rt2_path).c_str());
    system(command.c_str());
  }
}

void SetOpHostAndGraphSo(std::set<std::string> &temp_paths, bool flag = true) {
  std::string opp_path = "./";
  mmSetEnv(kEnvName, opp_path.c_str(), 1);

  std::string path ="./opp";
  temp_paths.insert(path);
  system(("mkdir -p " + path).c_str());
  path += "/scene.info";
  system(("touch " + path).c_str());
  system(("echo 'os=linux' > " + path).c_str());
  system(("echo 'arch=x86_64' >> " + path).c_str());

  std::string path1 = "./../../opp";
  temp_paths.insert(path1);
  system(("mkdir -p " + path1).c_str());
  path1 += "/scene.info";
  system(("touch " + path1).c_str());
  system(("echo 'os=linux' > " + path1).c_str());
  system(("echo 'arch=x86_64' >> " + path1).c_str());

  system("pwd");
  system(("realpath " + path).c_str());
  system(("realpath " + path1).c_str());

  std::string path_vendors = opp_path + "vendors";
  temp_paths.insert(path_vendors);
  std::string path_config = path_vendors + "/config.ini";
  system(("mkdir -p " + path_vendors).c_str());
  system(("echo 'load_priority=customize' > " + path_config).c_str());

  std::string path_custom_tiling = path_vendors + ("/customize" + kx86OpTilingPath);
  system(("mkdir -p " + path_custom_tiling).c_str());
  system(("touch " + path_custom_tiling + "libopmaster_customize.so").c_str());

  std::string path_custom_proto = path_vendors +  ("/customize" + kx86OpProtoPath);
  system(("mkdir -p " + path_custom_proto).c_str());
  system(("touch " + path_custom_proto + "libopsproto_customize.so").c_str());

  std::string opmaster_path = opp_path + kInner + kx86OpTilingPath;
  temp_paths.insert(opp_path + kInner);
  std::string command = "mkdir -p " + opmaster_path;
  system(command.c_str());
  GELOGD("command: %s", command.c_str());
  system(("realpath " + opmaster_path).c_str());

  std::string opmaster_rt_path = opmaster_path + "libopmaster_success_rt.so";
  command = "touch " + opmaster_rt_path;
  GELOGD("command: %s", command.c_str());
  system(("realpath " + opmaster_rt_path).c_str());
  system(command.c_str());

  std::string opmaster_rt2_path = opmaster_path + "libopmaster_success_rt2.0.so";
  command = "touch " + opmaster_rt2_path;
  GELOGD("command: %s", command.c_str());
  system(("realpath " + opmaster_rt2_path).c_str());
  system(command.c_str());

  std::string op_host_path = opp_path + kInner + kx86OpHostPath;
  temp_paths.insert(opp_path + kInner);
  command = "mkdir -p " + op_host_path;
  system(command.c_str());
  GELOGD("command: %s", command.c_str());
  system(("realpath " + op_host_path).c_str());

  op_host_path += "libophost_success.so";
  command = "touch " + op_host_path;
  GELOGD("command: %s", command.c_str());
  system(("realpath " + op_host_path).c_str());
  system(command.c_str());

  std::string op_proto_path = opp_path + kInner + kx86OpProtoPath;
  temp_paths.insert(opp_path + kInner);
  command = "mkdir -p " + op_proto_path;
  system(command.c_str());
  GELOGD("command: %s", command.c_str());
  system(("realpath " + op_proto_path).c_str());

  std::string op_proto_rt_path = op_proto_path + "libopsproto_success_rt.so";
  command = "touch " + op_proto_rt_path;
  GELOGD("command: %s", command.c_str());
  system(("realpath " + op_proto_rt_path).c_str());
  system(command.c_str());

  std::string op_proto_rt2_path =op_proto_path + "libopsproto_success_rt2.0.so";
  command = "touch " + op_proto_rt2_path;
  GELOGD("command: %s", command.c_str());
  system(("realpath " + op_proto_rt2_path).c_str());
  system(command.c_str());

  std::string op_graph_path = opp_path + kInner + kx86OpGraphPath;
  temp_paths.insert(opp_path + kInner);
  command = "mkdir -p " + op_graph_path;
  system(command.c_str());
  GELOGD("command: %s", command.c_str());
  system(("realpath " + op_graph_path).c_str());

  op_graph_path += "libopgraph_success_rt2.0.so";
  command = "touch " + op_graph_path;
  GELOGD("command: %s", command.c_str());
  system(("realpath " + op_graph_path).c_str());
  system(command.c_str());
}

void RemoveTempPaths(const std::set<std::string> &temp_paths) {
  for (const auto &path : temp_paths) {
    system(("rm -rf " + path).c_str());
  }
}

std::string CreateBuiltInSplitAndUpgradedSo() {
  std::string model_path = __FILE__;
  std::string opp_path = model_path + "opp/";
  system(("mkdir -p " + opp_path).c_str());
  mmSetEnv(kEnvName, opp_path.c_str(), 1);

  std::string path ="./opp";
  system(("mkdir -p " + path).c_str());
  path += "/scene.info";
  system(("touch " + path).c_str());
  system(("echo 'os=linux' > " + path).c_str());
  system(("echo 'arch=x86_64' >> " + path).c_str());

  std::string path1 = "./../../opp";
  system(("mkdir -p " + path1).c_str());
  path1 += "/scene.info";
  system(("touch " + path1).c_str());
  system(("echo 'os=linux' > " + path1).c_str());
  system(("echo 'arch=x86_64' >> " + path1).c_str());

  std::string proto_path = opp_path + "built-in/op_proto/lib/linux/x86_64";
  system(("mkdir -p " + proto_path).c_str());
  proto_path += "/a_rt.so";
  system(("touch " + proto_path).c_str());
  system(("echo 'ops proto 123' > " + proto_path).c_str());

  std::string tiling_path = opp_path + "built-in/op_impl/ai_core/tbe/op_tiling/lib/linux/x86_64";
  system(("mkdir -p " + tiling_path).c_str());
  tiling_path += "/b_rt.so";
  system(("touch " + tiling_path).c_str());
  system(("echo 'op tiling 456' > " + tiling_path).c_str());

  std::string home_path = opp_path.substr(0, opp_path.rfind("/opp/"));
  mmSetEnv(kAscendHomePath, home_path.c_str(), 1);
  std::string opp_latest_path = home_path + "/opp_latest/";
  system(("mkdir -p " + opp_latest_path).c_str());
  system(("cp -rf " + opp_path + "built-in " + opp_latest_path).c_str());

  return opp_path;
}

size_t g_impl_num = 3;
size_t g_ct_impl_num = 2;
const char *type[] = {"Add_0", "Add_1", "Add_2"};
size_t GetRegisteredOpNum() { return g_impl_num; }
size_t GetRegisteredOpCtNum() { return g_ct_impl_num; }
uint32_t GetOpImplFunctions(TypesToImpl *impl, size_t g_impl_num) {
  gert::OpImplKernelRegistry::OpImplFunctions funcs;
  for (size_t i = 0; i < g_impl_num; ++i) {
    funcs.tiling = (gert::OpImplRegisterV2::TilingKernelFunc) (0x10 + i);
    funcs.infer_shape = (gert::OpImplRegisterV2::InferShapeKernelFunc) (0x20 + i);
    impl[i].op_type = type[i];
    impl[i].funcs = funcs;
  }
  return 0;
}
uint32_t GetOpCtImplFunctions(TypesToCtImpl *impl, size_t g_ct_impl_num) {
  gert::OpCtImplKernelRegistry::OpCtImplFunctions funcs;
  for (size_t i = 0; i < g_ct_impl_num; ++i) {
    funcs.calc_op_param = (gert::OpCtImplKernelRegistry::OpCalcParamKernelFunc) (0x10 + i);
    funcs.gen_task = (gert::OpCtImplKernelRegistry::OpGenTaskKernelFunc) (0x20 + i);
    impl[i].op_type = type[i];
    impl[i].funcs = funcs;
  }
  return 0;
}

void *mock_handle = nullptr;
class MockMmpa : public ge::MmpaStubApi {
 public:
  void *DlSym(void *handle, const char *func_name) override {
    if (std::string(func_name) == "GetRegisteredOpNum") {
      return (void *) &GetRegisteredOpNum;
    } else if (std::string(func_name) == "GetOpImplFunctions") {
      return (void *) &GetOpImplFunctions;
    }
    if (std::string(func_name) == "GetRegisteredOpCtNum") {
      return (void *) &GetRegisteredOpCtNum;
    } else if (std::string(func_name) == "GetOpCtImplFunctions") {
      return (void *) &GetOpCtImplFunctions;
    }
    return nullptr;
  }
  void *DlOpen(const char *fileName, int32_t mode) override {
    if (mock_handle == nullptr) {
      return nullptr;
    }
    return (void *) mock_handle;
  }
  int32_t DlClose(void *handle) override {
    return 0L;
  }
};
} // namespace

class OppSoManagerUT : public testing::Test {
 protected:
  void SetUp() {}

  void TearDown() {
    gert::OpImplRegistryHolderManager::GetInstance().ClearOpImplRegistries();
    gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr);
    gert::DefaultOpImplSpaceRegistry::GetInstance().SetDefaultSpaceRegistry(nullptr, OppImplVersion::kOppKernel);
    ge::MmpaStub::GetInstance().Reset();
  }
};

TEST_F(OppSoManagerUT, LoadOppSo_fail) {
  std::set<std::string> temp_paths;
  SetRt2OpImplSo(temp_paths, false);
  OppSoManager::GetInstance().LoadOppPackage();

  auto space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry();
  // 之前是如果load so失败，不会造SpaceRegistry，修改过后，SpaceRegistry在LoadSo之前就会造好
  EXPECT_NE(space_registry, nullptr);
  RemoveTempPaths(temp_paths);
}

TEST_F(OppSoManagerUT, LoadOppSo) {
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 1;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  std::set<std::string> temp_paths;
  SetRt2OpImplSo(temp_paths);
  OppSoManager::GetInstance().LoadOppPackage();

  auto space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry();
  EXPECT_NE(space_registry, nullptr);
  RemoveTempPaths(temp_paths);
}

TEST_F(OppSoManagerUT, LoadOppHostAndGraphSo) {
  mock_handle = (void *) 0xffffffff;
  g_impl_num = 1;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  std::set<std::string> temp_paths;
  SetOpHostAndGraphSo(temp_paths);
  OppSoManager::GetInstance().LoadOppPackage();

  auto space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry();
  EXPECT_NE(space_registry, nullptr);
  RemoveTempPaths(temp_paths);
}

TEST_F(OppSoManagerUT, LoadSplitAndUpgradedOppSo_suc) {
  mock_handle = (void *) 0xfffffff0;
  g_impl_num = 1;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  std::vector<std::string> paths;
  const auto &opp_path = CreateBuiltInSplitAndUpgradedSo();
  gert::OppPackageUtils::LoadAllOppPackage();
  auto space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry();
  EXPECT_NE(space_registry, nullptr);
  space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry(OppImplVersion::kOppKernel);
  // 会判断opp_kernel_version
  EXPECT_NE(space_registry, nullptr);
  RemoveTempPaths({opp_path});
}

TEST_F(OppSoManagerUT, LoadOpsProtoPackage_suc) {
  mock_handle = (void *) 0xfffffff0;
  g_impl_num = 1;
  ge::MmpaStub::GetInstance().SetImpl(std::make_shared<MockMmpa>());
  std::vector<std::string> paths;
  const auto &opp_path = CreateBuiltInSplitAndUpgradedSo();
  OppSoManager::GetInstance().LoadOpsProtoPackage();
  auto space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry();
  EXPECT_NE(space_registry, nullptr);
  space_registry = gert::DefaultOpImplSpaceRegistry::GetInstance().GetDefaultSpaceRegistry(OppImplVersion::kOppKernel);
  EXPECT_NE(space_registry, nullptr);
}
}  // namespace ge
