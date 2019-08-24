REM @echo off
:: Name:     customCompiler.win32.cpp.cmd
:: Purpose:  Run CPP code for Nexss PROGRAMMER
:: Author:   mapoart@gmail.com
:: Revision: December 2018 - initial version
::           July 2019 - added support for vcpkg includes and NEXSS_BUILD_PATH_FILE
:: clang-cl /std:c++17 -Wall /Id:\VisualStudioLibraries\Cpp\vcpkg\installed\x86-windows\include\ -o %1.exe %1
clang++ -std=c++17 -Xclang -flto-visibility-public-std -Wall -isystem d:\VisualStudioLibraries\Cpp\vcpkg\installed\x86-windows\include\ -o %2 %1
REM %2