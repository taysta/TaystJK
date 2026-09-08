---
title: "cl_paused"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cl_paused`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `cl_paused` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `float` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ROM` — read-only after registration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `engine-shared` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:412](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L412)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`d1043c837228`](https://github.com/JACoders/OpenJK/commit/d1043c837228fea287e590753713376d1e15a4c0)<br>Pause code fixes (ioq3) | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp`, `codemp/client/cl_main.cpp`, `codemp/client/cl_parse.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_ents.c`, `codemp/cgame/cg_main.c` and 2 more | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2013-09-05` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`9bc49a503050`](https://github.com/JACoders/OpenJK/commit/9bc49a503050e4c8cf96d5496432ba48c7340c58)<br>UI cleanup. Unused functions | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `code/qcommon/common.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2018-02-10` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`697cfad347d9`](https://github.com/videoP/jaPRO/commit/697cfad347d92f7833f5663f5f27014e9e83b290)<br>Moved ui_isJAPro from cgame to UI. | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `high` |
| `2018-03-23` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`852cd1037427`](https://github.com/eternalcodes/EternalJK/commit/852cd10374272a0195a05ac15e9b69c2313ecaff)<br>Merge remote-tracking branch 'bucky/master' | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`7bd5df22796d`](https://github.com/eternalcodes/EternalJK/commit/7bd5df22796d79cd2d117f49cca0d65375f1624d)<br>Prevent camera from jerking when toggling cg_thirdPerson/strafeHelper settings | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_view.c` | `medium` |
| `2019-07-26` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`32fd320e90d7`](https://github.com/eternalcodes/EternalJK/commit/32fd320e90d7ea31d6989579d22cac223f87a273)<br>pause demo playback when menu open | Changed an exact bound cvar-variable reference. `codemp/client/cl_cgame.cpp` | `medium` |
| `2020-06-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`a43a3418a405`](https://github.com/eternalcodes/EternalJK/commit/a43a3418a40564fc48038585ad6054b6df79dba2)<br>Fix NPC console spam+fix cg_drawHitBox on local player | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_players.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:371](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L371) (XCVAR_DEF)
- registration: [codemp/qcommon/common.cpp:1478](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1478) (Cvar_Get)
- behavior: [codemp/client/cl_cgame.cpp:976](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_cgame.cpp#L976)
- behavior: [codemp/client/cl_input.cpp:1690](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_input.cpp#L1690)
- behavior: [codemp/client/cl_main.cpp:2332](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/client/cl_main.cpp#L2332)
- behavior: [codemp/server/sv_main.cpp:994](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_main.cpp#L994)
- behavior: [codemp/cgame/cg_draw.c:11730](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L11730)
