---
title: "Compiling"
layout: reference
description: "Configure and compile TaystJK with CMake on Windows, Linux, or macOS."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Developer guide</p>

# Compile TaystJK

<p class="page-lede">Use an out-of-source CMake build. A release build is for playing; <code>RelWithDebInfo</code> is a useful default for development because it keeps optimization and debug symbols.</p>
</div>

## Get the source

Install Git, CMake, and a C/C++ compiler, then clone TaystJK:

```bash
git clone https://github.com/taysta/TaystJK.git
cd TaystJK
```

TaystJK is GPLv2 software. If you distribute a changed binary, make the corresponding source available under the same licence.

## Common CMake options

| Option | Default | Purpose |
|:--|:--|:--|
| `BuildMPEngine` | `ON` | Multiplayer client executable. |
| `BuildMPDed` | `ON` | Dedicated server executable. |
| `BuildMPGame` | `ON` | Server-side game module. |
| `BuildMPCGame` | `ON` | Client-side game module. |
| `BuildMPUI` | `ON` | UI module. |
| `BuildMPRdVanilla` | `ON` | Vanilla renderer. |
| `BuildMPRend2` | `ON` | Experimental rend2 renderer. |
| `BuildMPRdVulkan` | `ON` | Vulkan renderer. |
| `BuildPortableVersion` | `OFF` | Store user files beside the executable. |
| `BuildDiscordRichPresence` | `ON` | Include Discord Rich Presence where a bundled binary is available. |
| `UseAddressSanitizer` | `OFF` | Detect many memory errors at runtime. |
| `UseUndefinedSanitizer` | `OFF` | Detect undefined behavior with GCC/Clang. |

The authoritative list is in the top-level [CMake configuration](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/CMakeLists.txt#L38).

## Windows

Visual Studio 2022 with **Desktop development with C++**, Git, and CMake is the straightforward toolchain. Bundled libraries are selected by default on Windows.

From a Developer PowerShell prompt:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config RelWithDebInfo --parallel
cmake --install build --config RelWithDebInfo --prefix "C:\TaystJK-test"
```

You can instead open the generated `TaystJK.sln`, select `RelWithDebInfo` and `x64`, and build the solution. Use `Debug` when you want the least optimized stepping experience.

## Linux

On Debian or Ubuntu, install the normal development dependencies:

```bash
sudo apt update
sudo apt install build-essential cmake git libsdl2-dev libgl1-mesa-dev \
  libjpeg-dev libpng-dev zlib1g-dev
```

Configure, compile, and optionally install into a test staging directory:

```bash
cmake -S . -B build \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DCMAKE_INSTALL_PREFIX="$HOME/.local/taystjk-test"
cmake --build build --parallel
cmake --install build
```

For a dedicated-server-only build, disable the client, client modules, and renderers:

```bash
cmake -S . -B build-server -DCMAKE_BUILD_TYPE=Release \
  -DBuildMPEngine=OFF -DBuildMPCGame=OFF -DBuildMPUI=OFF \
  -DBuildMPRdVanilla=OFF -DBuildMPRend2=OFF -DBuildMPRdVulkan=OFF
cmake --build build-server --parallel
```

## macOS

Install Xcode Command Line Tools and CMake. The repository bundles the image libraries and SDL for the default Apple build:

```bash
xcode-select --install
brew install cmake
cmake -S . -B build -G Xcode \
  -DCMAKE_INSTALL_PREFIX="$HOME/Library/Application Support/Steam/steamapps/common/Jedi Academy"
cmake --build build --config RelWithDebInfo --parallel
```

On Apple silicon, CMake selects `arm64` from the host architecture and raises the deployment target to macOS 11 when necessary. For a development build, run the install target and then use the repository's helper to move and sign the installed files:

```bash
cmake --build build --config RelWithDebInfo --target install
./scripts/macosx/moveandsign.sh
```

The helper currently expects the install staging directory under the default Steam location and moves the result to `~/Library/Application Support/TaystJK`. Review the path and architecture variables at the top of [the script](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/scripts/macosx/moveandsign.sh) before using it with a different setup. The [debugging guide](/TaystJK/development/debugging/#clion) covers pointing CLion at the executable in that installed layout.

## Install and test

The build output alone does not contain the retail assets. `CMAKE_INSTALL_PREFIX` is the parent staging directory; TaystJK creates a `JediAcademy` directory beneath it. Copy the retail `base` directory into that installed layout, or launch with `+set fs_cdPath /path/to/JediAcademy` so the engine can find `base/assets0.pk3` through `assets3.pk3`.

Keep test builds separate from the client you use every day. The [installation guide](/TaystJK/install/#installing-several-modded-clients) shows a shared-asset layout that works well for development.

## If configuration fails

- Delete only the affected build directory or choose a new one; do not build in the source tree.
- Check the first missing package reported by CMake. On Linux, setting `UseInternalSDL2`, `UseInternalJPEG`, `UseInternalPNG`, and `UseInternalZlib` changes which dependencies must be installed.
- Make sure the compiler architecture matches the libraries and executable you intend to load.
- Use `cmake --build build --target help` to list available targets for a Makefiles or Ninja build.

This guide is tailored from OpenJK's broader [compilation guide](https://github.com/JACoders/OpenJK/wiki/Compilation-guide) and TaystJK's current CMake options.
