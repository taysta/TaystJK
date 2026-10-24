---
title: "Builds and versioning"
layout: reference
nav_order: 2
parent: "Install TaystJK"
description: "How TaystJK releases are identified, what your build reports, and how to read it in a bug report."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Builds and versioning

<p class="page-lede">There are no version numbers. Each release replaces the last under the same tag, and a build identifies itself by the date it was compiled.</p>
</div>

## What your build reports

Two commands, and they answer about different halves of the client.

```text
version        the engine
modversion     the game module
```

`version` ends with the date the engine was compiled
([`common.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/qcommon/common.cpp#L1504)).
`modversion` prints the date and time the game module was compiled, followed by an
identifier like `latest-build-6ff04c0ba`
([`CG_ModVersion_f`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/cgame/cg_consolecmds.c#L561)).

Both halves come from the build. `GIT_TAG` is whatever `git describe --tags --abbrev=0`
found and `GIT_HASH` is `git rev-parse --short HEAD`
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/CMakeLists.txt#L411)).
Built outside a Git checkout, both read `vUNKNOWN`.

## Release channels

Three releases are rebuilt in place rather than numbered:

| Release | Built from | When |
|:--|:--|:--|
| [`latest-build`](https://github.com/taysta/TaystJK/releases/latest) | `master` | Every push to `master` ([`build.yml`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build.yml#L501)). This is the one to install. |
| [`latest-beta`](https://github.com/taysta/TaystJK/releases) | `beta` | Every push to `beta`, marked as a pre-release ([`build.yml`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build.yml#L555)). Only when you have been asked to test something. |
| [`winxp`](https://github.com/taysta/TaystJK/releases/tag/winxp) | `master` | Every four months, and when a release is published ([`build-winxp.yml`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build-winxp.yml#L4)). For Windows XP only. |

`latest-build` and `latest-beta` carry the same set of archives; the [install guide](/TaystJK/install/#before-you-start)
lists which one to download for your system.

## Compare the date, not the tag

Each new build deletes the release and creates it again on the new commit, so `git describe`
finds the same tag name every time. The tag part of the identifier reads `latest-build` on
every build and does not tell one release from the next.

The hash does not order builds either. Two short hashes cannot be ranked against each other
without the repository. A later hash is not a "higher" one.

So when you want to know whether your build has something, **compare the date**. The console
reference gives each entry an *Added* date for exactly this purpose; if your build's compile
date is earlier, your build does not have that entry. See
[how to tell what your build has](/TaystJK/features/whats-new/#how-to-tell-what-your-build-has).

The date is strong evidence, not proof. It is the day the build was compiled, not the day
its source was committed
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/CMakeLists.txt#L391)).
`latest-build` is compiled on each push to `master`, so for it the two match. A build compiled later from an older commit, whether the workflow
reran or you built an old checkout yourself, carries the later date. An earlier date still
proves the entry is missing; a later one only suggests it is there. When that matters, the
hash settles it. Each entry's *Added* field links the commit that added it, and in a checkout:

```sh
git merge-base --is-ancestor <added-commit> <your-build-hash> && echo "your build has it"
```

If your clone has also fetched one of the projects TaystJK descends from, you may see
version-like tags such as `1.5.5`. They belong to that project, not to TaystJK, and no
TaystJK build reports them.

## Reporting a build

Paste the whole line rather than summarising it. A useful report says:

- the output of `version` **and** `modversion`, since the engine and the game module are
  built and shipped separately and can differ
- your operating system and whether the build is 32- or 64-bit, because
  [some features exist only on certain platforms](/TaystJK/install/platform-support/)
- which renderer you are running, and whether the problem survives switching to
  `rd-taystjk`; see [Renderers](/TaystJK/features/renderers/)
- the server and the mod it runs, because much of what you see is the server's game module
  rather than the client; see [the overview](/TaystJK/overview/)

## Every published build is portable

Each artifact the build workflow uploads is built with `BuildPortableVersion=ON`
([`build.yml`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build.yml#L33)).

A portable build has no home directory at all: `Sys_DefaultHomePath` returns nothing
([`sys_win32.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/shared/sys/sys_win32.cpp#L168),
[`sys_unix.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/shared/sys/sys_unix.cpp#L481)),
and `fs_homepath` then falls back to the install path
([`files.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/qcommon/files.cpp#L3923)).
Your configs, screenshots, downloaded PK3s and logs are written next to the executable
rather than under your user profile. That is what lets you keep TaystJK entirely separate
from another Jedi Academy installation, and it is why `fs_homepath` and `fs_basepath` read
the same in `path`.

Debug builds are compiled by CI as a check but never archived or uploaded. Only the Release
builds and the AddressSanitizer build below are published ([`build.yml`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build.yml#L144)).

## The AddressSanitizer build

One extra Windows artifact exists for diagnosing crashes: an x86-64 `RelWithDebInfo` build
with AddressSanitizer enabled, shipped with its PDBs, the sanitizer runtime and a
`Run-TaystJK-ASan.bat` launcher
([`build.yml`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build.yml#L116)).

It is slower than a normal build and it has **no Discord Rich Presence**: the prebuilt
`discord-rpc` library cannot link against an ASan-annotated binary, so the build forces the
option off
([`CMakeLists.txt`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/CMakeLists.txt#L263)).

You want this one only when someone investigating a crash asks for a sanitizer log.
Otherwise take the ordinary Release build.
