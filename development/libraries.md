---
title: "Libraries and versions"
layout: reference
parent: "Development"
nav_order: 3
description: "Bundled and optional third-party libraries used by the current TaystJK source tree."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Dependency inventory</p>

# Libraries and versions

<p class="page-lede">Versions below are read from TaystJK source commit <code>d843fa409b7</code>. A build that uses system libraries can end up with different versions; its configure log has the real ones.</p>
</div>

## Versioned source dependencies

| Library | Version in tree | How TaystJK uses it | Evidence |
|:--|:--|:--|:--|
| SDL 2 | 2.32.4 | Windowing, input, audio, and platform integration; bundled by default on Windows and macOS, system-provided by default on Linux. | [`SDL_version.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/SDL2/include/SDL_version.h#L59) |
| OpenAL Soft | 1.25.2 | OpenAL sound backend with software EAX; fetched and built from source by CMake and packaged with the client on Windows (MSVC), Linux and macOS. | [`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/CMakeLists.txt#L595) |
| EalMan | upstream commit `7c19ff8` | Portable reimplementation of Creative's EAX Manager (`EaxMan.dll`) that reads the game's `.eal` environment files; built as a static library with the OpenAL backend. | [`lib/EalMan/readme.txt`](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/lib/EalMan/readme.txt#L4) |
| libpng | 1.6.53 | PNG image loading for renderer builds. | [`png.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/libpng/include/png.h#L3) |
| zlib | 1.3.1 | Deflate compression and PK3 support. | [`zlib.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/zlib/include/zlib.h#L40) |
| minizip | from zlib 1.3.1 | ZIP/PK3 reading; always uses TaystJK's modified bundled copy. | [`lib/minizip/CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/minizip/CMakeLists.txt#L37) |
| IJG libjpeg | 9c | Default bundled JPEG implementation. | [`jversion.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/jpeg-9c/jversion.h#L12) |
| libjpeg-turbo | 3.1.4.1 | Optional configure-time replacement when `UseTurboJPEG=ON`; fetched by CMake. | [`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/CMakeLists.txt#L507) |
| cJSON | 1.7.16 | JSON parsing in the client game module. | [`cJSON.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/cJSON/include/cJSON.h#L81) |
| Mongoose | 7.13 | Embedded HTTP server and HTTP client used by downloads. | [`mongoose.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/mongoose/include/mongoose.h#L23) |
| gsl-lite | 0.41.0 | Header-only bounds and safety helpers. | [`gsl-lite.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/lib/gsl-lite/include/gsl/gsl-lite.h#L33) |
| SQLite | 3.8.5 | Embedded database used by the game module. | [`sqlite3.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/sqlite3.h#L110) |
| libcurl headers | 7.15.5 | Legacy game-module HTTP interface headers. | [`curlver.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/curl/curlver.h#L31) |

## Bundled binaries without recorded upstream versions

TaystJK also carries prebuilt Discord RPC libraries for some platforms. Nothing in the repository records which upstream release they are, so identify them by the commit that added them and the file's hash.

| Library | Selection | Source evidence |
|:--|:--|:--|
| Discord RPC | Prebuilt per-platform archives, controlled by `BuildDiscordRichPresence`. | [Discord RPC selection](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/CMakeLists.txt#L415) |

## Bundled versus system libraries

Windows defaults to bundled zlib, libpng, libjpeg, and SDL 2. macOS defaults to bundled zlib, libpng, libjpeg, and SDL 2. Other Unix-like systems normally use libraries found by CMake, except for the always-bundled modified minizip, cJSON, Mongoose, gsl-lite, and embedded SQLite source.

OpenAL Soft is bundled by default on every platform, provided the toolchain can build it: it needs CMake 3.18 or newer and, with GCC, GCC 12 or newer. With an older toolchain `UseInternalOpenAL` defaults to `OFF`
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/CMakeLists.txt#L64))
and CMake looks for a system OpenAL instead; if it finds none, it warns and builds the client without the OpenAL backend, leaving only the software mixer
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/d843fa409b7e269a3775392e569f8f4694a7cb25/CMakeLists.txt#L566)).
MinGW builds and builds without the client skip OpenAL entirely. `BuildOpenALSupport=OFF` does the same on purpose; the Windows XP compatibility workflow uses it because its toolchain cannot build OpenAL Soft.

The bundled OpenAL Soft is configured with EAX enabled on every platform, and EalMan is linked into the client, so EAX environmental audio works in software on all of them; Creative or other EAX-capable hardware is not required. On Windows the library is named `OpenALSoft.x86.dll` or `OpenALSoft.x86_64.dll` so it cannot collide with the retail game's `OpenAL32.dll`. On Linux it is installed beside the client as `libopenal.so.1`, and on macOS it goes in the app bundle's `Frameworks`.

A system OpenAL usually has no EAX. Upstream OpenAL Soft only enables EAX by default on Windows, so a Linux build linked against a distribution's OpenAL generally gets the OpenAL backend without the environmental effects.

The relevant switches are `UseInternalOpenAL`, `BuildOpenALSupport`, `UseInternalZlib`, `UseInternalPNG`, `UseInternalJPEG`, `UseTurboJPEG`, and `UseInternalSDL2`. CMake records its actual choices in the configure output and `CMakeCache.txt`.

Release builds set `UseTurboJPEG=ON` on every platform
([`build.yml`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/.github/workflows/build.yml#L96)).
On x86 and x86-64, including the Intel half of a universal macOS build, libjpeg-turbo needs
the [NASM](https://www.nasm.us/) assembler for its SIMD code. Without it CMake only prints a
warning and builds the slower plain-C version
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/CMakeLists.txt#L488)), so
install NASM if you want your build to match a release.

When reporting a dependency bug, include:

1. The TaystJK commit and build configuration.
2. The value of each `UseInternal…` option.
3. The runtime library version where it can differ from the header version.
4. The operating system and architecture.
