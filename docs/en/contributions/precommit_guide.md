# pre-commit Usage Guide

[TOC]
--

## 1 Usage Background

This guide provides instructions on how to locally use the pre-commit capabilities deployed in the code repository (mainly including code formatting and OAT scanning capabilities).

## 2 Feature Overview

1. After installing pre-commit, code formatting and OAT checks are automatically triggered before git commit.

2. Compliance issues prevent commit and prompt for modification. Prevention is not forced modification and can be ignored.

## 3 Community Contributors Using pre-commit Capabilities

### 3.1 pre-commit Installation Steps

Step 1: Install pre-commit Framework

```bash
# Using pip (recommended)
pip install pre-commit

# Verify installation
pre-commit --version
# Output: pre-commit 3.x.x
```

**Windows Users**: Ensure Python and pip are installed.

Step 2: Enter Project Directory

```bash
cd /path/to/your/project

# For example
cd d:\complianceRepo\CANN
```

Step 3: Install Git Hooks

```bash
# Run in project root directory
pre-commit install
```

Step 4: Verify Installation (Optional)

```bash
# Test hook (will not actually commit)
git commit --allow-empty -m "test pre-commit"
```

Subsequently, code formatting and OAT checks will be automatically triggered before code commit.

### 3.2 OAT Usage Guide

**OAT (Open Source Audit Tool)** is an open source compliance checking tool automatically integrated into the Git commit process.

#### 3.2.1 Check Content

**File Type Check** - Prevents submission of binary files (.so, .dll, .exe, and so on)
**License Header Check** - Verifies source code files contain compliant license declarations

#### 3.2.2 Core Features

- **Incremental Check** - Only checks pending files, fast (< 5 seconds)
- **Automatic Trigger** - Runs automatically with each `git commit`
- **Detailed Report** - Automatically generates `result.txt` summary and full report
- **Zero Configuration** - Java and Maven automatically installed (Linux/macOS)
- **Cross-Platform** - Full support for Windows/Linux/macOS

#### 3.2.3 Required Software

| Software | Version Requirement | Purpose | Installation Method |
|------|---------|------|----------|
| **Java** | JRE 8+ | Run OAT | **Automatic Installation** (Linux/macOS)<br> Manual Installation (Windows) |
| **Maven** | 3.5+ | Package OAT | **Automatic Installation** (Linux/macOS)<br> Manual Installation (Windows) |
| **Git** | 2.0+ | Version Control | Usually already installed |
| **pre-commit** | 2.0+ | Hook Framework | `pip install pre-commit` |

#### 3.2.4 Automatic Installation Support

| Platform | Java | Maven | Package Manager | First Installation Time |
|------|------|-------|---------|-------------|
| **Linux (Ubuntu/Debian)** | Automatic | Automatic | apt | 5-8 minutes |
| **Linux (CentOS/RHEL)** | Automatic | Automatic | yum | 5-8 minutes |
| **macOS** | Automatic | Automatic | Homebrew | 8-10 minutes |
| **Windows** | Manual | Manual | - | Requires manual installation |

#### 3.2.5 Important Note: Automatic Skip for Environment Issues

**Friendly Design**: If Java/Maven cannot be installed or environment issues occur, OAT check **automatically skips** and commit continues.

**Scenarios that Automatically Skip**

| Scenario | Behavior | Prompt |
|------|------|------|
| Java/Maven not installed (Windows) | Skip check, allow commit | Provide manual installation guide |
| Java/Maven automatic installation fails | Skip check, allow commit | Prompt manual installation method |
| Maven packaging fails | Skip check, allow commit | Provide solution |
| OAT scan execution fails | Skip check, allow commit | Prompt to repackage |

**Scenarios that Still Prevent Commit**

| Scenario | Behavior | Reason |
|------|------|------|
| **Binary files found** | Prevent commit | Actual compliance issue |
| **License header missing/invalid** | Prevent commit | Actual compliance issue |

**Skip Check Prompt Example**

```
[OAT] Windows system cannot automatically install Java
[OAT] Please manually download and install:
  ... (installation steps) ...

[OAT] Skip OAT check, continue commit...
[OAT] Recommend installing Java and then running check again
```

**Manually Run Check Later**

After configuring the environment, you can manually run checks:

```bash
# Recommended method
pre-commit run oat-check

# Or directly run script
bash scripts/oat_check.sh
```

#### 3.2.6 Compliance Issues (Prevent Commit)

**Important**: The following issues **prevent commit** and must be fixed.

**1) Invalid File Type Found**

**Scenario**: Attempting to submit binary files (.so, .dll, .exe, and so on).

**Output**:
```
====================================================================
  Compliance Issue Found
====================================================================

[OAT] Found 1 compliance issue(s):
  - Invalid File Type: 1
  - License Header Invalid: 0

[OAT] Details saved to: oat_reports/single/result.txt
[OAT] Please check the report and fix the issues.

To view the summary:
  cat oat_reports/single/result.txt

To skip this check temporarily:
  git commit --no-verify
```

**Behavior**: **Prevent commit, must fix**

**View Details**:
```bash
cat oat_reports/single/result.txt
```

**Report Content Example**:
```
===================================
OAT Scan Result Summary
===================================
Scan Time: 2026-03-25 14:30:15
Project: CANN
Files Checked: 1

----------------------------------
Invalid File Type Total Count: 1
lib/libtest.so: BINARY_FILE_TYPE

----------------------------------
License Header Invalid Total Count: 0

==================================
Full report: oat_reports/single/PlainReport_CANN.txt
==================================
```

**Solution**:
```bash
# Method 1: Remove binary file
git reset HEAD lib/libtest.so

# Method 2: Add binary files to .gitignore
echo "*.so" >> .gitignore
echo "*.dll" >> .gitignore
echo "*.exe" >> .gitignore

# Resubmit
git add .gitignore
git commit -m "update: add binary files to gitignore"
```

**2) Invalid License Header**

**Scenario**: Source code file lacks or has incorrect license header format.

**Output**:
```
====================================================================
  Compliance Issue Found
====================================================================

[OAT] Found 2 compliance issue(s):
  - Invalid File Type: 0
  - License Header Invalid: 2

[OAT] Details saved to: oat_reports/single/result.txt
```

**Behavior**: **Prevent commit, must fix**

**View Details**:
```bash
cat oat_reports/single/result.txt
```

**Report Content Example**:
```
===================================
OAT Scan Result Summary
===================================

----------------------------------
Invalid File Type Total Count: 0

----------------------------------
License Header Invalid Total Count: 2
src/main.cpp: MISSING_LICENSE_HEADER
src/utils.cpp: MISSING_LICENSE_HEADER

==================================
```

**Solution**:

Add license header at the top of the file, for example CANN-2.0:

```cpp
/**
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

```

**Resubmit**:
```bash
git add src/main.cpp src/utils.cpp
git commit -m "fix: add license headers"
```

---

#### 3.2.7 Report Viewing

**Report File Location**

| Report Type | File Path | Content |
|---------|---------|------|
| **Summary Report** | `oat_reports/single/result.txt` | Key issue summary |

**View Commands**

```bash
# View report
cat oat_reports/single/result.txt

# View with editor
code oat_reports/single/result.txt
vim oat_reports/single/result.txt
```

**Summary Report Content**

```
===================================
OAT Scan Result Summary
===================================
Scan Time: 2026-03-25 14:30:15
Project: CANN
Files Checked: 3

----------------------------------
Invalid File Type Total Count: 0

----------------------------------
License Header Invalid Total Count: 0

==================================
Full report: oat_reports/single/PlainReport_CANN.txt
==================================
```

#### 3.2.8 Environment Issues

**1) Java Not Installed (Linux/macOS Automatic Installation)**

**Scenario**: First commit, system does not have Java installed.

**Output**:
```
====================================================================
  Java Not Installed - Attempting Automatic Installation
====================================================================

[OAT] Detected system does not have Java installed, starting automatic installation...
[OAT] Using apt to install OpenJDK 11...
[OAT] [OK] OpenJDK 11 installed successfully
```

**Handling**: Automatic installation, may require sudo password input.

---

**2) Java Not Installed (Windows Manual Installation)**

**Scenario**: Windows system cannot automatically install Java.

**Output**:
```
[OAT] Windows system cannot automatically install Java
[OAT] Please manually download and install:

  1. Visit: https://adoptium.net/
  2. Download: Eclipse Temurin JRE 11 (x64)
  3. After installation, restart Git Bash
  4. Verify: java -version

[OAT] Skip OAT check, continue commit...
[OAT] Recommend installing Java and then running check again
```

**Behavior**: **Skip check, allow commit**

**Follow-up Actions**:
1. Manually install Java according to prompts
2. Restart terminal
3. Run `pre-commit run oat-check` to verify environment

---

**3) Java Automatic Installation Failed**

**Scenario**: Linux/macOS automatic Java installation failed.

**Output**:
```
[OAT] [ERROR] Automatic installation failed

[OAT] Automatic installation failed, skip OAT check

Manual installation methods:
  Linux:   sudo apt install openjdk-11-jre
  macOS:   brew install openjdk@11
  Windows: https://adoptium.net/

[OAT] Continue commit (compliance check not performed)...
[OAT] Recommend installing Java and then run: pre-commit run oat-check
```

**Behavior**: **Skip check, allow commit**

**Possible Reasons**:
- Network connection issue
- Package manager not configured
- Insufficient permissions
- macOS does not have Homebrew installed

**Solution**:
```bash
# Linux
sudo apt update
sudo apt install openjdk-11-jre

# macOS - First install Homebrew
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install openjdk@11

# Verify
java -version

# Manually run check
pre-commit run oat-check
```

---

**4) Maven Not Installed (Linux/macOS Automatic Installation)**

**Scenario**: First commit, system does not have Maven installed.

**Output**:
```
====================================================================
  Maven Not Installed - Attempting Automatic Installation
====================================================================

[OAT] Using apt to install Maven...
[OAT] [OK] Maven installed successfully
```

**Handling**: Automatic installation, may require sudo password input.

---

**5) Maven Not Installed (Windows Manual Installation)**

**Scenario**: Windows system cannot automatically install Maven.

**Output**:
```
[OAT] Windows system cannot automatically install Maven
[OAT] Please manually download and install:

  1. Visit: https://maven.apache.org/download.cgi
  2. Download: apache-maven-3.x.x-bin.zip
  3. Extract to C:\Program Files\apache-maven-3.x.x
  4. Add to system PATH
  5. Restart Git Bash
  6. Verify: mvn -version

[OAT] Skip OAT check, continue commit...
[OAT] Recommend installing Maven and then running check again
```

**Behavior**: **Skip check, allow commit**

**Follow-up Actions**: Manually install Maven according to prompts, then run `pre-commit run oat-check`

---

**6) Maven Packaging Failed**

**Scenario**: Maven packaging OAT JAR failed.

**Output**:
```
====================================================================
  Maven Packaging Failed
====================================================================

[OAT] Cannot package OAT JAR, skip OAT check

Possible reasons:
  1. Maven configuration issue
  2. Network connection issue (cannot download dependencies)
  3. pom.xml configuration error

Recommended solutions:
  1. Manual packaging:
     cd ../tools_oat
     mvn clean package -DskipTests

  2. Configure Maven mirror (domestic network):
     Edit ~/.m2/settings.xml to add Aliyun mirror

[OAT] Continue commit (compliance check not performed)...
[OAT] Recommend fixing packaging issue and then run: pre-commit run oat-check
```

**Behavior**: **Skip check, allow commit**

**Solution**:

**Method 1: Manual Packaging**
```bash
cd ../tools_oat
mvn clean package -DskipTests

# View output, should see BUILD SUCCESS
```

**Method 2: Configure Aliyun Mirror (Domestic Network)**
```bash
mkdir -p ~/.m2
cat > ~/.m2/settings.xml <<'EOF'
<settings>
  <mirrors>
    <mirror>
      <id>aliyun</id>
      <mirrorOf>central</mirrorOf>
      <name>Aliyun Maven Mirror</name>
      <url>https://maven.aliyun.com/repository/public</url>
    </mirror>
  </mirrors>
</settings>
EOF

# Repackage
cd ../tools_oat
mvn clean package -DskipTests
```

**Method 3: Get JAR from Team**
```bash
# If team has compiled JAR, directly copy
# Copy JAR file to ../tools_oat/target/ directory
```

**Verify Fix**:
```bash
pre-commit run oat-check
```

---

**7) tools_oat Clone Failed**

**Output**:
```
[OAT] tools_oat not found. Cloning...
[OAT] [ERROR] Failed to clone tools_oat.
[OAT] You can manually clone from: https://gitcode.com/openharmony-sig/tools_oat.git
```

**Reason**: Network connection issue.

**Solution**:
```bash
# Method 1: Check network
ping gitcode.com

# Method 2: Manual clone
cd ..
git clone https://gitcode.com/openharmony-sig/tools_oat.git

# Method 3: Configure proxy
git config --global http.proxy http://proxy.example.com:8080

# Method 4: Copy from team member
# Let colleague who already cloned package tools_oat folder for you
```

---

**8) OAT Scan Execution Failed**

**Scenario**: OAT JAR execution failed.

**Output**:
```
====================================================================
  OAT Scan Execution Failed
====================================================================

[OAT] Scan failed, skip OAT check

Possible reasons:
  1. JAR file damaged
  2. Java version incompatible
  3. OAT configuration issue

Recommended solutions:
  1. Delete and repackage JAR:
     rm ../tools_oat/target/ohos_ossaudittool-*.jar
     cd ../tools_oat && mvn clean package -DskipTests

  2. Check Java version (requires Java 8+):
     java -version

[OAT] Continue commit (compliance check not performed)...
[OAT] Recommend fixing scan issue and then run: pre-commit run oat-check
```

**Behavior**: **Skip check, allow commit**

**Solution**:
```bash
# Step 1: Delete old JAR
rm ../tools_oat/target/ohos_ossaudittool-*.jar

# Step 2: Repackage
cd ../tools_oat
mvn clean package -DskipTests

# Step 3: Verify JAR
ls -lh target/ohos_ossaudittool-*.jar

# Step 4: Run check
cd -
pre-commit run oat-check
```