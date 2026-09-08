---
title: "cg_hudFiles"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_hudFiles`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

HUD style

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `string` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | JKA HUD | [codemp/ui/ui_xdocs.h:79](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L79) |
| `1` | Simple HUD | [codemp/ui/ui_xdocs.h:79](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L79) |
| `2` | JK2 HUD | [codemp/ui/ui_xdocs.h:80](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L80) |
| `3` | Elegant HUD | [codemp/ui/ui_xdocs.h:81](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L81) |
| `4` | Quake HUD | [codemp/ui/ui_xdocs.h:82](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L82) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:417](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L417)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2014-03-12` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`6c02dcb2a6a2`](https://github.com/JACoders/OpenJK/commit/6c02dcb2a6a2b654a47aab49e428a130f3c09250)<br>[JK2SP] Assign correct hudfiles in ui module for jk2mode. | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/ui/ui_main.cpp` | `medium` |
| `2014-12-03` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`5ab07009afb3`](https://github.com/JACoders/OpenJK/commit/5ab07009afb306f2852a97caedf4eaab8774c743)<br>[SP] Fix compiler warnings | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/ui/ui_main.cpp` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `code/ui/ui_main.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2017-12-29` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`43b393062090`](https://github.com/eternalcodes/EternalJK/commit/43b393062090de615d5e5e694ef4fb5fd42ce59a)<br>  Merge remote-tracking branch 'upstream/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c` | `medium` |
| `2018-05-16` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`5df1fad1b1f6`](https://github.com/eternalcodes/EternalJK/commit/5df1fad1b1f6ba70e74e42630b0e0494750010f0)<br>Merge remote-tracking branch 'bucky/master' | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_main.c` and 1 more | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_cvar.c`, `codemp/cgame/cg_draw.c`, `codemp/cgame/cg_main.c` and 1 more | `high` |
| `2018-09-11` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`8a080da0044d`](https://github.com/eternalcodes/EternalJK/commit/8a080da0044d95468ad40bf52e86c270603c46df)<br>Fixed flashing health tic on JK2 HUD | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |
| `2019-04-21` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`2c42f32bebfc`](https://github.com/eternalcodes/EternalJK/commit/2c42f32bebfc4c0c5cb5f20bf53af57c02e1a3e6)<br>Moved Set2DRatio code for CG and UI into ui_shared, removed CG_Set2DRatio, update renderer widthRatioCoef when changing cl_ratioFix cvar. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_cvar.c` | `medium` |
| `2019-04-22` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`51081cd07aee`](https://github.com/eternalcodes/EternalJK/commit/51081cd07aee3c28ce9b89583e979a87998107d1)<br>Fix JK2 HUD when dead in Siege. | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_weapons.c` | `medium` |
| `2020-03-28` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`070c363f57f9`](https://github.com/eternalcodes/EternalJK/commit/070c363f57f9700b50250b1234b499df5fbc2b3c)<br>Cleanup displaycontext usage in cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_cvar.c`, `codemp/cgame/cg_draw.c` and 1 more | `medium` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b6c02420b9df`](https://github.com/taysta/TaystJK/commit/b6c02420b9df02ae2b88006b332f1e053ecbf15c)<br>#13 HUD Improvements - new timer (cg_drawTimer 7) and new team scores display (cg_drawScores 3) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_consolecmds.c`, `codemp/cgame/cg_main.c` | `medium` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`81e53a19e932`](https://github.com/taysta/TaystJK/commit/81e53a19e932d3be3da68e9ca7606b841183ce8f)<br>#13 HUD Improvements - new HUD (cg_hudFiles 4) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`0353b737b374`](https://github.com/taysta/TaystJK/commit/0353b737b374fd979fc57c5c7fd91ab01896878c)<br>docs for last commit | Changed an exact bound cvar-variable reference. `codemp/ui/ui_xdocs.h` | `medium` |
| `2022-10-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`420d7dc3fb1d`](https://github.com/taysta/TaystJK/commit/420d7dc3fb1d739171ac22011774a7c9876c02bf)<br>add new basejka duel scores overlay wtih cg_drawscores 3 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2023-10-12` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a07b984fe408`](https://github.com/taysta/TaystJK/commit/a07b984fe408ac4383931255330026d4b07bec87)<br>Merge remote-tracking branch 'origin/master' | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2023-11-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`a0faccba9b0f`](https://github.com/taysta/TaystJK/commit/a0faccba9b0f2aa6c902d11de9a24ee2baf0b871) · [PR #38](https://github.com/taysta/TaystJK/pull/38)<br>Merge pull request #38 from taysta/strafehelper-patch | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2023-11-03` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`85d0990f8536`](https://github.com/taysta/TaystJK/commit/85d0990f853676253d1a7fe427265e92a87f5ebc)<br>Adjust the default position of movement keys to the center of the screen | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2024-03-02` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`1d4c081cb762`](https://github.com/taysta/TaystJK/commit/1d4c081cb7621bf86ee9e3d1a523df56cf2992d1) · [PR #46](https://github.com/taysta/TaystJK/pull/46)<br>SnapHUD, PitchHUD, MV_OCPM & MV_TRIBES, Strafehelper refactors, movestyle constants usage (#46) | Changed an exact bound cvar-variable reference. `codemp/cgame/hud_strafehelper.c` | `medium` |
| `2025-04-30` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`df1c0a096e1a`](https://github.com/taysta/TaystJK/commit/df1c0a096e1a80f4a16f5300ff2993701d34b028) · [PR #232](https://github.com/taysta/TaystJK/pull/232)<br>Small Cleanup (#232) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:315](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L315) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_consolecmds.c:312](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L312)
- behavior: [codemp/cgame/cg_consolecmds.c:314](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_consolecmds.c#L314)
- behavior: [codemp/cgame/cg_cvar.c:61](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_cvar.c#L61)
- behavior: [codemp/cgame/cg_draw.c:675](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L675)
- behavior: [codemp/cgame/cg_draw.c:716](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L716)
- documentation: [codemp/ui/ui_xdocs.h:79](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L79)
