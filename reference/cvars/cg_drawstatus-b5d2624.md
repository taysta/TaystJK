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

- Commit evidence: [`14cea1563762`](https://github.com/JACoders/OpenJK/commit/14cea1563762076974bee277afadbd5bf234c494)
- Upstream registration evidence: [code/cgame/cg_main.cpp:342](https://github.com/JACoders/OpenJK/blob/14cea1563762076974bee277afadbd5bf234c494/code/cgame/cg_main.cpp#L342)
- Attribution method: `present-in-openjk-initial-source-import`
- Attribution confidence: `high`
- Notes: Identifier is present in OpenJK's initial Raven source-import snapshot.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:285](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L285) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:3675](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L3675)
- behavior: [codemp/cgame/cg_draw.c:6935](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6935)
- behavior: [codemp/cgame/cg_draw.c:11656](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L11656)
- behavior: [codemp/cgame/cg_newDraw.c:570](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_newDraw.c#L570)
- behavior: [codemp/cgame/cg_draw.c:9987](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L9987)
- documentation: [codemp/ui/ui_xdocs.h:286](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L286)
