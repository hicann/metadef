/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of 
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "register/op_bin_info.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cstdint>
#include <ctime>
#include <sstream>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <dirent.h>
#include <unistd.h>
#include <dlfcn.h>
#include <elf.h>
#include "op_bin_info_utils.h"
#include "dlog_pub.h"
#include "common/ge_common/debug/ge_log.h"
#include "graph/utils/file_utils.h"

namespace ops {
constexpr uint32_t kOpsFour = 4;
constexpr uint32_t kOpsBufLen = 64;

void CheckCloseDir(DIR *dir, const char *file, int32_t line, const char *func) {
  if (closedir(dir) != 0) {
    GELOGE(ge::FAILED, "closedir failed, [%s:%d]%s", file, line, func);
  }
}

bool FileExist(const std::string &filename) {
  std::ifstream file(filename);
  return file.good();
}

bool DirectoryExists(const std::string &path) {
  GELOGD("Running DirectoryExists.");
  DIR *dir = opendir(path.c_str());
  if (dir != nullptr) {
    CheckCloseDir(dir, __FILE__, __LINE__, __FUNCTION__);
    return true;
  } else {
    return false;
  }
}

std::string GetCurrentTimestamp() {
  const std::time_t now = std::time(nullptr);
  char buf[kOpsBufLen];
  (void) std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", std::localtime(&now));
  return std::to_string(getpid()) + "_" + std::string(buf);
}

bool CheckWritePermission(const std::string &path) {
  GELOGD("Running CheckWritePermission.");
  if (access(path.c_str(), W_OK) != 0) {
    GELOGE(ge::FAILED, "No write permission for the path: %s", path.c_str());
    return false;
  }
  return true;
}

bool CheckBasePathWritePermission(std::string &basePath, const char *resolvedPath,
                                  const std::string &currentTimestamp) {
  std::string ascendWorkPath = std::string(resolvedPath);
  basePath = ascendWorkPath + "/opp/" + currentTimestamp + "/vendors/";
  if (!CheckWritePermission(ascendWorkPath)) {
    return false;
  }
  return true;
}

bool GetBasePathByEnv(std::string& basePath, const char *ascendWorkPathEnv, const std::string& currentTimestamp) {
  GELOGD("Running GetBasePathByEnv.");
  std::string resolvedPath = metadef::RealPath(ascendWorkPathEnv);
  if (resolvedPath.empty()) {
    GELOGE(ge::FAILED, "Invalid ASCEND_WORK_PATH: %s", ascendWorkPathEnv);
    return false;
  }
  return CheckBasePathWritePermission(basePath, resolvedPath.c_str(), currentTimestamp);
}

bool GetBasePath(std::string &basePath, const std::string &opType) {
  GELOGD("Running GetBasePath.");
  const char *ascendWorkPathEnv = getenv("ASCEND_WORK_PATH");
  std::string currentTimestamp = GetCurrentTimestamp();
  if (ascendWorkPathEnv != nullptr) {
    return GetBasePathByEnv(basePath, ascendWorkPathEnv, currentTimestamp);
  } else {
    basePath = "/tmp/opp/" + opType + currentTimestamp + "/vendors/";
    if (!CheckWritePermission("/tmp/")) {
      return false;
    }
  }
  return true;
}

bool CreateDirectory(const std::string &path) {
  GELOGD("Running CreateDirectory.");
  if (DirectoryExists(path)) {
    GELOGD("Directory is existed.");
    return true;
  } else {
    std::string currentPath = path;
    size_t pos = currentPath.find('/', 1);
    while (pos != std::string::npos) {
      std::string subDir = currentPath.substr(0, pos);
      const int32_t status = mkdir(subDir.c_str(), static_cast<mode_t>(S_IRWXU) | static_cast<mode_t>(S_IRWXG));
      if (status == -1 && errno != EEXIST) {
        return false;
      }
      pos = currentPath.find('/', pos + 1U);
    }
    const int32_t status = mkdir(currentPath.c_str(), static_cast<mode_t>(S_IRWXU) | static_cast<mode_t>(S_IRWXG));
    if (status == -1 && errno != EEXIST) {
      return false;
    }
    GELOGD("Running CreateDirectory Succeed.");
    return true;
  }
}

void WriteBinaryFile(const std::string &path, const uint8_t *start, const uint8_t *end) {
  GELOGD("Running WriteBinaryFile.");
  std::ofstream outfile(path, std::ios::binary);
  if (!outfile) {
    GELOGE(ge::FAILED, "Error opening file for writing: %s", path.c_str());
    return;
  }
  std::copy(start, end, std::ostreambuf_iterator<char>(outfile));
  if (!outfile) {
    GELOGE(ge::FAILED, "Error writing file: %s", path.c_str());
    return;
  }
}

std::string GetParentPath(const std::string &path) {
  const size_t pos = path.find_last_of("/\\");
  if (pos == std::string::npos) {
    return "";
  }
  return path.substr(0, pos);
}

bool CreateSymlink(const std::string &targetPath, const std::string &linkPath) {
  GELOGD("Running CreateSymlink.");
  if (!FileExist(targetPath)) {
    GELOGE(ge::FAILED, "The file doesn't exist.");
    return false;
  }
  std::string parentDir = GetParentPath(linkPath);
  if (!DirectoryExists(parentDir)) {
    if (!CreateDirectory(parentDir)) {
      GELOGE(ge::FAILED, "Failed create directory: %s", parentDir.c_str());
      return false;
    }
  }
  if (symlink(targetPath.c_str(), linkPath.c_str()) != 0) {
    GELOGE(ge::FAILED, "Error creating symlink failed.");
    return false;
  }
  GELOGI("Successfully creating symlink: %s", linkPath.c_str());
  return true;
}

bool GetSystemArchitecture(std::string &arch) {
  const char *systemArch = getenv("SYSTEM_PROCESSOR");
  if (systemArch != nullptr) {
    arch = std::string(systemArch);
    return true;
  }
  struct utsname sysInfo;
  if (uname(&sysInfo) == 0) {
    arch = sysInfo.machine;
    return true;
  }
  return false;
}

bool RemoveDirectoryRecursively(const std::string &path) {
  GELOGD("Running RemoveDirectoryRecursively.");
  DIR *dir = opendir(path.c_str());
  if (dir == nullptr) {
    const int32_t currentErr = errno;
    if (currentErr == ENOENT) {
      GELOGW("Directory does not exist: %s", path.c_str());
      return true;
    } else {
      GELOGW("Failed to open directory: %s", path.c_str());
      return false;
    }
  }
  dirent *entry = readdir(dir);
  while (entry != nullptr) {
    std::string entryPath = path + "/" + entry->d_name;
    if (static_cast<int32_t>(entry->d_type) == DT_DIR) {
      if (std::string(entry->d_name) != "." && std::string(entry->d_name) != "..") {
        if (!RemoveDirectoryRecursively(entryPath)) {
          GELOGW("Failed to remove subdirectory: %s", entryPath.c_str());
          CheckCloseDir(dir, __FILE__, __LINE__, __FUNCTION__);
          return false;
        }
        GELOGI("Successfully remove subdirectory: %s", entryPath.c_str());
      }
    } else {
      if (unlink(entryPath.c_str()) != 0) {
        GELOGW("Failed to unlink file: %s", entryPath.c_str());
        CheckCloseDir(dir, __FILE__, __LINE__, __FUNCTION__);
        return false;
      }
      GELOGI("Successfully remove linkpath: %s", entryPath.c_str());
    }
    entry = readdir(dir);
  }
  CheckCloseDir(dir, __FILE__, __LINE__, __FUNCTION__);
  const bool result = (rmdir(path.c_str()) == 0);
  return result;
}

bool IsDirectoryEmpty(const std::string &dirPath) {
  GELOGD("Running check directory empty.");
  DIR *dir = opendir(dirPath.c_str());
  if (dir == nullptr) {
    const int32_t currentErr = errno;
    if (currentErr == ENOENT) {
      GELOGW("Directory is already empty: %s", dirPath.c_str());
      return true;
    } else {
      GELOGE(ge::FAILED, "Failed to open directory: %s", dirPath.c_str());
      return false;
    }
  }
  dirent *entry = readdir(dir);
  while (entry != nullptr) {
    if (strncmp(entry->d_name, ".", 1) != 0 &&
        strncmp(entry->d_name, "..", 2) != 0) {  // 1 is size of ".", 2 is size of ".."
      CheckCloseDir(dir, __FILE__, __LINE__, __FUNCTION__);
      return false;
    }
    entry = readdir(dir);
  }
  CheckCloseDir(dir, __FILE__, __LINE__, __FUNCTION__);
  return true;
}

void DestroyCustomOpRegistry(const std::string &basePath) {
  GELOGD("Running removed directory.");
  const size_t lastSlashPos = (basePath).rfind('/');
  const size_t secondLastSlashPos = (basePath).rfind('/', lastSlashPos - 1U);
  std::string oppBasePath = (basePath).substr(0, secondLastSlashPos);
  if (!RemoveDirectoryRecursively(oppBasePath)) {
    GELOGW("Failed to remove directory: %s", oppBasePath.c_str());
  } else {
    GELOGI("Successfully removed directory: %s", oppBasePath.c_str());
    const std::string oppSubstring = "/opp/";
    const size_t pos = oppBasePath.find(oppSubstring);
    std::string oppDir = oppBasePath.substr(0, pos + (oppSubstring.length()) - 1);
    if (IsDirectoryEmpty(oppDir)) {
      if (rmdir(oppDir.c_str()) != 0) {
        GELOGW("Failed to remove empty opp directory: %s", oppDir.c_str());
      } else {
        GELOGI("Successfully removed empty opp directory: %s", oppDir.c_str());
      }
    }
  }
}

OpBinInfo::OpBinInfo(const std::string &opType, const OpInfo &opInfo) : opType_(opType), opInfo_(opInfo) {
  const bool ret = GetBasePath(basePath_, opType);
  if (ret) {
    GELOGI("Succeed to call OpBinInfo constructor.");
  } else {
    GELOGW("Failed to call OpBinInfo constructor.");
  }
}

OpBinInfo::~OpBinInfo() {
  DestroyCustomOpRegistry(basePath_);
}

uint32_t OpBinInfo::Generate(ge::AscendString *opLibPath, const std::string &targetPath) {
  for (const auto &fileInfo : opInfo_) {
    std::string fileName = std::get<0>(fileInfo).GetString();
    std::string filePath = std::get<1>(fileInfo).GetString();
    const uint8_t *start = std::get<2>(fileInfo);
    const uint8_t *end = std::get<3>(fileInfo);
    std::string fullPath = (basePath_) + "/" + filePath + "/" + fileName;
    if (!CreateDirectory((basePath_) + "/" + filePath)) {
      GELOGE(ge::FAILED, "Failed to create subdirectory: %s", filePath.c_str());
      return 1;
    }
    WriteBinaryFile(fullPath, start, end);
  }
  GELOGI("Get OpLibPath is %s", (basePath_ + opType_).c_str());

  std::string arch = "";
  const bool ret = GetSystemArchitecture(arch);
  if (!ret) {
    GELOGE(ge::FAILED, "Failed to get system architecture name");
    return 1;
  }

  std::string resolvedPath = metadef::RealPath(targetPath.c_str());
  if (resolvedPath.empty()) {
    GELOGE(ge::FAILED, "Failed to resolve libcust_opapi.so path.");
    return 1;
  }
  std::string targetResPath = resolvedPath;
  GELOGI("Resolve libcust_opapi.so path is: %s", targetResPath.c_str());
  std::string opmasterPath =
      basePath_ + opType_ + "/op_impl/ai_core/tbe/op_tiling/lib/linux/" + arch + "/libcust_opmaster_rt2.0.so";
  if (!CreateSymlink(targetResPath, opmasterPath)) {
    GELOGE(ge::FAILED, "Failed to create symlink for libcust_opmaster_rt2.0.so");
    return 1;
  }
  std::string opsprotoPath = basePath_ + opType_ + "/op_proto/lib/linux/" + arch + "/libcust_opsproto_rt2.0.so";
  if (!CreateSymlink(targetResPath, opsprotoPath)) {
    GELOGE(ge::FAILED, "Failed to create symlink for libcust_opsproto_rt2.0.so");
    return 1;
  }
  std::string optilingPath = basePath_ + opType_ + "/op_impl/ai_core/tbe/op_tiling/liboptiling.so";
  if (!CreateSymlink(targetResPath, optilingPath)) {
    GELOGE(ge::FAILED, "Failed to create symlink for liboptiling.so");
    return 1;
  }
  *opLibPath = ge::AscendString((basePath_ + opType_).c_str());
  return 0;
}

bool OpBinInfo::Check(const std::string &path) {
  Elf64_Ehdr ehdr;
  std::ifstream file(path, std::ios::binary);
  const std::streamsize sizeEhdr = static_cast<std::streamsize>(sizeof(ehdr));
  file.read(reinterpret_cast<char *>(&ehdr), sizeEhdr);
  file.seekg(static_cast<std::streamoff>(ehdr.e_phoff));
  std::vector<Elf64_Phdr> phdrs(static_cast<size_t>(ehdr.e_phnum));
  const std::streamsize sizePhnum = static_cast<std::streamsize>(sizeof(Elf64_Phdr));
  if (!file.read(reinterpret_cast<char *>(phdrs.data()), static_cast<long>(ehdr.e_phnum) * sizePhnum)) {
    file.close();
    GELOGE(ge::FAILED, "Failed to read file %s phdrs.", path.c_str());
    return false;
  }
  if (memcmp(ehdr.e_ident,
             "\x7F"
             "ELF",
             kOpsFour) != 0) {
    file.close();
    GELOGE(ge::FAILED, "File %s is not a valid ELF file.", path.c_str());
    return false;
  }
  if (ehdr.e_type != ET_DYN) {
    file.close();
    GELOGE(ge::FAILED, "File %s is not a shared library, the e_type is not ET_DYN.", path.c_str());
    return false;
  }
  for (const auto &phdr : phdrs) {
    if (phdr.p_type == PT_INTERP) {
      file.close();
      GELOGE(ge::FAILED, "File %s is an executable with PT_INTERP segment. Not a shared library.", path.c_str());
      return false;
    }
  }
  file.close();
  return true;
}
}  // namespace ops