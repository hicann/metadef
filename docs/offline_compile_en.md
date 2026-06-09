# METADEF Offline Compilation Guide

## 1. Complete the Following Preparation in a Networked Environment

### Step 1: Repository Download

In a networked environment, go to [This Project Homepage](https://gitcode.com/cann/metadef) and complete source code download through the `Download ZIP` or `clone` button according to the instructions.

### Step 2: Download Open Source Third-Party Software Dependencies

The third-party open source software that metadef depends on during compilation is listed below:

| Open Source Software | Version | Download Address |
|---|---|---|
| protobuf | 25.1 | [protobuf-25.1.tar.gz](https://gitcode.com/cann-src-third-party/protobuf/releases/download/v25.1/protobuf-25.1.tar.gz) |
| abseil-cpp | 20230802.1 | [abseil-cpp-20230802.1.tar.gz](https://gitcode.com/cann-src-third-party/abseil-cpp/releases/download/20230802.1/abseil-cpp-20230802.1.tar.gz) |
| benchmark | 1.8.3 | [benchmark-1.8.3.tar.gz](https://gitcode.com/cann-src-third-party/benchmark/releases/download/v1.8.3/benchmark-1.8.3.tar.gz) |
| googletest | 1.14.0 | [googletest-1.14.0.tar.gz](https://gitcode.com/cann-src-third-party/googletest/releases/download/v1.14.0/googletest-1.14.0.tar.gz) |
| json | 3.11.3 | [json-3.11.3.tar.gz](https://gitcode.com/cann-src-third-party/json/releases/download/v3.11.3/json-3.11.3.tar.gz) |
| makeself | 2.5.0 | [makeself-release-2.5.0-patch1.tar.gz](https://gitcode.com/cann-src-third-party/makeself/releases/download/release-2.5.0-patch1.0/makeself-release-2.5.0-patch1.tar.gz) |
| cann-cmake | master | [cmake-master.tar.gz](https://raw.gitcode.com/cann/cmake/archive/refs/heads/master.tar.gz) |

- Method 1 (Recommended): Use the [one-click third-party software download and packaging script](../scripts/download_third_party_source.sh) provided by the metadef repository. Usage:

```bash
# Execute in metadef repository root directory in networked environment
cd metadef
bash scripts/download_third_party_source.sh
```

After successful execution, `opensource.tar.gz` will be generated in the metadef repository root directory.

- Method 2: Download third-party open source software packages one by one through the third-party open source software list links.

## 2. After Completing [Networked Environment Preparation](#1-complete-the-following-preparation-in-a-networked-environment), Log in to the Test Environment (Offline) to Continue Compilation Preparation

### Scenario 1: Using Third-Party Software Downloaded Through [One-Click Third-Party Software Download and Packaging Script](../scripts/download_third_party_source.sh)

Connect to the test environment (offline) and upload the [repository](#step-1-repository-download) and [third-party software dependencies](#step-2-download-open-source-third-party-software-dependencies) source code obtained from the networked environment to your designated directory. The downloaded files are compressed packages and need to be decompressed.

After decompression, the project structure is as follows:

```bash
├── metadef                          # metadef repository source code decompressed directory
│  ├── base
│  ├── build
│  └── ...
├── opensource                       # third-party software dependencies decompressed directory
│  └── abseil-cpp-20230802.1.tar.gz
│  └── benchmark-1.8.3.tar.gz
│  └── ...
```

Go to the repository root directory and adjust directories through the following commands:

  ```bash
  # Move files under opensource directory to metadef repository
  cd metadef
  mkdir output output/third_party
  cp -r ../opensource/* output/third_party
  rm -rf ../opensource
  ```

After adjustment, the project structure is as follows:

```bash
├── metadef                          # metadef repository source code decompressed directory
│  ├── base
│  ├── build
│  ├── ...
│  └── output                        # third-party software default directory
│     └── third_party
│         └── abseil-cpp-20230802.1.tar.gz
│         └── benchmark-1.8.3.tar.gz
│         └── ...
```

After completion, return to the [Build Verification - Compilation](build_en.md#43-compilation) section to continue compilation.

### Scenario 2: Manually Download Third-Party Software One by One Through Third-Party Open Source Software List Links

1. Connect to the test environment (offline) and upload the [repository](#step-1-repository-download) and [third-party software dependencies](#step-2-download-open-source-third-party-software-dependencies) source code obtained from the networked environment to your designated directory. The repository is a compressed package and needs to be decompressed.

2. Go to the repository root directory, create `output/third_party` and place third-party software packages in that directory.

  ```bash
  # Create output/third_party directory
  cd metadef
  mkdir output output/third_party
  ```

After adjustment, the project structure is as follows:

```bash
├── metadef                          # metadef repository source code decompressed directory
│  ├── base
│  ├── build
│  ├── ...
│  └── output                        # third-party software default directory
│     └── third_party
│        ├── abseil-cpp-20230802.1.tar.gz
│        ├── benchmark-1.8.3.tar.gz
│        └── ...
```

After completion, return to the [Build Verification - Compilation](build_en.md#43-compilation) section to continue compilation.
