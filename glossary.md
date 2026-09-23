---
title: "Glossary"
layout: reference
nav_order: 4
parent: "Help"
description: "Terms the guides and the console reference assume you already know."
toc: true
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Start here</p>

# Glossary

<p class="page-lede">Terms used across these pages and in the console reference, defined once.</p>
</div>

## Movement and HUD

**CGAZ:** a display mode of the strafe helper, showing the angles at which you gain speed
for your current velocity and movement style. It is one bit of the `cg_strafeHelper`
setting rather than a separate feature; configure it with the `strafehelper` command. See
[HUD and movement tools](/TaystJK/features/hud-and-movement/).

**Snaps, snap zones:** movement is applied in whole units each frame, so at some view
angles the rounding gains you a little speed and at others it costs you. The boundaries
between those angles are snap zones, and they move with your speed and framerate: the
SnapHUD computes them from both and draws them
([`hud_strafehelper.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/hud_strafehelper.c#L2507)).
Enable it with `cg_snapHud`. See [HUD and movement tools](/TaystJK/features/hud-and-movement/).

**Movement style:** the rule set a server applies to player movement, changing
acceleration, air control and what tricks are possible. The client knows nineteen, from
`MV_SIEGE` and `MV_JKA` through `MV_CPM`, `MV_WSW` and `MV_TRIBES`
([`bg_public.h`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_public.h#L560)).
See [movement styles](/TaystJK/features/movement-styles/).

**Ski:** sliding along the ground instead of running, in the Tribes movement style, with
its own landing sound. See [Tribes](/TaystJK/features/tribes/).

**IFF:** identification friend-or-foe, a team-coloured marker floating above other players
in the Tribes movement style, so you can tell at a glance who is on your side. It grows with
distance so it stays readable far away, and enemies are only marked within a limited range
([`cg_players.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_players.c#L11059)).
See [Tribes](/TaystJK/features/tribes/).

## Files and directories

**Base directory:** `GameData/base`, holding the four retail `assets*.pk3` files. Never
put your own files here; see [Install](/TaystJK/install/).

**Mod directory:** a sibling of `base` under `GameData` holding one mod's files. TaystJK's
own is `taystjk`, which is where `japro-assets.pk3` is installed.

**`fs_game` / `fs_forcegame`:** `fs_game` selects the mod directory and a server can set
it. `fs_forcegame` is a client-side override that a server cannot change. See
[Server hosting](/TaystJK/server-hosting/).

**homepath, basepath, cdpath:** the three roots the filesystem searches. `fs_basepath` is
the installation directory, `fs_homepath` is where your own generated files are written
(configs, screenshots, downloads), and `fs_cdpath` is an additional read-only search path.
Writes go to homepath; a file found in homepath takes precedence.

**Levelshot:** the loading-screen image for a map, read from `levelshots/<mapname>`. The
client prefers a widescreen version at `levelshots_16_9/<mapname>` when one exists
([`cg_info.c`](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_info.c#L149)).

**Pure server:** a server running `sv_pure 1`, which requires clients to load game assets
only from pk3 files the server also has. It stops mismatched or modified assets, and it is
why a custom pk3 can leave you unable to join.

**Reflist:** the list of pk3 files a server tells clients it is using, which drives what
they must download or already have. See
[PK3 referencing and reflists](/TaystJK/server-hosting/#pk3-referencing-and-reflists).

## Client and server code

**game, cgame, UI module:** the three pieces of per-mod code. `game` runs on the server
and owns the rules; `cgame` runs on the client and decides what you see; `ui` draws the
menus. The console reference labels every entry with the module that registers it.

**QVM versus native module:** QVM files contain bytecode; native modules are libraries
compiled for a particular platform and architecture. TaystJK's module loaders use native
libraries. `vm_legacy` is a per-slot bitmask selecting the older `dllEntry`/`vmMain` API
instead of `GetModuleAPI`; it does not enable QVM bytecode support
([legacy loader](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/vm.cpp#L110),
[native API loader](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/qcommon/vm.cpp#L150)).
A native module must match the client's architecture, so a 32-bit mod library cannot be
loaded by a 64-bit client.

**Serverinfo:** the small set of values a server publishes about itself, visible in the
server browser before you connect. A cvar registered `CVAR_SERVERINFO` is part of it.

**Feature flag:** `taystJKinfo`, a serverinfo key through which a server mod advertises
which TaystJK client features it supports, independently of which mod it is. It is why a
feature can work on one server and silently do nothing on another; see
[mod compatibility](/TaystJK/mod-compatibility/).

**Origin:** in the console reference, the project an entry *first appeared* in, not every
fork that ships it. See [sources and methodology](/TaystJK/reference/sources/).
