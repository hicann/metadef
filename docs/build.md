# 源码构建

## 1. 环境准备

在源码编译前，请先完成基础环境搭建。具体操作请参见[快速安装](quick_install.md)。

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
> 若您的编译环境无法访问网络，请确保已经完成了[4.3 编译](#4.3-编译)章节中的[离线编译指导](offline_compile.md)。

执行本地验证前，请确保已完成[安装依赖](#4.2-安装依赖)，并设置[环境变量](#3.-环境变量配置)。

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