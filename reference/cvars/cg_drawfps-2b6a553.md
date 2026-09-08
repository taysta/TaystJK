---
title: "cg_drawFPS"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawFPS`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Draw the match timer

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
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Big text | [codemp/ui/ui_xdocs.h:304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L304) |
| `1` | Small text 1 | [codemp/ui/ui_xdocs.h:304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L304) |
| `2` | Small text 2 | [codemp/ui/ui_xdocs.h:305](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L305) |
| `3` | Small text 3 | [codemp/ui/ui_xdocs.h:306](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L306) |
| `4` | Medium text | [codemp/ui/ui_xdocs.h:307](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L307) |
| `5` | Large text | [codemp/ui/ui_xdocs.h:308](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L308) |
| `6` | Small text 4 | [codemp/ui/ui_xdocs.h:309](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L309) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:345](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L345)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2019-12-14` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`90251d63bc5d`](https://github.com/eternalcodes/EternalJK/commit/90251d63bc5dc5a4323645e999334181d4783c27)<br>move CG_DrawSnapshot and CG_DrawFPS functions | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2019-12-15` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`30aed170933a`](https://github.com/eternalcodes/EternalJK/commit/30aed170933a96a6b5b737af925d3c3094ab7263)<br>CG_DrawFPS/DrawTimer/DrawSnapshot improvements | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2022-04-21` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`b6c02420b9df`](https://github.com/taysta/TaystJK/commit/b6c02420b9df02ae2b88006b332f1e053ecbf15c)<br>#13 HUD Improvements - new timer (cg_drawTimer 7) and new team scores display (cg_drawScores 3) | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/ui/ui_xdocs.h` | `medium` |
| `2022-04-24` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`72f6921bb38a`](https://github.com/taysta/TaystJK/commit/72f6921bb38aedb0d0fed368a3c35af162947686)<br>hud/timer tweaks | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:277](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L277) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:5859](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L5859)
- behavior: [codemp/cgame/cg_draw.c:6927](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6927)
- behavior: [codemp/cgame/cg_draw.c:5785](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L5785)
- behavior: [codemp/cgame/cg_draw.c:5840](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L5840)
- behavior: [codemp/cgame/cg_draw.c:5913](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L5913)
- documentation: [codemp/ui/ui_xdocs.h:304](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L304)
