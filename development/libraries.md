---
title: "Libraries and versions"
layout: reference
description: "Bundled and optional third-party libraries used by the current TaystJK source tree."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Dependency inventory</p>

# Libraries and versions

<p class="page-lede">Versions below are read from TaystJK source commit <code>6ff04c0baf58</code>. A system-library build can use different runtime versions; the configure log is authoritative for that build.</p>
</div>

## Versioned source dependencies

| Library | Version in tree | How TaystJK uses it | Evidence |
|:--|:--|:--|:--|
| SDL 2 | 2.32.4 | Windowing, input, audio, and platform integration; bundled by default on Windows and macOS, system-provided by default on Linux. | [`SDL_version.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/SDL2/include/SDL_version.h#L59) |
| libpng | 1.6.53 | PNG image loading for renderer builds. | [`png.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/libpng/include/png.h#L3) |
| zlib | 1.3.1 | Deflate compression and PK3 support. | [`zlib.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/zlib/include/zlib.h#L40) |
| minizip | from zlib 1.3.1 | ZIP/PK3 reading; always uses TaystJK's modified bundled copy. | [`lib/minizip/CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/minizip/CMakeLists.txt#L37) |
| IJG libjpeg | 9c | Default bundled JPEG implementation. | [`jversion.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/jpeg-9c/jversion.h#L12) |
| libjpeg-turbo | 3.1.4.1 | Optional configure-time replacement when `UseTurboJPEG=ON`; fetched by CMake. | [`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/CMakeLists.txt#L507) |
| cJSON | 1.7.16 | JSON parsing in the client game module. | [`cJSON.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/cJSON/include/cJSON.h#L81) |
| Mongoose | 7.13 | Embedded HTTP server and HTTP client used by downloads. | [`mongoose.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/mongoose/include/mongoose.h#L23) |
| gsl-lite | 0.41.0 | Header-only bounds and safety helpers. | [`gsl-lite.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/lib/gsl-lite/include/gsl/gsl-lite.h#L33) |
| SQLite | 3.8.5 | Embedded database used by the game module. | [`sqlite3.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/sqlite3.h#L110) |
| libcurl headers | 7.15.5 | Legacy game-module HTTP interface headers. | [`curlver.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/curl/curlver.h#L31) |

## Bundled binaries without recorded upstream versions

TaystJK also carries prebuilt OpenAL Soft and Discord RPC libraries for selected platforms. Their current files do not expose an upstream release number in the repository, so this documentation does not invent one. The source commit and binary hash are the reliable identifiers until those dependencies gain checked-in version metadata.

| Library | Selection | Source evidence |
|:--|:--|:--|
| OpenAL Soft | Bundled on Windows when `UseInternalOpenAL=ON`; otherwise discovered from the system where supported. | [OpenAL selection](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/CMakeLists.txt#L442) |
| Discord RPC | Prebuilt per-platform archives, controlled by `BuildDiscordRichPresence`. | [Discord RPC selection](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/CMakeLists.txt#L415) |

## Bundled versus system libraries

Windows defaults to bundled OpenAL, zlib, libpng, libjpeg, and SDL 2. macOS defaults to bundled zlib, libpng, libjpeg, and SDL 2. Other Unix-like systems normally use libraries found by CMake, except for the always-bundled modified minizip, cJSON, Mongoose, gsl-lite, and embedded SQLite source.

The relevant switches are `UseInternalOpenAL`, `UseInternalZlib`, `UseInternalPNG`, `UseInternalJPEG`, `UseTurboJPEG`, and `UseInternalSDL2`. CMake records its actual choices in the configure output and `CMakeCache.txt`.

When reporting a dependency bug, include:

1. The TaystJK commit and build configuration.
2. The value of each `UseInternal…` option.
3. The runtime library version where it can differ from the header version.
4. The operating system and architecture.

[Return to development documentation](/TaystJK/development/).
