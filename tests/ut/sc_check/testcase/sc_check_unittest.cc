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
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
namespace {
// 这个函数现在会递归地调用自身来处理子目录
void countFilesAndDirs(const fs::path& dirPath, int threshold = 50) {
  int fileCount = 0;
  int dirCount = 0;

  // 计算当前目录下的文件和子目录数量
  for (const auto& entry : fs::directory_iterator(dirPath)) {
    if (fs::is_directory(entry.status())) {
      dirCount++;
      // 递归调用以检查子目录
      countFilesAndDirs(entry.path());
    } else if (fs::is_regular_file(entry.status())) {
      fileCount++;
    }
  }
  if (fileCount + dirCount > threshold) {
    throw std::runtime_error("Directory " + dirPath.string() + " exceeds the limit of 50 files and directories.");
  }
}
}
namespace SC{
/*
 * 线上SC非拦截项里面会要求每个目录的直属子目录和文件之和不超过50
 * 因此添加这个ut来看护代码仓目录
 */
TEST(FileCount, CheckFileCount) {
  fs::path dirPath1(std::string(TOP_DIR).append("/inc"));
  EXPECT_NO_THROW(countFilesAndDirs(dirPath1));

  fs::path dirPath5(std::string(TOP_DIR).append("/base"));
  EXPECT_NO_THROW(countFilesAndDirs(dirPath5));
}
}
