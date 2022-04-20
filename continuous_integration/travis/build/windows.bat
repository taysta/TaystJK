echo off

SET ARCH=%1
SET BUILD_TYPE=%2

mkdir build
cd build

if "%ARCH%" == "x64" (
    cmake -G "Visual Studio 15" -A x64 -T host=x64 ..
) else (
    cmake -G "Visual Studio 15" -A Win32 -T host=x86 ..
)

:: https://docs.travis-ci.com/user/speeding-up-the-build/#makefile-optimization
:: https://docs.microsoft.com/fr-fr/visualstudio/msbuild/building-multiple-projects-in-parallel-with-msbuild?view=vs-2017
:: https://docs.travis-ci.com/user/reference/overview/#virtualization-environments
MSBuild.exe ALL_BUILD.vcxproj -maxcpucount -p:Configuration=%BUILD_TYPE%