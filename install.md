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

<p class="page-lede">TaystJK replaces the multiplayer executable, not the game's data. You need the four asset archives from your own copy of Jedi Academy, and TaystJK can sit beside them or in a directory of its own.</p>
</div>

## Before you start

You need a legal Jedi Academy installation and these files from its `GameData/base` directory:

```text
assets0.pk3
assets1.pk3
assets2.pk3
assets3.pk3
```

Download the archive for your system from the [latest release](https://github.com/taysta/TaystJK/releases/latest):

| System | Archive |
|:--|:--|
| Windows, 64-bit | `TaystJK-windows-x86_64.zip` |
| Windows, 32-bit | `TaystJK-windows-x86.zip` |
| macOS, Apple silicon or Intel | `TaystJK-macos-universal2.tar.gz` |
| macOS, one architecture only | `TaystJK-macos-arm64.tar.gz` or `TaystJK-macos-x86_64.tar.gz` |
| Linux, 64-bit | `TaystJK-linux-x86_64.tar.gz` |
| Linux, 32-bit | `TaystJK-linux-x86.tar.gz`, whose executables end in `.i386` |

Extract the whole archive. Do not copy only the executable: the renderer and game libraries
beside it are needed too.

The release also has a `TaystJK-windows-x86_64-AddressSanitizer.zip` for diagnosing crashes;
you only need it if someone asks for a sanitizer log. Builds for Windows XP are published
separately under the [`winxp` release](https://github.com/taysta/TaystJK/releases/tag/winxp).
[Builds and versioning](/TaystJK/install/builds-and-versioning/) explains the release
channels.

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

Use the **64-bit build** unless you have a reason not to. A 32-bit process has at most 2 GB to
work with, and demanding maps or asset sets can run out of that with any renderer.

Install the latest supported [Microsoft Visual C++ Redistributable](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170)
for the build you chose:

- the **x64** package for `TaystJK-windows-x86_64`
- the **x86** package for `TaystJK-windows-x86`

The archive already includes the matching SDL 2 and OpenAL DLLs. Keep them beside the
TaystJK executable, and do not replace them with DLLs from third-party download sites.

The 32-bit build has one thing the 64-bit build lacks: EAX environmental audio, done in
software by its bundled OpenAL Soft and `EaxMan.dll`, so no EAX sound card is needed. Choose
x86 if you want EAX or need another 32-bit compatibility feature, and keep `OpenAL32.dll` and
`EaxMan.dll` beside the executable. See [platform support](/TaystJK/install/platform-support/#eax-is-32-bit-windows-only).

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. In Steam, right-click **STAR WARS Jedi Knight: Jedi Academy**, then choose **Manage → Browse local files**. Open `GameData`.
2. Extract the TaystJK Windows archive into `GameData`.
3. Start the executable for your build: `taystjk.x86_64.exe`, or `taystjk.x86.exe` for 32-bit.
4. Optionally create a desktop shortcut to it.

For a non-Steam copy, find the directory that holds `base`, `jamp.exe` and `jasp.exe`. That is
the `GameData` directory.

### Optional: update automatically

[TaystJK Updater](https://github.com/slash-fr/taystjk-updater) is a third-party launcher by Slash; it is not part of TaystJK. If something goes wrong only when you start the game through the updater, report it on the updater's repository; if it also happens when you start TaystJK directly, it is ours. Each time you start it, it checks the `latest-build` TaystJK release, downloads and installs a newer Windows build if there is one, and then launches the game. It also keeps itself up to date.

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

Take `TaystJK-macos-universal2.tar.gz`, which runs natively on both Apple silicon and Intel
Macs. The `arm64` and `x86_64` archives each run on one of them.

Nothing else needs installing. The app bundles SDL 2 and the image and compression
libraries it uses, so no Homebrew package is required.

Copy the four `assets*.pk3` files from any install of the game. If you own it on Steam and
have no copy to hand, [SteamCMD](https://developer.valvesoftware.com/wiki/SteamCMD), which
runs on macOS, can download the Windows release:

```sh
steamcmd +@sSteamCmdForcePlatformType windows +login <your-steam-name> +app_update 6020 validate +quit
```

Only the PK3s in `GameData/base` are needed from that download.

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. Extract the TaystJK archive and copy its `.app` bundle to a directory you own.
2. Create a `base` directory beside the app and put the four asset files in it, or point the
   app at an existing copy with `fs_cdPath`, as [several modded clients](#installing-several-modded-clients)
   shows.
3. Launch the app. Release builds are portable, so configs, screenshots and downloads are
   written beside the app, in the directory that holds it, not under
   `~/Library/Application Support`
   ([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/shared/sys/sys_main.cpp#L700));
   see [builds and versioning](/TaystJK/install/builds-and-versioning/#every-published-build-is-portable).

The [release workflow](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build.yml#L433)
ad-hoc signs the app, so it does not need signing again. If macOS refuses to open it because
it was downloaded, clear the quarantine attribute from the extracted app:

```sh
xattr -dr com.apple.quarantine "/path/to/taystjk.app"
```

You do not need `sudo` for an app in a directory you own. An update is a fresh download, so
you have to do this again after each one.

If the app still will not open, re-extract it from the archive instead of signing it
yourself. The `moveandsign.sh` script in the [debugging guide](/TaystJK/development/debugging/#move-and-sign-the-installed-build)
is for builds you compiled, not for releases.
  </section>
  <section class="platform-panel" id="platform-panel-linux" role="tabpanel" aria-labelledby="platform-tab-linux" tabindex="0" data-platform-panel="linux" markdown="1">
## Linux

### Install prerequisites

The Linux client uses system-provided SDL 2, OpenGL, JPEG, PNG, zlib, and C++ runtime libraries. For the 64-bit release on Ubuntu 22.04, install them with:

```sh
sudo apt update
sudo apt install libsdl2-2.0-0 libgl1 libjpeg-turbo8 libpng16-16 zlib1g libstdc++6
```

Ubuntu 24.04 names the PNG package `libpng16-16t64`. Other distributions provide the same libraries under their own package names; for example:

```sh
# Fedora
sudo dnf install SDL2 libglvnd-glx libjpeg-turbo libpng zlib libstdc++

# Arch Linux
sudo pacman -S sdl2 libglvnd libjpeg-turbo libpng zlib
```

The 32-bit build needs 32-bit versions of the same libraries, and its executables are named
`taystjk.i386` and `taystjkded.i386`. Prefer the x86_64 release unless you specifically need
32-bit compatibility. TaystJK's [Linux release job](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/.github/workflows/build.yml#L158) records the libraries the official archive is built against.

If the loader still reports a missing library, run:

```sh
ldd ./taystjk.x86_64 | grep "not found"
```

Install the missing library from your distribution's package manager instead of copying a loose `.so` file beside the executable.

### Install TaystJK

This is the simplest layout when TaystJK is your only modded client.

1. Create a clean directory such as `~/.local/share/TaystJK` and extract the Linux archive there.
2. Create `~/.local/share/TaystJK/base` and copy `assets0.pk3` through `assets3.pk3` into it.
3. Make the client executable if necessary: `chmod +x taystjk.x86_64`.
4. Launch `./taystjk.x86_64`.

If you only have the game on Steam, [SteamCMD](https://developer.valvesoftware.com/wiki/SteamCMD)
can download its Windows release, app `6020`, after you set
`@sSteamCmdForcePlatformType windows`. Only the PK3s in `GameData/base` are needed from it.
  </section>

</section>

## First-launch checks

- Open the console with <kbd>Shift</kbd> + <kbd>~</kbd> and run `version` to confirm that TaystJK is running.
- If the game stops with "Couldn't load mpdefault.cfg", TaystJK cannot see the retail `assets*.pk3` files in `base/`. Check where you put them, or your `fs_cdPath`.
- If the client cannot load a renderer or library, re-extract the complete release, check it matches your system's architecture, and recheck the prerequisites above.
- If settings or downloaded PK3s turn up somewhere unexpected, run `path` in the console and look at `fs_homepath`, `fs_basepath` and `fs_game`.

[Troubleshooting](/TaystJK/troubleshooting/#the-game-will-not-start) covers the startup
errors people hit most often.

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

On Linux, the equivalent launch command is:

```sh
./taystjk.x86_64 +set fs_cdPath ../JediAcademy
```

On macOS, pass the same option to the app:

```sh
open /path/to/taystjk.app --args +set fs_cdPath /path/to/JediAcademy
```

`fs_cdPath` supplies the shared retail assets while TaystJK keeps its own executable, libraries, mod directory, and user files separate.

This layout is adapted from the longer [multiple modded clients guide on JKHub](https://jkhub.org/tutorials/errors-problems/how-to-install-multiple-modded-clients-on-the-same-system-r229/).

### Simpler alternative: copy `base`

Copy the complete retail `base` directory into each client's directory. This uses more disk space, but needs no launch script and keeps each installation self-contained.

Put PK3s that should affect every client in that client's `base` directory. Put TaystJK-only content in `taystjk/`, beside `japro-assets.pk3`.

## Using another mod's client files

TaystJK plays on modded servers with its own client-side code, so you normally install nothing
else. If you want a mod's own HUD or menus, or an older mod's files do not seem to load,
[mod compatibility](/TaystJK/install/mod-compatibility/#loading-another-mods-client-modules)
explains how the client picks its modules and what to do about mods that pack them inside a
PK3.

## Steam playtime and overlay

Optional, and **Windows only**. `Sys_SteamInit` is an empty stub everywhere else
([`sys_unix.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/shared/sys/sys_unix.cpp#L655)).

With it working, Steam counts your TaystJK time against Jedi Academy and the overlay works,
without having to launch the client through Steam.

`com_steamIntegration` is already **on by default**
([`common.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/codemp/qcommon/common.cpp#L1452)), so there is nothing to enable. It
does nothing until you supply two files, neither of which ships with TaystJK or with retail
Jedi Academy. Put both in `GameData`, beside the executable:

| File | Which build |
|:--|:--|
| `steam_api64.dll` | 64-bit TaystJK |
| `steam_api.dll` | 32-bit TaystJK |
| `steam_appid.txt` containing `6020` | both |

`6020` is Jedi Academy's Steam app ID.

Mind the architecture. The
[Steam Integration Tools](https://jkhub.org/files/file/3549-steam-integration-tools/)
package on JKHub is the usual source for these, but it provides the 32-bit `steam_api.dll`
only. If you run the 64-bit build, as most people do, that package alone will not work; you
need `steam_api64.dll`, which comes from the Steamworks SDK.

If the file is missing the client says so at startup in red, and otherwise runs normally:

```text
Steam integration failed: Couldn't find steam_api64.dll
```

The cvar is latched, so a change needs a restart. Set `com_steamIntegration 0` to stop the
client looking at all.

You have to supply these yourself because the Steamworks SDK's terms do not fit TaystJK's
GPLv2 licence, so the library cannot be bundled. The client loads it at runtime if it finds
it, which keeps the licences apart
([`sys_win32.cpp`](https://github.com/taysta/TaystJK/blame/f999cbc0912773164962d8be37737a31fe9ade8d/shared/sys/sys_win32.cpp#L714)).

## Next steps

- [What this client adds](/TaystJK/features/): the HUD tools, movement styles and cosmetics
- [Something is wrong](/TaystJK/troubleshooting/): problems listed by what you see
- [Host a dedicated server](/TaystJK/server-hosting/)
- [Search cvars and commands](/TaystJK/reference/)
- [Compile TaystJK from source](/TaystJK/development/compiling/)

{% include browse-grid.html section="install" %}
