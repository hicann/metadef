# Environment Deployment

## 1. Environment Preparation

This project supports source code compilation. Before compiling from source, ensure CANN software (Ascend-cann-toolkit and Ascend-cann-ops (optional)) is installed. If running samples, NPU driver and firmware also need to be installed.

Select software installation method according to the following description:

| Installation Method | Description | Usage Scenario |
| :-- | :-- | :-- |
| Using WebIDE Installation | WebIDE provides an online directly runnable Ascend environment. Currently provides single-machine computing power, default installation of latest commercial release CANN software package (currently CANN 8.5.0) and firmware/driver package. | Suitable for developers without Ascend devices. |
| Docker | Docker image is an efficient deployment method, one-click deployment of CANN package and essential dependencies.<br>Currently OS only supports Ubuntu. | Suitable for developers with Ascend devices who need to quickly set up environment. |
| Manual Software Package Installation | - | Suitable for developers with Ascend devices who want to experience manual CANN package installation or experience latest master branch capabilities. |

### Method 1: Using WebIDE Installation

For users without an environment, directly use the WebIDE development platform, namely "**Operator One-Stop Development Platform**". This platform provides an online directly runnable Ascend environment with essential software packages already installed, no manual installation needed. For more platform introduction, refer to [LINK](https://gitcode.com/org/cann/discussions/54).

1. Enter the open source project, click the "`Cloud Development`" button, and log in with a certified Huawei Cloud account. If not registered or certified, follow page prompts for registration and certification.

   <img src="../figures/cloudIDE.png" alt="Cloud Platform"  width="750px" height="90px">

2. Follow page prompts to create and start cloud development environment, click "`Connect > WebIDE`" to enter the operator one-stop development platform. Open source project resources default in `/mnt/workspace` directory.

   <img src="../figures/webIDE.png" alt="Cloud Platform"  width="1000px" height="150px">

### Method 2: Docker Deployment

For developers not dependent on Ascend devices, if you want to quickly set up compilation build environment, use Docker image deployment.

> **Note**: Image file is relatively large, download takes some time, please wait patiently. For docker command option introduction, query through `docker --help`.

1.**Install Driver and Firmware (Runtime Dependency)**

For Ascend driver and firmware download and installation on host machine, refer to "[CANN Software Installation Guide](https://www.hiascend.com/document/redirect/CannCommunityInstWizard)" sections "Prepare Software Packages" and "Install NPU Driver and Firmware". Driver and firmware are runtime dependencies. If only compiling operators, installation is not required.

2.**Download Image**

- Step 1: Log in to host machine as root user. Ensure Docker engine is installed on host machine (version 1.11.2 or above).
- Step 2: Pull pre-integrated CANN software package and development-required dependency image from [Ascend Image Repository](https://www.hiascend.com/developer/ascendhub/detail/17da20d1c2b6493cb38765adeba85884). Commands below, select according to actual architecture (using Atlas A2 series products as example, compilation-only scenario does not need attention):

    ```bash
    # Example: Pull ARM architecture CANN development image
    docker pull --platform=arm64 swr.cn-south-1.myhuaweicloud.com/ascendhub/cann:9.0.0-beta.1-910-ubuntu22.04-py3.11
    # Example: Pull X86 architecture CANN development image
    docker pull --platform=amd64 swr.cn-south-1.myhuaweicloud.com/ascendhub/cann:9.0.0-beta.1-910-ubuntu22.04-py3.11
    ```

3.**Run Docker**
Select different startup methods according to usage scenario:

- **Scenario 1: Compilation Build Only (No Need to Run Samples)**

  If only code compilation build is needed, without accessing NPU device, use the following simplified command:

  ```bash
  docker run --name cann_container -it -u root --privileged=true -v /home/metadef/:/home/metadef swr.cn-south-1.myhuaweicloud.com/ascendhub/cann:9.0.0-beta.1-910-ubuntu22.04-py3.11 bash
  ```

- **Scenario 2: Need to Run Samples (Need to Access NPU Device)**

  If running samples or tests is needed, container needs to access host NPU device. Using Atlas A2 series products as example:

```bash
docker run --name cann_container \
  --device /dev/davinci0 \
  --device /dev/davinci_manager \
  --device /dev/devmm_svm \
  --device /dev/hisi_hdc \
  -v /usr/local/dcmi:/usr/local/dcmi \
  -v /usr/local/bin/npu-smi:/usr/local/bin/npu-smi \
  -v /usr/local/Ascend/driver/lib64/:/usr/local/Ascend/driver/lib64/ \
  -v /usr/local/Ascend/driver/version.info:/usr/local/Ascend/driver/version.info \
  -v /etc/ascend_install.info:/etc/ascend_install.info \
  -it -u root --privileged=true \
  swr.cn-south-1.myhuaweicloud.com/ascendhub/cann:9.0.0-beta.1-910-ubuntu22.04-py3.11 bash
```

| Parameter | Description | Note |
| :-- | :-- | :-- |
| `--name cann_container` | Specify name for container, convenient for management. | Optional (value can be customized). |
| `--device /dev/davinci0` | Map NPU device file into container. | Required (when running samples). For multiple devices, use this parameter multiple times, such as `/dev/davinci0` `/dev/davinci1`. |
| `--device /dev/davinci_manager` | Ascend device manager, responsible for device resource management. | Required (when running samples). |
| `--device /dev/devmm_svm` | Device memory management unit. | Required (when running samples). |
| `--device /dev/hisi_hdc` | Ascend high-definition codec device. | Required (when running samples). |
| `-v /usr/local/dcmi:/usr/local/dcmi` | Mount DCMI (Device Communication Management Interface) directory. | Required (when running samples). |
| `-v /usr/local/bin/npu-smi:...` | Mount NPU monitoring tool, for viewing NPU status. | Required (when running samples). |
| `-v /usr/local/Ascend/driver/...` | Mount NPU driver library and version information. | Required (when running samples). |
| `-v /etc/ascend_install.info:...` | Mount Ascend software installation information. | Required (when running samples). |
| `-it` | Combination parameter of `-i` (interactive) and `-t` (allocate pseudo terminal). | Required |
| `-u root` | Enter container as root (administrator). | Recommended |
| `--privileged=true` | Enable container highest privilege mode. | Recommended |
| `swr.cn-south-1.myhuaweicloud.com/ascendhub/cann:...` | Specify Docker image to run. | Required, ensure this image name and tag (tag) exactly match the image you pulled through `docker pull`. |
| `bash` | Command executed immediately after container starts. | Required |

> **Note**:

> - Scenario 1 is suitable for compilation build only of metadef, without NPU device support

> - Scenario 2 is suitable for running samples or performing NPU-related tests, requires host machine already installed NPU driver and firmware
> - If using other model chips (such as 950, Atlas A3 series products), please accordingly adjust device names in `--device` parameter

4.**Initialize Environment**
After entering container, execute the following commands to initialize environment:

- **Scenario 1 (Compilation Build Only)**:

    ```bash
    curl -fsSL https://raw.gitcode.com/cann/metadef/raw/master/scripts/init_env.sh | bash
    ```

- **Scenario 2 (Need to Run Samples, using Atlas A2 series products as example)**:

    ```bash
    curl -fsSL https://raw.gitcode.com/cann/metadef/raw/master/scripts/init_env.sh | bash -s -- --chip-type 910b
    ```

> **Note**:
>
> - For other chip models, replace `--chip-type` parameter with corresponding model (such as `950`, `A3`)

### Method 3: Manual Software Package Installation

**Scenario 1: Experience Master Version Capabilities or Develop Based on Master Version**

Click [Download Link](https://ascend.devcloud.huaweicloud.com/artifactory/cann-run-mirror/software/master/), select latest time version, and download corresponding package according to product model and environment architecture. Installation commands below, for more guidance refer to "[CANN Software Installation Guide](https://www.hiascend.com/document/redirect/CannCommunityInstWizard)". CANN Toolkit development suite package installation method:

```bash
# Ensure installation package has executable permission
chmod +x Ascend-cann-toolkit_${cann_version}_linux-${arch}.run
# Installation command
./Ascend-cann-toolkit_${cann_version}_linux-${arch}.run --install --install-path=${install_path}
```

- `${cann_version}`: Indicates CANN package version number.
- `${arch}`: Indicates CPU architecture, such as `aarch64`, `x86_64`.
- `${install_path}`: Indicates specified installation path, needs to be installed in same path as toolkit package. Root user default installation in `/usr/local/Ascend` directory.

**Scenario 2: Experience Released Version Capabilities or Develop Based on Released Version**

If you want to experience **officially released CANN package** capabilities, visit [CANN Official Download Center](https://www.hiascend.com/cann/download), select corresponding version CANN software package (only supports CANN 8.5.0 and subsequent versions) for installation.
