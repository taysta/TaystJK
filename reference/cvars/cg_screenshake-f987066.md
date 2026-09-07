---
title: "cg_screenShake"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_screenShake`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Shake screen when hit or while charging weapons

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame` |
| Renderer | All / not renderer-specific |
| Network scope | `feature-flagged` — Client behavior is negotiated through a server feature flag. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `2` |
| Value type | `enum` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Screen doesn't shake | [codemp/ui/ui_xdocs.h:437](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L437) |
| `1` | Screen shakes only when taking damage | [codemp/ui/ui_xdocs.h:437](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L437) |
| `2` | Screen shakes when charging weaspons and taking damage | [codemp/ui/ui_xdocs.h:438](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L438) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`bdcd618c6771`](https://github.com/taysta/TaystJK/commit/bdcd618c67713b86946b720d791c382d3908d97c)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:131](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L131) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_effects.c:676](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_effects.c#L676)
- behavior: [codemp/cgame/cg_weapons.c:676](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L676)
- behavior: [codemp/cgame/cg_weapons.c:684](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L684)
- behavior: [codemp/cgame/cg_weapons.c:2537](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_weapons.c#L2537)
- behavior: [codemp/cgame/cg_main.c:3625](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_main.c#L3625)
- documentation: [codemp/ui/ui_xdocs.h:437](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L437)
