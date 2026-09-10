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

1. Extract the TaystJK archive and copy its `.app` bundle to a directory you control.
2. Put the retail `base` directory beside the app, or point the app at an existing Jedi Academy installation with `fs_cdPath` as described below.
3. Launch the app. User data is stored under `~/Library/Application Support/TaystJK/`.

The [release workflow](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/.github/workflows/build.yml#L435) ad-hoc signs the universal app before packaging, so a normal installation does not need another `codesign` command. If macOS quarantines the downloaded app and refuses to open it, clear that attribute from the extracted bundle:

```bash
xattr -dr com.apple.quarantine "/path/to/taystjk.app"
```

Run this without `sudo` when the app is in a directory you own. Use `sudo` only if `xattr` reports a permissions error and you have confirmed the path is the intended TaystJK bundle. Quarantine alone is not a reason to re-sign the app. You can verify the packaged signature with:

```bash
codesign --verify --deep --strict "/path/to/taystjk.app"
```

If verification fails, re-extract a fresh copy of the official archive rather than blindly signing the damaged copy. The separate `moveandsign.sh` workflow described in the [debugging guide](/TaystJK/development/debugging/#macos-move-and-sign-the-installed-build) is for locally built development binaries.

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

## Run TaystJK with another client-side mod

The TaystJK executable is the engine. The game, client-game, and UI modules are separate native libraries:

| Module | Windows example | Linux example | Purpose |
|:--|:--|:--|:--|
| Game | `jampgamex86_64.dll` | `jampgamex86_64.so` | Server-side game rules; also used by a locally hosted game. |
| Client game | `cgamex86_64.dll` | `cgamex86_64.so` | Client-side prediction, HUD, and world presentation. |
| UI | `uix86_64.dll` | `uix86_64.so` | Menus and other UI behavior. |

macOS uses the equivalent `.dylib` files. TaystJK does not currently execute QVM bytecode; both its current module API and the older `dllEntry`/`vmMain` API load native libraries. A module must match the operating system and CPU architecture of the TaystJK executable.

### What `fs_forcegame` does

On a normal client, `fs_forcegame` defaults to `taystjk`. This keeps TaystJK's directory at the highest filesystem priority when a server supplies a different `fs_game`, and keeps configs, demos, screenshots, and other generated files under `taystjk/`. A server cannot change `fs_forcegame`.

The default is therefore appropriate when you want TaystJK's client-side files and settings while joining servers that run JA+, JA++, jaPRO, or another server-side mod. You can state it explicitly in a shortcut or launch script:

```text
taystjk.x86_64.exe +set fs_forcegame taystjk
```

Use the executable name for your platform. Do not add `fs_game` merely to join a server; the server sends its own game directory during connection.

Native libraries are a separate concern: when a matching loose library exists in the server-selected `fs_game` directory, the engine tries that library before the copy in `taystjk/`. Keep other mods' native client libraries out of a clean TaystJK installation unless you intend to load them.

To deliberately use another mod's client-side libraries and assets, install them in that mod's directory and select it at startup. For example, JA++ uses `japlus/` for compatibility with JA+:

```text
taystjk.x86_64.exe +set fs_game japlus +set fs_forcegame japlus
```

Setting both values loads the mod from the beginning—including a custom UI—and prevents a later server-provided `fs_game` from changing the directory used for files and generated output. To return to the normal TaystJK client setup, remove the `fs_game japlus` argument and either remove the `fs_forcegame` argument or set it back to `taystjk`.

### When to use `vm_legacy`

TaystJK first expects the newer OpenJK-style `GetModuleAPI` interface and normally falls back to the older `dllEntry`/`vmMain` interface. `vm_legacy` skips the newer interface for selected module slots. Use it when the particular native mod library requires the older interface or crashes while the engine probes it as a newer module; it does not enable QVM support.

`vm_legacy` is a bitmask:

| Bit | Value | Module |
|:--|:--|:--|
| 0 | `1` | Game (`jampgame`), relevant to a local or dedicated server. |
| 1 | `2` | Client game (`cgame`). |
| 2 | `4` | UI (`ui`). |

Add values to force more than one module. For example, an older JA++ build with a legacy custom UI can be launched with:

```text
taystjk.x86_64.exe +set fs_game japlus +set fs_forcegame japlus +set vm_legacy 4
```

Use `vm_legacy 6` only when both the JA++ `cgame` and UI libraries require the legacy interface. Use `vm_legacy 0` for modern libraries, including JA++ builds that implement `GetModuleAPI`. Put this setting on the command line so it is applied before the UI and client-game modules load; changing it after a module has loaded does not convert that running module.

If the console reports `VM_CreateLegacy: ... succeeded`, the requested legacy interface loaded. If it reports an architecture mismatch, a missing entry point, or repeated load failures, recheck the mod build and directory rather than trying unrelated bit values.

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
