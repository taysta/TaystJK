---
title: "cg_speedometer"
layout: reference
nav_exclude: true
search_exclude: false
---

# `cg_speedometer`

<span class="label ref-origin ref-origin-japro">jaPRO</span>

Configure with the /speedometer command

## At a glance

| Field | Value |
|:--|:--|
| Module | `cgame` |
| Also registered in | `cgame`, `ui` |
| Renderer | All / not renderer-specific |
| Network scope | `client-only` — Local to the client/UI/renderer. |
| Derivation | `documented` |
| Confidence | `high` |
| Default | `0` |
| Value type | `bitmask` |
| Restart | No latch flag is registered. |
| Cheat protected | No |

## Values

| Value | Meaning | Evidence |
|:--|:--|:--|
| `64` | Enables the `SPEEDOMETER_ACCELMETER` code path. | [codemp/cgame/hud_strafehelper.h:90](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.h#L90) |
| `1` | Enables the `SPEEDOMETER_ENABLE` code path. | [codemp/cgame/hud_strafehelper.h:84](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.h#L84) |
| `8` | Enables the `SPEEDOMETER_JUMPDISTANCE` code path. | [codemp/cgame/hud_strafehelper.h:87](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.h#L87) |
| `4` | Enables the `SPEEDOMETER_JUMPHEIGHT` code path. | [codemp/cgame/hud_strafehelper.h:86](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.h#L86) |

## Flags

- `CVAR_ARCHIVE` — saved to the user configuration

## Registration-specific defaults

| Default | Module | Renderer | Compile condition |
|:--|:--|:--|:--|
| `0` | `cgame` | `—` | `always` |
| `0` | `ui` | `—` | `always` |

## Provenance

Origin: <span class="label ref-origin ref-origin-japro">jaPRO</span>

- Commit evidence: [`ead7c2c37109`](https://github.com/taysta/TaystJK/commit/ead7c2c37109a313e0f3994b832e627636e0fa06)
- Attribution method: `identifier-adjacent-explicit-credit`
- Attribution confidence: `high`
- Notes: An identifier-adjacent source/commit/PR line explicitly credits japro.

## Evidence

- registration: [codemp/cgame/cg_xcvar.h:46](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_xcvar.h#L46) (XCVAR_DEF)
- registration: [codemp/ui/ui_xcvar.h:164](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xcvar.h#L164) (XCVAR_DEF)
- behavior: [codemp/cgame/cg_draw.c:1962](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/cg_draw.c#L1962)
- behavior: [codemp/cgame/hud_strafehelper.c:415](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L415)
- behavior: [codemp/cgame/hud_strafehelper.c:419](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L419)
- behavior: [codemp/cgame/hud_strafehelper.c:421](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L421)
- behavior: [codemp/cgame/hud_strafehelper.c:423](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/cgame/hud_strafehelper.c#L423)
- documentation: [codemp/ui/ui_xdocs.h:107](https://github.com/taysta/TaystJK/blob/5802c999168db2f9759a48f1ef3a3d672fa99722/codemp/ui/ui_xdocs.h#L107)
