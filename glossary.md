---
title: "Glossary"
layout: reference
nav_order: 8
description: "Terms the guides and the console reference assume you already know."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Start here</p>

# Glossary

<p class="page-lede">Terms used across these pages and in the console reference, defined once.</p>
</div>

## Movement and HUD

**CGAZ** — a display mode of the strafe helper, showing the angles at which you gain speed
for your current velocity and movement style. It is one bit of the `cg_strafeHelper`
setting rather than a separate feature; configure it with the `strafehelper` command. See
[HUD and movement tools](/TaystJK/features/hud-and-movement/).

**Snaps, snap zones** — the SnapHUD (`cg_snapHud`) draws the zones a strafe player aims
between.
<!-- TODO: the underlying mechanic is not described anywhere in the source tree; the cvar's
     own documentation is only "Enable/Disable the snap HUD". Someone who understands the
     physics should write the one-sentence explanation of what a snap zone is. -->

**Movement style** — the rule set a server applies to player movement, changing
acceleration, air control and what tricks are possible. The client knows nineteen, from
`MV_SIEGE` and `MV_JKA` through `MV_CPM`, `MV_WSW` and `MV_TRIBES`
([`bg_public.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L560)).
See [movement styles](/TaystJK/features/movement-styles/).

**Ski** — sliding along the ground instead of running, in the Tribes movement style, with
its own landing sound. See [Tribes](/TaystJK/features/tribes/).

**IFF** — *TODO: not defined here yet.* The term appears in the project's planning notes as
a Tribes feature, but it occurs nowhere in the source tree, so there is nothing to verify a
definition against. Confirm what it refers to before writing one.

## Files and directories

**Base directory** — `GameData/base`, holding the four retail `assets*.pk3` files. Never
put your own files here; see [Install](/TaystJK/install/).

**Mod directory** — a sibling of `base` under `GameData` holding one mod's files. TaystJK's
own is `taystjk`, which is where `japro-assets.pk3` is installed.

**`fs_game` / `fs_forcegame`** — `fs_game` selects the mod directory and a server can set
it. `fs_forcegame` is a client-side override that a server cannot change. See
[Server hosting](/TaystJK/server-hosting/).

**homepath, basepath, cdpath** — the three roots the filesystem searches. `fs_basepath` is
the installation directory, `fs_homepath` is where your own generated files are written
(configs, screenshots, downloads), and `fs_cdpath` is an additional read-only search path.
Writes go to homepath; a file found in homepath takes precedence.

**Levelshot** — the loading-screen image for a map, read from `levelshots/<mapname>`. The
client prefers a widescreen version at `levelshots_16_9/<mapname>` when one exists
([`cg_info.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_info.c#L149)).

**Pure server** — a server running `sv_pure 1`, which requires clients to load game assets
only from pk3 files the server also has. It stops mismatched or modified assets, and it is
why a custom pk3 can leave you unable to join.

**Reflist** — the list of pk3 files a server tells clients it is using, which drives what
they must download or already have. See
[PK3 referencing and reflists](/TaystJK/server-hosting/#pk3-referencing-and-reflists).

## Client and server code

**game, cgame, UI module** — the three pieces of per-mod code. `game` runs on the server
and owns the rules; `cgame` runs on the client and decides what you see; `ui` draws the
menus. The console reference labels every entry with the module that registers it.

**QVM versus native module** — a module ships either as bytecode (`cgame.qvm`, `ui.qvm`)
run by the engine's virtual machine, or as a native library for your platform. `vm_legacy`
is a per-slot bitmask selecting the legacy bytecode path
([`vm.cpp`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/vm.cpp#L153)).
Native modules are platform-specific, which is why a 32-bit mod directory can break a
64-bit client.

**Serverinfo** — the small set of values a server publishes about itself, visible in the
server browser before you connect. A cvar registered `CVAR_SERVERINFO` is part of it.

**Feature flag** — `taystJKinfo`, a serverinfo key through which a server mod advertises
which TaystJK client features it supports, independently of which mod it is. It is why a
feature can work on one server and silently do nothing on another.

**Origin** — in the console reference, the project an entry *first appeared* in, not every
fork that ships it. See [sources and methodology](/TaystJK/reference/sources/).
