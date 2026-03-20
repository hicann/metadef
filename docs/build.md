# 源码构建

## 1. 环境准备

本项目支持源码编译，在源码编译前，需要确保已经安装CANN软件（Ascend-cann-toolkit）。

软件安装方式请根据如下描述进行选择：

| 安装方式       | 说明                                                         | 使用场景                                                     |
| :------------- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| 使用WebIDE安装 | WebIDE可提供在线直接运行的昇腾环境，当前可提供单机算力，默认安装最新商发版CANN软件包（目前是CANN 8.5.0）和固件/驱动包。 | 适用于没有昇腾设备的开发者。                                 |
| 手动安装软件包 | -                                                            | 适用有昇腾设备，想体验手动安装CANN包或体验最新master分支能力的开发者。 |

### 方式一：使用WebIDE安装

对于无环境的用户，可直接使用WebIDE开发平台，即“**算子一站式开发平台**”，该平台为您提供在线可直接运行的昇腾环境，环境中已安装必备的软件包，无需手动安装。更多关于开发平台的介绍请参考[LINK](https://gitcode.com/org/cann/discussions/54)。

1. 进入开源项目，单击“`云开发`”按钮，使用已认证过的华为云账号登录。若未注册或认证，请根据页面提示进行注册和认证。

   <img src="./figures/cloudIDE.png" alt="云平台"  width="750px" height="90px">

2. 根据页面提示创建并启动云开发环境，单击“`连接 > WebIDE `”进入算子一站式开发平台，开源项目的资源默认在`/mnt/workspace`目录下。

   <img src="./figures/webIDE.png" alt="云平台"  width="1000px" height="150px">

### 方式二：手动安装软件包

**场景1：已发布版本**

如果您想体验**官网正式发布的CANN包**能力，请访问[CANN官网下载中心](https://www.hiascend.com/cann/download)，选择对应版本CANN软件包（仅支持CANN 8.5.0及后续版本）进行安装。

**场景2：master版本**

如果您想体验**master分支最新能力**，单击[下载链接](https://ascend.devcloud.huaweicloud.com/artifactory/cann-run-mirror/software/master)获取获取软件包，按照如下步骤进行安装。更多安装指导请参考[CANN软件安装指南](https://www.hiascend.com/document/redirect/CannCommunityInstWizard)。安装社区版CANN toolkit包方法如下：

```bash
# 确保安装包具有可执行权限
chmod +x Ascend-cann-toolkit_${cann_version}_linux-${arch}.run
# 安装命令
./Ascend-cann-toolkit_${cann_version}_linux-${arch}.run --install --install-path=${install_path}
```

- `${cann_version}`：表示CANN包版本号。
- `${arch}`：表示CPU架构，如`aarch64`、`x86_64`。
- `${install_path}`：表示指定安装路径，需要与toolkit包安装在相同路径，root用户默认安装在`/usr/local/Ascend`目录。

## 2. 环境验证

安装完CANN包后，需验证环境是否正常。

```bash
# 查看CANN Toolkit的version字段提供的版本信息（默认路径安装），<arch>表示CPU架构（aarch64或x86_64）。WebIDE场景下，请将/usr/local替换为/home/developer。
cat /usr/local/Ascend/cann/<arch>-linux/ascend_toolkit_install.info
```

## 3. 环境变量配置

根据实际场景，选择合适的命令：

```bash
  # 默认路径安装，以root用户为例（非root用户，将/usr/local替换为${HOME}） 
  source /usr/local/Ascend/cann/set_env.sh
  # 指定路径安装
  source ${install_path}/cann/set_env.sh
```

## 4. 源码编译

### 4.1 下载源码

开发者可通过如下命令下载本仓源码：

  ```bash
  # 下载项目源码，以master分支为例 
  git clone https://gitcode.com/cann/metadef.git
  ```

### 4.2 安装依赖

#### 安装依赖

   以下所列为源码编译用到的依赖，请注意版本要求。

- GCC >= 7.3.x

- Python3 >= 3.9.x

- CMake >= 3.16.0 （建议使用3.20.0版本）

- ccache/cov/asan

- graph-easy(可选)

  ```bash
  # Ubuntu/Debian操作系统安装命令示例如下，其他操作系统请自行安装
  # asan以gcc 7.5.0版本为例，其他版本请安装对应版本asan
  sudo apt-get install cmake ccache lcov libasan4 libgraph-easy-perl
  ```

#### 检查编译环境

安装完成后，建议执行环境检查脚本，确认当前环境是否满足编译要求。

```bash
bash scripts/check_env.sh
```

检查结果说明如下：

| 状态          | 含义                         | 处理建议                 |
| ------------- | ---------------------------- | ------------------------ |
| **[PASS]**    | 检查通过                     | 无需处理                 |
| **[WARNING]** | 非关键依赖缺失或版本存在偏差 | 建议修复，不影响核心编译 |
| **[ERROR]**   | 关键依赖缺失或版本不兼容     | 必须修复，否则无法编译   |

> [!NOTE] 注意
> 环境检查脚本中所有检查项和版本约束严格来源于 docs/build.md，如 build.md 更新，请同步修改[脚本](../scripts/check_env.sh)。

### 4.3 编译

> [!NOTE] 注意
> 若您的编译环境无法访问网络，由于无法通过`git`指令下载代码，须在联网环境中下载源码及三方库依赖后，手动上传至目标环境，参见[离线编译指导](offline_compile.md)。 
> 若您的编译环境可以访问网络，通过`git`指令下载代码后，编译过程中将自动下载开源第三方软件。

若您的编译环境可以访问网络，或已经完成[离线编译指导](offline_compile.md)，`metadef`提供一键式编译能力，可通过如下命令进行编译：

```shell
bash build.sh
```

更多编译参数可以通过`bash build.sh -h`查看，编译成功后，会在`build_out`目录下生成`cann-metadef_<version>_linux.<arch>.run`软件包。

- `<version>`表示版本号。
- `<arch>`表示操作系统架构，取值包括x86_64与aarch64。

### 4.3. 本地验证（UT）

> [!NOTE] 注意
> 若您的编译环境无法访问网络，请确保已经完成了[4. 编译](#4-编译)章节中的[离线编译指导](offline_compile.md)。

执行本地验证前，请确保已完成[安装依赖](#1-安装依赖)，并设置[环境变量](#步骤二配置环境变量)。

`metadef`仓提供一键式编译执行供开发者测试，详细配置可通过`bash tests/run_test.sh -h`查看。

```bash
bash tests/run_test.sh -u
```

### 4.4 安装与卸载

- 安装

  编译完成后，生成metadef软件包放在`./build_out`目录下，可通过如下命令安装编译生成的metadef软件包。

  ```shell
  ./cann-metadef_<version>_linux.<arch>.run --full --install-path=${install_path}
  ```

  使用root用户、默认路径安装场景：`${install_path}`为`/usr/local/Ascend`；使用非root用户、默认路径安装场景：`${install_path}`为`$HOME/Ascend`。

- 卸载

  若您想卸载安装的自定义`metadef`软件包，可执行如下命令：

  ```shell
  ./cann-metadef_<version>_linux.<arch>.run --uninstall --install-path=${install_path}
  ```