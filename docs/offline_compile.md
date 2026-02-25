# METADEF 离线编译指导

## 1. 代码仓下载

在联网环境中，进入[本项目主页](https://gitcode.com/cann/metadef), 通过`下载ZIP`或`clone`按钮，根据指导，完成源码下载。

## 2. 开源第三方软件依赖

metadef在编译时，依赖的第三方开源软件列表如下：

| 开源软件 | 版本 | 下载地址 |
|---|---|---|
| protobuf | 25.1 | [protobuf-25.1.tar.gz](https://gitcode.com/cann-src-third-party/protobuf/releases/download/v25.1/protobuf-25.1.tar.gz) |
| abseil-cpp | 20230802.1 | [abseil-cpp-20230802.1.tar.gz](https://gitcode.com/cann-src-third-party/abseil-cpp/releases/download/20230802.1/abseil-cpp-20230802.1.tar.gz) |
| benchmark | 1.8.3 | [benchmark-1.8.3.tar.gz](https://gitcode.com/cann-src-third-party/benchmark/releases/download/v1.8.3/benchmark-1.8.3.tar.gz) |
| googletest | 1.14.0 | [googletest-1.14.0.tar.gz](https://gitcode.com/cann-src-third-party/googletest/releases/download/v1.14.0/googletest-1.14.0.tar.gz) |
| json | 3.11.3 | [json-3.11.3.tar.gz](https://gitcode.com/cann-src-third-party/json/releases/download/v3.11.3/json-3.11.3.tar.gz) |
| makeself | 2.5.0 | [makeself-release-2.5.0-patch1.tar.gz](https://gitcode.com/cann-src-third-party/makeself/releases/download/release-2.5.0-patch1.0/makeself-release-2.5.0-patch1.tar.gz) |

metadef仓提供[一键式第三方软件下载打包脚本](../scripts/download_third_party_source.sh)，使用方法如下：
```bash
# 在联网环境中，metadef仓根目录执行
cd metadef
bash scripts/download_third_party_source.sh
```
执行成功后会在metadef仓根目录生成`opensource.tar.gz`

## 3. 离线编译

连接至离线环境中，上传[代码仓](#1-代码仓下载)及[三方软件依赖](#2-开源第三方软件依赖)源码至您指定的目录下。下载的为压缩包，还需进行解压。

假定解压后项目结构如下：
```bash
├── metadef                          # metadef仓源码解压后目录
│  ├── api
│  ├── base
│  └── ...
├── opensource                       # 三方软件依赖解压后目录
│  ├── abseil-cpp
│  ├── benchmark
│  └── ...
```

进入代码仓根目录，可通过如下命令进行目录调整：
  ```bash
  # 将opensource目录下的文件移动至metadef仓
  cd metadef
  mkdir output output/third_party
  cp -r ../opensource/* output/third_party
  rm -rf ../opensource
  ```

调整后的项目结构如下：
```bash
├── metadef                          # metadef仓源码解压后目录
│  ├── api
│  ├── base
│  ├── ...
│  └── output                        # 三方软件默认目录
│     └── third_party
│        ├── abseil-cpp
│        ├── benchmark
│        └── ...
```

完成后回到[构建验证-编译](build.md#4-编译)章节，继续进行编译