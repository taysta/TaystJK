---
title: "fraglimit"
layout: reference
nav_exclude: true
search_exclude: false
---

# `fraglimit`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `fraglimit` in the game module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `game` |
| Also registered in | `game`, `engine-server` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Disabled. | [codemp/game/g_cmds.c:5980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L5980) |
| `1` | Enabled. | [codemp/game/g_cmds.c:5980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L5980) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_NORESTART` — preserved across cvar restart
- `CVAR_SERVERINFO` — published in serverinfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `game` | `—` | `always` |
| `20` | `engine-server` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/game/g_main.c:324](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/game/g_main.c#L324)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/g_cmds.c`, `codemp/game/g_main.c` and 1 more | `medium` |
| `2013-04-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f6cadd34c6ab`](https://github.com/JACoders/OpenJK/commit/f6cadd34c6ab5788140aa01552ea87b5b4b7cec1)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_servercmds.c`, `codemp/game/g_cmds.c`, `codemp/game/g_main.c` and 1 more | `medium` |
| `2013-10-24` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`872159cb6796`](https://github.com/JACoders/OpenJK/commit/872159cb6796e09bcd1065e318453e5358f52821)<br>[MP] Rewrote callvote to be far more robust | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `medium` |
| `2015-04-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`3a5f856a0bb4`](https://github.com/eternalcodes/EternalJK/commit/3a5f856a0bb455686515e55ba6068a9b72a82c28)<br>Added new callvote options in Gametype. [Timelimit, Fraglimit, Capturelimit, TeamSize] | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/g_main.c` | `high` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_scoreboard.c` | `high` |
| `2018-09-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`dbfd735d1da2`](https://github.com/eternalcodes/EternalJK/commit/dbfd735d1da2aa590f5aa453a330e6ab1ed94cdd)<br>Added jcinfo2 to allow UI to only show Race button when relevant | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/game/g_xcvar.h` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`15c685c83005`](https://github.com/eternalcodes/EternalJK/commit/15c685c830057239017ac08c4a9be5ab8a98c300)<br>Merge pull request #95 from Yberion/serversideEngineFix | Changed an exact bound cvar-variable reference. `codemp/server/sv_client.cpp` | `medium` |
| `2019-05-10` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`9a37943df03d`](https://github.com/eternalcodes/EternalJK/commit/9a37943df03dd6d09740d3cf94f596c82043d49f)<br>Fix broken ClientCleanName function+Refactor server fixes to utilize new legacyFixes bitmask and server mod detection. | Changed an exact bound cvar-variable reference. `codemp/server/server.h`, `codemp/server/sv_client.cpp` | `medium` |
| `2024-01-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`b5dff40126c7`](https://github.com/videoP/jaPRO/commit/b5dff40126c7922718f6b2ebb359463b8af78205) · [PR #82](https://github.com/taysta/TaystJK/pull/82)<br>Japro update (#82) | Changed an exact bound cvar-variable reference. `codemp/game/g_cmds.c` | `high` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/game/g_xcvar.h:65](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L65) (XCVAR_DEF)
- registration: [codemp/server/sv_init.cpp:963](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/server/sv_init.cpp#L963) (Cvar_Get)
- behavior: [codemp/game/g_cmds.c:5980](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_cmds.c#L5980)
- behavior: [codemp/game/g_main.c:2508](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L2508)
- behavior: [codemp/game/g_main.c:2522](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L2522)
- behavior: [codemp/game/g_main.c:2523](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L2523)
- behavior: [codemp/game/g_main.c:2534](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_main.c#L2534)
