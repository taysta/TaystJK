---
title: "cg_fov"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_fov`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cg_fov` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Category | Gameplay & combat |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| In-game xdocs | No |
| In-game menu | Yes — [ingame_camera.menu:138](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_camera.menu#L138), [ingame_camera.menu:158](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_camera.menu#L158), [ingame_camera.menu:181](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_camera.menu#L181) |
| Default | `90` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:333](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L333)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h`, `codemp/game/bg_pmove.c` | `medium` |
| `2013-07-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`8831076ddf5e`](https://github.com/JACoders/OpenJK/commit/8831076ddf5e4daa2844a84b19685e7868014c5d)<br>Allow cg_fov to be archived in SP. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp` | `medium` |
| `2013-08-04` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`004c73dcfeb3`](https://github.com/JACoders/OpenJK/commit/004c73dcfeb386fb520067d21963db250e6bdd2d)<br>Decoupled viewmodel FOV from view FOV. Added option to not lower viewmodel at high FOV values. Defaults to inheriting view FOV and lowering viewmodel like base. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |
| `2013-08-13` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`142bd8696935`](https://github.com/JACoders/OpenJK/commit/142bd869693538ab6e10d52a6e5d7df631a7d479)<br>Adds cg_fovAspectAdjust to SP. Waiting on viewmodel fov changes because, SP uses 80 as the starting number for viewmodel fov scaling. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp` | `medium` |
| `2014-01-20` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`7dd2d68dd65e`](https://github.com/JACoders/OpenJK/commit/7dd2d68dd65e9b805d75a8396853a6dc5f416875)<br>[SP] JK2: cg_fov is now flagged as CVAR_ARCHIVE | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2014-03-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`cfeb246ffcce`](https://github.com/JACoders/OpenJK/commit/cfeb246ffcce3105e835a8043c5770ce92cc7783)<br>[JK2SP] Merging in some fixes and cleanup from JASP cgame/game code. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_view.c`, `codemp/cgame/cg_xcvar.h` | `high` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:304](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L304) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:11682](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/game/bg_pmove.c#L11682)
- behavior: [codemp/cgame/cg_draw.c:12256](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L12256)
- behavior: [codemp/cgame/cg_draw.c:12259](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L12259)
- behavior: [codemp/cgame/cg_view.c:1303](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L1303)
- behavior: [codemp/cgame/cg_view.c:1927](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_view.c#L1927)
