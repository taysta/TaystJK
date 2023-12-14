@echo off
setlocal
echo Updating Git tag and hash...

:: Check if header file path is provided
if "%~1"=="" (
    echo Usage: %~nx0 [HeaderFilePath]
    exit /b
)

:: Get the current git tag and hash
for /f "delims=" %%i in ('git describe --tags --abbrev^=0') do set GIT_TAG=%%i
for /f "delims=" %%i in ('git rev-parse --short HEAD') do set GIT_HASH=%%i

:: Use powershell to replace the GIT_TAG and GIT_HASH in the header file
powershell -Command "(gc %~1) -replace '#define GIT_TAG .*', '#define GIT_TAG \""%GIT_TAG%\""' | Out-File -encoding ASCII %~1"
powershell -Command "(gc %~1) -replace '#define GIT_HASH .*', '#define GIT_HASH \""%GIT_HASH%\""' | Out-File -encoding ASCII %~1"

echo Git tag is %GIT_TAG%
echo Git hash is %GIT_HASH%
