---
title: "Install TaystJK"
layout: reference
nav_order: 2
description: "Install TaystJK on Windows, Linux, or macOS without conflicting with other Jedi Academy clients."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Install TaystJK

<p class="page-lede">TaystJK replaces the multiplayer executable, not the retail game data. Keep the four Jedi Academy asset archives and place TaystJK beside—or deliberately separate from—them.</p>
</div>

## Before you start

You need a legal Jedi Academy installation and these files from its `GameData/base` directory:

```text
assets0.pk3
assets1.pk3
assets2.pk3
assets3.pk3
```

Download the build for your operating system from the [latest TaystJK release](https://github.com/taysta/TaystJK/releases/tag/latest). Extract the whole archive; do not copy only the executable, because the renderer and game libraries beside it are also required.

## Install for your platform

Choose your operating system to see its prerequisites and installation steps. Your selection is saved on this device.

<section class="platform-guide" data-platform-guide>
  <div class="platform-selector-shell">
    <p class="platform-selector-label">Operating system</p>
    <div class="platform-selector" role="tablist" aria-label="Operating system">
      <button type="button" id="platform-tab-windows" role="tab" aria-controls="platform-panel-windows" aria-selected="false" tabindex="-1" data-platform-choice="windows">Windows</button>
      <button type="button" id="platform-tab-linux" role="tab" aria-controls="platform-panel-linux" aria-selected="false" tabindex="-1" data-platform-choice="linux">Linux</button>
      <button type="button" id="platform-tab-macos" role="tab" aria-controls="platform-panel-macos" aria-selected="false" tabindex="-1" data-platform-choice="macos">macOS</button>
    </div>
  </div>

  <section class="platform-panel" id="platform-panel-windows" role="tabpanel" aria-labelledby="platform-tab-windows" tabindex="0" data-platform-panel="windows" markdown="1">
## Windows

### Install prerequisites

Install the latest supported [Microsoft Visual C++ Redistributable](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170):

- Install the **x64** package for `TaystJK-windows-x86_64`.
- Install the **x86** package for `TaystJK-windows-x86`.

The release archive includes the matching SDL 2 and OpenAL DLLs. Keep those files beside the TaystJK executable; do not download replacement DLLs from third-party DLL sites.

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. In Steam, right-click **STAR WARS Jedi Knight: Jedi Academy**, then choose **Manage → Browse local files**. Open `GameData`.
2. Extract the TaystJK Windows archive into `GameData`.
3. Start the executable included for your architecture, normally `taystjk.x86_64.exe` on 64-bit Windows.
4. Optionally create a desktop shortcut to that executable.

For a non-Steam copy, locate the directory containing `base`, `jamp.exe`, and `jasp.exe`; that is the `GameData` directory.
  </section>

  <section class="platform-panel" id="platform-panel-linux" role="tabpanel" aria-labelledby="platform-tab-linux" tabindex="0" data-platform-panel="linux" markdown="1">
## Linux

### Install prerequisites

The Linux client uses system-provided SDL 2, OpenGL, JPEG, PNG, zlib, and C++ runtime libraries. For the 64-bit release on Ubuntu 22.04, install them with:

```bash
sudo apt update
sudo apt install libsdl2-2.0-0 libgl1 libjpeg-turbo8 libpng16-16 zlib1g libstdc++6
```

Ubuntu 24.04 names the PNG package `libpng16-16t64`. Other distributions provide the same libraries under their own package names; for example:

```bash
# Fedora
sudo dnf install SDL2 libglvnd-glx libjpeg-turbo libpng zlib libstdc++

# Arch Linux
sudo pacman -S sdl2 libglvnd libjpeg-turbo libpng zlib
```

The 32-bit TaystJK build needs 32-bit versions of the same libraries. Prefer the x86_64 release unless you specifically need 32-bit compatibility. TaystJK's [Linux release job](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/workflows/build.yml#L158) records the libraries against which the official archive is built.

If the loader still reports a missing library, run:

```bash
ldd ./taystjk.x86_64 | grep "not found"
```

Install the missing library from your distribution's package manager rather than copying a loose `.so` file beside the executable.

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. Create a clean directory such as `~/.local/share/TaystJK` and extract the Linux archive there.
2. Create `~/.local/share/TaystJK/base` and copy `assets0.pk3` through `assets3.pk3` into it.
3. Make the client executable if necessary: `chmod +x taystjk.x86_64`.
4. Launch `./taystjk.x86_64`.

If the retail files are only available through Steam, SteamCMD can download app `6020` after setting `@sSteamCmdForcePlatformType windows`; only the platform-neutral PK3 assets are needed from that download.
  </section>

  <section class="platform-panel" id="platform-panel-macos" role="tabpanel" aria-labelledby="platform-tab-macos" tabindex="0" data-platform-panel="macos" markdown="1">
## macOS

### Install prerequisites

Current TaystJK releases bundle SDL 2 inside the app, along with the non-system image and compression libraries. No Homebrew package is required for the current prebuilt app. If an older archive reports a missing SDL library, replace it with the current release; `brew install sdl2` is only relevant to an older system-linked build or a source build configured with `UseInternalSDL2=OFF`.

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. Open the TaystJK disk image and copy `TaystJK.app` to a directory you control.
2. Put the retail `base` directory beside the app, or point the app at an existing Jedi Academy installation with `fs_cdPath` as described below.
3. Launch `TaystJK.app`. User data is stored under `~/Library/Application Support/TaystJK/`.

On Apple silicon, use the universal or native arm64 release. Intel Macs need the x86_64 release.
  </section>
</section>

## Installing several modded clients

Do not merge every client's executables and shared libraries into one `GameData` directory. Different projects—or 32-bit and 64-bit builds of the same project—may ship incompatible `SDL2` or `OpenAL` libraries.

### Recommended: one shared asset directory

Keep the retail assets once and give every client its own directory:

```text
MyGames/
├── JediAcademy/
│   └── base/
│       ├── assets0.pk3
│       ├── assets1.pk3
│       ├── assets2.pk3
│       └── assets3.pk3
├── TaystJK/
│   ├── taystjk/
│   │   └── japro-assets.pk3
│   ├── taystjk.x86_64.exe
│   └── run-taystjk.bat
└── AnotherClient/
    ├── another-client files…
    └── run-client.bat
```

On Windows, put this beside the TaystJK executable as `run-taystjk.bat`:

```bat
@echo off
start "" taystjk.x86_64.exe +set fs_cdPath "../JediAcademy"
```

Use the executable name that actually appears in your release archive. On Linux, the equivalent launch command is:

```bash
./taystjk.x86_64 +set fs_cdPath ../JediAcademy
```

`fs_cdPath` supplies the shared retail assets while TaystJK keeps its own executable, libraries, mod directory, and user files separate.

### Simpler alternative: copy `base`

Copy the complete retail `base` directory into each client's directory. This uses more disk space, but needs no launch script and keeps each installation self-contained.

Put PK3s that should affect every client in that client's `base` directory. Put TaystJK-only content in `taystjk/`, beside `japro-assets.pk3`.

## First-launch checks

- Open the console with <kbd>Shift</kbd> + <kbd>~</kbd> and run `version` to confirm that TaystJK is running.
- If the console reports that it cannot find `default.cfg`, TaystJK cannot see `base/assets0.pk3`. Recheck the extraction directory or `fs_cdPath`.
- If the client cannot load a renderer or library, re-extract the complete release, confirm its architecture, and revisit the platform prerequisites above.
- If settings or downloaded PK3s appear in an unexpected place, run `path` in the console and inspect `fs_homepath`, `fs_basepath`, and `fs_game`.

This layout is adapted from the longer [multiple modded clients guide on JKHub](https://jkhub.org/tutorials/errors-problems/how-to-install-multiple-modded-clients-on-the-same-system-r229/).

## Next steps

- [Host a dedicated server](/TaystJK/server-hosting/)
- [Search cvars and commands](/TaystJK/reference/)
- [Compile TaystJK from source](/TaystJK/development/compiling/)
