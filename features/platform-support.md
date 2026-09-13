---
title: "Platform support"
layout: reference
nav_order: 10
parent: "Features"
description: "Features whose availability depends on your operating system or processor architecture."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Platform support

<p class="page-lede">A few features are compiled in only for certain platforms. If one of these is missing for you, it is not broken — your build never had it.</p>
</div>

Each of these is decided when the client is built, so no cvar will turn it on.

| Feature | Available on | Absent on |
|:--|:--|:--|
| EAX environmental audio | 32-bit Windows | 64-bit Windows, Linux, macOS |
| Discord Rich Presence | x86-64 Windows, Linux and macOS | Apple Silicon macOS, ARM Linux |
| Steam playtime and overlay | Windows | Linux, macOS |

## EAX is 32-bit Windows only

The EAX headers are compiled in only under MSVC
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/CMakeLists.txt#L497)),
so it never exists outside Windows at all.

On Windows it is narrower still. The sound code asks for `EAXMan64.dll` in a 64-bit build
and `EaxMan.dll` otherwise
([`snd_dma.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/client/snd_dma.cpp#L5399)),
but the installer ships `EaxMan.dll` only for 32-bit builds — a 64-bit install gets
`OpenAL32.x86_64.dll` and nothing else
([`InstallConfig.cmake`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/cmake/Modules/InstallConfig.cmake#L78)).
The 64-bit path therefore looks for a library that is never shipped, and EAX quietly stays
off.

If you want EAX, you need a 32-bit Windows build. There is no configuration that changes
this.

## Discord Rich Presence needs x86-64

Rich Presence is compiled in only where a prebuilt `discord-rpc` library exists for the
target
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/CMakeLists.txt#L415)).
The macOS and Linux branches both require `Architecture MATCHES "x86_64"`, and Windows is
covered for both 32- and 64-bit MSVC.

An Apple Silicon build matches none of those branches, so the `DISCORD` define is never set
and the feature is absent rather than disabled. The same applies to ARM Linux. Running an
x86-64 build under Rosetta is compiled differently and is not the same thing as an arm64
build.

The Windows AddressSanitizer build does not have it either, for an unrelated reason — see
[the AddressSanitizer build](/TaystJK/features/builds-and-versioning/#the-addresssanitizer-build).

## Steam integration is Windows only

`Sys_SteamInit` has a real implementation only in the Windows platform layer. The Unix one
is an empty function whose comment says as much — "Only Windows has this feature at the
moment"
([`sys_unix.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_unix.cpp#L650)).

This is not a build-time choice you can change: on Linux and macOS there is no code to
enable. `com_steamIntegration` still exists and still defaults to `1` there, because it is
registered in shared code — so the cvar being on is not evidence the feature is doing
anything.

Even on Windows it needs two files you have to supply yourself, and the commonly available
package is 32-bit only. Setting it up is covered on the
[install page](/TaystJK/install/#steam-playtime-and-overlay).

## Renderers

Which renderer backends exist in your build is also a build-time choice, and a missing one
falls back to the default with a message rather than failing. See
[Renderers](/TaystJK/features/renderers/).

