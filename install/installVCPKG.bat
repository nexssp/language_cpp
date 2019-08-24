REM https://github.com/Microsoft/vcpkg/tree/master/docs/examples
git clone https://github.com/Microsoft/vcpkg
cd vcpkg
bootstrap-vcpkg.bat
vcpkg integrate install
vcpkg integrate powershell
