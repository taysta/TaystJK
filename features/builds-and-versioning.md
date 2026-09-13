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

<!-- TODO: portable and debug build variants, and the Windows AddressSanitizer artifact,
     are named in the planning notes but were not verified for this page. Check
     BuildPortableVersion and the build workflow before describing them. -->
