# Security Statement

## Recommended Running User

For security reasons, it is not recommended to use root or other administrator accounts to execute any commands. Follow the principle of least privilege.

## File Permission Control

- It is recommended that users set the system umask value to 0027 or higher on hosts (including bare metal hosts) and containers. This ensures that new folders have a default maximum permission of 750 and new files have a default maximum permission of 640.
- It is recommended that users implement proper permission control and other security measures for sensitive content such as personal privacy data, commercial assets, source files, and various files saved during operator development. For example, for permission control of the project installation directory and input public data files, refer to [A-Recommended Maximum Permissions for Files (Folders) in Various Scenarios](#A-Recommended Maximum Permissions for Files (Folders) in Various Scenarios).
- Users should implement proper permission control during installation and usage. Refer to [A-Recommended Maximum Permissions for Files (Folders) in Various Scenarios](#A-Recommended Maximum Permissions for Files (Folders) in Various Scenarios) for file permission settings.

## Build Security Statement

When compiling and installing this project from source, you need to compile it yourself. Some intermediate files are generated during compilation. It is recommended that you implement proper permission control for these intermediate files after compilation to ensure file security.

## Runtime Security Statement

When an exception occurs during runtime, the process exits and prints error information. It is recommended to locate the specific error cause based on the error prompt.

## Public Network Address Statement

The public network addresses contained in this project code are as follows:

| Type | Open Source Code Address | File Name | Public IP Address/Public URL Address/Domain Name/Email Address/Compressed File Address | Usage Description |
| :--: | :--: | :-- | :-- | :-- |
| Dependency | Not applicable | cmake/third_party/build/modules/makeself-fetch.cmake | https://gitcode.com/cann-src-third-party/makeself/releases/download/release-2.5.0-patch1.0/makeself-release-2.5.0-patch1.tar.gz | Download makeself source code from gitcode as compilation dependency |
| Dependency | Not applicable | cmake/third_party/build/modules/json.cmake | https://gitcode.com/cann-src-third-party/json/releases/download/v3.11.3/include.zip | Download json source code from gitcode as compilation dependency |
| Dependency | Not applicable | cmake/third_party/build/modules/gtest.cmake | https://gitcode.com/cann-src-third-party/googletest/releases/download/v1.14.0/googletest-1.14.0.tar.gz | Download googletest source code from gitcode as compilation dependency |
| Dependency | Not applicable | cmake/third_party/build/modules/pybind11.cmake | https://gitcode.com/cann-src-third-party/pybind11/releases/download/v2.13.6/pybind11-2.13.6.tar.gz | Download pybind11 source code from gitcode as compilation dependency |
| Dependency | Not applicable | cmake | https://apt.kitware.com/keys/kitware-archive-latest.asc | Download cmake software from kitware as compilation dependency |
| Dependency | Not applicable | cmake | https://apt.kitware.com/ubuntu/ | Download cmake software from kitware as compilation dependency |

## Vulnerability Mechanism Description

[Vulnerability Management](https://gitcode.com/cann/community/blob/master/security/security.md)

## Appendix

### A-Recommended Maximum Permissions for Files (Folders) in Various Scenarios

| Type | Linux Permission Reference Maximum Value |
| -- | -- |
| User home directory | 750 (rwxr-x---) |
| Program files (including script files, library files, and so on) | 550 (r-xr-x---) |
| Program file directory | 550 (r-xr-x---) |
| Configuration file | 640 (rw-r-----) |
| Configuration file directory | 750 (rwxr-x---) |
| Log file (completed recording or archived) | 440 (r--r-----) |
| Log file (currently recording) | 640 (rw-r-----) |
| Log file directory | 750 (rwxr-x---) |
| Debug file | 640 (rw-r-----) |
| Debug file directory | 750 (rwxr-x---) |
| Temporary file directory | 750 (rwxr-x---) |
| Maintenance upgrade file directory | 770 (rwxrwx---) |
| Business data file | 640 (rw-r-----) |
| Business data file directory | 750 (rwxr-x---) |
| Key components, private keys, certificates, ciphertext file directory | 700 (rwx—----) |
| Key components, private keys, certificates, encrypted ciphertext | 600 (rw-------) |
| Encryption/decryption interfaces, encryption/decryption scripts | 500 (r-x------) |
