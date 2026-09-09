---
title: "Debugging"
layout: reference
description: "Debug the TaystJK engine and game modules with Visual Studio, GDB, LLDB, or CLion."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Developer guide</p>

# Debug TaystJK

<p class="page-lede">Most startup failures are path problems. Give the debugger the Jedi Academy <code>GameData</code> directory as its working directory, disable fullscreen, and point <code>fs_game</code> at <code>taystjk</code>.</p>
</div>

## Build with symbols

For a single-configuration generator such as Makefiles or Ninja:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug --parallel
```

For Visual Studio or Xcode, generate once and choose the `Debug` configuration when building and launching. `RelWithDebInfo` is useful when a bug disappears without optimization.

## Launch arguments

Use these arguments for the multiplayer client:

```text
+set sv_pure 0 +set r_fullscreen 0 +set fs_game taystjk
```

If the executable is outside the retail install, add:

```text
+set fs_cdPath "C:/Games/Jedi Academy/GameData"
```

Set the working directory to the directory containing the executable or to your test `GameData` directory. Do not add a trailing slash to `fs_cdPath` on Windows.

## Visual Studio

1. Open the generated `TaystJK.sln`.
2. Select the **Debug** configuration and the correct platform.
3. Right-click the **MP Client** project and choose **Set as Startup Project**.
4. In **Properties → Debugging**, set **Working Directory** to your test `GameData` directory and add the launch arguments above under **Command Arguments**.
5. Place a breakpoint and press <kbd>F5</kbd>.

Launching the client project still allows Visual Studio to load symbols and stop inside the game, cgame, UI, and renderer libraries once the engine loads them. If a breakpoint is hollow, open **Debug → Windows → Modules** and confirm that the expected module and PDB were loaded from your build.

## GDB or LLDB

Launch from the test directory so relative game paths resolve correctly:

```bash
gdb --args ./taystjk.x86_64 +set sv_pure 0 +set r_fullscreen 0 +set fs_game taystjk
```

Or on macOS:

```bash
lldb -- ./taystjk.arm64.app/Contents/MacOS/taystjk.arm64 \
  +set sv_pure 0 +set r_fullscreen 0 +set fs_game taystjk
```

Useful first commands are `run`, `bt`/`thread backtrace`, `info sharedlibrary`/`image list`, and `break function_name`.

## CLion

Open the repository as a CMake project and choose a Debug profile. In the client Run/Debug configuration:

- Set the executable to the `taystjk` client target.
- Set the working directory to your test `GameData` directory.
- Add the standard launch arguments above.
- Select the same architecture and build profile for every module you expect to load.

For a dedicated server, select `taystjkded` and use `+set dedicated 2 +set fs_game taystjk +exec server.cfg`.

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
- Keep `sv_pure 0` confined to development. Re-enable pure mode when validating a production server.

## Common breakpoint problems

| Symptom | Check |
|:--|:--|
| Breakpoint never binds | The process loaded a release module or a copy from another `GameData` directory. |
| `default.cfg` is missing | `base/assets0.pk3` is not reachable through the current paths. |
| Source line does not match | Rebuild the module and remove stale copied binaries from the test directory. |
| Crash only occurs in Release | Reproduce with `RelWithDebInfo`, then use AddressSanitizer or UndefinedBehaviorSanitizer. |
| Client exits when loading a map | Inspect the engine log and confirm the cgame, game, UI, and renderer architectures match the executable. |

The setup follows the OpenJK [debugging overview](https://github.com/JACoders/OpenJK/wiki/Debugging) and [Visual Studio guide](https://github.com/JACoders/OpenJK/wiki/Debugging-in-Visual-Studio), with TaystJK target names and diagnostics.
