# 源码构建

### 1. 安装依赖

metadef 支持源码编译。在源码编译前，请根据实际情况选择 **方式一（手动安装）** 或 **方式二（Docker容器）** 完成基础环境准备，然后进行 **CANN Toolkit** 的安装。

#### 方式一：手动安装依赖

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


#### 方式二：使用 Docker 镜像

  **配套 X86 构建镜像地址**：`swr.cn-north-4.myhuaweicloud.com/ci_cann/ubuntu20.04.05_x86:lv1_latest`
  
  **配套 ARM 构建镜像地址**：`swr.cn-north-4.myhuaweicloud.com/ci_cann/ubuntu20.04.05_arm:lv1_latest`

  以下是推荐的使用方式，可供参考:

  ```shell
  image=${根据本地机器架构类型从上面选择配套的构建镜像地址}

  # 1. 拉取配套构建镜像
  docker pull ${image}
  # 2. 创建容器
  docker run --name env_for_ge_build --cap-add SYS_PTRACE -d -it ${image} /bin/bash
  # 3. 启动容器
  docker start env_for_ge_build
  # 4. 进入容器
  docker exec -it env_for_ge_build /bin/bash
  ```
  完成后可以进入[安装软件包](#2-安装软件包)章节。

  > [!NOTE]说明
  > - `--cap-add SYS_PTRACE`：创建Docker容器时添加`SYS_PTRACE`权限，以支持[本地验证](#5-本地验证ut)时的内存泄漏检测功能。
  > - 更多 docker 选项介绍请通过 `docker --help` 查询。

### 2. 安装软件包

#### 步骤一：安装社区版CANN Toolkit包

根据实际环境，下载对应`Ascend-cann-toolkit_${cann_version}_linux-${arch}.run`包，下载链接为[toolkit x86_64包](https://ascend.devcloud.huaweicloud.com/cann/run/software/8.5.0-beta.1/x86_64/Ascend-cann-toolkit_8.5.0-beta.1_linux-x86_64.run)、[toolkit aarch64包](https://ascend.devcloud.huaweicloud.com/cann/run/software/8.5.0-beta.1/aarch64/Ascend-cann-toolkit_8.5.0-beta.1_linux-aarch64.run)。

  ```bash
  # 确保安装包具有可执行权限
  chmod +x Ascend-cann-toolkit_${cann_version}_linux-${arch}.run 
  # 安装命令(其中--install-path为可选)
  ./Ascend-cann-toolkit_${cann_version}_linux-${arch}.run --full --install-path=${install_path}
  ```

  -   `${cann_version}`：表示CANN包版本号。
  -   `${arch}`：表示CPU架构，如`aarch64`、`x86_64`。
  -   `${install_path}`：表示指定安装路径，可选，默认安装在/usr/local/Ascend目录，指定路径安装时，指定的路径权限需设置为755。

#### 步骤二：配置环境变量

根据实际场景，选择合适的命令：

  ```bash
  # 默认路径安装，以root用户为例（非root用户，将/usr/local替换为${HOME}） 
  source /usr/local/Ascend/cann/set_env.sh
  # 指定路径安装 
  source ${install_path}/cann/set_env.sh
  ```

### 3. 下载源码

开发者可通过如下命令下载本仓源码：

  ```bash
  # 下载项目源码，以master分支为例 
  git clone https://gitcode.com/cann/metadef.git
  ```

### 4. 编译

`metadef`提供一键式编译能力，可通过如下命令进行编译：

```shell
bash build.sh
```

更多编译参数可以通过`bash build.sh -h`查看，编译成功后，会在`build_out`目录下生成`cann-metadef_<version>_linux.<arch>.run`软件包。

- `<version>`表示版本号。
- `<arch>`表示操作系统架构，取值包括x86_64与aarch64。

### 5. 本地验证（UT）

执行本地验证前，请确保已完成[安装依赖](#1-安装依赖)，并设置[环境变量](#步骤二配置环境变量)。

`metadef`仓提供一键式编译执行供开发者测试，详细配置可通过`bash tests/run_test.sh -h`查看。

```bash
bash tests/run_test.sh -u
```

### 6. 安装与卸载

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