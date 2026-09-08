---
title: "cg_drawStatus"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawStatus`

<span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

Controls whether the main HUD status elements are drawn

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `1` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | HUD disabled; no status elements are drawn | [codemp/ui/ui_xdocs.h:286](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L286) |
| `1` | Draws the main HUD (health, armor, ammo, force power), the weapon/force/inventory selection panel, and the default CTF flag status indicators | [codemp/ui/ui_xdocs.h:286](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L286) |
| `2` | Same as 1, but replaces the CTF flag status with a new style | [codemp/ui/ui_xdocs.h:288](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L288) |
| `3` | Same as 1, but draws both the default and new style CTF flag status indicators | [codemp/ui/ui_xdocs.h:289](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L289) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-basejka">Base Jedi Academy</span>

- Baseline evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:342](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L342)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot. Dated commit evidence identifies later registration changes relative to the origin snapshot.

### Later changes

These commits occur after the ultimate-origin introduction on TaystJK's inherited first-parent lineage. Registration evidence is exact; behavior evidence requires a changed bound cvar reference or a changed registered command-handler hunk.

| Date | Change source | Commit / subject | Evidence | Confidence |
|:--|:--|:--|:--|:--|
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`a09d4827fb0d`](https://github.com/JACoders/OpenJK/commit/a09d4827fb0de284b33f1406d351ca9fd6a485e4)<br>Added /codeJK2/ for JK2. Also did a whole bunch of other crap which I shouldn't have, in hindsight. Have fun! | Changed registration, default, flags, module, renderer scope, handler, or gating. `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2013-04-07` | <span class="label ref-origin ref-origin-openjk">OpenJK</span> | [`b319c52fd4ed`](https://github.com/JACoders/OpenJK/commit/b319c52fd4ed1e4fb5dae4e468a1a791091b63a5)<br>Major codemp cleanup. Ported modbase. Restructured VS2010 projects. | Changed registration, default, flags, module, renderer scope, handler, or gating; and an exact bound cvar-variable reference. `codemp/cgame/cg_main.c`, `codemp/cgame/cg_newDraw.c`, `codemp/cgame/cg_xcvar.h` | `medium` |
| `2015-11-24` | <span class="label ref-origin ref-origin-eternaljk">EternalJK</span> | [`c8f6ea17a324`](https://github.com/eternalcodes/EternalJK/commit/c8f6ea17a3241677d1be74ef45109b96a357ef23)<br>Remove SP code | Changed registration, default, flags, module, renderer scope, handler, or gating. `code/cgame/cg_main.cpp`, `codeJK2/cgame/cg_main.cpp` | `medium` |
| `2018-09-03` | <span class="label ref-origin ref-origin-japro">jaPRO</span> | [`bdcd618c6771`](https://github.com/videoP/jaPRO/commit/bdcd618c67713b86946b720d791c382d3908d97c)<br>Import japro cgame | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `high` |
| `2024-02-27` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`baa02905f40f`](https://github.com/taysta/TaystJK/commit/baa02905f40f33652a2ae326fe55ece2642169c1) · [PR #130](https://github.com/taysta/TaystJK/pull/130)<br>Merge pull request #130 from taysta/tribes-clientside | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2024-03-22` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`02b8a825b64d`](https://github.com/taysta/TaystJK/commit/02b8a825b64d858f759133bc6f3adf8dd331b20e)<br>Tweak top center timer font and fix bug of ctf hud showing in tffa | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c` | `medium` |
| `2026-02-28` | <span class="label ref-origin ref-origin-taystjk">TaystJK</span> | [`168729602a5b`](https://github.com/taysta/TaystJK/commit/168729602a5b876069e9a19a63f5c6708cd8e353) · [PR #292](https://github.com/taysta/TaystJK/pull/292)<br>Merge pull request #292 from taysta/draw-status | Changed an exact bound cvar-variable reference. `codemp/cgame/cg_draw.c`, `codemp/ui/ui_xdocs.h` | `medium` |

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:285](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L285) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:3675](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L3675)
- behavior: [codemp/cgame/cg_draw.c:6935](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6935)
- behavior: [codemp/cgame/cg_draw.c:11656](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L11656)
- behavior: [codemp/cgame/cg_newDraw.c:570](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_newDraw.c#L570)
- behavior: [codemp/cgame/cg_draw.c:9987](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9987)
- documentation: [codemp/ui/ui_xdocs.h:286](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L286)
