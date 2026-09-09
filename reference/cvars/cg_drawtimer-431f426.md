---
title: "cg_drawTimer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawTimer`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Draw the match timer

## At a glance

| Field | Value |
|:--|:--|
| Category | HUD & interface |
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| In-game xdocs | Yes — [codemp/ui/ui_xdocs.h:293](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L293) |
| In-game menu | Yes — [ingame_setup.menu:3971](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/assets/japro/ui/jamp/ingame_setup.menu#L3971) |
| Default | `0` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Big text | [codemp/ui/ui_xdocs.h:293](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L293) |
| `1` | Small text 1 | [codemp/ui/ui_xdocs.h:293](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L293) |
| `2` | Small text 2 | [codemp/ui/ui_xdocs.h:294](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L294) |
| `3` | Small text 3 | [codemp/ui/ui_xdocs.h:295](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L295) |
| `4` | Medium text | [codemp/ui/ui_xdocs.h:296](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L296) |
| `5` | Large text | [codemp/ui/ui_xdocs.h:297](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L297) |
| `6` | Small text 4 | [codemp/ui/ui_xdocs.h:298](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L298) |
| `7` | Counter strike | [codemp/ui/ui_xdocs.h:299](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L299) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:344](https://github.com/JACoders/OpenJK/blame/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L344)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2013-08-11` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`794718e3fdfb`](https://github.com/JACoders/OpenJK/commit/794718e3fdfb94a07256904e829936d80d696ce1)<br>Merge pull request #344 from Razish/qvmtest | Changed an exact bound cvar-variable reference. `codemp/ui/ui_main.c` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2019-12-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`30aed170933a`](https://github.com/eternalcodes/EternalJK/commit/30aed170933a96a6b5b737af925d3c3094ab7263)<br>CG_DrawFPS/DrawTimer/DrawSnapshot improvements | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b6c02420b9df`](https://github.com/taysta/TaystJK/commit/b6c02420b9df02ae2b88006b332f1e053ecbf15c)<br>#13 HUD Improvements - new timer (cg_drawTimer 7) and new team scores display (cg_drawScores 3) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/ui/ui_xdocs.h` | `medium` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`81e53a19e932`](https://github.com/taysta/TaystJK/commit/81e53a19e932d3be3da68e9ca7606b841183ce8f)<br>#13 HUD Improvements - new HUD (cg_hudFiles 4) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`72f6921bb38a`](https://github.com/taysta/TaystJK/commit/72f6921bb38aedb0d0fed368a3c35af162947686)<br>hud/timer tweaks | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`81882b7ee881`](https://github.com/taysta/TaystJK/commit/81882b7ee8819e82f5308bf66d08fd2b7040aa35)<br>#13 new team overlays - cg_drawTeamOverlay 3/4 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-10-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`9c5814cd2451`](https://github.com/taysta/TaystJK/commit/9c5814cd24518a2dbb4e8b7fd3bdc34039d17c9f)<br>add timer countdown cvar | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-10-05` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`420d7dc3fb1d`](https://github.com/taysta/TaystJK/commit/420d7dc3fb1d739171ac22011774a7c9876c02bf)<br>add new basejka duel scores overlay wtih cg_drawscores 3 | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2026-02-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`168729602a5b`](https://github.com/taysta/TaystJK/commit/168729602a5b876069e9a19a63f5c6708cd8e353) · [PR #292](https://github.com/taysta/TaystJK/pull/292)<br>Merge pull request #292 from taysta/draw-status | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:286](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_xcvar.h#L286) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:3835](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L3835)
- behavior: [codemp/cgame/cg_draw.c:3892](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L3892)
- behavior: [codemp/cgame/cg_draw.c:3936](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L3936)
- behavior: [codemp/cgame/cg_draw.c:4154](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L4154)
- behavior: [codemp/cgame/cg_draw.c:5912](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/cgame/cg_draw.c#L5912)
- documentation: [codemp/ui/ui_xdocs.h:293](https://github.com/taysta/TaystJK/blame/6ff04c0baf588a89e5ec9361ad7a0992941d7655/codemp/ui/ui_xdocs.h#L293)
