@echo off
SETLOCAL EnableDelayedExpansion

:: Initialize configuration options with default values
SET "BuildPortableVersion=OFF"
SET "BuildMPEngine=ON"
SET "BuildMPRdVanilla=ON"
SET "BuildMPRdVulkan=ON"
SET "BuildMPDed=ON"
SET "BuildMPGame=ON"
SET "BuildMPCGame=ON"
SET "BuildMPUI=ON"
SET "BuildMPRend2=ON"
SET "BuildDiscordRichPresence=ON"
SET "BuildTests=OFF"
SET "INSTALL_PATH="

:: Check if CMake is installed
where cmake >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo CMake not found. Please install CMake and add it to your PATH.
    pause
    exit /b
)

echo Found CMake!

:: Prompt user for Visual Studio version with default
echo Please select the Visual Studio version or press Enter for the default [Visual Studio 2022 (msvc17)]:
echo [1] Visual Studio 2015 (msvc14)
echo [2] Visual Studio 2017 (msvc15)
echo [3] Visual Studio 2019 (msvc16)
echo [4] Visual Studio 2022 (msvc17)
echo.

set /p VS_CHOICE="Enter your choice (1-4) or press Enter for default: " || SET "VS_CHOICE=4"
echo.

IF "%VS_CHOICE%"=="1" (
    SET "VS_VERSION=Visual Studio 14 2015"
    SET "VS_FOLDER=msvc14"
) ELSE IF "%VS_CHOICE%"=="2" (
    SET "VS_VERSION=Visual Studio 15 2017"
    SET "VS_FOLDER=msvc15"
) ELSE IF "%VS_CHOICE%"=="3" (
    SET "VS_VERSION=Visual Studio 16 2019"
    SET "VS_FOLDER=msvc16"
) ELSE (
    SET "VS_VERSION=Visual Studio 17 2022"
    SET "VS_FOLDER=msvc17"
)

:: Prompt user for architecture with default
echo Please select the target architecture or press Enter for the default [32-bit (x86)]:
echo [1] 32-bit (x86)
echo [2] 64-bit (x64)
echo.

set /p ARCH_CHOICE="Enter your choice (1-2) or press Enter for default: " || SET "ARCH_CHOICE=1"
echo.

IF "%ARCH_CHOICE%"=="1" (
    SET "ARCH=Win32"
    SET "ARCH_FOLDER=x86"
) ELSE (
    SET "ARCH=x64"
    SET "ARCH_FOLDER=x64"
)

:: Configuration options prompt
:CONFIG_OPTIONS
echo.
echo Configuration will proceed with default build options.
echo Advanced users can enter 'ADVANCED' to configure options.
set /p ADVANCED_CONFIG="Enter ADVANCED to configure cmake build options or press Enter to continue: "
echo.

REM Set default installation path for both standard and advanced users
SET "INSTALL_PATH=..\install-%VS_FOLDER%_%ARCH_FOLDER%"

IF /I "!ADVANCED_CONFIG!"=="ADVANCED" (
    GOTO CONFIG_MENU
) ELSE (
    GOTO CONFIG_DONE
)

:CONFIG_MENU
cls
echo Advanced CMake Configuration Menu
echo [1] Build portable version - !BuildPortableVersion!
echo [2] Build MP Engine - !BuildMPEngine!
echo [3] Build MP default renderer - !BuildMPRdVanilla!
echo [4] Build MP vulkan renderer - !BuildMPRdVulkan!
echo [5] Build MP dedicated server - !BuildMPDed!
echo [6] Build MP server-side gamecode - !BuildMPGame!
echo [7] Build MP clientside gamecode - !BuildMPCGame!
echo [8] Build MP UI code - !BuildMPUI!
echo [9] Build EXPERIMENTAL MP rend2 renderer - !BuildMPRend2!
echo [A] Build with Discord Rich Presence - !BuildDiscordRichPresence!
echo [B] Build automatic unit tests (requires Boost) - !BuildTests!
echo [C] Set custom install path - [!INSTALL_PATH!]
echo [D] Done
echo [E] Exit without changes
echo.
set /p CONFIG_CHOICE="Select an option to toggle or configure (1-9, A-C) or D when done, E to exit: "

IF "!CONFIG_CHOICE!"=="1" CALL :TOGGLE_OPTION BuildPortableVersion
IF "!CONFIG_CHOICE!"=="2" CALL :TOGGLE_OPTION BuildMPEngine
IF "!CONFIG_CHOICE!"=="3" CALL :TOGGLE_OPTION BuildMPRdVanilla
IF "!CONFIG_CHOICE!"=="4" CALL :TOGGLE_OPTION BuildMPRdVulkan
IF "!CONFIG_CHOICE!"=="5" CALL :TOGGLE_OPTION BuildMPDed
IF "!CONFIG_CHOICE!"=="6" CALL :TOGGLE_OPTION BuildMPGame
IF "!CONFIG_CHOICE!"=="7" CALL :TOGGLE_OPTION BuildMPCGame
IF "!CONFIG_CHOICE!"=="8" CALL :TOGGLE_OPTION BuildMPUI
IF "!CONFIG_CHOICE!"=="9" CALL :TOGGLE_OPTION BuildMPRend2
IF /I "!CONFIG_CHOICE!"=="A" CALL :TOGGLE_OPTION BuildDiscordRichPresence
IF /I "!CONFIG_CHOICE!"=="B" CALL :TOGGLE_OPTION BuildTests
IF /I "!CONFIG_CHOICE!"=="C" (
    echo Enter custom install path or leave empty for default:
    set /p INSTALL_PATH="Custom install path: "
    echo.
)
IF /I "!CONFIG_CHOICE!"=="D" GOTO CONFIG_DONE
IF /I "!CONFIG_CHOICE!"=="E" exit /b
GOTO CONFIG_MENU

:CONFIG_DONE
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildPortableVersion=!BuildPortableVersion!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPEngine=!BuildMPEngine!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPRdVanilla=!BuildMPRdVanilla!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPRdVulkan=!BuildMPRdVulkan!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPDed=!BuildMPDed!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPGame=!BuildMPGame!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPCGame=!BuildMPCGame!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPUI=!BuildMPUI!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildMPRend2=!BuildMPRend2!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildDiscordRichPresence=!BuildDiscordRichPresence!"
SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DBuildTests=!BuildTests!"

IF NOT "%INSTALL_PATH%"=="" (
    SET "CMAKE_OPTIONS=!CMAKE_OPTIONS! -DCMAKE_INSTALL_PREFIX=%INSTALL_PATH%"
)

:: Display the selected install path
echo Selected install path: !INSTALL_PATH!
echo.

:: Generate the build folder name using the selected Visual Studio and Architecture
SET "BUILD_FOLDER=%VS_FOLDER%_%ARCH_FOLDER%"

:: If advanced configuration is not selected, continue with the default install path
IF "%ADVANCED_CONFIG%" NEQ "ADVANCED" (
    echo Continuing with default installation path.
    echo.
)

:: Before configuring a new build, clear previous CMake configuration files if they exist.
IF EXIST "%BUILD_FOLDER%\CMakeCache.txt" DEL /F /Q "%BUILD_FOLDER%\CMakeCache.txt"
IF EXIST "%BUILD_FOLDER%\CMakeFiles" RMDIR /S /Q "%BUILD_FOLDER%\CMakeFiles"

:: Configure and generate CMake project
echo Configuring CMake for %VS_VERSION% %ARCH% with options: !CMAKE_OPTIONS!
cmake -G "%VS_VERSION%" -A %ARCH% !CMAKE_OPTIONS! -B "%BUILD_FOLDER%" -S ".." || (
    echo Failed to configure CMake project.
    pause
    exit /b
)

echo CMake project configured successfully in folder "%BUILD_FOLDER%".
pause
exit /b

:: Function to toggle configuration options
:TOGGLE_OPTION
SET "optionName=%1"
IF "!%optionName%!"=="ON" (
    SET "%optionName%=OFF"
) ELSE (
    SET "%optionName%=ON"
)
GOTO :EOF
