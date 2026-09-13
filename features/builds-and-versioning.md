---
title: "Builds and versioning"
layout: reference
nav_order: 11
parent: "Features"
description: "How TaystJK releases are identified, what your build reports, and how to read it in a bug report."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Builds and versioning

<p class="page-lede">There are no version numbers. Releases roll under a single tag, and a build identifies itself by the date it was compiled.</p>
</div>

## What your build reports

Two commands, and they answer about different halves of the client.

```text
version        the engine
modversion     the game module
```

`version` ends with the date the engine was compiled
([`common.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/common.cpp#L1354)).
`modversion` prints the date and time the game module was compiled, followed by an
identifier like `latest-6ff04c0ba`
([`CG_ModVersion_f`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_consolecmds.c#L561)).

Both halves come from the build. `GIT_TAG` is whatever `git describe --tags --abbrev=0`
found and `GIT_HASH` is `git rev-parse --short HEAD`
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/CMakeLists.txt#L411)).
Built outside a Git checkout, both read `vUNKNOWN`.

## Why the date is the only useful part

Releases are rolling: the `latest` tag is moved onto each release commit, so `git describe`
finds it every time and the tag reads `latest` on every build. It does not distinguish one
release from the next.

The hash does not order builds either. Two short hashes cannot be ranked against each other
without the repository — a later hash is not a "higher" one.

So when you want to know whether your build has something, **compare the date**. The console
reference gives each entry an *Added* date for exactly this purpose; if your build's compile
date is earlier, your build does not have that entry. See
[how to tell what your build has](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has).

The semver-looking tags in the repository — `1.0` through `1.5.5` and similar — are
inherited from the projects TaystJK descends from. They are not TaystJK releases and no
build reports them.

## Reporting a build

Paste the whole line rather than summarising it. A useful report says:

- the output of `version` **and** `modversion`, since the engine and the game module are
  built and shipped separately and can differ
- your operating system and whether the build is 32- or 64-bit, because
  [some features exist only on certain platforms](/TaystJK/features/platform-support/)
- which renderer you are running, and whether the problem survives switching to
  `rd-taystjk` — see [Renderers](/TaystJK/features/renderers/)
- the server and the mod it runs, because much of what you see is the server's game module
  rather than the client — see [the overview](/TaystJK/overview/)

## Every published build is portable

Each artifact the build workflow uploads is built with `BuildPortableVersion=ON`
([`build.yml`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/workflows/build.yml#L33)).

A portable build has no home directory at all: `Sys_DefaultHomePath` returns nothing
([`sys_win32.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_win32.cpp#L168),
[`sys_unix.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/shared/sys/sys_unix.cpp#L481)),
and `fs_homepath` then falls back to the install path
([`files.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/files.cpp#L3923)).
Your configs, screenshots, downloaded PK3s and logs are written next to the executable
rather than under your user profile. That is what lets you keep TaystJK entirely separate
from another Jedi Academy installation, and it is why `fs_homepath` and `fs_basepath` read
the same in `path`.

Debug builds are compiled by CI as a check but never archived or uploaded — only Release is
published ([`build.yml`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/workflows/build.yml#L144)).

## The AddressSanitizer build

One extra Windows artifact exists for diagnosing crashes: an x86-64 `RelWithDebInfo` build
with AddressSanitizer enabled, shipped with its PDBs, the sanitizer runtime and a
`Run-TaystJK-ASan.bat` launcher
([`build.yml`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/workflows/build.yml#L116)).

It is slower than a normal build and it has **no Discord Rich Presence**: the prebuilt
`discord-rpc` library cannot link against an ASan-annotated binary, so the build forces the
option off
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/CMakeLists.txt#L263)).

You want this one only when someone investigating a crash asks for a sanitizer log.
Otherwise take the ordinary Release build.
