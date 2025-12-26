/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <dirent.h>
#include "register/op_bin_info.h"
#include "op_bin_info_utils.h"

class OpBinInfoUT : public testing::Test {
protected:
    void SetUp() {}
    void TearDown() {}
};

TEST_F(OpBinInfoUT, OpBinInfoFunc) {
    ops::OpInfo* opInfoTest = new ops::OpInfo();
    opInfoTest->push_back(std::make_tuple(
        "input_tensor",
        "float32",
        reinterpret_cast<const uint8_t*>("data"),
        reinterpret_cast<const uint8_t*>("data" + 1) 
    ));

    ops::OpBinInfo binInfo("add", *opInfoTest);
    ge::AscendString opLibPath = ge::AscendString("Test");
    std::string targetPath = "/tmp/opp/path";
    uint32_t res = binInfo.Generate(&opLibPath, targetPath);
    EXPECT_EQ(res, 1);
    targetPath = "/usr";
    res = binInfo.Generate(&opLibPath, targetPath);
    EXPECT_EQ(res, 0);
    bool checkRes = ops::OpBinInfo::Check(targetPath);
    EXPECT_EQ(checkRes, 0);

    delete opInfoTest;
}

TEST_F(OpBinInfoUT, OpBinInfoFuncTrue) {
    ops::OpInfo* opInfoTest = new ops::OpInfo();
    opInfoTest->push_back(std::make_tuple(
        "input_tensor",
        "float32",
        reinterpret_cast<const uint8_t*>("data"),
        reinterpret_cast<const uint8_t*>("data" + 1)
    ));

    mode_t mode = 0777;
    mkdir("/tmp/opp/", mode);

    ops::OpBinInfo binInfo("add", *opInfoTest);
    ge::AscendString opLibPath = ge::AscendString("Test");
    std::string targetPath = "/tmp/opp/";
    uint32_t res = binInfo.Generate(&opLibPath, targetPath);
    EXPECT_EQ(res, 0);
    targetPath = "/usr";
    res = binInfo.Generate(&opLibPath, targetPath);
    EXPECT_EQ(res, 1);
    bool checkRes = ops::OpBinInfo::Check(targetPath);
    EXPECT_EQ(checkRes, 0);

    delete opInfoTest;
}

TEST_F(OpBinInfoUT, OpBinInfoGetParentPath) {
    std::string path = "1.txt";
    std::string parentDir = ops::GetParentPath(path);
    EXPECT_EQ(parentDir, "");
    path = "/usr/local/1.txt";
    parentDir = ops::GetParentPath(path);
    EXPECT_EQ(parentDir, "/usr/local");
}

TEST_F(OpBinInfoUT, OpBinInfoCreateSymlink) {
    std::string target = "./op_bin_info_unittest11.cc";
    std::string linkpath = "";
    bool ret = ops::CreateSymlink(target, linkpath);
    EXPECT_EQ(ret, false);
    target = "./op_bin_info_unittest.cc";
    linkpath = "/usr/local/1.txt";
    ret = ops::CreateSymlink(target, linkpath);
    EXPECT_EQ(ret, false);
}

TEST_F(OpBinInfoUT, OpBinInfoGetSystemArchitecture) {
    std::string arch;
    bool ret = ops::GetSystemArchitecture(arch);
    EXPECT_EQ(ret, true);
}

TEST_F(OpBinInfoUT, OpBinInfoGetBasePathByEnv) {
    std::string basePath;
    const char *ascendWorkPathEnv = "/usr/local/zzz/ccc";
    std::string currentTimestamp = "111";
    bool ret = ops::GetBasePathByEnv(basePath, ascendWorkPathEnv, currentTimestamp);
    EXPECT_EQ(ret, false);

    std::string basePath1;
    const char *ascendWorkPathEnv1 = "/123/345/321";
    std::string currentTimestamp1 = "111";
    bool ret1 = ops::GetBasePathByEnv(basePath1, ascendWorkPathEnv1, currentTimestamp1);
    EXPECT_EQ(ret1, false);
    ret1 = ops::CheckBasePathWritePermission(basePath1, ascendWorkPathEnv1, currentTimestamp1);
    EXPECT_EQ(ret1, false);
}

TEST_F(OpBinInfoUT, OpBinInfoRemoveDirectory) {
    std::string entryPath = "/123/345";
    bool ret = ops::RemoveDirectoryRecursively(entryPath);
    EXPECT_EQ(ret, true);

    entryPath = "/tmp/123/345";
    mode_t mode = 0444;
    mkdir("/tmp/123/345", mode);
    ret = ops::RemoveDirectoryRecursively(entryPath);
    EXPECT_EQ(ret, true);
}

TEST_F(OpBinInfoUT, OpBinInfoIsDirectoryEmpty) {
    std::string entryPath = "/123/345";
    bool ret = ops::IsDirectoryEmpty(entryPath);
    EXPECT_EQ(ret, true);

    entryPath = "/tmp/123/345";
    mode_t mode = 0000;
    mkdir("/tmp/123/345", mode);
    ret = ops::IsDirectoryEmpty(entryPath);
    EXPECT_EQ(ret, true);
}

TEST_F(OpBinInfoUT, OpBinInfoWriteBinaryFileNoFile) {
    std::string Path = "/no_file";
    const uint8_t* start = nullptr;
    const uint8_t* end = nullptr;
    EXPECT_NO_THROW(ops::WriteBinaryFile(Path, start, end));
}

TEST_F(OpBinInfoUT, RemoveDirectoryRecursivelyFailedOpen) {
    system("mkdir /tmp/restricted_dir");
    std::string Path = "/tmp/restricted_dir";
    EXPECT_EQ(ops::RemoveDirectoryRecursively(Path), true);
    EXPECT_EQ(ops::IsDirectoryEmpty(Path), true);
    system("mkdir /tmp/test");
    system("touch /tmp/test/file.txt");
    Path = "/tmp/test";
    EXPECT_EQ(ops::IsDirectoryEmpty(Path), false);
    system("rm -rf /tmp/restricted_dir");
    system("rm -rf /tmp/test");
}

TEST_F(OpBinInfoUT, GetSystemArchitecture) {
    std::string arch;
    setenv("SYSTEM_PROCESSOR", "x86_64", 1);
    bool ret = ops::GetSystemArchitecture(arch);
    EXPECT_EQ(ret, true);
    EXPECT_EQ(arch, "x86_64");
    unsetenv("SYSTEM_PROCESSOR");
}

TEST_F(OpBinInfoUT, CheckCloseDir) {
    const std::string testDir = "/tmp/test_closedir_double_close";
    system(("mkdir -p " + testDir).c_str());
    DIR* dir = opendir(testDir.c_str());
    ASSERT_NE(dir, nullptr) << "Failed to open directory: " << testDir;
    int fd = dirfd(dir);
    ASSERT_NE(fd, -1) << "Failed to get directory file descriptor";
    close(fd);
    EXPECT_NO_THROW(ops::CheckCloseDir(dir, __FILE__, __LINE__, __FUNCTION__));
    system(("rm -rf " + testDir).c_str());
}