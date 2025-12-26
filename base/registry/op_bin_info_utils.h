/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef REGISTER_OP_BIN_INFO_UTILS_H
#define REGISTER_OP_BIN_INFO_UTILS_H

#include <string>
#include <dirent.h>

namespace ops {
bool FileExist(const std::string& filename);
bool DirectoryExists(const std::string& path);
std::string GetCurrentTimestamp();
bool CheckWritePermission(const std::string& path);
bool GetBasePathByEnv(std::string& basePath, const char *ascendWorkPathEnv, std::string& currentTimestamp);
bool GetBasePath(std::string& basePath, const std::string& opType);
bool CreateDirectory(const std::string& path);
void WriteBinaryFile(const std::string& path, const uint8_t* start, const uint8_t* end);
std::string GetParentPath(const std::string& path);
bool CreateSymlink(const std::string& targetPath, const std::string& linkPath);
bool GetSystemArchitecture(std::string& arch);
bool RemoveDirectoryRecursively(const std::string& path);
bool IsDirectoryEmpty(const std::string& dirPath);
void CheckCloseDir(DIR* dir, const char* file, int32_t line, const char* func);
void DestroyCustomOpRegistry(std::string& basePath);
bool CheckBasePathWritePermission(std::string &basePath, const char *resolvedPath, const std::string &currentTimestamp);
}
#endif
