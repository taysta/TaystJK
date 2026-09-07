---
title: "cg_drawTeamOverlayForce"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_drawTeamOverlayForce`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Draw force points on the team overlay. Only has an effect on jaPRO servers, where force points is networked

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
| Value type | `bool` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `0` | Force points are not drawn | [codemp/ui/ui_xdocs.h:154](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L154) |
| `1` | Force points are drawn | [codemp/ui/ui_xdocs.h:154](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L154) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`1165f2824506`](https://github.com/taysta/TaystJK/commit/1165f282450636cfa70dbb70d5d506804478ef58)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:59](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L59) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:6083](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6083)
- behavior: [codemp/cgame/cg_draw.c:6079](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L6079)
- behavior: [codemp/ui/ui_xdocs.h:154](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L154)
- documentation: [codemp/ui/ui_xdocs.h:154](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L154)
