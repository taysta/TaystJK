---
title: "Install TaystJK"
layout: reference
nav_order: 2
description: "Install TaystJK on Windows, Linux, or macOS without conflicting with other Jedi Academy clients."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Install TaystJK

<p class="page-lede">TaystJK replaces the multiplayer executable, not the retail game data. Keep the four Jedi Academy asset archives and place TaystJK beside them, or deliberately separate from them.</p>
</div>

This section also covers [platform support](/TaystJK/install/platform-support/),
[builds and versioning](/TaystJK/install/builds-and-versioning/) and
[mod compatibility](/TaystJK/install/mod-compatibility/).

## Before you start

You need a legal Jedi Academy installation and these files from its `GameData/base` directory:

```text
assets0.pk3
assets1.pk3
assets2.pk3
assets3.pk3
```

Download the build for your operating system from the [latest TaystJK release](https://github.com/taysta/TaystJK/releases/tag/latest). Extract the whole archive; do not copy only the executable, because the renderer and game libraries beside it are also required.

If you also install an older mod, check whether it keeps its native modules inside a
PK3. TaystJK does not unpack those modules by default; see
[mods that package native libraries inside a PK3](#mods-that-package-native-libraries-inside-a-pk3)
before assuming that the mod is incompatible.

## Install for your platform

Choose your operating system to see its prerequisites and installation steps. Your selection is saved on this device.

<section class="platform-guide" data-platform-guide>
  <div class="platform-selector-shell">
    <p class="platform-selector-label">Operating system</p>
    <div class="platform-selector" role="tablist" aria-label="Operating system">
      <button type="button" id="platform-tab-windows" role="tab" aria-controls="platform-panel-windows" aria-selected="false" tabindex="-1" data-platform-choice="windows">Windows</button>
      <button type="button" id="platform-tab-macos" role="tab" aria-controls="platform-panel-macos" aria-selected="false" tabindex="-1" data-platform-choice="macos">macOS</button>
      <button type="button" id="platform-tab-linux" role="tab" aria-controls="platform-panel-linux" aria-selected="false" tabindex="-1" data-platform-choice="linux">Linux</button>
    </div>
  </div>

  <section class="platform-panel" id="platform-panel-windows" role="tabpanel" aria-labelledby="platform-tab-windows" tabindex="0" data-platform-panel="windows" markdown="1">
## Windows

### Install prerequisites

Install the latest supported [Microsoft Visual C++ Redistributable](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170):

- Install the **x64** package for `TaystJK-windows-x86_64`.
- Install the **x86** package for `TaystJK-windows-x86`.

The release archive includes the matching SDL 2 and OpenAL DLLs. Keep those files beside the TaystJK executable; do not download replacement DLLs from third-party DLL sites.

Prefer the **64-bit build** for normal play, especially when using rend2. Rend2 can use enough memory to exhaust a 32-bit process's limited address space on demanding maps or asset sets; the 64-bit build has substantially more headroom.

The **32-bit Windows build** has one compatibility advantage: its bundled OpenAL Soft library and `EaxMan.dll` can provide EAX environmental audio in software, so EAX-capable sound hardware is not required. TaystJK does not currently ship the `EaxMan64.dll` needed by its 64-bit EAX path, so this feature is available only in the 32-bit build. Choose x86 if you specifically want EAX or require another 32-bit compatibility feature, and keep `OpenAL32.dll` and `EaxMan.dll` beside the executable.

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. In Steam, right-click **STAR WARS Jedi Knight: Jedi Academy**, then choose **Manage → Browse local files**. Open `GameData`.
2. Extract the TaystJK Windows archive into `GameData`.
3. Start the executable included for your architecture, normally `taystjk.x86_64.exe` on 64-bit Windows.
4. Optionally create a desktop shortcut to that executable.

For a non-Steam copy, locate the directory containing `base`, `jamp.exe`, and `jasp.exe`; that is the `GameData` directory.

### Optional: update automatically

[TaystJK Updater](https://github.com/slash-fr/taystjk-updater) is a third-party launcher by Slash; it is not part of TaystJK. If something goes wrong only when you start the game through the updater, report it on the updater's repository; if it also happens when you start TaystJK directly, it is ours. Each time you start it, it checks the `latest` TaystJK release, downloads and installs a newer Windows build if there is one, and then launches the game. It also keeps itself up to date.

<figure class="media-figure">
  <video controls muted playsinline preload="none" width="1280" height="720" poster="{{ '/assets/media/taystjk-updater-demo-poster.jpg' | relative_url }}">
    <source src="{{ '/assets/media/taystjk-updater-demo.mp4' | relative_url }}" type="video/mp4">
    <a href="{{ '/assets/media/taystjk-updater-demo.mp4' | relative_url }}">Download the updater demo video</a>.
  </video>
  <figcaption>An older build is closed and the <code>TaystJK</code> desktop shortcut, which points at the updater, installs the new release and starts it. The <code>version</code> command then shows the new build. Video by Slash.</figcaption>
</figure>

1. Download `TaystJK_Updater.exe` from its [releases page](https://github.com/slash-fr/taystjk-updater/releases).
2. Put it in the same directory as `taystjk.x86_64.exe` or `taystjk.x86.exe`.
3. Start the game from the updater, or from a shortcut to it, instead of from the TaystJK executable. You can rename the shortcut to `TaystJK` and pick the TaystJK executable as its icon.

It needs .NET Framework 4.8, which Windows 10 and 11 already include. The TaystJK directory must be writable without administrator rights. Do not run the updater as administrator, because it would then start TaystJK as administrator too.

Arguments after the updater's name are passed on to TaystJK, so the launch options elsewhere on this page work through it. If the directory holds both builds, or the updater lives somewhere else, give the executable's path first:

```bat
TaystJK_Updater.exe taystjk.x86_64.exe +set fs_cdPath "../JediAcademy"
```

The updater's [advanced usage notes](https://github.com/slash-fr/taystjk-updater/blob/main/doc/advanced-usage.md) cover the arguments in more detail.
  </section>

  <section class="platform-panel" id="platform-panel-macos" role="tabpanel" aria-labelledby="platform-tab-macos" tabindex="0" data-platform-panel="macos" markdown="1">
## macOS

### Install prerequisites

Current TaystJK releases bundle SDL 2 inside the app, along with the non-system image and compression libraries. No Homebrew package is required for the current prebuilt app. If an older archive reports a missing SDL library, replace it with the current release; `brew install sdl2` is only relevant to an older system-linked build or a source build configured with `UseInternalSDL2=OFF`.

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. Extract the TaystJK archive and copy its `.app` bundle to a directory you control.
2. Put the retail `base` directory beside the app, or point the app at an existing Jedi Academy installation with `fs_cdPath` as described below.
3. Launch the app. Release builds are portable, so configs, screenshots and downloads are
   written beside the app, in the directory that holds it, rather than under
   `~/Library/Application Support`
   ([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/sys/sys_main.cpp#L700));
   see [builds and versioning](/TaystJK/install/builds-and-versioning/#every-published-build-is-portable).

The [release workflow](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/.github/workflows/build.yml#L433) ad-hoc signs the universal app before packaging, so a normal installation does not need another `codesign` command. If macOS quarantines the downloaded app and refuses to open it, clear that attribute from the extracted bundle:

```bash
xattr -dr com.apple.quarantine "/path/to/taystjk.app"
```

Run this without `sudo` when the app is in a directory you own. Use `sudo` only if `xattr` reports a permissions error and you have confirmed the path is the intended TaystJK bundle. Quarantine alone is not a reason to re-sign the app. You can verify the packaged signature with:

```bash
codesign --verify --deep --strict "/path/to/taystjk.app"
```

If verification fails, re-extract a fresh copy of the official archive rather than blindly signing the damaged copy. The separate `moveandsign.sh` workflow described in the [debugging guide](/TaystJK/development/debugging/#move-and-sign-the-installed-build) is for locally built development binaries.

On Apple silicon, use the universal or native arm64 release. Intel Macs need the x86_64 release.
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

The 32-bit TaystJK build needs 32-bit versions of the same libraries. Prefer the x86_64 release unless you specifically need 32-bit compatibility. TaystJK's [Linux release job](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/.github/workflows/build.yml#L158) records the libraries against which the official archive is built.

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

</section>

## Installing several modded clients

Do not merge every client's executables and shared libraries into one `GameData` directory. Different projects, or 32-bit and 64-bit builds of the same project, may ship incompatible `SDL2` or `OpenAL` libraries.

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

### Mods that package native libraries inside a PK3

Many older mods put `cgame`, `ui`, or `jampgame` native libraries inside a PK3. TaystJK
still mounts the PK3 and reads its assets, but it does not unpack and execute those
libraries by default: [`com_unpackLibraries`](/TaystJK/reference/cvars/com_unpacklibraries-27a5b09/)
defaults to `0`, and both module loaders only try PK3 unpacking when it is enabled
([registration](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L179),
[legacy loader](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L493),
[OpenJK-style loader](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_main.cpp#L575)).
This can make an old mod's assets appear while its custom HUD, menus, or game code does
not load.

The preferred fix is to extract the native libraries from the mod's PK3 and place them
beside that PK3 in the mod directory. Keep the PK3 because the mod may still need its
maps, menus, shaders, and other assets. For a 32-bit Windows mod, the result commonly
looks like this:

```text
japlus/
├── mod-assets.pk3
├── cgamex86.dll
├── uix86.dll
└── jampgamex86.dll
```

Only extract files from a mod you trust. Native modules are executable code, not passive
assets. The names and architecture must match the TaystJK build: an `x86.dll` from an old
mod cannot be loaded by the 64-bit client. Use the 32-bit Windows build for a mod that
provides only 32-bit Windows modules, or obtain modules built for your platform and
architecture.

On Windows, you can instead opt back into the old unpacking behavior for a trusted mod by
setting the cvar at startup:

```text
taystjk.x86.exe +set fs_game japlus +set fs_forcegame japlus +set com_unpackLibraries 1
```

`com_unpackLibraries` is an initialization cvar, so put it on the command line rather
than changing it after launch. This fallback is implemented on Windows. It does not
extract ordinary `.so` or `.dylib` modules on Linux or macOS, so install those as loose
native libraries
([Windows unpacker](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_win32.cpp#L603),
[Unix behavior](https://github.com/taysta/TaystJK/blame/f4643281440c626cb7e30444c8c392606167a7f8/shared/sys/sys_unix.cpp#L566)).

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

Setting both values loads the mod from the beginning, including a custom UI, and prevents a later server-provided `fs_game` from changing the directory used for files and generated output. To return to the normal TaystJK client setup, remove the `fs_game japlus` argument and either remove the `fs_forcegame` argument or set it back to `taystjk`.

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

## Steam playtime and overlay

Optional, and **Windows only**. `Sys_SteamInit` is an empty stub everywhere else
([`sys_unix.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/sys/sys_unix.cpp#L655)).

With it working, Steam counts your TaystJK time against Jedi Academy and the overlay works,
without having to launch the client through Steam.

`com_steamIntegration` is already **on by default**
([`common.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/codemp/qcommon/common.cpp#L1452)), so there is nothing to enable. It
does nothing until you supply two files, neither of which ships with TaystJK or with retail
Jedi Academy. Put both in `GameData`, beside the executable:

| File | Which build |
|:--|:--|
| `steam_api64.dll` | 64-bit TaystJK |
| `steam_api.dll` | 32-bit TaystJK |
| `steam_appid.txt` containing `6020` | both |

`6020` is Jedi Academy's Steam app ID.

**Mind the architecture.** The
[Steam Integration Tools](https://jkhub.org/files/file/3549-steam-integration-tools/)
package on JKHub is the usual source for these, but it provides the **32-bit**
`steam_api.dll` only. If you run the 64-bit build, as most people do, that package
alone will not work; you need `steam_api64.dll`, which comes from the Steamworks SDK.

If the file is missing the client says so at startup in red, and otherwise runs normally:

```text
Steam integration failed: Couldn't find steam_api64.dll
```

The cvar is latched, so a change needs a restart. Set `com_steamIntegration 0` to stop the
client looking at all.

Why you have to supply these: the Steamworks SDK's terms do not fit TaystJK's GPLv2
licence, so the library cannot be bundled. The client loads it at runtime if it finds it,
which keeps the licences apart
([`sys_win32.cpp`](https://github.com/taysta/TaystJK/blame/77d84176b3b94356d189a4420e1bc5e68c88e1ea/shared/sys/sys_win32.cpp#L714)).

## First-launch checks

- Open the console with <kbd>Shift</kbd> + <kbd>~</kbd> and run `version` to confirm that TaystJK is running.
- If the console reports that it cannot find `default.cfg`, TaystJK cannot see `base/assets0.pk3`. Recheck the extraction directory or `fs_cdPath`.
- If the client cannot load a renderer or library, re-extract the complete release, confirm its architecture, and revisit the platform prerequisites above.
- If settings or downloaded PK3s appear in an unexpected place, run `path` in the console and inspect `fs_homepath`, `fs_basepath`, and `fs_game`.

This layout is adapted from the longer [multiple modded clients guide on JKHub](https://jkhub.org/tutorials/errors-problems/how-to-install-multiple-modded-clients-on-the-same-system-r229/).

## Next steps

- [What this client adds](/TaystJK/features/): the HUD tools, movement styles and cosmetics
- [Something is wrong](/TaystJK/troubleshooting/): listed by symptom, including the macOS
  and modded-server cases above
- [Host a dedicated server](/TaystJK/server-hosting/)
- [Search cvars and commands](/TaystJK/reference/)
- [Compile TaystJK from source](/TaystJK/development/compiling/)

{% include browse-grid.html section="install" %}
