# metadef

## 🔥Latest News

- [2025/12/26] metadef项目首次上线。

## 🚀概述

`metadef`，即昇腾元数据定义，用于定义相关数据结构以及对外接口。

## 🔍目录结构说明

本源码仓的关键目录结构如下所示：

```angular2html
metadef
├── base
|   ├── common                          #  算子包管理相关实现
|   ├── context_builder                 #  构建算子执行上下文相关实现
|   ├── device_registry                 #  算子Tiling下沉注册相关实现
|   ├── registry                        #  算子注册相关实现
|   ├── runtime                         #  算子执行接口相关实现
|   ├── type                            #  基础数据类型相关实现
|   ├── utils                           #  工具类相关实现
├── cmake                               #  cmake公共脚本
├── docs                                #  关联文档目录
├── error_manager                       #  相关错误码定义
├── inc
|   ├── base                            #  一些基础数据结构头文件
|   ├── common                          #  一些公共头文件
|   ├── exe_graph                       #  执行图头文件
|   ├── external                        #  对外发布的头文件(保证兼容性)
|   ├── graph                           #  图接口相关头文件
|   ├── register                        #  算子注册头文件
├── pkg_inc                             #  包间接口文件目录
├── scripts                             #  打包脚本文件目录
├── tests                               #  开发者测试目录
```

## ⚡️快速开始

若您希望快速构建本项目，请访问[源码构建](docs/build.md)，了解如何编译、安装本项目，并进行基础测试验证。

## 📖 学习教程

若您希望深入了解本仓的接口并修改源码，请访问[API参考](docs/api/README.md)获取详细教程。

## 📝相关信息

- [贡献指南](CONTRIBUTING.md)
- [安全声明](SECURITY.md)
- [许可证](LICENSE)