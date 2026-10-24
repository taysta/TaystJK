---
title: "Mod compatibility"
layout: reference
nav_order: 3
parent: "Install TaystJK"
description: "How TaystJK loads another mod's client modules, why a client feature can silently do nothing on another server, and how a server turns features back on."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Player guide</p>

# Mod compatibility

<p class="page-lede">Two things decide how TaystJK behaves with a mod: which client modules get loaded, and which server features the client turns on once they are. This page covers both, and why a feature can silently do nothing.</p>
</div>

## Loading another mod's client modules

The TaystJK executable is the engine. The game, client-game and UI modules are separate
native libraries:

| Module | Windows example | Linux example | Purpose |
|:--|:--|:--|:--|
| Game | `jampgamex86_64.dll` | `jampgamex86_64.so` | Server-side game rules; also used by a locally hosted game. |
| Client game | `cgamex86_64.dll` | `cgamex86_64.so` | Client-side prediction, HUD, and world presentation. |
| UI | `uix86_64.dll` | `uix86_64.so` | Menus and other UI behaviour. |

macOS uses the equivalent `.dylib` files. TaystJK does not run QVM bytecode; both its current
module API and the older `dllEntry`/`vmMain` API load native libraries. A module must match
the operating system and CPU architecture of the TaystJK executable.

For each module, the client asks only for the file name that matches its own architecture,
and looks in the server's mod directory first, then `taystjk`, then `base`
([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_main.cpp#L404)).
So a 64-bit client on a JA+ server never tries the mod's `cgamex86.dll`; it loads TaystJK's
own `cgame` and you keep TaystJK's HUD. That is what you want almost every time.

### Mods that package native libraries inside a PK3

Many older mods put `cgame`, `ui`, or `jampgame` native libraries inside a PK3. TaystJK
still mounts the PK3 and reads its assets, but it does not unpack and run those libraries
by default: [`com_unpackLibraries`](/TaystJK/reference/cvars/com_unpacklibraries-27a5b09/)
defaults to `0`, and both module loaders only try PK3 unpacking when it is on
([registration](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_main.cpp#L179),
[legacy loader](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_main.cpp#L493),
[OpenJK-style loader](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_main.cpp#L575)).
The result is a mod whose assets appear while its custom HUD, menus or game code does not
load.

The fix is to extract the native libraries from the mod's PK3 and put them beside that PK3
in the mod directory. Keep the PK3, because the mod still needs its maps, menus, shaders and
other assets. For a 32-bit Windows mod, the result usually looks like this:

```text
japlus/
├── mod-assets.pk3
├── cgamex86.dll
├── uix86.dll
└── jampgamex86.dll
```

Only extract files from a mod you trust: native modules are programs, not data. The names
and architecture must match your TaystJK build, so an `x86.dll` from an old mod cannot be
loaded by the 64-bit client. Use the 32-bit Windows build for a mod that only has 32-bit
Windows modules, or get modules built for your platform.

On Windows, you can instead turn the old unpacking behaviour back on for a trusted mod at
startup:

```text
taystjk.x86.exe +set fs_game japlus +set fs_forcegame japlus +set com_unpackLibraries 1
```

`com_unpackLibraries` is read once at startup, so put it on the command line. Only Windows
has this fallback. Linux and macOS never extract `.so` or `.dylib` modules from a PK3, so
install those as loose files
([Windows unpacker](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_win32.cpp#L603),
[Unix behaviour](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_unix.cpp#L566)).

### When to use `vm_legacy`

You should not need it. For each native module, TaystJK looks for the newer OpenJK-style
`GetModuleAPI` entry point and, when the library does not export one, loads it through the
older `dllEntry`/`vmMain` interface instead
([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_main.cpp#L628),
[`cl_uiapi.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_uiapi.cpp#L1485)).
Older mods such as JA+ load this way with no setting.

`vm_legacy` forces the older interface on a library that exports both. That matters in one
case: the library's `GetModuleAPI` rejects the engine's API version, and the client stops
with `GetGameAPI failed on` followed by the library name
([`cl_uiapi.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_uiapi.cpp#L1475)).
It still loads a native library; it does not enable QVMs.

`vm_legacy` is a bitmask:

| Bit | Value | Module |
|:--|:--|:--|
| 0 | `1` | Game (`jampgame`), for a local or dedicated server. |
| 1 | `2` | Client game (`cgame`). |
| 2 | `4` | UI (`ui`). |

Add the values to force more than one, so `6` forces both `cgame` and UI. Put it on the
command line, for example `+set vm_legacy 4` for the UI: it is read when a module loads, and
changing it later does not affect a module that is already running.

If the console then reports `VM_CreateLegacy: ... succeeded`, the older interface loaded. If
it reports `failed`, the library has no older interface; remove the setting and check that
the mod build matches your platform.

## Where TaystJK reads and writes files

Three cvars decide which directories the client reads files from and which one it writes
to. All three can only be set at startup, on the command line or in a launch script.

### The search order

The client searches these directories, lowest priority first, and a file in a later one
replaces the same file in an earlier one
([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L3933)):

| Order | Directory | Holds |
|--:|:--|:--|
| 1 | `base` | The retail game files. |
| 2 | `fs_basegame` | A mod other mods build on. On TaystJK this is `taystjk`, with `japro-assets.pk3`. |
| 3 | `fs_game` | The mod the server runs, or the one you chose at startup. |

Each directory is looked for under `fs_cdpath`, `fs_basepath` and `fs_homepath` in turn. Run
`path` in the console to see the result.

**On TaystJK, `fs_basegame` defaults to `fs_forcegame`**
([`files.cpp`](https://github.com/taysta/TaystJK/blame/8b1c57f303aa18bb6f6f6d75fcd633eeb29ff8f5/codemp/qcommon/files.cpp#L3919)): it is `taystjk` on a normal client, and empty when you clear
`fs_forcegame`. Set it yourself on the command line to choose a different one
([`files.cpp`](https://github.com/taysta/TaystJK/blame/8b1c57f303aa18bb6f6f6d75fcd633eeb29ff8f5/codemp/qcommon/files.cpp#L4414)). [Running TaystJK for one mod](#running-taystjk-for-one-mod) shows
what that is for. Builds from before 24 October 2026 ignore a `+set fs_basegame` and always copy
`fs_forcegame`.

`fs_forcegame` also decides where the client **writes**: configs, screenshots, demos and
downloads go to the `fs_forcegame` directory when it is set
([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L4000)), and to the `fs_game` directory, or `base`, when it is empty.

Client modules are found separately. The client tries the `fs_game` directory first, then
`taystjk`, then `base`, whatever these cvars say
([`sys_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/shared/sys/sys_main.cpp#L404)).

### What `fs_forcegame` does

`fs_forcegame` defaults to `taystjk` on the client and to nothing on a dedicated server
([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L3915)). A server cannot change it. The three ways to set it behave
differently:

| `fs_forcegame` | Searched | Written to | When you join a server with another mod |
|:--|:--|:--|:--|
| `taystjk`, the default | `base`, `taystjk`, then the server's mod | `taystjk/` | The mod's files override TaystJK's. Your settings stay in one `taystjk/taystjk.cfg` on every server. |
| A mod, such as `japlus`, with `fs_game` set to the same | `base`, then that mod, then the server's mod if it is a different one. `taystjk/` is not searched, so TaystJK's own assets are not loaded. | that mod's directory | Your settings stay in that mod's directory on every server, and its files stay in the search order under the server's. |
| Empty: `+set fs_forcegame ""` | `base`, then the server's mod. Add `+set fs_basegame taystjk` to keep `taystjk` between them. | the server's mod directory, or `base/` | The client switches to that mod's directory and loads the `taystjk.cfg` in it ([`files.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/qcommon/files.cpp#L4480)), so each mod keeps its own settings. A mod you have never played starts a new directory and config. |

Leave it at the default to keep TaystJK's own client files and one set of settings on JA+,
JA++, jaPRO and other modded servers. Do not add `fs_game` just to join a server; the server
sends its own game directory when you connect. The Mods menu only changes `fs_game`, so it
does not change where your files are written
([`ui_main.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/ui/ui_main.c#L7625)).

To use another mod's client libraries and assets everywhere, install them in that mod's
directory and set both at startup. JA++, for example, uses `japlus/` to stay compatible with
JA+:

```text
taystjk.x86_64.exe +set fs_game japlus +set fs_forcegame japlus
```

To go back to the normal setup, remove `fs_game japlus` and either remove `fs_forcegame` or
set it back to `taystjk`.

### Running TaystJK for one mod

A mod with its own client files, such as a roleplay mod with its own models, HUD and settings,
has two separate choices to make about TaystJK: what happens to TaystJK's assets, and where its
players' settings are saved.

**Overriding TaystJK's assets** needs nothing special. The mod's directory is searched after
`taystjk/`, so any file the mod ships under the same name, such as a HUD graphic, replaces
TaystJK's on that mod's servers. TaystJK's other assets still load.

**Bypassing TaystJK's assets**, so that none of them load, means keeping `taystjk/` out of the
search order. Only a launch option can do that: `fs_basegame` has to be empty, so `fs_forcegame`
has to be cleared without setting `fs_basegame`, or set to the mod itself.

**Settings** go wherever `fs_forcegame` points. By default that is one `taystjk/taystjk.cfg`
used on every server. Clearing it gives each mod its own `taystjk.cfg` in its own directory.

| TaystJK's assets | Settings | Launch with |
|:--|:--|:--|
| Overridden by the mod | `taystjk/taystjk.cfg`, shared with every server | nothing extra |
| Overridden by the mod | `mymod/taystjk.cfg`, separate per mod | `+set fs_forcegame "" +set fs_basegame taystjk +set fs_game mymod` |
| Not loaded | `mymod/taystjk.cfg`, separate per mod | `+set fs_forcegame "" +set fs_game mymod` |
| Not loaded | `mymod/taystjk.cfg`, used on every server | `+set fs_forcegame mymod +set fs_game mymod` |

In the first row the player needs no script, but if the mod has its own `ui` module, starting
with `+set fs_game mymod` loads its menus before the player connects.

With separate settings per mod, joining a server that runs a different mod switches the client
to that mod's directory and its `taystjk.cfg`, which is the point of clearing `fs_forcegame`.
With the last row nothing switches: the mod's settings and files follow the player to servers
that were not made for them.

For every row except the first, the launch script is the only signal. A player who starts
TaystJK normally gets the default setup, so tell players to start the game from a shortcut to
your script.

## What the client decides

On connecting, the client reads the server's `gamename` and sorts the server into one of six
kinds
([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_servercmds.c#L252)):

| `gamename` | Treated as |
|:--|:--|
| starts with `JA+`, `^4U^3A^5Galaxy` or `AbyssMod` | JA+ |
| starts with `japro` | jaPRO |
| starts with `smU` | OpenJK-alt |
| starts with `base_enhanced` or `base_entranced` | Base Enhanced |
| starts with `basejk` | Base JKA |
| is exactly `Lugormod` or `^5L^7ugormod ^5v3` | Lugormod |

None of these care about case. Anything else is treated as base JKA, and so is any server on
a pre-1.01 protocol whatever its name. Because most of these match only the start of the
name, a server that renames itself loses the classification and the features that depend on
it; a Lugormod server has to use one of its two names exactly
([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_servercmds.c#L293)).

## Why that ordering matters

The six kinds are an **ordered** enum, not a set
([`cg_local.h`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_local.h#L205)):

```text
basejka  <  base_enhanced  <  ojkalt  <  lugormod  <  ja+  <  japro
```

Most feature checks are written as *at least JA+* instead of as a list of names. A feature
checked that way is on for JA+ and jaPRO and off for everything to their left, including
Lugormod. So the practical answer to "does my client do X here" is usually "are you on a JA+
or jaPRO server".

## What is actually gated

Not everything. The client's own display settings, including the HUD tools, the cosmetics
you see locally and console behaviour, work whatever the server runs. What is gated is
behaviour the **server has to agree with**, because the client is predicting movement or
drawing something the server also has a say in.

| Feature | Needs |
|:--|:--|
| RGB sabers | JA+ or jaPRO, or the server advertising it ([`cg_players.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_players.c#L6063)) |
| Black sabers | the same, and not disabled by plugin settings ([`cg_players.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_players.c#L6055)) |
| Flipkick | the server advertising it ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_pmove.c#L272)) |
| JA+-style grapple | JA+, or jaPRO with its JA+ grapple option on, or the server advertising it ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/4cca97d97551d2fda974e7fe7d5693f21900a2f3/codemp/game/bg_pmove.c#L15608)) |
| Roll fixes 1–3 | JA+ or jaPRO with the matching option, or the server advertising it ([`bg_pmove.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/game/bg_pmove.c#L314)) |
| The `plugin` command | JA+ or above; it returns silently otherwise ([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_consolecmds.c#L1292)) |
| Force column on the team overlay | jaPRO, which is what supplies the data |

Lugormod is a special case throughout: it is recognised on its own and several movement
paths branch for it, because it moves players in ways the stock prediction gets wrong.

## Base Enhanced and Base Entranced: use NewJK

If you play on **base_enhanced** or **base_entranced** servers, use
[NewJK/NewMod](https://jkanewmod.github.io/) instead of this client.

Those server mods and NewMod share an author, and NewMod is built for them. It supports
their features fully, where TaystJK only recognises base_enhanced well enough not to break
on it.

## `taystJKinfo`: how a server turns these on

A server does not have to be JA+ or jaPRO. Any game module can advertise the individual
features it supports by putting a bitmask in the `taystJKinfo` serverinfo key, which the
client reads on connect and whenever the serverinfo changes
([`cg_servercmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_servercmds.c#L250)).

The mask covers RGB and black sabers, flipkick, grapple, the three roll fixes, and
server-supplied scoreboard deaths. The bits are listed in
[the feature flags spec](/TaystJK/development/feature-flags/#the-bits). Scoreboard deaths
also depends on the client advertising support in its `taystJKcgflags` userinfo, so the
server only sends the extended scoreboard to clients that can read it.

The flag does not bypass the `plugin` command's JA+/jaPRO check
([`cg_consolecmds.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_consolecmds.c#L1292)),
or turn on the team overlay's force column on other mods: that still requires jaPRO
([`cg_draw.c`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/cgame/cg_draw.c#L6082)).

If you run a server on something other than JA+ or jaPRO and players report that RGB sabers
or flipkick do nothing, this key is the answer.

## Telling which you are on

Run `configstrings` in the console while connected
([`cl_main.cpp`](https://github.com/taysta/TaystJK/blame/76943f046bbbdc23d67323b838cb1c4c1e3fba0e/codemp/client/cl_main.cpp#L3481)).
The first entry is the server's serverinfo, which includes `gamename` and, if the server
sets it, `taystJKinfo`. That is the quickest way to tell whether a feature is missing
because of your client or because of the server. `serverinfo` only works on the machine
running the server; on a client it prints "Server is not running."

A feature that behaves differently on two servers is usually down to the servers, not the
client. See [where to report](/TaystJK/where-to-report/).
