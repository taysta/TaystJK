---
title: "Debugging"
layout: reference
description: "Debug the TaystJK engine and game modules with Visual Studio, GDB, LLDB, or CLion."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Developer guide</p>

# Debug TaystJK

<p class="page-lede">Debug an installed build so the engine, game modules, renderers, and bundled libraries use the same layout as a real TaystJK installation. On macOS, run <code>moveandsign.sh</code> after installing, then point CLion at the executable inside the installed app bundle.</p>
</div>

## Build with symbols

For a single-configuration generator such as Makefiles or Ninja:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug --parallel
```

For Visual Studio or Xcode, generate once and choose the `Debug` configuration when building and launching. `RelWithDebInfo` is useful when a bug disappears without optimization.

## Install before debugging

Building creates the targets; installing assembles the client, modules, renderers, and assets in the layout that the engine expects. Configure `CMAKE_INSTALL_PREFIX` for your platform's test or staging location, then install the same configuration you built:

```bash
# Makefiles or Ninja
cmake --install build-debug

# Xcode or Visual Studio
cmake --install build-debug --config Debug
```

TaystJK installs beneath the `JediAcademy` directory inside that prefix. Keep the build configuration consistent: installing `Debug` and then debugging a previously installed `Release` executable will give you mismatched binaries and breakpoints.

## Launch arguments

Use these arguments for the multiplayer client:

```text
+set r_fullscreen 0 +set fs_game taystjk
```

If the executable is outside the retail install, add:

```text
+set fs_cdPath "C:/Games/Jedi Academy/GameData"
```

Set the working directory to the root of the installed test layout. Do not add a trailing slash to `fs_cdPath` on Windows.

## Debug for your platform

Choose your operating system to see its debugger setup. Your selection is saved on this device.

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

### Visual Studio

Give CMake a stable, user-writable install prefix when generating the Visual Studio solution. The **INSTALL** project uses this cached path:

```powershell
cmake -S . -B build-vs -G "Visual Studio 17 2022" -A x64 `
  -DCMAKE_INSTALL_PREFIX="C:/TaystJK-test"
```

Then configure the debugger:

1. Open `build-vs\TaystJK.sln` and select **Debug** and **x64** in the solution toolbar.
2. Build the solution, then right-click the **INSTALL** project and choose **Build**. This creates the runnable layout under `C:\TaystJK-test\JediAcademy`.
3. Right-click **MP Client**, choose **Properties**, and select **Debug** and **x64** at the top of the Property Pages dialog.
4. Under **Configuration Properties → Debugging**, set the following values:

| Setting | Value |
|:--|:--|
| Debugger to launch | **Local Windows Debugger** |
| Command | `C:\TaystJK-test\JediAcademy\taystjk.x86_64.exe` |
| Command Arguments | `+set r_fullscreen 0 +set fs_game taystjk` |
| Working Directory | `C:\TaystJK-test\JediAcademy` |
| Debugger Type | **Native Only** |

If the retail `base` directory is elsewhere, append `+set fs_cdPath "C:/Games/Jedi Academy/GameData"` to **Command Arguments**, replacing the example path and omitting any trailing slash.

5. Right-click **MP Client** and choose **Set as Startup Project**.
6. Place a breakpoint and press <kbd>F5</kbd>.

After changing engine or module code, build **Debug** again and rerun **INSTALL** before launching. The install step refreshes the executable, renderers, game, cgame, UI modules, and bundled runtime DLLs as one matching set. Visual Studio can then debug every loaded project in the solution even though **Command** points to the installed executable.

If a breakpoint remains hollow, open **Debug → Windows → Modules** and confirm that the expected installed DLL and its matching PDB were loaded. The debugger properties are stored in Visual Studio's per-user project settings, so deleting and regenerating `build-vs` requires configuring them again.
  </section>

  <section class="platform-panel" id="platform-panel-linux" role="tabpanel" aria-labelledby="platform-tab-linux" tabindex="0" data-platform-panel="linux" markdown="1">
## Linux

### GDB

Launch the installed executable from the test directory so relative game paths resolve correctly:

```bash
gdb --args ./taystjk.x86_64 +set r_fullscreen 0 +set fs_game taystjk
```

Useful first commands are `run`, `bt`, `info sharedlibrary`, and `break function_name`.
  </section>

  <section class="platform-panel" id="platform-panel-macos" role="tabpanel" aria-labelledby="platform-tab-macos" tabindex="0" data-platform-panel="macos" markdown="1">
## macOS

### Move and sign the installed build

After the install target finishes, run TaystJK's [macOS development helper](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/scripts/macosx/moveandsign.sh):

```bash
./scripts/macosx/moveandsign.sh
```

The script moves the installed files from the Steam-side `JediAcademy` staging directory to `~/Library/Application Support/TaystJK`, removes quarantine attributes, and ad-hoc signs the app bundle and dedicated-server binary. Its paths and binary names currently assume the default Steam location and an arm64 build; inspect the variables at the top of the script if your install location or architecture differs.

### LLDB

After running `moveandsign.sh`, launch the executable inside the installed app bundle:

```bash
lldb -- "$HOME/Library/Application Support/TaystJK/taystjk.arm64.app/Contents/MacOS/taystjk.arm64" \
  +set r_fullscreen 0 +set fs_game taystjk
```

Useful first commands are `run`, `thread backtrace`, `image list`, and `break function_name`.
  </section>
</section>

## CLion

Open the repository as a CMake project and choose a Debug profile. Build the project, run its `install` target, and on macOS run `./scripts/macosx/moveandsign.sh`.

Then create or edit the client Run/Debug configuration:

- Choose **Custom executable** and browse to the client executable in the installed layout. On arm64 macOS, the default helper-script destination is `~/Library/Application Support/TaystJK/taystjk.arm64.app/Contents/MacOS/taystjk.arm64`.
- Set the working directory to the installed TaystJK directory. With the default macOS helper script, this is `~/Library/Application Support/TaystJK`.
- Add the standard launch arguments above.
- Before each debugging session, rebuild and rerun the install step; on macOS, rerun `moveandsign.sh` after installing.
- Keep the installed executable and all loaded modules on the same architecture and build profile.

For a dedicated server, choose the installed `taystjkded` executable and use `+set dedicated 2 +set fs_game taystjk +exec server.cfg`.

## Sanitizers

AddressSanitizer catches use-after-free, buffer overflow, and related memory faults:

```bash
cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DUseAddressSanitizer=ON
cmake --build build-asan --parallel
```

With GCC or Clang, undefined-behavior checks can be added with `-DUseUndefinedSanitizer=ON`. Run a sanitizer build from a terminal so its complete report is retained. On MSVC, TaystJK disables the incompatible prebuilt Discord RPC library for AddressSanitizer builds.

## Logs and useful console settings

- Start with `+set developer 1 +set logfile 2` when you need a flushed log after a crash.
- Run `path` to verify which base, home, and mod directories are mounted.
- Run `which filename.pk3` or the closest available file-list command when a wrong asset version appears to load.
- Use `condump debug-console.txt` before quitting if the console contains the only copy of a useful trace.

## Common breakpoint problems

| Symptom | Check |
|:--|:--|
| Breakpoint never binds | The process loaded a release module or a copy from another `GameData` directory. |
| `default.cfg` is missing | `base/assets0.pk3` is not reachable through the current paths. |
| Source line does not match | Rebuild the module and remove stale copied binaries from the test directory. |
| Crash only occurs in Release | Reproduce with `RelWithDebInfo`, then use AddressSanitizer or UndefinedBehaviorSanitizer. |
| Client exits when loading a map | Inspect the engine log and confirm the cgame, game, UI, and renderer architectures match the executable. |

The setup follows the OpenJK [debugging overview](https://github.com/JACoders/OpenJK/wiki/Debugging) and [Visual Studio guide](https://github.com/JACoders/OpenJK/wiki/Debugging-in-Visual-Studio), with TaystJK target names and diagnostics. Microsoft's [C++ debug-configuration reference](https://learn.microsoft.com/en-us/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration?view=visualstudio) describes the Visual Studio property fields used above.
