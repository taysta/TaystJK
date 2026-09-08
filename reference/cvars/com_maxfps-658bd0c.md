---
title: "com_maxFPS"
layout: reference
nav_exclude: true
search_exclude: false
---

# `com_maxFPS`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Maximum frames per second

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `engine-shared` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `125` |
| Value type | `int` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

No discrete value list is enforced or documented in the inspected source.

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `125` | `cgame` | `—` | `always` |
| `125` | `engine-shared` | `—` | `defined(_JK2EXE)` |
| `125` | `engine-shared` | `—` | `else(defined(_JK2EXE))` |

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/qcommon/common.cpp:1031](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/qcommon/common.cpp#L1031)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-10` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`300bc4422b2a`](https://github.com/JACoders/OpenJK/commit/300bc4422b2a2b552f7e834881283aef20503730)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `high` |
| `2013-04-16` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`714c868b42c6`](https://github.com/JACoders/OpenJK/commit/714c868b42c6eaa5a1d2704d3425419f6e55579c)<br>Merge branch 'master' of https://github.com/Razish/OpenJK | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/qcommon/common.cpp` | `high` |
| `2013-11-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`2e90f9c19be1`](https://github.com/JACoders/OpenJK/commit/2e90f9c19be1a2b74a1ac71f8ff0dcdadfa3103c)<br>[MP] Removed leftover delayFreeVM references. Init lastTime to 0 in Com_Frame. Bring back ERR_NEED_CD handling just for conformity sake. Init the jakey randomizer first thing in Com_Init. | Changed an exact bound cvar-variable reference. `codemp/qcommon/common.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/qcommon/common.cpp` | `medium` |
| `2016-03-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`f5defc782a90`](https://github.com/eternalcodes/EternalJK/commit/f5defc782a901c885afbd5d8f1c3cb23072583dc)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/qcommon/common.cpp`, `shared/sys/sys_main.cpp`, `shared/sys/sys_public.h` | `medium` |
| `2016-03-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c9c6ab99fdd2`](https://github.com/eternalcodes/EternalJK/commit/c9c6ab99fdd24759cc32d45f642d63ebd3361b62)<br>Merge branch 'master' of https://github.com/JACoders/OpenJK into japro | Changed registration, default, flags, module, renderer scope, handler, or gating. `shared/sys/sys_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_view.c`, `codemp/cgame/cg_xcvar.h` | `high` |
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2026-06-11` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`ee86ea605ac4`](https://github.com/taysta/TaystJK/commit/ee86ea605ac4c0356f892a91721cd922306169df) · [PR #333](https://github.com/taysta/TaystJK/pull/333)<br>Merge pull request #333 from taysta/shelper-fixes | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:196](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L196) (XCVAR_DEF)
- registration: [shared/sys/sys_main.cpp:172](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_main.cpp#L172) (Cvar_Get); condition `defined(_JK2EXE)`
- registration: [shared/sys/sys_main.cpp:174](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/shared/sys/sys_main.cpp#L174) (Cvar_Get); condition `else(defined(_JK2EXE))`
- behavior: [codemp/qcommon/common.cpp:1759](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1759)
- behavior: [codemp/cgame/cg_view.c:2627](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_view.c#L2627)
- behavior: [codemp/qcommon/common.cpp:1760](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/qcommon/common.cpp#L1760)
- behavior: [codemp/cgame/hud_strafehelper.c:859](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L859)
- behavior: [codemp/cgame/hud_strafehelper.c:2546](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L2546)
