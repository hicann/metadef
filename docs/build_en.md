# Source Code Build

## 1. Environment Preparation

Before compiling from source, complete the basic environment setup. For specific operations, refer to [Quick Install](quick_install_en.md).

## 2. Environment Verification

After installing the CANN package, verify whether the environment is normal.

```bash
# View the version information provided by the version field of CANN Toolkit (default path installation). <arch> indicates the CPU architecture (aarch64 or x86_64). In WebIDE scenarios, replace /usr/local with /home/developer.
cat /usr/local/Ascend/cann/<arch>-linux/ascend_toolkit_install.info
```

## 3. Environment Variable Configuration

Select the appropriate command based on your actual scenario:

```bash
  # Default path installation, using root user as example (for non-root users, replace /usr/local with ${HOME})
  source /usr/local/Ascend/cann/set_env.sh
  # Specified path installation
  source ${install_path}/cann/set_env.sh
```

## 4. Source Code Compilation

### 4.1 Download Source Code

Developers can download the source code of this repository through the following command:

  ```bash
  # Download project source code, using master branch as example
  git clone https://gitcode.com/cann/metadef.git
  ```

### 4.2 Install Dependencies

#### Install Dependencies

  The following lists dependencies used for source code compilation. Note version requirements (if you encounter installation issues, try switching mirror sources).
  > [!NOTE] Note
  > If using the mirror mode for project experience, all dependencies are included in [init_env.sh](../scripts/init_env.sh). You can skip this dependency installation step.

- GCC >= 7.3.x

- Python3 >= 3.9.x

- CMake >= 3.16.0 (version 3.20.0 recommended)

- ccache/asan/patch

- lcov (optional，for ut coverage)

- pybind11/coverage (optional，for ut coverage)

- graph-easy (optional)


  ```bash
  # Ubuntu/Debian OS installation command examples are shown below. For other OS, install yourself.
  # asan uses gcc 7.5.0 version as example. For other versions, install the corresponding version asan.
  sudo apt-get install cmake ccache lcov libasan4 libgraph-easy-perl patch
  pip3 install "pybind11>=2.13.6,<3.0.0" coverage
  ```

#### Check Build Environment

After installation, it is recommended to execute the environment check script to confirm whether the current environment meets compilation requirements.

```bash
bash scripts/check_env.sh
```

Check result descriptions:

| Status | Meaning | Handling Recommendation |
| -- | -- | -- |
| **[PASS]** | Check passed | No action needed |
| **[WARNING]** | Non-critical dependency missing or version deviation | Recommended to fix, does not affect core compilation |
| **[ERROR]** | Critical dependency missing or incompatible version | Must fix, otherwise cannot compile |

> [!NOTE] Note
> All check items and version constraints in the environment check script strictly come from docs/build.md. If build.md is updated, please synchronously modify the [script](../scripts/check_env.sh).

### 4.3 Compilation

> [!NOTE] Note
> If your compilation environment cannot access the network, because source code cannot be downloaded through `git` commands, you must download source code and third-party library dependencies in a networked environment and manually upload to the target environment. Refer to [Offline Compilation Guide](offline_compile_en.md).
> If your compilation environment can access the network, after downloading code through `git` commands, open source third-party software will be automatically downloaded during compilation.

If your compilation environment can access the network, or you have completed [Offline Compilation Guide](offline_compile_en.md), `metadef` provides one-click compilation capability through the following command:

```shell
bash build.sh
```

For more compilation parameters, check through `bash build.sh -h`. After successful compilation, the `cann-metadef_<version>_linux.<arch>.run` software package will be generated in the `build_out` directory.

- `<version>` indicates the version number.
- `<arch>` indicates the OS architecture, with values including x86_64 and aarch64.

### 4.4 Local Verification (UT)

> [!NOTE] Note
> If your compilation environment cannot access the network, ensure you have completed the [Offline Compilation Guide](offline_compile_en.md) in the [4.3 Compilation](#43-compilation) section.

Before executing local verification, ensure you have completed [Install Dependencies](#4.2-Install Dependencies) and set [Environment Variables](#3.-Environment Variable Configuration).

The `metadef` repository provides one-click compilation execution for developer testing. For detailed configuration, check through `bash tests/run_test.sh -h`.

```bash
bash tests/run_test.sh -u
```

### 4.5 Installation and Uninstallation

- Installation

  After compilation, the generated metadef software package is placed in the `./build_out` directory. You can install the compiled metadef software package through the following command.

  ```shell
  ./cann-metadef_<version>_linux.<arch>.run --full --install-path=${install_path}
  ```

  For root user with default path installation: `${install_path}` is `/usr/local/Ascend`; for non-root user with default path installation: `${install_path}` is `$HOME/Ascend`.

- Uninstallation

  If you want to uninstall the installed custom `metadef` software package, execute the following command:

  ```shell
  ./cann-metadef_<version>_linux.<arch>.run --uninstall --install-path=${install_path}
  ```
