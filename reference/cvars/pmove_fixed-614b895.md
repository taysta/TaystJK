---
title: "pmove_fixed"
layout: reference
nav_exclude: true
search_exclude: false
---

# `pmove_fixed`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

<p class="ref-warning"><strong>Needs review.</strong> The inventory/provenance evidence is recorded, but some behavior, options, or attribution still lacks a direct user-facing source.</p>

Controls `pmove_fixed` in the cgame module. Consult the cited behavior reads before relying on values not listed here.

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `game` |
| Renderer | All / not renderer-specific |
| Network scope | `server-authoritative` — Owned or enforced by the server. |
| Derivation | `code-trace` |
| Confidence | `high` |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `16` | Selects the code path tested for value 16. | [codemp/game/bg_pmove.c:1984](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L1984) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration
- `CVAR_SYSTEMINFO` — replicated in systeminfo

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `game` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [codemp/cgame/cg_main.c:1035](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/codemp/cgame/cg_main.c#L1035)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h`, `codemp/game/g_main.c` and 1 more | `medium` |
| `2013-05-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`f203e799b14c`](https://github.com/JACoders/OpenJK/commit/f203e799b14c0716833793eed611c272111c3cb6)<br>Merge branch 'master' of https://github.com/Razish/OpenJK into modrender-port | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/game/g_active.c`, `codemp/game/g_xcvar.h` | `high` |
| `2013-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b12414718708`](https://github.com/JACoders/OpenJK/commit/b1241471870888d0e2b7c2613dadcd5da8761ae2)<br>[MP] Improve cvar code a bit further.  Based mostly on zturtleman/spearmint@778bce425a2e6b6860e9d5ec4c7fc736311f9351. With some changes for legacy support still (and extra cvars that should be allowed in mods, if the mods were incorrectly setting them). And also some other misc stuff related to OpenJK specific. | Changed an exact bound cvar-variable reference. `codemp/qcommon/cvar.cpp` | `high` |
| `2018-01-01` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`d9d510063ce6`](https://github.com/videoP/jaPRO/commit/d9d510063ce680639e6ba060021b6d40ee0c1419)<br>Merge branch 'japro-ejk' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c`, `codemp/game/g_active.c` | `high` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`6551f0ce2a0b`](https://github.com/eternalcodes/EternalJK/commit/6551f0ce2a0bafaa447abcc1795a467a243c12d8)<br>racemode jerkyness tweak? test | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `medium` |
| `2018-02-25` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`db38609f2346`](https://github.com/eternalcodes/EternalJK/commit/db38609f2346aafae77b6213098cc532be4003c3)<br>rest of msec racemode restriction remove | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-07-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`fae0fd307416`](https://github.com/eternalcodes/EternalJK/commit/fae0fd30741627a4c90fec92d4ba5c07c826410a)<br>Merge branch 'feature/update-game' into develop | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_predict.c` | `high` |
| `2018-11-04` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`ad634ee5d2ff`](https://github.com/eternalcodes/EternalJK/commit/ad634ee5d2ffe8264a546136a174ee3fdba985c3)<br>Merge branch 'master' of https://github.com/eternalcodes/EternalJK | Changed an exact bound cvar-variable reference. `codemp/game/g_active.c` | `high` |
| `2018-11-09` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`4bbb14b56d12`](https://github.com/videoP/jaPRO/commit/4bbb14b56d12beddb3de30294fef6127beaeecc7)<br>Merge remote-tracking branch 'videoP-jaPRO/master' | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `high` |
| `2025-11-15` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`c318e71b7c60`](https://github.com/taysta/TaystJK/commit/c318e71b7c6017e5482e7a1111ed196df1fbbb8b) · [PR #271](https://github.com/taysta/TaystJK/pull/271)<br>Merge pull request #271 from slash-fr/fix-lugormod-compat | Changed an exact bound cvar-variable reference. `codemp/game/bg_pmove.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:379](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L379) (XCVAR_DEF)
- registration: [codemp/game/g_xcvar.h:172](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_xcvar.h#L172) (XCVAR_DEF)
- behavior: [codemp/game/bg_pmove.c:1984](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/bg_pmove.c#L1984)
- behavior: [codemp/game/g_active.c:3783](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L3783)
- behavior: [codemp/game/g_active.c:4886](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/game/g_active.c#L4886)
- behavior: [codemp/cgame/cg_predict.c:1136](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_predict.c#L1136)
- behavior: [codemp/cgame/cg_predict.c:1559](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_predict.c#L1559)
